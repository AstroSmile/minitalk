# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-maro <ana-maro@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 17:54:16 by ana-maro          #+#    #+#              #
#    Updated: 2024/06/09 18:30:01 by ana-maro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
CLIENT_BON = client_bonus
SERVER = server
SERVER_BON = server_bonus
LIBFT = lib/libft/
MINITALK = include/
CC_FLAGS = gcc -Wall -Wextra -Werror
RM = rm -f
INCLUDE = -L ./lib/libft -lft
DEPS = -I include

SRCS_SRV = src/server.c
SRCS_CLT = src/client.c

B_SRC_SV = src/server_bonus.c
B_SRC_CL = src/client_bonus.c

OBJ_SRV = $(SRCS_SRV:.c=.o)
OBJ_CLT = $(SRCS_CLT:.c=.o)

B_OBJ_SR = $(B_SRC_SV:.c=.o)
B_OBJ_CL = $(B_SRC_CL:.c=.o)

################################################################################
##                                    COLOURS                                 ##
################################################################################

RED = \033[0;31m
GREEN = \033[0;32m
END = \033[0m

################################################################################
##                                     RULES                                  ##
################################################################################

all : head libft $(CLIENT) $(SERVER)

bonus : head libft $(CLIENT_BON) $(SERVER_BON)

head :
	@echo "$(RED)"
	@echo "\t @@@@@@@@@@   @@@  @@@  @@@  @@@  @@@@@@@   @@@@@@   @@@       @@@  @@@ "
	@echo "\t @@@@@@@@@@@  @@@  @@@@ @@@  @@@  @@@@@@@  @@@@@@@@  @@@       @@@  @@@ "
	@echo "\t @@! @@! @@!  @@!  @@!@!@@@  @@!    @@!    @@!  @@@  @@!       @@!  !@@ "
	@echo "\t !@! !@! !@!  !@!  !@!!@!@!  !@!    !@!    !@!  @!@  !@!       !@!  @!! "
	@echo "\t @!! !!@ @!@  !!@  @!@ !!@!  !!@    @!!    @!@!@!@!  @!!       @!@@!@!  "
	@echo "\t !@!   ! !@!  !!!  !@!  !!!  !!!    !!!    !!!@!!!!  !!!       !!@!!!   "
	@echo "\t !!:     !!:  !!:  !!:  !!!  !!:    !!:    !!:  !!!  !!:       !!: :!!  "
	@echo "\t :!:     :!:  :!:  :!:  !:!  :!:    :!:    :!:  !:!   :!:      :!:  !:! "
	@echo "\t :::     ::    ::   ::   ::   ::     ::    ::   :::   :: ::::   ::  ::: "
	@echo "\t  :      :    :    ::    :   :       :      :   : :  : :: : :   :   ::: "
	@echo "\t                        42MALAGA: by ana-maro"
	@echo "\tProyect: \033[36m Minitalk $(RED)"
	@echo "\t"                                      

libft :
	@make -s -C $(LIBFT)

$(CLIENT) : $(OBJ_CLT)
	@$(CC_FLAGS) $(OBJ_CLT) $(INCLUDE) -o $(CLIENT)

$(SERVER) : $(OBJ_SRV)
	@$(CC_FLAGS) $(OBJ_SRV) $(INCLUDE) -o $(SERVER)

#$(CLIENT_BON) : $(B_OBJ_CL)
#	@$(CC_FLAGS) $(B_OBJ_CL) $(INCLUDE) -o $(CLIENT_BON)

#$(SERVER_BON) : $(B_OBJ_SR)
#	@$(CC_FLAGS) $(B_OBJ_SR) $(INCLUDE) -o $(SERVER_BON)

%.o : %.c $(MINITALK)
	@$(CC_FLAGS) -c $< -o $@ $(DEPS)
	@echo "$(GREEN)  ✓ Compiled"

clean:
	@$(RM) $(OBJ_SRV) $(OBJ_CLT) $(B_OBJ_SR) $(B_OBJ_CL)
	@echo "$(GREEN)\r  ✓  $(GREEN)Limpiando objetos desde $(CLIENT) and $(SERVER) $(END)"
	@make clean -s -C $(LIBFT)

fclean:
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BON) $(SERVER_BON)
#@$(RM) $(OBJ_SRV) $(OBJ_CLT) $(B_OBJ_SR) $(B_OBJ_CL)
	@echo "$(GREEN)\r  ✓  $(GREEN)Limpieza completa de $(CLIENT) and $(SERVER) $(END)"

re: fclean clear all

.PHONY: all clean fclean re bonus