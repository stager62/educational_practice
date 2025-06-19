#include <iostream>
#include <vector>

//используем поиск в глубину, посещаем вешину и смотрим ее соседей, если они не поещены, то вызываем dfs оттуда
void dfs(int v, std::vector<bool>& visited, std::vector<std::vector<int>>& graph) {
  visited[v] = true;
  for (int u : graph[v]) {
    if (!visited[u]) {
      dfs(u, visited, graph);
    }
  }
}

int main() {
  int n = 0;
  int m = 0;
  int components = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n + 1); //список смежности
  std::vector<bool> visited(n + 1, false); //посещена вершина или нет

  for (int i = 0; i < m; i = i + 1) { //создаем список смежности
    int u = 0;
    int v = 0;
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

//смотрим посещена вершина или нет, если нет, то +1 к комонентам и запускаем dfs
  for (int i = 1; i <= n; i = i + 1) {
    if (!visited[i]) {
      dfs(i, visited, graph);
      components = components + 1;
    }
  }
    
  std::cout << components - 1;
  return 0;
}