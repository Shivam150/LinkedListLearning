#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int d){
			this->data = d;
			this->next = NULL;
		}
		
		~Node() {
		    int val = this->data;
		    if(this->next != NULL){
		    	delete next;
		    	next = NULL;
			}
			
			cout<<"Memory is free for node with data "<<val<<endl;
		}
};


void insertNode(Node* &tail , int element , int d)
{
	if(tail == NULL){
		Node* newNode = new Node(d);
		tail = newNode;
		newNode->next = newNode;
	}else{
		Node* curr = tail;
		while(curr->data != element){
			curr = curr->next;
		}
		Node* temp = new Node(d);
		temp->next = curr->next;
		curr->next = temp;
	}
}

void deletenNode(Node* &tail , int value)
{
	if(tail == NULL)
	{
		cout<<"Linked List is empty, Please check";
		return;
	}else{
		Node* prev = tail;
		Node* curr = prev->next;
		while(curr->data != value)
		{
			 prev = curr;
			 curr = curr->next;
		}
		
		prev->next = curr->next;
		// if there is only One Node
		if(curr == prev)
		{
			tail = NULL;
		}
		if(tail == curr)
		{
			tail = prev;
		}
		curr->next = NULL;
		delete curr;
	}
}


void print(Node* tail){
	Node* temp = tail;
	do{
		cout<<tail->data<<" ";
		tail = tail->next;
	}while(tail != temp);
	cout<<endl;
}

int main(){
	
	Node* tail = NULL;
	insertNode(tail,5,3);
	print(tail);
	
//	insertNode(tail,3,5);
//	print(tail);
//	
//	insertNode(tail,3,4);
//	print(tail);
//	
//	insertNode(tail,5,7);
//	print(tail);
//	
//	insertNode(tail,7,9);
//	print(tail);
//	
//	insertNode(tail,9,11);
//	print(tail);
	
	deletenNode(tail ,3);
	print(tail);
	
}