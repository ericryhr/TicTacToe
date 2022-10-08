TicTacToe: main.cc Board.o AI.o
	g++ -o TicTacToe.exe main.cc Board.o AI.o

Board: Board.cc Board.h
	g++ -c Board.cc

AI: AI.cc AI.h
	g++ -c AI.cc

clean:
	rm -f Board.o AI.o TicTacToe.exe