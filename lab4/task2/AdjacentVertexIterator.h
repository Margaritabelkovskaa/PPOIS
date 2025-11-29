#pragma once
#include <iterator>
#include <memory>
#include <vector>

template<typename T>
class Graph;
template<typename T>
class Vertex;

template<typename T>
class AdjacentVertexIterator {
private:
    using VertexPtr = std::shared_ptr<Vertex<T>>;

    Graph<T>* graph;
    VertexPtr base_vertex;
    size_t current_index;

    void find_next_adjacent() {
        if (!graph || !base_vertex) return;

        size_t n = graph->vertices.size();
        size_t base_index = graph->find_vertex_index(base_vertex);

        if (base_index >= n) return;

        while (current_index < n) {
            if (graph->adjacency_matrix[base_index][current_index] &&
                base_index != current_index) {
                return;
            }
            ++current_index;
        }
    }

public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = VertexPtr;
    using difference_type = std::ptrdiff_t;
    using pointer = VertexPtr*;
    using reference = VertexPtr&;

    AdjacentVertexIterator(Graph<T>* g, VertexPtr base, size_t start = 0)
        : graph(g), base_vertex(base), current_index(start) {
        find_next_adjacent();
    }

    AdjacentVertexIterator() noexcept : graph(nullptr), base_vertex(nullptr), current_index(0) {}

    VertexPtr operator*() const {
        if (!graph || current_index >= graph->vertices.size()) {
            return nullptr;
        }
        return graph->vertices[current_index];
    }

    AdjacentVertexIterator& operator++() {
        if (graph && base_vertex) {
            ++current_index;
            find_next_adjacent();
        }
        return *this;
    }

    AdjacentVertexIterator operator++(int) {
        AdjacentVertexIterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const AdjacentVertexIterator& other) const {
        return current_index == other.current_index &&
            base_vertex == other.base_vertex &&
            graph == other.graph;
    }

    bool operator!=(const AdjacentVertexIterator& other) const {
        return !(*this == other);
    }
};