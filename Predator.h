//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __PREDATOR_H__
#define __PREDATOR_H__


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






class Predator : public Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Predator(void);
    Predator(float a_x, float a_y);
    Predator(float a_x, float a_y, float a_vx, float a_vy);
    
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Predator(void);

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
    inline float Get_GP(void) const;
    inline float Get_PERCEPTION_RADIUS_P(void) const;
    inline float Get_CONTACT_RADIUS_P(void) const;
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
    /*Predator(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    Predator(const Predator &model)
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
    static const float GP;
    static const float PERCEPTION_RADIUS_P;
    static const float CONTACT_RADIUS_P;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline float Predator::Get_x(void) const
{
  return x;
}

inline float Predator::Get_y(void) const
{
  return y;
}

inline float Predator::Get_vx(void) const
{
  return vx;
}

inline float Predator::Get_vy(void) const
{
  return vy;
}

inline float Predator::Get_x_next(void) const
{
  return x_next;
}

inline float Predator::Get_y_next(void) const
{
  return y_next;

}

inline float Predator::Get_vx_next(void) const
{
  return vx_next;
}

inline float Predator::Get_vy_next(void) const
{
  return vy_next;
}

inline float Predator::Get_GP(void) const
{
  return GP;
}

inline float Predator::Get_PERCEPTION_RADIUS_P(void) const
{
  return PERCEPTION_RADIUS_P;
}

inline float Predator::Get_CONTACT_RADIUS_P(void) const
{
  return CONTACT_RADIUS_P;
}

// ===========================================================================
//                              Setters' definitions
// ===========================================================================
inline void Predator::Set_x_next(float a_x)
{
  x_next = a_x;
}

inline void Predator::Set_y_next(float a_y)
{
  y_next = a_y;
}

inline void Predator::Set_vx_next(float a_vx)
{
  vx_next = a_vx;
}

inline void Predator::Set_vy_next(float a_vy)
{
  vy_next = a_vy;
}

inline void Predator::Set_x(float a_x)
{
  x = a_x;
}

inline void Predator::Set_y(float a_y)
{
  y = a_y;
}

inline void Predator::Set_vx(float a_vx)
{
  vx = a_vx;
}

inline void Predator::Set_vy(float a_vy)
{
  vy = a_vy;
}

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __PREDATOR_H__

