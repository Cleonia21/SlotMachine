NAME	=	slot_machine

CC		=	c++ -Wall -Wextra -Werror -std=c++17
LIBS	=	-I/usr/local/include/SDL2 -D_THREAD_SAFE -L/usr/local/lib -lSDL2 -lSDL2_image

HPP		=	Texture.hpp \
            Button.hpp \
            Game.hpp \
			Drum.hpp \
            DrumSymbol.hpp \
            StateInterface.hpp \
            RotationState.hpp \
            StopState.hpp \
			WaitingState.hpp \
            WinState.hpp \
            ButtonsInterface.hpp \

CPP		=	main.cpp \
			Texture.cpp \
			Button.cpp \
			Game.cpp \
			Drum.cpp \
			DrumSymbol.cpp \
			StateInterface.cpp \
			RotationState.cpp \
			StopState.cpp \
            WaitingState.cpp \
            WinState.cpp \
            ButtonsInterface.cpp \

OBJ_DIR	=	.objs/
OBJS	=	$(addprefix $(OBJ_DIR), $(CPP:.cpp=.o))

all: 		$(NAME)

$(OBJ_DIR):
			mkdir -p $@

$(OBJ_DIR)%.o: %.cpp $(HPP)
			$(CC) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
			$(CC) $(LIBS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJ_DIR)

fclean: clean
			rm -f $(NAME) $(MEBOT)

re: fclean all

.PHONY: all clean fclean re