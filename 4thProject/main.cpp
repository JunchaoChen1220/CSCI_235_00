#include <iostream>
//#include <>

#include "Node.hpp"
#include "LinkedList.hpp"
#include "PrecondViolatedExcep.hpp"

int main(int argc, char const *argv[])
{
	LinkedList<int> ll1;


	int size = 1;

	// Create a singly linked list 
	// Values are in decending order
	for(int i = 0; i < size; i++){
		ll1.insert(0,i);
	}


	ll1.display();
	
	// Reverse order of list
	ll1.invert();

	ll1.display();

	return 0;
}



// A  wrapper to a recursive method that inverts the contents of the list
// @post the contents of the list are inverted such that
//      the item previously at position 1 is at position item_count_,
//      the item previously at position 2 is at position item_count_-1 ...
//      the item previously at position ⌊item_count/2⌋ is at position ⌈item_count_/2⌉

//private function to invert, used for safe programming to avoid
//exposing pointers to list in public methods
// @post the contents of the list are inverted such that
//      the item previously at position 1 is at position item_count_,
//      the item previously at position 2 is at position item_count_-1 ...
//      the item previously at position ⌊item_count/2⌋ is at position ⌈item_count_/2⌉