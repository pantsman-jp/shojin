# What I Learned

**注）特に断りがなければ、示されているコードの言語は C++**

## 目次
### 基本的なコード構造と整数操作
- [解答雛形](#解答雛形)
- [整数型](#整数型)
- [整数除算の仕様](#整数除算の仕様)
- [小数点数の標準出力](#小数点数の標準出力)
- [配列の定義方法の違い](#配列の定義方法の違い)

### アルゴリズムと探索
- [bit 全探索](#bit-全探索)
- [深さ優先探索](#深さ優先探索)
- [幅優先探索](#幅優先探索)
- [Union-Find](#union-find)

### 計算テクニック
- [インクリメント](#インクリメント)
- [累積和](#累積和)
- [いもす法（累積和の応用）](#いもすimos法)
- [巨大数での割り算の余り](#巨大数での割り算の余り)
- [順位付け](#順位付け)
---


## 解答雛形
### Last Updated : 2025-10-21
C++ での解答の雛形を示す。
```C++
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
```
---
---

## 整数型
### Last Updated : 2025-10-20
C++ において、整数型は以下のようにまとめられる。
| 整数型 | 記法 | 10 進法での桁数 | 範囲 |
| :---: | :---: | :---: | :---: |
| 32 ビット整数（符号付き） | `int` | 10 | -2^31 ~ 2^31 - 1 |
| 64 ビット整数（符号付き） | `long long` | 19 | -2^63 ~ 2^63 - 1 |
| 64 ビット整数（符号なし） | `unsigned long long` | 20 | 0 ~ 2^64 - 1 |
---
---


## bit 全探索
### last updated : 2025-10-04
### 使用問題
- 競プロ典型90題 - 002
- ABC427 B

部分集合のパターンを全列挙する際に用いる手法。
具体的には、大きさ `n` の集合から `i` (0 <= i < n) 番目の要素を選ぶか、選ばないかは `2^n` 通りある。
`n <= 20` であれば十分高速である。

配列の全部分集合の和を計算する例を以下に示す。

```C++
int n = 10;
vector<int> array(n);
for (int bit = 0; bit < (1 << n); ++bit)
{
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    if (bit & (1 << i))
      sum += array[i];
  }
  cout << sum << endl;
}
```

**逐行解説**
1. `1 << n` は 1 を n ビット左シフトする(ex. `1 << 10` -> `0b1000000000 = 1024`)。
すなわち bit は `0 <= bit < 2^n` の範囲をループする。
2. `sum` の初期化。
3. `i` は配列 `array` のインデックスになる。
4. -  端的に言えば、`i` 番目のビットが `1` かどうかを判定するための操作。
    - `1 << i` と AND することで、i ビット目だけを取り出して判定している。~~AND 演算を各桁に行なっている。~~
    - AND 演算は以下の表で定義される。
    - 先に述べたように `1 << i` は `i` 桁目のみ `1` なので、`i` 桁目以外の AND 演算の結果は必然的に `0` となる。
    - 故に、`bit` の二進表記の `i` 桁目が `1` かどうかを調べられる。
    - `bit & (1 << i)` を評価すると、`0` か それ以外の整数となる。
    - C++ では `0` を `false`、それ以外の整数を `true` と言い換えられ、 `i` 番目の要素を取得するか否かを決定できる。

| x | y | x & y |
| :---: | :---: | :---: |
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |
---
---

## インクリメント
### Last Updated : 2025-10-05

インクリメントには二種類あり、`前置インクリメント` と `後置インクリメント` である。

### 前置インクリメント
```C++
int i = 0;
int var = ++i; // var = 1, i = 1
```
機序は以下の通り。
1. `i` の初期化 (`i = 0`)
2. `i` を `1` 増加 (`i = 1`)
3. 2.の評価値を `var` に代入 (`var = 1`)

### 後置インクリメント
```C++
int i = 0;
int var = i++; // var = 0, i = 1
```
機序は以下の通り。
1. `i` の初期化 (`i = 0`)
2. `i` の値を一時的に保存 (`tmp = 0`)
3. `i` を `1` 増加 (`i = 1`)
4. 保存した値（`temp = 0`）が返り、それが `var` に代入される（`var = 0`）
---
---

## 整数除算の仕様
### Last Updated : 2025-10-06
### 使用問題
- ABC334 B

### C++ の場合
整数型 a, b について、`a / b` は0に向かう丸めとして定義される。
すなわち、`a / b` は **a ÷ b の小数部分を切り捨てる** 動作となる。

例
```C++
int a = 7, b = 3;
a / b // 2 であり、floor(7 / 3) = 2 に等しい
-a / b // -2 であり、floor(-7 / 3) = -3 と異なる
```
---

### Python3 の場合
#### `/` 演算子
常に少数点数を返す。

例
```Python
7 / 3   # 2.333...
-7 / 3  # -2.333...
```

#### `//` 演算子
結果を floor に丸める。すなわち、負の無限大方向に切り下げる。
```Python
7 // 3   # 2
-7 // 3  # -3   # 0方向ではなく floor
```
---
---

## 順位付け
### Last Updated : 2025-10-06
### 使用問題
- ABC323 B

1. `count[i]` にプレイヤー `i` の勝利数を格納する
2. プレイヤー番号のインデックス 0..n-1 を配列 `ans` に保持する
3. sort 関数で ans を並べ替える
4. 勝利数が異なる場合は勝利数の多い方を前にする
5. 勝利数が同じ場合はプレイヤー番号の小さい方を前にする
6. 並べ替えられた `ans` を出力する（番号は 1 始まりなので +1 する）

```C++
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> count(n);
  // （略）ポイントの集計
  vector<int> ans(n);
  rep(i, n) ans[i] = i;
  sort(ans.begin(), ans.end(), [&](int a, int b)
       {
         if (count[a] != count[b])
           return count[a] > count[b];
         return a < b; });
  rep(i, n) { cout << ans[i] + 1 << ' '; }
  cout << endl;
}
```
---
---


## 配列の定義方法の違い
### Last Updated : 2025-10-16

`int array[n]` と `vector<int> array(n)` の違い以下に示す。

| 項目 | int dp[n]  | vector<int> dp(n) |
| :---: | :---: | :---: |
| メモリ確保場所 | スタック | ヒープ |
| サイズ決定 | コンパイル時に固定 | 実行時に動的に決定可能 |
| サイズ変更 | 不可 | 可（`push_back` などで追加可能） |
| 安全性 | 大きいとスタックオーバーフローの可能性あり | ヒープ確保なので安全 |
| 便利機能 | なし | `size()`, `begin()`, `end()`, `push_back()` など利用可能 |
| 使用例 | 小さく固定の配列向き | 大きな配列や動的配列向き |
---
---

## 小数点数の標準出力
### Last Updated : 2025-10-17
```C++
double ans;
cout << fixed << setprecision(10) << ans << endl;
```
---
---

## 累積和
### Last Updated : 2025-10-25
### 0-index の場合
配列 `a[0..n-1]` に対して
```C++
sum[0] = 0
sum[i+1] = sum[i] + a[i]  // (0 ≤ i < n)
```
- このとき sum は 0..n の n+1 要素
- 区間 [l, r] の和を `sum[r+1] - sum[l]` で計算するため、`sum[r+1]` にアクセスできるように n+1 要素必要

### 1-index の場合
配列 `a[1..n]` に対して
```C++
sum[0] = 0
sum[i] = sum[i-1] + a[i]  // (1 ≤ i ≤ n)
```
- このとき sum は 0..n の n+1 要素
- 区間 [l, r] の和を `sum[r] - sum[l-1]` で計算するため、`sum[0]` が必要
---
---

## 深さ優先探索
### Last Updated : 2025-10-18
グラフが連結かどうかを探索して判定するプログラムを以下に示す。

連結:どの頂点間も辺を辿って移動できること。
```C++
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

vector<vector<int>> g;
vector<bool> visited;

void dfs(ll v)
{
  visited[v] = true;
  for (ll i : g[v])
    if (!visited[i])
      dfs(i);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  g.assign(n, {});
  visited.assign(n, false);
  rep(i, 0, m)
  {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  dfs(0);
  for (bool b : visited)
  {
    if (!b)
    {
      cout << "The graph is not connected." << endl;
      return 0;
    }
  }
  cout << "The graph is connected." << endl;
}
```
---
---

## 幅優先探索
### Last Updated : 2025-10-21
頂点1からの最短経路長を探索により調べる方法を以下に示す。
```C++
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n + 1);
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }
  vector<ll> dist(n + 1, -1);
  queue<ll> q;
  q.push(1), dist[1] = 0;
  while (!q.empty())
  {
    ll pos = q.front();
    q.pop();
    rep(i, 0, g[pos].size())
    {
      ll nex = g[pos][i];
      if (dist[nex] == -1)
        dist[nex] = dist[pos] + 1, q.push(nex);
    }
  }
  rep(i, 1, n + 1) cout << dist[i] << endl;
}
```
---
---

## 巨大数での割り算の余り
### Last Updated : 2025-10-18
- `modpow` は `pow(a, b) % m` を計算する。
- `moddiv` は `(a ÷ b) % m` を計算する。
```C++
ll modpow(ll a, ll b, ll m)
{
  ll ans = 1;
  while (b > 0)
  {
    if (b & 1)
      ans = (ans * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return ans;
}

ll div(ll a, ll b, ll m) { return (a * modpow(b, m - 2, m)) % m; }
```
---
---

## いもす（Imos）法
### Last Updated : 2025-10-24
### 使用問題
- ABC408 C
### 概要
長さ `N` の配列 `A` について、区間 `[L, R]` に値 `X` を加えたいとする。
このとき、以下のような記録をすれば良い。
```C++
A[L] += X, A[R + 1] -= X;
```

上記の操作を全ての区間について行った後、`A` の累積和を取ることで、各位置の値を知ることができる。
すなわち以下を実行する。
```C++
for (int i = 1; i < N; i++)
  A[i] += A[i - 1];
```
---
---

## Union Find
### Last Updated : 2025-10-25
### 使用問題
- ABC399 C
### 概要
Union-Find は、グループ分けを効率的に管理できるデータ構造である。

ある要素 `a` と `b` について、これらをグループに併合したり（`merge(a, b)`）、
`a` と `b` が同じグループに属するかを調べたり（`same(a, b)`）、
要素 `a` の所属するグループのサイズを調べたり（`size(a)`）できる。

AtCoder Library を用いて以下のように実行できる。
```C++
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int main() {
  int n = 5;
  dsu uf(n);
  uf.merge(0, 1);
  uf.merge(1, 2);
  if (uf.same(0, 2))
    cout << "0 と 2 は同じグループです" << endl;
  cout << "0 のグループサイズ: " << uf.size(0) << endl;
}
```

Union-Find（DSU）は、要素をグループに分け、それらのグループ操作を効率的に行う必要がある場面で使える。
具体的なケースは以下。

1. **連結成分の管理**  
  - グラフの頂点やネットワークの要素をグループとして管理する場合に有効
    - 例えば、無向グラフの連結成分を求める際に各辺で `merge` を行い
    - 頂点が同じ連結成分に属するかを `same` で判定できる
2. **サイクル検出**  
  - グラフに辺を順に追加する際、追加する辺の両端がすでに同じグループに属していればサイクルができることが分かる
    - これは最小全域木（Kruskal法）を構成するときにも使われる
3. **集合の統合**  
  - 互いに関係するデータを一つのグループとして扱いたい場合に便利
    - 例えば、友達関係や同一カテゴリの判定などの問題で `merge` を使って効率的に集合を統合できる
4. **オフラインクエリ処理**  
  - 順序付きの情報をもとに集合を統合しながらクエリを処理する場面で役立つ
    - 「ある時点で A と B は同じグループか」といったクエリを効率的に処理できる

「要素をグループ化し、グループ間の関係を高速に管理する必要がある場合」 に Union-Find は非常に有効。
---
---

<!-- ## 
### Last Updated : 
### 使用問題
- 
---
--- -->

<!-- ## 
### Last Updated : 
### 使用問題
- 
---
--- -->