use chrono::{Local, Duration};
use std::thread::sleep;
use std::time::Duration as StdDuration;

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
        println!("Car 1 is on!");
    }
    fn turn_off(&mut self){
        self.is_online = false;
    }
    fn start_flight(&mut self){
        self.start_time = Local::now().timestamp_millis() as u64;
    }
    fn end_flight(&mut self){
        let end_time = Local::now().timestamp_millis() as u64;
        let flight_duration = end_time - self.start_time;
        println!("{}",flight_duration)
        // self.flight_time += flight_duration;
    }

}


fn main() {
    let mut vehicle1 = Vehicle::new("Vehicle1");
    vehicle1.turn_on();
    vehicle1.start_flight();
    sleep(StdDuration::from_secs(2));
    vehicle1.end_flight();
    println!("Hello, world!");
}
