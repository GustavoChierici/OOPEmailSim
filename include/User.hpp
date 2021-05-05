#pragma once
#include <string>
#include <vector>
#include <future>
#include "Inbox.hpp"

class User
{
public:
    User();
    ~User();

    void sendEmail(unsigned int id, std::string message);
    void receiveEmail(Email* email);
    void readEmail(Email* email);

    const unsigned int getId() const;
    static void reset()
    {
        id_count = 0;
        users.clear();
    }

    Inbox* getEmailBox() {return email_box;}

public:
    std::mutex mu;

private:
    static std::vector<User*> users;
    const unsigned int id;

    static unsigned int id_count;

    Inbox* email_box;
};
