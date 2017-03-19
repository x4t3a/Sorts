export CC := gcc
export CFLAGS := --std=c11 -g
INCLUDE := -I"Include"

run: Bin/x4test
	$^

Bin/x4test: Bin/x4sort.o Test/x4test.c
	${CC} ${CFLAGS} $^ -o $@ ${INCLUDE}

Bin/x4sort.o: Bin Include/x4sort.h Src/x4sort.c
	${CC} ${CFLAGS} -c Src/x4sort.c -o $@ ${INCLUDE}

Bin:
	mkdir Bin

clean:
	git clean -fdx
