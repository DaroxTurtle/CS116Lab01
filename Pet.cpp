/*
  CLASS PET FOR PET SHELTER,
  STORES NAME, TYPE, AGE, ID NUMBER & DAYS IN SHELTER
  FOR ARRAY USE
*/

#include "Pet.h"
#include <iostream>

Pet::Pet() 
{
  this->name = "N/A";
  this->type = "N/A";
  this->age = 0;
  this->id_number = 0;
  this->days_in_shelter = 0;
}

string Pet::get_name() const 
{
  return this->name;
}

string Pet::get_type() const
{
  return this->type;
}

int Pet::get_age() const
{
  return this->age;
}

int Pet::get_id_number() const
{
  return this->id_number;
}

int Pet::get_days_in_shelter() const
{
  return this->days_in_shelter;
}

void Pet::set_name(string name)
{
  this->name = name;
}

void Pet::set_type(string type)
{
  this->type = type;
}

void Pet::set_age(int age)
{
  this->age = age;
}

void Pet::set_id_number(int id_number)
{
  this->id_number = id_number;
}

void Pet::set_days_in_shelter(int days_in_shelter)
{
  this->days_in_shelter = days_in_shelter;
}

void Pet::increment_days_in_shelter()
{
  this->days_in_shelter++;
}
