#pragma once
#include "Vertex.h"
#include <iostream>
#include <memory>

template<typename T>
class Edge {
private:
    std::shared_ptr<Vertex<T>> from;
    std::shared_ptr<Vertex<T>> to;

public:
    Edge(std::shared_ptr<Vertex<T>> f, std::shared_ptr<Vertex<T>> t)
        : from(f), to(t) {
    }

    // Конструктор копирования
    Edge(const Edge& other) : from(other.from), to(other.to) {}

    // Присваивание
    Edge& operator=(const Edge& other) {
        if (this != &other) {
            from = other.from;
            to = other.to;
        }
        return *this;
    }

    // Доступ к вершинам
    std::shared_ptr<Vertex<T>> getFrom() const { return from; }
    std::shared_ptr<Vertex<T>> getTo() const { return to; }

    // Операторы сравнения
    bool operator==(const Edge& other) const {
        return (from == other.from && to == other.to) ||
            (from == other.to && to == other.from); // Для неориентированного графа
    }
    bool operator!=(const Edge& other) const { return !(*this == other); }
    bool operator<(const Edge& other) const {
        if (from != other.from) return from < other.from;
        return to < other.to;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Edge& edge) {
        os << "Edge(" << *edge.from << " - " << *edge.to << ")";
        return os;
    }
};