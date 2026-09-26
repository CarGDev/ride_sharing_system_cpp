#pragma once

#include "person/driver.h"
#include "person/rider.h"
#include "rides/rides.h"
#include "vehicle.h"
#include <vector>

class RideSharingSystem {
private:
  std::vector<Driver> drivers;
  std::vector<Rider> riders;
  std::vector<Vehicle> vehicles;
  std::vector<Ride *> rides;

public:
  void addDriver(Driver driver);
  void addRider(Rider rider);
  void addVehicle(Vehicle vehicle);
  void addRide(Ride *ride);

  Driver *findAvailableDriver();
  Vehicle *findAvailableVehicle();

  std::vector<Driver> getDrivers();
  std::vector<Rider> getRiders();
  std::vector<Vehicle> getVehicles();
  std::vector<Ride *> getRides();

  void processRides();
};
