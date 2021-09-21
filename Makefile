NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INCLUDE 	= ./include/
LIBDIR = ./libft/
LIBNAME = libft.a

SRCDIR		=	srcs/
SRC			=	main.c minishell.c builtin.c \

BITD		=	builtin/
BITC		=	ft_cd.c ft_echo.c ft_env.c ft_exit.c \
				ft_export.c ft_pwd.c ft_unset.c

UTID		=	utils/
UTIS		=	error.c find_en.c freeshell.c child_process.c pipe_process.c

PTID		=	parse/
PTIS		=	parse.c

BITDIR	= $(addprefix $(SRCDIR), $(BITD))
UTIDIR	= $(addprefix $(SRCDIR), $(UTID))
PTIDIR	= $(addprefix $(SRCDIR), $(PTID))


SRCS	= $(addprefix $(SRCDIR), $(SRC))
BITCS	= $(addprefix $(BITDIR), $(BITC))
UTICS	= $(addprefix $(UTIDIR), $(UTIS))
PTICS	= $(addprefix $(PTIDIR), $(PTIS))

OBJS			= $(SRCS:.c=.o)
BITJS			= $(BITCS:.c=.o)
UTIJS			= $(UTICS:.c=.o)
PTIJS			= $(PTICS:.c=.o)

ALL_OBJS		=	$(OBJS) $(BITJS) $(UTIJS) $(PTIJS)

%.o:		%.c
			$(CC) $(CFLAGS) -g -I$(INCLUDE) -c $< -o $@

$(NAME):	$(LIBNAME) $(ALL_OBJS)
				$(CC) $(CFLAGS) -g -I$(INCLUDE) -o $(NAME) $(ALL_OBJS)  $(LIBNAME)

$(LIBNAME):
				@$(MAKE) -C $(LIBDIR)
				@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)
all:		$(NAME)

clean:
			$(RM) $(ALL_OBJS)

fclean:		clean
			$(RM) $(NAME) $(LIBNAME)
			@$(MAKE) -C $(LIBDIR) fclean

re:			fclean $(NAME)


.PHONY:			all clean fclean re bonus