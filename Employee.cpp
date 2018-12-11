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
	name = "";
	salary = DefaultStartingSalary;
	id = 0;

}

Employee::Employee (char* name, int id , double salary ){
	if (!name || ! salary )
       this->name = new char[strlen(name) + 1];
   strcpy(this->name, name);
   this->salary=salary;
   this->id=id;
}

Employee::Employee (const Employee& emp){
	id = emp.id;
	salary = emp.salary;
	name = new char[strlen(emp.name) + 1];
	strcpy(this->name, emp.name);
}
int planOfficeParty(){ // TODO
	return 0;
}

void Employee::print() const
{
	cout << "name:" << name << "\n" << "ID:" << id
 << "\n" << "Salary:" << salary <<"\n"<< endl;
}

//GETTERS AND SETTERS

void Employee::setName(const char*& nName){
    name = nName;
}

const char*& Employee::getName() const {
    return name;
}

void Employee::setSalary(double newSalary) {
    salary = newSalary;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setEmployeeID(int nId){
    id = nId;
}

int Employee::getEmployeeID() const {
    return id;
}

void Employee::promote(double raiseAmount){
    setSalary(getSalary() + raiseAmount);
}

void Employee::demote(double demeritAmount){
    setSalary(getSalary() - demeritAmount);
}


Employee::~Employee() {
    // TODO Auto-generated destructor stub
    delete[] name;
}
