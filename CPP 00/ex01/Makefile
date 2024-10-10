# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daortega <daortega@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 16:50:36 by daortega          #+#    #+#              #
#    Updated: 2024/10/09 18:01:12 by daortega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------<COLORS>---------------
GREEN	=	\033[38;5;154m
RED		=	\033[38;5;197m
NC		=	\033[0m
YELLOW	=	\033[38;5;190m

#-------------<COMMANDS>------------
CC 		= 	c++
CFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD -MP

#--------------<SRC>----------------
NAME	=	cpp01
CFILES	=	Contact.cpp PhoneBook.cpp main.cpp

DIR_O	= 	tmp/
OBJC	=	$(addprefix $(DIR_O), $(CFILES:.cpp=.o))

#-------------<RULES>-------------
all: $(DIR_O) $(NAME)

$(DIR_O):
	@mkdir -p $(DIR_O)

$(NAME): $(OBJC)
	@$(CC) $(CFLAGS) $(OBJC) -o $(NAME)
	@echo "${GREEN}CPP01 Compiled${NC}"
	
$(DIR_O)%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	@echo "${YELLOW}Compiling obj $@...${NC}"

clean: 
	@rm -rf $(DIR_O)
	@printf "${RED}Objs deleted\n${NC}"

fclean: clean 
	@rm -f $(NAME)
	@printf "${RED}CPP01 deleted\n${NC}"

re: fclean all

.PHONY: all clean fclean re