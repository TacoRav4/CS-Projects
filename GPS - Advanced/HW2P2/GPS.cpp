#include "GPS.h"
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:::Original code from class has been tweaked for a better fitment::*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

GPS_DD::GPS_DD() : latitude(0.0), longitude(0.0) {}

GPS_DD::GPS_DD(double lat, double lon) : latitude(lat), longitude(lon) {}

double GPS_DD::getLatitude() {
    return latitude;
}

double GPS_DD::getLongitude() {
    return longitude;
}

static double deg2rad(double deg) {
    return (deg * M_PI / 180.0);
}

static double rad2deg(double rad) {
    return (rad * 180.0 / M_PI);
}

// Calculates the distance between two GPS coordinates using the Haversine formula
static double GeoDataSource_distance(double lat1, double lon1, double lat2, double lon2, char unit) {
    double theta = lon1 - lon2;
    double dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist *= 60 * 1.1515;
    if (unit == 'K') dist *= 1.609344;
    if (unit == 'N') dist *= 0.8684;
    return dist;
}

void GPS_DD::xyz() {
    printf("Hello World\n");
}

double GPS_DD::distance(GPS_DD another) {
    return GeoDataSource_distance(latitude, longitude, another.latitude, another.longitude, 'M');
}

double GPS_DD::operator-(GPS_DD another) {
    return GeoDataSource_distance(latitude, longitude, another.getLatitude(), another.getLongitude(), 'M');
}

double GPS_DD::operator-(int x) {
    return 9.2;  // placeholder
}

// Print out the latitude and longitude
void GPS_DD::dump() {
    cout << "[GPS_DD] dump-begin" << endl;
    cout << "latitude       = " << latitude << endl;
    cout << "longitude      = " << longitude << endl;
    cout << "[GPS_DD] dump-end" << endl;
}