NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src/
OBJS_DIR = obj/
HEADERS_DIR = header/

SRCS_NAME = libft.c \
			main.c \
			philosophers.c \
			validation.c \

HEADERS = libft.h \
		  philosophers.h \
		  utils.h \
		  validation.h \

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(addprefix $(HEADERS_DIR), $(HEADERS)) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re