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
        // Clear stdin
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
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
        cerr << "只有管理员才有权限删除图书!" << endl;
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


void Manager::searchBook()
{
    Book theBook;
    string bookName;
    char ch;
    do {
        cout << "请输入图书名称" << endl;
        cin >> bookName;
        m_lib.searchBook(bookName, theBook);
        if (theBook.id() == 0)
            cout << "图书不存在" << endl;
        else {
            cout << "编号\t书名\t作者\t\tISBN\t\t出版社\t\t总数\t剩余数量" << endl;
            cout << theBook << endl;
        }
        cout << endl;
        cout << "继续吗? (y/n)  ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
}


void Manager::delUser()
{
    long uid;

    if (m_user->id() != 9999) {
        cerr << "只有管理员才有权限删除用户!" << endl;
        cerr << "输入任意键继续" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        getchar();
        return;
    }

    cin >> uid;
    m_lib.delUser(uid);
    cout << "用户已删除" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    getchar();
    return;
}


void Manager::addUser()
{
    User newUser;
    cout << "请依次输入：学号 用户名 性别（男1 女0）" << endl;
    cin >> newUser;
    m_lib.addUser(newUser);
    cout << "成功注册！" << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    getchar();
    return;
}


void Manager::borrowBook()
{
    Book book;
    string bookName;
    if (m_user->id() == 0) {
        cout << "借书前请先登陆" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        getchar();
        return;
    }
    cout << "请输入书名" << endl;
    cin >> bookName;
    if (m_lib.searchBook(bookName, book)) {
        bool status = m_lib.borrowBook(*m_user, book);
        if (status)
            cout << "成功借走:" << bookName << endl;
        else
            cout << "这本书已经被人借走了！" << endl;
    }
    else {
        cout << "图书不存在" << endl;
    }
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    getchar();
    return;
}


void Manager::returnBook()
{
    Book book;
    string bookName;
    if (m_user->id() == 0) {
        cout << "还书前请先登陆" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        getchar();
        return;
    }
    cout << "请输入书名" << endl;
    cin >> bookName;
    if (m_lib.searchBook(bookName, book)) {
        m_lib.retBook(*m_user, book);
        cout << "成功还书" << endl;
    }
    else {
        cout << "图书不存在" << endl;
    }
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    getchar();
    return;
}


void Manager::showAllBook()
{
    vector<Book> bl;
    m_lib.sortBook(bl);
    cout << "编号\t书名\t作者\t\tISBN\t\t出版社\t\t总数\t剩余数量" << endl;
    for (auto i : bl)
        cout << i << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    getchar();
    return;
}


void Manager::showAllBorrowBook()
{
    if (m_user->id() == 0) {
        cout << "请先登陆" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        getchar();
        return;
    }
    else if (m_user->m_books.size() == 0) {
        cout << "没有借阅书籍" << endl;
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        getchar();
        return;
    }
    list<string>::const_iterator it = m_user->m_books.begin();
    Book book;
    cout << "编号\t书名\t作者\t\tISBN\t\t出版社\t\t总数\t剩余数量" << endl;
    while (it != m_user->m_books.end()) {
        m_lib.searchBook(*it, book);
        cout << book << endl;
        ++it;
    }
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    getchar();
    return;
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
    cout << line << endl;
    cout << "*                 图书管理系统                    *" << endl;
    cout << line << endl;
    cout << line << endl;
    cout << "*     1添加图书            5查看所有书籍          *" << endl;
    cout << line << endl;
    cout << "*     2删除图书            6搜索                  *" << endl;
    cout << line << endl;
    cout << "*     3借书                7登陆                  *" << endl;
    cout << line << endl;
    cout << "*     4还书                8注册                  *" << endl;
    cout << line << endl;
    cout << "*                          9查看借阅              *" << endl;
    if (m_user->id() == 9999) {
        cout << line << endl;
        cout << "*                          10删除用户             *" << endl;
    }
    cout << line << endl;
    cout << "*     0退出                                       *" << endl;
    cout << line << endl;
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
                borrowBook();
                break;

            // Return book
            case 4:
                returnBook();
                break;

            // Show all books
            case 5:
                showAllBook();
                break;

            // Search book
            case 6:
                searchBook();
                break;

            // Login
            case 7:
                login();
                break;

            // Register
            case 8:
                addUser();
                break;

            // All borrow books
            case 9:
                showAllBorrowBook();
                break;

            // Delete user
            case 10:
                delUser();
                break;

            // Invalid input
            default:
                break;
        }
    }
}
