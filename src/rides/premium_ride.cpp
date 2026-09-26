#include "premium_ride.h"
#include <string>

PremiumRide::PremiumRide(std::string rideID, std::string pickup,
                         std::string dropoff, double distance,
                         int durationMinutes)
    : Ride(rideID, pickup, dropoff, distance, durationMinutes),
      ratePerMile(1.0), baseFare(0.0), premiumFee(0.0), serviceFee(0.0),
      minimumFare(0.0), maxPassengers(4), vehicleType("Premium"),
      luxuryVehicle(true), priorityPickup(true) {}

double PremiumRide::calculateFare() {
  this->fare = (this->distance + this->durationMinutes) * this->ratePerMile;
  return this->fare;
}

std::string PremiumRide::rideDetails() {
  return "Premium Ride " + this->rideID + " from " + this->pickupLocation +
         " to " + this->dropoffLocation + " - Miles: " +
         std::to_string(this->distance) + " - Minutes: " +
         std::to_string(this->durationMinutes) + " - Status: " + this->status;
}

double PremiumRide::getRatePerMile() { return this->ratePerMile; }

double PremiumRide::getBaseFare() { return this->baseFare; }

double PremiumRide::getPremiumFee() { return this->premiumFee; }

double PremiumRide::getServiceFee() { return this->serviceFee; }

double PremiumRide::getMinimumFare() { return this->minimumFare; }

int PremiumRide::getMaxPassengers() { return this->maxPassengers; }

std::string PremiumRide::getVehicleType() { return this->vehicleType; }

bool PremiumRide::hasLuxuryVehicle() { return this->luxuryVehicle; }

bool PremiumRide::hasPriorityPickup() { return this->priorityPickup; }
