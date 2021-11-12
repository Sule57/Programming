#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int num = rand() % 100;
    int guess;
    bool a = 0;
    cout << "Input your guess: " << endl;
    while (a == 0) {
        cin >> guess;
        if (guess == num) {
            cout << "Congratulations you have guessed the number.";
            a = 1;
        }
        else if (guess < num) {
            cout << "It's a bit bigger."<< endl << "Guess again: "<< endl;
        }
        else {
            cout << "It's a bit smaller"<<endl << "Guess again: "<< endl;
        }
    }
    return 0;
}