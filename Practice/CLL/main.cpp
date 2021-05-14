#include "clist.h"
#include <iostream>


int main()
{
    clist object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    /*
    int array[50];
    int index = 0;
    object.copyNotTwo(object.getRear()->next, array, index);
    cout << "\nCopied except 2s:" << endl;
    for (int i = 0; i < index; i++){
    	cout << array[i] << " ";
    }
    cout << "" << endl;
    */


    /*
    int sum = 0;
    sum = object.sum_even_wrapper(object.getHead());
    cout << "\nSum Even: " << sum << endl;
    */

    /*
    int sum = 0;
    int count = 0;
    object.findaverage(object.getRear()->next, sum, count);
    float ave = (float) sum / (float) count;
    cout << "\nAverage: " << ave << endl;
    */

    //object.displayFL(object.getHead());

    int amount = object.countAmount(object.getHead());
    cout << "Number: " << amount << endl;


    object.display(); //resulting list after your function call!
    
    return 0;
}