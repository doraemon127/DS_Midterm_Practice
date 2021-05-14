#include "dlist.h"

#include <iostream>


dlist::dlist() {
  head = NULL;
  tail = NULL;
}

dlist::~dlist() {
  while (head != NULL) {
    node* temp = head;
    head = head->next;
    delete temp;
  }
}

void dlist::build() {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  head = current;
  current->previous = NULL;
  node* previous = current;
  int additionalValues = (rand()&5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->previous = previous;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  tail = current;
  current->next = NULL;
}

void dlist::display() {
  node* current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

node* dlist::getHead() {
  return head;
}




//NOTE: doesn't work if first node is >9
void dlist::remove_greater_than_nine(node* current) {
  if (current == NULL) {
    return;
  }

  remove_greater_than_nine(current->next);

  if (!(current->data > 9)) {
    return;
  }
  else {
    node* temp = current;
    if (current->next != NULL) {
      current->next->previous = current->previous;
    }
    if (current->previous != NULL) {
      current->previous->next = current->next;
    }

    //error when first node > 9
    if (current && !current->previous) { //if current->previous == NULL
      current = current->next;
    }

    delete temp;
  }

  return;
} //end of function




/*
//function to remove every number greater than 9 from a doubly linked list
void dlist::remove_greater_than_nine (node* current)
{
  //base case
  if (current == NULL) {
    return;
  }
 
  if (current->data > 9) {
    node* temp = current;
    if (current == head) {
      current = current->next;
      current->previous = NULL;
    }
    if (current->previous != NULL) {
      current->previous->next = current->next;
    }
    if (current->next != NULL) {
      current->next->previous = current->previous;
    }
   
    delete temp;
  }

  remove_greater_than_nine(current->next);
     
} //end of function
*/



//remove nth node but not head or tail
void dlist::remove_nth_node(node* current, int pos) {

  if (current == NULL) {
    return;
  }

  if (pos == 1)
  {
    node* temp = current;
    //current->next->previous = current->previous;
    //current->previous->next = current->next;

    if (current->next != NULL) {
      current->next->previous = current->previous;
    }
    if (current->previous != NULL) {
      current->previous->next = current->next;
    }
    delete temp;
    return;
  }

  remove_nth_node(current->next, pos - 1);

}



//reverse DLL and return new head
node* dlist::reverse(node* current)
{
  if (current == NULL) { 
    return NULL;
  }

  //swap next and previous
  node* temp = current->next;
  current->next = current->previous;
  current->previous = temp;

  if (current->previous == NULL) { //if previous is NULL then list fully reversed
    return current;
  }

  return reverse(current->previous);

} //end of function




void dlist::printList(node* head) 
{
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "" << endl;
}








void dlist::delete_first_last(node* current) 
{
  if (current == NULL) {
    return;
  }

  if (current == head) {
    node* temp = current;
    head = current->next;
    head->previous = NULL;
    delete temp;
    delete_first_last(current->next);
  }
  else if (current->next == NULL) {
    node* temp = current;
    current->previous->next = NULL;
    delete temp;
  }
  else {
    delete_first_last(current->next);
  }

} //end of function

