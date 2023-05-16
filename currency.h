#ifndef CURRENCY_H
#define CURRENCY_H

#include<iostream>
using namespace std;
enum signType{positive, negative};

class currency{
friend ostream& operator<<(ostream&, const currency&);
private:
    long amount;

public:
    currency(signType theSign = positive, unsigned long theDollars = 0, unsigned int theCents = 0);
    ~currency(){}
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const{
        if(amount < 0){
            return negative;
        }
        else return positive;
    }
    unsigned long getDollars() const{
        if(amount < 0){
            return (-amount) / 100;
        }
        else return amount/100;
    }
    unsigned int getCents() const{
        if(amount < 0){
            return -amount - getDollars() * 100;
        }
        else return amount - getDollars() * 100;
    }
    // currency add(const currency&) const;
    currency operator+(const currency&) const;
    // currency& increment(const currency & x){
    //     amount += x.amount;
    //     return *this;
    // }
    currency& operator+=(const currency& x){
        amount += x.amount;
        return *this;
    }
    // void output() const;
    // void output(ostream &) const;

};
    




#endif