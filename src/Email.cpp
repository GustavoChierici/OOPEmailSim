#include "Email.hpp"

Email::Email(const unsigned int s_id, const unsigned int r_id, std::string msg):
sender_id{s_id},
receiver_id{r_id},
message{msg},
is_read{false}
{
}

Email::~Email()
{
}

const unsigned int Email::getSenderId() const
{
    return sender_id;
}

const unsigned int Email::getReceiverId() const
{
    return receiver_id;
}

const bool Email::isRead() const
{
    return is_read;
}

const std::string Email::read()
{
    is_read = true;
    return message;
}