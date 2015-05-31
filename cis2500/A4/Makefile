
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-std=c99 -Wall  -pedantic -g -Iinclude


diary:
	gcc $(CFLAGS)  src/diary.c src/linkedList.c -o bin/runMe

test: 
	gcc $(CFLAGS) src/diary.c src/linkedList.c  -o bin/listTest

clean:
	@ rm *.o