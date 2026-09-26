#pragma once

#include "rides.h"
#include <string>

class StandardRide : public Ride {
private:
  double ratePerMile;
  double baseFare;
  double minimumFare;
  double bookingFee;
  int maxPassengers;
  std::string vehicleType;

public:
  StandardRide(std::string rideID, std::string pickup, std::string dropoff,
               double distance);

  double calculateFare() override;
  std::string rideDetails() override;

  double getRatePerMile();
  double getBaseFare();
  double getMinimumFare();
  double getBookingFee();
  int getMaxPassengers();
  std::string getVehicleType();
};
