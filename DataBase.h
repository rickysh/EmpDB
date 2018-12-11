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
	int numOfemployees;//number of Employees DB
	Employee *list; //array of employee list
    int lsize; //size of list

public:
	DataBase();//default constructor

	DataBase ( int , Employee* );//constructor
	DataBase ( const DataBase&  );//copy constructor

	void addEmployee ( Employee&);//function to insert an employee into database
	void print(); //prints the employee list
	bool removeEmployee(int); //function to delete an employee into database
	Employee* getEmployee (int);//gets the info of an employee by their id

    int getNumEmployee(); //gets the number of Employees in list
    int getActualSize(); //gets the actual size of the list

    virtual ~DataBase();//destructor
};

#endif /* DATABASE_H_ */
