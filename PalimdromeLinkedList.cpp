#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next ;
		
		
		Node(int d){
			this->data = d;
			this->next = NULL;
		}
		
		
};

Node* getMiddle(Node* head){
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

Node* reverse(Node* head){
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


bool isPalim(vector<int> arr){
	int n = arr.size();
	int s =0;
	int e = n-1;
	
	while(s <= e){
		if(arr[s] != arr[e]){
			return 0;
		}
		s++;
		e--;
	}
	
	return 1;
}


//Approach One  using Array
bool isPalimdromeOne(Node* head){
	vector<int> arr;
	
	Node* temp = head;
	
	while(temp != NULL){
		arr.push_back(temp->data);
		temp = temp->next;
	}
	
	return isPalim(arr);
}

//Approach Two Using Linked list it self

bool isPalimdrome(Node* head){
	if(head == NULL || head->next == NULL){
		return true;
	}
	
	// Step 1 find middle.
	Node* middle  = getMiddle(head);
	
	// Step 2 reverse LL after it
	Node* temp = middle->next;
	middle->next = reverse(temp);
	
	//Step 3 compare both half 
	Node* head1 = head;
	Node* head2 = middle->next;
	
	while(head2 != NULL){
		if(head1->data != head2->data){
			return false;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	
	
	temp = middle->next;
	middle->next = reverse(temp);
	
	return true;
}




void print(Node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}



int main(){
	Node* head = new Node(1);
	Node* node1 = new Node(2);
	Node* node2 = new Node(1);
	
	head->next = node1;
	node1->next = node2;
	node2->next = NULL;
	
	if(isPalimdromeOne(head)){
		cout<<"Linked List is palimdrom"<<endl;
	}else{
		cout<<"Not Palimdrom"<<endl;
	}
	
	return 0;
}