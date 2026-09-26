#pragma once

#include "person/driver.h"
#include <string>

class Vehicle {
private:
  std::string vehicleID;
  std::string make;
  std::string model;
  int year;
  std::string color;
  std::string licensePlate;
  int capacity;
  std::string vehicleType;
  bool available;
  Driver driver;

public:
  Vehicle();
  Vehicle(std::string vehicleID, std::string make, std::string model, int year,
          std::string color, std::string licensePlate, int capacity,
          std::string vehicleType);

  std::string getVehicleID();
  std::string getVehicleInfo();
  std::string getVehicleType();
  int getCapacity();
  void setDriver(Driver driver);
  Driver getDriver();
  bool isAvailable();
  void setAvailable(bool available);
};
