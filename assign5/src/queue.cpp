//===================================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Implement binary search tree and perform following operations:
//					  a. Insert
//					  b. Delete
//					  c. Search
//					  d. Mirror image
//					  e. Display
//					  f. Display level wise traversals.
//===================================================================================

#include "queue.h"
#include "linked.h"


template<typename T>
queue<T>::queue() {
	// TODO Auto-generated constructor stub

}

template<typename T>
queue<T>::~queue() {
	// TODO Auto-generated destructor stub
}

template<typename T>
bool queue<T>::isempty()  //Return true if queue is empty else false
{
   if(l.isempty())
	   return true;
   return false;

}


template<typename T>
T queue<T>::peep()	//Return front element of queue
{
  return(l.display_first());
}

template<typename T>
	void queue<T>::enqueue(T x)
{
  l.insert_last(x);
}



template<typename T>
	T queue<T>::dequeue()
{
   T x=l.display_first();
   l.delete_first();
   return x;

}
