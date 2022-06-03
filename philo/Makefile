# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobougre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 13:27:10 by yobougre          #+#    #+#              #
#    Updated: 2022/06/03 08:40:03 by yobougre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	philo

SRCS=	srcs/philo_main.c

INCL=	includes/includes.h\
		includes/struct.h\
		includes/philo.h

OBJS=	$(SRCS:.c=.o)

CFLAGS=	-Wall -Werror -Wextra -g3

RM=		rm -f

CC=		gcc

all: $(NAME)

$(NAME): $(INCL) $(OBJS)
	@echo "\033[1;34m"
	@echo "Project name : $(NAME)"
	@echo "\n\033[1;32mOn going compilation... ⌛\033[0;m\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)	
	@make wait
	@echo "Bonne correction!"

clean:
	@$(RM) $(OBJS)
	@echo -n "\033[0;31m⠀"
	@echo "Erase .o files"
	@echo "[##############]"
	@echo "　╭━╮╭━╮ ╭╮ ╱ "　　
	@echo "　╰━┫╰━┫ ╰╯╱ ╭╮ "　　
	@echo "　╰━╯╰━╯　╱　╰╯" 　　　　　
	@echo "　     COMPLETE"
	@echo "\033[1;1;32m♻️  Objects and $(NAME) have been \033[5;1;31mdeleted\033[m ♻️"

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "\033[1;31m ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣶⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣄⣀⡀⣠⣾⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⡇⠀⠀⠀⠀"
	@echo "⠀⣶⣿⣦⣜⣿⣿⣿⡟⠻⣿⣿⣿⣿⣿⣿⣿⡿⢿⡏⣴⣺⣦⣙⣿⣷⣄⠀⠀⠀\033[1;34m Goodbye everyone\033[1;31m"
	@echo "⠀⣯⡇⣻⣿⣿⣿⣿⣷⣾⣿⣬⣥⣭⣽⣿⣿⣧⣼⡇⣯⣇⣹⣿⣿⣿⣿⣧⠀⠀"
	@echo "⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣿⣿⣿⣿⣿⣷⠀\033[m"
	@echo "\033[1;1;32m♻️  Objects have been \033[5;1;31mdeleted\033[m ♻️"

wait:
	@echo -n "\r  5%  [\033[0;31m█\033[m.........................]"
	@sleep 0.1
	@clear
	@echo -n "\r 10%  [\033[0;31m███\033[m.......................]"
	@sleep 0.1
	@clear
	@echo -n "\r 15%  [\033[0;31m████\033[m......................]"
	@sleep 0.1
	@clear
	@echo -n "\r 20%  [\033[0;31m██████\033[m....................]"
	@sleep 0.1
	@clear
	@echo -n "\r 27%  [\033[0;31m████████\033[m..................]"
	@sleep 0.1
	@clear
	@echo -n "\r 32%  [\033[0;31m██████████\033[m................]"
	@sleep 0.1
	@clear
	@echo -n "\r 35%  [\033[0;31m███████████\033[m...............]"
	@sleep 0.1
	@clear
	@echo -n "\r 45%  [\033[0;31m█████████████\033[m.............]"
	@sleep 0.1
	@clear
	@echo -n "\r 50%  [\033[0;31m███████████████\033[m...........]"
	@sleep 0.1
	@clear
	@echo -n "\r 65%  [\033[0;31m██████████████████\033[m........]"
	@sleep 0.1
	@clear
	@echo -n "\r 80%  [\033[0;31m█████████████████████\033[m.....]"
	@sleep 0.1
	@clear
	@echo -n "\r 90%  [\033[0;31m████████████████████████\033[m..]"
	@sleep 0.1
	@clear
	@echo -n "\r 95%  [\033[0;31m█████████████████████████\033[m.]"
	@sleep 0.1
	@clear
	@echo -n "\r 99%  [\033[0;31m██████████████████████████\033[m]"
	@sleep 0.5
	@clear
	@echo -n "\r 100% [\033[0;32m██████████████████████████\033[m]\033[0;32m compilation terminee ✓\n\033[0;m"
re:		fclean all

.PHONY: all clean fclean re
