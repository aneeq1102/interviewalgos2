#include</home/aneeq/Public/bits/stdc++.h>
using namespace std;
//algorithm to perform binary search for an elemnet in a sorted array and returrn index

int binarySearch(vector<int> nums,int n,int ele){
    int low =0,high = n-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(ele < nums[mid]){
            high = mid-1;
        }
        else if(ele > nums[mid]){
            low = mid+1;
        }
        else{
            return mid;
        }
    }

    return -1;

}

int main(){

    cout<<binarySearch(vector<int> {2,4,6,8,10,12},6,4)<<endl;


    return 0;
}