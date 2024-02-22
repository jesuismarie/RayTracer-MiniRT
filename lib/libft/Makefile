NAME			= libft.a

BUILD			= ./build

SRC				= ./sources

SRCS			= $(shell find $(SRC) -name '*.c')

OBJS			= $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

INCS			= -I./includes

HEADER			= ./includes/libft.h

RM				= rm -f

AR				= ar rcs

CC				= cc

FLAGS 			= -Wall -Wextra -Werror

RESET			= \033[0m
BLUE			= \033[34m
CYAN			= \033[36m
YELLOW			= \033[38;2;255;239;0m

$(BUILD)/%.o:	$(SRC)/%.c $(HEADER) Makefile
		@echo "${CYAN} Compiling $<${RESET}"
		@$(CC) $(FLAGS) $(INCS) -c $< -o $@

all:			$(BUILD) $(NAME)

$(NAME):		$(OBJS) 
		@$(AR) $(NAME) $(OBJS)
		@echo "${YELLOW}Libft compiled ✨ ${RESET}"

$(BUILD):
		@mkdir -p $(BUILD)

clean:
		@echo "${BLUE} Removing Libft $(BUILD) ${RESET}"
		@rm -rf $(BUILD)

fclean:
		@echo "${BLUE} Removing Libft $(BUILD) ${RESET}"
		@echo "${BLUE} Removing ${NAME} ${RESET}"
		@rm -rf $(BUILD)
		@$(RM) $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re