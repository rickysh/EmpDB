

#include "DataBase.h"

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



void Database::addEmployee(Employee theEmployee)
{
    Employee emp;
    emp.setName(theEmployee.name);
    emp.setSalary(theEmployee.salary);
    emp.setEmployeeID(theEmployee.id);
    numOfemployees++;
    //TODO - need to add it to array.

    if(!employeeExist(E)){ //if it does not exist already, add the employee
        if (size < numEmp) { //looks if the list is full or not
            list[size] = E; //adds the employee to the list
            size++; //increments the list
        }
        else
        {
            cout<<"You cannot add "<<E.getName()<<" because the list is full."<<endl;
        }
    }
    else
    {
        cout<<"The employee "<<E.getName()<<" already exists."<<endl;
    }

}

bool Database::removeEmployee(int idToRemove)
{
    Employee* E = getEmployee(idToRemove);
        if(E && lsize != 0){ //if it exist, delete it, looks if the list is empty or not
            for(int i = 0; i < lsize; i++){
                if(list[i].getId() == E.getId()){
                    for(int j = i; j < lsize-1; j++)
                        list[j] = list[j+1]; //shifts the elements
                    numOfemployees--; //decrements the list
                }
            }
        }
        else
            cout<<"The employee "<<E.getName()<<" does not exist."<<endl;
    }

    Employee* Database::getEmployee(int employeeID)
    {
        for (auto& employee : list) {
            if (employee.getEmployeeID() == employeeID)
                return employee;
        }
        throw runtime_error("No employee found.");
    }

    void Database::print() const
    {
        if(lsize != 0)
            for (const auto& employee : list)
                employee.print();
            else
                cout<<"Cannot print the list of employees because it is empty."<<endl;

    }
int EmployeeDB::getNumEmployee(){ //gets the number of employee in the database company
    return numOfemployees;
}
int EmployeeDB::getActualSize(){ //returns the size
    return lsize;
}


DataBase::~DataBase() {
    // TODO Auto-generated destructor stub
    for (const auto& employee : list)
        employee.~Employee();
    delete list;
}