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

// Ïğåäâàğèòåëüíûå îáúÿâëåíèÿ
template<typename T> class VertexIterator;
template<typename T> class ConstVertexIterator;
template<typename T> class EdgeIterator;
template<typename T> class ConstEdgeIterator;
template<typename T> class IncidentEdgeIterator;
template<typename T> class AdjacentVertexIterator;

template<typename T>
class Graph {
public:
    // STL-òğåáîâàíèÿ: typedef'û
    using value_type = std::shared_ptr<Vertex<T>>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    // Èòåğàòîğû
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
    // Ìàòğèöà ñìåæíîñòè
    std::vector<value_type> vertices;
    std::vector<std::vector<bool>> adjacency_matrix;
    std::vector<std::shared_ptr<Edge<T>>> edges;

    // Âñïîìîãàòåëüíûå ìåòîäû
    size_type find_vertex_index(value_type vertex) const;
    void update_matrix_after_vertex_removal(size_type index);
    void rebuild_edges();

public:
    // ===== ÊÎÍÑÒĞÓÊÒÎĞÛ È ÄÅÑÒĞÓÊÒÎĞ =====
    Graph() noexcept;
    Graph(const Graph& other);
    ~Graph() = default;

    // ===== ÎÑÍÎÂÍÛÅ ÌÅÒÎÄÛ ÊÎÍÒÅÉÍÅĞÀ =====
    bool empty() const noexcept;
    void clear() noexcept;
    size_type size() const noexcept;

    // ===== ÎÏÅĞÀÒÎĞ ÏĞÈÑÂÀÈÂÀÍÈß =====
    Graph& operator=(const Graph& other);

    // ===== ÎÏÅĞÀÒÎĞÛ ÑĞÀÂÍÅÍÈß =====
    bool operator==(const Graph& other) const;
    bool operator!=(const Graph& other) const;
    bool operator<(const Graph& other) const;
    bool operator>(const Graph& other) const;
    bool operator<=(const Graph& other) const;
    bool operator>=(const Graph& other) const;

    // ===== ÌÅÒÎÄÛ ÄËß ĞÀÁÎÒÛ Ñ ÂÅĞØÈÍÀÌÈ =====
    bool containsVertex(value_type vertex) const;
    size_type vertexCount() const noexcept;
    value_type addVertex(const T& value);
    value_type getVertex(size_type index) const;
    bool removeVertex(value_type vertex);

    // ===== ÌÅÒÎÄÛ ÄËß ĞÀÁÎÒÛ Ñ ĞÅÁĞÀÌÈ =====
    bool containsEdge(value_type from, value_type to) const;
    size_type edgeCount() const noexcept;
    std::shared_ptr<Edge<T>> addEdge(value_type from, value_type to);
    std::shared_ptr<Edge<T>> addEdge(size_type fromIndex, size_type toIndex);
    bool removeEdge(std::shared_ptr<Edge<T>> edge);

    // ===== ÂÛ×ÈÑËÅÍÈÅ ÑÒÅÏÅÍÅÉ =====
    size_type vertexDegree(value_type vertex) const;
    size_type edgeDegree(std::shared_ptr<Edge<T>> edge) const noexcept;

    // ===== ÓÄÀËÅÍÈÅ ÏÎ ÈÒÅĞÀÒÎĞÀÌ =====
    bool removeVertex(vertex_iterator it);
    bool removeVertex(const_vertex_iterator it);
    bool removeEdge(edge_iterator it);
    bool removeEdge(const_edge_iterator it);

    // ===== ÈÒÅĞÀÒÎĞÛ ÂÅĞØÈÍ =====
    vertex_iterator verticesBegin();
    vertex_iterator verticesEnd();
    const_vertex_iterator verticesCBegin() const;
    const_vertex_iterator verticesCEnd() const;
    reverse_vertex_iterator verticesRBegin();
    reverse_vertex_iterator verticesREnd();
    const_reverse_vertex_iterator verticesCRBegin() const;
    const_reverse_vertex_iterator verticesCREnd() const;

    // ===== ÈÒÅĞÀÒÎĞÛ ĞÅÁÅĞ =====
    edge_iterator edgesBegin();
    edge_iterator edgesEnd();
    const_edge_iterator edgesCBegin() const;
    const_edge_iterator edgesCEnd() const;
    reverse_edge_iterator edgesRBegin();
    reverse_edge_iterator edgesREnd();
    const_reverse_edge_iterator edgesCRBegin() const;
    const_reverse_edge_iterator edgesCREnd() const;

    // ===== ÈÍÖÈÄÅÍÒÍÛÅ ĞÅÁĞÀ =====
    incident_edge_iterator incidentEdgesBegin(value_type vertex);
    incident_edge_iterator incidentEdgesEnd(value_type vertex);

    // ===== ÑÌÅÆÍÛÅ ÂÅĞØÈÍÛ =====
    adjacent_vertex_iterator adjacentBegin(value_type vertex);
    adjacent_vertex_iterator adjacentEnd(value_type vertex);

    // Äëÿ äîñòóïà èç èòåğàòîğîâ (äğóæåñòâåííûå êëàññû)
    template<typename U> friend class VertexIterator;
    template<typename U> friend class ConstVertexIterator;
    template<typename U> friend class EdgeIterator;
    template<typename U> friend class ConstEdgeIterator;
    template<typename U> friend class IncidentEdgeIterator;
    template<typename U> friend class AdjacentVertexIterator;

    // ===== ÎÏÅĞÀÒÎĞ ÂÛÂÎÄÀ =====
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Graph<U>& graph);
};

#include "VertexIterator.h"
#include "EdgeIterator.h"
#include "IncidentEdgeIterator.h"
#include "AdjacentVertexIterator.h"
#include "GraphImplementation.h"