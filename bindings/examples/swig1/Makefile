all: python perl java csharp ruby
	

python: main.c main.i
	swig -python main.i
	gcc -fPIC -c -I/usr/include/python2.6 main.c main_wrap.c
	ld -shared main.o main_wrap.o -o _matematicas.so

perl: main.i
	swig -perl main.i

java: main.i
	swig -java main.i

csharp: main.i
	swig -csharp main.i

ruby: main.i
	swig -ruby -o main_wrap_ruby.c main.i

clean:
	rm *.so *.o *_wrap* *.pyc *.cs *.java *.pm
