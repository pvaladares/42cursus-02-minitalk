# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 18:12:40 by pvaladar          #+#    #+#              #
#    Updated: 2022/07/04 16:57:37 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	GENERAL CONFIG & FLAGS
# =============================================================================

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

RM			= /bin/rm -f

NAME_SERVER = server
NAME_CLIENT	= client

# =============================================================================
#	MANDATORY PART
# =============================================================================

SRC_SERVER	=	server.c minitalk.c
SRC_CLIENT	=	client.c minitalk.c

OBJ_SERVER	=	${SRC_SERVER:.c=.o}
OBJ_CLIENT	=	${SRC_CLIENT:.c=.o}

INCLUDES = -I . -I libft

LIBFT = ./Libft/libft.a
LIBFT_PATH = ./Libft

# =============================================================================
#	RULES
# =============================================================================

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)
	
all		:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER)	:	$(OBJ_SERVER) $(LIBFT)
					$(CC) $(CFLAGS) $(LIBFT) $(SRC_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT)	:	$(OBJ_CLIENT) $(LIBFT)
					$(CC) $(CFLAGS) $(LIBFT) $(SRC_CLIENT) -o $(NAME_CLIENT)

# Make libft
$(LIBFT):	$(shell make -C $(LIBFT_PATH) -q libft.a)
			make -C $(LIBFT_PATH)

# Clean object files (*.o)
clean	:	
			$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

# Clean object files (*.o) and the binary file
fclean	:	clean
			$(RM) $(NAME_SERVER) $(NAME_CLIENT)

# Clean object files (*.o) and the binary file; 
# Then create the binary file again, and generate the library and index it
re		:	fclean all

# "To turn in bonuses to your project, you must include a rule bonus to your Makefile"
# "Makefile must not relink" (https://42born2code.slack.com/archives/CMX2R5JSW/p1634727271200100?thread_ts=1634724450.199600&cid=CMX2R5JSW)
bonus	:	all

rebonus	:	fclean bonus

# .PHONY rule in order to avoid relinking
.PHONY	:	all clean fclean re bonus rebonus