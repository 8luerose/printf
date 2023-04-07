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


# NAME = libftprintf.a

# CC = cc

# CFLAGS = -Wall -Wextra -Werror

# HEADER = ft_printf.h

# SRC = ft_printf.c \
	

# OBJS = $(SRC:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJ)
# 	ar rc $(NAME) $^
# 	ranlib $(NAME)

# %.o: %.c
# 	@echo "\033[0;32mGenerating obj..."
# 	$(CC) -c $< $(CFLAGS)
# 	@echo "\033[0m"

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all re clean fclean




# SRCS	= $(wildcard sources/*.c)
# OBJS	= $(SRCS:.c=.o)

# NAME	= libftprintf.a
# CC		= gcc
# RM		= rm -f
# CFLAGS	= -Wall -Wextra -Werror 

# all :  ${NAME}

# $(NAME) : ${OBJS}
# 	ar rc $(NAME) $(OBJS)
# 	ranlib $(NAME)

# .c.o : 
# 	${CC} ${CFLAGS} -c $< -o $@ 

# clean :
# 	${RM} ${OBJS}

# fclean : clean
# 	${RM} ${NAME}

# norm :
# 	norminette sources/*.[ch]

# re : fclean all
