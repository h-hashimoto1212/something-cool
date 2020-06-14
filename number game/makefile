number: number_game.o number_game_utils.o
	g++ number_game.o number_game_utils.o -o number

number_game.o: number_game.cpp
	g++ -c number_game.cpp

number_game_utils.o: number_game_utils.cpp
	g++ -c number_game_utils.cpp

clean: 
	rm *.o number