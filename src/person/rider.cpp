#include "rider.h"
#include <string>

Rider::Rider() : current_ride_id(-1), on_ride(false), current_driver{} {}

std::string Rider::getFullName() { return Persona::getFullName(); }

void Rider::requestRide(int id, DriverData driver) {
  this->on_ride = true;
  this->current_ride_id = id;
  this->current_driver = driver;
}

void Rider::endRide(int id) {
  this->on_ride = false;
  this->current_ride_id = -1;
  this->ride_requested.push_back(id);
  this->current_driver = DriverData{};
}

void Rider::cancelRide(int id) {
  this->cancel_ride_requested.push_back(id);
  this->current_ride_id = -1;
  this->on_ride = false;
  this->current_driver = DriverData{};
}

DriverData Rider::getDriverData() { return this->current_driver; }

RideRequestsView Rider::viewRides() {
  return {this->ride_requested, this->cancel_ride_requested};
}

RiderData Rider::getRiderInfo() {
  return {name, last_name, id, email, phone, current_ride_id, on_ride};
}
