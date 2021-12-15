#include <iostream>
#include <cassert>
#include "Ring.h"
using namespace std;

void test1()
{
    Ring<int, string> R;
    R.is_empty();
    assert(R.amount() == 0);
}

void test2()
{
    Ring<int, int> R;
    R.insert(1, 1);
    R.insert(2, 21);
    R.insert(3, 321);
    R.insert(4, 4321);
    //R.insertFront(2, 1);
    R.print();
}

void test3()
{
    Ring<int, int> R;
    R.insert(1, 1);
    R.insert(2, 1);
    R.insert(3, 1);
    Ring<int, int> R1(R);
    R1.print();

}

int main()
{
    test1();
    test2();
    //test3();
    return 0;
}