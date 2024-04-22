#include <iostream>
#include <vector>

using namespace std;

class Vehicle{
    public:
        string name;

};

class Fleet{
    public:
        void print_vehicles();
        void add_vehicles(Vehicle new_vehicle);
    
    private:
        vector<Vehicle> vehicle_list;
};

void Fleet::add_vehicles(Vehicle new_vehicle){
    this->vehicle_list.push_back(new_vehicle);
}

void Fleet::print_vehicles(){
    for (int i=0; i < vehicle_list.size(); i++ ){
        cout << vehicle_list[i].name << endl;
    }
}


int main(){
    Vehicle myVehicle1;
    myVehicle1.name = "Drone1";

    Vehicle myVehicle2;
    myVehicle2.name = "Drone2";

    Vehicle myVehicle3;
    myVehicle3.name = "Drone3";

    Fleet myFleet;
    myFleet.add_vehicles(myVehicle1);
    myFleet.add_vehicles(myVehicle2);
    myFleet.add_vehicles(myVehicle3);
    myFleet.print_vehicles();
}