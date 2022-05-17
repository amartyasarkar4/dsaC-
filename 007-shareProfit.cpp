#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>&stPric){
    int maxProfitval=0;
    for(int i=0;i<stPric.size();i++){
        for(int j=i+1;j<stPric.size();j++){
            if(stPric[j]>stPric[i]){
                maxProfitval=max((stPric[j]-stPric[i]),maxProfitval);
            }
        }
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