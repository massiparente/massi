#include "Parallel.h"
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::list;
using std::string;

// Basic Constructor - Parallel made by just a resistor.
Parallel::Parallel(const string& name, Resistor* R):Resistor(name,0.){
  resistors_.push_back(R);
  setR(R->value());
}
// Otherwise we could create a
// parallel object with no resistor, associated to a Resistor object with infinite resistance.
// In this way we can use the "add" method to build the parallel starting from no resistors.
// This could be done by using a constructor like:
//
// Parallel::Parallel(const string& name):Resistor(name, std::numeric_limits<double>::infinity()){}

// Constructor for two resistors; it also updates the value of the resistor
// object associated to the parallel

Parallel::Parallel(const string& name, Resistor* R1, Resistor* R2):Resistor(name,0.){
  resistors_.push_back(R1);
  resistors_.push_back(R2);
  setR(1./(1./(R1->value())+1./(R2->value())));
}

// value(): it returns the value of the parallel by iterating on each element of the list

double Parallel::value() const{
  double value_parallel=0;
  for(list<Resistor*>::const_iterator i = resistors_.begin(); i != resistors_.end(); ++i) {
    value_parallel+=1./((*i)->value());
  }
  return 1./value_parallel;
}

// name(): it returns the name of the parallel (so R1||R2||R3... etc...)

string Parallel::name() const{
  string name_parallel= (resistors_.front())->name();
  for(list<Resistor*>::const_iterator i = next(resistors_.begin()); i != resistors_.end(); ++i) {
    name_parallel.append("||");
    name_parallel.append((*i)->name());
  }
  return name_parallel;
}

// print(): it prints the name and the value of the parallel, and also the name and the value of
// each resistor of the parallel

void Parallel::print() const {
  cout << name() << ": " << value() << " ohm" << endl;
  for(list<Resistor*>::const_iterator i = resistors_.begin(); i != resistors_.end(); ++i) {
    cout << " " ;
    (*i)->print();
  }
}

// add: it allows to add more resistors to the parallel. It also updates the value of the
// resistor object associated to the parallel

void Parallel::add(Resistor* resistor){
  double value_parallel=0;
  resistors_.push_back(resistor);
  value_parallel+=(1./resistor->value());
  setR(1./((1./Resistor::value())+value_parallel));
}
