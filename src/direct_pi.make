# direct_pi.make
# makefile for the cpp version of direct_pi
# wpfernandes 20160721_08h59min

all: ../bin/direct_pi_cppversion

../bin/direct_pi_cppversion: ../obj/direct_pi_main.o ../obj/direct_pi.o
	g++ -std=c++11 -Wall -g -gdwarf-2 -o ../bin/direct_pi_cppversion \
           ../obj/direct_pi_main.o ../obj/direct_pi.o

../obj/direct_pi.o: direct_pi.cpp direct_pi.h
	g++ -std=c++11 -Wall -g -gdwarf-2 -c -o ../obj/direct_pi.o direct_pi.cpp

../obj/direct_pi_main.o: direct_pi_main.cpp direct_pi.h
	g++ -std=c++11 -Wall -g -gdwarf-2 -c -o ../obj/direct_pi_main.o \
           direct_pi_main.cpp

# end of file direct_pi.make 
