#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node * next;
    Node(int a=0){
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
        cout<<"Linked List is Empty."<<endl;
    }
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"-->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
Node * addTwoNumbers(Node * l1,Node * l2){
    Node * dummy=new Node();
    Node * temp=dummy;
    int carry=0;
    while(l1!=NULL||l2!=NULL||carry){
        int sum=0;
        if(l1!=NULL){
            sum=sum+l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum=sum+l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node * valNode=new Node(sum%10);
        temp->next=valNode;
        temp=temp->next;
    }
    return dummy->next;
}
int main(){
    Node * num1=NULL;
    insertNode(num1,6);
    insertNode(num1,8);
    insertNode(num1,1);
    Node * num2=NULL;
    insertNode(num2,2);
    insertNode(num2,3);
    insertNode(num2,4);
    printLList(num1);
    printLList(num2);
    Node * sumOfLList=addTwoNumbers(num1,num2);
    printLList(sumOfLList);
}