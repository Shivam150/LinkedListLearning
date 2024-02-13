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

Node* floydCycleDetectionAlgo(Node* head){
	if(head == NULL && head->next == NULL)
	{
		return NULL;
	}
	
	Node* slow = head;
	Node* fast = head;
	
	while(slow != NULL && fast != NULL){
		fast = fast->next;
		if(fast != NULL)
		{
			fast = fast->next;
		}
		slow = slow->next;
		
		if(slow == fast)
		{
			return slow;
		}
	}
	
	return 0;
}


Node* getStartNodeOfLoop(Node* head)
{
	if(head == NULL){
		return NULL;
	}
	
	Node* intersection = floydCycleDetectionAlgo(head);
	if(intersection == NULL){
		return NULL;
	}
//	cout<<"Intersection Point: "<<intersection->data<<endl;
	Node* slow = head;
	
	while(slow != intersection){
		slow = slow->next;
		intersection = intersection->next;
	}
	
	return slow;
}

void removeStartNodeOfLoop(Node* head){
	if(head == NULL)
	{
		return;
	}
	
	//get start node
	Node* startNodeOfLoop = getStartNodeOfLoop(head);
	if(startNodeOfLoop == NULL){
		return NULL;
	}
	Node* temp = startNodeOfLoop;
	
	while(temp->next != startNodeOfLoop){
		temp = temp->next;
	}
	
	cout<<"Node which is made NULL: "<<temp->data<<endl;
	temp->next = NULL;
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
	node5->next = node2;
	Node* head = node1;
	
	removeStartNodeOfLoop(head);
	
	if(floydCycleDetectionAlgo(head)){
		cout<<"Loop is present in the Linked List"<<endl;
	}else{
		cout<<"Loop is not present in the Linked List"<<endl;
	}
	
//	Node* loop = getStartNodeOfLoop(head);
//	cout<<"Start Node of Loop Or Loop starts at: "<<loop->data<<endl;
}