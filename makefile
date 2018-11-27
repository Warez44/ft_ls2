# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clingier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 07:44:16 by clingier          #+#    #+#              #
#    Updated: 2018/11/27 14:56:34 by clingier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

SRC = src/err_handler.c src/ft_flags.c src/ft_ls.c\
	  src/ft_ls_exec.c src/ft_ls_exec2.c src/lflag.c src/lflag2.c src/lflag3.c\
	  src/lflag4.c src/main.c src/readfiles.c src/sorting.c src/stats.c 

OBJ = err_handler.o ft_flags.o\
	  ft_ls.o ft_ls_exec.o ft_ls_exec2.o lflag.o lflag2.o lflag3.o\
	  lflag4.o main.o readfiles.o sorting.o stats.o 

$(NAME):
	@make re -C libft/
	@gcc -I includes/ -I libft/  $(FLAGS) -c $(SRC)
	@gcc -L libft/ -lft $(FLAGS) $(OBJ) -o $(NAME)
	@echo "make"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C libft/
	@echo "clean"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "fclean"

re: fclean all
