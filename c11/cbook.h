#ifndef CBOOK_H
#define CBOOK_H

#include<iostream>

class BasicBook
{
public:

    BasicBook(int Info,int price):bookInfo(Info),basicPrice(price){}

    void printInfo()
    {
        std::cout<<("This book is %s",bookInfo)<<std::endl;
    }

    virtual double getPrice()
    {
        return basicPrice;
    }

    //通过匿名函数实现“函数作为参数的功能”!没有编译通过！
    template <typename findInfo>
    bool findRightBook(findInfo)
    {
        if(findInfo(this->bookInfo))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    const int bookInfo;
protected:
    const double basicPrice;
};

class DiscountBook:public BasicBook
{
public:
    DiscountBook(int Info,double price):BasicBook(Info,price)
    {
        discount=1.;
        //const的变量是不能在构造函数内部赋值的，需要带初值的构造函数
        //basicPrice=100;
    }
    void setDiscount(double discount)
    {
        this->discount=discount;
    }
    //override可以显式声明覆盖，假如覆盖不了会显示程序错误。final则表示派生类不能重写这个虚函数（c++11特性）
    double getPrice() override final
    {
        return discount*basicPrice;
    }
private:
    double discount;
};

class Oldbook:public DiscountBook
{
    //===此时想要覆盖会触发错误===//
    /*
    double getPrice() override
    {
        return 0.1*basicPrice;
    }
    */
};

#endif // CBOOK_H
