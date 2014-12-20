#ifndef _BOOK_H
#define _BOOK_H

#include <iostream>
#include <map>
#include <time.h>

#include "user.h"

using namespace std;

class Book
{
public:
    Book ();
    Book (string &name, string &isbn, string &writer, string &publisher, int total);
    ~Book () {}

    long id() const { return this->m_id; }
    string name() const { return this->m_name; }
    string isbn() const { return this->m_isbn; }
    string writer() const { return this->m_writer; }
    string publisher() const { return this->m_publisher; }
    int total() const { return this->m_total; }
    int remain() const { return this->m_total; }

    friend ostream &operator<<(ostream &os, Book &book);
    friend istream &operator>>(istream &is, Book &book);

private:
    long m_id;
    string m_name;
    string m_isbn;
    string m_writer;
    string m_publisher;
    int m_total;
    int m_remain;
    map<User, time_t> m_borrowers;
};

#endif  // _BOOK_H
