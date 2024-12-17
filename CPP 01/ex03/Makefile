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
NAME	=	Weapon
CFILES	=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

DIR_O	= 	tmp/
OBJC	=	$(addprefix $(DIR_O), $(CFILES:.cpp=.o))

#-------------<RULES>-------------
all: $(DIR_O) $(NAME)

$(DIR_O):
	@mkdir -p $(DIR_O)

$(NAME): $(OBJC)
	@$(CC) $(CFLAGS) $(OBJC) -o $(NAME)
	@echo "${GREEN}Weapon Compiled${NC}"
	
$(DIR_O)%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	@echo "${YELLOW}Compiling obj $@...${NC}"

clean: 
	@rm -rf $(DIR_O)
	@printf "${RED}Objs deleted\n${NC}"

fclean: clean 
	@rm -f $(NAME)
	@printf "${RED}Weapon deleted\n${NC}"

re: fclean all

.PHONY: all clean fclean re