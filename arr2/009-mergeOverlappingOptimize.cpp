#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>merge(vector<vector<int>>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;

    for(int i=0;i<n;i++){
        if(ans.empty()||ans.back()[1]<arr[i][0]){
            vector<int>v={
                arr[i][0],
                arr[i][1]
            };
            ans.push_back(v);
        }else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>>arr;
    arr={{1,3},{2,4},{2,6},{8,9},{8,10},{9,11},{15,21},{16,20},{17,20},{20,25}};
    vector<vector<int>>ans=merge(arr);
    cout<<"Merged Overlapping Intervals are: "<<endl;
    for(auto it:ans){
        cout<<it[0]<<" "<<it[1]<<endl;
    }

}    