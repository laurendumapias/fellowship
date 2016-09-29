#ifndef Student_h
#define Student_h 
#include <string>

class Student
{
  public:
  Student();
  Student(std::string name, double gpa);

  double getGPA();
  std::string getName();

  void setGPA(double gpa);
  void setName(std::string name);

 private:
  std::string name;
  double gpa;
};

#endif
