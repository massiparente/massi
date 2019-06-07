#ifndef Resistor_h
#define Resistor_h

#include <string>
#include <iostream>

using std::string;

class Resistor{
 public:
  Resistor(const string& name, const double& R);
  ~Resistor(){};
  void setR(const double& R);

  virtual void print() const;
  virtual string name() const;
  virtual double value() const;

  Resistor operator+(const Resistor& rhs) const;
  Resistor operator||(const Resistor& rhs) const;

 private:
  string _name;
  double _R;
};

#endif
