#include <stdio.h>
#include <iostream>
using namespace  std;

class Solution {
public:
    int Sum_Solution(int n) {       
        n&&(n+=Sum_Solution(n-1));
        return n;
    }
};