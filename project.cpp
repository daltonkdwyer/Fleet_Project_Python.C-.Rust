#include <iostream>
#include <vector>

using namespace std;

class Vehilce{
    public:
        string name;

}

class Fleet{
    public:
        void print_vehicles();
        void add_vehicles(Vehicle vehicle)
    
    private:
        vector<Vehicle> vehicle_list;
}

Fleet::print_vehicles(){
    for (Vehicle v : vehicle_list){
        cout << v.name << endl;
    }
}


int main(){
    Vehicle myVehicle = new Vehicle
    Fleet myFleet;
    Fleet.add_vehicles(myVehicle)
    Fleet.print_vehicles()
}