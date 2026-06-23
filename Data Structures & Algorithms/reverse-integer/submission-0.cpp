class Solution {
public:
    int reverse(int x) {
        int sign= (x<0)?-1:1;
        long long ans=0;
        while(x!=0){
            if(sign) ans = ans*10 + (x%10);
            else ans = ans*10 - (x%10);
            x /=10;
            if(ans<INT_MIN || ans>INT_MAX) return 0;
        }
        return int(ans);
    }
};
