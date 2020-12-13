//boyer moore method for pattern matching
//If the character is not present at all, then it may result in a shift by m (length of pattern). 
//Therefore, the bad character heuristic takes O(n/m) time in the best case.
//The Bad Character Heuristic may take O(mn) time in worst case.
//The worst case occurs when all characters of the text and pattern are same.
//For example, txt[] = “AAAAAAAAAAAAAAAAAA” and pat[] = “AAAAA”.

#include<bits/stdc++.h>

using namespace std;

int last_occurence(string t , char c , int l)
{
        for(int i = l;i >= 0;i--)
        {   
            if(t[i] == c)
            {
                return i;
            }
        }
        return -1;
}

int boyer_moore(string s , string t)
{
    	int n = s.length();
        int m = t.length();
        if(m == 0)
        {
            return 0;
        }
        if(n < m)
        {
            return -1;
        }
        int i = m - 1;
        int j = m - 1;
        while(i < n && i >= 0)
        {
            cout<<endl<<i<<"\t"<<j;
            if(s[i] == t[j])
            {
                if(j == 0)
                {
                    return i;
                }
                i--;
                j--;
            }
            else
            {
                int l = last_occurence(t , s[i] , j);
                i = i + m - (l + 1);
                j = m - 1;
            }
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
    cout<<"\n pattern found at : "<<boyer_moore(text , pattern);
    return 0;
}