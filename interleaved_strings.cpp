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
        if (len == 0)
        {
            return true;
        }

        if (t[n][m] != -1)
        {
            return t[n][m];
        }

        int x = 0, y = 0;
        if (n - 1 >= 0 and a[n - 1] == c[len - 1])
        {
            x = solve(a, b, c, n - 1, m, len - 1);
        }

        if (m - 1 >= 0 and b[n - 1] == c[len - 1])
        {
            y = solve(a, b, c, n, m - 1, len - 1);
        }

        return t[n][m] = x or y;
    }

    bool isInterleave(string a, string b, string c)
    {
        int n = a.size();
        int m = b.size();
        int len = c.size();

        if (n + m != len)
        {
            return false;
        }

        int t[n][m];
        memset(t, -1, sizeof(t));

        return solve(a, b, c, n, m, len);
    }
};


// YXYYXXYXYYYXYXXXXXYYXXXXXXXXYXYXXXYYYYYYXYXXYYYYYXXYXYXXYXYXYXYXXXYYYYYXYYYYXYYXXXYYYXXXYXYYYYYXYXXY
// XYYYXYXXYXXYYYXYXYYYYXYXXXXYYXYXYXXXXYXYXXXYYXYYXXXXXYXYYXYXYYXXXYYXYXYYXYXXYXXXXXYXYYYYXYXYYXYXXYXY
// YYXXYXYYXXYYYYXXYYYXXYXXYXXYXXXYYXXYYYYYYXXYYYYYYXXYXXXYXYYYXYYXXYYYYYYXXXXXXYXXXYXYYYXXXXXXYYYYXYYX
// XXXYXYXXXYYYXYXYXXXYXYXXXYXYYXYYXXXYYXXXYXXXYXXYXXYYYXYXXYYYYYXXXYXYXXXYXXYXYXYXXXYYYXYXYXYYYYXXYYYX