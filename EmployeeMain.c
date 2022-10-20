//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 

//gcc employeeMain.c employeeTable.c employeeTwo.c 

#include <string.h> 
#include <stdlib.h> 
#include "Employee.h" 

int main(void){ 
    //defined in employeeSearchOne.c 
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneNumberToFind); 
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind); 

    //defined in employeeTable.c 
    extern Employee EmployeeTable[];     //extern tells computer that the it will be declared somewhere else
    extern const int EmployeeTableEntries;      

    PtrToEmployee matchPtr;  //Declaration      //Can also use Employee* HOWEVER, doing it this way makes it more readable
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

    //Example not found 
    if (matchPtr != NULL) 
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee ID is NOT found in the record\n"); 

    //Example found 
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 
    if (matchPtr != NULL) 
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n"); 

    //Search by Phone Number Test
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134"); 
    if (matchPtr != NULL) 
        printf("Employee Phone Number 909-555-2134 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Phone Number 909-555-2134 is not in the record\n"); 
        
    //Search by Salary Test
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34); 
    if (matchPtr != NULL) 
        printf("Employee Salary 6.34 is in record %d\n", matchPtr - EmployeeTable); 
    else 
        printf("Employee Salary 6.34 is NOT found in the record\n"); 

    return EXIT_SUCCESS; 
} 