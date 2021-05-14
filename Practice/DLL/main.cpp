#include "dlist.h"


int main()
{
    dlist object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned-----------------------
    
    //object.remove_greater_than_nine(object.getHead());

    //node* head = object.reverse(object.getHead());
    //object.printList(head);

    object.remove_nth_node(object.getHead(), 3);


    //-----------------------------------------------------------------------------

    object.display();
    
    return 0;
}