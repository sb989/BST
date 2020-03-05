PROJECT = proj_1
CC = gcc

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

INC_PATHS = ../include
INC_PARAMS = $(foreach d, $(INC_PATHS), -I$d)

LFLAGS = -g -o ../$(PROJECT)
CFLAGS = -g -std=gnu99 $(INC_PARAMS)

$(PROJECT): $(OBJECTS)
	$(CC) $(OBJECTS) $(LFLAGS)

sources:
	echo (patsubst %.c,%.o,$(wildcard *.c)) > makefile.sources

makefile.dep: depend

depend:
	@touch makefile.dep
	@-rm makefile.dep
	@echo Creating dependencies.
	@for i in *.c; do $(CC) $(INC) -MM $(INC_PARAMS) $$i; done > makefile.dep
	@echo Done.

clean:
	rm *.o

count:
	wc -l *.c $(foreach d, $(INC_PATHS), $d/*.h) makefile

include makefile.dep

.c.o:
	$(CC) $(CFLAGS) -c $<
