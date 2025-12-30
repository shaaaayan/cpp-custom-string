#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <stdexcept>

class MyString {
private:
    char* _data;      
    size_t _size;     
    size_t _capacity; 
    void resize(size_t new_capacity);
    static size_t my_strlen(const char* str);          
    static void my_strcpy(char* dest, const char* src); 
    static char* my_strstr(const char* haystack, const char* needle); 

public:
    MyString();                       
    MyString(const char* str);        
    MyString(const MyString& other);  
    ~MyString();                      
    MyString& operator=(const MyString& other); 
    MyString& operator+=(const MyString& other); 
    int find(const MyString& substring, size_t pos = 0) const; 
    size_t size() const { return _size; } 
    size_t length() const { return _size; } 
    size_t capacity() const;
    const char* data() const { return _data; } 
    bool empty() const { return _size == 0; } 
    const char& at(size_t pos) const;  
    char& at(size_t pos);              
    const char& front() const;         
    void clear();                      
    friend bool operator==(const MyString& lhs, const MyString& rhs); 
    friend MyString operator+(const MyString& lhs, const MyString& rhs); 
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
};

#endif
