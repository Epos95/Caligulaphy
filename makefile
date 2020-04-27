CFLAGS = -Wall -g
f = exe
all:
	gcc -lncurses caligula.c -o $f

run:
	./$f

clean:
	rm -f $f
