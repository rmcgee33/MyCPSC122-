#include <iostream>
using namespace std;

#include "3-ListT.h"

int main()
{
    ListT lst;
    ListT* lst1 = new ListT;

    cout << "Test Dynamic Insert and Print" << endl;
    cout << "Correct if out is 4, 3, 2, 1, 0 on subsequent lines" << endl;
    for (int i = 0; i < 5; i++)
    {
        lst1->PutItemH(i);
    }

    lst1->PutItemH(2);
    lst1->PutItemT(2);
    lst1->PutItemT(2);

    lst1->Print();
    cout << endl;
    lst1->DeleteItem(2);
    lst1->Print();

    //lst1->~ListT();
    //delete lst1; //necessary to invoke destructor on dynamic list
    cout << endl;
    return 0;
}
