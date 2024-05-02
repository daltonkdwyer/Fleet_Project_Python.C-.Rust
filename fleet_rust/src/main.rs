use chrono::{Local};
use std::thread::sleep;
use std::time::Duration as StdDuration;

// Vehicle Structure
struct Vehicle{
    id: String,
    is_online: bool,
    is_connected: bool,
    flight_time: u64,
    start_time: u64,
}
impl Vehicle {
    fn new(id: &str) -> Self{
        Self {
            id: String::from(id),
            is_online: false,
            is_connected: false,
            flight_time: 0,
            start_time: 0,
        }
    }
    fn turn_on(&mut self) {
        self.is_online = true;
    }
    fn turn_off(&mut self){
        self.is_online = false;
    }
    fn start_flight(&mut self){
        self.start_time = Local::now().timestamp_millis() as u64;
        self.is_connected = true;
    }
    fn end_flight(&mut self){
        let end_time = Local::now().timestamp_millis() as u64;
        let flight_duration = end_time - self.start_time;
        self.is_connected = false;
        println!("Flight Duration: {}",flight_duration);
        self.flight_time += flight_duration;
    }
}
// Fleet Structure
struct Fleet{
    id: String,
    vehicle_list: Vec<Vehicle>, // Bug #1: this vec should be a vector of references, not actual vehicles. But when I try to make this Vec<*Vehicle> like I would in C++, the compiler gets angry with me.
    active_vehicles: Vec<Vehicle>,
}
impl Fleet {
    fn new(id: &str) -> Self{
        Self {
            id: String::from(id),
            vehicle_list: Vec::new(),
            active_vehicles: Vec::new(),
        }
    }
    fn print_vehicle(&mut self){
        for item in &self.vehicle_list{
            println!("{}", item.id);
        }
    }
    fn add_vehicle(&mut self, new_vehicle: Vehicle){
        let mut insertion_index = 0;
        for (i = 0, i < self.vehicle_list.length(), i++){
            if new_vehicle.flight_time < self.vehicle_list[i].flight_time{
                insertion_index = i;
                break;
            }
        }
        self.vehicle_list.insert(insertion_index, new_vehicle);
    }
    fn remove_vehicle(&mut self, vehicle_to_remove: Vehilce){
        self.vehicle_list.remove(vehicle_to_remove);
    }
    fn turn_on_vehicles(&mut self){
        for vehicle in &mut self.vehicle_list{
            vehicle.turn_on();
        }
    }
    fn turn_off_vehicles(&mut self){
        for vehicle in &mut self.vehicle_list{
            vehicle.turn_off();
        }
    }
}
// User Structure 
struct User { //Bug #2: ChatGPT is telling me I need to put in <a'> tags here, but I'm not sure why or what they do. So I'm leaving my mistake in, to solve for later.
    username: String,
    connected_vehicle: Option<Vehicle>,
}

impl User{
    fn new(username: &str) -> Self {
        Self {
            username: String::from(username),
            connected_vehicle: None,
        }
    }
    fn connect(&mut self, vehicle_list: &Vec<Vehicle>) {
        let mut lowest_flight_vehicle = &vehicle_list[0];
        for vehicle in vehicle_list {
            if vehicle.flight_time < lowest_flight_vehicle.flight_time {
                lowest_flight_vehicle = vehicle;
            }
        }
        self.connected_vehicle = Some(lowest_flight_vehicle);
        // Bug #3: The compiler is really unhappy about the line below. I'm trying to tell the vehicle that the user will be controlling to take off. I think the issue's root is the same as Bug #1: I've passed in a vector of actual vehicles, instead of a reference to the original vehicle. So the 'lowest flight vehicle' maybe doesn't have access to the functions a normal vehicle would have access to? 
        lowest_flight_vehicle.start_flight(); 
        println!("{}", lowest_flight_vehicle.id); 
    }
    fn disconnect(&mut self){
        self.connected_vehicle.end_flight();
        self.connected_vehicle = None;
    }
}

fn main() {
    let mut vehicle1 = Vehicle::new("Vehicle1");
    let mut vehicle2 = Vehicle::new("Vehicle2");
    let mut vehicle3 = Vehicle::new("Vehicle3");

    let mut fleet1 = Fleet::new("Fleet 1");
    let mut user1 = User::new("User 1");
    
    vehicle1.turn_on();
    vehicle1.start_flight();
    sleep(StdDuration::from_secs(1));
    vehicle1.end_flight();
    
    fleet1.add_vehicle(vehicle1);
    fleet1.add_vehicle(vehicle2);
    fleet1.add_vehicle(vehicle3);

    user1.connect(&fleet1.vehicle_list);
    user1.disconnect();
}