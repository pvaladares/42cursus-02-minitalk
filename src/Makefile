# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 18:12:40 by pvaladar          #+#    #+#              #
#    Updated: 2022/07/20 16:24:45 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	GENERAL CONFIG & FLAGS
# =============================================================================

# Program for compiling C programs
CC := cc

# Extra flags to give to the C compiler
CFLAGS := -Wall -Wextra -Werror

RM := /bin/rm -f

NAME_SERVER := server
NAME_CLIENT := client

# =============================================================================
#	MANDATORY PART
# =============================================================================

SRC_SERVER := server.c minitalk.c
SRC_CLIENT := client.c minitalk.c

SRC_SERVER_BONUS := server_bonus.c minitalk_bonus.c
SRC_CLIENT_BONUS := client_bonus.c minitalk_bonus.c

INCLUDES := -I. -Ilibft

LIBFT := ./libft/libft.a
LIBFT_PATH := ./libft

# =============================================================================
#	RULES
# =============================================================================

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

# Make libft
$(LIBFT): $(shell make -C $(LIBFT_PATH) -q libft.a)
	make -C $(LIBFT_PATH)

# Clean object files (*.o) - not used on this project
clean:

# Clean object files (*.o) and the binary file
fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

# Clean object files (*.o) and the binary file; 
# Then create the binary file again, and generate the library and index it
re: fclean all

# "To turn in bonuses to your project, you must include a rule bonus to your Makefile"
# "Makefile must not relink"
bonus: $(LIBFT) fclean
	$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT)

rebonus: fclean bonus

# .PHONY rule in order to avoid relinking
.PHONY: all clean fclean re bonus rebonus
