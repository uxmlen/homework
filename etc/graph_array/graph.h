#pragma once

#include <cassert>
#include <cstdio>

#define SIZE 10

// implementation graph without using containers STL
class GraphInt {
    size_t vertex_count_ = 0; // количество добавленных вершин
    int matrix_[SIZE][SIZE] = { 0 }; // матрица смежности
    int verteces_[SIZE];

public:
    bool does_edge_exist(int v1, int v2) const noexcept;
    bool does_vertex_exist(int v) const noexcept;

    GraphInt& add_vertex(int vnumber);
    GraphInt& add_edge(int v1, int v2, int weight = 1);

    void del_edge(int v1, int v2);
    void del_vertex(int vnumber);

    // graph traversail
    void dfs(int start); // depth first search
    void bfs(int start); // breadth first search
private:
    void dfs_inner_recursive(int start, bool* visited);
    void dfs_inner_iterative(int start, bool* visited); // stack
};
