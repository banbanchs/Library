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


std::ostream& operator<<(std::ostream& os, Book& book)
{
    os << book.m_id << "\t"
        << book.m_name << "\t"
        << book.m_isbn << "\t"
        << book.m_writer << "\t"
        << book.m_publisher << "\t"
        << book.m_total << "\t"
        << book.m_remain;
    return os;
}


std::istream& operator>>(std::istream& is, Book& book)
{
    is >> book.m_id >> book.m_name >> book.m_writer >> book.m_isbn
        >> book.m_publisher >> book.m_total >> book.m_remain;
    return is;
}
