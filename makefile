CFLAGS = -Wall -g 
f = exe
all:
	gcc -lncurses caligula.c -o $f
	gcc -lncurses test.c -o test

run:
	./$f


clean:
	rm -f $f
	rm -f test

