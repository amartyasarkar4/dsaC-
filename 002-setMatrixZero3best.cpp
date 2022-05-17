#include<bits/stdc++.h>
using namespace std;
void setZero(vector<vector<int>>&matrix){
    int rows=matrix.size(),cols=matrix[0].size();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==0){
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }
    for(int i=rows-1;i>=0;i--){
        for(int j=cols-1;j>=0;j--){
            if(matrix[i][0]==0||matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
        // if (col0 == 0) {
        //     matrix[i][0] = 0;
        // }
    }
}
int main(){
    vector<vector<int>>arr;
    arr={{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    setZero(arr);
    cout<<"The Final Matrix is "<<endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}