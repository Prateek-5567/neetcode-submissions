class Solution {
public:
    bool isPalin(int i,int j,string& s){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++; j--;
            }else{
                return isPalin(i+1,j,s) or isPalin(i,j-1,s);
            }
        }
        return true;
    }
};