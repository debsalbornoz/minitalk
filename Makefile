CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror

SERVER_SRC = server.c
CLIENT_SRC = client.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_NAME = server
CLIENT_NAME = client
LIBFT_DIR = ./libft

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT_DIR)/libft.a $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L$(LIBFT_DIR) -lft -o $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT_DIR)/libft.a $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L$(LIBFT_DIR) -lft -o $(CLIENT_NAME)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(SERVER_NAME) $(CLIENT_NAME) libft.a

re: fclean all