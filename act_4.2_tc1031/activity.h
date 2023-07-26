#ifndef ACTIVITY_H
#define ACTIVITY_H

// =========================================================
// File: actitivy.h
// Author: Ricardo Fernandez
// Date: 11/11/2022
// =========================================================

#include "ugraph.h"

// @complexity O(n^2)
template <class Vertex>
void dfs2(Vertex v, const UnweightedGraph<Vertex> *graph,
          std::set<Vertex> &reached, std::stack<Vertex> &TS)
{
  reached.insert(v);

  for (auto i : graph->getConnectionFrom(v))
  {
    if (reached.find(i) == reached.end())
      dfs2(i, graph, reached, TS);
  }

  TS.push(v);
}

// @complexity O(n^2)
template <class Vertex>
std::string topologicalSort(const UnweightedGraph<Vertex> *graph)
{
  std::stringstream aux;
  std::set<Vertex> reached;
  std::stack<Vertex> TS;

  for (auto i : graph->getVertexes())
  {
    if (reached.find(i) == reached.end())
    {
      dfs2(i, graph, reached, TS);
    }
  }
  aux << "[" << TS.top();
  TS.pop();
  while (!TS.empty())
  {
    aux << " ";
    aux << TS.top();
    TS.pop();
  }
  aux << "]";

  return aux.str();
}

// @complexity O(n^2)
template <class Vertex>
bool isBipartite(const UnweightedGraph<Vertex> *graph)
{
  std::set<Vertex> reached;
  std::map<Vertex, int> color;
  std::queue<Vertex> Q;

  for (auto i : graph->getVertexes())
  {
    if (reached.find(i) == reached.end())
    {
      Q.push(i);
      color[i] = 0;
      reached.insert(i);
      while (!Q.empty())
      {
        Vertex v = Q.front();
        Q.pop();
        for (auto j : graph->getConnectionFrom(v))
        {
          if (reached.find(j) == reached.end())
          {
            Q.push(j);
            reached.insert(j);
            color[j] = 1 - color[v];
          }
          else if (color[j] == color[v])
            return false;
        }
      }
    }
  }
  return true;
}

// O(n^2)
template <class Vertex>
bool isCyclic(Vertex v, const UnweightedGraph<Vertex> *graph,
              std::set<Vertex> &reached, Vertex parent)
{
  reached.insert(v);

  for (auto i : graph->getConnectionFrom(v))
  {
    if (reached.find(i) == reached.end())
    {
      if (isCyclic(i, graph, reached, parent))
        return true;
    }
    else if (i != parent)
    {
      return true;
    }
  }

  return false;
}

// @complexity O(n^2)
template <class Vertex>
bool isTree(const UnweightedGraph<Vertex> *graph)
{
  std::set<Vertex> reached;
  std::queue<Vertex> Q;

  for (auto i : graph->getVertexes())
  {
    if (reached.find(i) == reached.end())
    {
      Q.push(i);
      reached.insert(i);
      while (!Q.empty())
      {
        Vertex v = Q.front();
        Q.pop();
        for (auto j : graph->getConnectionFrom(v))
        {
          if (reached.find(j) == reached.end())
          {
            Q.push(j);
            reached.insert(j);
          }
          else
            return false;
        }
      }
    }
  }
  return true;
}

#endif /* ACTIVITY_H */
