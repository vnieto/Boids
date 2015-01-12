//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __AGENT_H__
#define __AGENT_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================
//#include "Boids.h"



// ===========================================================================
//                              Class declarations
// ===========================================================================






class Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Agent(void);
    Agent(int a_x, int a_y);
    Agent(int a_x, int a_y, int a_vx, int a_vy);
    Agent(int a_x, int a_y, int a_vx, int a_vy, int a_r, int a_c);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Agent(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    virtual int Get_x(void) const =0;
    virtual int Get_y(void) const =0;
    virtual int Get_vx(void) const =0;
    virtual int Get_vy(void) const =0;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================

    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Agent(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    Agent(const Agent &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    int x;
    int y;
    int vx;
    int vy;
    int x_next;
    int y_next;
    int vx_next;
    int vy_next;
    int radius;
    int contact;
    static const int G1;
    static const int G2;
    static const int G3;
    static const int R_DEFAULT;
    static const int C_DEFAULT;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
/*int Agent::Get_x(void)
{
  return x;
}

int Agent::Get_y(void)
{
  return y;

}

int Agent::Get_vx(void)
{
  return vx;
}

int Agent::Get_vy(void)
{
  return vy;
}*/
// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __AGENT_H__

