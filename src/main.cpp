#include "rides/premium_ride.h"
#include "rides/standard_ride.h"
#include "sharing_system.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  RideSharingSystem system;

  Driver driver1;
  Driver driver2;
  Driver driver3;

  Rider standardRider1;
  Rider standardRider2;
  Rider standardRider3;
  Rider premiumRider1;
  Rider premiumRider2;

  driver1.setFullName("Hall", "Coode");
  driver1.setEmail("hcoode0@nationalgeographic.com");
  driver1.setId("D001");
  driver1.setRating(4.8);

  driver2.setFullName("Izabel", "Balding");
  driver2.setEmail("ibalding1@mysql.com");
  driver2.setId("D002");
  driver2.setRating(4.9);

  driver3.setFullName("Elden", "McQuillen");
  driver3.setEmail("emcquillen2@psu.edu");
  driver3.setId("D003");
  driver3.setRating(4.7);

  standardRider1.setFullName("Bertha", "Byrd");
  standardRider1.setEmail("bbyrd3@eventbrite.com");
  standardRider1.setId("R001");

  standardRider2.setFullName("Blakeley", "Kalinsky");
  standardRider2.setEmail("bkalinsky4@foxnews.com");
  standardRider2.setId("R002");

  standardRider3.setFullName("Reynolds", "Stubbin");
  standardRider3.setEmail("rstubbin5@addthis.com");
  standardRider3.setId("R003");

  premiumRider1.setFullName("Christel", "Chipchase");
  premiumRider1.setEmail("cchipchase6@blogger.com");
  premiumRider1.setId("R004");

  premiumRider2.setFullName("Gillan", "Auger");
  premiumRider2.setEmail("gauger7@japanpost.jp");
  premiumRider2.setId("R005");

  Vehicle standardVehicle("V001", "Chevrolet", "Impala", 2020, "White",
                          "STD-001", 4, "Standard");
  Vehicle premiumVehicle1("V002", "Aston Martin", "DBS", 2023, "Black",
                          "PRE-001", 4, "Premium");
  Vehicle premiumVehicle2("V003", "Infiniti", "QX56", 2022, "Blue", "PRE-002",
                          4, "Premium");

  system.addDriver(driver1);
  system.addDriver(driver2);
  system.addDriver(driver3);

  system.addRider(standardRider1);
  system.addRider(standardRider2);
  system.addRider(standardRider3);
  system.addRider(premiumRider1);
  system.addRider(premiumRider2);

  system.addVehicle(standardVehicle);
  system.addVehicle(premiumVehicle1);
  system.addVehicle(premiumVehicle2);

  StandardRide ride1("R001", "Campus", "Downtown", 5.0, 12);
  PremiumRide ride2("R002", "Airport", "Hotel", 10.0, 25);
  StandardRide ride3("R003", "Library", "Mall", 3.5, 8);
  PremiumRide ride4("R004", "Station", "Museum", 8.0, 18);
  PremiumRide ride5("R005", "Hospital", "Campus", 6.2, 15);
  PremiumRide ride6("R006", "Downtown", "Airport", 12.0, 28);
  StandardRide ride7("R007", "Park", "Theater", 4.7, 10);
  PremiumRide ride8("R008", "Hotel", "Restaurant", 2.8, 7);
  StandardRide ride9("R009", "Gym", "Home", 7.1, 16);
  PremiumRide ride10("R010", "Office", "Stadium", 9.4, 20);

  std::vector<Ride *> rides = {&ride1, &ride2, &ride3, &ride4, &ride5,
                               &ride6, &ride7, &ride8, &ride9, &ride10};

  std::vector<Rider *> requestRiders = {
      &standardRider1, &premiumRider1, &standardRider2, &premiumRider2,
      &premiumRider1,  &premiumRider2, &standardRider3, &premiumRider1,
      &standardRider1, &premiumRider2};
  std::vector<std::string> requestRiderLabels = {
      "Bertha Byrd",      "Christel Chipchase", "Blakeley Kalinsky",
      "Gillan Auger",     "Christel Chipchase", "Gillan Auger",
      "Reynolds Stubbin", "Christel Chipchase", "Bertha Byrd",
      "Gillan Auger"};
  std::vector<std::string> riderTypes = {
      "Standard", "Premium",  "Standard", "Premium",  "Premium",
      "Premium",  "Standard", "Premium",  "Standard", "Premium"};
  std::vector<std::string> rideTypes = {
      "Standard", "Premium",  "Standard", "Premium",  "Premium",
      "Premium",  "Standard", "Premium",  "Standard", "Premium"};

  std::vector<Driver *> activeDrivers;
  std::vector<Vehicle *> activeVehicles;
  std::vector<Ride *> activeRides;
  std::vector<std::string> activeRideTypes;

  std::cout << "Ride Sharing System Simulation" << std::endl;
  std::cout << "Drivers: 3 | Riders: 5 (3 standard, 2 premium) | Vehicles: 3 "
               "(1 standard, 2 premium) | Ride requests: 10"
            << std::endl
            << std::endl;

  for (int i = 0; i < static_cast<int>(rides.size()); i++) {
    Ride *ride = rides[i];
    Rider *rider = requestRiders[i];
    std::string riderType = riderTypes[i];
    std::string rideType = rideTypes[i];

    if (i >= 4) {
      int rideToComplete = -1;

      for (int j = 0; j < static_cast<int>(activeRides.size()); j++) {
        if (activeRides[j] != nullptr && activeRideTypes[j] == rideType) {
          rideToComplete = j;
          break;
        }
      }

      if (i == 4) {
        for (int j = 0; j < static_cast<int>(activeRides.size()); j++) {
          if (activeRides[j] != nullptr &&
              activeRides[j]->getRideID() == "R002") {
            rideToComplete = j;
            break;
          }
        }
      }

      if (rideToComplete != -1) {
        activeRides[rideToComplete]->setStatus("completed");
        activeDrivers[rideToComplete]->setAvailable(true);
        activeVehicles[rideToComplete]->setAvailable(true);

        std::cout << "Completed " << activeRides[rideToComplete]->getRideID()
                  << "; driver and " << activeRideTypes[rideToComplete]
                  << " vehicle are available again." << std::endl;

        activeRides[rideToComplete] = nullptr;
      }
    }

    Driver *driver = system.findAvailableDriver();
    Vehicle *vehicle = system.findAvailableVehicle(rideType);

    std::cout << "Request " << i + 1 << " by " << requestRiderLabels[i]
              << " for a " << rideType << " ride: " << ride->getRideID()
              << std::endl;

    if (driver != nullptr && vehicle != nullptr) {
      driver->addRide(i + 1);
      driver->setAvailable(false);
      vehicle->setDriver(*driver);
      vehicle->setAvailable(false);
      ride->setStatus("assigned");
      ride->calculateFare();
      rider->requestRide(i + 1, driver->getDriverInfo());
      system.addRide(ride);
      activeDrivers.push_back(driver);
      activeVehicles.push_back(vehicle);
      activeRides.push_back(ride);
      activeRideTypes.push_back(rideType);

      std::cout << "Assigned" << std::endl;
      std::cout << "Driver: " << driver->getFullName() << std::endl;
      std::cout << "Vehicle: " << vehicle->getVehicleInfo() << std::endl;
      std::cout << ride->rideDetails() << std::endl;
      std::cout << "Fare: $" << ride->getFare() << std::endl;
    } else {
      ride->setStatus("unassigned");
      rider->cancelRide(i + 1);

      std::cout << "No available driver or " << rideType << " vehicle for "
                << ride->getRideID() << std::endl;
    }

    std::cout << std::endl;
  }

  system.processRides();

  return 0;
}
