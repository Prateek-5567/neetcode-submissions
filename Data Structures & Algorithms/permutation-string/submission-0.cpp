#include<bits/stdc++.h>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(),n2=s2.length();
        if(n1>n2)return false;
        int l=0,r=n1;
        sort(s1.begin(),s1.end());

        while(l<=n2-n1){
            string str=s2.substr(l,n1);
            sort(str.begin(),str.end());
            if(s1==str)return true;
            l++;
        }
        return false;
    }
};
