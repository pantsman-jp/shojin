# What I Learned

**注）特に断りがなければ、示されているコードの言語は C++**

## 目次
### 基本的なコード構造と整数操作
- [解答雛形](#解答雛形)
- [整数型](#整数型)
- [整数除算の仕様](#整数除算の仕様)
- [配列の定義方法の違い](#配列の定義方法の違い)

### アルゴリズムと探索
- [bit 全探索](#bit-全探索)
- [深さ優先探索 | DFS](#深さ優先探索)
- [DFS 的全探索](#再帰関数による-dfs-的全探索)
- [幅優先探索 | BFS](#幅優先探索)
- [Union-Find](#union-find)
- [尺取り法](#尺取り法)
- [座標圧縮](#座標圧縮)

### 計算テクニック
- [インクリメント](#インクリメント)
- [累積和](#累積和)
- [いもす法（累積和の応用）](#いもすimos法)
- [巨大数での割り算の余り](#巨大数での割り算の余り)
- [天井関数の言い換え](#天井関数の床関数による言い換え)
---

## 解答雛形
### Last Updated : 2026-01-27
```C++
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// const ll mod = 998244353;
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
```

[先頭に戻る](#what-i-learned)

---

## 整数型
### Last Updated : 2025-12-01
### 概要
C++ において、整数型は以下のようにまとめられる。
| 整数型 | 記法 | 10 進法でのおおよその桁数 | 範囲 |
| :---: | :---: | :---: | :---: |
| 32 ビット整数（符号付き） | `int` | 10 | -2^31 ~ 2^31 - 1 |
| 64 ビット整数（符号付き） | `long long` | 19 | -2^63 ~ 2^63 - 1 |
| 64 ビット整数（符号なし） | `unsigned long long` | 20 | 0 ~ 2^64 - 1 |

[先頭に戻る](#what-i-learned)

---


## bit 全探索
### last updated : 2026-01-15
### 使用問題
- 競プロ典型90題 002
- ABC427 B
- ABC321 C
- ABC404 D

### 概要
[ABC404 D](abc/abc401-500/abc401-410/abc404/d.cpp) がわかりやすい。

部分集合のパターンを全列挙する際に用いる手法。
具体的には、大きさ `n` の集合から `i` (0 <= i < n) 番目の要素を選ぶか、選ばないかは `2^n` 通りある。
`n <= 20` であれば十分高速である。

配列の全部分集合の和を計算する例を以下に示す。
```C++
int n = 10;
vector<int> array(n);
rep(bit, 0, 1 << n)
{
  int sum = 0;
  rep(i, 0, n) if ((bit & (1 << i)) != 0) sum += array[i];
  cout << sum << endl;
}
```

**逐行解説**
1. `1 << n` は 1 を n ビット左シフトする(ex. `1 << 10` -> `0b1000000000 = 1024`)
すなわち bit は `0 <= bit < 2^n` の範囲をループ
2. `sum` の初期化
3. `i` は配列 `array` のインデックス
4. `i` 番目のビットが `1` かどうかを判定
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

[先頭に戻る](#what-i-learned)

---

## インクリメント
### Last Updated : 2025-12-01
### 概要
インクリメントには二種類あり、`前置インクリメント` と `後置インクリメント` である。

#### 前置インクリメント
```C++
int i = 0;
int var = ++i; // var = 1, i = 1
```
評価順序は以下の通り。
1. `i` の初期化 (`i = 0`)
2. `i` を `1` 増加 (`i = 1`)
3. 2.の評価値を `var` に代入 (`var = 1`)

#### 後置インクリメント
```C++
int i = 0;
int var = i++; // var = 0, i = 1
```
評価順序は以下の通り。
1. `i` の初期化 (`i = 0`)
2. `i` の値を一時的に保存 (`tmp = 0`)
3. `i` を `1` 増加 (`i = 1`)
4. 保存した値（`temp = 0`）が返り、それが `var` に代入される（`var = 0`）

[先頭に戻る](#what-i-learned)

---

## 整数除算の仕様
### Last Updated : 2025-11-10
### 使用問題
- ABC334 B
- ABC239 B

### 概要
#### C++ の場合
整数型 a, b について、`a / b` は **0に向かう丸め**、**少数部分を無視した数学的な商** として定義される。
すなわち、`a / b` は **a ÷ b の小数部分を切り捨てる** 動作となる。
C++ の整数除算では、「割られる数が負である」 + 「余りが発生している」場合に本来切り捨てられるべき部分が切り上げられてしまう。
`0 < a, b` であれば `floor(a / b)` と同義。

例
```C++
int a = 7, b = 3;
a / b // 2 であり、floor(7 / 3) = 2 に等しい
-a / b // -2 であり、floor(-7 / 3) = -3 と異なる
```

C++ において床関数は以下で定義できる。

```C++
ll floor(ll a, ll b)
{
  if (a < 0 and a % b != 0)
    return a / b - 1;
  else
    return a / b;
}
```

#### Python3 の場合
##### `/` 演算子
常に少数点数を返す。

例
```Python
7 / 3   # 2.333...
-7 / 3  # -2.333...
```

##### `//` 演算子
結果を floor に丸める。すなわち、負の無限大方向に切り下げる。
```Python
7 // 3   # 2
-7 // 3  # -3   # 0方向ではなく floor
```

[先頭に戻る](#what-i-learned)

---


## 配列の定義方法の違い
### Last Updated : 2025-10-16
### 概要
`int array[n]` と `vector<int> array(n)` の違い以下に示す。

| 項目 | int dp[n]  | vector<int> dp(n) |
| :---: | :---: | :---: |
| メモリ確保場所 | スタック | ヒープ |
| サイズ決定 | コンパイル時に固定 | 実行時に動的に決定可能 |
| サイズ変更 | 不可 | 可（`push_back` などで追加可能） |
| 安全性 | 大きいとスタックオーバーフローの可能性あり | ヒープ確保なので安全 |
| 便利機能 | なし | `size()`, `begin()`, `end()`, `push_back()` など利用可能 |
| 使用例 | 小さく固定の配列向き | 大きな配列や動的配列向き |

[先頭に戻る](#what-i-learned)

---

## 累積和
### Last Updated : 2025-12-01
### 概要
#### 0-index の場合
配列 `a[0..n-1]` に対して
```C++
sum[0] = 0
sum[i + 1] = sum[i] + a[i]  // (0 ≤ i < n)
```
- このとき sum は 0..n の n+1 要素
- 区間 [l, r] の和を `sum[r+1] - sum[l]` で計算するため、`sum[r+1]` にアクセスできるように n+1 要素必要

#### 1-index の場合
配列 `a[1..n]` に対して
```C++
sum[0] = 0
sum[i] = sum[i - 1] + a[i]  // (1 ≤ i ≤ n)
```
- このとき sum は 0..n の n+1 要素
- 区間 [l, r] の和を `sum[r] - sum[l - 1]` で計算するため、`sum[0]` が必要

[先頭に戻る](#what-i-learned)

---

## 深さ優先探索
### Last Updated : 2026-01-27
### 概要
```C++
vector<vector<int>> g;
vector<bool> seen;

void dfs(int u)
{
  seen[u] = true;
  for (int v : g[u])
    if (!seen[v])
      dfs(v);
  seen[u] = false;
}
```

[先頭に戻る](#what-i-learned)

---

## 幅優先探索
### Last Updated : 2025-12-12
### 概要
```C++
vector<vector<int>> g;
vector<bool> seen;

void bfs(int v)
{
  queue<int> q;
  q.push(v);
  seen[v] = true;
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    for (int u : g[v])
    {
      if (!seen[u])
        seen[u] = true, q.push(u);
    }
  }
}
```

[先頭に戻る](#what-i-learned)

---

## 巨大数での割り算の余り
### Last Updated : 2025-12-01
### 概要
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

ll moddiv(ll a, ll b, ll m) { return (a * modpow(b, m - 2, m)) % m; }
```

[先頭に戻る](#what-i-learned)

---

## いもす（Imos）法
### Last Updated : 2025-12-24
### 使用問題
- ABC408 C

### 概要
長さ `n + 1` の配列 `a` について、区間 `[l, r]` に値 `x` を加えたいとする。
このとき、以下のような記録をすれば良い。
```C++
a[l] += x, a[r + 1] -= x;
```

上記の操作を全ての区間について行った後、`a` の累積和を取ることで、各位置の値を知ることができる。
すなわち以下を実行する。
```C++
rep(i, 1, n) a[i] += a[i - 1];
```

[先頭に戻る](#what-i-learned)

---

## Union Find
### Last Updated : 2025-11-21
### 使用問題
- ABC399 C
- ABC325 C

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

[先頭に戻る](#what-i-learned)

---

## 尺取り法
### Last Updated : 2025-11-01
### 使用問題
- ABC430 C

### 概要
長さ N の配列を考える。ある性質を満たす区間 `[l, r]` の数を数えたいとき、
全探索では `O(N^2)` になるが、尺取り法を使えば `O(N)` にできる。

**尺取り法の基本手順**
1. 左端 `l` と右端 `r` を `0` に置く。
2. `r` を右に1つずつ動かしながら条件をチェックする。
3. 条件を満たさなくなったら、`l` を右に動かして再び満たすまで縮める。
4. 各ステップで **今の区間が条件を満たすか** を評価し、答えに反映する。

`l` と `r` はともに一方向にしか進まないため，全体で `O(N)` となる。

[先頭に戻る](#what-i-learned)

---

## 再帰関数による DFS 的全探索
### Last Updated : 2025-11-06
### 使用問題
- ABC367 C
### 概要
例えば、長さ `N` で、数列の各項が `[0, M)` となるような数列を列挙したいとする。
この処理は以下のようなコードで実現できる。

参考：[よくやる再帰関数の書き方 〜 n 重 for 文を機械的に 〜](https://drken1215.hatenablog.com/entry/2020/05/04/190252)

```C++
void dfs(vector<int> &A) {
    if (A.size() == N) {
        // 処理
        return;
    }

    for (int v = 0; v < M; ++v) {
        A.push_back(v);
        dfs(A);
        A.pop_back();
    }
}

int main() {
    vector<int> A;
    dfs(A);
}
```

[先頭に戻る](#what-i-learned)

---

## 天井関数の床関数による言い換え
### Last Updated : 2025-11-12
### 概要
```C++
ceil(a / b) = (a + b - 1) / b
```

[先頭に戻る](#what-i-learned)

---

## 座標圧縮
### Last Updated : 2025-12-24
### 概要
数列のそれぞれの要素が **全体で何番目に小さいか** を求める。

例:

```
A = (8, 100, 33, 12, 6, 1211)

1, 4, 3, 2, 0, 5
```

実装

```C++
vector<int> a = {8, 100, 33, 33, 33, 12, 6, 1211};
vector b = a;

// b を小さい順にソート
sort(all(b));

// b から重複を除去
b.erase(unique(all(b)), b.end());

// 座標圧縮した結果
vector<int> ans(a.size());
rep(i, 0, a.size()) ans[i] = lower_bound(all(b), a[i]) - b.begin();

// ans = {1, 4, 3, 3, 3, 2, 0, 5,}
```

[先頭に戻る](#what-i-learned)

---

<!-- ## 
### Last Updated : 
### 使用問題
- 
### 概要


[先頭に戻る](#what-i-learned)

--- -->

---
Copyright © 2025-2026 pantsman