/*
 * dataBase.h
 *
 *  Created on: Dec 10, 2018
 *      Author: serfati
 */
#ifndef DATABASE_H_
#define DATABASE_H_
#include "Employee.h"
#include <string.h>
#include <iostream>

class DataBase {
	int numOfemployees;
	Employee* data;

public:
	DataBase();
	virtual ~DataBase();
	DataBase ( int , Employee* );
	DataBase ( const DataBase&  );

	void addEmployee ( Employee*);
	void print(); // printAll
	bool removeEmployee(int); //by ID
	Employee* searchByID (int);
	Employee* getEmployee (int);
};

#endif /* DATABASE_H_ */
