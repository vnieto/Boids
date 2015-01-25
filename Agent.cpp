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
#include "Agent.h"




//############################################################################
//                                                                          
//                           Class Agent                                    
//                                                                          
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
//const float Agent::R_DEFAULT = 10;
//const float Agent::C_DEFAULT = 2;
// ===========================================================================
//                                  Constructors
// ===========================================================================
Agent::Agent(void)
{
  x = 0;
  y = 0;
  vx = 0;
  vy = 0;
  //radius = R_DEFAULT;
  //contact = C_DEFAULT;
}

Agent::Agent(float a_x, float a_y)
{
  x = a_x;
  y = a_y;
  vx = 0;
  vy = 0;
  //radius = R_DEFAULT;
  //contact = C_DEFAULT;
}

Agent::Agent(float a_x, float a_y, float a_vx, float a_vy)
{
  x = a_x;
  y = a_y;
  vx = a_vx;
  vy = a_vx;
  //radius = R_DEFAULT;
  //contact = C_DEFAULT;
}
/*
Agent::Agent(float a_x, float a_y, float a_vx, float a_vy, float a_r, float a_c)
{
  x = a_x;
  y = a_y;
  vx = a_vx;
  vy = a_vx;
  radius = a_r;
  contact = a_c;
}*/

// ===========================================================================
//                                  Destructor
// ===========================================================================
Agent::~Agent(void)
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
