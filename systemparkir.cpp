#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>
#include <iomanip>

using namespace std;

struct Car {
    string licensePlate;
    time_t entryTime;
};

class ParkingLot {
private:
    unordered_map<string, Car> parkingSlots;
    int capacity;
    double totalEarnings;
    double ratePerHour;

public:
    ParkingLot(int cap, double rate) : capacity(cap), ratePerHour(rate), totalEarnings(0) {}

    bool parkCar(const string& licensePlate) {
        if ((int)parkingSlots.size() >= capacity) 
        {
            cout << "⚠️ Parking lot is full. Cannot park car " << licensePlate << "." << endl;
            return false;
        }
        if (parkingSlots.find(licensePlate) != parkingSlots.end()) 
        {
            cout << "⚠️ Car with license plate " << licensePlate << " is already parked." << endl;
            return false;
        }
       
    }

    
    {
        
        }
       


    }

    void showStatus() const 
    {
       
        }
      ;
        }
    }

    void showEarnings() const 
    {
        
    }
};

int main() {
   

    while (true) {
      
        {
           
        } 
        
        {
            
        } 
        
        {
          
        } 
       
        {
           
        }
         
        {
            
        } 
        else
        {
           
        }
    }

    return 0;
}

