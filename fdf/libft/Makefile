# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gargence <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 21:35:39 by gargence          #+#    #+#              #
#    Updated: 2016/10/17 15:54:28 by gargence         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_putstr.c ft_strdup.c ft_strncpy.c ft_strsub.c\
ft_memalloc.c ft_strchr.c ft_strequ.c ft_strnequ.c ft_strtrim.c\
ft_memdel.c ft_strclr.c ft_strjoin.c ft_strnew.c ft_memset.c\
ft_strcmp.c ft_strlen.c ft_strnstr.c ft_putchar.c ft_strcpy.c\
ft_strncmp.c  ft_strrchr.c ft_putendl.c  ft_strdel.c ft_strstr.c ft_strcat.c\
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_strncat.c ft_toupper.c ft_tolower.c ft_putnbr.c ft_memchr.c\
ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c\
ft_striter.c ft_striteri.c ft_strlcat.c ft_strmap.c ft_strmapi.c\
ft_strsplit.c ft_itoa.c ft_memccpy.c ft_memmove.c ft_atoi.c ft_memcpy.c\
ft_memcmp.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c\
ft_lstiter.c ft_lstmap.c ft_power.c ft_sqrt.c ft_strrev.c ft_lstlen.c\
ft_lstaddend.c ft_strjoinfree.c get_next_line.c ft_wstrlen.c ft_special_float.c\
ft_isint.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

INCLUDES = includes/

all : $(NAME)

$(NAME) :
	@echo "\033[1;32mCompilation...\033[0m"
	@gcc -c $(FLAG) $(SRC) -I $(INCLUDES)
	@echo "\033[1;32mCompilation done !\033[0m"
	@echo "\033[1;32mCreating $(NAME)...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32m$(NAME) created !\033[0m"

clean :
	@echo "\033[1;32mDeleting object files...\033[0m"
	@rm -rf $(OBJ)
	@echo "\033[1;32mObject files deleted !\033[0m"

fclean : clean
	@echo "\033[1;32mDeleting $(NAME)...\033[0m"
	@rm -rf $(NAME)
	@echo "\033[1;32m$(NAME) deleted !\033[0m"

re : fclean all

easy : all clean
