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
  Prey p1();
  Prey p2(1.1,5.5);
  Prey p3(0.5,0.5,5.5,5.5);
  Prey p4(6.5,5.5,4.5,3.5,2.5,1.5);
  printf("p4.x=%lf\tp4.y=%lf\tp4.vx=%lf\tp4.vy=%lf\n",
    p4.Get_x(),p4.Get_y(),p4.Get_vx(),p4.Get_vy());


  Boids b(12,'r');
  b.window();
  printf("Successfully compilated.\n");
  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================
