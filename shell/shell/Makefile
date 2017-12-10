\all:mytoc shell

CFLAGS = -g -O2

shell:sh.o mytoc.o
	cc -o shell sh.o mytoc.o

mytoc:mytoc.o test.o
	cc -o mytoc mytoc.o test.o

clean:
	rm -r *.o
