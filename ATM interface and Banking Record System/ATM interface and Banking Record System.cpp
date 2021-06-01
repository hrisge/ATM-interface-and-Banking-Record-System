#include <iostream>
#include "Admin.h"

int main()
{
    std::cout << "Hello World!\n";
    Admin p("0123456789", "Gosho", "Ot", "Pochivka", 04, 05, 1953, 298346, "Mladost69");
    Admin d(p);
    std::cout << d.getEgn() << '\n';
    std::cout << d.getName().getFirstName() << '\n';
    std::cout << d.getName().getMidName() << '\n';
    std::cout << d.getName().getLastName() << '\n';
    std::cout << d.getDateOfBirth().getDay() << '\n';
    std::cout << d.getDateOfBirth().getMonth() << '\n';
    std::cout << d.getDateOfBirth().getYear() << '\n';
    std::cout << d.getMobileNumber() << '\n';
    std::cout << d.getAdress() << '\n';


}