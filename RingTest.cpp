#include <iostream>
#include <cassert>
#include "Ring.h"
using namespace std;

void test1()
{
    Ring<int, string> R;
    assert(R.amount() == 0);
    assert(R.is_empty() == true);
}

void test2()
{
    Ring<int, int> R;
    R.insert(1, 1);
    R.insert(2, 21);
    R.insert(3, 321);
    R.insert(4, 4321);
    assert(R.amount() == 4);
}

void test3()
{
    Ring<int, int> R;
    R.insert(1, 1);
    R.insert(2, 1);
    R.insert(3, 1);
    Ring<int, int> R1(R);
    assert(R1.amount() == 3);
}

void test4()
{
    Ring<int, int> R;
    R.insert(1, 2);
    R.insert(2, 2);
    R.insert(3, 2);
    R.remove();
    assert(R.amount() == 2);
}

void test5()
{
    Ring<int, int> R;
    R.insert(1, 3);
    R.insert(2, 3);
    R.insert(3, 3);
    R.removeAll();
    assert(R.amount() == 0);
}

void test6()
{
    Ring<int, int> R;
    R.insert(5, 1);
    R.insert(4, 1);
    R.insert(3, 1);
    R.insert(2, 1);
    R.insert(1, 1);
    Ring<int, int> r1;
    Ring<int, int> r2;
    split_pos(R, 1, true, 4, r1, 2, true, r2, 1, false);
    R.print();
    cout<< "" << endl; 
    r1.print();
    cout<< "" << endl;
    r2.print();
}

void test7()
{
    Ring<int, int> R;
    R.insert(5, 1);
    R.insert(4, 1);
    R.insert(3, 1);
    R.insert(2, 1);
    R.insert(1, 1);
    Ring<int, int> r1;
    Ring<int, int> r2;
    split_key(R, 2, 10, true, 4, r1, 2, true, r2, 1, false);
    R.print();
    cout<< "" << endl; 
    r1.print();
    cout<< "" << endl;
    r2.print();
}



int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    test7();
    return 0;
}