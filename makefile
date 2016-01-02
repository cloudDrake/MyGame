.PHONY: MyGame
	
MyGame: src/main.cpp src/Board.cpp src/Tile.cpp
	g++ src/Board.cpp src/Tile.cpp src/main.cpp -o MyGame -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: clean
clean:
	rm MyGame
