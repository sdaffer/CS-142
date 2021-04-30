#include <iostream>
#include <iomanip>
#include <cmath> // This library isn't used in my code, but I'm keeping it just in case it's needed for the zyBooks test to work
using namespace std;


// Function prototypes/declarations
double CalcRectanglePerimeter(double rectHeight, double rectWidth);
void PrintRectanglePerimeter(double rectHeight, double rectWidth);
void DoubleRectanglePerimeter(double& rectHeight, double& rectWidth);
double CalcCircumferenceOfCircle(double circleRadius);
double CalcAreaOfCircle(double circleRadius);
double CalcVolumeOfSphere(double circleRadius);
void Swap(int& firstValue, int& secondValue);
void Swap(double& firstValue, double& secondValue);


// Global constants
const double PI = 3.14;


// Main function
int main(){
    cout << "Getting this line to print earns you points!\n";

    double height = 0;
    double width = 0;
    double radius = 0;

    cin >> height >> width >> radius;

    PrintRectanglePerimeter(height, width);
    cout << CalcRectanglePerimeter(height, width) << std::endl;
    cout << "... about to double height and width...\n";
    DoubleRectanglePerimeter(height, width);
    PrintRectanglePerimeter(height, width);


    return 0;
}


// Function definitions
double CalcRectanglePerimeter(double rectHeight, double rectWidth){
    double rectPerimeter;
    rectPerimeter = (2 * rectHeight) + (2 * rectWidth); // Doubles the dimensions but keeps the ratio the same

    return rectPerimeter;
}

void PrintRectanglePerimeter(double rectHeight, double rectWidth){
    cout << fixed << setprecision(1);
    cout << "A rectangle with height " << rectHeight << " and width " << rectWidth << " has a perimeter of " << CalcRectanglePerimeter(rectHeight, rectWidth) << "." << endl;
}

void DoubleRectanglePerimeter(double& rectHeight, double& rectWidth){
    rectHeight = rectHeight * 2;
    rectWidth = rectWidth * 2;
}

double CalcCircumferenceOfCircle(double circleRadius){
    double circleCircumference = 0.0;
    circleCircumference = 2 * PI * circleRadius;

    return circleCircumference;
}

double CalcAreaOfCircle(double circleRadius){
    double circleArea = 0.0;
    circleArea = PI * (circleRadius * circleRadius);

    return circleArea;
}

double CalcVolumeOfSphere(double circleRadius){
    double sphereVolume = 0.0;
    sphereVolume = (4.0 / 3.0) * PI * (circleRadius * circleRadius * circleRadius);

    return sphereVolume;
}

void Swap(int& firstValue, int& secondValue){
    int tempValue = 0;
    // Store the first parameter in a temporary variable so that it doesn't get lost in the reassignment
    tempValue = firstValue;
    firstValue = secondValue;
    secondValue = tempValue;
}

void Swap(double& firstValue, double& secondValue){
    double tempValue = 0.0;
    // Store the first parameter in a temporary variable so that it doesn't get lost in the reassignment
    tempValue = firstValue;
    firstValue = secondValue;
    secondValue = tempValue;
}