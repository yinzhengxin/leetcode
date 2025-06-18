#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0, right = 0, n = nums.size();
        while (right < n)
        {
            if (nums[right] != 0)
            {
                std::swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

#include <iostream>

int main()
{
    Solution sol;
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    sol.moveZeroes(nums);
    
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << " ";
    }
    cout << endl;
}