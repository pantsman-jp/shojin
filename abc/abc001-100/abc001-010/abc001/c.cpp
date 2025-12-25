#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;

string dir(int deg10, int w)
{
  if (w == 0)
    return "C";
  if ((3488 <= deg10 and deg10 <= 3600) or (0 <= deg10 and deg10 <= 112))
    return "N";
  if (113 <= deg10 and deg10 <= 337)
    return "NNE";
  if (338 <= deg10 and deg10 <= 562)
    return "NE";
  if (563 <= deg10 and deg10 <= 787)
    return "ENE";
  if (788 <= deg10 and deg10 <= 1012)
    return "E";
  if (1013 <= deg10 and deg10 <= 1237)
    return "ESE";
  if (1238 <= deg10 and deg10 <= 1462)
    return "SE";
  if (1463 <= deg10 and deg10 <= 1687)
    return "SSE";
  if (1688 <= deg10 and deg10 <= 1912)
    return "S";
  if (1913 <= deg10 and deg10 <= 2137)
    return "SSW";
  if (2138 <= deg10 and deg10 <= 2362)
    return "SW";
  if (2363 <= deg10 and deg10 <= 2587)
    return "WSW";
  if (2588 <= deg10 and deg10 <= 2812)
    return "W";
  if (2813 <= deg10 and deg10 <= 3037)
    return "WNW";
  if (3038 <= deg10 and deg10 <= 3262)
    return "NW";
  if (3263 <= deg10 and deg10 <= 3487)
    return "NNW";
  return "N";
}

int power(int dis)
{
  int ws10 = (dis * 10 + 30) / 60;
  if (ws10 <= 2)
    return 0;
  if (ws10 <= 15)
    return 1;
  if (ws10 <= 33)
    return 2;
  if (ws10 <= 54)
    return 3;
  if (ws10 <= 79)
    return 4;
  if (ws10 <= 107)
    return 5;
  if (ws10 <= 138)
    return 6;
  if (ws10 <= 171)
    return 7;
  if (ws10 <= 207)
    return 8;
  if (ws10 <= 244)
    return 9;
  if (ws10 <= 284)
    return 10;
  if (ws10 <= 326)
    return 11;
  return 12;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int deg, dis;
  cin >> deg >> dis;
  int w = power(dis);
  string d = dir(deg, w);
  cout << d << ' ' << w << endl;
}