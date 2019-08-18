# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/07 13:02:13 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/06/19 18:33:57 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
# **************************************************************************** #

NAME = gbmu
TYPE = "of the executable"

LIBFT_M :
	@make -C libft/ all

CFLAGS = -Wall -Wextra -g3

INCLUDE = -Iincludes -Ilibft/includes

HEADER = gbmu.h gbmu_enum.h

LIBFT = libft/libft.a

CC = gcc

OBJ = $(SRC:.c=.o)

DSRC = srcs/
DOBJ = obj/
MDOBJ = obj
ALL_D = $(DSRC)

DHEADER = includes/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))
CHEADER = $(addprefix $(DHEADER),$(HEADER))

# *****************************************************************************#
# 								ALL  SCRS									   #
# *****************************************************************************#

SRC =	main.c

COUNT = "1"
SPACE = "                    "
.DEFAULT_GOAL := all
 ESC = $(shell printf '\033')

print_name :
	@printf "\n----------------------------------------------------------------------\n\n${ESC}[37m"
	@printf " ${ESC}[47m  ${ESC}[0m${ESC}[37m                    [   GBMU_CORE    ]            "
	@printf "         ${ESC}[0m  ${ESC}[47m  ${ESC}[0m\n"
	@printf "\n----------------------------------------------------------------------\n\n"

print_norme :
	@printf "\n----------------------------------------------------------------------\n\n${ESC}[37m"
	@printf " ${ESC}[47m  ${ESC}[0m${ESC}[37m                    [  GBMU_CORE NORME     ]      "
	@printf "         ${ESC}[0m  ${ESC}[47m  ${ESC}[0m\n"
	@printf "\n----------------------------------------------------------------------\n\n"

all: LIBFT_M print_name $(NAME)
	@if [ $(COUNT) = "1" ]; then \
		echo $(SPACE)"${ESC}[1;34m   Nothing are changed !${ESC}[0m"; \
	fi

$(NAME): $(COBJ) $(LIBFT)
	@echo $(SPACE)"${ESC}[JCompilation${ESC}[1;32m completed${ESC}[0m"
	@echo $(SPACE)"Compilation" $(TYPE) "${ESC}[34m" $(NAME) "${ESC}[0m"
	@$(CC) $(COBJ) $(CFLAGS) $(NCURSES) $(LIBFT) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) $(LIBFT)
	@$(eval COUNT = "0")
	@mkdir -p $(MDOBJ)
	@mkdir -p $(addprefix $(DOBJ), $(ALL_D))
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $(SPACE)"Compilation from fonction ${ESC}[1;32m"$< "${ESC}[0m${ESC}[K${ESC}[1A"

clean: print_name
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Deleting ${ESC}[1;31mobjects${ESC}[0m"
	@make -C libft/ clean

fclean: print_name
	@rm -f $(NAME)
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Deleting ${ESC}[1;31m"$(NAME) "${ESC}[0m"
	@echo $(SPACE)"Deleting ${ESC}[1;31mobjects${ESC}[0m"
	@make -C libft/ fclean


re: print_name
	@rm -f $(NAME)
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Deleting ${ESC}[1;31m"$(NAME) "${ESC}[0m"
	@echo $(SPACE)"Deleting ${ESC}[1;31mobjects${ESC}[0m"
	@make all

debug:
	@printf "[ debug ]\n"
	@./gbmu -v 31

norme : print_norme
	@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"


.PHONY: default all fclean clean re norme print_norme print_name
