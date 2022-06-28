# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 18:12:40 by pvaladar          #+#    #+#              #
#    Updated: 2022/06/27 17:08:57 by pvaladar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Based on intra video, C Piscine - C 09, C 11
# https://elearning.intra.42.fr/notions/c-piscine-c-09-c-11/subnotions/makefile-example/videos/makefile-example

# =============================================================================
#	GENERAL CONFIG & FLAGS
# =============================================================================

NAME	= libft.a
RM		= /bin/rm -f

# "use cc"
CC		= cc

# "submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror"
CFLAGS	= -Wall -Wextra -Werror

# "You must use the command ar to create your library."
LIB1	= ar -rcs
LIB2	= ranlib

# =============================================================================
#	MANDATORY PART
# =============================================================================

# Part 1 - Libc functions (ft_isalpha, ... ft_strdup)
# Part 2 - Additional functions (ft_substr, ..., ft_putnbr_fd)
SRCS_MAND	=	ft_isalpha.c	ft_toupper.c	\
				ft_isdigit.c	ft_tolower.c	\
				ft_isalnum.c	ft_strchr.c		\
				ft_isascii.c	ft_strrchr.c	\
				ft_isprint.c	ft_strncmp.c	\
				ft_strlen.c		ft_memchr.c		\
				ft_memset.c		ft_memcmp.c		\
				ft_bzero.c		ft_strnstr.c	\
				ft_memcpy.c		ft_atoi.c		\
				ft_memmove.c					\
				ft_strlcpy.c					\
				ft_strlcat.c					\
				ft_toupper.c					\
				ft_calloc.c						\
				ft_strdup.c						\
				ft_substr.c						\
				ft_strjoin.c					\
				ft_strtrim.c					\
				ft_split.c						\
				ft_itoa.c						\
				ft_strmapi.c					\
				ft_striteri.c					\
				ft_putchar_fd.c					\
				ft_putstr_fd.c					\
				ft_putendl_fd.c					\
				ft_putnbr_fd.c

# Takes the variable value ${SRCS_MAND}, which is a string composed of words separated by spaces, and for each word, replace the suffix .c with .o
OBJS_MAND	=	${SRCS_MAND:.c=.o}

# =============================================================================
#	BONUS PART
# =============================================================================

# From Common Instructions: "Bonuses must be in a different file _bonus.{c/h} if the subject does not specify anything else."
# From Mandatory part: "Turn in files Makefile, libft.h, ft_*.c"
SRC_BONUS	=	ft_lstadd_front.c	\
				ft_lstnew.c			\
				ft_lstsize.c		\
				ft_lstadd_back.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstlast.c		\
				ft_lstmap.c

OBJS_BONUS	=	${SRC_BONUS:.c=.o}

# =============================================================================
#	RULES
# =============================================================================

# "Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re."
# "NAME, all, clean, fclean, re" @ page 6/16

# Compile the sources (*.c) to object files (*.o)
# Then generate a library file and index it
# 'nm libft.a' to check content
$(NAME)	:	$(OBJS_MAND)
			$(LIB1) $(NAME) $(OBJS_MAND)
			$(LIB2) $(NAME)

# 'all' is the second rule so 'libft.a' (NAME) will show message library filename 'make: `libft.a' is up to date.' when trying to relink
all		:	$(NAME)

# Sample:
# cc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o
#	-c				Only run preprocess, compile, and assemble steps
#	-o <file>		Write output to <file>
#	$< and $@		https://www.gnu.org/software/make/manual/make.html#Automatic-Variables
%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

# Clean object files (*.o)
clean	:	
			$(RM) $(OBJS_MAND) $(OBJS_BONUS)

# Clean object files (*.o) and the binary file
fclean	:	clean
			$(RM) $(NAME)

# Clean object files (*.o) and the binary file; 
# Then create the binary file again, and generate the library and index it
re		:	fclean all

# "To turn in bonuses to your project, you must include a rule bonus to your Makefile"
# "Makefile must not relink" (https://42born2code.slack.com/archives/CMX2R5JSW/p1634727271200100?thread_ts=1634724450.199600&cid=CMX2R5JSW)
bonus	:	$(OBJS_BONUS)
			@make OBJS_MAND="$(OBJS_MAND) $(OBJS_BONUS)" $(NAME)

rebonus	:	fclean bonus

# .PHONY rule in order to avoid relinking
.PHONY	:	all clean fclean re bonus rebonus

# More info @ https://github.com/pvaladares/42cursus-00-Libft
