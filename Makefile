
all: main

main: 	main.o Boids.o Agent.o Prey.o
	g++ -Wall -o main main.o Boids.o Agent.o Prey.o -g

main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o -g

Boids.o:Agent.h Boids.h Boids.cpp
	g++ -Wall -c Boids.cpp -o Boids.o -g

Agent.o:Agent.h Agent.cpp
	g++ -Wall -c Agent.cpp -o Agent.o -g

Prey.o:	Agent.h Prey.h Prey.cpp
	g++ -Wall -c Prey.cpp -o Prey.o -g

clean:
	rm *.o

mrproper: clean
	rm main
