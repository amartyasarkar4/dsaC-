#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>merge(vector<pair<int,int>>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<pair<int,int>>ans;

    for(int i=0;i<n;i++){
        int start=arr[i].first,end=arr[i].second;

        if(!ans.empty()){
            if(start<=ans.back().second){
                continue;
            }
        }
        
        for(int j=i+1;j<n;j++){
            if(arr[j].first<=end){
                end=max((arr[j].second),end);
            }
        }
        ans.push_back({
            start,end
        });
        cout<<ans.back().first<<" & "<<ans.back().second<<endl;
    }
    return ans;
}
int main(){
    vector<pair<int,int>>arr;
    arr={{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,21},{16,20},{17,20},{20,25}};
    vector<pair<int,int>>ans=merge(arr);
    cout<<"Merged Overlapping Intervals are: "<<endl;
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }

}    