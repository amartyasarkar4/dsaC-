#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node * next;
        Node * bottom;
        Node(int a=0){
            this->val=a;
            this->next=NULL;
            this->bottom=NULL;
        }
};
void insertNode(Node * &root,int val){
    Node * newNode=new Node(val);
    if(root==NULL){
        cout<<"root was NULL"<<endl;
        root=newNode;
        return;
    }
    Node * temp=root;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
Node * getNode(Node * root,int top){
    Node * temp=root;
    while(temp!=NULL){
        if(temp->val==top)return temp;
        temp=temp->next;
    }
    return NULL;
}
void insertBottom(Node * root,int top,int val){
    Node * topNode=getNode(root,top);
    if(topNode==NULL){
        cout<<"Node el can not find !! .."<<endl;
        return;
    }else{
        Node * newBottomNode=new Node(val);
        while(topNode->bottom!=NULL){
            topNode=topNode->bottom;
        }
        topNode->bottom=newBottomNode;
    }
}
void printLList(Node * root){
    if(root==NULL){
        cout<<"Linked list is Empty"<<endl;
        return;
    }
    
    Node * big=root;
    while(big!=NULL){
        Node * temp=big;
        while(temp!=NULL){
            cout<<temp->val<<"-->";
            temp=temp->bottom;
        }
        cout<<"NULL\n";
        big=big->next;
    }
    
    cout<<"NULL\n";
}
Node * mergeTwoLists(Node * a,Node *b){
    Node * temp=new Node();
    Node * res=temp;
    while(a!=NULL && b!=NULL){
        if(a->val<b->val){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }else{
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
    }
    if(a)temp->bottom=a;
    else temp->bottom=b;

    return res->bottom;
}
Node * flatten(Node * root){
    Node * tem=root;
    if(tem==NULL||tem->next==NULL)return root;

    tem->next=flatten(tem->next);
    tem=mergeTwoLists(tem,tem->next);

    return tem;
}
int main(){
    Node * root=NULL;
    insertNode(root,5);
    insertNode(root,10);
    insertNode(root,2);
    insertNode(root,28);

    insertBottom(root,5,7);
    insertBottom(root,5,8);
    insertBottom(root,5,10);

    insertBottom(root,10,32);

    insertBottom(root,2,20);
    insertBottom(root,2,50);

    insertBottom(root,28,30);
    insertBottom(root,28,31);
    insertBottom(root,28,45);
    printLList(root);

    Node * flat=flatten(root);
    printLList(flat);
}