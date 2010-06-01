all: main.c
	gcc -fPIC -shared -I/usr/include/python2.6 main.c `pkg-config --cflags --libs cairo` -o cairo.so

clean:
	rm cairo.so helloPython.png
