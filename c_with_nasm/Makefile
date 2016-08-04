div.o:div.asm Makefile
	nasm -f elf -o div.o div.asm

main.o:main.c Makefile
	gcc -m32 -c -o main.o main.c

run:main.o div.o
	gcc -m32 -o run div.o main.o

clean:
	rm *.o
	rm run

build:
	make run
	./run
