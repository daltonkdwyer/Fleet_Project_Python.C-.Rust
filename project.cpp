#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <thread>

using namespace std;

class Vehicle{
    public:
        string name;
        bool operator==(const Vehicle& other) const {
            return name == other.name;
        }
        bool is_online = false;
        bool is_connected = false;
        int flight_time = 0;
        int start_time;
        void start_flight();
        void end_flight();
        void print_flight_time();
};

void Vehicle::start_flight(){
    this->start_time = chrono::system_clock::to_time_t(std::chrono::system_clock::now());    
    this->is_connected = true;
}

void Vehicle::end_flight(){
    int end_time = chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    int duration = end_time - start_time;
    this->flight_time += duration;
    this->start_time = 0;
}

void Vehicle::print_flight_time(){
    cout << "Total vehicle flight time: " << this-> flight_time << " seconds" << endl;
}

class Fleet{
    public:
        void print_vehicles();
        void add_vehicles(Vehicle new_vehicle);
        void remove_vehicles(Vehicle delete_vehicle);
        void turn_on_vehicles();
        void turn_off_vehicles();
   
    private:
        vector<Vehicle> vehicle_list;  
};

void Fleet::print_vehicles(){
    for (int i=0; i < vehicle_list.size(); i++ ){
        cout << vehicle_list[i].name << endl;
    }
}

void Fleet::add_vehicles(Vehicle new_vehicle){
    this->vehicle_list.push_back(new_vehicle);
}

void Fleet::remove_vehicles(Vehicle delete_vehicle){
    for (int i = 0; i < this->vehicle_list.size(); i++){
        if (this->vehicle_list[i] == delete_vehicle){
            this->vehicle_list.erase(this->vehicle_list.begin() + i);
        }
    }
}

void Fleet::turn_on_vehicles(){
    for (int i = 0; i < this->vehicle_list.size(); i++){
        this->vehicle_list[i].is_online = true;
    }
}

void Fleet::turn_off_vehicles(){
    for (int i = 0; i < this->vehicle_list.size(); i++){
        this->vehicle_list[i].is_online = true;
    }
}

class User{
    public:
        string Username;
        int flightTime;
        Vehicle* connectedVehicle;
        void connect(Fleet fleet);
        void disconnect();
}

int main(){
    Vehicle myVehicle1;
    myVehicle1.name = "Drone1";

    Vehicle myVehicle2;
    myVehicle2.name = "Drone2";

    Vehicle myVehicle3;
    myVehicle3.name = "Drone3";

    Fleet myFleet;
    myFleet.turn_on_vehicles();
    myFleet.turn_off_vehicles();
    myFleet.add_vehicles(myVehicle1);
    myFleet.add_vehicles(myVehicle2);
    myFleet.add_vehicles(myVehicle3);
    myFleet.print_vehicles();

    myVehicle2.start_flight();
    this_thread::sleep_for(std::chrono::seconds(5));
    myVehicle2.end_flight();
    myVehicle2.print_flight_time();
}