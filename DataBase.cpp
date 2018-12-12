#include "Employee.h"
#include <string.h>
#include <iostream>
#include "DataBase.h"
using namespace std;

DataBase::DataBase() {
	numOfemployees = 0;
	arrLen = 3;
	list = new Employee[arrLen]; // data is an array need to build array with size 3
}
DataBase::DataBase ( int numOfemployees, Employee* otherList ){
	//TODO not good enougth
	this->numOfemployees = numOfemployees;
	arrLen = 10;
	for(int i = 0; i < arrLen; i++)
		this->list[i] = otherList[i];
	this->list = otherList;

}

DataBase::DataBase ( const DataBase& DB ){//copy another database
	//copy everything
	list = new Employee[DB.arrLen];
	this->numOfemployees = DB.numOfemployees;
	this->arrLen = DB.arrLen;
	for(int i = 0; i < DB.arrLen; i++)
		list[i] = DB.list[i]; //copies all the employees inside the other list
}

bool DataBase::addEmployee(Employee *theEmployee)
{
	//TODO - need to add it to array.

	if(true){ //if it does not exist already, add the employee
		if (numOfemployees < arrLen) { //looks if the list is full or not
			list[numOfemployees] = *theEmployee; //adds the employee to the list // TODO maybe +1
			numOfemployees++; //increments the list
			return true;
		}
		else //TODO double the size of list!
			cout<<"You cannot add "<<theEmployee->getName()<<" because the list is full."<<endl;
	}
	else
		cout<<"The employee "<<theEmployee->getName()<<" already exists."<<endl;
	return false;
}

bool DataBase::removeEmployee(int idToRemove)
{
	Employee* E = getEmployee(idToRemove);
	if(E && arrLen != 0){ //if it exist, delete it, looks if the list is empty or not
		for(int i = 0; i < arrLen; i++){
			if(list[i].getId() == E->getId()){
				list[i].~Employee();
				for(int j = i; j < arrLen-1; j++)
					list[j] = list[j+1]; //shifts the elements
				numOfemployees--; //decrements the list
				return true;
			}
		}
	}
	else
		cout<<"The employee "<<E->getName()<<" does not exist."<<endl;

	return false;
}
Employee* DataBase::getEmployee(int employeeID)
{
	for(int i = 0; i < arrLen; i++){
		if(list[i].getId() == employeeID)
			return &list[i];
	}
	throw runtime_error("No employee found.");
	return NULL;
}

void DataBase::print() const
{
	if(arrLen != 0)
		for(int i = 0; i < arrLen-1; i++)
			list[i].print();

	else
		cout<<"Cannot print the list of employees because it is empty."<<endl;

}

int DataBase::getNumEmployee(){ //gets the number of employee in the database company
	return numOfemployees;
}

int DataBase::getArrayLength(){ //returns the size
	return arrLen;
}

DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
	for(int i = 0; i < arrLen; i++)
		list[i].~Employee();
	delete list;
}
