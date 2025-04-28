#pragma once
#include "pch.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Customer.h"


Customer::Customer(string n, string pn, string mailId, string lic, string add, int age) : name(n), phoneNumber(pn), email(mailId), dlNumber(lic), address(add), age(age) {}

void Customer::rentCar(string carModel, string LicensePlate, string date) {
	rentedCar = carModel;
	rentedOn = date;
	isCurrentlyRenting = true;
	carLicensePlate = LicensePlate;
}
void Customer::returnCar(string date) {
	returnDate = date;
	isCurrentlyRenting = false;
}
bool Customer::isRenting() {
	return isCurrentlyRenting;
}
string Customer::getRentedCar() {
	return rentedCar;
}
string Customer::getRentedOn() {
	return rentedOn;
}