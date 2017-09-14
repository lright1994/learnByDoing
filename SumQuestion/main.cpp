#include <QCoreApplication>

using namespace std;

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
};




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> test;
    test.push_back(3);
    test.push_back(2);
    test.push_back(4);
    auto target=6;

    Solution solutionTest;

    solutionTest.twoSum(test,target);

    return a.exec();
}
