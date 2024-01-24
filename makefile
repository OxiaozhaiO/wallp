wallp:main.o
	g++ -o wallp main.o
main.o:main.cpp
	g++ -c main.cpp 

install:wallp
	cp wallp /bin/
uninstall:
	rm /bin/wallp
.PHONY clean:
	rm -rf wallp main.o
