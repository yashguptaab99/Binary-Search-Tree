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

#ifndef linked_H_
#define linked_H_

template<typename T>
 struct node
	{
		T data;
	    node<T>* next;
	};

template<typename T>
class linked {

	 node <T>* head;

public:
    node<T>* getnode(T);
	linked();
	virtual ~linked();
	bool isempty();
	void insert_first(T);
	void insert_last(T);
	void insert_middle(int,T);
	void display();
	T display_first();
	void delete_first();
	void delete_last();


};

#endif /* linked_H_ */
