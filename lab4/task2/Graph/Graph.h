#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <memory>
#include <map>
#include "Vertex.h"
#include "Edge.h"
#include "VertexIterator.h"
#include "ConstVertexIterator.h"
#include "EdgeIterator.h"
#include "ConstEdgeIterator.h"
#include "IncidentEdgeIterator.h"
#include "AdjacentVertexIterator.h"

template<typename T>
class Graph {
public:
    // STL-òðåáîâàíèÿ: typedef'û
    using value_type = std::shared_ptr<Vertex<T>>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    using vertex_type = Vertex<T>;
    using edge_type = Edge<T>;
    using vertex_ptr = value_type;
    using edge_ptr = std::shared_ptr<edge_type>;

    // Èòåðàòîðû
    using vertex_iterator = VertexIterator<T>;
    using const_vertex_iterator = ConstVertexIterator<T>;
    using reverse_vertex_iterator = std::reverse_iterator<vertex_iterator>;
    using const_reverse_vertex_iterator = std::reverse_iterator<const_vertex_iterator>;

    using edge_iterator = EdgeIterator<T>;
    using const_edge_iterator = ConstEdgeIterator<T>;
    using reverse_edge_iterator = std::reverse_iterator<edge_iterator>;
    using const_reverse_edge_iterator = std::reverse_iterator<const_edge_iterator>;

    using incident_edge_iterator = IncidentEdgeIterator<T>;
    using adjacent_vertex_iterator = AdjacentVertexIterator<T>;

private:
    std::vector<vertex_ptr> vertices;
    std::vector<std::vector<bool>> adjacency_matrix;

    // Âñïîìîãàòåëüíûå ìåòîäû
    size_type find_vertex_index(vertex_ptr vertex) const {
        for (size_type i = 0; i < vertices.size(); ++i) {
            if (vertices[i] == vertex) return i;
        }
        return vertices.size();
    }

    void update_matrix_after_vertex_removal(size_type index) {
        // Óäàëÿåì ñòðîêó
        adjacency_matrix.erase(adjacency_matrix.begin() + index);

        // Óäàëÿåì ñòîëáåö èç âñåõ ñòðîê
        for (auto& row : adjacency_matrix) {
            if (row.size() > index) {
                row.erase(row.begin() + index);
            }
        }
    }

public:
    // ===== ÊÎÍÑÒÐÓÊÒÎÐÛ È ÄÅÑÒÐÓÊÒÎÐ =====
    Graph() noexcept = default;

    Graph(const Graph& other) {
        // Êîïèðóåì âåðøèíû
        std::map<vertex_ptr, vertex_ptr> vertex_map;
        for (const auto& v : other.vertices) {
            auto new_vertex = std::make_shared<vertex_type>(*v);
            vertices.push_back(new_vertex);
            vertex_map[v] = new_vertex;
        }

        // Ïåðåñòðàèâàåì ìàòðèöó ñìåæíîñòè
        adjacency_matrix.resize(vertices.size(), std::vector<bool>(vertices.size(), false));

        for (size_type i = 0; i < other.vertices.size(); ++i) {
            for (size_type j = 0; j < other.vertices.size(); ++j) {
                if (other.adjacency_matrix[i][j]) {
                    size_type new_i = std::distance(vertices.begin(),
                        std::find(vertices.begin(), vertices.end(), vertex_map[other.vertices[i]]));
                    size_type new_j = std::distance(vertices.begin(),
                        std::find(vertices.begin(), vertices.end(), vertex_map[other.vertices[j]]));
                    adjacency_matrix[new_i][new_j] = true;
                }
            }
        }
    }

    ~Graph() = default;

    // ===== ÎÑÍÎÂÍÛÅ ÌÅÒÎÄÛ ÊÎÍÒÅÉÍÅÐÀ =====
    bool empty() const noexcept { return vertices.empty(); }

    void clear() noexcept {
        vertices.clear();
        adjacency_matrix.clear();
    }

    size_type size() const noexcept { return vertices.size(); }

    // ===== ÎÏÅÐÀÒÎÐ ÏÐÈÑÂÀÈÂÀÍÈß =====
    Graph& operator=(const Graph& other) {
        if (this != &other) {
            clear();
            Graph temp(other);
            std::swap(vertices, temp.vertices);
            std::swap(adjacency_matrix, temp.adjacency_matrix);
        }
        return *this;
    }

    // ===== ÎÏÅÐÀÒÎÐÛ ÑÐÀÂÍÅÍÈß =====
    bool operator==(const Graph& other) const {
        if (vertices.size() != other.vertices.size()) return false;

        // Ñðàâíèâàåì òîëüêî ñòðóêòóðó ãðàôà (ðåáðà)
        for (size_type i = 0; i < vertices.size(); ++i) {
            for (size_type j = 0; j < vertices.size(); ++j) {
                if (adjacency_matrix[i][j] != other.adjacency_matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Graph& other) const { return !(*this == other); }
    bool operator<(const Graph& other) const { return vertexCount() < other.vertexCount(); }
    bool operator>(const Graph& other) const { return vertexCount() > other.vertexCount(); }
    bool operator<=(const Graph& other) const { return vertexCount() <= other.vertexCount(); }
    bool operator>=(const Graph& other) const { return vertexCount() >= other.vertexCount(); }

    // ===== ÌÅÒÎÄÛ ÄËß ÐÀÁÎÒÛ Ñ ÂÅÐØÈÍÀÌÈ =====
    bool containsVertex(vertex_ptr vertex) const {
        return find_vertex_index(vertex) != vertices.size();
    }

    size_type vertexCount() const noexcept { return vertices.size(); }

    vertex_ptr addVertex(const T& value) {
        auto new_vertex = std::make_shared<vertex_type>(value);
        vertices.push_back(new_vertex);

        // Ðàñøèðÿåì ñóùåñòâóþùèå ñòðîêè
        for (auto& row : adjacency_matrix) {
            row.push_back(false);
        }

        // Äîáàâëÿåì íîâóþ ñòðîêó
        adjacency_matrix.push_back(std::vector<bool>(vertices.size(), false));

        return new_vertex;
    }

    vertex_ptr getVertex(size_type index) const {
        if (index >= vertices.size()) {
            throw std::out_of_range("Vertex index out of range");
        }
        return vertices[index];
    }

    bool removeVertex(vertex_ptr vertex) {
        size_type index = find_vertex_index(vertex);
        if (index == vertices.size()) return false;

        // Óäàëÿåì âåðøèíó
        vertices.erase(vertices.begin() + index);
        update_matrix_after_vertex_removal(index);
        return true;
    }

    // ===== ÌÅÒÎÄÛ ÄËß ÐÀÁÎÒÛ Ñ ÐÅÁÐÀÌÈ =====
    bool containsEdge(vertex_ptr from, vertex_ptr to) const {
        size_type i = find_vertex_index(from);
        size_type j = find_vertex_index(to);
        return i != vertices.size() && j != vertices.size() && adjacency_matrix[i][j];
    }

    bool containsEdge(edge_ptr edge) const {
        return containsEdge(edge->getFrom(), edge->getTo());
    }

    size_type edgeCount() const noexcept {
        size_type count = 0;
        for (size_type i = 0; i < vertices.size(); ++i) {
            for (size_type j = i + 1; j < vertices.size(); ++j) {
                if (adjacency_matrix[i][j]) ++count;
            }
        }
        return count;
    }

    edge_ptr addEdge(vertex_ptr from, vertex_ptr to) {
        size_type i = find_vertex_index(from);
        size_type j = find_vertex_index(to);

        if (i == vertices.size() || j == vertices.size()) {
            throw std::invalid_argument("One or both vertices not found");
        }

        if (i == j) {
            throw std::invalid_argument("Self-loops not allowed");
        }

        adjacency_matrix[i][j] = true;
        adjacency_matrix[j][i] = true;  // Íåîðèåíòèðîâàííûé ãðàô

        return std::make_shared<edge_type>(from, to);
    }

    edge_ptr addEdge(size_type fromIndex, size_type toIndex) {
        if (fromIndex >= vertices.size() || toIndex >= vertices.size()) {
            throw std::out_of_range("Vertex index out of range");
        }
        return addEdge(vertices[fromIndex], vertices[toIndex]);
    }

    bool removeEdge(vertex_ptr from, vertex_ptr to) {
        size_type i = find_vertex_index(from);
        size_type j = find_vertex_index(to);

        if (i == vertices.size() || j == vertices.size()) return false;

        adjacency_matrix[i][j] = false;
        adjacency_matrix[j][i] = false;
        return true;
    }

    bool removeEdge(edge_ptr edge) {
        return removeEdge(edge->getFrom(), edge->getTo());
    }

    // ===== ÂÛ×ÈÑËÅÍÈÅ ÑÒÅÏÅÍÅÉ =====
    size_type vertexDegree(vertex_ptr vertex) const {
        size_type index = find_vertex_index(vertex);
        if (index == vertices.size()) return 0;

        size_type count = 0;
        for (size_type i = 0; i < vertices.size(); ++i) {
            if (adjacency_matrix[index][i]) ++count;
        }
        return count;
    }

    size_type edgeDegree(edge_ptr edge) const noexcept {
        return 2;  // Äëÿ íåîðèåíòèðîâàííîãî ãðàôà
    }

    // ===== ÓÄÀËÅÍÈÅ ÏÎ ÈÒÅÐÀÒÎÐÀÌ =====
    bool removeVertex(vertex_iterator it) {
        return removeVertex(*it);
    }

    bool removeEdge(edge_iterator it) {
        return removeEdge(*it);
    }

    // ===== ÈÒÅÐÀÒÎÐÛ ÂÅÐØÈÍ =====
    vertex_iterator verticesBegin() {
        return vertex_iterator(this, vertices.begin());
    }

    vertex_iterator verticesEnd() {
        return vertex_iterator(this, vertices.end());
    }

    const_vertex_iterator verticesCBegin() const {
        return const_vertex_iterator(this, vertices.begin());
    }

    const_vertex_iterator verticesCEnd() const {
        return const_vertex_iterator(this, vertices.end());
    }

    reverse_vertex_iterator verticesRBegin() {
        return reverse_vertex_iterator(verticesEnd());
    }

    reverse_vertex_iterator verticesREnd() {
        return reverse_vertex_iterator(verticesBegin());
    }

    const_reverse_vertex_iterator verticesCRBegin() const {
        return const_reverse_vertex_iterator(verticesCEnd());
    }

    const_reverse_vertex_iterator verticesCREnd() const {
        return const_reverse_vertex_iterator(verticesCBegin());
    }

    // Â êëàññå Graph èñïðàâüòå ìåòîäû èòåðàòîðîâ:

// ===== ÈÒÅÐÀÒÎÐÛ ÐÅÁÅÐ =====
    edge_iterator edgesBegin() {
        return edge_iterator(this, 0, 0);
    }

    edge_iterator edgesEnd() {
        return edge_iterator(this, vertices.size(), 0);
    }

    const_edge_iterator edgesCBegin() const {
        return const_edge_iterator(this, 0, 0);
    }

    const_edge_iterator edgesCEnd() const {
        return const_edge_iterator(this, vertices.size(), 0);
    }

    // ===== ÈÍÖÈÄÅÍÒÍÛÅ ÐÅÁÐÀ =====
    incident_edge_iterator incidentEdgesBegin(vertex_ptr vertex) {
        return incident_edge_iterator(this, vertex, 0);
    }

    incident_edge_iterator incidentEdgesEnd(vertex_ptr vertex) {
        return incident_edge_iterator(this, vertex, vertices.size());
    }

    // ===== ÑÌÅÆÍÛÅ ÂÅÐØÈÍÛ =====
    adjacent_vertex_iterator adjacentBegin(vertex_ptr vertex) {
        return adjacent_vertex_iterator(this, vertex, 0);
    }

    adjacent_vertex_iterator adjacentEnd(vertex_ptr vertex) {
        return adjacent_vertex_iterator(this, vertex, vertices.size());
    }


    // Äëÿ äîñòóïà èç èòåðàòîðîâ
    template<typename U> friend class VertexIterator;
    template<typename U> friend class ConstVertexIterator;
    template<typename U> friend class EdgeIterator;
    template<typename U> friend class ConstEdgeIterator;
    template<typename U> friend class IncidentEdgeIterator;
    template<typename U> friend class AdjacentVertexIterator;

    // ===== ÎÏÅÐÀÒÎÐ ÂÛÂÎÄÀ =====
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        os << "Graph with " << graph.vertexCount() << " vertices and " << graph.edgeCount() << " edges\n";

        os << "Vertices: ";
        for (auto it = graph.verticesCBegin(); it != graph.verticesCEnd(); ++it) {
            os << **it << " ";
        }

        os << "\nEdges: ";
        for (auto it = graph.edgesCBegin(); it != graph.edgesCEnd(); ++it) {
            os << **it << " ";
        }

        return os;
    }

};
