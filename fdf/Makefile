# **************************************************************************** #
#                                                                              #
#     #####     #   ######                                         Makefile    #
#     #         #   #                                                          #
#     ###    ####   ###                                                        #
#     #     #   #   #                                                          #
#     #      ###    #                                      Geoffrey Argence    #
#                                                                              #
# **************************************************************************** #

NAME =	FdF

TD =	\033[32;1m

END =	\033[0m

SRC =	calcul.c config_data.c count_args.c get_args.c main.c \
		print.c print_lign.c put_error.c rotxyz.c

FLAG =	-Wall -Wextra -Werror -framework OpenGL -framework Appkit

INC =	-I includes/ -I libft/includes -I minilibx_macos

LIB =	libft/libft.a minilibx_macos/libmlx.a

all: $(NAME)

$(NAME):
	@echo "$(TD)Making libft...$(END)"
	@make -C libft
	@echo "$(TD)Making minilibx...$(END)"
	@make -C minilibx_macos
	@echo "$(TD)Compilating $(NAME)...$(END)"
	@gcc -o $(NAME) $(FLAG) $(INC) $(SRC) $(LIB)
	@echo "$(TD)$(NAME) ready !$(END)"

clean:
	@echo "$(TD)Making clean libft...$(END)"
	@make fclean -C libft
	@echo "$(TD)Making clean minilibx...$(END)"
	@make clean -C minilibx_macos
	@echo "$(TD)Removing $(NAME)...$(END)"
	@rm -rf $(NAME)
	@echo "$(TD)Cleaned Successfull !$(END)"

re: clean all
