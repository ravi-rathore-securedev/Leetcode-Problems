/*
1122. Relative Sort Array
Solved
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 */
 
 #include<bits/stdc++.h>
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       int maxx= *max_element(arr1.begin(),arr1.end());
       vector<int>count(maxx+1,0);
       vector<int>res;
       
       for(int i=0;i<arr1.size();i++){
        count[arr1[i]]++;
       }
       for(int i=0;i<arr2.size();i++){
        while(count[arr2[i]]>0){
            res.push_back(arr2[i]);
            count[arr2[i]]--;
        }
       }
       for(int i=0;i<count.size();i++){
        if(count[i]!=0){
            while(count[i]>0){
            res.push_back(i);
            count[i]--;
            }
        }
       }
       
       return res;
    }
};