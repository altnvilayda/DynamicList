#include <iostream>
#include "dynamicList.h"

using namespace std;

int main()
{


    dynamicList dynList;
    dynList.insertItemDesc(5);
    dynList.insertItemDesc(10);
    dynList.insertItemDesc(6);
    dynList.insertItemDesc(7);
    dynList.insertItemDesc(4);
    dynList.printList();
    dynList.removeItem(10);
    dynList.printList();

/*
    dynamicList dynList2;
    dynList2.insertItemAsc(5);
    dynList2.insertItemAsc(10);
    dynList2.insertItemAsc(6);
    dynList2.insertItemAsc(7);
    dynList2.insertItemAsc(4);

    dynList2.printList();
    cout << "6 degerini arayalim: "<< " " << dynList2.searchItem(6)->item << endl;

*/

    dynamicList dynList3;
    dynList3.removeItem(5);

    dynList3.printList();


    return 0;
}
