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
    Boids(int a_N);
    Boids(int a_N, char R); //Constructor for boid with random vectors
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
    int change_position_prey(void);
    int change_velocity_prey(void);
    int v1(int i);
    int v2(int i);
    int v3(int i);
    bool testradius(int i, int j);
    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    Prey * preys;
    int N;
    int dt;
    int t;
    static const int MAX_X;
    static const int MAX_Y;
    static const int MAX_V;
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

