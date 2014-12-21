#include <cstdio>
#include <limits>
#include "manager.h"


Manager::Manager()
{
    m_user = new User();
}


Manager::~Manager()
{
    delete m_user;
}


void Manager::login()
{
    long uid;
    cout << "请输入登陆用户的学号：" << endl;
    cin >> uid;
    bool status = m_lib.searchUser(uid, *m_user);
    // login success
    if (status) {
        cout << "你好！" << m_user->name() << endl;
        getchar();
    }
    else {
        cout << "用户不存在" << endl;
    }
}


void Manager::addBook()
{
    char ch;
    if (m_user->id() != 9999) {
        cerr << "只有管理员才有权限添加图书!" << endl;
        cerr << "输入任意键继续" << endl;
        // Clear stdin
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        getchar();
        return;
    }
    do {
        Book newBook;
        cout << "请依次输入以下信息，用空格隔开" << endl;
        cout << "编号 图书名称 作者 ISBN 出版社 图书总数量" << endl;
        cin >> newBook;
        m_lib.addBook(newBook);
        cout << "添加成功！" << endl;
        cout << endl;
        cout << "继续吗? (y/n)  ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}


void Manager::delBook()
{
    string bookName;
    char ch;
    if (m_user->id() != 9999) {
        cerr << "只有管理员才有权限添加图书!" << endl;
        cerr << "输入任意键继续" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        getchar();
        return;
    }
    do {
        cout << "请输入图书名称" << endl;
        cin >> bookName;
        m_lib.delBook(bookName);
        cout << "删除成功！" << endl;
        cout << endl;
        cout << "继续吗? (y/n)  ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}


int Manager::showMenu()
{
    int input = 0;
    // clear screen
#ifdef __linux__
    printf("\033[2J");
#else
    system("cls");
#endif
    string dash(51, '*');
    string line = "*                                                 *";

    // show menu
    cout << dash << endl;
    cout << "*                 图书管理系统                    *" << endl;
    cout << line << endl;
    cout << line << endl;
    cout << line << endl;
    cout << "*     1添加图书            5查看所有书籍          *" << endl;
    cout << line << endl;
    cout << "*     2删除图书            6搜索                  *" << endl;
    cout << line << endl;
    cout << "*     3借书                7登陆                  *" << endl;
    cout << line << endl;
    cout << "*     4还书                                       *" << endl;
    cout << line << endl;
    cout << "*     0退出                                       *" << endl;
    cout << dash << endl;
    cin >> input;
    return input;
}


void Manager::run()
{
    int input = 1;
    while (input != 0) {
        input = showMenu();
        switch(input) {
            // Quit
            case 0:
                return;

            // Add Book
            case 1:
                addBook();
                break;

            // Delete book
            case 2:
                delBook();
                break;

            // Borrow book
            case 3:
                break;

            // Return book
            case 4:
                break;

            // Show all books
            case 5:
                break;

            // Search book
            case 6:
                break;

            // Login
            case 7:
                login();
                break;

            // Delete user
            case 8:
                break;
        }
    }
}
