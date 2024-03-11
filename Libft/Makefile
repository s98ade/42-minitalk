NAME = libft.a
SRCS = \
	   ft_isalnum.c \
	   ft_itoa.c \
	   ft_memset.c \
	   ft_strchr.c \
	   ft_strlcpy.c \
	   ft_strrchr.c \
	   ft_isalpha.c \
	   ft_memchr.c \
	   ft_putchar_fd.c \
	   ft_strdup.c \
	   ft_strlen.c \
	   ft_strtrim.c \
	   ft_atoi.c \
	   ft_isascii.c \
	   ft_memcmp.c \
	   ft_putendl_fd.c \
	   ft_striteri.c \
	   ft_strmapi.c \
	   ft_substr.c \
	   ft_bzero.c \
	   ft_isdigit.c \
	   ft_memcpy.c \
	   ft_putnbr_fd.c \
	   ft_strjoin.c \
	   ft_strncmp.c \
	   ft_tolower.c \
	   ft_calloc.c \
	   ft_isprint.c \
	   ft_memmove.c \
	   ft_putstr_fd.c \
	   ft_strlcat.c \
	   ft_strnstr.c \
	   ft_toupper.c \
	   ft_split.c \
	   ft_print_chr.c \
	   ft_print_digit.c \
	   ft_print_hex_lower.c \
	   ft_print_hex_upper.c \
	   ft_print_percent.c \
	   ft_print_ptr.c \
	   ft_print_str.c \
	   ft_print_unsigned.c \
	   ft_printf.c \
	   get_next_line_utils.c \
	   get_next_line.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
