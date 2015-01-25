
all: main

main: 	main.o Boids.o Agent.o Prey.o Predator.o Obstacle.o bwindow.o
	g++ -Wall -o main main.o Boids.o Agent.o Prey.o Predator.o Obstacle.o bwindow.o -g  -lX11 -L/usr/X11R6/lib

main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o -g

Boids.o:Agent.h Boids.h Boids.cpp bwindow.h Obstacle.h
	g++ -Wall -c Boids.cpp -o Boids.o -g


bwindow.o: bwindow.cpp bwindow.h
	g++ -c bwindow.cpp


Agent.o:Agent.h Agent.cpp
	g++ -Wall -c Agent.cpp -o Agent.o -g

Prey.o:	Agent.h Prey.h Prey.cpp
	g++ -Wall -c Prey.cpp -o Prey.o -g

Predator.o:	Agent.h Predator.h Predator.cpp
	g++ -Wall -c Predator.cpp -o Predator.o -g

Obstacle.o:Obstacle.h Obstacle.cpp
	g++ -Wall -c Obstacle.cpp -o Obstacle.o -g


clean:
	rm *.o

mrproper: clean
	rm main
