NAME = minitalk

SERVER = server
CLIENT = client

SRCS = server.c 
SRCC = client.c 

OBJC = $(SRCC:%.c%.o)
OBJS = $(SRCS:%.c%.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = Libft/libft.a

all:	$(SERVER) $(CLIENT)

GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAMES): $(OBJS) minitalk.h
	make -C ./Libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(SRCS)
	@echo "$(GREEN)Compilation of '$(SERVER)' completed successfully$(NC)"
$(NAMEC): $(OBJC) minitalk.h
	$(CC) $(CFLAGS) $(OBJC) $(LIBFT) -o $(SRCC)
	@echo "$(GREEN)Compilation of '$(CLIENT)' completed successfully$(NC)"

clean:
	make clean -C ./Libft
	@/bin/rm -rf $(OBJS) $(OBJC)
	@echo "$(BLUE)Removed object-files!$(NC)"

fclean:
	make fclean -C ./Libft
	@/bin/rm -rf $(SERVER) $(OBJS) $(CLIENT) $(OBJC)
	@echo "$(BLUE)Removed '$(SERVER)' and '$(CLIENT)'$(NC)"

re: fclean all
	@echo "$(GREEN)Everything recompiled$(NC)"

.PHONY: all clean fclean re