#include<bits/stdc++.h>
class Solution {
public:
    int countMatches(int hash1[],int hash2[]){
        int cnt=0;
        for(int i=0;i<26;i++){
            if(hash1[i]==hash2[i]) cnt++;
        }
        return cnt;
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
        int matches = countMatches(hash1,hash2);
        cout<<matches<<endl;
        if(matches==26)return true;

        for(int i=n1;i<n2;i++){
            int l=s2[i-n1]-'a';
            if( hash1[ l ] == hash2[ l ] ) matches--;
            hash2[l]--;
            if( hash1[ l ] == hash2[ l ] ) matches++; // does removing s2[i-n1] increases matches.

            int r=s2[i]-'a';
            hash2[r]++;
            if( hash1[ r ] == hash2[ r ] ) matches++;
            else if(hash2[r]-1 == hash1[r] ) matches--; // phle match ho rahe the abb nahi ho rhe... 

            if(matches==26)return true;
        }
        
        return false;

    }
};
