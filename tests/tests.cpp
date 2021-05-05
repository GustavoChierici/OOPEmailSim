#include "catch.hpp"
#include "User.hpp"

#include <iostream>
#include <future>
#include <cstdlib>
#include <ctime>

TEST_CASE("One user can be created", "[User]")
{
    User* u = new User();

    REQUIRE(u->getId() == 0);

    User::reset();
}

TEST_CASE("Multiple users can be created", "[User]")
{
    User* u1 = new User();
    User* u2 = new User();
    User* u3 = new User();
    User* u4 = new User();
    User* u5 = new User();

    REQUIRE(u1->getId() == 0);
    REQUIRE(u2->getId() == 1);
    REQUIRE(u3->getId() == 2);
    REQUIRE(u4->getId() == 3);
    REQUIRE(u5->getId() == 4);

    User::reset();
}

TEST_CASE("Inbox can be created", "[Inbox]")
{
    Inbox* i = new Inbox(new User());

    REQUIRE(i != nullptr);
    User::reset();
}

TEST_CASE("Email can be created", "[Email]")
{
    Email* e = new Email(0, 1, "Olá!");

    REQUIRE(e->read() == "Olá!");
    REQUIRE(e->isRead() == true);
}

TEST_CASE("User can send email", "[Complete]")
{
    User* u1 = new User();
    User* u2 = new User(); 

    u1->sendEmail(u2->getId(), "Olá, tudo bem?");

    REQUIRE(u2->getEmailBox()->getUnreadEmailsCount() == 1);

    User::reset();
}

TEST_CASE("Multiple emails being sent", "[Concurrent]")
{
    std::vector<User*> users;

    for(int i = 0; i < 500; i++)
        users.push_back(new User());

    int count = 0;

    std::vector<std::future<void>> futures;

    srand(time(NULL));
    while(count < 100000)
    {
        futures.push_back(std::async(std::launch::async, &User::sendEmail, users[(rand() % users.size())], (unsigned int)(rand() % users.size()), "Olá"));
        count++;
    }
}