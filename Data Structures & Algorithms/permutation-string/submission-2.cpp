#include<bits/stdc++.h>
class Solution {
public:
    bool isEqual(int hash1[],int hash2[]){
        for(int i=0;i<26;i++){
            if(hash1[i]!=hash2[i])return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(),n2=s2.length();
        if(n1>n2)return false;
        int l=0,r=n1;

        // this solution will have O(26*n) time complexity :-
        int hash1[26]={0};
        int hash2[26]={0};

        for(int i=0;i<n1;i++){
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;
        }
        if(isEqual(hash1,hash2))return true;

        for(int i=n1;i<n2;i++){
            hash2[s2[i]-'a']++;
            hash2[s2[i-n1]-'a']--;
            if(isEqual(hash1,hash2))return true;
        }
        
        return false;

    }
};
