# Makefile for ecs36b S2024
#

CC = g++ -std=c++14
CFLAGS = -g -I/usr/include/jsoncp

# CFLAGS = -g -D_ECS35B_DEBUG_ -I/usr/include/jsoncpp
# CFLAGS = -g -Wall -Wstrict-prototypes
# CFLAGS = -O3

# rules.
all:	hw1p2

#
#

GPS_0404_s2024.o: GPS.cpp GPS.h
	$(CC) -c $(CFLAGS) GPS.cpp

hw1p2.o: hw1p2.cpp GPS.h
	$(CC) -c $(CFLAGS) hw1p2.cpp

hw1p2: GPS.o hw1p2.o
	$(CC) -o hw1p2 GPS.o hw1p2.o

clean:
	rm -f *.o *~ core hw1p2


