#include <bits/stdc++.h>
#define mod 10000007
using namespace std;

int a, b, c, d, e, f;
int dp[10006];
int fn(int n)
{
    if(n == 0){
        return a;
    }else if(n < 0){
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = ((((((fn(n - 1) + fn(n - 2)) % mod + fn(n - 3)) % mod + fn(n - 4) ) %mod+ fn(n - 5) ) % mod+ fn(n - 6))%mod) %mod;
    return dp[n] ;
}
int solve(int n)
{
    for (int i = 0; i <= n+2; i++)
    {
        dp[i] = -1;
    }
    dp[0] = a;
    dp[1] = b;
    dp[2] = c;
    dp[3] = d;
    dp[4] = e;
    dp[5] = f;
    return fn(n);
}
int32_t main()
{
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno)
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", caseno, solve(n) % 10000007);
    }
    return 0;
}
