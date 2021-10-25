#include <iostream>
#include <string.h>

using namespace std;

void airlineSystem () {
    //All of the seats in the plane array & other variable initializations//
    bool seats[10] = {0,0,0,0,0,0,0,0,0,0};
    int selection, seat;
    int counter = 0;
    //CLASS CHOICE//
    reset: cout << "Please type 1 for 'first class. " << endl;
    cout << "Please type 2 for 'economy'. "<< endl;
    cout << "Your choice: ";
    cin >> selection;
    reselect: //USED TO GO BACK IF THEY DECIDE TO GO INTO OTHER CLASS WHEN ONE IS FILLED//
    switch (selection) {
        case 1:
            for (int i = 0; i < 5; i++){
                if (i == 4 && seats[i] != 0) {

                    //CHECKS IF THE PERSON ALREADY SWAPPED CLASSES//

                    if (counter == 1) {cout << "No available spaces in this plane, next one is in 3 hours."; return;}

                    //ALLOWS THE PERSON TO SWITCH CLASS IF NO FREE SEATS AND THEY HAVENT SWITCHED ALREADY//

                    cout << "No available spaces in 'first class' would you like to be placed into 'economy'? y/n: ";
                    char choice;
                    cin >> choice;
                    if (choice == 'y' || choice == 'Y') {selection = 2; counter = counter + 1; goto reselect;}

                    //CASE WHERE THEY REFUSE TO CHANGE CLASSES//

                    else {cout << "Next flight leaves in 3 hours."; return;}
                }
                //CHECKING FOR FREE SEATS IN THE SELECTED FIRST CLASS//

                if (seats[i] == 0) {
                    seats[i] = 1;
                    seat = i+1;
                    break;
                }
                
            }
            break;
        case 2:

        //ECONOMY CLASS/
            //THIS ENTIRE THINGS WORKS THE SAME AS PREVIOUS JUST THE SWAPS ARE TO FS INSTEAD OF ECONOMY//
            //I LITERALLY COPIED IT AND EDITED IT, YOU WILL LEARN THAT THIS IS 90% OF PROGRAMMING//

            for (int i = 5; i < 10; i++) {                                                                              
                if (i == 9 && seats[i] != 0) {
                    if (counter == 1) {cout << "No available spaces in this plane, next one is in 3 hours."; return;}
                    cout << "No available spaces in 'economy' would you like to be placed into 'first class'? y/n: ";
                    char choice;
                    cin >> choice;
                    if (choice == 'y' || choice == 'Y') {selection = 1;counter = counter + 1; goto reselect; }
                    else {cout << "Next flight leaves in 3 hours."; return;}
                }
                if (seats[i] == 0) {
                    seats[i] = 1;
                    seat = i+1;
                    break;
                }
            }
            break;

        //THIS IS JUST WHEN THEY USE A NUMBER OTHER THAN 1 OR 2 FOR CLASS SELECT    

        default:
            cout <<"Please enter an existing option!"<<endl;
            goto reset;
    }

    //JUST A STRING FOR OUTPUT OF CLASS//

    string classOfFlight;
    char selection2;

    //CHECKS FOR THE CLASS SO IT CAN OUTPUT IT//

    if (selection == 1) classOfFlight = "First Class"; 
    else if (selection == 2) classOfFlight = "Economy";
    cout << endl;

    //NEW TICKET BOOKED OUTPUT//

    cout << "New ticket booked!" << endl;
    cout << "Class: " << classOfFlight << endl;
    cout << "Seat: " << seat << endl;
    cout << endl;

    //BOOK ANOTHER TICKET OPTION//

    cout << "Would you like to book another ticket? y/n: ";
    cin >> selection2;
    if (selection2 == 'y' || selection2 == 'Y') goto reset;
    else return;
}


int main() {
    airlineSystem();
    return 0;
}