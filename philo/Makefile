NAME= philo

SRCS= main.c utils.c create.c start_thread.c timestamp.c mutex.c philo_life.c routine.c \

OBJS= $(addprefix srcs/,$(SRCS:.c=.o))

CC= gcc

CFLAGS= -Wall -Werror -Wextra #-g -fsanitize=thread

HEADER= -I includes

LIBS= -lpthread

.c.o:
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re