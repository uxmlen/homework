#pragma once

#include <cassert>

#define SIZE 10

// implementation graph without using containers STL
class GraphInt {
    int vertex_count_ = 0; // количество добавленных вершин
    int verteces_[SIZE];
    int matrix_[SIZE][SIZE] = { 0 }; // матрица смежности {Adjacency Matrix)
                                     // space complexity is O(n^2)
public:
    bool does_edge_exist(int v1, int v2) const noexcept;
    bool does_vertex_exist(int v) const noexcept;

    GraphInt& add_vertex(int vnumber);
    GraphInt& add_edge(int v1, int v2, int weight = 1); // O(1)

    void del_edge(int v1, int v2); // O(1)
    void del_vertex(int vnumber);

    // shortest path searching algorithms
    void find_shortest_path(int v_from); // deijkstra's algorithms
    // graph traversal
    void dfs(int start); // depth first search
    void bfs(int start); // breadth first search
private:
    void dfs_inner_recursive(int start, bool* visited);
    void dfs_inner_iterative(int start, bool* visited); // stack
};
