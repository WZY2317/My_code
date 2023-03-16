#include<iostream>
#include "test.h"
class A

{

public:

    A() :m_iVal(0) { test(); }

    virtual void func() { std::cout << m_iVal; }

    void test() { func(); }

public:

    int m_iVal;

};
class A1

{

public:

    A1() :m_iVal(0) { test(); }

    virtual void func() { std::cout << m_iVal; }

    void test() { func(); }

public:

    int m_iVal;

};



class B : public A  

{

public:

    B() { test(); }

    virtual void func()

    {

        ++m_iVal;

        std::cout << m_iVal;

    }

};
class B : public A1

{

public:

    B() { test(); }

    virtual void func()

    {

        ++m_iVal;

        std::cout << m_iVal;

    }
    virtual void j()
    {
        std::cout << "j()" << std::endl;
    }

};




int main(int argc, char* argv[])

{

    B b;

    return 0;

}