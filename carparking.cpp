#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

class login
{
public:
    int loginsys();
    string pass = "man";
};

typedef struct car
{
    string drivername;
    string carname;
    string carid;
    int timestay;
} car;

int login ::loginsys()
{
    while (1)
    {
        string password;
        cout << "\n\n\n\n\t\t\t\t---------->  CAR PARKING MANAGEMENT SYSTEM  <----------" << endl;
        char ch;
        cout << "\n\n\n\t\t\t\t\t  Car Parking Reservation System Login";
        cout << "\n\n\n\n\t\t\t\t\t\t    Enter Password: ";
        ch = _getch();

        while (ch != 13)
        {
            password.push_back(ch);
            cout << '*';
            ch = _getch();
        }

        if (password == pass)
        {
            cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
            system("PAUSE");
            break;
        }
        else
        {
            cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
            system("PAUSE");
            system("CLS");
        }
    }
    return 1;
}

class ParkingManagement
{
public:
    void park(ParkingManagement);
    void cardetail();
    void addexpensedb(car CAR[], int);
    void expense();
    void removecar();
};

int count = 0;

void ParkingManagement ::park(ParkingManagement obj)
{
    cout << "                        -------------> Car Parking System <-------------" << endl
         << endl;

    ofstream out;

    car CAR[10];
    out.open("carparkdb.txt", ios::app);

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Name : ";
    getchar();
    getline(cin, CAR[count].drivername);

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your CarName : ";
    getline(cin, CAR[count].carname);

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Car Number Plate  (Remember It Well!) : ";
    cin >> CAR[count].carid;

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your Time Stay In Hours (Integer Only) : ";
    cin >> CAR[count].timestay;

    out << "Car Name : " << CAR[count].carname
        << ", Car Id : " << CAR[count].carid << "\n"
        << "Driver Name : " << CAR[count].drivername
        << ", Car Time Stay : " << CAR[count].timestay << " hours\n";

    addexpensedb(CAR, count);

    count++;
    out.close();
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Your Car Is Parked Now!" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    getch();
}

void ParkingManagement ::cardetail()
{
    system("CLS");
    int i = 0;
    string detailid;
    string line;
    ifstream in;
    cout << "                        -------------> Your Car Details <-------------" << endl
         << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Enter Your CarID : ";
    getchar();
    getline(cin, detailid);
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    in.open("carparkdb.txt");
    while (getline(in, line))
    {
        size_t found = line.find(detailid);
        if (found != string::npos)
        {
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Your Car Details Are : " << endl;
            cout << line << endl;
            getline(in, line);
            cout << line << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Press Enter Key To Return" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            getch();
            in.close();
            i++;
            break;
        }
    }

    in.close();

    if (i == 0)
    {
        cout << "Car With CarID " << detailid << " Not Found" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "TRY AGAIN! (Use Correct CarID)" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "Press Enter Key To Return" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        getch();
    }
}

void ParkingManagement ::addexpensedb(car CAR[], int count)
{
    ofstream out;

    out.open("carparkexpensedb.txt", ios::app);

    out << "Car ID : " << CAR[count].carid << ", Car Name : " << CAR[count].carname << "\n";
    out << "Driver Name : " << CAR[count].drivername << ", Car Time Stay : " << CAR[count].timestay
        << " hours, Total Expense : " << CAR[count].timestay * 100 << " Rupees\n";

    out.close();
}

void ParkingManagement ::expense()
{
    system("CLS");
    string cexpenseid, line;
    int i = 0;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << "                        -------------> Car Parking Expenses <-------------" << endl;
    cout << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    cout << "Enter Your Car Id : ";
    cin >> cexpenseid;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    ifstream in;
    in.open("carparkexpensedb.txt");
    while (getline(in, line))
    {
        size_t found = line.find(cexpenseid);
        if (found != string::npos)
        {
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Your Car Parking Expense Details Are : " << endl;
            cout << line << endl;
            getline(in, line);
            cout << line << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Press Enter Key To Return" << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            getch();
            in.close();
            i++;
            break;
        }
    }

    in.close();

    if (i == 0)
    {
        cout << "Car With CarID " << cexpenseid << " Not Found" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "TRY AGAIN! (Use Correct CarID)" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "Press Enter Key To Return" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        getch();
    }
}

void ParkingManagement ::removecar()
{
    system("CLS");
    string rcarid;
    string line, nextline;
    bool carFound = false;
    int totalExpense = 0;
    int parkingTime = 0;

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << endl;
    cout << "                        -------------> Car Parking Check Out System <-------------"
         << endl;
    cout << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    cout << "Enter Your Car Id : ";
    cin >> rcarid;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;

    ifstream in;
    ofstream out;
    in.open("carparkdb.txt");
    out.open("temp.txt", ios::app);
    while (getline(in, line))
    {
        size_t found = line.find(rcarid);
        if (found != string::npos)
        {
            carFound = true;
            getline(in, line); // Get the next line with time information
            size_t timePos = line.find("Car Time Stay : ");
            if (timePos != string::npos)
            {
                string timeStr = line.substr(timePos + 15);
                parkingTime = stoi(timeStr);
            }
        }
        else
        {
            out << line << endl;
        }
    }

    in.close();
    out.close();

    remove("carparkdb.txt");
    rename("temp.txt", "carparkdb.txt");

    in.open("carparkexpensedb.txt");
    out.open("tempexpense.txt", ios::app);
    while (getline(in, nextline))
    {
        size_t found = nextline.find(rcarid);
        if (found != string::npos)
        {
            carFound = true;
            getline(in, nextline);
            // Extract the total expense
            size_t expensePos = nextline.find("Total Expense : ");
            if (expensePos != string::npos)
            {
                string expenseStr = nextline.substr(expensePos + 16);
                totalExpense = stoi(expenseStr);
            }
        }
        else
        {
            out << nextline << endl;
        }
    }

    in.close();
    out.close();

    remove("carparkexpensedb.txt");
    rename("tempexpense.txt", "carparkexpensedb.txt");

    if (carFound)
    {
        cout << "Car with ID " << rcarid << " has been removed." << endl;
        cout << "Parking Time: " << parkingTime << " hours" << endl;
        cout << "Total parking expense: " << totalExpense << " Rupees" << endl;
        cout << "Good Bye" << endl << "Thanks For Choosing Us!" << endl;
    }
    else
    {
        cout << "Car with ID " << rcarid << " not found." << endl;
    }

    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    cout << "Press Enter Key To Return" << endl;
    cout << "---------------------------------------------------";
    cout << "---------------------------------------------------" << endl;
    getch();
}

int main()
{
    system("CLS");
    login loginobj;
    loginobj.loginsys();
    ParkingManagement parkobj;

    while (1)
    {
        system("CLS");
        int choice;
        cout << "                        -------------> Car Parking System <-------------" << endl
             << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "1. Park Your Car " << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "2. View Your Car Details" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "3. Check Expenses" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "4. Remove Your Car" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "5. EXIT" << endl;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        cout << "---------------------------------------------------";
        cout << "---------------------------------------------------" << endl;

        switch (choice)
        {
        case 1:
            char yn;
            cout << "Do Your Want To Continue (y/n) : ";
            cin >> yn;
            system("CLS");
            if (yn == 'y')
            {
                parkobj.park(parkobj);
            }
            system("CLS");
            break;

        case 2:
            parkobj.cardetail();
            break;

        case 3:
            parkobj.expense();
            break;

        case 4:
            parkobj.removecar();
            break;

        case 5:
            cout << endl;
            cout << " CREATED BY : Aman Kumar Singh";
            cout << endl
                 << endl;
            cout << "---------------------------------------------------";
            cout << "---------------------------------------------------" << endl;
            cout << "Press Enter Key To EXIT";
            getch();
            exit(0);

        default:
            system("CLS");
            cout << "You Entered A Wrong Choice!" << endl;
            break;
        }
    }

    return 0;
}