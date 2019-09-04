#include <stdio.h>
#include <iostream>
using namespace  std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        //num2 表示进位 num1是结果
        return num2?Add(num1^num2,(num1&num2)<<1):num1;
        /*
        if(num2==0) return num1;
        else return Add(num1^num2,(num1&num2)<<1);
        */

    }
};