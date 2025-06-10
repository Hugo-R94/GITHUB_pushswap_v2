NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCSDIR = srcs
BONUSDIR = bonus
OBJDIR = objs
BONUSOBJDIR = bonus_objs
INCLUDES = headers

SRC = \
	$(SRCSDIR)/ft_atoi.c \
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
	$(SRCSDIR)/sort_long_2.c \
	$(SRCSDIR)/utils_lst.c \
	$(SRCSDIR)/utils.c \
	

BONUS_SRC = \
	$(BONUSDIR)/checker.c \
	$(BONUSDIR)/func_push_bonus.c \
	$(BONUSDIR)/func_reverse_rotate_bonus.c \
	$(BONUSDIR)/func_rotate_bonus.c \
	$(BONUSDIR)/func_swap_bonus.c \
	$(BONUSDIR)/parsing_bonus.c \
	$(BONUSDIR)/get_next_line_utils.c \
	$(BONUSDIR)/get_next_line.c \
	$(BONUSDIR)/checker_utils.c \
	$(BONUSDIR)/checker_utils2.c \
	$(BONUSDIR)/checker_utils3.c \
	$(BONUSDIR)/ft_split_bonus.c \
	$(BONUSDIR)/ft_atoi_bonus.c 
	
OBJ = $(SRC:$(SRCSDIR)/%.c=$(OBJDIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:$(BONUSDIR)/%.c=$(BONUSOBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(OBJ)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $(BONUS) $(BONUS_OBJ)

$(OBJDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(BONUSOBJDIR)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(BONUSOBJDIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(BONUSOBJDIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
