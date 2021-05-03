#include <iostream>
using namespace std;

int main() {
    char triangleChar = ' ';
    int triangleHeight = 0;

    cout << "Enter a character: " << endl;
    cin >> triangleChar;

    cout << "Enter triangle height: " << endl;
    cin >> triangleHeight;

    string charString = "";
    for (int i = 0; i < triangleHeight; ++i) {
        charString.push_back(triangleChar);
        charString.push_back(' ');
        cout << charString << endl;
    }
    return 0;
}