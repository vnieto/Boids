//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __PREY_H__
#define __PREY_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>


// ===========================================================================
//                                Project Files
// ===========================================================================
#include "Agent.h"



// ===========================================================================
//                              Class declarations
// ===========================================================================






class Prey : public Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Prey(void);
    Prey(float a_x, float a_y);
    Prey(float a_x, float a_y, float a_vx, float a_vy);
    Prey(float a_x, float a_y, float a_vx, float a_vy, float a_r, float a_c);
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Prey(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline float Get_x(void) const;
    inline float Get_y(void) const;
    inline float Get_vx(void) const;
    inline float Get_vy(void) const;
    inline float Get_x_next(void) const;
    inline float Get_y_next(void) const;
    inline float Get_vx_next(void) const;
    inline float Get_vy_next(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    inline void Set_x(float a_x);
    inline void Set_y(float a_y);
    inline void Set_vx(float a_vx);
    inline void Set_vy(float a_vy);
    inline void Set_x_next(float a_x);
    inline void Set_y_next(float a_y);
    inline void Set_vx_next(float a_vx);
    inline void Set_vy_next(float a_vy);
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
    /*Prey(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    Prey(const Prey &model)
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
    static const double G1;
    static const double G2;
    static const double G3;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline float Prey::Get_x(void) const
{
  return x;
}

inline float Prey::Get_y(void) const
{
  return y;

}

inline float Prey::Get_vx(void) const
{
  return vx;
}

inline float Prey::Get_vy(void) const
{
  return vy;
}

inline float Prey::Get_x_next(void) const
{
  return x_next;
}

inline float Prey::Get_y_next(void) const
{
  return y_next;

}

inline float Prey::Get_vx_next(void) const
{
  return vx_next;
}

inline float Prey::Get_vy_next(void) const
{
  return vy_next;
}

// ===========================================================================
//                              Setters' definitions
// ===========================================================================
inline void Prey::Set_x_next(float a_x)
{
  x_next = a_x;
}

inline void Prey::Set_y_next(float a_y)
{
  y_next = a_y;
}

inline void Prey::Set_vx_next(float a_vx)
{
  vx_next = a_vx;
}

inline void Prey::Set_vy_next(float a_vy)
{
  vy_next = a_vy;
}

inline void Prey::Set_x(float a_x)
{
  x = a_x;
}

inline void Prey::Set_y(float a_y)
{
  y = a_y;
}

inline void Prey::Set_vx(float a_vx)
{
  vx = a_vx;
}

inline void Prey::Set_vy(float a_vy)
{
  vy = a_vy;
}

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __PREY_H__

