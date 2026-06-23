class Solution {
public:
    int reverse(int x) {
        int sign= (x<0)?-1:1;
        int ans=0;
        while(x!=0){
            int digit=x%10;
            digit *= sign;
            if( (ans>INT_MAX/10) or (ans==INT_MAX/10 && digit>7) ) return 0;
            else if( (ans<INT_MIN/10) or (ans==INT_MIN/10 && digit<-8) )  return 0;
            if(sign) ans = ans*10 + (x%10);
            else ans = ans*10 - (x%10);
            x /=10;
        }
        return int(ans);
    }
};
