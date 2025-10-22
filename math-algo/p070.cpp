#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll N, K, X[59], Y[59];
ll Answer = (1LL << 62);

int check_numpoints(ll lx, ll rx, ll ly, ll ry)
{
  ll cnt = 0;
  for (ll i = 1; i <= N; i++)
    if (lx <= X[i] and X[i] <= rx and ly <= Y[i] and Y[i] <= ry)
      cnt++;
  return cnt;
}

int main()
{
  cin >> N >> K;
  for (ll i = 1; i <= N; i++)
    cin >> X[i] >> Y[i];
  for (ll i = 1; i <= N; i++)
  {
    for (ll j = 1; j <= N; j++)
    {
      for (ll k = 1; k <= N; k++)
      {
        for (ll l = 1; l <= N; l++)
        {
          ll cl = X[i], cr = X[j], dl = Y[k], dr = Y[l];
          if (check_numpoints(cl, cr, dl, dr) >= K)
          {
            ll area = 1LL * (cr - cl) * (dr - dl);
            Answer = min(Answer, area);
          }
        }
      }
    }
  }
  cout << Answer << endl;
}