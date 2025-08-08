#pragma once
#include <string>
#include <iostream>
using namespace std;

class BigInt
{
    std::string internalNumber;

    std::string fillZeros(std::string str, int n, bool flag);
    std::string Multiply(std::string str, int num);

public:
    std::string AddNumbers(std::string n);
    std::string deleteNumbers(std::string n);
    std::string multiplication(std::string n);
    std::string Division(std::string n);

    void SetInternalNumber(std::string number);

    BigInt();
    BigInt(std::string str);
    BigInt(const char* str);
    BigInt(int number);
    //~BigInt();

    BigInt operator+(BigInt& n);
    BigInt operator-(BigInt& n);

    friend std::ostream& operator<<(std::ostream& out, BigInt n);

    BigInt operator++(int);
    BigInt operator--(int);

    BigInt operator+=(BigInt& n);
    BigInt operator-=(BigInt& n);

    BigInt operator+=(int n);
    BigInt operator-=(int n);
};

string add(string numStr, string n);
string deleteNum(string numStr, string n);
string multiplication(string numStr, string n);
string division(string numStr, string n);
