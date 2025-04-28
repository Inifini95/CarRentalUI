#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Car.h"
#include <unordered_map>
#include "Customer.h"
using namespace std;

class rentalService {
private:

	static int numOfRentals;

public:
	static unordered_map<string, Car*> rentedCars;
	static unordered_map<string, vector<Car*>> availableCars;
	static unordered_map<string, vector<Car*>> customers;
	static unordered_map<string, Customer*> customerDetails;

	static void listAllCars();

	Car* rentACar(string carModel, string dlNumber, string date, string customerName);

	void returnACar(string carModel, string LicensePlate, string date);

	void addCar(string carModel, string LicensePlate, string date, int year, string color, string company);

	Car* searchCar(string carModel, string LicensePlate = "");

	Customer* searchCustomer(string dlNumber);


};