# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anouri <anouri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 16:03:37 by anouri            #+#    #+#              #
#    Updated: 2024/05/04 13:42:16 by anouri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= RPN
INCDIR= -I./incs

SRCDIR= ./srcs

# BUILDDIR= ./objs

CXX= c++

CXXFLAGS= -Wall -Werror -Wextra -std=c++98 ${INCDIR} 

SRCS = ${wildcard ${SRCDIR}/*.cpp}

OBJS = ${SRCS:.cpp=.o}
DEPS = $(OBJS:.o=.d)

RM= rm -rf

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -g -o $@

all: ${NAME}

%.o:%.cpp
	${CXX} ${CXXFLAGS} -c -MMD  $< -o $@  -I$(INCDIR)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ${DEPS}

re: fclean all


-include $(DEPS)

.Phony: clean fclean re