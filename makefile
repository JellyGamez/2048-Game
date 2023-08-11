ifeq ($(OS), Windows_NT)
	EXECUTABLE=2048.exe
else
	EXECUTABLE=2048.out
endif


$(EXECUTABLE): 2048.cpp
ifeq ($(OS), Windows_NT)
	g++ 2048.cpp
else
	g++ 2048.cpp -lncurses
endif