#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node * next;
    Node(int a){
        val=a;
        next=NULL;
    }
};
void insertNode(Node * &head,int val){
    Node * newNode=new Node(val);
    if(head==NULL){
        cout<<"Head was Null"<<endl;
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
        cout<<"Linked List is Empty!!"<<endl;
    }
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"-->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
Node * removeNthFromEnd(Node * head,int n){
    int val=8;
    Node * start=new Node(val);
    start->next=head;
    Node * fast=start;
    Node * slow=start;
    int count=0;
    for(int i=1;i<=n && fast->next!=NULL;i++){
        count++;
        fast=fast->next;
    }
    cout<<"Count: "<<count<<endl;
    if(count<n){
        cout<<"Size of Linked List is smaller than you want to delete nth Node."<<endl;
        return head;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return start->next;
}
int main(){
    Node * head=NULL;
    insertNode(head,2);
    insertNode(head,9);
    insertNode(head,3);
    insertNode(head,7);
    insertNode(head,23);

    printLList(head);

    head=removeNthFromEnd(head,8);
    printLList(head);

}