//doubly linked list

#include <iostream>

using namespace std;

/**
* Creates a structure for the elements of the list (information and pointers to previous and next element)
*/

struct DListElem {
    int info;
    DListElem* next;
    DListElem* prev;
};

/**
* Creates a structure for the pointers to the first and last element of the list
*/

struct DList {
    DListElem* first;
    DListElem* last;
};

/**
* Initializes the list
* @param dl The default name of the list
*/
void initializeDList (DList & dl) {
    dl.first = nullptr;
    dl.last = nullptr;
}

/**
* Checks if the list is empty
* @param dl The default name of the list
* @return returns if the list is empty or not
*/

bool isEmpty(DList dl){
  if (dl.first == nullptr) return true;
  return false;
}

/**
* Adds an element into the beginning of the list.
* @param dl The default name of the list
* @param val The value of the info of the new element
*/

void put (DList& dl, int val) {
    DListElem* temp = new DListElem;
    temp->info = val;
    if (isEmpty(dl)){
      dl.first = temp;
      dl.last = temp;
    }
    else {
      dl.first->prev = temp;
      dl.first->prev->next = dl.first;
      dl.first = temp;
    }
}

/**
* Removes the last element in the list
* @param dl The default name of the list
* @param val The reference to the value of the element being removed
* @return Returns if it was possible to remove the last item (If the list was empty already or not)
*/

bool get (DList& dl, int &val){
  if (isEmpty(dl)) return false;
  if (dl.first == dl.last){val = dl.last-> info; delete dl.last; return true;}
    DListElem* temporary = new DListElem;
    dl.last->prev->next = nullptr;
    temporary = dl.last->prev;
    val = dl.last->info;
    delete dl.last;
    dl.last = temporary;
    return true;
}




int main(int argc, char* argv[])
{
  DList queue;

  initializeDList(queue);

  //insert 5 values
  for (int i = 1; i <= 5; i++) {
    cout << "put: " << 10 * i << endl;
    put(queue, 10 * i);
  }

  //remove 3 values and print them to console
  for (int j = 1; j <= 3; j++) {
    int value;
    if (get(queue, value))
       cout << "     get: " << value << endl;
  }

 // cout << "Laenge: " << dlistLength(queue) << endl;
  
  //insert 5 values 
  for (int i = 6; i <= 10; i++) {
    cout << "put: " << 10 * i << endl;
    put(queue, 10 * i);
  }

 // cout << "Laenge: " << dlistLength(queue) << endl;

  //remove all values and print them
  while(!isEmpty(queue)) {
    int value;
    get(queue, value);
    cout << "     get: " << value << endl;
  }

  cin.sync(); cin.get();
  return 0;
}
