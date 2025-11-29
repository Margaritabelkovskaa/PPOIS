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
        : graph(g), current(it) {}

    reference operator*() { return *current; }
    pointer operator->() { return &(*current); }

    VertexIterator& operator++() { ++current; return *this; }
    VertexIterator operator++(int) { VertexIterator temp = *this; ++current; return temp; }
    
    VertexIterator& operator--() { --current; return *this; }
    VertexIterator operator--(int) { VertexIterator temp = *this; --current; return temp; }

    bool operator==(const VertexIterator& other) const { return current == other.current; }
    bool operator!=(const VertexIterator& other) const { return current != other.current; }
};
