#include <iostream>
#include "User.hpp"

int main()
{
    User* u = new User();

    std::cout << u->getId() << std::endl;
    return 0;
}