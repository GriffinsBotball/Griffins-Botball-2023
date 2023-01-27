#include <kipr/wombat.h>
void turnDegrees(int deg) //Makes robot drive a set number of degrees either direction. Set Negative for left.
{
  	cmpc(1);
    cmpc(0);
    if (deg<0)
    {
    while(gmpc(0)<23*deg*-1)
    {
        motor(0,56);
        motor(1,-1);
    }
    	ao();
    }

    else if (deg>0)
        {
            while(gmpc(1)<23*deg)
        		{
            	motor(1,56);
            	motor(0,-1);
        		}
        	ao();
        }
}


void driveDistance(int dis) //Makes robot drive forward for a set number of inches.
{


    cmpc(0);
    cmpc(1);
    if (dis>0)
    {
    while(gmpc(1)<200*dis && gmpc(0)<200*dis)
    {
        motor(0,50);
        motor(1,50);
    }
    ao();
    }
    else if (dis<0)
    {
        while(gmpc(1)>200*dis && gmpc(0)>200*dis)
        {
            motor(0,-50);
            motor(1,-50);
        }
        ao();
	}
}

void slowServo(int servo, int endAngle, int speed) //Slowly controls the servo to move to the correct position at the correct speed.
{
  if (get_servo_position(servo) > endAngle)
  {
	   enable_servo(servo);
     while (get_servo_position(servo) > endAngle)
		   {

  			set_servo_position(servo, get_servo_position(servo)-2);
  			msleep(speed);


		   }
	  ao();
  }
  else if (get_servo_position(servo) < endAngle)
    {
	   enable_servo(servo);
     while (get_servo_position(servo) < endAngle)
		   {

  			set_servo_position(servo, get_servo_position(servo)+2);
  			msleep(speed);


		    }
	   ao();
    }
}


void squareupForward()
{
	while(digital(0) == 0 && digital(1) == 0)
    {

    if(digital(0)==0)
    {
    	motor(0, 25);
    }
    if(digital(3)==0)
    {
        motor(1, 25);
    }
    }
}

void squareupReverse()
{
	while(digital(4) == 0 && digital(5) == 0)
    {

    if(digital(0)==0)
    {
    	motor(0, -25);
    }
    if(digital(3)==0)
    {
        motor(1, -25);
    }
    }
}


void lineFollow()
{

 int X = 2000;

    while((X) >= 1)
    {
   	 if(analog(0) >= 3850)
   		{
        motor(0, 25);
        motor(1, 50);
     	}
   	 if(analog(0) < 3850)
    	{
        motor(0, 50);
    	motor(1, 25);
     	}

    }
}


void startup()
{
  wait_for_light(2);
  shut_down_in(115);
}
