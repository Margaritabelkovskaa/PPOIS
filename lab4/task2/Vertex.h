#pragma once
#include <iostream>
#include <memory>

template<typename T>
class Vertex {
private:
    T data;
    size_t id;
    static size_t next_id;

public:
    Vertex(const T& value) : data(value), id(next_id++) {}

    // Копирующий конструктор
    Vertex(const Vertex& other) : data(other.data), id(next_id++) {}

    // Присваивание
    Vertex& operator=(const Vertex& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    // Доступ к данным
    const T& getData() const { return data; }
    T& getData() { return data; }
    size_t getId() const { return id; }

    // Операторы сравнения
    bool operator==(const Vertex& other) const { return id == other.id; }
    bool operator!=(const Vertex& other) const { return !(*this == other); }
    bool operator<(const Vertex& other) const { return id < other.id; }
    bool operator>(const Vertex& other) const { return id > other.id; }
    bool operator<=(const Vertex& other) const { return id <= other.id; }
    bool operator>=(const Vertex& other) const { return id >= other.id; }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex) {
        os << "Vertex(" << vertex.data << ", id:" << vertex.id << ")";
        return os;
    }
};

template<typename T>
size_t Vertex<T>::next_id = 0;