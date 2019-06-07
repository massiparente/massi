// g++ -o /tmp/app exam.cc Resistor.cc Parallel.cc


#include <string>
#include <iostream>
#include "Resistor.h"

using std::cout;
using std::endl;
using std::string;


Resistor::Resistor(const string& name, const double& R){
  _name=name;
  _R=R;
}

void Resistor::setR(const double& R){
  _R=R;
}

double Resistor::value() const{
  return _R;
}

string Resistor::name() const{
  return _name;
}

void Resistor::print() const{
  cout << _name << ": " << _R << " ohm" << endl;
}

// + operator : it returns a Resistor object with resistance the sum of the two resistances

Resistor Resistor::operator+(const Resistor& rhs) const{
  string name_ser="(" + _name + "+" + rhs._name + ")";
  return Resistor(name_ser,_R+rhs._R);
}

// || operator : it returns a Resistor object with resistance the reciprocal of the
// sum of the reciprocal of the two resistances

Resistor Resistor::operator||(const Resistor& rhs) const{
  string name_par="("+_name + "||" + rhs._name + ")";
  return Resistor(name_par,1./(1./_R+1./rhs._R));
}
