#include <iostream>
using namespace std;

//Define your class here
class Door {
    public:
        // Default constructor
        Door();

        // Setters
        void LockDoor();
        void UnlockDoor();
        void OpenDoor();
        void CloseDoor();

    private:
        bool isOpen;
        bool isLocked;
};

// Default constructor
Door::Door(){
    isOpen = false;
    isLocked = true;
}

// Setters
void Door::LockDoor() {
    if (!isOpen && !isLocked) {
        isLocked = true;
    }
    else {
        if (isOpen) {
            cout << "Sorry, the door is open." << endl;
        }
        if (!isOpen && isLocked) {
            cout << "The door is already locked." << endl;
        }
    }
}
void Door::UnlockDoor() {
    if (!isOpen && isLocked) {
        isLocked = false;
    }
    else {
        if (isOpen) {
            cout << "Sorry, the door is open." << endl;
        }
        if (!isOpen && !isLocked) {
            cout << "The door is already unlocked." << endl;
        }
    }
}
void Door::OpenDoor() {
    if (isOpen) {
        cout << "The door is already open." << endl;
    }
    else {
        if (isLocked){
            cout << "Sorry, the door is locked." << endl;
        }
        else {
            isOpen = true;
        }
    }
}
void Door::CloseDoor() {
    if (!isOpen) {
        cout << "The door is already shut." << endl;
    }
    else {
        isOpen = false;
    }
}


//Do not edit below this line-----------------------------------------------------------------

int main() {
    Door pantryDoor;
    Door frontDoor;


    frontDoor.LockDoor();
    frontDoor.UnlockDoor();
    frontDoor.UnlockDoor();
    frontDoor.OpenDoor();
    frontDoor.LockDoor();
    frontDoor.UnlockDoor();
    frontDoor.CloseDoor();
    frontDoor.LockDoor();
    frontDoor.LockDoor();
    pantryDoor.OpenDoor();
    pantryDoor.UnlockDoor();
    pantryDoor.OpenDoor();
    pantryDoor.OpenDoor();
    frontDoor.CloseDoor();
    pantryDoor.CloseDoor();
    pantryDoor.CloseDoor();
    pantryDoor.LockDoor();
    pantryDoor.OpenDoor();

    return 0;
}
