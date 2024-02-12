#include<bits/stdc++.h>
using namespace std;


//INSERTION AT TAIL

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};

void insertAtTail(Node* &tail, int d){
	Node* node2 = new Node(d);
	tail->next = node2;
	tail = tail->next;
}

void print(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp= temp->next;
	}
	
	cout<<endl;
	
}





int main(){
	Node* node1 = new Node(10);
	Node* head = node1;
	Node* tail = node1;
	cout<<node1->data<<endl;
	cout<<node1->next<<endl;
	
	insertAtTail(tail,20);
	insertAtTail(tail,30);
	insertAtTail(tail,40);
	insertAtTail(tail,50);
	print(head);
	
}