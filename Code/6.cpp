#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    vc a(n + 1);
    for (int i = 1;i<=n;i++)cin>>a[i];
    vvi dp(n + 1,vi(n + 2));

    for (int l = 0;l<=n + 1;l++)dp[n][l] = 1;

    for (int i = n - 1;i>=1;i--){

         int sum=0;

        for (int l =0;l<=n;l++){
            
           

           

            sum+=dp[i+1][l];

            sum%=mod;

            if (a[i] == 'f'){
                dp[i][l] = dp[i + 1][l + 1];
               // cout<<dp[i][l]<<" "<<i<<" "<<l<<"\n";
            }
            else{
                    dp[i][l] = sum;
            }
           // cout<<dp[i][l]<<" ";

          
        } 
       // cout<<"\n";
    }





    cout<<dp[1][0];
    return 0;
}
