NAME = ft_ssl

SRC =	src/main.c src/ft_md5.c

OBJ =	main.o ft_md5.o 

FLAGS = -Wall -Wextra -Werror #-fsanitize=address

all: $(NAME)

$(OBJ): $(SRC)
	@gcc -c $(SRC) -I ./includes

$(NAME): $(OBJ)
	#@make -C libft
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -L./libft -lft 
	@echo "make for ft_ssl: Done" 

clean:
	@rm -f $(OBJ)
	#@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	#@make -C libft fclean

re: fclean all
