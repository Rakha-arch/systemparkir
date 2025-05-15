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
        if ((int)parkingSlots.size() >= capacity) {
            cout << "⚠️ Parking lot is full. Cannot park car " << licensePlate << "." << endl;
            return false;
        }
        if (parkingSlots.find(licensePlate) != parkingSlots.end()) {
            cout << "⚠️ Car with license plate " << licensePlate << " is already parked." << endl;
            return false;
        }
        time_t now = time(nullptr);
        Car newCar{licensePlate, now};
        parkingSlots[licensePlate] = newCar;
        cout << "✅ Car " << licensePlate << " parked at " << ctime(&now);
        return true;
    }

    bool leaveCar(const string& licensePlate) {
        auto it = parkingSlots.find(licensePlate);
        if (it == parkingSlots.end()) {
            cout << "⚠️ Car with license plate " << licensePlate << " not found in parking lot." << endl;
            return false;
        }
        time_t exitTime = time(nullptr);
        time_t entryTime = it->second.entryTime;
        double durationMinutes = difftime(exitTime, entryTime) / 60.0;
        double durationHours = durationMinutes / 60.0;
        double fee = ratePerHour * durationHours;

        // Calculate minimum fee for a fraction of an hour - round up to next hour
        int hoursCharged = (int)(durationHours);
        if (durationHours - hoursCharged > 0) hoursCharged +=1;
        fee = hoursCharged * ratePerHour;

        totalEarnings += fee;
        parkingSlots.erase(it);
        cout << "✅ Car " << licensePlate << " left at " << ctime(&exitTime);
        cout << fixed << setprecision(2);
        cout << "⏱ Parking duration: " << durationMinutes << " minutes (" << hoursCharged << " hours charged)." << endl;
        cout << "💰 Parking fee: $" << fee << endl;
        return true;
    }

    void showStatus() const {
        cout << "\n📋 Current parked cars (" << parkingSlots.size() << "/" << capacity << "):" << endl;
        if (parkingSlots.empty()) {
            cout << "No cars parked." << endl;
            return;
        }
        for (const auto& pair : parkingSlots) {
            const Car& car = pair.second;
            cout << " - " << car.licensePlate << ", entry time: " << ctime(&car.entryTime);
        }
    }

    void showEarnings() const {
        cout << fixed << setprecision(2);
        cout << "\n💵 Total earnings: $" << totalEarnings << endl;
    }
};

int main() {
    int capacity;
    double rate;
    cout << "🅿️  Enter parking lot capacity: ";
    cin >> capacity;
    cout << "💲 Enter hourly parking rate (e.g. 5.0): $";
    cin >> rate;
    ParkingLot lot(capacity, rate);
    cin.ignore();

    while (true) {
        cout << "\nMenu:\n1. Park Car\n2. Leave Car\n3. Show Parking Status\n4. Show Total Earnings\n5. Exit\nChoose option: ";
        int option;
        cin >> option;
        cin.ignore();

        if (option == 1) {
            cout << "Enter license plate to park: ";
            string plate;
            getline(cin, plate);
            lot.parkCar(plate);
        } else if (option == 2) {
            cout << "Enter license plate to leave: ";
            string plate;
            getline(cin, plate);
            lot.leaveCar(plate);
        } else if (option == 3) {
            lot.showStatus();
        } else if (option == 4) {
            lot.showEarnings();
        } else if (option == 5) {
            cout << "👋 Exiting system. Goodbye!" << endl;
            break;
        } else {
            cout << "⚠️ Invalid option, please try again." << endl;
        }
    }

    return 0;
}

