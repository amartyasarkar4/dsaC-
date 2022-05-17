#include<bits/stdc++.h>
using namespace std;
void printVec(vector<vector<int>>&fAns){
    for(int i=0;i<fAns.size();i++){
        for(int j=0;j<fAns[0].size();j++){
            cout<<fAns[i][j]<<" ";
        }
        cout<<"\n";
    }
}
class Solution{
    public:
        void recurPermute(int index,vector<int>&nums,vector<vector<int>>&ans){
            if(index==nums.size()){
                ans.push_back(nums);
                return;
            }
            for(int i=index;i<nums.size();i++){
                // cout<<"Before 1st swap i="<<i<<" & index= "<<index<<endl;
                // printVec(ans);
                swap(nums[index],nums[i]);
                // cout<<"after 1st swap i="<<i<<" & index= "<<index<<endl;
                // printVec(ans);
                recurPermute(index+1,nums,ans);
                // cout<<"after recur of before 2nd swap i="<<i<<" & index= "<<index<<endl;
                // printVec(ans);
                swap(nums[index],nums[i]);
                // cout<<"after 2nd swap i="<<i<<" & index= "<<index<<endl;
                // printVec(ans);
            }
        }
        vector<vector<int>>permute(vector<int>&nums){
            vector<vector<int>>ans;
            recurPermute(0,nums,ans);
            return ans;
        }
};

int main(){
    int n;
    cin>>n;
    vector<int>nums;
    while(n--){
        int nip;
        cin>>nip;
        nums.push_back(nip);
    }
    // for(auto it:nums){
    //     cout<<it<<" ";
    // }
    vector<vector<int>>fAns;
    Solution s1;
    fAns=s1.permute(nums);
    for(int i=0;i<fAns.size();i++){
        for(int j=0;j<fAns[0].size();j++){
            cout<<fAns[i][j]<<" ";
        }
        cout<<"\n";
    }
}