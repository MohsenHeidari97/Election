#ifndef ELECTIONMAIN_PERSON_H
#define ELECTIONMAIN_PERSON_H

#include <iostream>
#include "Date.h"

class Person{
public:
    Person();
    Person(string);

    Person(string , string , string , string , int);

    ~Person();

    void setNationalCode(string);
    void setFirstName(string);
    void setLastName(string);
    void setFatherName(string);
    void setAge(int);
    void setLicense(string);
    void setId(int);
    void setbirthDate(Date);

    string getFirstName();
    string getLastName();
    string getFatherName();
    string getNationalCode();
    int getId();
    int getAge();
    Date getBirthDate();

public:
    string firstName;
    string lastName;
    string fatherName;
    string nationalCode;
    string license;
    int id;
    int age;
    Date birthDate;
};


#endif //ELECTIONMAIN_PERSON_H
