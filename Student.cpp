#include "Student.h"
#include <string>
//#include <cstring>
//const char * const name

Student::Student(){
    setName("");
    setGPA(0.0);
}

Student::Student(std::string name, double gpa) {
  setName(name);
  setGPA(gpa);
}

double Student::getGPA(){
  return gpa;
}

std::string Student::getName(){
  return name;
}

void Student::setGPA(double gpa) {
  this->gpa = gpa; 
}

void Student::setName(std::string name) {
  this->name = name;
}


/*std::string Student::toString() const {
  std::string Sname(this->getName());
  std::string SGpa = std::to_string(this->getGPA());
  std::string result = "[" + Sname + "," + SGpa + "]";
  return result;
  }*/
