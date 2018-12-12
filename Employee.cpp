/*
 * Employee.cpp
 *
 *  Created on: Dec 10, 2018
 *      Author: serfati
 */

#include "Employee.h"
#include "DataBase.h"
using namespace std;
Employee::Employee() {
	// TODO Auto-generated constructor stub
	this->name = new char[strlen("Name") + 1];
	name = (char*)"Name";
	salary = DefaultStartingSalary;
	id = 0;
	empCounter++;
}

Employee::Employee (const char* name, int id , double salary ){

	if(!name ) return;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->salary=salary;
	this->id=id;
	empCounter++;
}

Employee::Employee (const Employee& emp){
	id = emp.id;
	salary = emp.salary;
	name = new char[strlen(emp.name) + 1];
	strcpy(this->name, emp.name);
}
int Employee::planOfficeParty(){ // TODO
	return empCounter*10;
}

void Employee::print() const
{
	cout << "name:" << name << "\n" << "ID:" << id
   << "\n" << "Salary:" << salary <<"\n"<< endl;
}

//GETTERS AND SETTERS

void Employee::setName( const char* nName){
	this->name = new char[strlen(nName) + 1];
	strcpy(this->name, nName);
}

const char* Employee::getName() const {
	return name;
}

void Employee::setSalary(double newSalary) {
	salary = newSalary;
}

double Employee::getSalary() const {
	return salary;
}

void Employee::setId(int nId){
	id = nId;
}

int Employee::getId() const {
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
	empCounter--;
}

Employee& Employee::operator++()
{
	this->promote(100);
    return *this;
}
Employee Employee::operator++(int o)
{
        Employee tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }
Employee& Employee:: operator+=(const Employee& rhs){

}

friend inline bool Employee::operator==(const Employee& lhs, const Employee& rhs){
	return false;
}
//Employee& Employee::operator=(const Employee& other){
//    this->id = other.id;
//    this->salary = other.salary;
//    this->name = new char[strlen(other.name) + 1];
//    strcpy(this->name, other.name);
//    return *this;
//}
