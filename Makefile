#!/usr/bin/make -f

CLIENT = client
SERVER = server
SERVER_DIR = ./server_dir
CLIENT_DIR = ./client_dir
LIBFT_DIR = ./libft

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

all: $(LIBFT) $(SERVER) #$(CLIENT)

$(SERVER): $(LIBFT)
	make -C $(SERVER_DIR)

#$(CLIENT): $(LIBFT)
#	make -C $(CLIENT_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(SERVER_DIR) clean
#	make -C $(CLIENT_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
#	rm -f $(CLIENT)
	rm -f $(SERVER)
	make -C $(SERVER_DIR) fclean
#	make -C $(CLIENT_DIR) fclean
	make -C $(LIBFT_DIR) fclean
re: fclean all

.PHONY: clean fclean all re
