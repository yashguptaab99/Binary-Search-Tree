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

#include <iostream>
using namespace std;
#include "btree.h"
#include "btree.cpp"

int main(int argc, char** argv) {
	int data,height;
	btree <int>b;
	int ch;
	do
	{
		cout<<"\n1.Insert\n2.Display\n3.Search\n4.Mirror\n5.Delete\n6.Height\n7.Exit"<<endl;
		cout<<"Enter your choice :";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
				cout<<"Enter data :"<<endl;
				cin>>data;
				b.insert(data);
				b.display_rec();
				//b.call_insert_rec(data);
				break;
			case 2:
				b.display_rec();
				break;
			case 3:
				cout<<"Enter data :"<<endl;
				cin>>data;
				b.search(data);
				//b.call_search_rec(data);
				break;
			case 4:
				b.call_mirror();
				//b.call_mirror_nr();
				break;
			case 5:
				cout<<"Enter data :"<<endl;
				cin>>data;
				b.Delete_rec(data);
				b.display_rec();
				break;
			case 6:
				b.call_height();
				break;
				case 7:
					break;
		}
	}while(ch!=7);
	return 0;
}
