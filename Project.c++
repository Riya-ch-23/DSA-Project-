#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Vehicle {
    string reg_no;
    int priority;  

    Vehicle(string r, int p) : reg_no(r), priority(p) {}
};

struct ComparePriority {
    bool operator()(Vehicle const& v1, Vehicle const& v2) {
        return v1.priority > v2.priority;  
    }
};

class ParkingManagement {
private:
    int total_spots;
    priority_queue<Vehicle, vector<Vehicle>, ComparePriority> pq;

public:
    ParkingManagement(int spots) : total_spots(spots) {}


    void parkVehicle(string reg_no, int priority) {
        if (pq.size() >= total_spots) {
            cout << "Parking full. Can't park vehicle: " << reg_no << endl;
            return;
        }
        pq.push(Vehicle(reg_no, priority));
        cout << "Vehicle " << reg_no << " parked with priority " << priority << endl;
    }

    void removeVehicle() {
        if (pq.empty()) {
            cout << "Parking empty. No vehicles to remove." << endl;
            return;
        }
        Vehicle v = pq.top();
        pq.pop();
        cout << "Vehicle " << v.reg_no << " with priority " << v.priority << " removed from parking." << endl;
    }

    void availableSpots() {
        cout << "Available spots: " << total_spots - pq.size() << "/" << total_spots << endl;
    }
};

int main() {
    int total_spots = 5; 
    ParkingManagement parking(total_spots);

    parking.parkVehicle("KA-01-1234", 2);  
    parking.parkVehicle("KA-02-5678", 1); 
    parking.parkVehicle("KA-03-9876", 3);  

    parking.availableSpots();  

    parking.removeVehicle();  
    parking.removeVehicle();

    parking.availableSpots(); 

    return 0;
}