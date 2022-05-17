#include<bits/stdc++.h>
using namespace std;
void mergeByGap(int arr1[],int arr2[],int n,int m){
    cout<<"Entered Into Merge By Gap"<<endl;
    int gap=ceil((float)(n+m)/2);
    while(gap>0){
        int i=0;
        int j=gap;
        while(j<(n+m)){
            // cout<<"perform"<<endl;
            if(j<n && arr1[i]>arr1[j]){
                // cout<<"perform"<<endl;
                swap(arr1[i],arr1[j]);
            }else if(j>=n && i<n && arr1[i]>arr2[j-n]){
                // cout<<"perform"<<endl;
                swap(arr1[i],arr2[j-n]);
            }else if(j>=n && i>=n && arr2[i-n]>arr2[j-n]){
                // cout<<"perform"<<endl;
                swap(arr2[i-n],arr2[j-n]);
            }
            j++;
            i++;
        }
        
        if(gap==1){
            cout<<"Exiting from gap"<<endl;
            gap=0;
        }else{
            gap=ceil((float)gap/2);
        }
    }
}

int main(){
    int arr1[]={1,4,7,8,10};
    int arr2[]={2,3,9};
    cout<<"Before merge: "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<3;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<"\n";
    mergeByGap(arr1,arr2,5,3);
    cout<<"After merge: "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<3;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<"\n";
}