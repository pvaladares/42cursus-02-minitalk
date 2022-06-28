# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 17:40:15 by pvaladar          #+#    #+#              #
#    Updated: 2022/06/09 12:01:11 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	GENERAL CONFIG & FLAGS
# =============================================================================

NAME	= libftprintf.a
RM		= rm -f

# "use cc"
CC		= cc

# "submit a Makefile which will compile your source files to the required 
# output with the flags -Wall, -Wextra and -Werror"
CFLAGS	= -Wall -Wextra -Werror

# "You must use the command ar to create your library."
LIB1	= ar -rcs
LIB2	= ranlib

# =============================================================================
#	MANDATORY PART
# =============================================================================

SRCS_MAND	=	ft_printf.c \
				ft_putchar.c \
				ft_putnbr_base.c \
				ft_putnbr.c \
				ft_putptr.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_u_putnbr_base.c

# Takes the variable value ${SRCS_MAND}, which is a string composed of words 
# separated by spaces, and for each word, replace the suffix .c with .o
OBJS_MAND	=	${SRCS_MAND:.c=.o}

# =============================================================================
#	RULES
# =============================================================================

# "Your Makefile must at least contain the rules $(NAME), all, clean, fclean 
# and re."

# Compile the sources (*.c) to object files (*.o)
# Then generate a library file and index it
# 'nm libftprintf.a' to check content
$(NAME)	:	$(OBJS_MAND)
			$(LIB1) $(NAME) $(OBJS_MAND)
			$(LIB2) $(NAME)

# 'all' is the second rule so 'libftprintf.a' (NAME) will show message library 
# filename 'make: `libftprintf.a' is up to date.' when trying to relink
all		:	$(NAME)

# Sample:
# cc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o
#	-c			Only run preprocess, compile, and assemble steps
#	-o <file>	Write output to <file>
#	$< and $@	gnu.org/software/make/manual/make.html#Automatic-Variables
%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

# Clean object files (*.o)
clean	:	
			$(RM) $(OBJS_MAND)

# Clean object files (*.o) and the binary file
fclean	:	clean
			$(RM) $(NAME)

# Clean object files (*.o) and the binary file; 
# Then create the binary file again, and generate the library and index it
re		:	fclean all

# .PHONY rule in order to avoid relinking
.PHONY	:	all clean fclean re

# More info @ https://github.com/pvaladares/42cursus-01-ft_printf
