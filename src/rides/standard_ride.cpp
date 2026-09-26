#include "standard_ride.h"
#include <string>

StandardRide::StandardRide(std::string rideID, std::string pickup,
                           std::string dropoff, double distance,
                           int durationMinutes)
    : Ride(rideID, pickup, dropoff, distance, durationMinutes),
      ratePerMile(1.5), baseFare(0.0), minimumFare(0.0), bookingFee(0.0),
      maxPassengers(4),
      vehicleType("Standard") {}

double StandardRide::calculateFare() {
  this->fare = (this->distance + this->durationMinutes) * this->ratePerMile;
  return this->fare;
}

std::string StandardRide::rideDetails() {
  return "Standard Ride " + this->rideID + " from " + this->pickupLocation +
         " to " + this->dropoffLocation + " - Miles: " +
         std::to_string(this->distance) + " - Minutes: " +
         std::to_string(this->durationMinutes) + " - Status: " + this->status;
}

double StandardRide::getRatePerMile() { return this->ratePerMile; }

double StandardRide::getBaseFare() { return this->baseFare; }

double StandardRide::getMinimumFare() { return this->minimumFare; }

double StandardRide::getBookingFee() { return this->bookingFee; }

int StandardRide::getMaxPassengers() { return this->maxPassengers; }

std::string StandardRide::getVehicleType() { return this->vehicleType; }
