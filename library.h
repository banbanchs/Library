#ifndef _LIBRARY
#define _LIBRARY

#include <vector>
#include <map>
#include <fstream>

#include "book.h"
#include "user.h"

using namespace std;

class Library
{
public:
    Library ();
    ~Library ();
    void addBook(const Book &newBook);
    void addUser(const User &newUser);

    void delBook(const string bookName);
    void delUser(const long userId);

    bool searchBook(const string bookName, Book &theBook);
    bool searchUser(const long userId, User &user);

    void sortBook(vector<Book> &bookList);
    bool borrowBook(User &user, Book &book);
    void retBook(User &user, Book &book);

private:
    std::map<long, User> m_userList;
    std::map<std::string, Book> m_bookList;

private:
    template <class Key, class Value>
        void save(const string fname, const map<Key, Value> &list) {
            ofstream fos;
            fos.open(fname, ios::out|ios::trunc);
            if (fos.is_open()) {
                for (auto it = list.begin(); it != list.end(); ++it)
                    fos << it->second << endl;
            }
        }
    void saveUserList();
    void saveBookList();
};

#endif
