#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class my_string
{
public:
    // constructors
    my_string();

    // copy constructor
    my_string(const my_string& s);
    my_string(const char* s);
    // destructor
    ~my_string();
    bool equals(const my_string& s);
    unsigned int length() const;

    unsigned int capacity() const;

    my_string& append(const char* s);

    my_string& append(const my_string& s);

    my_string& assign(const char* s);

    my_string& assign(const my_string& s);

    my_string& replace(unsigned int pos, unsigned int len, const char* s);

    my_string& operator =(const char* s);

    my_string& operator =(const my_string& s);

    bool operator ==(const my_string& s);

    bool operator !=(const my_string& s);

    const char& at(const int __pos) const;

    const char& operator [](const int __pos) const;

    friend basic_ostream<char>&
    operator <<(basic_ostream<char>& __os, const my_string& __str);

private:
    unsigned int _capacity = 5;
    unsigned int _length = 0;
    char *_buf = new char[_capacity + 1];

    void _M_construct(const char* __s, unsigned int __n);

    char* _create(unsigned int& __capacity, unsigned int __old_capacity);

    my_string& _replace(unsigned int __pos, unsigned int __len1, const char* __s,
                        unsigned int __len2);

    void _set_capacity(const unsigned int __n);

    void _set_length(const unsigned int __n);

    void _data(char * _buf);

    void _dispose();

    my_string& _append(const char* __s, unsigned int __n);

    my_string& _append(const my_string& __s);

    void _assign(const char* __s, unsigned int __n);

    void _copy(char* __d, const char* __s, unsigned int __n);

    void _mutate(const char* __s, unsigned int __n);
};

my_string operator +(my_string& lhs, const my_string& rhs);

my_string operator +(my_string& lhs, const char* rhs);

basic_ostream<char>&
operator <<(basic_ostream<char>& __os, const my_string& __str);
