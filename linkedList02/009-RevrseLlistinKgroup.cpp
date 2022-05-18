#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node * next;
        Node(int a=0){
            this->val=a;
            this->next=NULL;
        }
};
void insertNode(Node * &head,int val){
    Node * newNode=new Node(val);
    if(head==NULL){
        cout<<"Linked List was Empty."<<endl;
        head=newNode;
        return;
    }
    Node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void printLList(Node * head){
    if(head==NULL){
        cout<<"Linked list is Empty"<<endl;

    }
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"-->";
        temp=temp->next;

    }
    cout<<"NULL\n";
}
int lengthOfLinkedList(Node * head){
    int length=0;
    Node * temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}
Node * reverseInKNodes(Node * head,int k){
    if(head==NULL||head->next==NULL)return head;
    Node * temp=head;
    int length=lengthOfLinkedList(temp);
    
    Node * dummyHead=new Node();
    dummyHead->next=head;

    Node * pre=dummyHead;
    Node * cur;
    Node * nxt;

    while(length>=k){
        cur=pre->next;
        nxt=cur->next;

        for(int i=1;i<k;i++){
            cur->next=nxt->next;
            nxt->next=pre->next;
            pre->next=nxt;
            nxt=cur->next;
        }
        pre=cur;
        length-=k;

    }
    return dummyHead->next;
}

int main(){
    Node * head=NULL;
    // insertNode(head,2);
    // insertNode(head,4);
    // insertNode(head,7);
    // insertNode(head,10);
    // insertNode(head,3);

    printLList(head);
    int k = 6;
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);
    insertNode(head,7);
    insertNode(head,8);
    
    cout<<"Original Linked List: "; printLList(head);
    cout<<"After Reversal of k nodes: "; 
    Node* newHead = reverseInKNodes(head,k);
    printLList(newHead);
}