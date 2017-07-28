OBJS = krs0048_3p.o MazeGame.o Node.o
CC = g++
DEBUG = -g
CXXFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

krs0048_3p : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o krs0048_3p

krs0048_3p.o : krs0048_3p.cpp MazeGame.h Node.h
	$(CC) $(CXXFLAGS) krs0048_3p.cpp

MazeGame.o : MazeGame.cpp Node.h
	$(CC) $(CXXFLAGS) MazeGame.cpp

Node.o : Node.cpp
	$(CC) $(CXXFLAGS) Node.cpp


clean:
	\rm *.o krs0048_3p
