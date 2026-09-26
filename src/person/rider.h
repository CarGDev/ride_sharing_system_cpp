#pragma once
#include "driver.h"
#include <string>
#include <vector>

struct RiderData {
  std::string name, last_name, id, email, phone;
  int current_ride_id;
  bool on_ride;
};

struct RideRequestsView {
  std::vector<int> requested;
  std::vector<int> cancelled;
};

class Rider : public Persona {
private:
  std::vector<int> ride_requested;
  std::vector<int> cancel_ride_requested;
  int current_ride_id;
  bool on_ride;
  DriverData current_driver;

public:
  Rider();

  std::string getFullName() override;
  void requestRide(int id, DriverData driver);
  void endRide(int id);
  void cancelRide(int id);
  DriverData getDriverData();
  RideRequestsView viewRides();
  RiderData getRiderInfo();
};
