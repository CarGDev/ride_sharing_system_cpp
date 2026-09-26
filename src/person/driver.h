#pragma once
#include "persona.h"
#include <string>
#include <vector>

struct DriverData {
  std::string name, last_name, id, email, phone;
  double rating;
  bool available;
};

class Driver : public Persona {
private:
  double rating;
  std::vector<int> assigned_rides;
  bool available;
  int current_ride_id;

public:
  Driver();

  std::string getFullName() override;
  void addRide(int id_ride);
  DriverData getDriverInfo();
  void closeRide(int id);
  int getCurrentRideId();
  void setCurrentRideId(int current_ride_id);
  double getRating();
  void setRating(double rating);
  bool isAvailable();
  void setAvailable(bool available);
};
