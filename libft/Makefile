NAME	=	libft.a

ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET		 := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif


SRCS	= ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_substr.c \
		  ft_atoi.c \
		  ft_atol.c \
		  ft_strdup.c \
		  ft_calloc.c \
		  ft_strchr.c \
		  ft_memcmp.c \
		  ft_memchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c  \
		  ft_split.c \
		  ft_strnstr.c \
		  ft_substr.c \

BONUS	= ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c \

BONUS_OBJS = ${BONUS:.c=.o}

OBJS = ${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM 		= 	rm -f

.c.o:
		@$(CC) $(CFLAGS) -c  $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(BONUS_OBJS) libft.h
			@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
			@echo "$(GREEN)Libft Compiled$(RESET)"
			
all:		$(NAME)

bonus: ${BONUS_OBJS} ${OBJS}
		@ar rcs ${NAME} ${BONUS_OBJS} ${OBJS}
		@touch $@
clean:
			@$(RM) $(OBJS) $(BONUS_OBJS)
fclean:		clean
			@$(RM) $(NAME)
			@$(RM) bonus

re:			fclean all

.PHONY: all clean fclean re 
