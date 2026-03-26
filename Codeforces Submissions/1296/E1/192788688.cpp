#include <cstdio>
#include <vector>

const int N = 200;
std::vector<int> adj_list[N];
bool color[N], visited[N];
char str[N];
int n;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj_list[v]) {
        if (!visited[u]) {
            color[u] = !color[v];
            dfs(u);
        }
    }
}

bool bipartite() {
    for (int v = 0; v < n; v++) {
        for (int u : adj_list[v]) {
            if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

void insert_edge(int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        str[i] = getchar();
        for (int j = 0; j < i; j++) {
            if (str[i] < str[j]) {
                insert_edge(i,  j);
            }
        }
    }
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    if (bipartite()) {
        puts("YES");
        for (int i = 0; i < n; i++) {
            putchar(color[i] ? '1' : '0');
        }
    } else {
        puts("NO");
    }
}

