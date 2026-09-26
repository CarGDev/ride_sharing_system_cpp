#include "persona.h"
#include <string>

std::string Persona::getFullName() { return name + " " + last_name; }

PersonaData Persona::getData() { return {name, last_name, id, email, phone}; }

void Persona::setFullName(std::string name, std::string last_name) {
  this->name = name;
  this->last_name = last_name;
}

void Persona::setId(std::string id) { this->id = id; }

void Persona::setEmail(std::string email) { this->email = email; }

void Persona::setPhone(std::string phone) { this->phone = phone; }
