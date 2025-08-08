#include "mathLongOperations.h"

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

string BigInt::fillZeros(string str, int n, bool flag) {
    // flag 0 to fill left, flag 1 to fill right.
    if (flag) {
        while (n)
        {
            str.push_back('0');
            n--;
        }
    }
    else {
        while (n)
        {
            str.insert(0, 1, '0');
            n--;
        }
    }
    return str;
}

string BigInt::Multiply(string str, int num)
{
    int reminder = 0;
    string result = "";
    int sum;
    int currNum;
    for (int i = str.length() - 1; i >= 0; i--) {
        currNum = str[i] - '0';
        sum = currNum * num + reminder;
        string numStr = to_string(sum);
        if (sum >= 10) {
            if (i == 0) {
                result = numStr + result;
                return result;
            }
            string number = numStr;
            reminder = stoi(number.substr(0, number.length() - 1));
        }
        else {
            result.insert(0, numStr);
        }
    }
    return result;
}

string BigInt::AddNumbers(string n)
{
    string CinternalNumber = internalNumber;
    if (CinternalNumber.length() > n.length())
    {
        int total = CinternalNumber.length() - n.length();
        n = fillZeros(n, total, 0);
    }
    else if (CinternalNumber.length() < n.length())
    {
        int total = n.length() - CinternalNumber.length();
        CinternalNumber = fillZeros(CinternalNumber, total, 0);
    }

    int reminder = 0;
    string result = "";
    for (int i = CinternalNumber.length() - 1; i >= 0; i--)
    {
        int num1 = CinternalNumber[i] - '0';
        int num2 = n[i] - '0';
        int sum = num1 + num2 + reminder;
        if (sum >= 10)
        {
            reminder = 1;
        }
        else
        {
            reminder = 0;
        }

        int res = sum % 10;
        result.insert(0, 1, res + '0');
    }

    if (reminder)
    {
        result.insert(0, 1, reminder + '0');
    }

    return result;
}

string BigInt::deleteNumbers(string n)
{
    string upper;
    string lower;
    string result = "";
    if (internalNumber.length() > n.length())
    {
        int total = internalNumber.length() - n.length();
        n = fillZeros(n, total, 0);
        upper = internalNumber;
        lower = n;
    }
    else if (internalNumber.length() < n.length())
    {
        int total = n.length() - internalNumber.length();
        internalNumber = fillZeros(internalNumber, total, 0);
        upper = n;
        lower = internalNumber;
    }
    else {
        upper = n;
        lower = internalNumber;
    }

    for (int i = internalNumber.length() - 1; i >= 0; i--)
    {
        int  num1 = upper[i] - '0';
        int num2 = lower[i] - '0';
        int flag = 1;
        int part = 0;
        if (num1 < num2) {
            string num1Str = upper;
            bool run = true;
            int flag = 1;
            while (run) {
                if ((num1Str[i - flag] - '0') > 0) {
                    upper[i - flag] = char(((num1Str[i - flag] - '0') - 1) + '0');
                    run = 0;
                }
                else {
                    upper[i - flag] = char(9 + '0');
                }
                flag++;
            }
            num1 = (upper[i] - '0') + 10;
        }
        int sub = num1 - num2;

        result.insert(0, 1, sub + '0');
    }

    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }

    return result;
}

string BigInt::multiplication(string n) {
    int j = 0;
    string upper;
    string lower;
    string prevNum = "";
    string result;
    if (n.length() > internalNumber.length()) {
        upper = n;
        lower = internalNumber;
    }
    else if (n.length() < internalNumber.length()) {
        upper = internalNumber;
        lower = n;
    }
    else {
        upper = n;
        lower = internalNumber;
    }
    for (int i = lower.length() - 1; i >= 0; i--) {
        string numStr = Multiply(upper, (lower[i] - '0'));
        if (prevNum == "") {
            prevNum = fillZeros(numStr, j, 1);
        }
        else {
            BigInt k = prevNum;
            prevNum = k.AddNumbers(fillZeros(numStr, j, 1));
        }
        if (i == 0) {
            result = prevNum;
        }
        j++;
    }
    return result;
}

string BigInt::Division(string n) {
    string remainder = "0";
    string result = "";
    int num = stoi(n);
    int currNum;
    int currSubNum = 0;
    int i = 0;
    while (remainder != "0" || i < internalNumber.length()) {
        if (i > internalNumber.length() - 1) {
            return "Error: number " + internalNumber + " cannot be divided by number " + n;
        }
        currNum = internalNumber[i] - '0';
        if (remainder == "0") {
            if (currSubNum == 0) {
                currSubNum = currNum;
            }
            else {
                currSubNum = stoi(to_string(currSubNum) + to_string(currNum));
            }
            if (num <= currSubNum) {
                result = result + to_string(currSubNum / num);
                remainder = to_string(currSubNum % num);
                currSubNum = 0;
            }
            else if (i != 0) {
                result = result + "0";
            }
        }
        else {
            if (num <= stoi(remainder)) {
                result = result + to_string(stoi(remainder) / num);
                remainder = to_string(stoi(remainder) % num);
                currSubNum = 0;
            }
            else {
                remainder = remainder + to_string(currNum);
                if (num <= stoi(remainder)) {
                    result = result + to_string(stoi(remainder) / num);
                    remainder = to_string(stoi(remainder) % num);
                    currSubNum = 0;
                }
                else {
                    result = result + "0";
                }
            }
        }
        i++;
    }

    return result;
}

void BigInt::SetInternalNumber(string number)
{
    internalNumber = number;
}

BigInt::BigInt()
{
    internalNumber = "0";
}

BigInt::BigInt(string str)
{
    internalNumber = str;
}

BigInt::BigInt(const char* str)
{
    internalNumber = str;
}

BigInt::BigInt(int number)
{
    internalNumber = std::to_string(number);
}

//BigInt::~BigInt()
//{}

BigInt BigInt::operator+(BigInt& n)
{
    string result = AddNumbers(n.internalNumber);
    BigInt r;
    r.internalNumber = result;
    return r;
}

BigInt BigInt::operator-(BigInt& n)
{
    string result = deleteNumbers(n.internalNumber);
    BigInt r;
    r.internalNumber = result;
    return r;
}

std::ostream& operator<<(std::ostream& out, BigInt n)
{
    out << n.internalNumber;
    return out;
}

BigInt BigInt::operator++(int)
{
    BigInt n = AddNumbers("1");
    internalNumber = n.internalNumber;
    return n;
}

BigInt BigInt::operator--(int)
{
    BigInt n = deleteNumbers("1");
    internalNumber = n.internalNumber;
    return n;
}

BigInt BigInt::operator+=(BigInt& n)
{
    BigInt m = internalNumber;
    internalNumber = AddNumbers(n.internalNumber);
    return m;
}

BigInt BigInt::operator-=(BigInt& n)
{
    BigInt m = internalNumber;
    internalNumber = deleteNumbers(n.internalNumber);
    return m;
}

BigInt BigInt::operator+=(int n)
{
    BigInt m = internalNumber;
    internalNumber = AddNumbers(to_string(n));
    return m;
}

BigInt BigInt::operator-=(int n)
{
    BigInt m = internalNumber;
    internalNumber = deleteNumbers(to_string(n));
    return m;
}


string add(string numStr, string n) {
	BigInt a(numStr);
	return a.AddNumbers(n);
}

string deleteNum(string numStr, string n) {
	BigInt a(numStr);
	return a.deleteNumbers(n);
}

string division(string numStr, string n) {
	BigInt a(numStr);
	return a.Division(n);
}

string multiplication(string numStr, string n) {
	BigInt a(numStr);
	return a.multiplication(n);
}