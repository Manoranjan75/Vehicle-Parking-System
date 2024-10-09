# Car Parking Management System

## Overview
The Car Parking Management System is a C++ console application designed to manage a car parking facility. It provides functionalities for parking cars, viewing car details, checking expenses, and removing cars from the parking lot.

## Features
- Secure login system
- Park a car with driver and car details
- View parked car details
- Check parking expenses
- Remove a car from the parking lot (with time and expense summary)
- Simple console-based user interface

## Requirements
- C++ compiler (supporting C++11 or later)
- Standard C++ libraries

## How to Compile and Run
1. Ensure you have a C++ compiler installed on your system.
2. Clone this repository or download the source code.
3. Navigate to the project directory in your terminal or command prompt.
4. Compile the code using your C++ compiler. For example:
   ```
   g++ -std=c++11 main.cpp -o car_parking_system
   ```
5. Run the compiled executable:
   ```
   ./car_parking_system
   ```

## Usage
1. When you start the program, you'll be prompted to enter a password. The default password is "man".
2. After successful login, you'll see a menu with the following options:
   - Park Your Car
   - View Your Car Details
   - Check Expenses
   - Remove Your Car
   - EXIT
3. Choose an option by entering the corresponding number.
4. Follow the on-screen prompts to complete each action.

## Important Notes
- The system uses file storage to maintain records. Two files will be created in the same directory as the executable:
  - `carparkdb.txt`: Stores car parking details
  - `carparkexpensedb.txt`: Stores expense information
- Make sure the program has write permissions in the directory it's running from.
- The parking rate is set to 100 Rupees per hour.

## Contributing
Contributions to improve the Car Parking Management System are welcome. Please feel free to fork the repository, make changes, and submit a pull request.
