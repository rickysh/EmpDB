/*
 * Employee.h
 *
 *      Author: serfati
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string.h>
#include <iostream>

class Employee {
	char* name;
	double salary;
	int   id;

public:
	Employee();
	virtual ~Employee();
	Employee (	char* , int , double   );
	Employee (const Employee&);
	int planOfficeParty();
	void print();
	double getSalary();
};

#endif /* EMPLOYEE_H_ */
