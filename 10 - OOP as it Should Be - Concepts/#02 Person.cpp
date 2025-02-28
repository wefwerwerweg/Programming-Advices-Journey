// Person
// https://programmingadvices.com/courses/1936515/lectures/44037326/comments/25928975
#include <iostream>

class Person {
 public:
  Person(short id, std::string firstName, std::string lastName,
         std::string email, std::string phone) {
    id_ = id;
    email_ = email;
    phone_ = phone;
    lastName_ = lastName;
    firstName_ = firstName;
  }

  short id() { return id_; }
  std::string email() { return email_; }
  std::string phone() { return phone_; }
  std::string lastName() { return lastName_; }
  std::string firstName() { return firstName_; }
  std::string fullName() { return firstName_ + ' ' + lastName_; }

  void setEmail(std::string email) { email_ = email; }
  void setPhone(std::string phone) { phone_ = phone; }
  void setLastName(std::string lastName) { lastName_ = lastName; }
  void setFirstName(std::string firstName) { firstName_ = firstName; }

  void info() {
    std::cout << "\nInfo:\n";
    std::cout << "\n--------------------";
    std::cout << "\nID         : " << id_;
    std::cout << "\nFirst Name : " << firstName_;
    std::cout << "\nLast Name  : " << lastName_;
    std::cout << "\nFull Name  : " << firstName_ << ' ' << lastName_;
    std::cout << "\nEmail      : " << email_;
    std::cout << "\nPhone      : " << phone_;
    std::cout << "\n--------------------\n";
  }

  void sendEmail(std::string subject, std::string body) {
    std::cout << "\nThe following message sent successfully to email: " << email_;
    std::cout << "\nSubject: " << subject;
    std::cout << "\nBody: " << body << '\n';
  }

  void sendSms(std::string sms) {
    std::cout << "\nThe following SMS sent successfully to phone: " << phone_
              << '\n' << sms << '\n';
  }

 private:
  short id_;
  std::string email_;
  std::string phone_;
  std::string lastName_;
  std::string firstName_;
};

int main() {
  Person person(1, "Mohamed", "Osama", "example@gmail.com", "0123456789");
  person.info();
  person.sendSms("hello");
  person.sendEmail("Subject", "Body");
  return 0;
}
