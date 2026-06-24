class Solution {
public:
    pair<char,char> getSumCarry(char b1,char b2,char carry){ // sum,carry
        int tempSum = (b1-'0')+(b2-'0')+(carry-'0');
        if(tempSum==0)return {'0','0'};
        else if(tempSum==1) return {'1','0'};
        else if(tempSum==2) return {'0','1'};
        else return {'1','1'};
    }
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        char sum,carry='0';
        string ans="";
        while(i>=0 || j>=0){
            char b1 = (i>=0)? a[i] : '0';
            char b2 = (j>=0)? b[j] : '0';
            auto pair = getSumCarry(b1,b2,carry);
            sum = pair.first;
            carry = pair.second;
            ans = sum + ans;
            i--; j--;
        }
        if(carry=='1') ans = carry+ans;
        return ans;
    }
};

/*
 a b c  sum. ->  return (sum,carry)
 0 0 0. 0.   ->. {0,0}
 0 0 1. 1.  ->   {1,0}
 0 1 0. 1.   ->. {1,0}
 0 1 1.  2.  ->   {0,1}
 1 0 0.  1.  ->  {1,0}
 1 0 1.  2.  ->.  {0,1}
 1 1 0.  2.  ->.  {0,1}  
 1 1 1   3.   ->. {1,1}

*/