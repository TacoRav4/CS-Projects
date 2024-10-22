#include "GPS.h"
#include <iostream>
#include <sstream>

// Main Function
int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <latitude-1> <longitude-1> <latitude-2> <longitude-2>" << std::endl;
        return 1;
    }

    double lat1 = std::stod(argv[1]);
    double lon1 = std::stod(argv[2]);
    double lat2 = std::stod(argv[3]);
    double lon2 = std::stod(argv[4]);

    GPS_DD point1(lat1, lon1);
    GPS_DD point2(lat2, lon2);

    double distance = point1.distance(point2);

    std::cout << "{\"distance\": " << distance << "}" << std::endl;

    return 0;
}






