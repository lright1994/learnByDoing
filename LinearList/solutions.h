#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

class Solutions
{
public:
    //Remove Duplicates from Sorted Array
    //time o(n), space o(n)
    int RemoveDuplicates(std::vector<int> &nums)
    {
        //std::unique去重
        return std::distance(nums.begin(),std::unique(nums.begin(),nums.end()));
    }

    //Duplicates are sllowed at most twice
    //不可用，因为unique后后面的数据不是排列好的
    int RemoveDupTwice(std::vector<int> &nums)
    {
        int uniqueNums=std::distance(nums.begin(),std::unique(nums.begin(),nums.end()));
        int uniqueTwiceNums=std::distance(nums.begin(),std::unique(nums.begin()+uniqueNums,nums.end()));
        return uniqueTwiceNums;
    }
};




#endif // SOLUTIONS_H
