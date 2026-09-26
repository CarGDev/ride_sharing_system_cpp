#pragma once

#include "rides.h"
#include <string>

class PremiumRide : public Ride {
private:
  double ratePerMile;
  double baseFare;
  double premiumFee;
  double serviceFee;
  double minimumFare;
  int maxPassengers;
  std::string vehicleType;
  bool luxuryVehicle;
  bool priorityPickup;

public:
  PremiumRide(std::string rideID, std::string pickup, std::string dropoff,
              double distance, int durationMinutes);

  double calculateFare() override;
  std::string rideDetails() override;

  double getRatePerMile();
  double getBaseFare();
  double getPremiumFee();
  double getServiceFee();
  double getMinimumFare();
  int getMaxPassengers();
  std::string getVehicleType();
  bool hasLuxuryVehicle();
  bool hasPriorityPickup();
};
