#------------<COLORS>---------------
GREEN	=	\033[38;5;154m
RED		=	\033[38;5;197m
NC		=	\033[0m
YELLOW	=	\033[38;5;190m

#-------------<COMMANDS>------------
CC 		= 	c++
CFLAGS 	= 	-Wall -Wextra -Werror -std=c++98 -fsanitize=address
DEPFLAGS = -MMD -MP

#--------------<SRC>----------------
NAME	=	Zombie
CFILES	=	main.cpp Fixed.cpp 

DIR_O	= 	tmp/
OBJC	=	$(addprefix $(DIR_O), $(CFILES:.cpp=.o))

#-------------<RULES>-------------
all: $(DIR_O) $(NAME)

$(DIR_O):
	@mkdir -p $(DIR_O)

$(NAME): $(OBJC)
	@$(CC) $(CFLAGS) $(OBJC) -o $(NAME)
	@echo "${GREEN}Zombie Compiled${NC}"
	
$(DIR_O)%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@
	@echo "${YELLOW}Compiling obj $@...${NC}"

clean: 
	@rm -rf $(DIR_O)
	@printf "${RED}Objs deleted\n${NC}"

fclean: clean 
	@rm -f $(NAME)
	@printf "${RED}Zombie deleted\n${NC}"

re: fclean all

.PHONY: all clean fclean re