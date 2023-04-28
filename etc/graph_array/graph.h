#pragma once

#include <cstdio>

#define SIZE 10

class GraphInt {
    int vertex_count_ = 0; // количество добавленных вершин
    int matrix_[SIZE][SIZE] = {0}; // матрица смежности
    int verteces_[SIZE];
public:
    GraphInt& add_vertex(int vnumber);
    GraphInt& add_edge(int v1, int v2, int weight = 1);
    void del_edge(int v1, int v2);
    void del_vertex(int vnumber);
};
