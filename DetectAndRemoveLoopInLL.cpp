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
			if(this->next != NULL){
				delete next;
				next = NULL;
			}
			cout<<"Memory free from Node with value "<<val<<endl;
		}
};



//Using Map

bool detectLoop(Node* head){
	if(head == NULL)
	{
		return false;
	}
	
	map<Node* , bool> visited;
	
	Node* temp = head;
	
	while(temp != NULL)
	{
		if(visited[temp] == true)
		{
			cout<<"Node data : "<<temp->data<<endl;
			return true;
		}
		
		visited[temp] = true;
		temp = temp->next;
	}
	
	return false;
}

// Using Floyd's Detection Algorithm

bool floydCycleDetectionAlgo(Node* head){
	if(head == NULL && head->next == NULL)
	{
		return false;
	}
	
	Node* slow = head;
	Node* fast = head->next;
	
	while(slow != fast){
		if(fast == NULL || fast->next == NULL){
			return false;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	
	
	cout<<"Node data: "<< slow->data<<endl;
	return true;
	
	
}


int main(){
	//	Node* tail = NULL;
	Node* node1 = new Node(10);
	Node* node2 = new Node(20);
	Node* node3 = new Node(30);
	Node* node4 = new Node(40);
	Node* node5 = new Node(50);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node3;
	Node* head = node1;
	
	if(floydCycleDetectionAlgo(head)){
		cout<<"Loop is present in the Linked List"<<endl;
	}else{
		cout<<"Loop is not present in the Linked List"<<endl;
	}
}