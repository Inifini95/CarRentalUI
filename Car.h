#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Car {
private:
	int year;
	string company;
	string model;
	string color;
	string licensePlate;

	bool isRented;
	string rentedOn;


public:
	Car(int, string, string, string);

	void setLicensePlate(string lp);

	string getLicensePlate();

	string getModel();

	string getCompany();

	string getColor();

	int getYear();

	string getRentedOn();

	bool isAvailable();

};
