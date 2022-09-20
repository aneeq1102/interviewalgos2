//  https://leetcode.com/problems/flood-fill/

#include<iostream>
#include<vector>
using namespace std;


void helper(vector<vector<int>>& img,int row,int col,int prev_color,int color,int row_c,int col_c){
    if(row >= row_c || col >= col_c || row < 0 || col <0){
        return;
    }
    
    if(img[row][col] == prev_color){
        img[row][col]=color;
    }else{
        return;
    }
    
    helper(img,row+1,col,prev_color,color,row_c,col_c);
    helper(img,row-1,col,prev_color,color,row_c,col_c);
    helper(img,row,col+1,prev_color,color,row_c,col_c);
    helper(img,row,col-1,prev_color,color,row_c,col_c);
    
    
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color) return image;
    helper(image,sr,sc,image[sr][sc],color,image.size(),image[0].size());
    
    return image;
}

int main(){

    vector<vector<int>> img = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    floodFill(img,1,1,2);

    for(auto x:img){
        for(auto y:x){
            cout<<y<<"  ";
        }
        cout<<'\n';
    }

    return 0;
}