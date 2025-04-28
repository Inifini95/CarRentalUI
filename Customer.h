#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer {

private:
	string name;
	string address;
	string phoneNumber;
	string email;
	int age;
	string dlNumber;
	string rentedCar;
	string carLicensePlate;
	string rentedOn;
	string returnDate;
	bool isCurrentlyRenting;

public:
	Customer(string n, string pn, string mailId, string lic, string add = "", int age = 18);

	void rentCar(string carModel, string LicensePlate, string date);

	void returnCar(string date);

	bool isRenting();

	string getRentedCar();

	string getRentedOn();


};