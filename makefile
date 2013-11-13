CC = gcc

SH =bash
all:musiclib
musiclib: new.o \
	   	  Queue.o
	$(CC) -g -o $@ $^ `pkg-config --libs --cflags gtk+-2.0` -lmp

new.o:media_library.c \
			Queue.h
	$(CC) -g -o $@ -c $< `pkg-config --libs --cflags gtk+-2.0` -lmp

Queue.o: Queue.c \
	   Queue.h
	$(CC) -g  -o $@ -c $<

clean :
		rm -rf *.o *.out global_songs.txt Artists.txt Albums.txt

install: all
	sudo cp musiclib /usr/bin/
	sudo cp Music* /usr/share/applications/
uninstall:
	sudo rm -f /usr/bin/musiclib
	sudo rm  -f /usr/share/applications/Music*
