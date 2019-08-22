#include <vector>
#include <iostream>
#include <queue>
using namespace  std;

class Solution {
public:
    void Insert(int num)
    {
        //目前有偶数个num 加入小顶堆
        if((count&1)==0){ 
            max.push(num);
            int temp=max.top();
            max.pop();
            min.push(temp);
            count++;
        }else{
        //目前是奇数  加入大顶堆
            min.push(num);
            int temp=min.top();
            min.pop();
            max.push(temp);
            count++;
        }
    }

    double GetMedian()
    { 
        if((count&1)==0){
            return (max.top()+min.top())/2.0;
        }else{
            return min.top();
        }
    }
    
private:
    //第三个参数是类模版
    priority_queue<int, vector<int>, less<int> >    max;
    priority_queue<int, vector<int>, greater<int> > min;
    int count;
};
int main(){
    Solution sol;
    sol.Insert(2);
    cout<<sol.GetMedian()<<" ";
    sol.Insert(1);
    cout<<sol.GetMedian()<<" ";
    sol.Insert(3);
    cout<<sol.GetMedian()<<" ";
    sol.Insert(4);
    cout<<sol.GetMedian()<<" ";
    sol.Insert(5);
    cout<<sol.GetMedian()<<" ";
    sol.Insert(6); 
    cout<<sol.GetMedian()<<" ";
    sol.Insert(7);
    cout<<sol.GetMedian()<<" ";

    return 0;
}
