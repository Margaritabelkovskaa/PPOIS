#pragma once
#include <iterator>
#include <memory>
#include <vector>

template<typename T>
class Edge;

template<typename T>
class Graph;

template<typename T>
class EdgeIterator {
private:
    Graph<T>* graph;
    size_t i, j;

    void find_next_edge() {
        if (!graph) return;
        size_t n = graph->vertices.size();

        while (i < n) {
            while (j < n) {
                if (graph->adjacency_matrix[i][j] && i < j) {
                    return;
                }
                ++j;
            }
            ++i;
            j = i + 1;
        }
        i = n;
        j = 0;
    }

public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::shared_ptr<Edge<T>>;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    EdgeIterator(Graph<T>* g, size_t start_i = 0, size_t start_j = 0)
        : graph(g), i(start_i), j(start_j) {
        if (graph && i < graph->vertices.size()) {
            if (j == 0) j = i + 1;
            find_next_edge();
        }
    }

    value_type operator*() const {
        if (!graph || i >= graph->vertices.size() || j >= graph->vertices.size()) {
            return nullptr;
        }
        return std::make_shared<Edge<T>>(graph->vertices[i], graph->vertices[j]);
    }

    EdgeIterator& operator++() {
        if (graph) {
            ++j;
            find_next_edge();
        }
        return *this;
    }

    EdgeIterator operator++(int) {
        EdgeIterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const EdgeIterator& other) const {
        return i == other.i && j == other.j && graph == other.graph;
    }

    bool operator!=(const EdgeIterator& other) const {
        return !(*this == other);
    }
};
