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
    // void insertBegin(int val){
    //     if
    // }
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
        cout<<"Linked List is empty"<<endl;
    }
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"-->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
// ============================
// Approach 1 Hashing By Unordered SET------>
// 
Node * intersectionPresent1(Node * head1,Node * head2){
    unordered_set<Node*>st;
    while(head1!=NULL){
        st.insert(head1);
        head1=head1->next;
    }
    while(head2!=NULL){
        if(st.find(head2)!=st.end())return head2;
        head2=head2->next;

    }
    return NULL;
}
// ==========================
// Approach 2-------------->
// 
int getDifference(Node * head1,Node * head2){
    int len1=0,len2=0;
    while(head1!=NULL||head2!=NULL){
        if(head1!=NULL){
            ++len1;
            head1=head1->next;
        }
        if(head2!=NULL){
            ++len2;
            head2=head2->next;
        }
    }
    return len1-len2;
}
Node * intersectionPresent2(Node * head1,Node * head2){
    int diff=getDifference(head1,head2);
    if(diff<0){
        while(diff++!=0)head2=head2->next;
    }else{
        while(diff--!=0)head1=head1->next;
    }
    while(head1!=NULL){
        if(head1==head2)return head1;
        head2=head2->next;
        head1=head1->next;
    }
    return head1;
}
// ============================
// Approach 3----------------->
// 
Node * intersectionPresent3(Node * head1,Node * head2){
    Node * d1=head1;
    Node * d2=head2;

    while(d1!=d2){
        d1=(d1==NULL?head2:d1->next);
        d2=(d2==NULL?head1:d2->next);
    }
    return d1;
}
// =================================
// Approach4------------>
// 
Node * intersectionPresent4(Node * head1,Node * head2){
    while(head2!=NULL){
        Node * temp=head1;
        while(temp!=NULL){
            if(temp==head2)return head2;
            temp=temp->next;
        }
        head2=head2->next;
    }
    return NULL;
}

// =======================
// Main---------------->
// 
int main(){
    Node * list1=NULL;
    insertNode(list1,1);
    insertNode(list1,3);
    insertNode(list1,1);
    insertNode(list1,2);
    insertNode(list1,4);
    insertNode(list1,9);
    Node * list2=NULL;
    insertNode(list2,3);
    insertNode(list2,8);
    Node * common=list1->next->next->next;
    list2->next->next=common;
    printLList(list1);
    printLList(list2);

    Node * intersected=intersectionPresent1(list1,list2);
    printLList(intersected);

    Node * intersected2=intersectionPresent2(list1,list2);
    printLList(intersected2);

    Node * intersected3=intersectionPresent3(list1,list2);
    printLList(intersected3);

    Node * intersected4=intersectionPresent4(list1,list2);
    printLList(intersected4);
    // Node* head = NULL;
    // insertNode(head,1);
    // insertNode(head,3);
    // insertNode(head,1);
    // insertNode(head,2);
    // insertNode(head,4);
    // Node* head1 = head;
    // head = head->next->next->next;
    // Node* headSec = NULL;
    // insertNode(headSec,3);
    // Node* head2 = headSec;
    // headSec->next = head;
    // //printing of the lists
    // cout<<"List1: "; printLList(head1);
    // cout<<"List2: "; printLList(head2);
    // //checking if intersection is present
    // Node* answerNode = intersectionPresent1(head1,head2);
    // if(answerNode == NULL )
    // cout<<"No intersection\n";
    // else
    // cout<<"The intersection point is "<<answerNode->val<<endl;
}