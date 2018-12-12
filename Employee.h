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
using namespace std;
const int DefaultStartingSalary = 0;
static int empCounter= 0;
class Employee {
private:
	char* name;
	double salary;
	int   id;

public:

	Employee();//Default Constructor
	virtual ~Employee();//Destructor
	Employee (const char* , int , double   );//Constructor
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


    //OPERATORS
    Employee operator+ (const Employee& e) const;
    Employee operator*(const Employee& e)const;
    Employee& operator++();
    Employee operator++(int);
    friend inline bool operator<(const Employee& l, const Employee& r) {return l.salary< r.salary;}
    inline bool operator==(const Employee& e)const;
    Employee& operator+=(const Employee& e);
    Employee& operator=(const Employee& e);
    friend ostream& operator<<(ostream& out, const Employee& e) {e.print();return out;}
#endif /* EMPLOYEE_H_ */
