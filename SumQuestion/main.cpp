#include <QCoreApplication>
#include "solutions.h"
#include <iostream>
#include "football.h"


//c++的数据读取找到一个完美的方案！！！！！！！！！！！！（用标准容器）

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> test{1,5,3};
    auto target=6;

    Solution solutionTest;
/*
    //随意输入的vector
    for(auto kvp:solutionTest.twoSum(test,target))
    {
        //cout<<kvp<<endl;
    }
    for(auto kvp:solutionTest.twoSumHash(test,target))
    {
        cout<<kvp<<endl;
    }
*/
    FootBall*foot_ball_=new FootBall;
    foot_ball_->defineTeam();


    return a.exec();
}
