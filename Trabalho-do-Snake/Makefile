snake :  snake.o main.o
	gcc -o snake -pg snake.o main.o -lncurses

main.o : main.c
	gcc -c -pg main.c 

snake.o : snake.c snake.h
	gcc -c -pg snake.c 

clean: 
	rm *.o snake
