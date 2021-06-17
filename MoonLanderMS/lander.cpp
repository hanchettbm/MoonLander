//
//  lander.cpp
//  MoonLanderMS
//
//  Created by Baden Hanchett on 6/1/20.
//  Copyright © 2020 Baden Hanchett. All rights reserved.
//

#include "lander.h"
#include "point.h"
#include "uiDraw.h"

bool Lander::isAlive()
{

    return alive;
}

bool Lander::isLanded()
{
   
    return landed;
}

bool Lander::canThrust()
{
    if (fuel <= 0)
    {
        thrust = false;
    }
    return thrust;
}

void Lander::applyGravity(float gravity)
{
    velocity.setDy(velocity.getDy() - gravity);
}

void Lander::applyThrustLeft()
{
    if (thrust == true)
    {
       velocity.setDx(velocity.getDx() + 0.1);
       fuel = fuel -1;
       if (fuel <= 0)
       {
          fuel = 0;
       }
    }
}

void Lander::applyThrustRight()
{
    if (thrust == true)
    {
       velocity.setDx(velocity.getDx() - 0.1);
       fuel = fuel -1;
       if (fuel <= 0)
       {
          fuel = 0;
       }
    }
}

void Lander::applyThrustBottom()
{
    if (thrust == true)
    {
        velocity.setDy(velocity.getDy() + 0.3);
        fuel = fuel - 3;
        if (fuel <= 0)
        {
            fuel = 0;
        }
    }
}

void Lander::advance()
{
    p.addX(velocity.getDx());
    p.addY(velocity.getDy());
}

void Lander::draw()
{
    drawLander(p);
}
