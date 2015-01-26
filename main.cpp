//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>

// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "Boids.h"
#include "Agent.h"
#include "Prey.h"
#include "Predator.h"
#include "Obstacle.h"
// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================







// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  Boids b(120,3,20);
  b.window();
  printf("Successfully compilated.\n");
  return 0;
}

/*
git add Makefile main.cpp Boids.cpp Boids.h Agent.cpp Agent.h Prey.cpp Prey.h Predator.cpp Predator.h Obstacle.cpp Obstacle.h bwindow.cpp bwindow.h
*/
/*
TO DO LIST
isotropic changes of velocity
add a Is_alive bool to preys
	take off dead preys to all loops
add a Is_mobile bool to predatory
	when (Is_eating == false) use system time
	at the end, add a new predator
add v3 for predators (obstacles)
meaning of parameters (GP, GO)
*/

// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================
