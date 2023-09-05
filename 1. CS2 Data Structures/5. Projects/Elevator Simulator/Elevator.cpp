//
//  Elevator.cpp
//  ElevatorSim
//
//  Created by Sherine Antoun on 4/21/20.
//  Copyright © 2020 Sherine Antoun. All rights reserved.
//

#include "Elevator.h"
// constructor for number of floors - no default constructor
Elevator::Elevator(int floors)
{
    
}
// destructor
Elevator::~Elevator()
{
   
}

// move one floor in required direction
void Elevator::Move()
{
    //determine if we have requests above or below
    
    
    //before moving check doors are closed
   
    //workout which floor is requesting elevator (above or below)
    
        //look for direction button pushed above our floor loc
        

    
        //look for direction button pushed below our floor loc
       
    //keep direction up
   
    //direction is up but all requests are from below
   
    //keep going downwards
   
    //direction is down but all requests are from above
   
    //deal with no request so go into idell mode
   
    //stoped now move on request above
    
    //stoped now move on request below
 
    //reset requests
     
    //now that a move was completed - again determine where requests originate from:
    
       //look for direction of button pusheds from above

       //look for direction of button pusheds from below
       
    //check the current floor for any request
    
    //now again since we have moved determine if the new direction - no move just determine ...
    //direction up no change
  
    //direction is up but requests are from below
    
    //keep direction down
    
    //direction down all requests are from above
    
    //regardless of direction we have no requests - idel
    
    //stopped and move according to request
    
    
    //check buttons to do with current floor to open and close doors as needed .. safely then reset em
    
    //floorup reset
   
}
//talk to the driver program
void Elevator::Status(int& currentFloor, int& currDir,int& doorIsOpen)
{
   
}

// handle rider request outside elevator
void Elevator::DirectionSelect(int floorNum, int direction)
{
   
// handle rider request inside elevator
}


