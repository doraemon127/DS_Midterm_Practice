#include "clist.h"
#include <iostream>


clist::clist() {
  rear = NULL;
}

clist::~clist() {
  node* temp = rear;
  rear = rear->next;
  temp->next = NULL;
  while (rear->next != NULL) {
    temp = rear;
    rear = rear->next;
    delete temp;
  }
  rear->next = NULL;
  delete rear;
}

void clist::build() {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  rear = current;
  node* previous = current;
  int additionalValues = (rand()%5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  current->next = rear;
}

void clist::display() {
  node* current = rear->next;
  while (current != rear) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << rear->data << " ";
  cout << endl;
}


node* clist::getRear() {
  return rear;
}



node* clist::getHead()
{
  return rear->next;
}



//function to copy all data that isn't a 2
//current initially passed in as rear-next
void clist::copyNotTwo (node* current, int array[], int & index)
{
  node* originalRear = getRear();
  if (current != originalRear) {
    if (current->data > 2) {
      array[index] = current->data;
      index++;
    }
    copyNotTwo(current->next, array, index);
  }
  else if(originalRear == current) {
    if (rear->data > 2) {
      array[index] = current->data;
    }
    index++;
  }
}



void clist::findaverage (node* current, int & sum, int & count)
{
  node* originalRear = getRear();
  if (current != originalRear) {
    sum += current->data;
    count++;
    findaverage(current->next, sum, count);
  }
  else if(originalRear == current) {
    sum += current->data;
    count++;
  }

}




int clist::sum_even_wrapper(node* h)
{
  //make CLL into LLL
  node* end = h;
  h = h->next;
  end->next = NULL;

  int sum = 0;
  sum_even(h, sum);

  //convert back into LLL
  end->next = h;
  h = end;

  return sum;
}

//function to add up all even numbers
//parameter current initially passed in as head
//parameter sum initially passed in as zero
void clist::sum_even(node* current, int& sum)
{
  if (current != NULL) {
    if (current->data % 2 == 0) {
      sum += current->data;
    }
    sum_even(current->next, sum);
  }
}





void clist::displayFL(node* current) {
  if (current == rear->next) {
    cout << current->data << " ";
    displayFL(current->next);
  }
  else if (current == rear) {
    cout << current->data << endl;
  }
  else {
    displayFL(current->next);
  }
}



int clist::countAmount(node* head) {
  if (head == rear) {
    return 1;
  }
  else {
    return 1 + countAmount(head->next);
  }
}
