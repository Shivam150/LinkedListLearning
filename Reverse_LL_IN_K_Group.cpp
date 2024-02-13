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
			int val = this->data;
			if(this->next != NULL)
			{
				delete next;
				next = NULL;
			}
			cout<<"Memory is free from node with data "<<val<<endl;
		}
};


void print(Node* head){
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	
	cout<<endl;
}


//Recursive Solution 

 Node* KReverseLL(Node* head, int k){
 	//base case
 	if(head == NULL && head->next == NULL)
 	{
 		return head;
	}
	
	// Step1  Solve first case
	int cnt = 0;
	Node* Next = NULL;
	Node* prev = NULL;
	Node* curr = head;
	
	
	Node* temp = head;
	int count = 0;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k) {
        // If the remaining nodes are less than k, no need to reverse
        return head;
    }
	
	while(curr != NULL && cnt < k){
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr  = Next;
		cnt++;
	}
	
	// Step2 aage ka recursive dekh lega
	if(Next != NULL)
	{
	   head->next = KReverseLL(Next,k);	
	}
	return prev; 
 }





int main()
{
	
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	Node* head = node1;
	print(head);
	Node* h = KReverseLL(head,3);
	print(h);
	
}