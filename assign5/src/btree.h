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


#ifndef BTREE_H
#define BTREE_H
#include "queue.h"
#include "queue.cpp"
template<class T>
struct bnode
{
	T data;
	bnode<T>*left;
	bnode<T>*right;
};
template<class T>
class btree
{
	bnode <T>*root;
	public:
		btree();
		~btree();
		void display_rec();
		void call_mirror();
		bnode <T>* minValueNode(bnode <T>*root);
		bnode <T>* Delete(bnode <T>*root,T d);
		bnode<T>*mirror_nr();
		void call_mirror_nr();
		void call_height();
		int depth(bnode <T>*temp);
		void Delete_rec(T d);
		//bnode<T>* mirror(bnode<T>*root);
		bnode<T>* mirror(bnode<T>*p,bnode<T>*q);
		void search(T data);
		void call_search_rec(T data);
		bool search_rec(bnode<T>*temp,T data);
		void inorder_rec(bnode<T>*temp);
		void preorder_rec(bnode<T>*temp);
		void postorder_rec(bnode<T>*temp);
		bnode<T>*getnode(T data);
		void call_insert_rec(T data);
		void insert(T data);
		void level_order();
		bnode<T>*insert_rec(bnode<T>*temp,T data);
	protected:
};

#endif
