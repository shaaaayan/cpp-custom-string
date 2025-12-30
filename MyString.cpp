#include "MyString.h"
#include <stdexcept>

size_t MyString::my_strlen(const char* str) {
    size_t length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}
void MyString::my_strcpy(char* dest, const char* src) {
    while ((*dest++ = *src++) != '\0') {}
}
char* MyString::my_strstr(const char* haystack, const char* needle) {
    if (!*needle) return const_cast<char*>(haystack);
    for (const char* h = haystack; *h; ++h) {
        const char* h_it = h;
        const char* n_it = needle;
        while (*h_it && *n_it && *h_it == *n_it) {
            ++h_it;
            ++n_it;
        }
        if (!*n_it) return const_cast<char*>(h); 
    }
    return nullptr;
}
MyString::MyString() : _data(new char[1]), _size(0), _capacity(1) {
    _data[0] = '\0';
}
MyString::MyString(const char* str) : _data(nullptr), _size(0), _capacity(0) {
    if (str) {
        _size = my_strlen(str);
        _capacity = _size + 1;
        _data = new char[_capacity];
        my_strcpy(_data, str);
    }
}
MyString::MyString(const MyString& other)
    : _data(new char[other._capacity]), _size(other._size), _capacity(other._capacity) {
    my_strcpy(_data, other._data);
}
MyString::~MyString() {
    delete[] _data;
}
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _capacity = other._capacity;
        _data = new char[_capacity];
        my_strcpy(_data, other._data);
    }
    return *this;
}
MyString& MyString::operator+=(const MyString& other) {
    size_t new_size = _size + other._size;
    if (new_size + 1 > _capacity) resize(new_size + 1);
    my_strcpy(_data + _size, other._data);
    _size = new_size;
    return *this;
}
int MyString::find(const MyString& substring, size_t pos) const {
    if (pos >= _size) return -1; // Position out of bounds
    char* found = my_strstr(_data + pos, substring._data);
    return found ? found - _data : -1;
}
void MyString::resize(size_t new_capacity) {
    char* new_data = new char[new_capacity];
    if (_data) my_strcpy(new_data, _data);
    delete[] _data;
    _data = new_data;
    _capacity = new_capacity;
}
const char& MyString::front() const {
    if (empty()) throw std::out_of_range("MyString is empty");
    return _data[0];
}
const char& MyString::at(size_t pos) const {
    if (pos >= _size) throw std::out_of_range("MyString: Index out of range");
    return _data[pos];
}
char& MyString::at(size_t pos) {
    if (pos >= _size) throw std::out_of_range("MyString: Index out of range");
    return _data[pos];
}
void MyString::clear() {
    delete[] _data;
    _size = 0;
    _capacity = 1;
    _data = new char[_capacity];
    _data[0] = '\0'; 
}
size_t MyString::capacity() const {
    return _capacity;
}
bool operator==(const MyString& lhs, const MyString& rhs) {
    if (lhs._size != rhs._size) {
        return false;
    }
    for (size_t i = 0; i < lhs._size; ++i) {
        if (lhs._data[i] != rhs._data[i]) {
            return false;
        }
    }
    return true;
}
MyString operator+(const MyString& lhs, const MyString& rhs) {
    MyString result;
    result._size = lhs._size + rhs._size;
    result._capacity = result._size + 1;
    result._data = new char[result._capacity];
    MyString::my_strcpy(result._data, lhs._data);
    MyString::my_strcpy(result._data + lhs._size, rhs._data);
    return result;
}
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    if (str._data) os << str._data;
    return os;
}
