# William Wood cssc1167, Nadim Tahmass cssc1158
# CS570, Summer 2018
# Assignment #2, File Editor
# makefile

SRC=$(wildcard *.c)

filem: $(SRC)
	gcc -o $@ $^ -std=gnu99 -I.
