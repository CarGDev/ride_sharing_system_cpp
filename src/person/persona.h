#pragma once
#include <string>

struct PersonaData {
  std::string name, last_name, id, email, phone;
};

class Persona {
public:
  std::string name;
  std::string last_name;
  std::string id;
  std::string email;
  std::string phone;

  virtual ~Persona() = default;
  virtual std::string getFullName();
  virtual PersonaData getData();
  virtual void setFullName(std::string name, std::string last_name);
  virtual void setId(std::string id);
  virtual void setEmail(std::string email);
  virtual void setPhone(std::string phone);
};
