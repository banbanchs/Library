#ifndef _USER_H
#define _USER_H

#include <iostream>
#include <list>

using namespace std;

class User
{
public:
    User ();
    User (long id);
    ~User () {}

    long id() const { return this->m_id; }
    string name() const { return this->m_name; }

    bool isSuperUser() const { return this->m_permission; }
    bool active() const { return this->m_active; }

    bool borrowBook(string bookName);
    void retBook(string bookName);

private:
    long m_id;
    string m_name;
    bool m_sex;     /* man: true, woman: false */
    bool m_active;
    bool m_permission;

    list<string> m_books;

    friend ostream &operator<<(ostream &os, User &user);
    friend ostream &operator<<(ostream &os, const User &user);
    friend istream &operator>>(istream &is, User &user);
};

#endif
