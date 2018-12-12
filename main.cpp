#include "Employee.h"
#include "DataBase.h"

#include <string.h>
#include <iostream>

using namespace std;

int main() {


	Employee* yael = new Employee((char*)"Yael",11,6000);
	Employee* barak = new Employee((char*)"Barak",10,11000);

//	cout<<"Cost party for Barak: "<< barak->planOfficeParty() << "\n" <<endl;
//	cout<<"Cost party for yael: "<< yael->planOfficeParty() << "\n" <<endl;
//	if(*barak>*yael)
//		cout<<"Barak's salary is higher than Yael's \n"<<endl;
//	double salaryBefore =((*barak)++).getSalary();
//	cout<< "Salary before:"<< salaryBefore <<"\n"<<endl;
//	cout <<(*barak)<<endl;
//	*barak+*yael;
//	*barak += *yael;
//	cout<< "Salary of barakyael:"<<endl;
//	cout <<(*barak)<<endl;
//	if(*barak>*yael)
//		cout<<"Barak's salary is higher than Yael's \n"<<endl;


		DataBase dataBase;
		dataBase.addEmployee(yael);
		dataBase.addEmployee(barak);
		dataBase.print();
	//	dataBase.removeEmployee(1);
	//	dataBase.removeEmployee(10);
	//	dataBase.print();

	//	Employee *b = dataBase.getEmployee(12);
	//	Employee *y = dataBase.getEmployee(10);
	//	cout <<(*b)<<endl;
	//	cout <<(*y)<<endl;


	//dataBase.print();


	return 0;

}
