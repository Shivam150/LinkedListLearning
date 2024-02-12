#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
		//Constructor
		Node(int d){
			this->data = d;
			this->prev = NULL;
			this->next = NULL;
		}
		
		
};

void insertAtHead(Node* &head ,Node* &tail ,int d){
	
	if(head == NULL){
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	}
	else{	
	  Node* temp = new Node(d);
	  temp->next = head;
	  head->prev = temp;
	  head = temp;
	}
}

void insertAtTail(Node* &tail , Node* &head , int d){
	if(tail == NULL){
		Node* temp = new Node(d);
		tail = temp;
		head = temp;
	}
	else{
	   Node* temp = new Node(d);
	   tail->next = temp;
	   temp->prev = tail;
	   tail = temp;
	}
}

void insertAtPosition(Node* &head , Node* &tail ,  int position , int d){
	if(position == 1){
		insertAtHead(head,tail,d);
		return;
	}
	 
	Node* temp = head;
	int cnt =1;
	
	while(cnt < position-1){
		temp = temp->next;
		cnt++;
	}
	
	if(temp->next == NULL){
		insertAtTail(tail,head ,d);
		return;
	}
	
	Node* nodeToInsert = new Node(d);
	nodeToInsert->next = temp->next;
	temp->next->prev = nodeToInsert;
	temp->next = nodeToInsert;
	nodeToInsert->prev = temp;
}


		
	
		

void print(Node* head){
	Node* temp = head;
	
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	cout<<endl;
}

int getLength(Node* head){
	Node* temp = head;
	int len;
	while(temp != NULL){
		len++;
		temp = temp->next;
	}
	
	return len;
}

int main(){
//	Node* node1 = new Node(10);
	Node* head = NULL;
	Node* tail = NULL;
	print(head);
	
//	insertAtHead(head,tail,15);
//	insertAtHead(head,tail,20);
//	print(head);
	
	insertAtTail(tail ,head, 15);
	insertAtTail(tail ,head, 20);
	insertAtTail(tail ,head, 25);
	print(head);
	print(tail);
//	
	insertAtPosition(head , tail , 4 ,17);
	print(head);
//	print(tail);
	
	
	
	return 0;
	
}