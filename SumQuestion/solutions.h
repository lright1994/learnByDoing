#ifndef CLASS_H
#define CLASS_H

#include<map>
#include<hash_map>
#include<iostream>

using namespace std;

//(Brute Force)暴力算法 复杂度O(n*n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> twoSum;
        auto solutionNum=0;
        for(size_t i=0;i<nums.size();i++)
        {
            for(size_t j=i;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    twoSum.push_back(i);
                    twoSum.push_back(j);
                    solutionNum++;
                }
            }
        }
        return twoSum;
    }
    //(Two-pass Hash Table)
    vector<int> twoSumHash(vector<int> nums,int target)
    {
        //哈希映照容器，第一元素为key值（不可重复），第二为value（可重复）
        std::hash_map<int,int>map;
        for(size_t i=0;i<nums.size();i++)
        {
            map[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int complement=target-nums[i];
            if(map.find(complement)!=map.end()&&map.at(complement)!=i)
            {
                vector<int> result {i,map.at(complement)};
                return result;
            }
            //还没学会在c++里面抛出异常
            //throw new IllegalArgumentException
        }

    }
    //(sorted twoSum)已经按照上升排序了
    vector<int> twoSumSorted(vector<int>& numbers, int target)
    {
        std::hash_map<int,int>map;

    }
   // std::ListNode* h;

};




#endif // CLASS_H
