#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>>generate(int numRow){
        vector<vector<int>>r(numRow);
        for(int i=0;i<numRow;i++){
            r[i].resize(i+1);
            r[i][0]=r[i][i]=1;
            for(int j=1;j<i;j++){
                r[i][j]=r[i-1][j-1]+r[i-1][j];
            }
        }
        return r;   
    }
};
int main(){
    int n;
    cin>>n;
    Solution s1;
    vector<vector<int>>pascal;
    pascal=s1.generate(n);
    int l=n;
    for(int i=0;i<pascal.size();i++){
        for(int sp=0;sp<=l-1;sp++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<pascal[i][j]<<" ";
        }
        l--;
        cout<<"\n";
    }
}