#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int num;
        Node * next;
        Node(int a){
            num=a;
            next=NULL;
        }
};
void insertNode(Node* &head,int val){
    Node * newNode=new Node(val);
    // cout<<"New node created"<<endl;
    if(head==NULL){
        // cout<<"head Null tha"<<endl;
        head=newNode;
        return;
    }
    Node * temp=head;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=newNode;
}
void printLList(Node * head){
    if(head==NULL){
        cout<<"Linked List is Empty";
    }else{
        Node * temp=head;
        while(temp!=NULL){
            cout<<temp->num<<"-->";
            temp=temp->next;
        }
    }
}
Node * getNode(Node * head,int val){
    Node * temp=head;
    while(temp->num!=val){
        temp=temp->next;
    }
    return temp;
}
void deleteNode(Node * &head,int val){
    if(head->num==val){
        Node * willBeDeleted=head;
        head=head->next;
        delete(willBeDeleted);
        return;
    }
    Node * temp=head;
    while(temp->next!=NULL){
        if(temp->next->num==val){
            Node * prevNode=temp;
            Node * willBedeletedNode=temp->next;
            prevNode->next=willBedeletedNode->next;
            delete(willBedeletedNode);
            return;
        }
        temp=temp->next;
    }
    if(temp->next==NULL){
        cout<<"Node is not present"<<endl;
    }
    return;
    
}
Node * reverseList1(Node * head){
    Node * prev_p=NULL;
    Node * current_p=head;
    Node * next_p;
    while(current_p){
        next_p=current_p->next;
        current_p->next=prev_p;

        prev_p=current_p;
        current_p=next_p;
    }
    head=prev_p;
    return head;
}
Node * reverseList2(Node * head){
    Node * newHead=NULL;
    while(head!=NULL){
        Node * next=head->next;
        head->next=newHead;
        newHead=head;
        head=next;
    }
    return newHead;
}
Node * reverseList3(Node * head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node * newNode=reverseList3(head->next);
    head->next->next=head;
    head->next=NULL;
    return newNode;
}
Node * MiddleNode1(Node * head){
    Node * temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    temp=head;
    for(int i=0;i<(count/2);i++){
        temp=temp->next;
    }
    return temp;
}
// Tortoise-Hare-Approach
Node * MiddleNode2TortoiseHare(Node * head){
    Node * slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next,fast=fast->next->next;
    }
    return slow;

}
int main(){
    Node *head=NULL;
    // cout<<"hello"<<endl;
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,14);
    insertNode(head,32);
    insertNode(head,7);
    insertNode(head,1);
    insertNode(head,67);
    printLList(head);

    
    deleteNode(head,1);
    deleteNode(head,7);
    deleteNode(head,32);
    // deleteNode(head,2);
    // deleteNode(head,3);
    cout<<"After deleting the Node : "<<endl;
    printLList(head);

    head=reverseList1(head);
    cout<<"After Reverse th ListNode : "<<endl;
    printLList(head);

    head=reverseList2(head);
    cout<<"After Reverse th ListNode : "<<endl;
    printLList(head);

    head=reverseList3(head);
    cout<<"After Reverse th ListNode : "<<endl;
    printLList(head);

    Node * Middle=MiddleNode1(head);
    cout<<"Middle Node val is: "<<endl;
    cout<<Middle->num<<endl;
    Node * MiddleTortoiseHare=MiddleNode2TortoiseHare(head);
    cout<<"Middle Node val Usind Tortoise-Hare-Approach: "<<endl;
    cout<<MiddleTortoiseHare->num<<endl;
}