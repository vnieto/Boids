//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Boids.h"



//############################################################################
//                                                                           #
//                           Class Boids                                     #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Boids::Boids(void)
{
  preys = NULL;
  N = 0;
}

Boids::Boids(int a_N)
{
	N = a_N;
	preys = new Prey[N];
}

Boids::Boids(int a_N, char R)
{
	N = a_N;
	preys = new Prey[N];
	for (int i=0; i<N; i++)
	{
		preys[i] = Prey((rand()%10+1),(rand()%10+1),(rand()%10+1),(rand()%10+1));
		printf("preys[%d].x = %d\n",i,preys[i].Get_x());
	}
}


// ===========================================================================
//                                  Destructor
// ===========================================================================
Boids::~Boids(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
