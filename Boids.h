//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __BOIDS_H__
#define __BOIDS_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================
#include "Agent.h"
#include "Prey.h"
#include "Obstacle.h"
#include "bwindow.h"

// ===========================================================================
//                              Class declarations
// ===========================================================================






class Boids
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Boids(void);
    Boids(int a_N, int a_N_O); //Constructor for boid with random vectors
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Boids(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    int window(void);
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Boids(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    Boids(const Boids &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };


    // =======================================================================
    //                              Protected Methods
    // =======================================================================
    int Change_position_prey(void);
    int Change_velocity_prey(void);
    float v1_x(int i);
    float v2_x(int i);
    float v3_x(int i);
    float v1_y(int i);
    float v2_y(int i);
    float v3_y(int i);
    bool Is_prey_in_range(int i, int j, float R);
    bool Is_obstacle_in_range(int i, int j, float R);
    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    Prey * preys;
    int N;
    Obstacle * obstacles;
    int N_O;
    static const int MAX_X;
    static const int MAX_Y;
    static const int MAX_V;
    static const float MIN_V;
    static const float MIN_V_G;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __BOIDS_H__

