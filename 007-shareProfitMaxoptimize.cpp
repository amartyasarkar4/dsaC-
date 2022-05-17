#include<bits/stdc++.h>
using namespace std;


int maxProfit(vector<int>&stPric){
    int maxProfitval=0;
    int minVal8=INT8_MAX;
    // cout<<minVal8<<endl;
    // int minVal16=INT16_MIN;
    // cout<<minVal16<<endl;
    // int minVal32=INT32_MIN;
    // cout<<minVal32<<endl;
    // long int minVal64=INT64_MIN;
    // cout<<minVal64<<endl;
    for(int i=0;i<stPric.size();i++){
        minVal8=min(stPric[i],minVal8);
        maxProfitval=max((stPric[i]-minVal8),maxProfitval);
    }
    return maxProfitval;
}

int main(){
    vector<int>stPrices;
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        int val;
        cin>>val;
        stPrices.push_back(val);
    }
    for(auto it:stPrices){
        cout<<it<<" ";
    }
    int prof=maxProfit(stPrices);
    cout<<"Maximum profit is: "<<prof<<endl;
}