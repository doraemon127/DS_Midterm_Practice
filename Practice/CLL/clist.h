//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class clist
{
   public:
   		//These functions are already written
   		clist();			//supplied
   		~clist();		//supplied
   		void build();	//supplied
   		void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
      node* getHead();
      node* getRear();

      int sum_even_wrapper(node* h);
      void sum_even(node* current, int& sum);

      void copyNotTwo(node* current, int array[], int & index);

      void findaverage (node* current, int & sum, int & count);

      void displayFL(node* current); //display first and last

      int countAmount(node* head);


	private:
		node * rear;
};