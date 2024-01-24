wallp:main.o
	g++ -o wallp main.o
main.o:main.cpp
	g++ -c main.cpp 

.PHONY clean:
	rm -rf wallp main.o
