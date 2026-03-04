NAME			= miniRT

BUILD			= build

SRC				= sources

MAKEFILEFLAGS	= --no-print-directory

DIRS			= parse constructor vector graphics ray_tracing control utils

SRCSDIRS		= $(foreach dir, $(DIRS), $(addprefix $(SRC)/, $(dir))) $(SRC)

OBJS			= $(foreach dir, $(SRCSDIRS), \
				$(patsubst $(dir)/%.c, $(BUILD)/%.o, \
				$(shell find $(dir) -maxdepth 1 -name '*.c')))

INCS			= -I./includes -I./lib/libft/includes -I./lib/ft_printf/includes \
				-I./lib/minilibx_opengl

HEADER			= ./includes/minirt.h ./includes/defines.h ./includes/structures.h ./includes/parse.h

FLAGS			= -Wall -Wextra -Werror -Wno-cast-function-type #-g3 -fsanitize=address

LIB				= -L./lib/libft -lft -L./lib/ft_printf -lftprintf -L $(MINILIBX) -lmlx

MINILIBX		= lib/minilibx_opengl

FMS				= -framework OpenGL -framework AppKit

CC				= cc

ifeq ($(shell uname -s), Linux)
	INCS		= -I./includes -I./lib/libft/includes -I./lib/ft_printf/includes \
				-I./lib/minilibx-linux
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
	@$(CC) $(FLAGS) $(OBJS) $(INCS) $(LIB) $(FMS) -o ${NAME}
	@echo "${ORANGE}Ray Tracer created 🧩${RESET}"
	@echo "$(ORANGE)--------------------------------------------------------$(RESET)"
	@echo "$(ORANGE)| Usage               | ./miniRT <path/to/scene.rt>    |$(RESET)"
	@echo "$(ORANGE)--------------------------------------------------------$(RESET)"
	@echo "$(ORANGE)| Recommended Scenes  | scenes/white.rt                |$(RESET)"
	@echo "$(ORANGE)|                     | scenes/complex.rt              |$(RESET)"
	@echo "$(ORANGE)--------------------------------------------------------$(RESET)"
	@echo "$(ORANGE)| Help                | make help                      |$(RESET)"
	@echo "$(ORANGE)--------------------------------------------------------$(RESET)"

$(BUILD):
	@mkdir -p $(BUILD)

mlx:
	@printf "${YELLOW}🧩 Compiling MiniLibX ${RESET}"
	@make -C $(MINILIBX) > /dev/null 2>&1 & i=0; \
	while ps -p $$! > /dev/null; do \
		printf "${GREEN}✦ ${RESET}"; \
		sleep 0.3; \
	done
	@echo "${YELLOW} Done 🧩${RESET}"

lib:
	@printf "${YELLOW}🧩 Compiling Libft Printf ${RESET}"
	@make $(MAKEFILEFLAGS) -C lib/ft_printf > /dev/null
	@make $(MAKEFILEFLAGS) -C lib/libft > /dev/null 2>&1 & i=0; \
	while ps -p $$! > /dev/null; do \
		printf "${GREEN}✦ ${RESET}"; \
		sleep 0.3; \
	done
	@echo "${YELLOW} Done 🧩${RESET}"

help:
	@echo "$(ORANGE)--------------------------------------------------------$(RESET)"
	@echo "$(ORANGE)| Controls    | T     - Apply texture                  |$(RESET)"
	@echo "$(ORANGE)|             | B     - Apply bump map                 |$(RESET)"
	@echo "$(ORANGE)|             | C     - Apply checkerboard             |$(RESET)"
	@echo "$(ORANGE)--------------------------------------------------------$(RESET)"

clean:
	@make $(MAKEFILEFLAGS) clean -C lib/ft_printf
	@make $(MAKEFILEFLAGS) clean -C lib/libft
	@make $(MAKEFILEFLAGS) clean -C $(MINILIBX) > /dev/null
	@rm -rf $(BUILD)

fclean:
	@make $(MAKEFILEFLAGS) fclean -C lib/ft_printf
	@make $(MAKEFILEFLAGS) fclean -C lib/libft
	@make $(MAKEFILEFLAGS) clean -C $(MINILIBX) > /dev/null
	@rm -rf $(BUILD)
	@rm -f ${NAME}
	@echo "${YELLOW} Everything is cleared ✅${RESET}"

re:			fclean all

.PHONY:		all clean fclean re lib mlx