class Solution {
public:
    pair<char,char> getSumCarry(char b1,char b2,char carry){ // sum,carry
        int tempSum = (b1-'0')+(b2-'0')+(carry-'0');
        return {
            tempSum%2 + '0',
            tempSum/2 + '0'
        };
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
            ans.push_back(sum);
            i--; j--;
        }
        if(carry=='1') ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/*
 a b c  sum. ->  return (sum,carry)
 0 0 0. 0.   ->. {0,0}
 0 0 1. 1.  ->   {1,0}
 0 1 0. 1.   ->. {1,0}
 0 1 1.  2.  ->  {0,1}
 1 0 0.  1.  ->  {1,0}
 1 0 1.  2.  ->. {0,1}
 1 1 0.  2.  ->. {0,1}  
 1 1 1   3.  ->  {1,1}
*/