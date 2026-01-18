#include "splashkit.h"
using namespace std;

int main()
{
    int age = 0;
    string name = "Taro";

    // datatype * identifier = &variable;
    //(NOTE: & operator is used to get the address of the variable, * operator is used to access the value at the address)

    int * pAge = &age;
    string * pName = &name;

    // de-referencing => getting the value from the pointer/address
    // *identifier = newValue;
    *pAge = 20;

    // Example usage: Print the values pointed to by the pointers
    write_line("Age: " + to_string(*pAge));
    write_line("Name: " + *pName);

    return 0;
}
