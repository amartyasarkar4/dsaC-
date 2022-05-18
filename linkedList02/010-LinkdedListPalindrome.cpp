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
        cout<<"Head was NULL"<<endl;
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
bool isPalindrome(Node * head){
    vector<int>arr;
    Node * temp=head;
    while(temp!=NULL){
        arr.push_back(temp->val);
        temp=temp->next;
    }
    for(int i=0;i<arr.size()/2;i++){
        // cout<<"Checkinh for"<<arr[i]<<arr.size()/2<<endl;
        if(arr[i]!=arr[arr.size()-i-1])return false;
    }
    return true;
}
Node * reverse(Node * head){
    Node * pre=NULL;
    Node * current=head;
    Node * nxt;
    while(current){
        nxt=current->next;
        current->next=pre;

        pre=current;
        current=nxt;
    }
    return pre;
}
bool isPalindrome2(Node * head){
    if(head==NULL||head->next==NULL)return head;

    Node * slow= head;
    Node * fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverse(slow->next);
    slow=slow->next;
    Node * dummy=head;
    while(slow!=NULL){
        if(dummy->val!=slow->val)return false;
        dummy=dummy->next;
        slow=slow->next;
    }
    return true;
}
int main(){
    Node * head=NULL;
    insertNode(head,12);
    insertNode(head,3);
    insertNode(head,7);
    insertNode(head,13);
    insertNode(head,7);
    insertNode(head,3);
    insertNode(head,12);
    // insertNode(head,3);
    printLList(head);

    if(isPalindrome(head)){
        cout<<"Yes "<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    if(isPalindrome2(head)){
        cout<<"Yes "<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}