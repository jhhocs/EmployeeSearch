#include <string.h> 
#include "Employee.h" 

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){ 
    const PtrToConstEmployee endPtr = ptr + tableSize; 
    for(; ptr < endPtr; ptr++)  //search until end of table  ptr++ will increment by what??     
                                //ptr++ increments by 32 bytes because the Employee struct has a size of 32 bytes
    { 
        if(ptr->number == targetNumber) //check if it equals the Employee number 
            return (PtrToEmployee) ptr; //return location of the number to callee. 
    } 
     return NULL;   //this will only happen if no Employee number matches in loop above 
} 

//Essentially the same functionality as above but comparing strings to check if equal 
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName){ 
    const PtrToConstEmployee endPtr = ptr + tableSize; 
    for(; ptr < endPtr; ptr++) 
    { 
        if(strcmp(ptr->name,targetName) == 0) 
            return (PtrToEmployee) ptr; 
    } 
    return NULL; 
} 