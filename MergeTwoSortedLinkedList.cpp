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
		
		~Node() {
			int value = this->data;
			if(this->next != NULL){
				delete next;
				next = NULL;
			}
//			cout<<""
		}
};


Node* solve(Node* first , Node* second){
	
	//check if there is only one Node in first list
	if(first->next == NULL){
		// then point to second list
		first->next = second;
		return first;
	}
	
	Node* prev = first;
	Node* curr = first->next;
	Node* temp = second;
	
	while(curr != NULL && temp != NULL){
		if((temp->data >= prev->data) && (temp->data <= curr->data)){
			prev->next = temp;
			Node* Temp_next = temp->next;
			temp->next = curr;
			
			//update pointer
			prev =temp;
			temp = Temp_next;
		}else{
			// move prev and curr to next 
			prev = curr;
			curr = curr->next;
			// check if curr reached to end 
			if(curr == NULL){
				//put remaining all node of second list to end of first list (curr->remaining second list).
				prev->next = temp;
				return first;
		    } 
	    }
	
   }
   
   return first;
   
}


Node* mergeTwoSortedList(Node* head1 , Node* head2){
 	
	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
	
	if(head1->data <= head2->data)
	{
		return solve(head1,head2);
	}else{
		return solve(head2,head1);
	}
}

void print(Node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head= head->next;
	}
	cout<<endl;
}


int main(){
	Node* headOne = new Node(1);
	Node* node2 = new Node(3);
	Node* node3 = new Node(5);
	
	headOne->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	
	Node* headTwo = new Node(2);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);
	
	headTwo->next = node4;
	node4->next = node5;
	node5->next = NULL;
	
	cout<<"List One==:"<<endl;
	print(headOne);
	
	cout<<"List Two==:"<<endl;
	print(headTwo);
	
	cout<<"After merge of Two sorted list==:"<<endl;
	Node* head = mergeTwoSortedList(headOne,headTwo);
	print(head);
	
	
	return 0;
}

