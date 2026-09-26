#pragma once

#include <string>

class Ride {
protected:
  std::string rideID;
  std::string pickupLocation;
  std::string dropoffLocation;
  double distance;
  double fare;
  int durationMinutes;
  std::string status;

  Ride(std::string rideID, std::string pickup, std::string dropoff,
       double distance);

public:
  virtual ~Ride() = default;

  virtual double calculateFare() = 0;
  virtual std::string rideDetails() = 0;

  std::string getRideID();
  double getDistance();
  double getFare();
  std::string getStatus();
  void setStatus(std::string status);
};
