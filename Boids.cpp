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
const int Boids::MAX_X = 800;
const int Boids::MAX_Y = 600;
const int Boids::MAX_V = 200;
// ===========================================================================
//                                  Constructors
// ===========================================================================
Boids::Boids(void)
{
  preys = NULL;
  N = 0;
}

Boids::Boids(int a_N)
{ 
	N = a_N;
	preys = new Prey[N];
}

Boids::Boids(int a_N, char R)
{
	N = a_N;
	preys = new Prey[N];
	for (int i=0; i<N; i++)
	{
		preys[i] = Prey((rand()%MAX_X+1),(rand()%MAX_Y+1),(rand()%4-2),(rand()%4-2));
		printf("preys[%d].x = %lf\n",i,preys[i].Get_x());
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


      change_velocity_prey();
			// Erase of the boids
  		for(int i = 0; i<N; i++)
  			{
  				win.draw_fsquare((preys[i].Get_x()-1),(preys[i].Get_y()-1),(preys[i].Get_x()+1),(preys[i].Get_y()+1),0x00FFFF);
  			}
  		change_position_prey();
			// Drawing of the boids
  		for(int i = 0; i<N; i++)
  			{
  				win.draw_fsquare((preys[i].Get_x()-1),(preys[i].Get_y()-1),(preys[i].Get_x()+1),(preys[i].Get_y()+1),0xFF0000);
  			}
  		

    	}
  return 0;
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================
int Boids::change_position_prey(void)
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
  				preys[i].Set_x_next(preys[i].Get_x()+preys[i].Get_vx()/20);
  				preys[i].Set_y_next(preys[i].Get_y()+preys[i].Get_vy()/20);
  			}
	for(int i = 0; i<N; i++)
  			{
  				// Apply the computed positions
  				preys[i].Set_x(preys[i].Get_x_next());
  				preys[i].Set_y(preys[i].Get_y_next());
  				printf("preys[%d].x = %lf\t",i,preys[i].Get_x());
  				printf("preys[%d].y = %lf\n",i,preys[i].Get_y());
  			}
	return 0;
}



int Boids::change_velocity_prey(void)
{
	for(int i = 0; i<N; i++)
  			{
  				int range = 3; // range of random change
  				preys[i].Set_vx_next(preys[i].Get_vx()+(rand()%(range)-range/2));
  				preys[i].Set_vy_next(preys[i].Get_vy()+(rand()%(range)-range/2));
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
              preys[i].Get_vy()*preys[i].Get_vy()<MAX_V))
          {
            preys[i].Set_vx(preys[i].Get_vx_next());
            preys[i].Set_vy(preys[i].Get_vy_next());
            printf("preys[%d].vx = %lf\t",i,preys[i].Get_vx());
            printf("preys[%d].vy = %lf\n",i,preys[i].Get_vy());
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


bool Boids::testradius(int i, int j)
{
  float xi,yi,xj,yj,R;
  xi = preys[i].Get_x();
  yi = preys[i].Get_y();
  xj = preys[j].Get_x();
  yj = preys[j].Get_y();
  R = preys[i].Get_PERCEPTION_RADIUS();
  if( sqrt( (xi-xj)*(xi-xj)+(yi-yj)*(yi-yj) ) < R)
  {
    return true;
  } else {
    return false;
  }
}


int Boids::v1(int i)
{
  double vxi, vyi;
  for (int j=0; j<N; j++)
    {
      if (testradius(i,j))
      {
      vxi = vxi + preys[j].Get_vx() - preys[i].Get_vx();
      vyi = vyi + preys[j].Get_vy() - preys[i].Get_vy();
      }
    }
  vxi = vxi/N;
  vyi = vyi/N;
  preys[i].Set_vx_next(vxi);
  preys[i].Set_vx_next(vyi);
	return 0;
}


int Boids::v2(int i)
{
  double vxi, vyi;
  for (int j=0; j<N; j++)
    {
      vxi = vxi + preys[j].Get_x() - preys[i].Get_x();
      vyi = vyi + preys[j].Get_y() - preys[i].Get_y();
    }
  vxi = vxi/N;
  vyi = vyi/N;
  preys[i].Set_vx_next(vxi);
  preys[i].Set_vx_next(vyi);
  return 0;
}


int Boids::v3(int i)
{
  
  return 0;
}


// ===========================================================================
//                               Non inline accessors
// ===========================================================================
