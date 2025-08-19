/*std::shared_ptr is one of the smart pointers introduced in C++11. Unlike a simple pointer, it 
has an associated control block that keeps track of the reference count for the managed object. 
This reference count is shared among all the copies of the shared_ptr instances pointing to the 
same object, ensuring proper memory management and deletion.*/

#include <iostream>

using namespace std;

template <typename T>
class Shared_ptr
{
private:
    T* ptr;             // Raw pointer to the actual object
    int* refCount;      // Pointer to shared reference count

public:
    Shared_ptr(T* p = nullptr)
    {
        ptr = p;
        if(p)
            refCount = new int(1);
        else
            refCount = nullptr;
    }
    //copy constructor
    Shared_ptr(const Shared_ptr<T>& other)
    {
        ptr = other.ptr;
        refCount = other.refCount;
        if(refCount)
            ++(*refCount);
    }
    //Assignment operator
    Shared_ptr<T>& operator=(const Shared_ptr<T>& other)
    {
        if(this != &other){
            //decrease old reference count
            release();

            //copy from other
            ptr = other.ptr;
            refCount = other.refCount;
            if(refCount)
                ++(*refCount);
        }
        return *this;
    }

    ~Shared_ptr()
    {
        release();
    }

    //Access operators
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    //get raw pointer
    T* get() const { return ptr; }

    //use count
    int use_count() const {
        return refCount ? *refCount : 0;
    }

private:
    void release() {
        if(refCount)
        {
            --(*refCount);
            if(*refCount == 0) {
                delete ptr;
                delete refCount;
            }
            refCount = nullptr;
            ptr = nullptr;
        }
    }

};