#include "library.h"


Library::Library()
{
    Book book;
    User user;
    User superuser(-1L);
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open()) {
        while (fin >> book)
            m_bookList[book.name()] = book;
    }
    else {
        cerr << "data.txt doesn't exist. Abort!" << endl;
        exit(1);
    }
    fin.close();
    fin.open("user.txt", ios::in);
    if (fin.is_open()) {
        while (fin >> user)
            m_userList[user.id()] = user;
    }
    else {
        cerr << "user.txt doesn't exist." << endl;
    }
    m_userList[superuser.id()] = superuser;
    fin.close();
}


template <class T>
void Library::add(const string fname, const T &newThing)
{
    ofstream fout;
    fout.open(fname, ios::out|ios::app);
    if (fout.is_open()) {
        fout << newThing << endl;
    }
    else {
        cerr << fname << " doesn't exist." << endl;
        exit(1);
    }
    fout.close();
}


void Library::addBook(const Book &newBook)
{
    add("data.txt", newBook);
}


void Library::addUser(const User &newUser)
{
    add("user.txt", newUser);
}

bool Library::searchBook(const string bookName, Book &theBook)
{
    map<string, Book>::const_iterator it = m_bookList.find(bookName);
    // Found book
    if (it != m_bookList.end()) {
        theBook = it->second;
        return true;
    }
    return false;
}


bool Library::searchUser(const long userId, User &theUser)
{
    map<long, User>::const_iterator it = m_userList.find(userId);
    // Found user
    if (it != m_userList.end()) {
        theUser = it->second;
        return true;
    }
    return false;
}
