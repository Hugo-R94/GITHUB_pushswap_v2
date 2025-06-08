NAME = push_swap.a
EXEC = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCSDIR = srcs
OBJDIR = objs
INCLUDES = headers

# Liste manuelle des .c
CFILES = $(SRCSDIR)/ft_atoi.c \
         $(SRCSDIR)/ft_putstr_fd.c \
         $(SRCSDIR)/ft_split.c \
         $(SRCSDIR)/func_push.c \
         $(SRCSDIR)/func_reverse_rotate.c \
         $(SRCSDIR)/func_rotate.c \
         $(SRCSDIR)/func_swap.c \
         $(SRCSDIR)/get_all.c \
         $(SRCSDIR)/parsing.c \
         $(SRCSDIR)/push_swap.c \
         $(SRCSDIR)/set_all.c \
         $(SRCSDIR)/sort_base.c \
         $(SRCSDIR)/sort_long.c \
         $(SRCSDIR)/utils_lst.c \
		  $(SRCSDIR)/print.c


		

# Génère les .o correspondants
OFILES = $(CFILES:$(SRCSDIR)/%.c=$(OBJDIR)/%.o)

all: $(EXEC)

# Génère la librairie statique
$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

# Compile l'exécutable push_swap à partir de la lib
$(EXEC): $(NAME)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $(EXEC) $(NAME)

# Compilation des .o depuis les .c
$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
