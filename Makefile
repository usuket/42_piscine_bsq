# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 13:08:08 by ysakakib          #+#    #+#              #
#    Updated: 2017/01/30 13:08:10 by ysakakib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE          =bsq
SRCS         =./srcs/*.c
INCLUDES     =./includes/

all: fclean $(EXE)

$(EXE):
	gcc -Wall -Wextra -Werror -I $(INCLUDES) $(SRCS) -o $(EXE)
#	gcc -I $(INCLUDES) $(SRCS) -o $(EXE)

clean:
	rm -f *.o

fclean: clean
	rm -f bsq