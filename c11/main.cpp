#include <QCoreApplication>

#include "cbook.h"
#include "global.h"

#include <string>


template <typename T1, typename T2>
//auto做位函数类型时要在后面加decltype来确定返回类型
auto compose(T1 t1,T2 t2)->decltype(t1+t2)
{
    return t1+t2;
}

//测试lambda函数能否传入普通函数!!!为什么传不进去？？？
/*
template <typename findInfo>
bool findRightBook(findInfo)
{
    const int info=100;
    if(findInfo(info))
    {
        std::cout<<"Number is right"<<std::endl;
        return true;
    }
    else
    {
        std::cout<<"Number is wrong"<<std::endl;
        return false;
    }
}
*/

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    BasicBook ComicBook(110,10.);
    ComicBook.printInfo();

    DiscountBook pythonBook(112,50.);
    pythonBook.setDiscount(0.7);
    std::cout<<("PythonBook is only %l",pythonBook.getPrice())<<std::endl;

    //==========虚函数可以通过基类的指针调用派生类的函数=============
    BasicBook *bookPtr;
    bookPtr=&pythonBook;
    std::cout<<"Size of Basicbook is  "<<sizeof(BasicBook)<<std::endl;
    std::cout<<bookPtr->getPrice()<<std::endl;

    //============调试未通过!!!!!!!!!!!!!!!!!!!!!!! lambda函数========================//
    //普通lambda函数没问题，但是作为函数传入时报错C2440
    auto returnTrue=[&](const int bookInfo){return bookInfo==100;};
    //std::cout<<ComicBook.findRightBook(returnTrue)<<std::endl;
    //findRightBook(returnTrue);

    //=================auto作函数声明位，以及template占位符===============
    auto v=compose(1,2.5);
    std::cout<<("This is %l",v)<<std::endl;

    //===========================std::map的相关操作================
    std::map<std::string,int> map;
    map["one"]=1;
    map["Two"]=2;
    map["Three"]=3;
    std::map<std::string,int>::iterator itMap;
    for(itMap=map.begin();itMap!=map.end();++itMap)
    {
        std::cout<<(*itMap).first<<std::endl;
    }
    for(auto kvp: map)
    {
        std::cout<<kvp.second<<std::endl;
    }

    //=======================强枚举类型====================================//
    SelectOptions sOptions=SelectOptions::ALL;
    std::cout<<(int)sOptions<<std::endl;


    //=========================智能指针,难度较高先跳过==================================//

    //==========================非成员begin()和end()=================================//
    int arr[]={1,2,3};
    std::for_each(std::begin(arr),std::end(arr),[](int n){std::cout<<n<<std::endl;});
    std::string testStr="a test";
    std::for_each(std::begin(testStr),std::end(testStr),[](char n){std::cout<<n;});
    //=========stl里面很多有用的，例如for_each例如find_if和lambda函数配合能大大缩减代码量




    return a.exec();

}
