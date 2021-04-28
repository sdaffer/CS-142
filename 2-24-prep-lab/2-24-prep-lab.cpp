#include <iostream>
#include <cmath>                   // Note: Needed for math functions in part (3)
using namespace std;

int main() {
    double wallHeight = 0.0;
    double wallWidth = 0.0;
    double wallArea = 0.0;
    const double coverageOneGallon = 350;

    // Get inputs from user
    cout << "Enter wall height (feet): ";
    cin  >> wallHeight;
    cout << endl;

    cout << "Enter wall width (feet): ";
    cin  >> wallWidth;
    cout << endl;

    // Calculate and output wall area
    wallArea = wallHeight * wallWidth;

    // Output calculation
    cout << "Wall area: " << wallArea << " square feet" << endl;

    // Calculate and output gallons of paint needed
    cout << "Paint needed: " << wallArea / coverageOneGallon << " gallons" << endl;

    // Use math function to round gallons needed to the next largest whole number and output
    cout << "Cans needed: " << ceil(wallArea / coverageOneGallon) << " can(s)" << endl;

    return 0;
}