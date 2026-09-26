#include "driver.h"
#include <string>

Driver::Driver() : rating(0.0), available(true), current_ride_id(-1) {}

std::string Driver::getFullName() { return Persona::getFullName(); }

void Driver::addRide(int id_ride) {
  this->current_ride_id = id_ride;
  this->available = false;
}

DriverData Driver::getDriverInfo() {
  return {name, last_name, id, email, phone, rating, available};
}

void Driver::closeRide(int id) {
  assigned_rides.push_back(id);
  this->available = true;
  this->current_ride_id = -1;
}

int Driver::getCurrentRideId() { return this->current_ride_id; }

void Driver::setCurrentRideId(int current_ride_id) {
  this->current_ride_id = current_ride_id;
}

double Driver::getRating() { return this->rating; }

void Driver::setRating(double rating) { this->rating = rating; }

bool Driver::isAvailable() { return this->available; }

void Driver::setAvailable(bool available) { this->available = available; }
