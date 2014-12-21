#ifndef _MANAGER_H
#define _MANAGER_H

#include "library.h"

class Manager
{
public:
    Manager ();
    ~Manager ();

    void run();

    void login();
    int showMenu();
    void showAllBook();
    void showAllBorrowBook();

    void searchBook();
    void searchUser();

    void addBook();
    void delBook();
    void addUser();
    void delUser();

    void borrowBook();
    void returnBook();

private:
    Library m_lib;
    User *m_user;
};

#endif
