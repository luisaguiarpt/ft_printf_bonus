NAME=libftprintf.a
SRCS=ft_printf.c ft_printf_utils.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	cc $(CFLAGS) -c $< -o ${<:.c=.o}
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all


