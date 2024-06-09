/*
523. Continuous Subarray Sum
Medium
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
*/

//optimal approach
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            pre[i]=pre[i]%k;
        }
        map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(mp.find(pre[i])!=mp.end()){
            int ind=mp[pre[i]];
            if((i-ind)>1){
                return true;
            }
            }
            else{
                mp[pre[i]]=i;
            }
        }
        return false;
    }
};

//Brute apporach
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2){
            return false;
        }
        for(int i=0;i<n;i++){
            long long sum=0;
            sum+=nums[i];
            
            for(int j=i+1;j<n;j++){
                sum+=nums[j];

                if(sum%k==0){
                    return true;
                }
            }
        }
        return false;
    }
};