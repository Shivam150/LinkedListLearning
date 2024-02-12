#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node(int d){
			this->data = d;
			this->next = NULL;
		}
		
		
		~Node(){
			int val  = this->data;
			if(this->next != NULL)
			{
				delete next;
				next = NULL;
			}
			cout<<"Memory free from node with value: "<<val<<endl;
		}
};


bool isCircularLL(Node* head){
	if(head == NULL){
		return true;
	}
	
	Node* temp = head->next;
	while(temp != NULL && temp != head){
		temp = temp->next;
	}
	
	if(temp == head)
	{
		return true;
	}
	
	return false; 
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
//	Node* tail = NULL;
	Node* node1 = new Node(10);
	Node* node2 = new Node(20);
	Node* node3 = new Node(30);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node1;
	
	Node* head = node1;
	
	if(isCircularLL(head)){
		cout<<"Linked List is circular in nature"<<endl;
	}else{
		cout<<"Linked List is not Circular in Nature"<<endl;
	}
	
	
	
	
}