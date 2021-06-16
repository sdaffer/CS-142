#include "PeopleList.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    int personAge = 0;
    string personName = "Uninitialized";
    PeopleList personList;
    int numberOfPeople = 0;

    cout << "Congratulations! Your program has compiled!\n" << endl;//this line earns you points...

    cout << "How many people would you like to add to the list to be sorted?:\n";
    cin >> numberOfPeople;

    for(int i = 0; i < numberOfPeople; i++){
        cout << "Enter person " << i + 1 << "'s first name:\n";
        cin >> personName;
        cout << "Enter person " << i + 1 << "'s age:\n";
        cin >> personAge;

        personList.Add(Person(personName, personAge));
    }

    cout << endl;
    personList.PrintList();

    return 0;
}
