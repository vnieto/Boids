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
#include "Prey.h"




//############################################################################
//                                                                           #
//                           Class Prey                                      #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
const float Prey::G1 = 0.0001; // Lining up velocities 0.0005
const float Prey::G2 = 0.075; // Heading towards the center of the group 0.00075
const float Prey::G3 = 0.1; // Avoiding collisions with preys and obstacles 0.05
const float Prey::G4 = 0.2; // Fleeing predators 0.025
const float Prey::G5 = 0.2; // Wind at borders
const float Prey::PERCEPTION_RADIUS=100;
const float Prey::CONTACT_RADIUS=10;
// ===========================================================================
//                                  Constructors
// ===========================================================================
Prey::Prey(void)
{
  x = 0;
  y = 0;
  vx = 0;
  vy = 0;
  alive = true;
}

Prey::Prey(float a_x, float a_y)
{
  x = a_x;
  y = a_y;
  vx = 0;
  vy = 0;
  alive = true;
}

Prey::Prey(float a_x, float a_y, float a_vx, float a_vy)
{
  x = a_x;
  y = a_y;
  vx = a_vx;
  vy = a_vy;
  alive = true;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Prey::~Prey(void)
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
