#include "premium_ride.h"
#include <string>

PremiumRide::PremiumRide(std::string rideID, std::string pickup,
                         std::string dropoff, double distance)
    : Ride(rideID, pickup, dropoff, distance), ratePerMile(3.5), baseFare(10.0),
      premiumFee(8.0), serviceFee(4.0), minimumFare(18.0), maxPassengers(4),
      vehicleType("Premium"), luxuryVehicle(true), priorityPickup(true) {}

double PremiumRide::calculateFare() {
  this->fare = this->baseFare + (this->distance * this->ratePerMile) +
               this->premiumFee + this->serviceFee;

  if (this->fare < this->minimumFare) {
    this->fare = this->minimumFare;
  }

  return this->fare;
}

std::string PremiumRide::rideDetails() {
  return "Premium Ride " + this->rideID + " from " + this->pickupLocation +
         " to " + this->dropoffLocation + " - Status: " + this->status;
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
