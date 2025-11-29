#pragma once
#include <iterator>
#include <memory>
#include <vector>

template<typename T>
class Graph;
template<typename T>
class Vertex;
template<typename T>
class Edge;

template<typename T>
class IncidentEdgeIterator {
private:
    using VertexPtr = std::shared_ptr<Vertex<T>>;
    using EdgePtr = std::shared_ptr<Edge<T>>;

    Graph<T>* graph;
    VertexPtr base_vertex;
    size_t current_index;

    void find_next_incident() {
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
    using value_type = EdgePtr;
    using difference_type = std::ptrdiff_t;
    using pointer = EdgePtr*;
    using reference = EdgePtr&;

    IncidentEdgeIterator(Graph<T>* g, VertexPtr base, size_t start = 0)
        : graph(g), base_vertex(base), current_index(start) {
        find_next_incident();
    }

    // Конструктор по умолчанию
    IncidentEdgeIterator() noexcept : graph(nullptr), base_vertex(nullptr), current_index(0) {}

    EdgePtr operator*() const {
        if (!graph || current_index >= graph->vertices.size()) {
            return nullptr;
        }

        // Ищем существующее ребро в кэше
        VertexPtr neighbor = graph->vertices[current_index];
        for (const auto& edge : graph->edges) {
            if ((edge->getFrom() == base_vertex && edge->getTo() == neighbor) ||
                (edge->getTo() == base_vertex && edge->getFrom() == neighbor)) {
                return edge;
            }
        }

        // Если не нашли, создаем временное представление
        return std::make_shared<Edge<T>>(base_vertex, neighbor);
    }

    IncidentEdgeIterator& operator++() {
        if (graph && base_vertex) {
            ++current_index;
            find_next_incident();
        }
        return *this;
    }

    IncidentEdgeIterator operator++(int) {
        IncidentEdgeIterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const IncidentEdgeIterator& other) const {
        return current_index == other.current_index &&
            base_vertex == other.base_vertex &&
            graph == other.graph;
    }

    bool operator!=(const IncidentEdgeIterator& other) const {
        return !(*this == other);
    }
};