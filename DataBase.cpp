/*
 * dataBase.cpp
 *
 *  Created on: Dec 10, 2018
 *      Author: serfati
 */

#include "DataBase.h"

DataBase::DataBase() {
	// TODO Auto-generated constructor stub
	numOfemployees = 0;
	data = NULL;
}



DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
	delete data;
}