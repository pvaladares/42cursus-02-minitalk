# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 18:12:40 by pvaladar          #+#    #+#              #
#    Updated: 2022/06/30 11:26:19 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	GENERAL CONFIG & FLAGS
# =============================================================================

CC			= cc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address,undefined

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

INCLUDES = -I . -I libft -I printf
LINKERS =  -L libft -L printf


# =============================================================================
#	RULES
# =============================================================================

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)
	
all		:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER)	:	$(OBJ_SERVER)
#					$(CC) $(CFLAGS) $(LINKERS) $(OBJ_SERVER) -o $(NAME_SERVER)
					$(CC) $(CFLAGS) libft/libft.a printf/libftprintf.a $(SRC_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT)	:	$(OBJ_CLIENT)
#					$(CC) $(CFLAGS) $(LINKERS) $(OBJ_CLIENT) -o $(NAME_CLIENT)
					$(CC) $(CFLAGS) libft/libft.a printf/libftprintf.a $(SRC_CLIENT) -o $(NAME_CLIENT)

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
bonus	:	$(OBJS_BONUS) fclean
			@make OBJS_MAND="$(OBJS_MAND) $(OBJS_BONUS)" $(NAME)

rebonus	:	fclean bonus

# .PHONY rule in order to avoid relinking
.PHONY	:	all clean fclean re bonus rebonus