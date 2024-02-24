NAME			= miniRT

BUILD			= ./build

SRC				= ./sources

DIRS			= parse

SRCSDIRS		= $(foreach dir, $(DIRS), $(addprefix $(SRC)/, $(dir))) $(SRC)

OBJS			= $(foreach dir, $(SRCSDIRS), \
				$(patsubst $(dir)/%.c, $(BUILD)/%.o, \
				$(shell find $(dir) -maxdepth 1 -name '*.c')))

INCS			= -I./includes -I./lib/libft/includes -I./lib/ft_printf/includes -I./lib/minilibx-linux -I./lib/minilibx_opengl

HEADER			= ./includes/minirt.h ./includes/define.h ./includes/structures.h

CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address

LIB				= -L./lib/libft -lft -L./lib/ft_printf -lftprintf

MINILIBX		= lib/minilibx_opengl

FMS				= -framework OpenGL -framework AppKit

CC				= cc

ifeq ($(shell uname -s), Linux)
	MINILIBX	= lib/minilibx-linux
	FMS			= -L $(MINILIBX) -lmlx -lm -lX11 -lXext
endif

RESET			= \033[0m
YELLOW			= \033[38;2;255;239;0m
GREEN			= \033[38;5;82m
ORANGE			= \033[38;5;208m

$(BUILD)/%.o:	$(SRC)/*/%.c $(HEADER) Makefile
	@printf "${GREEN}✦ ${RESET}"
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(BUILD)/%.o:	$(SRC)/%.c $(HEADER) Makefile
	@echo "${GREEN}✦ ${RESET}"
	@$(CC) $(FLAGS) $(INCS) -c $< -o $@

all:			mlx lib $(BUILD) $(NAME)

${NAME}:		${OBJS}
	@$(CC) $(FLAGS) $(OBJS) $(INCS) -o ${NAME} $(LIB)
	@echo "${ORANGE}Ray Tracer created 🧩${RESET}"

$(BUILD):
	@mkdir -p $(BUILD)

mlx:
	@printf "${YELLOW}🧩 Compiling MiniLibX ${RESET}"
	@make -C $(MINILIBX) > /dev/null 2>&1 & i=0; \
	while ps -p $$! > /dev/null; do \
		printf "${GREEN}✦ ${RESET}"; \
		sleep 0.2; \
	done
	@echo "${YELLOW} Done 🧩${RESET}"

lib:
	@printf "${YELLOW}🧩 Compiling Libft Printf ${RESET}"
	@make -C lib/ft_printf > /dev/null
	@make -C lib/libft > /dev/null 2>&1 & i=0; \
	while ps -p $$! > /dev/null; do \
		printf "${GREEN}✦ ${RESET}"; \
		sleep 0.2; \
	done
	@echo "${YELLOW} Done 🧩${RESET}"

clean:
	@make clean -C lib/ft_printf
	@make clean -C lib/libft
	@make clean -C $(MINILIBX) > /dev/null
	@rm -rf $(BUILD) > /dev/null

fclean:
	@make fclean -C lib/ft_printf
	@make fclean -C lib/libft
	@make clean -C $(MINILIBX) > /dev/null
	@rm -rf $(BUILD) > /dev/null
	@rm -f ${NAME}
	@echo "${YELLOW} Everything is cleared ✅${RESET}"

re:			fclean all

.PHONY:		all clean fclean re lib