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


#include "btree.h"
#include<iostream>
//#include "queue.h"
using namespace std;
template<class T>
btree<T>::btree()
{
	root=NULL;
}
template<class T>
btree<T>::~btree()
{
}
template<class T>
void btree<T>::call_height()
{
	bnode<T>*temp=root;
	int d=depth(temp);
	cout<<"\nHeight is :"<<d;
}
template<class T>
int btree<T>::depth(bnode <T>*temp)
{
	if(temp==NULL)
	{
		return -1;
	}
	else
	return(1+max(depth(temp->left),depth(temp->right)));
}
template<class T>
bnode <T>* btree<T>::minValueNode(bnode <T>*root)
{
	bnode <T>*temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp;
}
template<class T>
void btree<T>::Delete_rec(T d)
{
	root=Delete(root,d);
}
template<class T>
bnode <T>* btree<T>::Delete(bnode <T>*root,T d)
{
	if(root==NULL)
		return root;
	if(d<root->data)
		root->left=Delete(root->left,d);
	else if(d>root->data)
		root->right=Delete(root->right,d);
	else
	{
		if(root->left==NULL)
		{
			bnode <T>*temp=root->right;
			delete(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			bnode <T>*temp=root->left;
			delete(root);
			return temp;
		}
		bnode <T>*temp=minValueNode(root->right);
		root->data=temp->data;
		root->right=Delete(root->right,temp->data);
	}
	return root;
}


template<class T>
void btree<T>::call_mirror()
{
	bnode<T>*temp=NULL;
	if(root==NULL)
	{
		cout<<"Empty tree"<<endl;
		return;
	}
	bnode<T>*q=NULL;
	q=mirror(root,q);
	temp=q;
	cout<<"\nInorder   :";
	inorder_rec(temp);
	temp=q;
	cout<<"\nPreorder  :";
	preorder_rec(temp);
	temp=q;
	cout<<"\nPostorder :";
	postorder_rec(temp);

}
template<class T>
bnode<T>*btree<T>::mirror_nr()
{
	bnode<T>*p=root;
	queue<bnode<T>*>q;
	bnode<T>*temp;
	bnode<T>*temp1;
	bnode<T>*temp2;
	if(p==NULL)
	{
		return p;
	}
	q.enqueue(p);
	while(!q.isempty())
	{
		temp=q.dequeue();
		if(temp->left==NULL && temp->right==NULL)
		{
			continue;
		}
		if(temp->left!=NULL && temp->right!=NULL)
		{
			temp1=temp->left;
			temp->left=temp->right;
			temp->right=temp1;
			q.enqueue(temp->left);
			q.enqueue(temp->right);
		}
		else if(temp->right!=NULL)
		{
			temp->left=temp->right;
			temp->right=NULL;
			q.enqueue(temp->left);
		}
		else
		{
			temp->right=temp->left;
			temp->left=NULL;
			q.enqueue(temp->right);
		}
		}
		return p;
	}
template<class T>
void btree<T>::call_mirror_nr()
{
	bnode<T>*temp1=mirror_nr();
	bnode<T>*temp=temp1;
	cout<<"\nInorder   :";
	inorder_rec(temp);
	temp=temp1;
	cout<<"\nPreorder  :";
	preorder_rec(temp);
	temp=temp1;
	cout<<"\nPostorder :";
	postorder_rec(temp);
}
template<class T>
bnode<T>* btree<T>::mirror(bnode<T>*p,bnode<T>*q)
{
	q=getnode(p->data);

		if(p->left!=NULL)
		{
			q->right=mirror(p->left,q->right);
		}
		if(p->right!=NULL)
		{
			q->left=mirror(p->right,q->left);
		}
	return q;

}
template<class T>
void btree<T>::call_search_rec(T data)
{
	if(search_rec(root,data)){
	cout<<"Found"<<endl;
	return;
	}
	else
	{
		cout<<"not found"<<endl;
		return;
	}

}
template<class T>
bool btree<T>::search_rec(bnode<T>*temp, T data)
{
	if(root==NULL)
	{
		//cout<<"Not found"<<endl;
		return false;
	}

	if(data==temp->data)
	{
		return true;
	}
	if(data<temp->data)
	{
		if(search_rec(temp->left,data))
		return true;
	}
	if(data>temp->data)
	{
		if(search_rec(temp->right,data))
		return true;
	}
	return false;
}
template<class T>
void btree<T>::search(T data)
{
	if(root==NULL)
	{
		cout<<"Empty tree"<<endl;
		return;
	}
	bnode<T>*temp=root;
	while(temp)
	{
		if(data==temp->data)
		{
			cout<<"Found"<<endl;
			return;
		}
		if(data<temp->data)
		{
			temp=temp->left;
		}

		if(data>temp->data)
		{
			temp=temp->right;
		}
	}
	cout<<"Not found"<<endl;
}
template<class T>
void btree<T>::insert(T data)
{
	if(root==NULL)
	{
		root=getnode(data);
		return;
	}
	bnode<T>*temp=root;
	while(temp!=NULL)
	{
		 if(data==temp->data)
		{
			cout<<"Duplicate data"<<endl;
			return;
		}
		else if(data<temp->data)
		{
			if(temp->left==NULL)
			{
				temp->left=getnode(data);
				return ;
			}
			temp=temp->left;
		}
		else if(data>temp->data)
		{
			if(temp->right==NULL)
			{
				temp->right=getnode(data);
				return;
			}
			temp=temp->right;
		}


	}
	return;
}
template<class T>
void btree<T>::level_order()
{
	queue<bnode<T>*>q;
	if(root==NULL)
	{
		cout<<"Empty tree"<<endl;
		return;
	}
	bnode<T>*temp=NULL;
	q.enqueue(root);
	while(!q.isempty())
	{
		temp=q.dequeue();
		cout<<temp->data<<" ";

		if(temp->left!=NULL)
		{
			q.enqueue(temp->left);
		}
		if(temp->right!=NULL)
		{
			q.enqueue(temp->right);
		}

	}
}
template<class T>
void btree<T>::display_rec()
{
	bnode<T>*temp=NULL;
	temp=root;
	cout<<"\nInorder   :";
	inorder_rec(temp);
	temp=root;
	cout<<"\nPreorder  :";
	preorder_rec(temp);
	temp=root;
	cout<<"\nPostorder :";
	postorder_rec(temp);
	cout<<"\nLevelorder :";
	level_order();
}
template<class T>
void btree<T>::inorder_rec(bnode<T>*temp)
{
	if(temp!=NULL)
	{
		inorder_rec(temp->left);
		cout<<temp->data<<" ";
		inorder_rec(temp->right);
	}
}
template<class T>
void btree<T>::preorder_rec(bnode<T>*temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data<<" ";
		preorder_rec(temp->left);
		preorder_rec(temp->right);
	}
}
template<class T>
void btree<T>::postorder_rec(bnode<T>*temp)
{
	if(temp!=NULL)
	{
		postorder_rec(temp->left);
		postorder_rec(temp->right);
		cout<<temp->data<<" ";
	}
}

template<class T>
bnode<T>*btree<T>::getnode(T data)
{
	bnode<T>*p=new bnode<T>;
	p->left=NULL;
	p->right=NULL;
	p->data=data;
	return p;
}
template<class T>
void btree<T>::call_insert_rec(T data)
{
	bnode<T>*temp=root;
	root=insert_rec(temp,data);
}
template<class T>
bnode<T>*btree<T>::insert_rec(bnode<T>*temp,T data)
{
	if(temp==NULL)
	{
		temp=getnode(data);
		return temp;
	}
	else if(data<temp->data)
	{
		temp->left=insert_rec(temp->left,data);
	}
	else if(data>temp->data)
	{
		temp->right=insert_rec(temp->right,data);
	}
	else
	{
		cout<<"Duplicate data"<<endl;
	}
	return temp;
}
