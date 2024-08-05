# Vehicle Parking Management System

This project is a simple car parking management system implemented in C++. It allows users to manage a parking lot by tracking parked vehicles, calculating parking fees, and displaying the status of parking slots.

## Features

- **Park Vehicle**: Register a vehicle's entry into the parking lot.
- **Remove Vehicle**: Record a vehicle's exit and calculate the parking fee based on the duration of the stay.
- **Check Available Slots**: Display the number of available parking slots.
- **Display Parking Lot Status**: Show the status of all parking slots, indicating whether they are occupied or available.

## Classes

### `ParkingSlot`
Represents an individual parking slot with the following functionalities:
- **Occupy Slot**: Mark the slot as occupied and store the vehicle number.
- **Vacate Slot**: Mark the slot as available.
- **Get Status**: Check if the slot is occupied.
- **Get ID**: Retrieve the slot ID.
- **Get Vehicle Number**: Get the vehicle number occupying the slot.

### `Vehicle`
Represents a vehicle with the following functionalities:
- **Constructor**: Initializes the vehicle number and entry time.
- **Set Exit Time**: Record the exit time of the vehicle.
- **Get Entry Time**: Retrieve the entry time.
- **Get Exit Time**: Retrieve the exit time.
- **Get Vehicle Number**: Get the vehicle number.

### `FeeCalculator`
Calculates the parking fee based on the hourly rate and the duration of the stay.
- **Constructor**: Initializes the rate per hour.
- **Calculate Fee**: Calculate the fee based on the duration between entry and exit times.

### `ParkingLot`
Manages a collection of parking slots and parked vehicles.
- **Constructor**: Initializes the parking slots.
- **Park Vehicle**: Attempt to park a vehicle in an available slot.
- **Remove Vehicle**: Remove a vehicle and calculate the parking fee.
- **Get Available Slots**: Return the number of available slots.
- **Display Status**: Display the status of all parking slots.

## How to Run

1. **Compile the Program**: Use a C++ compiler to compile the code. For example:
   ```sh
   g++ -o ParkingSystem ParkingSystem.cpp
   ```

2. **Run the Program**: Execute the compiled program.
   ```sh
   ./ParkingSystem
   ```

3. **Interact with the Menu**: Follow the on-screen prompts to park and remove vehicles, check available slots, and display the parking lot status.

## Example Usage

- **Parking a Vehicle**:
  ```
  Enter the number of parking slots: 5
  Enter the hourly parking rate: 10
  Menu:
  1. Park Vehicle
  2. Remove Vehicle
  3. Check Available Slots
  4. Display Parking Lot Status
  5. Exit

  Enter your choice: 1
  Enter vehicle number: ABC123
  Vehicle parked successfully.
  ```

- **Removing a Vehicle**:
  ```
  Enter your choice: 2
  Enter vehicle number: ABC123
  Vehicle ABC123 exited. Fee: $5
  Vehicle removed successfully.
  ```

## Acknowledgements

This project was created as a demonstration of C++ programming and object-oriented design principles.
