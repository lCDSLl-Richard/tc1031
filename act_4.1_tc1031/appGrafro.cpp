#include "ugraph.h"
#include <fstream>

using namespace std;

// @complexity O(n^2)
template <class Vertex>
void loadGraph(int n, int m, UMatrixGraph<Vertex> &umg, UListGraph<Vertex> &ulg, ifstream &inFile)
{
  int a = 0, b = 0;
  for (int i = 0; i < m; i++)
  {
    inFile >> a >> b;
    umg.addEdge(a, b);
    ulg.addEdge(a, b);
  }
}

int main(int argc, char *argv[])
{

  if (argc != 3)
  {
    return -1;
  }

  ifstream inFile(argv[1]);
  ofstream outFile(argv[2]);

  int n = 0, m = 0;

  inFile >> n >> m;

  UMatrixGraph<int> umg(n, false);
  UListGraph<int> ulg(false);

  loadGraph(n, m, umg, ulg, inFile);

  cout << umg.toString() << endl
       << ulg.toString();

  dfs(2, &umg);
  cout << endl;

  bfs(2, &ulg);
  cout << endl;
}