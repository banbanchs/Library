#include <stdexcept>
#include "user.h"


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


std::ostream& operator<<(std::ostream &os, User &user)
{
    os << user.m_id << "\t"
        << user.m_name
        << user.m_sex;
    return os;
}


std::istream& operator>>(istream &is, User &user)
{
    is >> user.m_id >> user.m_name >> user.m_sex;
    return is;
}
