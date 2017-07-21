OBJS = krs0048_2.o ConcurrencyHandler.o MenuInteractionHandler.o Menu.o User.o WallPage.o HomePage.o
CC = g++
DEBUG = -g
CXXFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

krs0048_2 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o krs0048_2

krs0048_2.o : krs0048_2.cpp ConcurrencyHandler.h MenuInteractionHandler.h Menu.h User.h WallPage.h HomePage.h
	$(CC) $(CXXFLAGS) krs0048_2.cpp

Menu.o : Menu.cpp ConcurrencyHandler.o MenuInteractionHandler.h User.h WallPage.h HomePage.h
	$(CC) $(CXXFLAGS) Menu.cpp

MenuInteractionHandler.o : MenuInteractionHandler.cpp ConcurrencyHandler.h User.h WallPage.h HomePage.h
	$(CC) $(CXXFLAGS) MenuInteractionHandler.cpp

ConcurrencyHandler.o : User.h User.cpp ConcurrencyHandler.h
	$(CC) $(CXXFLAGS) ConcurrencyHandler.cpp

WallPage.o : WallPage.cpp User.h
	$(CC) $(CXXFLAGS) WallPage.cpp

HomePage.o : HomePage.cpp User.h
	$(CC) $(CXXFLAGS) HomePage.cpp

User.o : User.h
	$(CC) $(CXXFLAGS) User.cpp

clean:
	\rm *.o krs0048_2
