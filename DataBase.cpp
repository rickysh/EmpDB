

#include "DataBase.h"

DataBase::DataBase() {
	// TODO Auto-generated constructor stub
	numOfemployees = 0;
	data = NULL; // data is an array need to build array with size 3
    // IN HEAP
}


DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
	for (const auto& employee : data)
        employee.~Employee();
    delete data;
}

void Database::addEmployee(Employee theEmployee)
{
    Employee emp;
    emp.setName(theEmployee.name);
    emp.setSalary(theEmployee.salary);
    emp.setEmployeeID(theEmployee.id);
    numOfemployees++;
    //TODO - need to add it to array.

}

Employee* Database::getEmployee(int employeeID)
{
 for (auto& employee : data) {
     if (employee.getEmployeeID() == employeeID)
        return employee;
}
throw runtime_error("No employee found.");
}

void Database::print() const
{
    for (const auto& employee : data)
        employee.print();

}