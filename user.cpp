#include <stdexcept>
#include "user.h"

// Every person can borrow five books
const int MAX_BORROW = 5;


User::User()
{
    m_id = 0L;
    m_name = "Unkown";
    m_sex = true;
    m_active = true;
    m_permission = false;
}


User::User(long id)
{
    // Super user
    // ROOT
    if (id == -1L) {
        m_id = 9999L;
        m_name = "Root";
        m_sex = false;
        m_active = true;
        m_permission = true;
    }
    else {
        throw invalid_argument("user id need to be -1");
    }
}


bool User::borrowBook(string bookName)
{
    if (m_books.size() < MAX_BORROW) {
        m_books.push_back(bookName);
        return true;
    }
    return false;
}


void User::retBook(string bookName)
{
    m_books.remove(bookName);
}


std::ostream& operator<<(std::ostream &os, User &user)
{
    os << user.m_id << "\t"
        << user.m_name << "\t";
    if (user.m_sex)
        os << "male";
    else
        os << "female";
    return os;
}


std::ostream& operator<<(std::ostream &os, const User &user)
{
    os << user.m_id << " "
        << user.m_name << " "
        << user.m_sex;
    return os;
}


std::istream& operator>>(istream &is, User &user)
{
    is >> user.m_id >> user.m_name >> user.m_sex;
    return is;
}
