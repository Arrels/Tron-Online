################################################################
#
# Tron Make
#
#
################################################################

CC      = g++
CFLAGS  = -c -Wall -Werror -Isrc/include
LDFLAGS = -lliballegro
OBJECTS = obj/main.o \
          obj/application.o


all: bin/tron.exe

bin/tron.exe: obj/main.o obj/player.o obj/tronapplication.o
	$(CC) -o $@ $^ $(LDFLAGS)

obj/main.o: src/application/main.cpp
	$(CC) $(CFLAGS) $^ -o $@

obj/player.o: src/player/player.cpp
	$(CC) $(CFLAGS) $^ -o $@

obj/tronapplication.o: src/application/tronapplication.cpp
	$(CC) $(CFLAGS) $^ -o $@


.PHONY: clean cleanest

clean:
	rm obj/*.o

cleanest:
	rm bin/*
