// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

class Solution
{
public:
    int t[1001][1001];
    bool solve(string a, string b, string c, int n, int m, int len)
    {
        if (len == 0)  // means c is completely finish  so we got our answer return true
        {
            return true;
        }

        if (t[n][m] != -1)  // then we memoize 
        {
            return t[n][m];
        }

        int x = 0, y = 0;
        if (n - 1 >= 0 and a[n - 1] == c[len - 1])  // here i take n-1 beacuse of 0 based index
        {
            x = solve(a, b, c, n - 1, m, len - 1);  // if char of a match with c then we dec the lenght of both
        }

        if (m - 1 >= 0 and b[n - 1] == c[len - 1])
        {
            y = solve(a, b, c, n, m - 1, len - 1);   // if char of b match with c then we dec the lenght of both
        }

        return t[n][m] = x or y;
         
    }

    bool isInterleave(string a, string b, string c)
    {
        int n = a.size();
        int m = b.size();
        int len = c.size();

        if (n + m != len)  // check the if sum of both string a and b is equal to len of string c;
        {
            return false;
        }

        int t[n][m];
        memset(t, -1, sizeof(t));

        return solve(a, b, c, n, m, len);
    }
};

 
