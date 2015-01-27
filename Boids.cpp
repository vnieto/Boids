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
const float Boids::DT = 0.1; // Time coefficient for preys
const float Boids::DT_P = 0.1; // Time coefficient for predators
const int Boids::MAX_X = 750; // Horizontal limit of the window
const int Boids::MAX_Y = 750; // Vertical limit of the window
const int Boids::EDGE = 5; // Location of the edges
const int Boids::MAX_V = 20; // Maximum velocity of the preys
const int Boids::MAX_V_P = 20; // Maximum velocity of the predators
const float Boids::MIN_V = 1.5; // Minimum velocity of the preys
const float Boids::MIN_V_G = 1.1; // Gamma for minimum velocity of the preys
// ===========================================================================
//                                  Constructors
// ===========================================================================
Boids::Boids(void)
{
  N = 0;
  N_P = 0;
  N_O = 0;
  preys = NULL;
  predators = NULL;
  obstacles = NULL;
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
			//win.draw_fsquare(400,400,440,410,0xFF00FF);

      /*
      for(int i = 0; i<N; i++) // Erase of the boids one by one
        {
          win.draw_fsquare((preys[i].Get_x()-1),(preys[i].Get_y()-1),(preys[i].Get_x()+1),(preys[i].Get_y()+1),0xFF8800);
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
          if(preys[i].Is_alive()==true)
          {
            // equation (1): x(t+dt) = x(t)+ dt*v(t)
            preys[i].Set_x_next(preys[i].Get_x()+preys[i].Get_vx()*DT);
            preys[i].Set_y_next(preys[i].Get_y()+preys[i].Get_vy()*DT);
          
   	  			// Apply the computed positions
    				preys[i].Set_x(preys[i].Get_x_next());
  		  		preys[i].Set_y(preys[i].Get_y_next());
            // Forbide the boids to leave the window
            if (preys[i].Get_x()<EDGE)
            {
              preys[i].Set_x(EDGE);
              preys[i].Set_vx(abs(preys[i].Get_vx()));
            } else if (preys[i].Get_x()>MAX_X-EDGE)
            {
              preys[i].Set_x(MAX_X-EDGE);
              preys[i].Set_vx(-abs(preys[i].Get_vx()));
            }
            if (preys[i].Get_y()<EDGE)
            {
              preys[i].Set_y(EDGE);
              preys[i].Set_vy(abs(preys[i].Get_vy()));
            } else if (preys[i].Get_y()>MAX_Y-EDGE)
            {
              preys[i].Set_y(MAX_Y-EDGE);
              preys[i].Set_vy(-abs(preys[i].Get_vy()));
            }
          } else {
            preys[i].Dies();
          }
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
  			{
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
  			{
  				// Forbide the boids to go too fast
  				if (sqrt(preys[i].Get_vx()*preys[i].Get_vx()+
              preys[i].Get_vy()*preys[i].Get_vy()<MAX_V))
          {
            preys[i].Set_vx(preys[i].Get_vx_next());
            preys[i].Set_vy(preys[i].Get_vy_next());
          } else 
          {
            /* Reduce the speed /!\ /!\ /!\*/
            preys[i].Set_vx(preys[i].Get_vx_next()*0.9);
            preys[i].Set_vy(preys[i].Get_vy_next()*0.9);
          }
  			}
	return 0;
}




int Boids::Change_position_predator(void)
{
  for(int i = 0; i<N_P; i++)
        {
          // equation (1): x(t+dt) = x(t)+ dt*v(t)
          predators[i].Set_x_next(predators[i].Get_x()+predators[i].Get_vx()*DT_P);
          predators[i].Set_y_next(predators[i].Get_y()+predators[i].Get_vy()*DT_P);
        }
  for(int i = 0; i<N_P; i++)
  {
    if(predators[i].Is_eating()==false)
    {
          // Apply the computed positions
          predators[i].Set_x(predators[i].Get_x_next());
          predators[i].Set_y(predators[i].Get_y_next());

          // Forbide the boids to leave the window
          if (predators[i].Get_x()<EDGE)
          {
            predators[i].Set_x(EDGE);
            predators[i].Set_vx(abs(predators[i].Get_vx()));
          } else if (predators[i].Get_x()>MAX_X-EDGE)
          {
            predators[i].Set_x(MAX_X-EDGE);
            predators[i].Set_vx(-abs(predators[i].Get_vx()));
          }
          if (predators[i].Get_y()<EDGE)
          {
            predators[i].Set_y(EDGE);
            predators[i].Set_vy(abs(predators[i].Get_vy()));
          } else if (predators[i].Get_y()>MAX_Y-EDGE)
          {
            predators[i].Set_y(MAX_Y-EDGE);
            predators[i].Set_vy(-abs(predators[i].Get_vy()));
          }
    } else {
      predators[i].Is_still_eating();
    }
  }
  return 0;
}

int Boids::Change_velocity_predator(void)
{
  int prey_index;
  float GP1 = predators[0].Get_GP1();
  float GP2 = predators[0].Get_GP2();
  for(int i = 0; i<N_P; i++)
      {
        prey_index = Closest_prey_in_range(i, predators[i].Get_PERCEPTION_RADIUS_P());
        predators[i].Set_vx_next(GP1*v1_p_x(i,prey_index)+GP2*v2_p_x(i));//predators[i].Get_vx()
        predators[i].Set_vy_next(GP1*v1_p_y(i,prey_index)+GP2*v2_p_y(i));//predators[i].Get_vy()
        // Set a mimimun speed
        if ( sqrt((predators[i].Get_vx_next()*predators[i].Get_vx_next())+(predators[i].Get_vy_next()*predators[i].Get_vy_next()))<MIN_V)
        {
          predators[i].Set_vx_next(predators[i].Get_vx_next()*MIN_V_G);
          predators[i].Set_vy_next(predators[i].Get_vy_next()*MIN_V_G);
        }
      }
  for(int i = 0; i<N_P; i++)
      {
        float v_next = sqrt( predators[i].Get_vx_next()*predators[i].Get_vx_next() + predators[i].Get_vy_next()*predators[i].Get_vy_next() );
        // Forbide the boids to go too fast
        if (v_next<MAX_V_P)
          {
            // Apply the computed velocities
            predators[i].Set_vx(predators[i].Get_vx_next());
            predators[i].Set_vy(predators[i].Get_vy_next());
          } else 
          {
            // Reduce the velocity
            predators[i].Set_vx((predators[i].Get_vx_next()/v_next)*MAX_V_P);
            predators[i].Set_vy((predators[i].Get_vy_next()/v_next)*MAX_V_P);
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



bool Boids::Is_obstacle_in_range_P(int i, int j, float R)
{
  float xi,yi,xj,yj;
  xi = predators[i].Get_x();
  yi = predators[i].Get_y();
  xj = obstacles[j].Get_x();
  yj = obstacles[j].Get_y();
  if(sqrt( (xi-xj)*(xi-xj)+(yi-yj)*(yi-yj) ) < obstacles[0].Get_G_OBS()*R)
  {
    return true;
  } else {
    return false;
  }
}


int Boids::Closest_prey_in_range(int p, float R)
{
  float xp,yp,xj,yj;
  xp = predators[p].Get_x();
  yp = predators[p].Get_y();
  float min_dist = R;
  float dist;
  float prey_index=-1;
  for(int j=0; j<N; j++)
  {
    xj = preys[j].Get_x();
    yj = preys[j].Get_y();
    dist = sqrt((xp-xj)*(xp-xj)+(yp-yj)*(yp-yj));
    if(dist < min_dist && preys[j].Is_alive()==true)
    {
      min_dist = dist;
      prey_index = j;
    }
  }
  //Launching eating process
  if(min_dist<predators[p].Get_CONTACT_RADIUS_P() && predators[p].Is_eating()==false)
  {
    Prey_caught(p, prey_index);
  }
  return prey_index;
}


void Boids::Prey_caught(int predator_index, int prey_index)
{
  preys[prey_index].Killed();
  predators[predator_index].Starts_eating();
}








// Lining up velocities
float Boids::v1_x(int i)
{
  int K = 0; // number of preys j in the PERCEPTION_RADIUS of the prey i
  float vxi=0;
  float dist,distx,disty;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        distx = (preys[j].Get_vx() - preys[i].Get_vx());
        disty = (preys[j].Get_vy() - preys[i].Get_vy());
        dist = sqrt(distx*distx+disty*disty);
        vxi = vxi + distx/(abs(dist)+0.001);
        K++;
      }
    }
  if (K==0) return 0; // Avoid impossible division
  vxi = vxi/K;
  return vxi;
}
// Lining up velocities
float Boids::v1_y(int i)
{
  int K = 0; // number of preys j in the PERCEPTION_RADIUS of the prey i
  float vyi=0;
  float dist,distx,disty;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        distx = (preys[j].Get_vx() - preys[i].Get_vx());
        disty = (preys[j].Get_vy() - preys[i].Get_vy());
        dist = sqrt(distx*distx+disty*disty);
        vyi = vyi + disty/(abs(dist)+0.001);
        K++;
      }
    }
  if (K==0) return 0; // Avoid impossible division
  vyi = vyi/K;
  return vyi;
}


// Heading towards the center of the group
float Boids::v2_x(int i)
{
  int K = 0; // number of preys j in the PERCEPTION_RADIUS of the prey i
  float vxi=0;
  float dist,distx,disty;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        distx = (preys[j].Get_x() - preys[i].Get_x());
        disty = (preys[j].Get_y() - preys[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vxi = vxi + distx/(abs(dist)+0.001);
        K++;
      }
    }
  if (K==0) return 0; // Avoid impossible division
  vxi = vxi/K;
  return vxi;
}
// Heading towards the center of the group
float Boids::v2_y(int i)
{
  int K = 0; // number of preys j in the PERCEPTION_RADIUS of the prey i
  float vyi=0;
  float dist,distx,disty;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        distx = (preys[j].Get_x() - preys[i].Get_x());
        disty = (preys[j].Get_y() - preys[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vyi = vyi + disty/(abs(dist)+0.001);
        K++;
      }
    }
  if (K==0) return 0; // Avoid impossible division
  vyi = vyi/K;
  return vyi;
  return 0;
}


// Avoiding collision with preys and obstacles
float Boids::v3_x(int i)
{
  // Collision with PREYS
  int K = 0; // number of preys j in the CONTACT_RADIUS of the prey i
  float vxi=0;
  float dist,distx,disty;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_CONTACT_RADIUS()))
      {
        distx = (preys[j].Get_x() - preys[i].Get_x());
        disty = (preys[j].Get_y() - preys[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vxi = vxi + distx/(abs(dist)+0.01);
        //vxi = vxi + preys[j].Get_x() - preys[i].Get_x();
        K++;
      }
    }
  if (K!=0)// Avoid impossible division
  {
    vxi = - vxi/K;
  }
  // Collision with OBSTACLES
  int Obs = 0; // number of obstacles j in the CONTACT_RADIUS of the prey i
  float vxi_O=0;
  for (int j=0; j<N_O; j++)
    {
      if (Is_obstacle_in_range(i,j,preys[i].Get_CONTACT_RADIUS()))
      {
        distx = (obstacles[j].Get_x() - preys[i].Get_x());
        disty = (obstacles[j].Get_y() - preys[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vxi_O = vxi_O + distx/(abs(dist)+0.01);
        //vxi_O = vxi_O + 1/(obstacles[j].Get_x() - preys[i].Get_x());
        //vxi_O = vxi_O + obstacles[j].Get_x() - preys[i].Get_x();
        Obs++;
      }
    }
  if (Obs!=0)// Avoid impossible division
  {
    vxi = vxi - vxi_O/Obs;
  }
  return vxi;
}
// Avoiding collision with preys and obstacles
float Boids::v3_y(int i)
{
  // Collision with PREYS
  int K = 0; // number of preys j in the CONTACT_RADIUS of the prey i
  float vyi=0;
  float dist,distx,disty;
  for (int j=0; j<N; j++)
    {
      if (Is_prey_in_range(i,j,preys[i].Get_CONTACT_RADIUS()))
      {
        distx = (preys[j].Get_x() - preys[i].Get_x());
        disty = (preys[j].Get_y() - preys[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vyi = vyi + disty/(abs(dist)+0.01);
        //vyi = vyi + preys[j].Get_y() - preys[i].Get_y();
        K++;
      }
    }
if (K!=0)// Avoid impossible division
  {
    vyi = - vyi/K;
  }
  // Collision with OBSTACLES
  int Obs = 0; // number of obstacles j in the CONTACT_RADIUS of the prey i
  float vyi_O=0;
  for (int j=0; j<N_O; j++)
    {
      if (Is_obstacle_in_range(i,j,preys[i].Get_CONTACT_RADIUS()))
      {
        distx = (obstacles[j].Get_x() - preys[i].Get_x());
        disty = (obstacles[j].Get_y() - preys[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vyi_O = vyi_O + disty/(abs(dist)+0.01);
        //vyi_O = vyi_O + 1/(obstacles[j].Get_x() - preys[i].Get_x());
        //vyi_O = vyi_O + obstacles[j].Get_x() - preys[i].Get_x();
        Obs++;
      }
    }
  if (Obs!=0)// Avoid impossible division
  {
    vyi = vyi - vyi_O/Obs;
  }
  return vyi;
}


// Fleeing predators
float Boids::v4_x(int i)
{
  int P = 0; // number of predators j in the PERCEPTION_RADIUS of the prey i
  float vxi=0;
  float dist,distx,disty;
  for (int j=0; j<N_P; j++)
    {
      if (Is_predator_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        distx = (predators[j].Get_x() - preys[i].Get_x());
        disty = (predators[j].Get_y() - preys[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vxi = vxi + distx/(abs(dist)+0.001); //0.001 Avoid a jump of the prey
        P++;
      }
    }
  if (P==0) return 0; // Avoid impossible division
  vxi = - vxi/P;
  return vxi;
}
// Fleeing predators
float Boids::v4_y(int i)
{
  int P = 0; // number of predators j in the PERCEPTION_RADIUS of the prey i
  float vyi=0;
  float dist,distx,disty;
  for (int j=0; j<N_P; j++)
    {
      if (Is_predator_in_range(i,j,preys[i].Get_PERCEPTION_RADIUS()))
      {
        distx = (predators[j].Get_x() - preys[i].Get_x());
        disty = (predators[j].Get_y() - preys[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vyi = vyi + disty/(abs(dist)+0.001); //0.001 Avoid a jump of the prey
        P++;
      }
    }
  if (P==0) return 0; // Avoid impossible division
  vyi = - vyi/P;
  return vyi;
  return 0;
}


// Chasing preys
float Boids::v1_p_x(int i, int prey_index)
{
  float vxi=0;
  float dist=0;
  float distx=0;
  float disty=0;
  if (prey_index < 0) // Random movement
  {
    int range = 3; // range of random change
    distx = predators[i].Get_vx() + (rand()%(range)-range/2);
    disty = predators[i].Get_vy() + (rand()%(range)-range/2);
    dist = sqrt(distx*distx+disty*disty);
    vxi = (distx/(dist+0.001))*predators[i].Get_VP();
  } else {
    distx = (preys[prey_index].Get_x() - predators[i].Get_x());
    disty = (preys[prey_index].Get_y() - predators[i].Get_y());
    dist = sqrt(distx*distx+disty*disty);
    vxi = (distx/(dist+0.001))*predators[i].Get_VP();
  }
  return vxi;
}
// Chasing preys
float Boids::v1_p_y(int i, int prey_index)
{
  float vyi=0;
  float dist=0;
  float distx=0;
  float disty=0;
  if (prey_index < 0) // Random movement
  {
    int range = 3; // range of random change
    distx = predators[i].Get_vx() + (rand()%(range)-range/2);
    disty = predators[i].Get_vy() + (rand()%(range)-range/2);
    dist = sqrt(distx*distx+disty*disty);
    vyi = (disty/(dist+0.001))*predators[i].Get_VP();
  } else {
    distx = (preys[prey_index].Get_x() - predators[i].Get_x());
    disty = (preys[prey_index].Get_y() - predators[i].Get_y());
    dist = sqrt(distx*distx+disty*disty);
    vyi = (disty/(dist+0.001))*predators[i].Get_VP();
  }
  return vyi;
}


// Avoiding collisions with obstacles
float Boids::v2_p_x(int i)
{
  float vxi_O=0;
  float dist=0;
  float distx=0;
  float disty=0;
  int Obs = 0; // number of obstacles j in the CONTACT_RADIUS of the prey i
  for (int j=0; j<N_O; j++)
    {
      if (Is_obstacle_in_range(i,j,preys[0].Get_CONTACT_RADIUS()))
      {
        distx = (obstacles[j].Get_x() - predators[i].Get_x());
        disty = (obstacles[j].Get_y() - predators[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vxi_O = vxi_O + distx/(abs(dist)+0.01);
        //vxi_O = vxi_O + 1/(obstacles[j].Get_x() - predators[i].Get_x());
        //vxi_O = vxi_O + obstacles[j].Get_x() - predators[i].Get_x();
        Obs++;
      }
    }
  if (Obs==0)
  {
    return 0;// Avoid impossible division
  }
  vxi_O = - vxi_O/Obs;
  return vxi_O;
}
 // Avoiding collisions with obstacles
float Boids::v2_p_y(int i)
{
  float vyi_O=0;
  float dist=0;
  float distx=0;
  float disty=0;
  int Obs = 0; // number of obstacles j in the CONTACT_RADIUS of the prey i
  for (int j=0; j<N_O; j++)
    {
      if (Is_obstacle_in_range(i,j,preys[0].Get_CONTACT_RADIUS()))
      {
        distx = (obstacles[j].Get_x() - predators[i].Get_x());
        disty = (obstacles[j].Get_y() - predators[i].Get_y());
        dist = sqrt(distx*distx+disty*disty);
        vyi_O = vyi_O + disty/(abs(dist)+0.01);
        //vyi_O = vyi_O + 1/(obstacles[j].Get_y() - predators[i].Get_y());
        //vyi_O = vyi_O + obstacles[j].Get_y() - predators[i].Get_y();
        Obs++;
      }
    }
  if (Obs==0)
  {
    return 0;// Avoid impossible division
  }
  vyi_O = - vyi_O/Obs;
  return vyi_O;
}


// ===========================================================================
//                               Non inline accessors
// ===========================================================================
