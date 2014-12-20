#ifndef _USER_H
#define _USER_H value

#include <iostream>

using namespace std;

class User
{
public:
    User ();
    User (long id);
    ~User () {}

    long id() const { return this->m_id; }

    bool isSuperUser() const { return this->m_permission; }
    bool active() const { return this->m_active; }

private:
    long m_id;
    string m_name;
    bool m_sex;   /* man: true, woman: false */
    bool m_active;
    bool m_permission;

    friend ostream &operator<<(ostream &os, User &user);
    friend istream &operator>>(istream &is, User &user);
};

#endif
