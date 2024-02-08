NAMEC = client
NAMES = server

SRCC = client.c 
SRCS = server.c 

OBJC = $(SRCC:%.c%.o)
OBJS = $(SRCS:%.c%.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all:	$(NAMEC) $(NAMES)

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAMEC): $(OBJC)
	make -C ./Libft
	@$(CC) $(CFLAGS) $(OBJC) ./Libft/libft.a -o $(NAME)
	@echo "$(GREEN)Compilation of '$(NAMEC)' completed successfully$(NC)"
$(NAMES): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAMES)

clean:
	make clean -C ./Libft
	@/bin/rm -rf $(OBJC) $(OBJS)
	@echo "$(BLUE)Removed object-files!$(NC)"

fclean:
	make fclean -C ./Libft
	@/bin/rm -rf $(NAMEC) $(OBJC) $(NAMES) $(OBJS)
	@echo "$(BLUE)Removed '$(NAMEC) and '$(NAMES)'$(NC)"

re: fclean all
	@echo "$(GREEN)Everything recompiled$(NC)"

.PHONY: all clean fclean re