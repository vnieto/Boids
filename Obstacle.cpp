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
#include "Obstacle.h"




//############################################################################
//                                                                          
//                           Class Obstacle                                    
//                                                                          
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
const float Obstacle::RADIUS_OBS = 1; // Increase the radius of contact with obstacles
const float Obstacle::G_OBS = 5; // Coeff to avoid obstacles

// ===========================================================================
//                                  Constructors
// ===========================================================================
Obstacle::Obstacle(void)
{
  x = 0;
  y = 0;
}

Obstacle::Obstacle(float a_x, float a_y)
{
  x = a_x;
  y = a_y;
}


// ===========================================================================
//                                  Destructor
// ===========================================================================
Obstacle::~Obstacle(void)
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
