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
#include <math.h>


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
    inline bool Is_alive(void) const;
    inline float Get_G1(void) const;
    inline float Get_G2(void) const;
    inline float Get_G3(void) const;
    inline float Get_G4(void) const;
    inline float Get_PERCEPTION_RADIUS(void) const;
    inline float Get_CONTACT_RADIUS(void) const;
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
    inline void Killed(void);
    inline void Dies(void);
    inline void Lives(void);
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
    bool alive;
    static const float G1;
    static const float G2;
    static const float G3;
    static const float G4;
    static const float PERCEPTION_RADIUS;
    static const float CONTACT_RADIUS;
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

inline bool Prey::Is_alive(void) const
{
  return alive;
}

inline float Prey::Get_G1(void) const
{
  return G1;
}

inline float Prey::Get_G2(void) const
{
  return G2;
}

inline float Prey::Get_G3(void) const
{
  return G3;
}

inline float Prey::Get_G4(void) const
{
  return G4;
}

inline float Prey::Get_PERCEPTION_RADIUS(void) const
{
  return PERCEPTION_RADIUS;
}

inline float Prey::Get_CONTACT_RADIUS(void) const
{
  return CONTACT_RADIUS;
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

inline void Prey::Killed(void)
{
  alive = false;
}

inline void Prey::Dies(void)
{
  alive = false;
  x = sqrt(-1);
  y = sqrt(-1);/*
  vx = sqrt(-1);
  vy = sqrt(-1);
  x_next = sqrt(-1);
  y_next = sqrt(-1);
  vx_next = sqrt(-1);
  vy_next = sqrt(-1);*/
}

inline void Prey::Lives(void)
{
  alive = true;
  x = 0;
  y = 0;
}

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __PREY_H__

