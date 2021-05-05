#include "User.hpp"
#include <iostream>

std::vector<User*> User::users;
unsigned int User::id_count{0};

User::User():
id{User::id_count++},
email_box{new Inbox(this)}
{
    User::users.push_back(this);
}

User::~User()
{
    User::users[id] = nullptr;
}

const unsigned int User::getId() const 
{
    return id;
}

void User::sendEmail(unsigned int id, std::string message)
{
    User* receiver = User::users[id];
    Email* email = new Email(this->id, id, message);

    std::unique_lock<std::mutex> lock(receiver->mu);
    std::cout << this->id << " enviando: \"" << message << "\" para " << id << std::endl;
    receiver->receiveEmail(email);
}

void User::receiveEmail(Email* email)
{
    email_box->storeEmail(email);
}

void User::readEmail(Email* email)
{
    auto message = email->read();
    std::cout << id << " lendo: \"" << message << '"' << std::endl;
}