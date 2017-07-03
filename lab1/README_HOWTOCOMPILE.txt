How to compile main program:

Run the following:
g++ --std=c++11 krs0048_1.cpp MenuInteractionHandler.cpp Menu.cpp User.cpp WallPage.cpp HomePage.cpp -o krs0048_1.o

How to compile unit test cases:
g++ --std=c++11 Tests.cpp MenuInteractionHandler.cpp Menu.cpp User.cpp WallPage.cpp HomePage.cpp -o unitTests.o