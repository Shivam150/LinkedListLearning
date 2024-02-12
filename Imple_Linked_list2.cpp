#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
//		constructor

    Node(int data){
     	this -> data = data;
     	this -> next = NULL;
	 }
		
		
};

void insertAtHead(Node* &head, int d){
	
//	create new node 
    Node* node2 = new Node(d);
    node2->next = head;
    head = node2;
}

void printLinkedList(Node* &head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data <<" ";
		temp = temp->next;
	}
	
	cout<<endl;
}

int main(){
//	Created New Node
	Node* node1 = new Node(10);
	
//	cout<<node1->data<<endl;
//	cout<<node1 -> next <<endl;
	
//	head pointed to node1;
    Node* head = node1;
    cout<<"Before Insertion: ";
    printLinkedList(head);
    cout<<endl;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    printLinkedList(head);
}