#include<bits/stdc++.h>
class Solution {
public:
/*
we can use regex to replace all spaces by empty string.

string s = "hello world cpp";
s = regex_replace(s, regex(" "), "");

*/
    bool isPalindrome(string str) {

        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        // s = regex_replace(s, regex(" "), "");
        // cout<<s; 
        //  these above things are good for shortcut but dont fit in this question.

        transform(str.begin(), str.end(), str.begin(), ::tolower);
        string s="";
        for(char ch:str){
            if(isdigit(ch) || isalpha(ch)) s+=ch;
        }
        cout<<s<<endl;

        int i=0,j=s.length()-1;
        while(i<j){
            if( s[i++] != s[j--] )return false;
        }
        return true;
    }
};
