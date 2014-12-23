#include <iomanip>
#include "book.h"

Book::Book()
{
    m_id = 0L;
    m_name = "";
    m_isbn = "";
    m_writer = "";
    m_publisher = "";
    m_total = 0;
    m_remain = 0;
}


Book::Book (string &name, string &isbn, string &writer, string &publisher, int total)
    : m_name(name), m_isbn(isbn), m_writer(writer), m_publisher(publisher), m_total(total)
{
    m_remain = m_total;
}


bool Book::borrow(long uid)
{
    map<long, time_t>::iterator it = m_borrowers.find(uid);
    m_remain--;
    if (it == m_borrowers.end() && m_remain != 0) {
        m_borrowers[uid] = getCurrentTime();
        return true;
    }
    return false;
}


void Book::ret(long uid)
{
    map<long, time_t>::iterator it = m_borrowers.find(uid);
    if (it != m_borrowers.end()) {
        m_borrowers.erase(it);
    }
    if (m_remain < m_total)
        m_remain++;
}


std::ostream& operator<<(std::ostream& os, Book& book)
{
    os.setf(ios::left);
    os << setw(5) << book.m_id
        << setw(20) << book.m_name
        << setw(15) << book.m_writer
        << setw(14) << book.m_isbn
        << setw(16) << book.m_publisher
        << setw(2) << book.m_total
        << setw(2) << book.m_remain;
    return os;
}


std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << book.m_id << " "
        << book.m_name << " "
        << book.m_writer << " "
        << book.m_isbn << " "
        << book.m_publisher << " "
        << book.m_total;
    return os;
}


std::istream& operator>>(std::istream& is, Book& book)
{
    is >> book.m_id >> book.m_name >> book.m_writer >> book.m_isbn
        >> book.m_publisher >> book.m_total;
    book.m_remain = book.m_total;
    return is;
}
