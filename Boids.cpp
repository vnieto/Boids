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
#include "Boids.h"

#include <math.h>


//############################################################################
//                                                                           #
//                           Class Boids                                     #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
const float Boids::DT = 0.05;
const float Boids::DT_P = 0.07;
const int Boids::MAX_X = 800;
const int Boids::MAX_Y = 600;
const int Boids::MAX_V = 100;
const int Boids::MAX_V_P = 120;
const float Boids::MIN_V = 1.25;
const float Boids::MIN_V_G = 1.005;
// ===========================================================================
//                                  Constructors
// ===========================================================================
Boids::Boids(void)
{
  preys = NULL;
  N = 0;
}

Boids::Boids(int a_N, int a_N_P, int a_N_O)
{
	N = a_N;
  N_P = a_N_P;
  N_O = a_N_O;
  preys = new Prey[N];
  predators = new Predator[N_P+N]; // N_P number of predators added to the number of preys
  obstacles = new Obstacle[N_O];
  srand (time(NULL));
  for (int i=0; i<N; i++)
  {
    preys[i] = Prey((rand()%MAX_X+1),(rand()%MAX_Y+1),(rand()%4-2),(rand()%4-2));
  }
  for (int i=0; i<N_P; i++)
  {
    predators[i] = Predator((rand()%MAX_X+1),(rand()%MAX_Y+1),(rand()%4-2),(rand()%4-2));
  }
  for (int i=0; i<N_O; i++)
  {
    obstacles[i] = Obstacle((rand()%MAX_X+1),(rand()%MAX_Y+1));
  }
}


// ===========================================================================
//                                  Destructor
// ===========================================================================
Boids::~Boids(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
int Boids::window(void)
{
	bwindow win(MAX_X,MAX_Y);
    printf("%d\n",win.init());
    win.map();
    for(;;)
    {
			int ev = win.parse_event();
			switch(ev)
				{
	    		case BKPRESS :
						printf("keypressed\n"); 
						printf("key : %s\n",win.get_lastkey());
						break;
	    		case BBPRESS:
				printf("buttonpressed\n"); break;
	  		  case BEXPOSE:
				printf("expose\n"); break;
	    		case BCONFIGURE:
				printf("configure\n"); break;
				}
			//win.draw_point(100,100,0xFF00);
			//win.draw_line(100,100,200,200,0xFF0000);
			//win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
			//win.draw_square(200,200,220,220,0xFF00);
			//win.draw_fsquare(400,400,410,410,0xFF00FF);

      /*for(int i = 0; i<N; i++) // Erase of the boids one by one
        {
          win.draw_fsquare((preys[i].Get_x()-1),(preys[i].Get_y()-1),(preys[i].Get_x()+1),(preys[i].Get_y()+1),0xFFFF00);
        }*/

      Change_velocity_prey();
      Change_velocity_predator();
      Change_position_prey();
      Change_position_predator();
			// Erase of the boids
      win.draw_fsquare(0,0,MAX_X,MAX_Y,0x55AAFF);
  		
      // Drawing of the obstacles
      for(int i = 0; i<N_O; i++)
        {
          win.draw_fsquare((obstacles[i].Get_x()-6),(obstacles[i].Get_y()-3),(obstacles[i].Get_x()+6),(obstacles[i].Get_y()+3),0x337733);
          win.draw_fsquare((obstacles[i].Get_x()-3),(obstacles[i].Get_y()-6),(obstacles[i].Get_x()+3),(obstacles[i].Get_y()+6),0x337733);
          win.draw_fsquare((obstacles[i].Get_x()-5),(obstacles[i].Get_y()-5),(obstacles[i].Get_x()+5),(obstacles[i].Get_y()+5),0x337733);
        }
      // Drawing of the preys
      for(int i = 0; i<N; i++)
        {
          win.draw_fsquare((preys[i].Get_x()-1),(preys[i].Get_y()-1),(preys[i].Get_x()+1),(preys[i].Get_y()+1),0x000000);
        }
      // Drawing of the predators
      for(int i = 0; i<N_P; i++)
        {
          win.draw_fsquare((predators[i].Get_x()-2),(predators[i].Get_y()-2),(predators[i].Get_x()+2),(predators[i].Get_y()+2),0xCC0000);
        }
  		

    	}
  return 0;
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================
int Boids::Change_position_prey(void)
{
	for(int i = 0; i<N; i++)
  			{
  				// Forbide the boids to leave the window
  				if (preys[i].Get_x()<0 || preys[i].Get_x()>MAX_X)
  				{
  					preys[i].Set_vx(-preys[i].Get_vx());
  				}
					if (preys[i].Get_y()<0 || preys[i].Get_y()>MAX_Y)
  				{
  					preys[i].Set_vy(-preys[i].Get_vy());
  				}

  				// equation (1): x(t+dt) = x(t)+ dt*v(t)
  				preys[i].Set_x_next(preys[i].Get_x()+preys[i].Get_vx()*DT);
  				preys[i].Set_y_next(preys[i].Get_y()+preys[i].Get_vy()*DT);
  			}
	for(int i = 0; i<N; i++)
  			{
  				// Apply the computed positions
  				preys[i].Set_x(preys[i].Get_x_next());
  				preys[i].Set_y(preys[i].Get_y_next());/*
  				printf("preys[%d].x = %lf\t",i,preys[i].Get_x());
  				printf("preys[%d].y = %lf\n",i,preys[i].Get_y());*/
  			}
	return 0;
}



int Boids::Change_velocity_prey(void)
{
  float G1 = preys[0].Get_G1();
  float G2 = preys[0].Get_G2();
  float G3 = preys[0].Get_G3();
  float G4 = preys[0].Get_G4();
	for(int i = 0; i<N; i++)
  			{/*
  				int range = 3; // range of random change
  				preys[i].Set_vx_next(preys[i].Get_vx()+(rand()%(range)-range/2));
  				preys[i].Set_vy_next(preys[i].Get_vy()+(rand()%(range)-range/2));*/
          preys[i].Set_vx_next(preys[i].Get_vx()+(G1*v1_x(i)+G2*v2_x(i)+G3*v3_x(i)+G4*v4_x(i)));
          preys[i].Set_vy_next(preys[i].Get_vy()+(G1*v1_y(i)+G2*v2_y(i)+G3*v3_y(i)+G4*v4_y(i)));
          // Set a mimimun speed
          if ( sqrt((preys[i].Get_vx_next()*preys[i].Get_vy_next())*(preys[i].Get_vx_next()*preys[i].Get_vy_next()))<MIN_V)
          {
            preys[i].Set_vx_next(preys[i].Get_vx_next()*MIN_V_G);
            preys[i].Set_vy_next(preys[i].Get_vy_next()*MIN_V_G);
          }

  			}
	for(int i = 0; i<N; i++)
  			{/*
  				// Apply the computed velocities
  				preys[i].Set_vx(preys[i].Get_vx_next());
  				preys[i].Set_vy(preys[i].Get_vy_next());
  				printf("preys[%d].vx = %lf\t",i,preys[i].Get_vx());
  				printf("preys[%d].vy = %lf\n",i,preys[i].Get_vy());
*/
  				// Forbide the boids to go too fast
  				if (sqrt(preys[i].Get_vx()*preys[i].Get_vx()+
              preys[i].Get_vy()*preys[i].Get_vy()<MAX_V_P))
          {
            preys[i].Set_vx(preys[i].Get_vx_next());
            preys[i].Set_vy(preys[i].Get_vy_next());
            //printf("preys[%d].vx = %lf\t",i,preys[i].Get_vx());
            //printf("preys[%d].vy = %lf\n",i,preys[i].Get_vy());
          } else 
          {
            /* Reduce the speed? /!\ /!\ /!\*/
            if (preys[i].Get_vx()>0) preys[i].Set_vx(preys[i].Get_vx_next()-1);
            if (preys[i].Get_vy()>0) preys[i].Set_vy(preys[i].Get_vy_next()-1);
            if (preys[i].Get_vx()<0) preys[i].Set_vx(preys[i].Get_vx_next()+1);
            if (preys[i].Get_vy()<0) preys[i].Set_vy(preys[i].Get_vy_next()+1);
          }
  			}
	return 0;
}




int Boids::Change_position_predator(void)
{
  for(int i = 0; i<N_P; i++)
        {
          // Forbide the boids to leave the window
          if (predators[i].Get_x()<0 || predators[i].Get_x()>MAX_X)
          {
            predators[i].Set_vx(-predators[i].Get_vx());
          }
          if (predators[i].Get_y()<0 || predators[i].Get_y()>MAX_Y)
          {
            predators[i].Set_vy(-predators[i].Get_vy());
          }

          // equation (1): x(t+dt) = x(t)+ dt*v(t)
          predators[i].Set_x_next(predators[i].Get_x()+predators[i].Get_vx()*DT_P);
          predators[i].Set_y_next(predators[i].Get_y()+predators[i].Get_vy()*DT_P);
        }
  for(int i = 0; i<N_P; i++)
        {
          // Apply the computed positions
          predators[i].Set_x(predators[i].Get_x_next());
          predators[i].Set_y(predators[i].Get_y_next());
        }
  return 0;
}

int Boids::Change_velocity_predator(void)
{
    for(int i = 0; i<N_P; i++)
        {
          int range = 3; // range of random change
          predators[i].Set_vx_next(predators[i].Get_vx()+(rand()%(range)-range/2));
          predators[i].Set_vy_next(predators[i].Get_vy()+(rand()%(range)-range/2));
          // Set a mimimun speed
          if ( sqrt((predators[i].Get_vx_next()*predators[i].Get_vy_next())*(predators[i].Get_vx_next()*predators[i].Get_vy_next()))<MIN_V)
          {
            predators[i].Set_vx_next(predators[i].Get_vx_next()*MIN_V_G);
            predators[i].Set_vy_next(predators[i].Get_vy_next()*MIN_V_G);
          }

        }
  for(int i = 0; i<N_P; i++)
        {
          // Forbide the boids to go too fast
          if (sqrt(predators[i].Get_vx()*predators[i].Get_vx()+
              predators[i].Get_vy()*predators[i].Get_vy()<MAX_V))
          {
            // Apply the computed velocities
            predators[i].Set_vx(predators[i].Get_vx_next());
            predators[i].Set_vy(predators[i].Get_vy_next());
          } else 
          {
            // Reduce the velocity
            predators[i].Set_vx(predators[i].Get_vx_next()*0.9);
            predators[i].Set_vy(predators[i].Get_vy_next()*0.9);
          }
        }
  return 0;
}




bool Boids::Is_prey_in_range(int i, int j, float R)
{
  float xi,yi,xj,yj;
  xi = preys[i].Get_x();
  yi = preys[i].Get_y();
  xj = preys[j].Get_x();
  yj = preys[j].Get_y();
  if (i==j) return false;
  if(sqrt( (xi-xj)*(xi-xj)+(yi-yj)*(yi-yj) ) < R)
  {
    return true;
  } else {
    return false;
  }
}

bool Boids::Is_predator_in_range(int i, int j, float R)
{
  float xi,yi,xj,yj;
  xi = preys[i].Get_x();
  yi = preys[i].Get_y();
  xj = predators[j].Get_x();
  yj = predators[j].Get_y();
  if(sqrt( (xi-xj)*(xi-xj)+(yi-yj)*(yi-yj) ) < R)
  {
    return true;
  } else {
    return false;
  }
}

bool Boids::Is_obstacle_in_range(int i, int j, float R)
{
  float xi,yi,xj,yj;
  xi = preys[i].Get_x();
  yi = preys[i].Get_y();
  xj = obstacles[j].Get_x();
  yj = obstacles[j].Get_y();
  if(sqrt( (xi-xj)*(xi-xj)+(yi-yj)*(yi-yj) ) < obstacles[0].Get_G_OBS()*R)
  {
    return true;
  } else {
    return false;
  }
}


float Boids::v1_x(int i)
{
  int K = 0; // number of preys j in the PERCEPTION_RADIUS of the prey i
  double vxi=0;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        vxi = vxi + preys[j].Get_vx() - preys[i].Get_vx();
        K++;
      }
    }
  if (K==0) return 0; // Avoid impossible division
  vxi = vxi/K;
  return vxi;
}
float Boids::v1_y(int i)
{
  int K = 0; // number of preys j in the PERCEPTION_RADIUS of the prey i
  double vyi=0;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        vyi = vyi + preys[j].Get_vy() - preys[i].Get_vy();
        K++;
      }
    }
  if (K==0) return 0; // Avoid impossible division
  vyi = vyi/K;
  return vyi;
}


float Boids::v2_x(int i)
{
  int K = 0; // number of preys j in the PERCEPTION_RADIUS of the prey i
  double vxi=0;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        vxi = vxi + preys[j].Get_x() - preys[i].Get_x();
        K++;
      }
    }
  if (K==0) return 0; // Avoid impossible division
  vxi = vxi/K;
  return vxi;
}
float Boids::v2_y(int i)
{
  int K = 0; // number of preys j in the PERCEPTION_RADIUS of the prey i
  double vyi=0;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        vyi = vyi + preys[j].Get_y() - preys[i].Get_y();
        K++;
      }
    }
  if (K==0) return 0; // Avoid impossible division
  vyi = vyi/K;
  return vyi;
  return 0;
}


float Boids::v3_x(int i)
{
  // Collision with PREYS
  int K = 0; // number of preys j in the CONTACT_RADIUS of the prey i
  double vxi=0;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_CONTACT_RADIUS()))
      {
        //vxi = vxi + 1/(preys[j].Get_x() - preys[i].Get_x());
        vxi = vxi + preys[j].Get_x() - preys[i].Get_x();
        K++;
      }
    }
  /*
  if (K==0) return 0; // Avoid impossible division
  vxi = - vxi/K;
  // Collision with obstacles
  return vxi;*/
  if (K!=0)// Avoid impossible division
  {
    vxi = - vxi/K;
  }
  
  // Collision with OBSTACLES
  int Obs = 0; // number of obstacles j in the CONTACT_RADIUS of the prey i
  double vxi_O=0;
  for (int j=0; j<N_O; j++)
    {
      if (Is_obstacle_in_range(i,j,preys[i].Get_CONTACT_RADIUS()))
      {
        vxi_O = vxi_O + 1/(obstacles[j].Get_x() - preys[i].Get_x());
        vxi_O = vxi_O + obstacles[j].Get_x() - preys[i].Get_x();
        Obs++;
      }
    }
  if (Obs!=0)// Avoid impossible division
  {
    vxi = vxi - vxi_O/Obs;
  }
  return vxi;
}

float Boids::v3_y(int i)
{
  // Collision with PREYS
  int K = 0; // number of preys j in the CONTACT_RADIUS of the prey i
  double vyi=0;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_CONTACT_RADIUS()))
      {
        //vyi = vyi + 1/(preys[j].Get_y() - preys[i].Get_y());
        vyi = vyi + preys[j].Get_y() - preys[i].Get_y();
        K++;
      }
    }
if (K!=0)// Avoid impossible division
  {
    vyi = - vyi/K;
  }
  
  // Collision with OBSTACLES
  int Obs = 0; // number of obstacles j in the CONTACT_RADIUS of the prey i
  double vyi_O=0;
  for (int j=0; j<N_O; j++)
    {
      if (Is_obstacle_in_range(i,j,preys[i].Get_CONTACT_RADIUS()))
      {
        vyi_O = vyi_O + 1/(obstacles[j].Get_x() - preys[i].Get_x());
        vyi_O = vyi_O + obstacles[j].Get_x() - preys[i].Get_x();
        Obs++;
      }
    }
  if (Obs!=0)// Avoid impossible division
  {
    vyi = vyi - vyi_O/Obs;
  }
  return vyi;
}


float Boids::v4_x(int i)
{
  int P = 0; // number of predators j in the PERCEPTION_RADIUS of the prey i
  double vxi=0;
  float dist=0;
  for (int j=0; j<N_P; j++)
    {
      if (Is_predator_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        dist = (predators[j].Get_x() - preys[i].Get_x());
        vxi = vxi + dist/(abs(dist)+0.001); //0.001 Avoid a jump of the prey
        P++;
      }
    }
  if (P==0) return 0; // Avoid impossible division
  vxi = - vxi/P;
  return vxi;
}
float Boids::v4_y(int i)
{
  int P = 0; // number of predators j in the PERCEPTION_RADIUS of the prey i
  double vyi=0;
  float dist=0;
  for (int j=0; j<N_P; j++)
    {
      if (Is_predator_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        dist = (predators[j].Get_y() - preys[i].Get_y());
        vyi = vyi + dist/(abs(dist)+0.001); //0.001 Avoid a jump of the prey
        P++;
      }
    }
  if (P==0) return 0; // Avoid impossible division
  vyi = - vyi/P;
  return vyi;
  return 0;
}
// ===========================================================================
//                               Non inline accessors
// ===========================================================================
