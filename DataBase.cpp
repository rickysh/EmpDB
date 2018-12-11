

#include "DataBase.h"
using namespace std;

DataBase::DataBase() {
	// TODO Auto-generated constructor stub
	numOfemployees = 0;
	lsize = 3;
	list = new Employee[lsize]; // data is an array need to build array with size 3
	// IN HEAP

}
DataBase::DataBase ( const DataBase& D ){//copy another database
	//copy everything
	list = new Employee[D.lsize];
	this->numOfemployees = D.numOfemployees;
	this->lsize = D.lsize;
	for(int i = 0; i < D.lsize; i++)
		list[i] = D.list[i]; //copies all the employees inside the other list
}



void DataBase::addEmployee(Employee &theEmployee)
{
	Employee emp;
	emp.setName(theEmployee.getName());
	emp.setSalary(theEmployee.getSalary());
	emp.setId(theEmployee.getId());
	//TODO - need to add it to array.

	if(!getEmployee(emp.getId())){ //if it does not exist already, add the employee
		if (numOfemployees < lsize) { //looks if the list is full or not
			list[numOfemployees] = emp; //adds the employee to the list
			numOfemployees++; //increments the list
		}
		else
			cout<<"You cannot add "<<emp.getName()<<" because the list is full."<<endl;
	}
	else
		cout<<"The employee "<<emp.getName()<<" already exists."<<endl;
}

bool DataBase::removeEmployee(int idToRemove)
{
	Employee* E = getEmployee(idToRemove);
	if(E && lsize != 0){ //if it exist, delete it, looks if the list is empty or not
		for(int i = 0; i < lsize; i++){
			if(list[i].getId() == E->getId()){
				for(int j = i; j < lsize-1; j++)
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
	for (auto& employee : list) {
		if (employee.getId() == employeeID)
			return employee;
	}
	throw runtime_error("No employee found.");
}

void DataBase::print() const
{
	if(lsize != 0)
		for (const auto& employee : list)
			employee.print();
	else
		cout<<"Cannot print the list of employees because it is empty."<<endl;

}
int DataBase::getNumEmployee(){ //gets the number of employee in the database company
	return numOfemployees;
}
int DataBase::getActualSize(){ //returns the size
	return lsize;
}

DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
	for (const auto& employee : list)
		employee.~Employee();
	delete list;
}
