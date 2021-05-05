#include "Inbox.hpp"
#include "User.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

Inbox::Inbox(User* user):
user{user},
unread_emails_count{0}
{
}

Inbox::~Inbox()
{
}

void Inbox::notifyUser()
{
    if(unread_emails_count >= 10)
    {
        srand(time(NULL));
        for(auto& email : unread_emails)
        {
            if(rand() % 100 > 80)
                break;
            user->readEmail(email);
            unread_emails.pop_front();
            unread_emails_count--;
        }
    }
}

void Inbox::storeEmail(Email* email)
{
    emails.push_back(email);
    unread_emails.push_back(email);
    unread_emails_count++;

    notifyUser();
}

void Inbox::deleteEmail(Email* email)
{
    auto element = std::find(emails.begin(), emails.end(), email);
    if(element != emails.end())
        emails.erase(element);

    element = std::find(unread_emails.begin(), unread_emails.end(), email);
    if(element != unread_emails.end())
        unread_emails.erase(element);
}