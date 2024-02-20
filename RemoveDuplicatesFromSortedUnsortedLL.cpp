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

Node* removeDuplicateFromSortedLL(Node* head){
	
	if(head == NULL){
		cout << "List is empty." << endl;
		return head;
	}
	
	Node* curr = head;
	
	cout<<"Hello curr ka data:"<<curr->data<<endl;
	cout<<"Hello curr ke next ka data:"<<curr->next->data<<endl;
	
	while(curr->next != NULL){
		
//		cout<<"Helloooo:"<<endl;
		if(curr->data == curr->next->data)
		{
			Node* next_next = curr->next->next; //Store location to point deleted to next
			Node* nodeToDelete = curr->next;     // store node to delete 
			delete(nodeToDelete);              // delete first then point because if we point fist then we lost this node( we can not delete it).
			curr->next = next_next;            // point to deleted to next
			cout<<"Hello Inside While If: "<<endl;
		}
//		else{
			curr = curr->next;
//		}	
	}
	
	cout<<"Hello before return head: "<<head->data<<endl;
	return head;
}


void removeDuplicates(Node* head)
{
    map<int, bool> track;
    Node* temp = head;
    while (temp) {
        if (track.find(temp->data) == track.end()) {
            cout << temp->data << " ";
        }
        track[temp->data] = true;
        temp = temp->next;
    }
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
	Node* node2 = new Node(20);
	Node* node3 = new Node(20);
	Node* node4 = new Node(40);
	Node* node5 = new Node(50);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	Node* head = node1;
	
	cout<<"List Before Operation: "<<endl;
	print(head);
	
	
	cout<<"List After Operation: "<<endl;
	head = removeDuplicateFromSortedLL(head);
//    removeDuplicates(head);
	print(head);
	
	return 0;
}