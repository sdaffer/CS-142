#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int arrowBaseHeight = 0;
    int arrowBaseWidth = 0;
    int arrowHeadWidth = 0;
    int currentArrowHeadWidth = 0;

        cout << "Enter arrow base height: " << endl;
        cin >> arrowBaseHeight;

        cout << "Enter arrow base width: " << endl;
        cin >> arrowBaseWidth;

        cout << "Enter arrow head width: " << endl;
        cin >> arrowHeadWidth;

    while (arrowHeadWidth <= arrowBaseWidth) {
        cout << "Enter arrow head width: " << endl;
        cin >> arrowHeadWidth;
    }

    for (int i = 0; i < arrowBaseHeight; ++i) {
        for (int j = 0; j < arrowBaseWidth; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    currentArrowHeadWidth = arrowHeadWidth;
    for (int i = 0; i < arrowHeadWidth; ++i) {

        for (int j = 0; j < currentArrowHeadWidth; ++j) {
           cout << "*";
        }
        currentArrowHeadWidth = currentArrowHeadWidth - 1;
        cout << endl;
    }
    return 0;
}