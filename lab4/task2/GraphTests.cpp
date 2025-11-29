#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include "Graph.h"

class GraphTest : public ::testing::Test {
protected:
    void SetUp() override {
        graph = std::make_unique<Graph<int>>();

        v1 = graph->addVertex(1);
        v2 = graph->addVertex(2);
        v3 = graph->addVertex(3);
        v4 = graph->addVertex(4);

        e1 = graph->addEdge(v1, v2);
        e2 = graph->addEdge(v2, v3);
        e3 = graph->addEdge(v3, v4);
        e4 = graph->addEdge(v1, v4);
    }

    void TearDown() override {
        graph.reset();
    }

    std::unique_ptr<Graph<int>> graph;
    std::shared_ptr<Vertex<int>> v1, v2, v3, v4;
    std::shared_ptr<Edge<int>> e1, e2, e3, e4;
};

// ===== ТЕСТЫ ДЛЯ VERTEX =====
TEST(VertexTest, BasicOperations) {
    Vertex<int> v1(42);
    Vertex<int> v2(100);
    Vertex<int> v3(42);

    // Проверка данных
    EXPECT_EQ(42, v1.getData());
    EXPECT_EQ(100, v2.getData());

    // Проверка ID (должны быть уникальными)
    EXPECT_NE(v1.getId(), v2.getId());
    EXPECT_NE(v1.getId(), v3.getId());

    // Проверка операторов сравнения
    EXPECT_TRUE(v1 == v1);
    EXPECT_FALSE(v1 == v2);
    EXPECT_TRUE(v1 != v2);
    EXPECT_TRUE(v1 < v2);  // Сравнение по ID
}

TEST(VertexTest, CopyOperations) {
    Vertex<int> original(999);
    Vertex<int> copy1(original);  // Конструктор копирования
    Vertex<int> copy2 = original; // Оператор присваивания

    // Данные должны совпадать
    EXPECT_EQ(original.getData(), copy1.getData());
    EXPECT_EQ(original.getData(), copy2.getData());

    // Но ID должны быть разными
    EXPECT_NE(original.getId(), copy1.getId());
    EXPECT_NE(original.getId(), copy2.getId());
}

TEST(VertexTest, OutputOperator) {
    Vertex<int> v(123);
    std::ostringstream oss;
    oss << v;

    std::string output = oss.str();
    EXPECT_TRUE(output.find("Vertex(123") != std::string::npos);
    EXPECT_TRUE(output.find("id:") != std::string::npos);
}

// ===== ТЕСТЫ ДЛЯ EDGE =====
TEST(EdgeTest, BasicOperations) {
    auto v1 = std::make_shared<Vertex<int>>(1);
    auto v2 = std::make_shared<Vertex<int>>(2);
    auto v3 = std::make_shared<Vertex<int>>(3);

    Edge<int> e1(v1, v2);
    Edge<int> e2(v2, v3);
    Edge<int> e3(v1, v2); // Такие же вершины

    // Проверка доступа к вершинам
    EXPECT_EQ(v1, e1.getFrom());
    EXPECT_EQ(v2, e1.getTo());

    // Проверка операторов сравнения
    EXPECT_TRUE(e1 == e1);
    EXPECT_FALSE(e1 == e2);
    EXPECT_TRUE(e1 != e2);

    // Для неориентированного графа ребро симметрично
    Edge<int> e4(v2, v1);
    EXPECT_TRUE(e1 == e4); // v1-v2 должно равняться v2-v1
}

TEST(EdgeTest, CopyOperations) {
    auto v1 = std::make_shared<Vertex<int>>(10);
    auto v2 = std::make_shared<Vertex<int>>(20);

    Edge<int> original(v1, v2);
    Edge<int> copy1(original);  // Конструктор копирования
    Edge<int> copy2 = original; // Оператор присваивания

    EXPECT_EQ(original.getFrom(), copy1.getFrom());
    EXPECT_EQ(original.getTo(), copy1.getTo());
    EXPECT_EQ(original.getFrom(), copy2.getFrom());
    EXPECT_EQ(original.getTo(), copy2.getTo());
}

TEST(EdgeTest, OutputOperator) {
    auto v1 = std::make_shared<Vertex<int>>(100);
    auto v2 = std::make_shared<Vertex<int>>(200);
    Edge<int> e(v1, v2);

    std::ostringstream oss;
    oss << e;

    std::string output = oss.str();
    EXPECT_TRUE(output.find("Edge(") != std::string::npos);
    EXPECT_TRUE(output.find("Vertex(100") != std::string::npos);
    EXPECT_TRUE(output.find("Vertex(200") != std::string::npos);
}

// ===== БАЗОВЫЕ ТЕСТЫ КОНТЕЙНЕРА =====
TEST_F(GraphTest, DefaultConstructor) {
    Graph<int> emptyGraph;
    EXPECT_TRUE(emptyGraph.empty());
    EXPECT_EQ(0, emptyGraph.vertexCount());
    EXPECT_EQ(0, emptyGraph.edgeCount());
}

TEST_F(GraphTest, CopyConstructor) {
    Graph<int> copyGraph(*graph);
    EXPECT_EQ(graph->vertexCount(), copyGraph.vertexCount());
    EXPECT_EQ(graph->edgeCount(), copyGraph.edgeCount());
}

TEST_F(GraphTest, AssignmentOperator) {
    Graph<int> assignedGraph;
    assignedGraph = *graph;
    EXPECT_EQ(graph->vertexCount(), assignedGraph.vertexCount());
    EXPECT_EQ(graph->edgeCount(), assignedGraph.edgeCount());
}

TEST_F(GraphTest, EmptyAndClear) {
    EXPECT_FALSE(graph->empty());
    graph->clear();
    EXPECT_TRUE(graph->empty());
    EXPECT_EQ(0, graph->vertexCount());
    EXPECT_EQ(0, graph->edgeCount());
}

TEST_F(GraphTest, SizeMethod) {
    EXPECT_EQ(4, graph->size());
}

// ===== ТЕСТЫ ОПЕРАТОРОВ СРАВНЕНИЯ =====
TEST_F(GraphTest, EqualityOperator) {
    Graph<int> sameGraph;
    auto sv1 = sameGraph.addVertex(1);
    auto sv2 = sameGraph.addVertex(2);
    auto sv3 = sameGraph.addVertex(3);
    auto sv4 = sameGraph.addVertex(4);
    sameGraph.addEdge(sv1, sv2);
    sameGraph.addEdge(sv2, sv3);
    sameGraph.addEdge(sv3, sv4);
    sameGraph.addEdge(sv1, sv4);

    EXPECT_TRUE(*graph == sameGraph);
}

TEST_F(GraphTest, InequalityOperator) {
    Graph<int> differentGraph;
    differentGraph.addVertex(1);
    differentGraph.addVertex(2);
    EXPECT_TRUE(*graph != differentGraph);
}

TEST_F(GraphTest, ComparisonOperators) {
    Graph<int> smallerGraph;
    smallerGraph.addVertex(1);
    smallerGraph.addVertex(2);

    Graph<int> largerGraph;
    largerGraph.addVertex(1);
    largerGraph.addVertex(2);
    largerGraph.addVertex(3);
    largerGraph.addVertex(4);
    largerGraph.addVertex(5);

    EXPECT_TRUE(smallerGraph < *graph);
    EXPECT_TRUE(largerGraph > *graph);
    EXPECT_TRUE(smallerGraph <= *graph);
    EXPECT_TRUE(largerGraph >= *graph);
}

// ===== ТЕСТЫ РАБОТЫ С ВЕРШИНАМИ =====
TEST_F(GraphTest, AddVertex) {
    auto newVertex = graph->addVertex(5);
    EXPECT_EQ(5, graph->vertexCount());
    EXPECT_TRUE(graph->containsVertex(newVertex));
    EXPECT_EQ(5, newVertex->getData());
}

TEST_F(GraphTest, GetVertex) {
    auto vertex = graph->getVertex(0);
    EXPECT_EQ(v1, vertex);
    EXPECT_EQ(1, vertex->getData());
}

TEST_F(GraphTest, GetVertexOutOfRange) {
    EXPECT_THROW(graph->getVertex(10), std::out_of_range);
}

TEST_F(GraphTest, ContainsVertex) {
    EXPECT_TRUE(graph->containsVertex(v1));
    EXPECT_TRUE(graph->containsVertex(v2));
    auto nonExistent = std::make_shared<Vertex<int>>(999);
    EXPECT_FALSE(graph->containsVertex(nonExistent));
}

TEST_F(GraphTest, RemoveVertex) {
    EXPECT_TRUE(graph->removeVertex(v1));
    EXPECT_EQ(3, graph->vertexCount());
    EXPECT_FALSE(graph->containsVertex(v1));
    EXPECT_FALSE(graph->containsEdge(v1, v2));
}

TEST_F(GraphTest, RemoveNonExistentVertex) {
    auto nonExistent = std::make_shared<Vertex<int>>(999);
    EXPECT_FALSE(graph->removeVertex(nonExistent));
}

// ===== ТЕСТЫ РАБОТЫ С РЕБРАМИ =====
TEST_F(GraphTest, AddEdge) {
    auto newEdge = graph->addEdge(v2, v4);
    EXPECT_EQ(5, graph->edgeCount());
    EXPECT_TRUE(graph->containsEdge(v2, v4));
    EXPECT_TRUE(graph->containsEdge(v4, v2));
}

TEST_F(GraphTest, AddEdgeWithIndexes) {
    auto newEdge = graph->addEdge(1, 3);
    EXPECT_TRUE(graph->containsEdge(v2, v4));
}

TEST_F(GraphTest, AddEdgeInvalidVertices) {
    auto nonExistent = std::make_shared<Vertex<int>>(999);
    EXPECT_THROW(graph->addEdge(v1, nonExistent), std::invalid_argument);
}

TEST_F(GraphTest, AddEdgeSelfLoop) {
    EXPECT_THROW(graph->addEdge(v1, v1), std::invalid_argument);
}

TEST_F(GraphTest, ContainsEdge) {
    EXPECT_TRUE(graph->containsEdge(v1, v2));
    EXPECT_TRUE(graph->containsEdge(v2, v1));
    EXPECT_FALSE(graph->containsEdge(v1, v3));
}

TEST_F(GraphTest, RemoveEdge) {
    EXPECT_TRUE(graph->removeEdge(e1));
    EXPECT_EQ(3, graph->edgeCount());
    EXPECT_FALSE(graph->containsEdge(v1, v2));
}

TEST_F(GraphTest, RemoveNonExistentEdge) {
    auto nonExistentEdge = std::make_shared<Edge<int>>(
        std::make_shared<Vertex<int>>(999),
        std::make_shared<Vertex<int>>(1000)
    );
    EXPECT_FALSE(graph->removeEdge(nonExistentEdge));
}

// ===== ТЕСТЫ ВЫЧИСЛЕНИЯ СТЕПЕНЕЙ =====
TEST_F(GraphTest, VertexDegree) {
    EXPECT_EQ(2, graph->vertexDegree(v1));
    EXPECT_EQ(2, graph->vertexDegree(v2));
    EXPECT_EQ(2, graph->vertexDegree(v3));
    EXPECT_EQ(2, graph->vertexDegree(v4));
}

TEST_F(GraphTest, VertexDegreeNonExistent) {
    auto nonExistent = std::make_shared<Vertex<int>>(999);
    EXPECT_EQ(0, graph->vertexDegree(nonExistent));
}

TEST_F(GraphTest, EdgeDegree) {
    EXPECT_EQ(2, graph->edgeDegree(e1));
}

// ===== ТЕСТЫ ИТЕРАТОРОВ ВЕРШИН =====
TEST_F(GraphTest, VertexIterator) {
    size_t count = 0;
    for (auto it = graph->verticesBegin(); it != graph->verticesEnd(); ++it) {
        ++count;
        EXPECT_NE(nullptr, *it);
    }
    EXPECT_EQ(4, count);
}

TEST_F(GraphTest, ConstVertexIterator) {
    size_t count = 0;
    for (auto it = graph->verticesCBegin(); it != graph->verticesCEnd(); ++it) {
        ++count;
        EXPECT_NE(nullptr, *it);
    }
    EXPECT_EQ(4, count);
}

TEST_F(GraphTest, ReverseVertexIterator) {
    std::vector<int> values;
    for (auto it = graph->verticesRBegin(); it != graph->verticesREnd(); ++it) {
        values.push_back((*it)->getData());
    }
    EXPECT_EQ(4, values.size());
}

TEST_F(GraphTest, RemoveVertexByIterator) {
    auto it = graph->verticesBegin();
    EXPECT_TRUE(graph->removeVertex(it));
    EXPECT_EQ(3, graph->vertexCount());
}

// ===== ТЕСТЫ ИТЕРАТОРОВ РЕБЕР =====
TEST_F(GraphTest, EdgeIterator) {
    size_t count = 0;
    for (auto it = graph->edgesBegin(); it != graph->edgesEnd(); ++it) {
        ++count;
        EXPECT_NE(nullptr, *it);
    }
    EXPECT_EQ(4, count);
}

TEST_F(GraphTest, ConstEdgeIterator) {
    size_t count = 0;
    for (auto it = graph->edgesCBegin(); it != graph->edgesCEnd(); ++it) {
        ++count;
        EXPECT_NE(nullptr, *it);
    }
    EXPECT_EQ(4, count);
}

TEST_F(GraphTest, RemoveEdgeByIterator) {
    auto it = graph->edgesBegin();
    EXPECT_TRUE(graph->removeEdge(it));
    EXPECT_EQ(3, graph->edgeCount());
}

// ===== ТЕСТЫ ИНЦИДЕНТНЫХ РЕБЕР =====
TEST_F(GraphTest, IncidentEdgeIterator) {
    size_t count = 0;
    for (auto it = graph->incidentEdgesBegin(v1); it != graph->incidentEdgesEnd(v1); ++it) {
        ++count;
        auto edge = *it;
        EXPECT_TRUE(edge->getFrom() == v1 || edge->getTo() == v1);
    }
    EXPECT_EQ(2, count);
}

// ===== ТЕСТЫ СМЕЖНЫХ ВЕРШИН =====
TEST_F(GraphTest, AdjacentVertexIterator) {
    std::vector<int> adjacentValues;
    for (auto it = graph->adjacentBegin(v1); it != graph->adjacentEnd(v1); ++it) {
        adjacentValues.push_back((*it)->getData());
    }
    EXPECT_EQ(2, adjacentValues.size());
    EXPECT_TRUE(std::find(adjacentValues.begin(), adjacentValues.end(), 2) != adjacentValues.end());
    EXPECT_TRUE(std::find(adjacentValues.begin(), adjacentValues.end(), 4) != adjacentValues.end());
}

// ===== ТЕСТЫ ОПЕРАТОРА ВЫВОДА =====
TEST_F(GraphTest, OutputOperator) {
    std::ostringstream oss;
    oss << *graph;
    std::string output = oss.str();
    EXPECT_TRUE(output.find("Graph with 4 vertices and 4 edges") != std::string::npos);
}

// ===== ТЕСТЫ ИСКЛЮЧЕНИЙ =====
TEST_F(GraphTest, Exceptions) {
    EXPECT_THROW(graph->getVertex(10), std::out_of_range);
    auto nonExistent = std::make_shared<Vertex<int>>(999);
    EXPECT_THROW(graph->addEdge(v1, nonExistent), std::invalid_argument);
    EXPECT_THROW(graph->addEdge(v1, v1), std::invalid_argument);
}

// ===== ТЕСТЫ С ДРУГИМИ ТИПАМИ ДАННЫХ =====
TEST(GraphStringTest, StringVertices) {
    Graph<std::string> stringGraph;
    auto v1 = stringGraph.addVertex("A");
    auto v2 = stringGraph.addVertex("B");
    stringGraph.addEdge(v1, v2);

    EXPECT_EQ(2, stringGraph.vertexCount());
    EXPECT_EQ(1, stringGraph.edgeCount());
    EXPECT_TRUE(stringGraph.containsEdge(v1, v2));
}

TEST(GraphUserTest, CustomClassVertices) {
    struct Point {
        int x, y;
        Point(int x, int y) : x(x), y(y) {}
        bool operator==(const Point& other) const { return x == other.x && y == other.y; }
        bool operator<(const Point& other) const { return x < other.x || (x == other.x && y < other.y); }
    };

    Graph<Point> pointGraph;
    auto v1 = pointGraph.addVertex(Point(1, 2));
    auto v2 = pointGraph.addVertex(Point(3, 4));
    pointGraph.addEdge(v1, v2);

    EXPECT_EQ(2, pointGraph.vertexCount());
    EXPECT_EQ(1, pointGraph.edgeCount());
}

// ===== ТЕСТЫ ПРОИЗВОДИТЕЛЬНОСТИ =====
TEST(GraphPerformanceTest, LargeGraph) {
    Graph<int> largeGraph;
    std::vector<std::shared_ptr<Vertex<int>>> vertices;

    for (int i = 0; i < 100; ++i) {
        vertices.push_back(largeGraph.addVertex(i));
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 1; j <= 5 && i + j < 100; ++j) {
            largeGraph.addEdge(vertices[i], vertices[i + j]);
        }
    }

    EXPECT_EQ(100, largeGraph.vertexCount());
    EXPECT_GT(largeGraph.edgeCount(), 0);

    size_t vertexCount = 0;
    for (auto it = largeGraph.verticesBegin(); it != largeGraph.verticesEnd(); ++it) {
        ++vertexCount;
    }
    EXPECT_EQ(100, vertexCount);
}

// ===== ГЛАВНАЯ ФУНКЦИЯ =====
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    std::cout << "=== Running Graph Tests ===" << std::endl;
    std::cout << "Tests include:" << std::endl;
    std::cout << "- Vertex operations" << std::endl;
    std::cout << "- Edge operations" << std::endl;
    std::cout << "- Graph container functionality" << std::endl;
    std::cout << "- Iterators (vertex, edge, incident, adjacent)" << std::endl;
    std::cout << "- Comparison operators" << std::endl;
    std::cout << "- Exception handling" << std::endl;
    std::cout << "===========================" << std::endl;

    return RUN_ALL_TESTS();
}