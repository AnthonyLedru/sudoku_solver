# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aledru <aledru@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 16:42:45 by aledru            #+#    #+#              #
#*   Updated: 2018/02/16 20:24:33 by aledru           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME := sudoku_solver

INCLUDE_FOLDERS := -I includes/
SOURCES_FOLDER  := srcs/
OBJECTS_FOLDER  := objs/

vpath %.c srcs

FLAGS := -Wall -Wextra -Werror

SOURCES := \
		check_init.c \
		check.c \
		comp_tab.c \
		error.c \
		main.c \

OBJECTS := $(SOURCES:.c=.o)

OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER), $(SOURCES))

NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
HEAD_COLOR   := \x1b[32;01m
SILENT_COLOR := \x1b[30;01m

HEADER_PRINTED := NO

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "\n$(SILENT_COLOR)Compiling $(NAME)...$(NO_COLOR)"
	@$(CC) -o $(NAME) $(OBJECTS) $(FLAGS)
	@printf " $(OK_COLOR)Done ✓$(NO_COLOR)"

objs/%.o: %.c
	@if [ "$(HEADER_PRINTED)" = "NO" ]; then \
		printf "\n$(HEAD_COLOR)--------------------------------\n"; \
		printf "$(HEAD_COLOR)-------- SUDOKU SOLVER ---------\n"; \
		printf "$(HEAD_COLOR)--------------------------------$(NO_COLOR)\n\n"; \
		$(eval HEADER_PRINTED = YES) \
	fi
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE_FOLDERS) -c $< -o $@
	@printf "$(notdir $<) "
	@printf "$(OK_COLOR)✓$(NO_COLOR)\n"

clean:
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(SILENT_COLOR)$(NAME) : Objects removed$(NO_COLOR)\n"

fclean:
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(SILENT_COLOR)$(NAME) : Objects removed$(NO_COLOR)\n"
	@rm -f $(NAME)
	@printf "$(SILENT_COLOR)$(NAME) : Binary removed $(NO_COLOR)\n"

re: 
	@make fclean 
	@make all

.PHONY: all clean fclean re header
