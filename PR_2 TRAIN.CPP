#include <iostream>
#include <cstring>
using namespace std;
class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    Train(int number, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

   
    ~Train() {
        trainCount--;
    }

    
    void setTrainNumber(int number) { trainNumber = number; }
    int getTrainNumber() const { return trainNumber; }

    void setTrainName(const char* name) { strcpy(trainName, name); }
    const char* getTrainName() const { return trainName; }

    void setSource(const char* src) { strcpy(source, src); }
    const char* getSource() const { return source; }

    void setDestination(const char* dest) { strcpy(destination, dest); }
    const char* getDestination() const { return destination; }

    void setTrainTime(const char* time) { strcpy(trainTime, time); }
    const char* getTrainTime() const { return trainTime; }

    
    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source Station: ";
        cin.getline(source, 50);

        cout << "Enter Destination Station: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

   
    void displayTrainDetails() const {
        cout << "\nTrain Number: " << trainNumber
             << "\nTrain Name: " << trainName
             << "\nSource: " << source
             << "\nDestination: " << destination
             << "\nTime: " << trainTime << endl;
    }

    static int getTrainCount() {
        return trainCount;
    }
};


int Train::trainCount = 0;


class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
        trains[0] = Train(101, "Rajdhani Express", "Delhi", "Mumbai", "08:00");
        trains[1] = Train(102, "Shatabdi Express", "Ahmedabad", "Delhi", "06:00");
        trains[2] = Train(103, "Duronto Express", "Kolkata", "Chennai", "20:30");
        totalTrains = 3;
    }

    void addTrain() {
        if (totalTrains < 100) {
            cout << "\nAdding new train record:\n";
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        } else {
            cout << "Train limit reached." << endl;
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No trains to display.\n";
        } else {
            for (int i = 0; i < totalTrains; i++) {
                cout << "\n--- Train " << (i + 1) << " ---";
                trains[i].displayTrainDetails();
            }
        }
    }

    void searchTrainByNumber(int number) const {
        bool found = false;
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\nTrain found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << number << " not found.\n";
        }
    }
};


int main() {
    RailwaySystem rs;
    int choice;
    do {
        cout << "\n====== Railway System Menu ======";
        cout << "\n1. Display All Trains";
        cout << "\n2. Add New Train";
        cout << "\n3. Search Train by Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rs.displayAllTrains();
                break;
            case 2:
                rs.addTrain();
                break;
            case 3: {
                int number;
                cout << "Enter train number to search: ";
                cin >> number;
                rs.searchTrainByNumber(number);
                break;
            }
            case 4:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
/*OUTPUT:
===== Railway System Menu ======
1. Display All Trains
2. Add New Train
3. Search Train by Number
4. Exit
Enter your choice: 1

--- Train 1 ---
Train Number: 101
Train Name: Rajdhani Express
Source: Delhi
Destination: Mumbai
Time: 08:00

--- Train 2 ---
Train Number: 102
Train Name: Shatabdi Express
Source: Ahmedabad
Destination: Delhi
Time: 06:00

--- Train 3 ---
Train Number: 103
Train Name: Duronto Express
Source: Kolkata
Destination: Chennai
Time: 20:30

====== Railway System Menu ======
1. Display All Trains
2. Add New Train
3. Search Train by Number
4. Exit
Enter your choice: 2

Adding new train record:
Enter Train Number: 104
Enter Train Name: RAJDHANI2
Enter Source Station: DELHI
Enter Destination Station: AHEMDABAD
Enter Train Time: 03:00

====== Railway System Menu ======
1. Display All Trains
2. Add New Train
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter train number to search: 105
Train with number 105 not found.

====== Railway System Menu ======
1. Display All Trains
2. Add New Train
3. Search Train by Number
4. Exit
Enter your choice: 4
Exiting... Thank you!
*/