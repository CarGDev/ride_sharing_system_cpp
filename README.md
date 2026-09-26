# Ride Sharing System

The Ride Sharing System must include the following components at a minimum. You should add additional functionality and feel free to be creative.

1. Ride Class:
Create a base class Ride that holds core details such as rideID, pickupLocation, dropoffLocation, distance, and fare.
Define methods for calculating the fare() based on distance and a rideDetails() method to display ride information.
2. Specific Ride Subclasses:
Implement at least two derived classes of Ride, such as StandardRide and PremiumRide.
Each subclass should override the fare() method to calculate the fare based on ride type (e.g., premium rides might cost more per mile).
Demonstrate polymorphism by calling the overridden fare() method on a list of different ride types.
3. Driver Class:
Create a Driver class with attributes like driverID, name, rating, and assignedRides, a list of rides completed by the driver.
Include methods such as addRide(Ride ride) to add rides to the driver’s list and getDriverInfo() to display driver details.
Use encapsulation to keep assignedRides private and accessible only through defined methods.
4. Rider Class:
Create a Rider class with attributes like riderID, name, and requestedRides, a list of rides requested by the rider.
Include methods such as requestRide(Ride ride) to add a ride to the rider’s requested list, and viewRides() to display ride history.
5. System Functionality
Demonstrate polymorphism by storing rides of different types in a list (array or collection) and invoking fare() and rideDe- tails() polymorphically.

## Class Diagram

```mermaid
classDiagram

    class Person {
        <<abstract>>
        #String name
        #String last_name
        #String id
        #String email
        #String phone
        +getFullName() String
        +getId() String
        +getData() List~String~
        +setName(String name) void
        +setLastName(String last_name) void
        +setId(String id) void
        +setEmail(String email) void
        +setPhone(String phone) void
    }

    class Driver {
        -double rating
        -boolean available
        -List~Ride~ assignedRides
        +addRide(Ride ride) void
        +completeRide(Ride ride) void
        +getDriverInfo() String
        +getAssignedRides() List~Ride~
        +getRating() double
        +setRating(double rating) void
        +isAvailable() boolean
        +setAvailable(boolean available) void
    }

    class Rider {
        -List~Ride~ requestedRides
        +requestRide(Ride ride) void
        +cancelRide(Ride ride) void
        +viewRides() List~Ride~
        +getRiderInfo() String
    }

    class Vehicle {
        -String vehicleID
        -String make
        -String model
        -int year
        -String color
        -String licensePlate
        -int capacity
        -String vehicleType
        -boolean available
        +getVehicleID() String
        +getVehicleInfo() String
        +getVehicleType() String
        +getCapacity() int
        +isAvailable() boolean
        +setAvailable(boolean available) void
    }

    class Ride {
        <<abstract>>
        #String rideID
        #String pickupLocation
        #String dropoffLocation
        #double distance
        #double fare
        #int durationMinutes
        #String status
        +calculateFare() double
        +rideDetails() String
        +getRideID() String
        +getFare() double
        +getStatus() String
        +setStatus(String status) void
    }

    class StandardRide {
        -double ratePerMile
        -double baseFare
        -double minimumFare
        -double bookingFee
        -int maxPassengers
        +calculateFare() double
        +rideDetails() String
    }

    class PremiumRide {
        -double ratePerMile
        -double baseFare
        -double minimumFare
        -double premiumFee
        -double serviceFee
        -int maxPassengers
        -boolean priorityPickup
        +calculateFare() double
        +rideDetails() String
    }

    class RideSharingSystem {
        -String systemName
        -List~Rider~ riders
        -List~Driver~ drivers
        -List~Vehicle~ vehicles
        -List~Ride~ rides

        +addRider(Rider rider) void
        +addDriver(Driver driver) void
        +addVehicle(Vehicle vehicle) void
        +addRide(Ride ride) void

        +removeRider(String riderID) void
        +removeDriver(String driverID) void
        +removeVehicle(String vehicleID) void

        +findRider(String riderID) Rider
        +findDriver(String driverID) Driver
        +findVehicle(String vehicleID) Vehicle
        +findRide(String rideID) Ride

        +getRiders() List~Rider~
        +getDrivers() List~Driver~
        +getVehicles() List~Vehicle~
        +getRides() List~Ride~

        +findAvailableDriver() Driver
        +findAvailableVehicle() Vehicle
        +assignDriver(Ride ride, Driver driver) void
        +assignVehicle(Driver driver, Vehicle vehicle) void
        +processRides() void
    }

    %% Inheritance
    Person <|-- Driver
    Person <|-- Rider

    Ride <|-- StandardRide
    Ride <|-- PremiumRide

    %% Driver/Rider relationships
    Driver "1" --> "0..*" Ride : completes
    Rider "1" --> "0..*" Ride : requests
    Driver "0..1" --> "0..1" Vehicle : drives

    %% System stores/manages objects
    RideSharingSystem "1" o-- "0..*" Rider : manages
    RideSharingSystem "1" o-- "0..*" Driver : manages
    RideSharingSystem "1" o-- "0..*" Vehicle : manages
    RideSharingSystem "1" o-- "0..*" Ride : manages

```
