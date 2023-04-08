CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = cr
RM = rm -f
NAME = libftprintf.a

SRCS =  ft_printf.c 			\
		ft_print_c_s_i_d_u.c	\
		ft_print_ptr.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
