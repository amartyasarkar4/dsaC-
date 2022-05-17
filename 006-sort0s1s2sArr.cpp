#include<bits/stdc++.h>
using namespace std;
void printArr(vector<int>&nums){
    for(auto it:nums){
        cout<<it<<" ";
    }
}
class Solution{
    public:
    void sortColors(vector<int>&nums){
        int lo=0;
        int hi=nums.size()-1;
        int mid=0;
        while(mid<=hi){
            cout<<"\nFirst:";
            printArr(nums);
            switch(nums[mid]){
                case 0:
                    cout<<"Case0:lo="<<lo<<" mid="<<mid<<" & hi="<<hi<<endl;
                    swap(nums[lo++],nums[mid++]);
                    cout<<"\n";
                    printArr(nums);
                    break;
                case 1:
                    cout<<"Case1:lo="<<lo<<" mid="<<mid<<" & hi="<<hi<<endl;
                    mid++;
                    cout<<"\n";
                    printArr(nums);
                    break;
                case 2:
                    cout<<"Case 2:lo="<<lo<<" mid="<<mid<<" & hi="<<hi<<endl;
                    swap(nums[mid],nums[hi--]);
                    cout<<"\n";
                    printArr(nums);
                    break;
            }
        }
    }
};
int main(){
    vector<int>nums;
    nums={2,0,2,1,1,0};
    // for(auto it:nums){
    //     cout<<it<<" ";
    // }
    Solution s1;
    s1.sortColors(nums);
    cout<<"After Sorting: "<<endl;  
    for(auto it:nums){
        cout<<it<<" ";
    }


}