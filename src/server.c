/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:56:24 by pvaladar          #+#    #+#             */
/*   Updated: 2022/07/04 15:07:29 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_values(int *bits_received, int *info_received)
{
	if (*bits_received == 0)
		*info_received = 0;
}

/*
  Function catches SIGUSR1 and SIGUSR2 signals received from client that
  represents the status of each bit (either 0 or 1)
  Variables declared as static are initialized with zero, and after each 
  8 bits received they are again re-initialized to zero
  For each bit received from client, the server sends an ACK signal
  (then the client should only send the next bit after this ACK signal)
*/
void	server_handler(int num, siginfo_t *info, void *context)
{
	static t_protocol	t_server;
	static int			i;

	usleep(WAIT_US);
	(void)context;
	reset_values(&t_server.bits_received, &t_server.data_received);
	if (num == SIGUSR2 && t_server.flag_length_received == 0)
		t_server.data_received |= 1 << (((sizeof(int) * 8) - 1) - t_server.bits_received);
	else if (num == SIGUSR2 && t_server.flag_length_received == 1)
		t_server.data_received |= 1 << (((sizeof(char) * 8) - 1) - t_server.bits_received);
	t_server.bits_received++;
	if (t_server.bits_received == 8 && t_server.flag_length_received == 1)
	{
		t_server.message[i++] = t_server.data_received;
		if (t_server.data_received == '\0')
		{
			ft_putstr("\e[92mreceived message = [");
			ft_putstr(t_server.message);
			ft_putstr("]\n\e[0m");
			free(t_server.message);
			t_server.message = NULL;
			t_server.flag_length_received = 0;
			i = 0;
			t_server.bits_received = 0;
			send_bit(info->si_pid, 1, 0);
		}
		t_server.bits_received = 0;
	}
	if (t_server.bits_received == sizeof(int) * 8 && t_server.flag_length_received == 0)
	{
		t_server.flag_length_received = 1;
		ft_putstr("\e[92mreceived length = [");
		ft_putnbr(t_server.data_received);
		ft_putstr("]\n\e[0m");
		t_server.message = ft_calloc(t_server.data_received + 1, sizeof(char));
		if (t_server.message == NULL)
		{
			ft_putstr("\e[31m## error - ft_calloc() ##\n\e[0m");
			exit(EXIT_FAILURE);
		}
		t_server.message[t_server.data_received] = '\0';
		t_server.bits_received = 0;
	}
	send_bit(info->si_pid, 0, 0);
}

/*
  This program (server) prints to stdout the PID process and keeps
  listening for incoming message transmissions
  
  Each client should the following sequence:
         (int)              (char)               (char)
    length of message -> regular chars -> null string terminator char

  The string message is only printed to stdout when the full string is received
  For each signal received from client, this program (server) sends
  a corresponding signal back
  
  Using sigaction structure to define which signals to catch by the handler
  The infinite loop will just keep the process running
  
  The pause() function causes the calling thread to pause until a
  signal is received
*/
int	main(void)
{
	struct sigaction	s_server;

	sigemptyset(&s_server.sa_mask);
	s_server.sa_sigaction = server_handler;
	s_server.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	configure_sigaction_signals(&s_server);
	ft_putstr_fd("\e[92mserver [PID = ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("]\n\e[0m", STDOUT_FILENO);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
