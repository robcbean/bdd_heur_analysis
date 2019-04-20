ifeq ($(OS),Windows_NT)
    uname_S := Windows
else
    uname_S := $(shell uname -s)
endif

ifeq ($(uname_S),Linux)
	LFLAGS = -L ./libcuddlinux -l linuxcudd
	CUDD = ../../bdd/src/cudd-3.0.0_mod_linux
	STATIC = -static
else
	ifeq ($(uname_S),Darwin)
		LFLAGS = -L ./libcuddmac -l maccudd
		CUDD = ../../bdd/src/cudd-3.0.0_mod_imac
		STATIC =
	else
		LFLAGS = -L ./libcuddcyg -l cuddcyg
		CUDD = ../../bdd/src/cudd-3.0.0_mod_cygwin
		STATIC =
	endif
endif

CC = g++
CFLAGS = -g  $(STATIC) -D __UNED__ -I$(CUDD)/cplusplus  -I $(CUDD)/mtr/ -I $(CUDD)/cudd/ -I $(CUDD)/epd/  -I $(CUDD)/st/ -I $(CUDD)/util/ -I $(CUDD)/  -fpermissive -std=gnu++11

all: test_ruby

test_ruby: test_ruby.cc operations.cc output.cc 
	$(CC)  $(CFLAGS) test_ruby.cc operations.cc output.cc $(LFLAGS) -o test_ruby 

clean:
	rm test_ruby 
