#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <string>

class ParkingSlot {
private:
    int slotID;
    bool isOccupied;
    std::string vehicleNumber;

public:
    ParkingSlot(int id) : slotID(id), isOccupied(false), vehicleNumber("") {}

    bool occupySlot(const std::string& vehicleNum) {
        if (!isOccupied) {
            isOccupied = true;
            vehicleNumber = vehicleNum;
            return true;
        }
        return false;
    }

    void vacateSlot() {
        isOccupied = false;
        vehicleNumber = "";
    }

    bool getStatus() const {
        return isOccupied;
    }

    int getID() const {
        return slotID;
    }

    std::string getVehicleNumber() const {
        return vehicleNumber;
    }
};

class Vehicle {
private:
    std::string vehicleNumber;
    time_t entryTime;
    time_t exitTime;

public:
    // Constructor that initializes vehicle number and entry time
    Vehicle(const std::string& number) : vehicleNumber(number), entryTime(time(0)), exitTime(0) {}

    void setExitTime() {
        exitTime = time(0);
    }

    time_t getEntryTime() const {
        return entryTime;
    }

    time_t getExitTime() const {
        return exitTime;
    }

    std::string getVehicleNumber() const {
        return vehicleNumber;
    }
};

class FeeCalculator {
private:
    double ratePerHour;

public:
    FeeCalculator(double rate) : ratePerHour(rate) {}

    double calculateFee(const Vehicle& vehicle) {
        double duration = difftime(vehicle.getExitTime(), vehicle.getEntryTime()) / 3600.0; // convert seconds to hours
        return duration * ratePerHour;
    }
};

class ParkingLot {
private:
    std::vector<ParkingSlot> slots;
    std::map<std::string, Vehicle> parkedVehicles;

public:
    ParkingLot(int numSlots) {
        for (int i = 1; i <= numSlots; ++i) {
            slots.emplace_back(i);
        }
    }

    bool parkVehicle(const std::string& vehicleNum) {
        for (auto& slot : slots) {
            if (!slot.getStatus()) {
                slot.occupySlot(vehicleNum);
                parkedVehicles.emplace(vehicleNum, Vehicle(vehicleNum)); // Correctly initialize Vehicle with vehicleNum
                return true;
            }
        }
        return false;
    }

    bool removeVehicle(const std::string& vehicleNum, FeeCalculator& feeCalc) {
        auto it = parkedVehicles.find(vehicleNum);
        if (it != parkedVehicles.end()) {
            it->second.setExitTime();
            double fee = feeCalc.calculateFee(it->second);
            std::cout << "Vehicle " << vehicleNum << " exited. Fee: $" << fee << std::endl;
            for (auto& slot : slots) {
                if (slot.getVehicleNumber() == vehicleNum) {
                    slot.vacateSlot();
                    break;
                }
            }
            parkedVehicles.erase(it);
            return true;
        }
        return false;
    }

    int getAvailableSlots() const {
        int count = 0;
        for (const auto& slot : slots) {
            if (!slot.getStatus()) {
                count++;
            }
        }
        return count;
    }

    void displayStatus() const {
        for (const auto& slot : slots) {
            std::cout << "Slot " << slot.getID() << ": " << (slot.getStatus() ? "Occupied by " + slot.getVehicleNumber() : "Available") << std::endl;
        }
    }
};

int main() {
    int numSlots;
    double ratePerHour;

    std::cout << "Enter the number of parking slots: ";
    std::cin >> numSlots;
    std::cout << "Enter the hourly parking rate: ";
    std::cin >> ratePerHour;

    ParkingLot parkingLot(numSlots);
    FeeCalculator feeCalculator(ratePerHour);

    while (true) {
        std::cout << "\nMenu:\n1. Park Vehicle\n2. Remove Vehicle\n3. Check Available Slots\n4. Display Parking Lot Status\n5. Exit\n";
        int choice;
        std::cin >> choice;
        std::string vehicleNum;

        switch (choice) {
            case 1:
                std::cout << "Enter vehicle number: ";
                std::cin >> vehicleNum;
                if (parkingLot.parkVehicle(vehicleNum)) {
                    std::cout << "Vehicle parked successfully.\n";
                } else {
                    std::cout << "Parking full.\n";
                }
                break;

            case 2:
                std::cout << "Enter vehicle number: ";
                std::cin >> vehicleNum;
                if (parkingLot.removeVehicle(vehicleNum, feeCalculator)) {
                    std::cout << "Vehicle removed successfully.\n";
                } else {
                    std::cout << "Vehicle not found.\n";
                }
                break;

            case 3:
                std::cout << "Available slots: " << parkingLot.getAvailableSlots() << "\n";
                break;

            case 4:
                parkingLot.displayStatus();
                break;

            case 5:
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
