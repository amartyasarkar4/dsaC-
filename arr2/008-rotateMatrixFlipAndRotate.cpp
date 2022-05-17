#include<bits/stdc++.h>
using namespace std;
void flip(vector<vector<int>>&image){
    int n=image.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(image[i][j],image[j][i]);
        }
    }
}
void reverse(vector<vector<int>>&image){
    for (int i = 0; i < image.size(); i++) {
        reverse(image[i].begin(), image[i].end());
    }
}
void printImage(vector<vector<int>>&image){
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image.size();j++){
            cout<<image[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    vector<vector<int>>image;
    image={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    flip(image);
    cout<<"Flipped by diagonal: "<<endl;
    printImage(image);
    reverse(image);
    cout<<"after reverse it is rotated by diagonal: "<<endl;
    printImage(image);

}