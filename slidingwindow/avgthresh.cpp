https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/submissions/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;
        int count = 0;
        
        int sum = 0;
        for(int right = 0; right<arr.size();right++){
            sum += arr[right];
            
            if(right+1 < k){
                continue;
            }
            
            while(right - left +1> k){
                sum -= arr[left];
                left++;
            }
            if(float(sum)/k >= threshold){
                count++;
            }
        }
        return count;
    }
};