// Constructors & Assignment – Summary:

// ✅ Default Constructor
// Called when: MyString s;
// Implicitly generated if: No constructor is defined
// Must define explicitly if: Any other constructor exists (e.g., parameterized), and you still want default

// ✅ Parameterized Constructor
// Called when: MyString s("text");
// If only this is defined, default constructor is NOT generated

// ✅ Copy Constructor
// Called when: MyString s2 = s1;
// Implicitly generated: Yes, does shallow copy (bitwise copy)
// Define explicitly: When the class has raw pointers or dynamic resources
// If move ctor/assign are defined, copy ctor/assign are NOT suppressed

// ✅ Move Constructor
// Called when: MyString s2 = std::move(s1);
// Implicitly generated: Yes (C++11+) if no copy/move user-defined
// Define explicitly: For performance and resource stealing

// ✅ Copy Assignment
// Called when: s2 = s1;
// Implicitly generated: Yes
// Define explicitly: When managing dynamic memory

// ✅ Move Assignment
// Called when: s2 = std::move(s1);
// Implicitly generated: Yes (C++11+) if no user-defined copy/move
// Fallback: If move assignment not defined, falls back to copy assignment

// ✅ Destructor
// Called when: Object goes out of scope
// Implicitly generated: Yes
// Must define: When class manages dynamic memory (delete[] or delete)


// Rule of 3: If your class defines any of the following, define all 3:
// - Destructor
// - Copy Constructor
// - Copy Assignment Operator

// Rule of 5 (C++11 and beyond): Also define:
// - Move Constructor
// - Move Assignment Operator


// std::move(obj) does NOT force move constructor/operator
// It gives permission to move — compiler chooses best match

// If move constructor/operator is NOT available:
//   => Falls back to copy constructor/operator (if available)

// If neither copy nor move assignment is available:
//   => Compilation error when assigning

#include <iostream>
#include <cstring>

class MyString{
private:
    char* data;
public:
    //constructor
    MyString(const char* str = ""){
        data = new char[std::strlen(str)+1];
        std::strcpy(data,str);
        std::cout << "Constructor called" << std::endl;
    }
    void printData()
    {
        std::cout << data << std::endl;
    }
    //copy constructor
    MyString(const MyString& other)
    {
        data = new char[std::strlen(other.data)+1];
        std::strcpy(data, other.data);
        std::cout << "Copy Constructor called" << std::endl;
    }

    //copy assignment operator
    MyString& operator=(const MyString& other)
    {
        std::cout << "Copy Assignment Operator called" << std::endl;
        if(this != &other)
        {
            delete[] data;
            data = new char[std::strlen(other.data)+1];
            std::strcpy(data, other.data);
        }
        return *this;
    }

    //move constructor
    MyString(MyString&& other) noexcept
    {
        data = other.data;
        other.data = nullptr;
        std::cout <<"Move Constructor called" << std::endl;
    }

    //move assignment operator
    MyString& operator=(MyString&& other) noexcept
    {
        std::cout <<"Move Assignment Operator called" << std::endl;
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    //length of string
    size_t length() const{
        return strlen(data);
    }

    //indexing operator
    char& operator[](size_t index)
    {
        return data[index];
    }

    //C-style copy like strcpy
    void copy(const MyString& other)
    {
        delete[] data;
        data = new char[std::strlen(other.data)+1];
        std::strcpy(data, other.data);
    }

    //Equality operator
    bool operator==(const MyString& other)
    {
        return strcmp(data, other.data) == 0;
    }

    //stream insertion
    friend std::ostream& operator<<(std::ostream& os, const MyString& other)
    {
        os << other.data;
        return os;
    }

    //stream extraction
    friend std::istream& operator>>(std::istream& is, MyString& other)
    {
        std::string temp;
        is >> temp; // safely read input into std::string
        delete[] other.data;
        other.data = new char[temp.size() + 1];
        std::strcpy(other.data, temp.c_str());
        return is;
    }

    //destructor
    ~MyString(){
        delete[] data;
        std::cout << "Destructor called" << std::endl;
    }

};

int main()
{
    MyString s1 = "Hello"; //parameterized constructor called
    MyString s2 = s1; //copy construcor called, if copy constructor is not defined, will get free(): double free detected
    s2.printData(); 
    MyString s3;
    s3 = s2; //assignment operator called, if copy assignment operator is not defined, will get free(): double free detected
    MyString s4 = std::move(s3); //move constructor called if defined, otherwise as fallback copy constructor will be called
    std::cout << "=========="<<std::endl;
    MyString s5;
    s5 = std::move(s3); //move assignment operator called if defined, otherwise as fallback copy assignment operator will be called
}