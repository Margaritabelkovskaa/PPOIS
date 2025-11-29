#pragma once
#include <iterator>
#include <memory>
#include <vector>

template<typename T>
class Vertex;

template<typename T>
class Graph;

// 🔹 Константный итератор вершин (только для чтения)
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
        : graph(g), current(it) {}

    reference operator*() const { return *current; }
    pointer operator->() const { return &(*current); }

    ConstVertexIterator& operator++() { ++current; return *this; }
    ConstVertexIterator operator++(int) { ConstVertexIterator temp = *this; ++current; return temp; }

    ConstVertexIterator& operator--() { --current; return *this; }
    ConstVertexIterator operator--(int) { ConstVertexIterator temp = *this; --current; return temp; }

    bool operator==(const ConstVertexIterator& other) const { return current == other.current; }
    bool operator!=(const ConstVertexIterator& other) const { return current != other.current; }
};
