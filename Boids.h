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
#include "Predator.h"
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
    Boids(int a_N, int a_N_P, int a_N_O); //Constructor for boids with random vectors
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
    int Change_position_predator(void);
    int Change_velocity_predator(void);
    float v1_x(int i); // Lining up velocities
    float v1_y(int i); // Lining up velocities
    float v2_x(int i); // Heading towards the center of the group
    float v2_y(int i); // Heading towards the center of the group
    float v3_x(int i); // Avoiding collisions with preys and obstacles
    float v3_y(int i); // Avoiding collisions with preys and obstacles
    float v4_x(int i); // Fleeing predators
    float v4_y(int i); // Fleeing predators
    float v1_p_x(int i, int prey_index); //Chasing preys
    float v1_p_y(int i, int prey_index); //Chasing preys
    float v2_p_x(int i); // Avoiding collisions with obstacles
    float v2_p_y(int i); // Avoiding collisions with obstacles
    bool Is_prey_in_range(int i, int j, float R);
    bool Is_predator_in_range(int i, int j, float R);
    bool Is_obstacle_in_range(int i, int j, float R);
    int Closest_prey_in_range(int i, float R);
    void Prey_caught(int predator_index, int prey_index);
    bool Is_obstacle_in_range_P(int i, int j, float R);
    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    Prey * preys;
    int N;
    Predator * predators;
    int N_P;
    Obstacle * obstacles;
    int N_O;
    static const float DT;
    static const float DT_P;
    static const int MAX_X;
    static const int MAX_Y;
    static const int EDGE;
    static const int MAX_V;
    static const int MAX_V_P;
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

