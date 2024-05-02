Dalton K. Dwyer CSPB 2270 Final Project Submission

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
A User is a structure that has a username, and can choose when to connect and disconnect from a vehicle


NOTES:
    - The algorithm I use to select which vehicle the user should connect to is a fairly simple priority queue: it stores the vehicles in a list (vec) in reverse of drive time. So the lowest drive time vehicle is stored first. Anytime a new vehicle is added, the program adds it to the list based on drive time.

    - Whenever a vehicle is driven, it is removed from the list, and then re-added based on its new total duration. 

    - One reason for picking the vehicle with the shortest drive duration is for maintenance: you want the vehicles with less drive time to be used, as high drive time vehicles are more likely to need repair.

    - But after doing this exercise, I could make a more advanced algorithm. For example, I could also use distance between the User and Vehicle as a factor, with a shortest distance being better. Then I could use nodes that included both factors, process them, and store them on a b-tree or similar with the top node having the lowest 'combination' of the two factors. Just a thought. 