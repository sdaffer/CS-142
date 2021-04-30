#include <iostream>
#include <iomanip>
using namespace std;

//Write your functions here
double CalcRectanglePerimeter(double rectHeight, double rectWidth){
    double rectPerimeter;

    rectPerimeter = (2 * rectHeight) + (2 * rectWidth);

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

int main() {

    /*
      You are free to write code here to test your functions, but you are not required to do so.
      Our unit tests utilize their own main() function and are able to ignore this one...
    */

    return 0;
}