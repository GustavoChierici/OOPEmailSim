#pragma once
#include <deque>
#include "Email.hpp"

class User;
class Inbox
{
public:
    Inbox(User* user);
    ~Inbox();

    void notifyUser();
    void storeEmail(Email* email);
    void deleteEmail(Email* email);

    const unsigned int getUnreadEmailsCount() const { return unread_emails_count; }
private:
    User* user;
    unsigned int unread_emails_count;
    std::deque<Email*> emails;
    std::deque<Email*> unread_emails;
};