ifeq ($(OS), Windows_NT)
	EXECUTABLE=main.exe
else
	EXECUTABLE=main.out
endif


$(EXECUTABLE): 2048.cpp
ifeq ($(OS), Windows_NT)
	g++ main.cpp
else
	g++ main.cpp -lncurses
endif