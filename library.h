#ifndef _LIBRARY
#define _LIBRARY

#include <map>
#include <fstream>

#include "book.h"
#include "user.h"

using namespace std;

class Library
{
public:
    Library ();
    ~Library () {};
    void addBook(const Book &newBook);
    void addUser(const User &newUser);
    Book &searchBook(const string bookName);
    User &searchUser(const long userId);

private:
    std::map<long, User> m_userList;
    std::map<std::string, Book> m_bookList;

    fstream& loadFile(std::string fname);
    template <class T> void add(const string fname, const T &newThing);
};

#endif
