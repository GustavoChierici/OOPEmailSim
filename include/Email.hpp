#pragma once
#include <string>

class Email
{
public:
    Email(const unsigned int s_id, const unsigned int r_id, std::string msg);
    ~Email();

    const unsigned int getSenderId() const;
    const unsigned int getReceiverId() const;
    const bool isRead() const;
    const std::string read();
private:
    const unsigned int sender_id;
    const unsigned int receiver_id;
    std::string message;
    bool is_read;
};