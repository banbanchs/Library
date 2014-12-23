#include <algorithm>
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


Library::~Library()
{
    saveBookList();
    saveUserList();
}


void Library::saveUserList()
{
    save("user.txt", m_userList);
}


void Library::saveBookList()
{
    // FIXME: backup data before save new data.
    save("data.txt", m_bookList);
}


void Library::sortBook(vector<Book> &bookList)
{
    for (map<string, Book>::const_iterator it = m_bookList.begin();
            it != m_bookList.end(); ++it) {
        bookList.push_back(it->second);
    }
    sort(bookList.begin(), bookList.end(), [](const Book &a, const Book &b) -> bool {
            return a.id() < b.id();
            });
}


void Library::addBook(const Book &newBook)
{
    // FIXME: throw error when book already exist
    m_bookList[newBook.name()] = newBook;
}


void Library::addUser(const User &newUser)
{
    // FIXME: throw error when user already exist
    m_userList[newUser.id()] = newUser;
}


void Library::delBook(const string bookName)
{
    map<string, Book>::iterator it = m_bookList.find(bookName);
    if (it != m_bookList.end()) {
        m_bookList.erase(it);
    }
}


void Library::delUser(const long userId)
{
    map<long, User>::iterator it = m_userList.find(userId);
    if (it != m_userList.end()) {
        m_userList.erase(it);
    }
}


bool Library::borrowBook(User &user, Book &book)
{
    bool status;
    status = book.borrow(user.id());
    if (status) {
        status = user.borrowBook(book.name());
    }
    m_bookList[book.name()] = book;
    if (status)
        return true;
    else
        return false;
}


void Library::retBook(User &user, Book &book)
{
    book.ret(user.id());
    user.retBook(book.name());
    m_bookList[book.name()] = book;
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
