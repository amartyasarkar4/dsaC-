#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>rotate_90(vector<vector<int>>&matrix){
    int k=matrix.size();
    vector<vector<int>>rotated(k,vector<int>(k,0));
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            rotated[j][k-i-1]=matrix[i][j];
        }
    }
    return rotated;
}

int main(){
    vector<vector<int>>matrix;
    matrix={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>>finalRotated=rotate_90(matrix);
    cout<<"Final Rotated Matrix is: "<<endl;
    for(int i=0;i<finalRotated.size();i++){
        for(int j=0;j<finalRotated.size();j++){
            cout<<finalRotated[i][j]<<" ";
        }
        cout<<"\n";
    }
}