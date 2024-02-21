#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
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
//			cout<<"Memory free from node with value: "<<val <<endl;
		}
};

// Method first traversal. (done using data replacement).
Node* sort0s1s2s(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	int countZero = 0;
	int countOne = 0 ;
	int countTwo = 0;
	
	Node* temp = head;
	
	while(temp != NULL){
		if(temp->data == 0){
			countZero++;
		}else if(temp->data == 1){
			countOne++;
		}else if(temp->data == 2){
			countTwo++;
		}
		
		temp = temp->next;
	}
	
	temp = head;
	
	while(temp != NULL){
		if(countZero !=0){
			temp->data = 0;
			countZero--;
		}else if(countOne != 0){
			temp->data = 1;
			countOne--;
		}else if(countTwo != 0){
			temp->data = 2;
			countTwo--;
		}
		
		temp = temp->next;
	}
	
	return head;
}

void insertAtTail(Node* &tail, Node* curr){
	tail->next = curr;
	tail = curr;
}


// Method two Without replacement of data by dividing list into 3 seperate list 0 for second for 1 And Third for 2.

Node* sortZeroOneTwo(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	//Created dummy nodes and their tails to make three seperate nodes.
	Node* zeroHead = new Node(-1);
	Node* zeroTail = zeroHead;
	Node* oneHead = new Node(-1);
	Node* oneTail = oneHead;
	Node* twoHead = new Node(-1);
	Node* twoTail = twoHead;
	
	Node* curr = head;
	
	// Created 3 linked lsit for 0s , 1s, And 2s;
	while(curr != NULL){
		int val = curr->data;
		if(val == 0){
			insertAtTail(zeroTail, curr);
		}else if(val == 1){
			insertAtTail(oneTail, curr);
		}else if(val == 2){
			insertAtTail(twoTail, curr);
		}
		curr = curr->next;
	}
	
	//Merge all the list
	if(oneHead->next != NULL){ // jab 1s wali list empty Na Ho
		zeroTail->next = oneHead->next;
	}else{ // Jab 1s wali list empty Ho 
		zeroTail->next = twoHead->next;
	}
	
	oneTail->next = twoHead->next;
	twoTail->next = NULL;
	
	// update head
	head = zeroHead->next;
	
	//Delete all demmy nodes
	delete zeroHead;
	delete oneHead;
	delete twoHead;
	
	return head;
}



void print(Node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}


int main(){
	Node* node1 = new Node(1);
	Node* node2 = new Node(0);
	Node* node3 = new Node(1);
	Node* node4 = new Node(0);
	Node* node5 = new Node(2);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	Node* head = node1;
	cout<<"Before sorting:"<<endl;
	print(head);
	
	cout<<"After Sorting: "<<endl;
//	head = sort0s1s2s(head);
    head = sortZeroOneTwo(head);
	print(head);
	
}


