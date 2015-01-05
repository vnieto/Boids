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

// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================








// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  
  Agent a1();
  Agent a2(1,2);
  Agent a3(0,1,1,1);
  Agent a4(1,2,3,4,5,6);
  Prey p1();
  Prey p2(1,5);
  Prey p3(0,0,5,5);
  Prey p4(6,5,4,3,2,1);
  Boids b(10,'r');



  printf("Successfully compilated.\n");
  // git add Makefile main.cpp Boids.cpp Boids.h Agent.cpp Agent.h Prey.cpp Prey.h
  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

