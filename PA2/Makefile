# Make file for Lab Exercise 2
# WRITTEN BY: Michael Main (main@colorado.edu), Jan 11, 1997
# MODIFIED BY:  Glynis Hamel 3/2/99
# MODIFIED BY:  Glynis Hamel 3/21/02
# MODIFIED BY:  Glynis Hamel 11/14/05 Converted from C++ to C
# MODIFIED BY:  Hugh Lauer 04/06/09 Substituted $(CFLAGS) for -g
# MODIFIED BY:  Steve Kelly 09/05/12 Use in life assignment
#
# This makefile is used as follows to regenerate files for the life program:
#   make intarray.o   --  Regenerates intarray.o by compiling
#   make sinewave.o   --  Regenerates sinewave.o by compiling
#   make sinewave     --  Regenerates the executable sinewave file by compiling
#   make              --  Same as "make sinewave"
#

CFLAGS = -g

life: board.o life.o game.o
	gcc -Wall -g board.o life.o game.o -o life 

board.o: board.h board.c
	gcc -Wall -c -g board.c

game.o: game.h board.h life.h game.c
	gcc -Wall -c -g game.c

life.o: life.h board.h game.h life.c
	gcc -Wall -c -g life.c 

clean:
	rm -f *.o life


