#include "dynamicList.h"
#include <string>
#include <iostream>
#define NULL 0

using namespace std;

dynamicList::dynamicList(){

    listHead = NULL;
    //ctor
}
void dynamicList::insertItemDesc(int item){

   if(listHead == NULL) {
     listHead = new listItem;
     listHead->item = item;
     listHead->next = NULL;

   } else {
      listItem *newItem = new listItem;
      newItem->item = item;

      listItem *currentListItem = listHead;
      if(currentListItem->next == NULL) { //we have one item in the list
         if(currentListItem->item < item){
            newItem->next = currentListItem;
            listHead = newItem;
         } else {
             currentListItem->next = newItem;
         }
         return;
      }

      //Move the currentItem pointer until the correct item is found
      //currentItem pointeri dogru noktaya tasi
      while(currentListItem->next != NULL && currentListItem->next->item > item ){
        currentListItem = currentListItem->next;
      }

      //Eger hala liste basindaysan liste basina ekle ve liste basi pinterini guncelle
      if(currentListItem->item <= item && currentListItem == listHead){
        newItem->next = currentListItem;
        listHead = newItem;
      } else{
        if(currentListItem->next != NULL){//Check if we are at the end of the list, if not insert in the middle.
           newItem->next = currentListItem->next;
        }
        currentListItem->next = newItem;
      }
   }
}


void dynamicList::insertItemAsc(int item)       //kucukten buyuge
{
    if(listHead == NULL)
    {
        listHead = new listItem;
        listHead->item = item;
        listHead->next = NULL;
        return;
    }

    //liste tek elemanlı ise:
    if(listHead->next == NULL)
    {
        listItem* newNode = new listItem;
        newNode->item = item;
        if(listHead->item < newNode->item)
        {
            newNode->next = listHead->next;
            listHead->next = newNode;
            return;
        }
        else
        {
            newNode->next = listHead;
            listHead = newNode;
            return;
        }
     }

    //2 veya daha fazla elemanlı ise:
    listItem* previous = listHead;
    listItem* current = previous->next;

    // ilk sıraya mı yerleşecek:
    if(previous->item >= item)
    {
        listItem* temp = new listItem;
        temp->item     = item;
        listHead       = temp;
        temp->next     =previous;
        return;
    }


    while(current != NULL)
    {
        if(previous->item <= item  && item <= current->item)
        {
            listItem* temp = new listItem;
            temp->item     = item;
            previous->next = temp;
            temp->next     = current;
            return;
        }

        previous= previous->next;
        current = current->next;


    }

}


void dynamicList::removeItem(int item)
{
    if(listHead == NULL)
    {
        cout << "List is empty !" << endl;
		return;
    }

    //ilk eleman mı silinecek?
    if(item == listHead->item)
    {
        listItem* currentListItem = listHead;
        listHead = listHead->next;
        delete currentListItem;
        return;
    }

    listItem* previous = listHead;
    while(previous->next != NULL)
    {
        if(previous->next->item == item)
        {
            listItem* temp = previous->next;
            previous->next = previous->next->next;
            delete temp;
            return;
        }
        previous = previous->next;
    }

    cout<< "Silinmesi istenilen deger bulunamadi.." << endl;


}

void dynamicList::printList()
{

    if(listHead == NULL)
    {
        cout << "liste bos." << endl;
    }

    listItem *first = listHead;
    while(first != NULL)
    {
        cout << first->item << " " ;
		first = first->next;
    }
    cout << endl;
}

listItem* dynamicList::searchItem(int item)
{
    //liste bos mu?
    if(listHead == NULL)
    {
        cout << "List is empty !" << endl;
        return NULL;
    }
    listItem* current = listHead;
    while(current != NULL )
    {
        if(current->item == item)
        {
            return current;
        }
        current = current->next;
    }
    cout << "Aranan deger bulunamadi..." << endl;

}
void dynamicList::removeList()
{
    while(listHead != NULL)
    {
        listItem* temp = listHead;
        listHead = listHead->next;
        delete temp;
    }
}

dynamicList::~dynamicList(){
    //Butun listeyi sil Burada!!!


    cout << "Destructor cagrildi.." << endl;
    this->removeList();
    this->printList();


    //dtor
}
