//
//  lander.h
//  MoonLanderMS
//
//  Created by Baden Hanchett on 5/28/20.
//  Copyright © 2020 Baden Hanchett. All rights reserved.
//

#ifndef lander_h
#define lander_h

#include "point.h"
#include "velocity.h"

class Lander
{
private:
    Point p;
    Velocity velocity;
    int fuel;
    bool landed;
    bool alive;
    float gravity;
    bool thrust;
    
public:
    Lander() : p(0,200), velocity(0,0)
    {
        fuel = 0;
        landed = false;
        alive = true;
        gravity = 0.0;
        thrust = true;
        
    };
    Point getPoint() const {return p; }
    Velocity getVelocity() const { return velocity; }
    bool isAlive();
    bool isLanded();
    int getFuel() { return fuel; }
    bool canThrust();
    void setLanded(bool newLanded) { landed = newLanded; }
    void setAlive(bool newAlive) { alive = newAlive; }
    void setFuel(int newFuel) { fuel = newFuel; }
    void applyGravity(float gravity);
    void applyThrustLeft();
    void applyThrustRight();
    void applyThrustBottom();
    void advance();
    void draw();
};

#endif /* lander_h */
