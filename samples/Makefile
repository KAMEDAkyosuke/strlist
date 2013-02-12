CC         = clang
CFLAGS    += --std=c99 -Wall -Wextra -Wno-unused-parameter -pedantic
LDFLAGS   += 
LDLIBS    += 
OBJS       = 
TARGETS    = sample

sample: sample.c strlist.o
	$(CC) -o sample sample.c strlist.o

strlist.o: ../strlist.c
	$(CC) -c ../strlist.c

../strlist.c: ../strlist.h

.PHONY: clean
clean:
	$(RM) *.o $(TARGETS)

.PHONY: check-syntax
check-syntax:
	$(CC) $(CFLAGS) -fsyntax-only $(CHK_SOURCES)
