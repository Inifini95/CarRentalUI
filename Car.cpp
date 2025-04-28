#pragma once 
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

#include "Car.h"
Car::Car(int y, string m, string c, string clr) : year(y), model(m), company(c), color(clr) {}




void Car::setLicensePlate(string lp) {
	licensePlate = lp;
}
string Car::getLicensePlate() {
	return licensePlate;
}
string Car::getModel() {
	return model;
}
string Car::getCompany() {
	return company;
}
string Car::getColor() {
	return color;
}
int Car::getYear() {
	return year;
}
string Car::getRentedOn() {
	return rentedOn;
}



bool Car::isAvailable() {
	return !isRented;
}
