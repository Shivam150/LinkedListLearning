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
		
		
};






Node* reverse(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	Node* curr = head;
	Node* prev = NULL;
	Node* Next = NULL;
	
	while(curr != NULL){
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next;
	}
	
	return prev;
}

void insertAtTail(Node* &head , Node* &tail , int val){
	Node* temp = new Node(val);
	
	// if empty list
	if(head == NULL) {
		head = temp;
		tail = temp;
	}else{
		tail->next = temp;
		tail = temp;
	}
}

Node* AddNumber(Node* first , Node* second){
	int carry = 0;
	Node* ansHead = NULL;
	Node* ansTail = NULL;
	
	while(first != NULL || second != NULL || carry != 0){
		int val1 = 0;
		if(first != NULL){
			val1 = first->data;
		}
		
		int val2 = 0;
		if(second != NULL){
			val2 = second->data;
		}
		
		int sum = carry+val1+val2;
		int digit = sum%10;
		
		insertAtTail(ansHead , ansTail , digit);
		
		carry = sum/10;
		
		if(first != NULL){
			first = first->next;
		}
		if(second != NULL){
			second = second->next;
		}
	}
	
	return ansHead;
}


Node* AddTwoNumber(Node* First , Node* Second){
	
	First = reverse(First);
	Second = reverse(Second);
	
	Node* Ans = AddNumber(First , Second);
	
	Ans  = reverse(Ans);
	
	return Ans;
}


void print(Node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}




int main(){
	
	//First list
	Node* head1 = new Node(4);
	Node* node1 = new Node(5);
//	Node* node2 = new Node();
	
	head1->next = node1;
	node1->next = NULL;
//	node2->next = NULL;
	
	//Second list 
	
	Node* head2 = new Node(3);
	Node* node3 = new Node(4);
	Node* node4 = new Node(5);
	
	head2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	
	cout<<"First List Is: "<<endl;
	print(head1);
	
	cout<<"Second List is : "<<endl;
	print(head2);
	
	
	Node* result = AddTwoNumber(head1,head2);
	
	cout<<"Result List is: "<<endl;
	print(result);
	
}