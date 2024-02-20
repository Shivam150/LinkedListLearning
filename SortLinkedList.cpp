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
			cout<<"memory free from Node with value: "<<val<<endl;
		}
};

void swap(Node* a, Node* b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}


void sortList(Node* head){
	cout<<"head ka data==:"<<head->data<<endl;
	if(head == NULL || head->next == NULL)
	{
		cout<<"Hello===="<<endl;
		return;
	}
	
	Node* prev = head;
	Node* curr = head->next;
	cout<<"prev ka data: "<<prev->data<<endl;
	cout<<"curr ka data: "<<curr->data<<endl;
	
	while(curr != NULL)
	{
		if(prev->data > curr->data){
			swap(prev,curr);
		}
		prev = prev->next;
		curr = curr->next;	
	}
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

void print(Node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(){
	Node* node1 = new Node(10);
	Node* head = node1;
	insertAtPosition(head,2,20);
	insertAtPosition(head,3,10);
	insertAtPosition(head,4,40);
	insertAtPosition(head,5,30);
	insertAtPosition(head,6,40);
	cout<<"List before sorted: "<<endl;
	print(head);
	
	cout<<"List After Sorting: "<<endl;
	sortList(head);
	print(head);
}