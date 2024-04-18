# Making a class structure for fleet management

class Fleet:
    def __init__(self, id, vehicle_list):
        self.id = id
        self.vehicle_list = vehicle_list
        self.active_vehicles = []
    
    def print_vehicle(self):
        for vehicle in self.vehicle_list:
            print (vehicle.name)

    def add_vehicle(self, vehicle):
        self.vehicle_list.append(vehicle)
    
    def remove_vehicle(self, vehicle):
        self.vehicle_list.remove(vehicle)

class Vehicle:
    def __init__(self, name, flight_time):
        self.name = name
        self.flight_time = flight_time
        self.is_connected = False
        self.start_time = 0

    def start_flight(self):
        self.start_time = 1
        self.is_connected = True
        print("Flight started!")

    def end_flight(self):
        self.flight_time += 5
        self.is_connected = False
        print("Flight ended")

    def print_flight_time(self):
        print(self.flight_time)

class User:
    def __init__(self, username):
        self.username = username
        self.flight_time = 0
        self.flight_numbers = 0
        self.connected_vehicle = ''

    def connect(self, fleet):
        lowest_vehicle = Vehicle("dummy", 100)
        for vehicle in fleet:
            if vehicle.flight_time < lowest_vehicle.flight_time:
                lowest_vehicle = vehicle
        self.connected_vehicle = lowest_vehicle
        lowest_vehicle.start_flight()

    def disconnect(self):
        if self.connected_vehicle.is_connected == False:
            print("No connection")
            return
        self.connected_vehicle.end_flight()

        
# Create Vehicles 
drone1 = Vehicle("drone1", 2)
drone2 = Vehicle("drone2", 5)
drone3 = Vehicle("drone3", 10)

# Create Fleet
myFleet = Fleet(1, [])
myFleet.add_vehicle(drone1)
myFleet.add_vehicle(drone2)
myFleet.add_vehicle(drone3)
myFleet.print_vehicle() 

# Create User
user1 = User("Dalton")

drone1.print_flight_time()

user1.connect(myFleet.vehicle_list)

user1.disconnect()

drone1.print_flight_time()