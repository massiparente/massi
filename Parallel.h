#ifndef Parallel_h
#define Parallel_h


#include "Resistor.h"
#include <list>
#include <string>
#include <iostream>

using std::string;
using std::list;

class Parallel : public Resistor{

 public:
  Parallel(const string& name, Resistor* R);
  Parallel(const string& name, Resistor* R1, Resistor* R2);
  virtual void print() const;
  virtual double value() const;
  virtual string name() const;

  void add(Resistor* resistor);

 private:
  list<Resistor*> resistors_;

};

#endif
