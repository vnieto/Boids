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

  Boids b(100,1,8);
  b.window();
  printf("Successfully compilated.\n");
  return 0;
}

/*
git add Makefile main.cpp Boids.cpp Boids.h Agent.cpp Agent.h Prey.cpp Prey.h Predator.cpp Predator.h Obstacle.cpp Obstacle.h bwindow.cpp bwindow.h
*/

// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================
