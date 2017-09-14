#include <QCoreApplication>
#include "solutions.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> sortedArray{1,2,3,3,4,4,5};
    Solutions solution;
    std::cout<<solution.RemoveDuplicates(sortedArray)<<std::endl;

    /*
    std::vector<int> sortedArray2{1,1,1,2,2,3,3,4,4,4};
    std::cout<<solution.RemoveDupTwice(sortedArray2)<<std::endl;
    for(auto kvp:sortedArray2)
    {
        std::cout<<kvp<<std::endl;
    }
    */

    return a.exec();
}
