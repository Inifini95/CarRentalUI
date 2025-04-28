#pragma once	
#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
#include "rentalService.h"
#include "Car.h"
#include "Customer.h"
using namespace std;

int rentalService::numOfRentals = 0;
unordered_map<string, Car*> rentalService::rentedCars;
unordered_map<string, vector<Car*>> rentalService::availableCars;
unordered_map<string, vector<Car*>> rentalService::customers;
unordered_map<string, Customer*> rentalService::customerDetails;

void rentalService::listAllCars() {
	for (auto& car : availableCars) {
		cout << "Car Model: " << car.first << endl;
		if (car.second.empty()) {
			cout << "No cars available" << endl;
			continue;
		}
		for (auto& c : car.second) {
			cout << "License Plate: " << c->getLicensePlate() << endl;
		}
	}
}
void rentalService::addCar(string carModel, string LicensePlate, string date, int year, string color, string company) {
	Car* newCar = new Car(year, carModel, color, company);
	newCar->setLicensePlate(LicensePlate);
	if (availableCars.find(carModel) == availableCars.end()) {
		availableCars.insert({ carModel, { newCar } });
	}
	else {
		availableCars[carModel].push_back(newCar);
	}
}

Car* rentalService::rentACar(string carModel, string dlNumber, string date, string customerName) {
	Car* car = searchCar(carModel, "");
	if (car == nullptr) {
		return nullptr;
	}
	availableCars[carModel].pop_back();
	if (rentedCars.find(car->getLicensePlate()) != rentedCars.end()) {
		cout << "Car already rented" << endl;
		return nullptr;
	}
	rentedCars.insert({ car->getLicensePlate(), car });
	Customer* customer = new Customer("cust1", "100", "cust1@gmail.com", "dl1");
	customerDetails[dlNumber] = customer;
	customer->rentCar(carModel, car->getLicensePlate(), date);
	if (customers.find(dlNumber) == customers.end()) {
		customers[dlNumber] = { car };
	}
	else {
		customers[dlNumber].push_back(car);
	}
	numOfRentals++;
	return car;

}
void rentalService::returnACar(string carModel, string LicensePlate, string date) {
	Car* car = rentedCars[LicensePlate];
	if (car == nullptr) {
		cout << "Car not found in rented repo" << endl;
		return;
	}
	availableCars[carModel].push_back(car);
	rentedCars.erase(LicensePlate);

}
Car* rentalService::searchCar(string carModel, string LicensePlate) {
	if (availableCars.find(carModel) == availableCars.end()) {
		cout << "Car not found" << endl;
		return nullptr;
	}
	if (LicensePlate == "") {
		return availableCars[carModel].back();
	}
	for (auto x : availableCars[carModel]) {
		if (x->getLicensePlate() == LicensePlate) {
			return x;
		}
	}
	return nullptr;
}
Customer* rentalService::searchCustomer(string dlNumber) {
	if (customerDetails.find(dlNumber) == customerDetails.end()) {
		cout << "Customer not found" << endl;
		return nullptr;
	}
	return customerDetails[dlNumber];

}