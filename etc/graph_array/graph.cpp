// #include <cstring> // for memset
#include <iostream>

#include "graph.h"

namespace {
const int big_int = 1'000'000'000;
} // namespace

GraphInt& GraphInt::add_vertex(int vnumber)
{
    assert(vnumber >= 0); // developer check

    verteces_[vertex_count_++] = vnumber;
    return *this;
}

GraphInt& GraphInt::add_edge(int v1, int v2, int weight)
{
    assert(v1 >= 0 || v2 >= 0);

    matrix_[v1][v2] = weight;
    matrix_[v2][v1] = weight;
    return *this;
}

void GraphInt::del_edge(int v1, int v2)
{
    assert(v1 >= 0 && v2 >= 0);

    matrix_[v1][v2] = 0;
    matrix_[v2][v1] = 0;
}

void GraphInt::del_vertex(int vnumber)
{
    assert(vnumber >= 0 || vnumber <= vertex_count_);
    size_t i, index_num;

    for (i = 0; i < SIZE; ++i) {
        matrix_[i][vnumber] = 0;
        matrix_[vnumber][i] = 0;
    }

    for (i = 0; i < vertex_count_; ++i) {
        if (verteces_[i] == vnumber) {
            index_num = i;
        }
    }

    vertex_count_--;
    for (i = index_num; i < vertex_count_; ++i) {
        verteces_[i] = verteces_[i + 1];
    }
}

bool GraphInt::does_edge_exist(int v1, int v2) const noexcept
{
    return matrix_[v1][v2] > 0;
}

bool GraphInt::does_vertex_exist(int v) const noexcept
{
    size_t i;
    for (i = 0; i < vertex_count_; ++i) {
        if (verteces_[i] == v)
            return true;
    }
    return false;
}

// graph traversal
void GraphInt::dfs(int start) // depth first search
{
    assert(start >= 0 || start <= vertex_count_);
    bool visited[SIZE] = { 0 };

    dfs_inner_recursive(start, visited);
    std::cout << std::endl;
}

void GraphInt::dfs_inner_recursive(int current, bool* visited)
{
    assert(visited != NULL);

    std::cout << "V" << current << ", ";
    visited[current] = true;
    for (size_t i = 0; i < vertex_count_; ++i) { // проходимся по все смежным вершинам
        int v_index = verteces_[i]; // берём настоящий номер вершины
        if (does_edge_exist(current, v_index) != 0 && !visited[v_index]) { // проверяем смежность и вершина не должно быть посещена
            dfs_inner_recursive(v_index, visited);
        }
    }
}

void GraphInt::dfs_inner_iterative(int current, bool* visited) // stack
{
    assert(visited != NULL);
}

void GraphInt::bfs(int start) // breadth first search, queue
{
    assert(start >= 0 && start <= vertex_count_);

    bool visited[SIZE] = { 0 };
    int queue_to_visit[SIZE]; // очередь вершин для обхода
    int queue_count = 0;

    queue_to_visit[queue_count++] = start; // кладём начальную вершину
    while (queue_count > 0) { // цикл по очереди
        int current = queue_to_visit[0]; // берём из вершины
        queue_count--;
        for (int i = 0; i < queue_count; i++) {
            queue_to_visit[i] = queue_to_visit[i + 1];
        }
        visited[current] = true;
        std::cout << "V" << current << ", ";

        for (int i = 0; i < SIZE; ++i) {
            bool already_added = false;
            for (int j = 0; j < queue_count; ++j) {
                if (queue_to_visit[j] == i) {
                    already_added = true;
                    break;
                }
            }
            if (!already_added && does_edge_exist(current, i) && !visited[i])
                queue_to_visit[queue_count++] = i;
        }
    }
    std::cout << std::endl;
}

// shortest path searching algorithms
void GraphInt::find_shortest_path(int v_from) // dijkstra's algorithm, for non-negative edge weight
{
    assert(v_from > 0);
    int distances[SIZE]; // массив меток
    bool passed[SIZE] = { 0 }; // признак, что вершина окрашена. все неокрашенные изначально
    // std::memset(distances, big_int, sizeof(distances));
    for (int i = 0; i < SIZE; ++i) {
        distances[i] = big_int;
    }

    distances[v_from] = 0;

    int current_vertex = v_from;
    int min_dist = 0;
    while (min_dist != big_int) {
        // окрашиваем текущую вершину
        passed[current_vertex] = true;
        // пересчитываем метки
        for (int i = 0; i < SIZE; ++i) {
            int sum_current_weight = distances[current_vertex] + matrix_[current_vertex][i];
            if (does_edge_exist(current_vertex, i) && sum_current_weight < distances[i])
                distances[i] = sum_current_weight;
        }
        // находим минимальную метку среди неокрашенных
        min_dist = big_int;
        for (int i = 0; i < SIZE; ++i) {
            if (does_vertex_exist(i) && !passed[i] && distances[i] < min_dist) {
                min_dist = distances[i];
                current_vertex = i;
            }
        }
    }

    for (int i = 0; i < vertex_count_; ++i) {
        std::cout << "V" << i << ": " << distances[verteces_[i]] << ", ";
    }
    std::cout << std::endl;
}
