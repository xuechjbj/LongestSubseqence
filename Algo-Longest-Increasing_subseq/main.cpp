//
//  main.cpp
//  Algo-Longest-Increasing_subseq
//
//  Created by Chaojun Xue on 1/13/16.
//  Copyright © 2016 Chaojun Xue. All rights reserved.
//
/*
 https://leetcode.com/problems/longest-increasing-subsequence/
 
 Given an unsorted array of integers, find the length of longest increasing subsequence.
 
 For example,
 Given [10, 9, 2, 5, 3, 7, 101, 18],
 The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 
 Your algorithm should run in O(n2) complexity.
 
 Follow up: Could you improve it to O(n log n) time complexity?
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int *dp = new int[nums.size()];
        int maxx = 0;
        memset(dp, '\0', sizeof(int)*nums.size());
        
        for(int i = nums.size() - 2; i>=0; i--){
            int head = nums[i];
            int max = 0;
            for(int j = i+1; j<nums.size(); j++){
                if(head < nums[j]){
                    int seq = dp[j]+1;
                    if(seq>max)
                        max = seq;
                }
            }
            dp[i] = max;
            if(max > maxx){
                maxx = max;
            }
            
        }
        delete []dp;
        return maxx+1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums={10,9,2,5,3,4};
    Solution sol;
    std::cout << "Hello, World!\n"<<sol.lengthOfLIS(nums)<<"\n";
    return 0;
}
