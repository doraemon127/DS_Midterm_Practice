//doubly linked list
//dlist.h

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class dlist
{
    public:
        //These functions are already written
        dlist();         //supplied
        ~dlist();        //supplied
        void build();   //supplied
        void display(); //supplied
        

     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
        node* getHead();

        void remove_greater_than_nine(node* current);

        void remove_nth_node(node* current, int pos);
        
        node* reverse(node* current);
        void printList(node* head);

        void delete_first_last(node* current); 

     
     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
};