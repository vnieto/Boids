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
#include <time.h>

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
    inline bool Is_eating(void) const;
    inline float Get_GP(void) const;
    inline float Get_GP1(void) const;
    inline float Get_GP2(void) const;
    inline float Get_VP(void) const;
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
    inline void Starts_eating(void);
    inline void Stops_eating(void);
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    inline void Is_still_eating(void);
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
    bool eating;
    long int time_since_stop;
    static const float GP;
    static const float GP1;
    static const float GP2;
    static const float VP;
    static const float PERCEPTION_RADIUS_P;
    static const float CONTACT_RADIUS_P;
    static const long int LENGTH_OF_EATING_PROCESS;
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

inline bool Predator::Is_eating(void) const
{
  return eating;
}

inline float Predator::Get_GP(void) const
{
  return GP;
}

inline float Predator::Get_GP1(void) const
{
  return GP1;
}

inline float Predator::Get_GP2(void) const
{
  return GP2;
}

inline float Predator::Get_VP(void) const
{
  return VP;
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

inline void Predator::Starts_eating(void)
{
  eating = true;
  time_since_stop = time(NULL);
  //printf("time_since_stop: %li\n", time_since_stop);
}

inline void Predator::Stops_eating(void)
{
  eating = false;
}

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================
inline void Predator::Is_still_eating(void)
{
  if((time(NULL)-time_since_stop)<LENGTH_OF_EATING_PROCESS)
  {
    eating = true;
  } else {
    eating = false;
  }
}



#endif // __PREDATOR_H__

