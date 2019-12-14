#include <iostream>
#include <cstring>
#include <algorithm>
#include "my_string.hpp"

using namespace std;

my_string::my_string() {}


my_string::my_string(const char* s){
 _M_construct(s, strlen(s));}



bool my_string::equals(const my_string& s){
        if (this->length()==s.length()){
                for(int i=0; i<this->length(); i++){
                        if(this->at(i)!=s[i]){
                                return false;}

                }
                return true;
        }
        return false;
}





my_string::my_string(const my_string& s) {
    _M_construct(s._buf, s.length());
}

my_string::~my_string() {
    delete [] _buf;
}

unsigned int my_string::length() const {
    return _length;
}

unsigned int my_string::capacity() const {
    return _capacity;
}

my_string& my_string::append(const char* s) {

    return _append(s, strlen(s));
}

my_string& my_string::append(const my_string& s) {
    return _append(s);
}

my_string& my_string::assign(const char* s) {
    _assign(s, strlen(s));
    return *this;
}

my_string& my_string::assign(const my_string& s) {
    assign(s._buf);
    return *this;
}

my_string& my_string::replace(unsigned int pos, unsigned int len, const char* s) {
    return _replace(pos, len, s, strlen(s));
}

bool my_string::operator ==(const my_string& s){
   return equals(s);
}

bool my_string::operator !=(const my_string& s){
   return !equals(s);
}

my_string& my_string::operator =(const char* s) {
    return assign(s);
}

my_string& my_string::operator =(const my_string& s) {
    return assign(s._buf);
}

const char& my_string::at(const int __pos) const {
    return _buf[__pos];
}

const char& my_string::operator [](const int __pos) const {
    return at(__pos);
}

void my_string::_M_construct(const char* __s, unsigned int __n) {
    if (__n > _capacity) {
     _dispose();
        _data(_create(__n, _capacity));
        _set_capacity(__n);
    }

    if (__n > 0) this->_assign(__s, __n);

    _set_length(__n);
}

char* my_string::_create(unsigned int& __capacity, unsigned int __old_capacity) {
    if (__capacity > __old_capacity) {
        while (__capacity < 2 * __old_capacity) {
            __capacity = 2 * __old_capacity;
        }
    }

    return new char[__capacity];
}

my_string& my_string::_replace(unsigned int __pos, unsigned int __len1, const char* __s,
                               unsigned int __len2) {
    const unsigned int __old_size = length();
    const unsigned int __min_len = min(__len1, __len2);
    const unsigned int __new_size = max(__old_size, __pos + __min_len);

    if (__new_size < capacity()) {
        for (unsigned int i = 0; i < __min_len; i++) {
            _buf[__pos + i] = __s[i];
        }
    }

    return *this;
}

void my_string::_set_capacity(const unsigned int __n) {
    _capacity = __n;
}

void my_string::_set_length(const unsigned int __n) {
    _length = __n;
}

void my_string::_data(char * _buf) {
    this->_buf = _buf;
}
void my_string::_dispose() {
    delete [] _buf;
}

my_string& my_string::_append(const char* __s, unsigned int __n) {
    const unsigned int __len = __n + length();

    if (__len < capacity()) {
        if (__n > 0)
            _copy(_buf + length(), __s, __n);
    }
    else {
        _mutate(__s, __n);
    }

    _set_length(__len);
    return *this;
}

my_string& my_string::_append(const my_string& __s) {
    unsigned int __n = __s.length();
    return _append(__s._buf, __n);
}

void my_string::_assign(const char* __s, unsigned int __n) {
    for (unsigned int i = 0; i < __n; i++) {
        _buf[i] = __s[i];
    }
    _buf[__n] = '\0';
    this->_length = __n;
}

void my_string::_copy(char* __d, const char* __s, unsigned int __n) {
    for (unsigned int i = 0; i < __n; i++) {
        __d[i] = __s[i];
    }
    __d[__n] = '\0';
}

void my_string::_mutate(const char* __s, unsigned int __n) {
    unsigned int __new_capacity = length() + __n + 1;
    char *__new_buf = _create(__new_capacity, capacity());
    if (length() > 0)
        _copy(__new_buf, _buf, length());
    if (__s != NULL && __n > 0)
        _copy(__new_buf + length(), __s, __n);

    *(__new_buf + length() + __n) = '\0';

    _dispose();
    _data(__new_buf);
    _set_capacity(__new_capacity);
    _set_length(length() + __n);
}

my_string operator +(my_string& lhs, const my_string& rhs) {
    return lhs.append(rhs);
}

my_string operator +(my_string& lhs, const char* rhs) {
    return lhs.append(rhs);
}

basic_ostream<char>&
operator <<(basic_ostream<char>& __os, const my_string& __str) {
    return __ostream_insert(__os, __str._buf, __str.length());
}
