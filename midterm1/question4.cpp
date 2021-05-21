#include <iostream>
using namespace std;

int main() {
    // Constants
    const float WEST_LONG_BOUNDARY = 114.0;
    const float EAST_LONG_BOUNDARY = 102.0;
    const float MIDDLE_LAT_BOUNDARY = 37.0;
    const float MIDDLE_LONG_BOUNDARY = 109.0;
    const float NORTH_LAT_BOUNDARY = 41.0;
    const float SOUTH_LAT_BOUNDARY = 31.0;

    // Variables
    float userLatitude = 0.0;
    float userLongitude = 0.0;
    string coordinatePosition = "";

    // Get user input
    cout << "Please enter the latitude of the position: ";
    cin >> userLatitude;
    cout << "Please enter the longitude of the position: ";
    cin >> userLongitude;

    // Determine the location
    // Are we inside the boundary in the north-south and east-west directions?
    if ((((userLatitude < NORTH_LAT_BOUNDARY) && (userLatitude > SOUTH_LAT_BOUNDARY))) && ((userLongitude < WEST_LONG_BOUNDARY) && (userLongitude > EAST_LONG_BOUNDARY))) {
        // Utah condition
        if (((userLatitude > MIDDLE_LAT_BOUNDARY) && (userLatitude < NORTH_LAT_BOUNDARY)) && ((userLongitude > MIDDLE_LONG_BOUNDARY) && (userLongitude < WEST_LONG_BOUNDARY))) {
            coordinatePosition = "Utah";
        }
        // Colorado condition
        else if (((userLatitude > MIDDLE_LAT_BOUNDARY) && (userLatitude < NORTH_LAT_BOUNDARY )) && ((userLongitude < MIDDLE_LONG_BOUNDARY) && (userLongitude > EAST_LONG_BOUNDARY))) {
            coordinatePosition = "Colorado";
        }
        // Arizona condition
        else if (((userLatitude < MIDDLE_LAT_BOUNDARY) && (userLatitude > SOUTH_LAT_BOUNDARY)) && ((userLongitude > MIDDLE_LONG_BOUNDARY) && (userLongitude < WEST_LONG_BOUNDARY))) {
            coordinatePosition = "Arizona";
        }
        // New Mexico condition
        else if (((userLatitude < MIDDLE_LAT_BOUNDARY) && (userLatitude > SOUTH_LAT_BOUNDARY)) && ((userLongitude < MIDDLE_LONG_BOUNDARY) && (userLongitude > EAST_LONG_BOUNDARY))) {
            coordinatePosition = "New Mexico";
        }
        // Else we must be exactly on a boundary
        else {
            coordinatePosition  = "nowhere exactly";
        }

    }
    // If false, then we are outside of the four states, and need to check where - north-south direction first
    else {
        // Check north-south
        if (userLatitude > NORTH_LAT_BOUNDARY || userLatitude < SOUTH_LAT_BOUNDARY) {
            if (userLatitude > NORTH_LAT_BOUNDARY) {
                coordinatePosition = "the Northern Area";
            }
            if (userLatitude < SOUTH_LAT_BOUNDARY) {
                coordinatePosition = "the Southern Area";
            }
        }
        // Else we must be in north-south but outside east-west
        else {
            if (userLongitude > WEST_LONG_BOUNDARY) {
                coordinatePosition = "the Western Area";
            }
            if (userLongitude < EAST_LONG_BOUNDARY) {
                coordinatePosition = "the Eastern Area";
            }
        }
    }

    // Output position
    cout << "The position is found in " << coordinatePosition << endl;

    return 0;
}