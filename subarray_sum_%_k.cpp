/*
974. Subarray Sums Divisible by K
Solved
Medium
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
*/

//optimal approach
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        int res=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int mod=sum%k;
            if(mod<0){
                mod=mod%k+k;
            }
            // int mod = (sum % k + k) % k; 
            if(mp.find(mod)!=mp.end()){
                res+=mp[mod];

            }
                mp[mod]++;
        }
        return res;

    }
};