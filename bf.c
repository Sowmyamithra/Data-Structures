//brute force method of pattern matching
//worst case - O(m * (n - m + 1)) -> when last char is different or every letter is same
//best case - O(n) -> when the first char of pattern is not there in the text

#include<bits/stdc++.h>

using namespace std;

int brute_force(string s , string t)
{
    int n = s.length();
    int m = t.length();
    if(n < m)
    {
        return -1;
    }
    int ans = -1;
    int i = 0;
    int j = 0;
    while(i < n && j < m)
    {
        ans = i - m + 1;
        if(s[i] == t[j])
        {
            i = i + 1;
            j = j + 1;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == m)
    {
        return ans;
    }
    return -1;
}
int main()
{
    string text , pattern;
    cout<<"Enter text : ";
    cin>>text;
    cout<<"\nEnter pattern : ";
    cin>>pattern;
    cout<<"\n pattern found at : "<<brute_force(text , pattern);
    return 0;
}