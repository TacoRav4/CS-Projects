#ifndef GPS_H_
#define GPS_H_

#include <iostream>
#include <iomanip>
#include <json/json.h>

class GPS_DD {
 private:
  double longitude;
  double latitude;

 public:
  GPS_DD();
  GPS_DD(double longitude, double latitude);

  double getLatitude();
  double getLongitude();
  double distance(GPS_DD other);
  void xyz();
  double operator-(GPS_DD other);
  double operator-(int x);
  void dump();
};

#endif  // GPS_H_