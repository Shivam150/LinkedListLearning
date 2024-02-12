#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
		
		~Node(){
			int value = this->data;
			if(this->next != NULL){
				delete next;
				this->next = NULL;
			}
			
			cout<<"Memory is free for value:"<<value<<endl;
		}
		
};

void insertAtPosition(Node* &head , int position , int d ){
	Node* temp = head;
	int cnt =1;
	while(cnt< position-1){
		temp = temp->next;
		cnt++;
	}
	Node* nodeToInsert = new Node(d);
	nodeToInsert->next = temp->next;
	temp->next = nodeToInsert;
}

void deleteNode(Node* &head , int position){
	if(position == 1){
		Node* temp = head ;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else{
		Node* curr = head;
		Node*prev = NULL;
		int cnt = 1;
		while(cnt < position){
			prev = curr;
			curr = curr->next;
			cnt++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
}



void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	cout<<endl;
}


int main(){
	Node* node1 = new Node(10);
	Node* head = node1;
	
	print(head);
	
	insertAtPosition(head,2,20);
	insertAtPosition(head,3,30);
	insertAtPosition(head,4,40);
	print(head);
	
	deleteNode(head,4);
	print(head);
	
}

