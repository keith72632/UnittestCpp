CC = g++
SRCS = $(wildcard *.cpp)
FLAGS = -Wno-deprecated-declarations

all:$(SRCS)
	g++ $^ -o unittest $(FLAGS)

run: unittest
	./$^

clean: unittest
	rm $^


