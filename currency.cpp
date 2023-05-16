#include<iostream>
#include"currency.h"
using namespace std;

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents){
    setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents){
    if(theCents > 99){
        cout<<"theCents should be less than 100";
        return;
    }
    amount = theDollars * 100 + theCents;
    if(theSign == negative) amount = -amount;
}

void currency::setValue(double theAmount){
    if(theAmount < 0){
        amount = (long) ((theAmount - 0.001) * 100); 
    }
    else{
        amount = (long) ((theAmount + 0.001) * 100);
    }
}

//将用operator+代替
// currency currency::add(const currency& x) const{
//     currency y;
//     y.amount = amount + x.amount;
//     return y;
// }

currency currency::operator+(const currency& x) const{
    currency y;
    y.amount = amount + x.amount;
    return y;
}

//重载运算符<<要使用output（ostream&）
// void currency::output() const{
//     long theAmount = amount;
//     if(theAmount < 0){
//         cout<<'-';
//         theAmount = -theAmount;
//     }
//     long dollars = theAmount / 100;
//     cout<<'$'<<dollars<<'.';
//     int cents = theAmount - dollars * 100;
//     if(cents < 10)  cout<<'0';
//     cout<<cents;
// }

// 重载运算符<<使用
// void currency::output(ostream& out) const{
//     long theAmount = amount;
//     if(theAmount < 0){
//         cout<<'-';
//         theAmount = -theAmount;
//     }
//     long dollars = theAmount / 100;
//     out<<'$'<<dollars<<'.';
//     int cents = theAmount - dollars * 100;
//     if(cents < 10) out<<'0';
//     out<<cents;
// } 

//不是成员函数， 使用output来访问私有
// ostream& operator<<(ostream& out, const currency & x){
//     x.output(out);
//     return out;
// }

// 友元函数
ostream& operator<<(ostream& out, const currency& x){
    long theAmount = x.amount;
    if(theAmount < 0){
        cout<<'-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;
    out<<'$'<<dollars<<'.';
    int cents = theAmount - dollars * 100;
    if(cents < 10) out<<'0';
    out<<cents;
}