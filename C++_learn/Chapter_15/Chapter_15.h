#pragma once
#ifndef _Chapter_15_
#define _Chapter_15_
#include<iostream>
#include<string>
#include<memory>
using namespace std;
namespace U_1
{
    //string类


};
namespace U_2
{
    double test(double& S)
    {
        auto_ptr<double> Point(new double);
        *Point = S * S;
        cout << *Point << endl;
        
        return S * S;
    }
    
};
namespace U_3
{
    unique_ptr<string> Deemo(const char* S)
    {
        unique_ptr<string> tmp(new string(S));
        return tmp;
    }
};





#endif // !_Chapter_15_
