#include "sharing_system.h"

void RideSharingSystem::addDriver(Driver driver) {
  this->drivers.push_back(driver);
}

void RideSharingSystem::addRider(Rider rider) { this->riders.push_back(rider); }

void RideSharingSystem::addVehicle(Vehicle vehicle) {
  this->vehicles.push_back(vehicle);
}

void RideSharingSystem::addRide(Ride *ride) { this->rides.push_back(ride); }

Driver *RideSharingSystem::findAvailableDriver() {
  for (Driver &driver : this->drivers) {
    if (driver.isAvailable()) {
      return &driver;
    }
  }

  return nullptr;
}

Vehicle *RideSharingSystem::findAvailableVehicle() {
  for (Vehicle &vehicle : this->vehicles) {
    if (vehicle.isAvailable()) {
      return &vehicle;
    }
  }

  return nullptr;
}

Vehicle *RideSharingSystem::findAvailableVehicle(std::string vehicleType) {
  for (Vehicle &vehicle : this->vehicles) {
    if (vehicle.isAvailable() && vehicle.getVehicleType() == vehicleType) {
      return &vehicle;
    }
  }

  return nullptr;
}

std::vector<Driver> RideSharingSystem::getDrivers() { return this->drivers; }

std::vector<Rider> RideSharingSystem::getRiders() { return this->riders; }

std::vector<Vehicle> RideSharingSystem::getVehicles() { return this->vehicles; }

std::vector<Ride *> RideSharingSystem::getRides() { return this->rides; }

void RideSharingSystem::processRides() {
  for (Ride *ride : this->rides) {
    if (ride != nullptr) {
      ride->calculateFare();
    }
  }
}
