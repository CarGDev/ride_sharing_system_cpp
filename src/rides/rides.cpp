#include "rides.h"

Ride::Ride(std::string rideID, std::string pickup, std::string dropoff,
           double distance, int durationMinutes)
    : rideID(rideID), pickupLocation(pickup), dropoffLocation(dropoff),
      distance(distance), fare(0.0), durationMinutes(durationMinutes),
      status("requested") {}

std::string Ride::getRideID() { return this->rideID; }

double Ride::getDistance() { return this->distance; }

int Ride::getDurationMinutes() { return this->durationMinutes; }

double Ride::getFare() { return this->fare; }

std::string Ride::getStatus() { return this->status; }

void Ride::setStatus(std::string status) { this->status = status; }
