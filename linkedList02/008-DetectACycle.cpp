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
        cout<<"Head was NUll"<<endl;
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
        cout<<"Linked List is empty"<<endl;
    }
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"-->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
void createCycle(Node * & head,int a,int b){
    int cnta=0,cntb=0;
    Node * p1=head;
    Node *p2=head;
    while(cnta!=a||cntb!=b){
        if(cnta!=a){
            p1=p1->next;
            cnta++;
        }
        if(cntb!=b){
            p2=p2->next;
            ++cntb;
        }
    }
    if(cnta>cntb){
        p1->next=p2;
    }
    p2->next=p1;
}
// =======================
// Cycle Detect By hashing
//
Node * cycleDetect(Node * head){
    Node * temp=head;
    unordered_set<Node*>hashTable;
    while(temp!=NULL){
        if(hashTable.find(temp)!=hashTable.end())return temp;
        hashTable.insert(temp);
        temp=temp->next;
    }
    return NULL;
}
// =======================
// Cycle Detect 2 by slow and fast approach
// 
Node * cycleDetect2(Node * head){
    if(head==NULL)return NULL;
    Node * temp=head;
    Node * fast=temp;
    Node * slow=temp;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow)return slow;
    }
    return NULL;
}
int main(){
    Node * head=NULL;
    insertNode(head,12);
    insertNode(head,3);
    insertNode(head,7);
    insertNode(head,9);
    insertNode(head,4);
    printLList(head);

    createCycle(head,4,2);
    Node * find=cycleDetect(head);
    if(find!=NULL){
        cout<<"Cycle Detected at "<<find->val<<endl;
    }else{
        cout<<"No cycle detected"<<endl;
    }

    Node * find2=cycleDetect2(head);
    if(find!=NULL){
        cout<<"Cycle Detected By slow fast approach at "<<find->val<<endl;
    }else{
        cout<<"No cycle detected"<<endl;
    }

}