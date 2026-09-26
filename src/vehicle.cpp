#include "vehicle.h"
#include <string>

Vehicle::Vehicle()
    : vehicleID(""), make(""), model(""), year(0), color(""), licensePlate(""),
      capacity(0), vehicleType(""), available(true), driver{} {}

Vehicle::Vehicle(std::string vehicleID, std::string make, std::string model,
                 int year, std::string color, std::string licensePlate,
                 int capacity, std::string vehicleType)
    : vehicleID(vehicleID), make(make), model(model), year(year), color(color),
      licensePlate(licensePlate), capacity(capacity), vehicleType(vehicleType),
      available(true), driver{} {}

std::string Vehicle::getVehicleID() { return this->vehicleID; }

std::string Vehicle::getVehicleInfo() {
  return this->vehicleID + " - " + this->make + " " + this->model + " (" +
         std::to_string(this->year) + ") " + this->color + " - " +
         this->licensePlate;
}

std::string Vehicle::getVehicleType() { return this->vehicleType; }

int Vehicle::getCapacity() { return this->capacity; }

void Vehicle::setDriver(Driver driver) { this->driver = driver; }
Driver Vehicle::getDriver() { return this->driver; }

bool Vehicle::isAvailable() { return this->available; }

void Vehicle::setAvailable(bool available) { this->available = available; }
