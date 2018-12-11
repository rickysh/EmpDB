/*
 * Employee.cpp
 *
 *  Created on: Dec 10, 2018
 *      Author: serfati
 */

#include "Employee.h"
using namespace std;
Employee::Employee() {
	// TODO Auto-generated constructor stub
	name = new char[5];
	salary = 0;
	id = 0;

}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
	delete[] name;
}

Employee::Employee (char* name, int id , double salary ){
	if (!name || ! salary )
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->salary=salary;
	this->id=id;
}

Employee::Employee (const Employee& emp){
	this->id = emp.id;
	this->salary = emp.salary;
	this->name = new char[strlen(emp.name) + 1];
	strcpy(this->name, emp.name);
}
int planOfficeParty(){ // TODO
	return 0;
}

double Employee::getSalary(){
	return this->salary;
}

void Employee::print()
{
	cout << "name:" << name << "\n" << "ID:" << id
			<< "\n" << "Salary:" << salary <<"\n"<< endl;
}
