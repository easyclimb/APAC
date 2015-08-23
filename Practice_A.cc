#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int color[201];
bool visit[201];

bool bfs(vector<vector<int>>& graph, int start, int n) {
    memset(color, -1, sizeof(color));
    memset(visit, 0, sizeof(visit));
    queue<int> que;
    que.push(start);
    visit[start] = true;
    color[start] = 0;
    while(!que.empty()) {
        int id = que.front();
        que.pop();
        int size = graph[id].size();
        for(int i = 0; i < size; i++) {
            int id_cur = graph[id][i];
            if(color[id_cur] == -1) {
                color[id_cur] = (color[id] + 1)%2;
                visit[id_cur] = true;
                queue.push(id_cur);
            }
            else {
                if(color[id_cur] == color[id]) return false;
            }
        }
    }
    for(int i = 0; i < n; i++)
        if(!visit[i]) return bfs(graph, i, n);
    return true;
}

int main()
{
    freopen("A-small-practice-1.in", "r", stdin);
    freopen("A-small-practice-1.out", "w", stdout);
    int numCase;
    cin >> numCase;
    for(int i = 1; i <= numCase; i++) {
        int numInput;
        cin >> numInput;
        vector<vector<int>> graph(201);
        unordered_map<string, int> id;
        string a, b;
        int cur_id = 0, id_a, id_b;
        for(int j = 0; j < numInput; j++) {
            cin >> a >> b;
            if(id.find(a) != id.end())
                id_a = id[a];
            else {
                id[a] = cur_id;
                id_a = cur_id;
                cur_id++;
            }
            if(id.find(b) != id.end())
                id_b = id[b];
            else {
                id[b] = cur_id;
                id_b = cur_id;
                cur_id++;
            }
            graph[id_a].push_back(id_b);
            graph[id_b].push_back(id_a);
        }
        if(bfs(graph, 0, cur_id))
            cout << "Case #" << numCase << ": Yes" << endl;
        else
            cout << "Case #" << numCase << ": No" << endl;
    }
    return 0;
}
