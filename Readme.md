This program is a fleet management tool for remotely operated vehicles (like a toy car, or a drone). 

A user will connect to a fleet, and will be connected to the vehicle with the lowest number of drive hours available (see notes below). They can then 'operate' that vehicle until they've finished, and then they will end the session. Imagine if you are at work, and want to drive a toy car around your home remotely. The bit that is for remotely operating the vehicle will use WebRTC to see a low latency camera feed and make the car drive around/change directions, but that is out of the scope of this assignment. 

The data structures are as follows:
    1) A Vehicle
    2) A Fleet 
    3) A User

1) Vehicle 
A Vehicle is a structure that can be turned on or off, can start or end a flight, and stores the total flight time of the vehicle.

When it 'starts' a flight, it records the start time. When the flight is ended, it captures the end time, and calculates the flight duration. It then adds the current flight duration to the vehicles total flight time. 

2) Fleet
A Fleet is a structure that contains a list (vec in the case of Rust) of vehicles. It also has a vec that stores the vehicles that are currently being driven.

3) User
A user 