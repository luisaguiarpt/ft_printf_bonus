NAME=libftprintf.a
SRCS=./mandatory/ft_printf.c ./mandatory/char_utils.c ./mandatory/nbr_utils.c
OBJS=$(SRCS:.c=.o)
BONUS_SRCS=./bonus/ft_printf_bonus.c ./bonus/print_char_bonus.c ./bonus/print_str_bonus.c \
./bonus/print_ptr_bonus.c ./bonus/print_int_bonus.c ./bonus/print_handlers_bonus.c \
./bonus/print_hex_bonus.c
BONUS_OBJS=$(BONUS_SRCS:.c=.o)
CFLAGS=-Wall -Werror -Wextra -fPIC

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

.c.o:
	cc $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
