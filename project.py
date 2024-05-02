# Making a class structure for fleet management
# The tool should: 
# 1) Create a fleet data strcucture, create a vehicle data structure, and finally create a user data structure
# 2) Allow users to connect to the vehicle with the lowest total drive time
# 3) The vehicle should record when it is connected to and disconnected from, and record the additional drive time as long as it is connected

import time

class Fleet:
    def __init__(self, id, vehicle_list):
        self.id = id
        self.vehicle_list = vehicle_list
        self.active_vehicles = []
    
    def print_vehicles(self):
        for vehicle in self.vehicle_list:
            print (vehicle.name)

    def add_vehicle(self, vehicle):
        self.vehicle_list.append(vehicle)
    
    def remove_vehicle(self, vehicle):
        self.vehicle_list.remove(vehicle)

    def turn_on_vehicles(self):
        for vehicle in self.vehicle_list:
            vehicle.turn_on()

    def turn_off_vehicles(self):
        for vehicle in self.vehicle_list:
            vehicle.turn_off()

class Vehicle:
    def __init__(self, name, flight_time):
        self.name = name
        self.is_online = False
        self.is_connected = False
        self.flight_time = flight_time
        self.start_time = ''

    def turn_on(self):
        self.is_online = True

    def turn_off(self):
        self.is_online = False

    def start_flight(self):
        self.start_time = time.time()
        self.is_connected = True
        print("Flight started!")

    def end_flight(self):
        end_time = time.time()
        self.flight_time += end_time - self.start_time
        self.is_connected = False
        print("Flight ended")
        self.print_flight_time()

    def print_flight_time(self):
        print(self.name + " flight time: " + str(self.flight_time))

class User:
    def __init__(self, username):
        self.username = username
        self.flight_time = 0
        self.flight_numbers = 0
        self.connected_vehicle = ''

    def connect(self, fleet):
        lowest_flight_vehicle = fleet[0]
        for vehicle in fleet:
            if vehicle.flight_time < lowest_flight_vehicle.flight_time and vehicle.is_online == True:
                lowest_flight_vehicle = vehicle

        self.connected_vehicle = lowest_flight_vehicle

        print("Lowest vehicle: ", lowest_flight_vehicle.name)
        lowest_flight_vehicle.start_flight()

    def disconnect(self):
        if self.connected_vehicle.is_connected == False:
            print("No connection")
            return
        self.connected_vehicle.end_flight()
        self.connected_vehicle = ''


program_start_time = time.time()

# Create Vehicles 
drone1 = Vehicle("drone1", 1)
drone2 = Vehicle("drone2", 2)
drone3 = Vehicle("drone3", 1)

# Create Fleet
myFleet = Fleet(1, [])
myFleet.add_vehicle(drone1)
myFleet.add_vehicle(drone2)
myFleet.add_vehicle(drone3)

# Create User
user1 = User("Dalton")

# Start program
myFleet.turn_on_vehicles()
drone1.print_flight_time()

user1.connect(myFleet.vehicle_list)
time.sleep(1)
user1.disconnect()
user1.connect(myFleet.vehicle_list)
time.sleep(1)
user1.disconnect()
user1.connect(myFleet.vehicle_list)
time.sleep(1)
user1.disconnect()

myFleet.turn_off_vehicles()

program_end_time = time.time()
total_program_time = program_end_time - program_start_time - 3
print("Total program length : " + str(total_program_time * 1000) + "ms")