#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        vector<int>twoSum(vector<int>&nums,int target){
            vector<int>ans;
            unordered_map<int,int>mpp;

            for(int i=0;i<nums.size();i++){
                if(mpp.find(target-nums[i])!=mpp.end()){
                    ans.push_back(mpp[target-nums[i]]);
                    ans.push_back(i);
                    return ans;
                }
                mpp[nums[i]]=i;
            }
            return ans;
        }
        vector<int>twoSumViewNumber(vector<int>&nums,int target){
            vector<int>ans;
            unordered_map<int,int>mpp;

            for(int i=0;i<nums.size();i++){
                if(mpp.find(target-nums[i])!=mpp.end()){
                    ans.push_back(target-nums[i]);
                    ans.push_back(nums[i]);
                    return ans;
                }
                mpp[nums[i]]=i;
            }
            return ans;
        }
};
int main(){
    vector<int>num;
    int n;
    cin>>n;
    while(n--){
        int itm;
        cin>>itm;
        num.push_back(itm);
    }
    // for(auto it:num){
    //     cout<<"it: "<<it<<" ";
    // }
    Solution sol1;
    int target;
    cout<<"\n Enter target value";
    cin>>target;
    vector<int>finalAns;
    vector<int>finalView;
    finalAns=sol1.twoSum(num,target);
    finalView=sol1.twoSumViewNumber(num,target);
    for(auto it:finalAns){
        cout<<"it: "<<it<<" ";
    }
    for(auto itV:finalView){
        cout<<"\nView: "<<itV<<" ";
    }

}