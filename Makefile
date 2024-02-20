NAMES = server
NAMEC = client

SRCS = server.c 
SRCC = client.c 

OBJC = $(SRCC:%.c=%.o)
OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = Libft/libft.a

all:	$(NAMES) $(NAMEC)

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAMES): $(OBJS) minitalk.h
	make -C ./Libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAMES)
	@echo "$(GREEN)Compilation of '$(NAMES)' completed successfully$(NC)"
$(NAMEC): $(OBJC) minitalk.h
	$(CC) $(CFLAGS) $(OBJC) $(LIBFT) -o $(NAMEC)
	@echo "$(GREEN)Compilation of '$(NAMEC)' completed successfully$(NC)"

clean:
	make clean -C ./Libft
	@/bin/rm -f $(OBJS) $(OBJC)
	@echo "$(BLUE)Removed object-files!$(NC)"

fclean:
	make fclean -C ./Libft
	@/bin/rm -f $(NAMES) $(OBJS) $(NAMEC) $(OBJC)
	@echo "$(BLUE)Removed '$(NAMES)' and '$(NAMEC)'$(NC)"

re: fclean all
	@echo "$(GREEN)Everything recompiled$(NC)"

.PHONY: all clean fclean re