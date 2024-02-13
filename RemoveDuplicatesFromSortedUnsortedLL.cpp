#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data ;
		Node* next;
		
		
		Node(int d){
			this->data = d;
			this->next = NULL;
		}
		
		~Node(){
			int val = this->data;
			if(this->next != NULL){
				delete next;
				next = NULL;
			}
//			cout<<"Memory free from Node with value: "<<val<<endl;
		}	
};


// Remove Duplicates from soretd Linked List

Node* removeDuplicateFromSortedLL(Node* &head){
	if(head == NULL){
		return NULL;
	}
	
	Node* curr = head;
	
	while(curr != NULL){
		if( (curr->next != NULL) && curr->data == curr->next->data)
		{
			Node* next_next = curr->next->next; //Store location to point deleted to next
			Node* nodeTodelete =curr->next;     // store node to delete 
			delete(nodeTodelete);              // delete first then point because if we point fist then we lost this node( we can not delete it).
			curr->next = next_next;            // point to deleted to next
			
		}
		else{
			curr = curr->next;
		}	
	}
	
	return head;
}

void print(Node* &head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
	cout<<endl;
}


int main(){
	Node* node1 = new Node(10);
	Node* node2 = new Node(10);
	Node* node3 = new Node(20);
	Node* node4 = new Node(20);
	Node* node5 = new Node(30);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	Node* head = node1;
	
	cout<<"List Before Operation: "<<endl;
	print(head);
	
	
	cout<<"List After Operation: "<<endl;
	Node* headOfNew = removeDuplicateFromSortedLL(head);
	
	cout<<"headOfNewList===:"<<headOfNew->data<<endl;
	
	print(headOfNew);
}