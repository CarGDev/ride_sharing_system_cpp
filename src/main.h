#pragma once

#include "person/driver.h"
#include "person/rider.h"
#include "rides/premium_ride.h"
#include "rides/standard_ride.h"
#include <string>
#include <vector>

class RideSharingSystem {
protected:
  Driver drivers;
  Rider riders;
  PremiumRide premium_ride;
  StandardRide standard_ride;

public:
  void addDriver();
  void addRider();
  void addRide();
  void assignDriver();
  void processRides();
  Driver findAvailableDriver();
  std::vector<Ride> getAllRiders();
};
