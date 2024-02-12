#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		
		Node(int d)
		{
			this->data = d;
			this->next = NULL;
		}
		
		~Node(){
			int val = this->data;
			if(this->next != NULL){
		    	delete next;
		    	next = NULL;
			}
			cout<<"Memory is free for node with data "<<val<<endl;
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


int getLength(Node* head){
	int len;
	while(head != NULL){
		len++;
		head = head->next;
	}
	
	return len;
}

void print(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	cout<<endl;
}


//First Approach
Node* MiddleNode(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	int len = getLength(head);
	int ans = len/2 ;
	cout<<"Answer Position:  "<<ans<<endl;
	int cnt = 0;
	Node* temp = head;
	while(cnt < ans)
	{
		temp = temp->next;
		cnt++;
	}
	
	return temp;
}

// Second Approach or Optimised Solution

Node* FindMiddleNode(Node* head)
{
	if(head == NULL || head->next == NULL)
	{
		return head;
	}
	
	Node* slow = head;
	Node* fast = head->next;
	
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL)
		{
			fast = fast->next;
		}
		slow = slow->next;
	}
	
	return slow;
}






int main()
{
	Node* node1 = new Node(10);
	Node* head = node1;
	insertAtPosition(head,2,12);
	insertAtPosition(head,3,15);
	insertAtPosition(head,4,19);
	insertAtPosition(head,5,21);
	insertAtPosition(head,6,23);
	print(head);
	
	cout<<FindMiddleNode(head)->data<<endl;
}