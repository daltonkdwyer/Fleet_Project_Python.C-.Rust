#include <iostream>
#include <vector>

using namespace std;

class Vehicle{
    public:
        int type;
        void engage();
        void disengage();
    
    private:
        int flight_time;
        int number_flights;
        bool connection;
};

class Pilot{
    public:
        string user_name;
        string rank;
};

class Fleet{
    public:
        vector<string> vehicles;
        vector<string> pilots;
};   

void Vehicle::engage(){
    this->connection = true;
}

void Vehicle::disengage(){
    this->connection = false;  
}



int main(){

}
