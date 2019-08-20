
class Solution {
public:
    bool isPalindrome(int x) {
        int res=0;
        if(x==0) return true;
        if(x<0||x%10==0) return false;
        while(x>res){
            res=res*10+x%10;
            x/=10;
        }
        return x==res||x==res/10;
    }
};