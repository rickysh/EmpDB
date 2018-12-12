#include "Employee.h"
#include <string.h>
#include <iostream>
#include "DataBase.h"
using namespace std;

DataBase::DataBase() {
	numOfemployees = 0;
	arrLen = 10;
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

	if(getEmployee(theEmployee->getId()) == NULL){ //if it does not exist already, add the employee
		if (numOfemployees < arrLen) { //looks if the list is full or not
			list[numOfemployees] = *theEmployee; //adds the employee to the list
			numOfemployees++; //increments the list
			return true;
		}
		else{ //TODO double the size of list! // array is full
			arrLen = arrLen * 2;            // Double the previous size.
			Employee* temp = new Employee[arrLen]; // Allocate new, bigger array.
			for (int i=0; i<arrLen; i++)
				temp[i] = list[i];       // Copy old array to new array.
			//delete [] list;              // Free old array memory.
			list = temp;                 // Now a points to new array.
			list[numOfemployees] = *theEmployee; //adds the employee to the list // TODO maybe +1
			numOfemployees++; //increments the list
			return true;
		}
	}
	else
		cout<<"already exist"<<endl;
	return false;
}

bool DataBase::removeEmployee(int idToRemove)
{
	Employee* E = getEmployee(idToRemove);
	if(E != NULL && arrLen != 0){ //if it exist, delete it, looks if the list is empty or not
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

	return false;
}
Employee* DataBase::getEmployee(int employeeID)
{
	for(int i = 0; i < numOfemployees; i++){
		if(strcmp(list[i].getName(), "Name") != 0)
			if(list[i].getId() == employeeID )
				return &list[i];
	}
	return NULL;
}

void DataBase::print() const
{
	if(numOfemployees > 0){
		cout<<"Employees batabase:\n"<<endl;
		for(int i = 0; i < numOfemployees;  i++)
			if(strcmp(list[i].getName(), "Name") != 0)
				list[i].print();
	}
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
	// destructor stub
	for(int i = 0; i < arrLen; i++)
		list[i].~Employee();
	delete list;
}
