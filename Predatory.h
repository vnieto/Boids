//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __PREDATORY_H__
#define __PREDATORY_H__


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






class Predatory : public Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Predatory(void);
    Predatory(float a_x, float a_y);
    Predatory(float a_x, float a_y, float a_vx, float a_vy);
    
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Predatory(void);

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
    /*Predatory(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    Predatory(const Predatory &model)
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
inline float Predatory::Get_x(void) const
{
  return x;
}

inline float Predatory::Get_y(void) const
{
  return y;
}

inline float Predatory::Get_vx(void) const
{
  return vx;
}

inline float Predatory::Get_vy(void) const
{
  return vy;
}

inline float Predatory::Get_x_next(void) const
{
  return x_next;
}

inline float Predatory::Get_y_next(void) const
{
  return y_next;

}

inline float Predatory::Get_vx_next(void) const
{
  return vx_next;
}

inline float Predatory::Get_vy_next(void) const
{
  return vy_next;
}

inline float Predatory::Get_GP(void) const
{
  return GP;
}

inline float Predatory::Get_PERCEPTION_RADIUS_P(void) const
{
  return PERCEPTION_RADIUS_P;
}

inline float Predatory::Get_CONTACT_RADIUS_P(void) const
{
  return CONTACT_RADIUS_P;
}

// ===========================================================================
//                              Setters' definitions
// ===========================================================================
inline void Predatory::Set_x_next(float a_x)
{
  x_next = a_x;
}

inline void Predatory::Set_y_next(float a_y)
{
  y_next = a_y;
}

inline void Predatory::Set_vx_next(float a_vx)
{
  vx_next = a_vx;
}

inline void Predatory::Set_vy_next(float a_vy)
{
  vy_next = a_vy;
}

inline void Predatory::Set_x(float a_x)
{
  x = a_x;
}

inline void Predatory::Set_y(float a_y)
{
  y = a_y;
}

inline void Predatory::Set_vx(float a_vx)
{
  vx = a_vx;
}

inline void Predatory::Set_vy(float a_vy)
{
  vy = a_vy;
}

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __PREDATORY_H__

