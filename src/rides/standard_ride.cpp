#include "standard_ride.h"
#include <string>

StandardRide::StandardRide(std::string rideID, std::string pickup,
                           std::string dropoff, double distance)
    : Ride(rideID, pickup, dropoff, distance), ratePerMile(2.0), baseFare(5.0),
      minimumFare(8.0), bookingFee(2.0), maxPassengers(4),
      vehicleType("Standard") {}

double StandardRide::calculateFare() {
  this->fare =
      this->baseFare + (this->distance * this->ratePerMile) + this->bookingFee;

  if (this->fare < this->minimumFare) {
    this->fare = this->minimumFare;
  }

  return this->fare;
}

std::string StandardRide::rideDetails() {
  return "Standard Ride " + this->rideID + " from " + this->pickupLocation +
         " to " + this->dropoffLocation + " - Status: " + this->status;
}

double StandardRide::getRatePerMile() { return this->ratePerMile; }

double StandardRide::getBaseFare() { return this->baseFare; }

double StandardRide::getMinimumFare() { return this->minimumFare; }

double StandardRide::getBookingFee() { return this->bookingFee; }

int StandardRide::getMaxPassengers() { return this->maxPassengers; }

std::string StandardRide::getVehicleType() { return this->vehicleType; }
