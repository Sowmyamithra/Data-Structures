//kmp pattern matching 
//The KMP matching algorithm uses degenerating property (pattern having same sub-patterns appearing
//more than once in the pattern) of the pattern and improves the worst case complexity to O(n). 
//worst case - O(n)

#include<bits/stdc++.h>

using namespace std;

vector<int> F;

void failure_function(string t , int n)
{
    for(int i = 0;i < n;i++)
    {
        F.push_back(0);
    }
    int i = 1;
    int j = 0;
    F[0] = 0;
    while(i < n)
    {
        if(t[i] == t[j])
        {
            j++;
            F[i] = j;
            i++;
        }
        else if(j > 0)
        {
            j = F[j-1];
        }
        else
        {
            F[i] = 0;
            i++;
        }
    }
}

int kmp(string s , string t)
{
    int n = s.length();
    int m = t.length();
    if(n < m)
    {
        return -1;
    }
    failure_function(t , m);
    int i = 0;
    int j = 0;
    while(i < n)
    {
        if(s[i] == t[j])
        {
            if(j == m - 1)
            {
                return i - j;
            }
            i++;
            j++;
        }
        else if(j > 0)
        {
            j = F[j-1];
        }
        else
        {
            i++;
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
    cout<<"\n pattern found at : "<<kmp(text , pattern);
    return 0;
}