# 基础知识

* 并查集及其简单应用。例如洛谷P1551亲戚问题

   ~~~C++
   #include <iostream>
   using namespace std;
   int fa[5002];
   int ra[5002];
   inline void init(const int &n)
   {
       for (int i = 1; i <= n; i++)
       {
           fa[i] = i;
           ra[i] = 1;
       }
   }
   inline int find(const int &i)
   {
       return fa[i] == i ? i : fa[i] = find(fa[i]);
   }
   inline void merge(const int &i, const int &j)
   {
       int x = find(i);
       int y = find(j);
       ra[x] <= ra[y] ? fa[x] = y : fa[y] = x;
       if (ra[x] == ra[y] && x != y)
       {
           ra[y]++;
       }
   }
   int main()
   {
       ios::sync_with_stdio;
       int n, m, p;
       cin >> n >> m >> p;
       int x, y;
       init(n);
       for (int i = 1; i <= m; i++)
       {
           cin >> x >> y;
           merge(x, y);
       }
       for (int i = 1; i <= p; i++)
       {
           cin >> x >> y;
           find(x) == find(y) ? cout << "Yes" << endl : cout << "No" << endl;
       }
       return 0;
   }
   ~~~

* 拓扑排序及其简单应用。例如洛谷P4017最大食物链计数

   ~~~c++
   #include <iostream>
   #include <vector>
   #include <queue>
   using namespace std;
   int main()
   {
       ios::sync_with_stdio(false);
       int n, m;
       vector<int> edge[5002];
       queue<int> q;
       int in[5002] = {0};
       int out[5002] = {0};
       int ans[5002] = {0};
       cin >> n >> m;
       int u, v;
       const int mod = 80112002;
       for (int i = 1; i <= m; i++)
       {
           cin >> u >> v;
           edge[u].push_back(v);
           out[u]++;
           in[v]++;
       }
       for (int i = 1; i <= n; i++)
       {
           if (!in[i])
               q.push(i), ans[i] = 1;
       }
       while (!q.empty())
       {
           int p = q.front();
           q.pop();
           for (int i = 0; i < edge[p].size(); i++)
           {
               int v = edge[p][i];
               in[v]--;
               ans[v] = (ans[v] + ans[p]) % mod;
               if (!in[v])
                   q.push(v);
           }
       }
       int final_ans = 0;
       for (int i = 1; i <= n; i++)
       {
           if (!out[i])
               final_ans = (final_ans + ans[i]) % mod;
       }
       cout << final_ans;
       return 0;
   }
   ~~~

  

* 前缀和。用于快速且大量的求一段区间的和。

* 差分。用于快速改变一段区间的值。例如要改变[a,b]，每个加x，只要a处加x，b+1处减x即可。

# Unity 模块实现

* 敌人AI实现。参考的bilibili的视频。https://github.com/KevinChang7777/Unity/ EnemyAI
* 背包系统实现。https://github.com/KevinChang7777/Unity/ bagSystem

# 策划

* 横版2D冒险
* 背景：因为一场意外被传送到了异世界，需要努力回家
* 通过战斗击败敌人获取物品和属性提升，规避机关障碍。抵达终点标志胜利。
* 模块：背包，敌人AI等
