
all: main

main: 	main.o Boids.o
	g++ -Wall main.o Boids.o -o main -g

main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o -g

Boids.o: Boids.h Boids.cpp
	  g++ -Wall -c Boids.cpp -o Boids.o -g

Agent.o: Boids.h Agent.h Agent.cpp
	  g++ -Wall -c Agent.cpp -o Agent.o -g

clean:
	rm *.o

mrproper: clean
	rm main
