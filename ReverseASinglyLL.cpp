#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int d){
		    this->data = d;
			this->next = NULL;
		}
		
		~Node(){
			int value = this->data;
			if(this->next != NULL){
				delete next;
				this-> next = NULL;
			}
			
			cout<<"Memory is free for value: "<<value<<endl;
		}
};


//Recursive Solution 
Node* reverse(Node* head)
{
	//base case 
	if(head == NULL || head->next == NULL)
	{
		return head;
	}
	
	Node* chhotahead = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return chhotahead;
}


//Iterative Solution
Node* reversedLinkedList(Node* head)
{
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* prev = NULL;
	Node* curr = head;
	Node* forword = NULL;
	while(curr != NULL){
		forword = curr->next;
		curr->next  = prev;
		prev = curr;
		curr = forword;
	}
	return prev;
}



void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	cout<<endl;
}

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


int main(){
	Node* node1 = new Node(10);
	Node* head = node1;
	insertAtPosition(head,2,12);
	insertAtPosition(head,3,19);
	insertAtPosition(head,4,17);
	insertAtPosition(head,5,21);
	print(head);
	
	
//	print(reversedLinkedList(head));
    print(reverse(head));
}