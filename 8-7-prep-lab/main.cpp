#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    Student(string name = "not initialized", double gpa = 0.0);
    void SetName(string studentName);
    void SetGPA(double newGPA);
    string ToString() const;
private:
    string name;
    double gpa;
};

Student::Student(string initialName, double initialGPA) {
    name = initialName;
    gpa = initialGPA;
}

void Student::SetName(string inputName) {
    name = inputName;
}

void Student::SetGPA(double newGPA) {
    gpa = newGPA;
}

//Insert the ToString member function here
string Student::ToString() const {
    string returnedString = "";
    string gpaToString = "";

    // Convert double to string
    gpaToString = to_string(gpa);

    // Build returned string by appending
    returnedString = name + "has a GPA of " + gpaToString;

    return returnedString;
}

int main() {
    vector<Student*> students;
    bool continueLoop = true;
    string userInput = "";
    string userStudentName = "";
    double userStudentGpa = 0.0;


    // Menu loop
    while (continueLoop) {
        cout << "Enter Option: ";
        cin >> userInput;
        cout << endl;

        if (userInput == "quit") {
            continueLoop = false;
            exit(0);
        }
        if (userInput == "add") {
            // Input for new student information
            cout << "Student name: ";
            cin >> userStudentName;
            cout << userStudentName << "'s GPA: ";
            cin >> userStudentGpa;

            // Creating new student object with new to allocate memory
            Student* newStudent = new Student(userStudentName, userStudentGpa);
            students.push_back(newStudent); // It seems that we don't need a passby reference here
        }
        if (userInput == "drop") {
            int userIndex = 0;
            cout << "Index of student to drop: ";
            cin >> userIndex;

            delete students.at(userIndex); // zyBooks threw no error here. Seems that delete was used properly.
            students.erase(students.begin() + userIndex);
        }
        if (userInput == "print") {
            for (unsigned int i = 0; i < students.size(); ++i) {
                cout << i << ": " << students.at(i)->ToString() << endl;
            }
        }
    }


    return 0;
}