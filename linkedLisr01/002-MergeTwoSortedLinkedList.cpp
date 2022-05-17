#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int num;
        Node * next;
        Node(int val){
            num=val;
            next=NULL;
        }
};
void insertNode(Node * &head,int val){
    Node * newNode=new Node(val);
    if(head==NULL){
        // cout<<"Head was empty"<<endl;
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
        cout<<"Linked lIst iis Empty."<<endl;
    }
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->num<<"-->";
        temp=temp->next;
    }
    cout<<"Null\n";
}
Node * mergeTwoSortedList(Node * l1,Node * l2){
    if(l1==NULL)return l2;
    if(l2==NULL)return l1;

    if(l1->num>l2->num)swap(l1,l2);

    Node * res=l1;
    printLList(res);
    while(l1!=NULL && l2!=NULL){
        Node * temp=NULL;
        while(l1!=NULL && l1->num<=l2->num){
            temp=l1;
            printLList(temp);
            l1=l1->next;
        }
        temp->next=l2;
        printLList(l1);
        printLList(res);
        printLList(temp);
        swap(l1,l2);
    }
    return res;
}
int main(){
    Node * l1head=NULL;
    insertNode(l1head,5);
    insertNode(l1head,7);
    insertNode(l1head,9);
    insertNode(l1head,13);
    insertNode(l1head,16);
    
    Node * l2head=NULL;
    insertNode(l2head,4);
    insertNode(l2head,6);
    insertNode(l2head,10);
    insertNode(l2head,15);

    printLList(l1head);
    printLList(l2head);

    Node * merged=mergeTwoSortedList(l1head,l2head);
    printLList(merged);

}