/*
Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.
*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void reorderList(struct Node* head) ;
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("");
}
void freeList(struct Node *head)
{
	struct Node* temp;
    while(head != NULL)
    {
        
        temp=head;
        head = head->next;
        free(temp);
    }
  
}
int main(void)
{
   int t,n,m,i,x;
   
   cin>>t;
   while(t--)
   {
	   struct Node* temp,*head;
	    cin>>n;
	    cin>>x;
	    head=new Node(x);
	    temp=head;
	    for(i=0;i<n-1;i++)
	    {
			cin>>x;
			temp->next=new Node(x);
			temp=temp->next;
			}
	   
		reorderList(head);
	    printList(head);
        freeList(head);
   }
   return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Following is the Linked list node structure */
/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
void reorderList(Node* head) 
{
    // Your code here
    if(head==NULL) return;
    if(head->next==NULL) return;
    if(head->next->next==NULL) return;
    Node *firstList = head;
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while(fast!=NULL){
        if(fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        else{
            fast = fast->next;
        }
    }
    
    prev->next = NULL;
    
    Node *next = NULL;
    Node *target = NULL;
    while(slow!=NULL){
        next = slow->next;
        slow->next = target;
        target = slow;
        slow = next;
    }
    
    Node *secondList = target;
    Node *ans = firstList;
    Node *temp = NULL;
    Node *temp2 = NULL;
    while(firstList!=NULL){
        temp = firstList->next;
        firstList->next = secondList;
        temp2 = secondList->next;
        if(temp!=NULL) secondList->next = temp;
        else break;
        firstList = temp;
        secondList = temp2;
    }
}