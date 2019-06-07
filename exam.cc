// g++ -o /tmp/app exam.cc Parallel.cc Resistor.cc

#include <iostream>
#include "Resistor.h"
#include "Parallel.h"
#include <iomanip>

using std::cout;
using std::endl;

int main(){

cout << "Create R1 and R2" << endl;

Resistor R1("R1",10);
Resistor R2("R2",10);

R1.print();
R2.print();

cout << "make a parallel R6 of R1 and R2 and print it" << endl;

Parallel R6("R6", &R1, &R2);

R6.print();

cout << "Create R7 and R8" << endl;
Resistor R7("R7", 5);
Resistor R8("R8", 5);

cout << "make a parallel R9 of R7 and R8 and print it" << endl;

Parallel R9("R9", &R7, &R8);

R9.print();

cout << "add R6 to R9 and print it" << endl;
R9.add(&R6);

R9.print();

cout << "+++++ bonus +++++" << endl;

R1.print();
R2.print();

cout << "R3 = R1 + R2" << endl;

Resistor R3=R1+R2;

R3.print();

cout << "R4= R1 || R2" << endl;

Resistor R4=R1||R2;

R4.print();

return 0;

}
