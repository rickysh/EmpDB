/*
 * Employee.h
 *
 *      Author: serfati
 */
#pragma once
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string.h>
#include <iostream>

const int DefaultStartingSalary = 0;

class Employee {
private:
	const char* name;
	double salary;
	int   id;

public:

	Employee();//Default Constructor
	virtual ~Employee();//Destructor
	Employee (const	char* , int , double   );//Constructor
	Employee (const Employee&);//Copy Constructor
	int planOfficeParty();
	void print() const;  //prints the employee

	// GETTERS AND SETTERS
	void setName( const char* );
	const char* getName() const; //gets his name
	void setId(int );
	int getId() const; //gets his employee id
	void setSalary(double );
	double getSalary() const;

	void promote(double raiseAmount = 1000);
	void demote(double demeritAmount = 1000);


};

#endif /* EMPLOYEE_H_ */
