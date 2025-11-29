#pragma once
#include <iterator>
#include <memory>
#include <vector>

template<typename T>
class Vertex;

template<typename T>
class Graph;

template<typename T>
class VertexIterator {
private:
    using VertexPtr = std::shared_ptr<Vertex<T>>;
    typename std::vector<VertexPtr>::iterator current;
    Graph<T>* graph;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = VertexPtr;
    using difference_type = std::ptrdiff_t;
    using pointer = VertexPtr*;
    using reference = VertexPtr&;

    VertexIterator(Graph<T>* g, typename std::vector<VertexPtr>::iterator it)
        : graph(g), current(it) {
    }

    reference operator*() { return *current; }
    pointer operator->() { return &(*current); }

    VertexIterator& operator++() { ++current; return *this; }
    VertexIterator operator++(int) { VertexIterator temp = *this; ++current; return temp; }

    VertexIterator& operator--() { --current; return *this; }
    VertexIterator operator--(int) { VertexIterator temp = *this; --current; return temp; }

    bool operator==(const VertexIterator& other) const { return current == other.current; }
    bool operator!=(const VertexIterator& other) const { return current != other.current; }

    size_t getIndex() const {
        return std::distance(graph->vertices.begin(),
            typename std::vector<VertexPtr>::iterator(current));
    }
};

// Константные версии
template<typename T>
class ConstVertexIterator {
private:
    using VertexPtr = std::shared_ptr<Vertex<T>>;
    typename std::vector<VertexPtr>::const_iterator current;
    const Graph<T>* graph;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = VertexPtr;
    using difference_type = std::ptrdiff_t;
    using pointer = const VertexPtr*;
    using reference = const VertexPtr&;

    ConstVertexIterator(const Graph<T>* g, typename std::vector<VertexPtr>::const_iterator it)
        : graph(g), current(it) {
    }

    reference operator*() const { return *current; }
    pointer operator->() const { return &(*current); }

    ConstVertexIterator& operator++() { ++current; return *this; }
    ConstVertexIterator operator++(int) { ConstVertexIterator temp = *this; ++current; return temp; }

    ConstVertexIterator& operator--() { --current; return *this; }
    ConstVertexIterator operator--(int) { ConstVertexIterator temp = *this; --current; return temp; }

    bool operator==(const ConstVertexIterator& other) const { return current == other.current; }
    bool operator!=(const ConstVertexIterator& other) const { return current != other.current; }
};

// Reverse итераторы
template<typename T>
using ReverseVertexIterator = std::reverse_iterator<VertexIterator<T>>;

template<typename T>
using ConstReverseVertexIterator = std::reverse_iterator<ConstVertexIterator<T>>;