#include "Person.h"

Person::Person() {
    ;
}

Person::Person( string firstName, string lastName, string fatherName , string nationalCode ,int age ) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> fatherName = fatherName;
    this -> nationalCode = nationalCode;
    this -> age = age;
}

Person::~Person() {
    ;
}

void Person::setNationalCode(string nationalCode) {
    this -> nationalCode = nationalCode;
}

void Person::setFirstName(string firstName) {
    this -> firstName = firstName;
}

void Person::setLastName(string lastName) {
    this -> lastName = lastName;
}

void Person::setFatherName(string fatherName) {
    this -> fatherName = fatherName;
}

void Person::setAge(int age) {
    this -> age =age;
}

void Person::setLicense(string license) {
    this -> license = license;
}

void Person::setbirthDate(Date birthDate) {
    birthDate.setDate(birthDate.getDate("year"),
                      birthDate.getDate("month"),
                      birthDate.getDate("day"));
}

string Person::getFirstName() {
    return firstName;
}

string Person::getLastName() {
    return lastName;
}

string Person::getFatherName() {
    return fatherName;
}

string Person::getNationalCode() {
    return nationalCode;
}

int Person::getAge()  {
    return age;
}
int Person::getId() {
    return id;
}
Date Person::getBirthDate() {
    return birthDate;
}