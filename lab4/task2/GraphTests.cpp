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

// ===== ÒÅÑÒÛ ÎÏÅÐÀÒÎÐÎÂ ÑÐÀÂÍÅÍÈß =====
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

// ===== ÒÅÑÒÛ ÐÀÁÎÒÛ Ñ ÂÅÐØÈÍÀÌÈ =====
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

// ===== ÒÅÑÒÛ ÐÀÁÎÒÛ Ñ ÐÅÁÐÀÌÈ =====
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

TEST_F(GraphTest, IncidentEdgeIterator) {
    size_t count = 0;
    for (auto it = graph->incidentEdgesBegin(v1); it != graph->incidentEdgesEnd(v1); ++it) {
        ++count;
        auto edge = *it;
        EXPECT_TRUE(edge->getFrom() == v1 || edge->getTo() == v1);
    }
    EXPECT_EQ(2, count);
}

TEST_F(GraphTest, AdjacentVertexIterator) {
    std::vector<int> adjacentValues;
    for (auto it = graph->adjacentBegin(v1); it != graph->adjacentEnd(v1); ++it) {
        adjacentValues.push_back((*it)->getData());
    }
    EXPECT_EQ(2, adjacentValues.size());
    EXPECT_TRUE(std::find(adjacentValues.begin(), adjacentValues.end(), 2) != adjacentValues.end());
    EXPECT_TRUE(std::find(adjacentValues.begin(), adjacentValues.end(), 4) != adjacentValues.end());
}

TEST_F(GraphTest, OutputOperator) {
    std::ostringstream oss;
    oss << *graph;
    std::string output = oss.str();
    EXPECT_TRUE(output.find("Graph with 4 vertices and 4 edges") != std::string::npos);
}

TEST_F(GraphTest, Exceptions) {
    EXPECT_THROW(graph->getVertex(10), std::out_of_range);
    auto nonExistent = std::make_shared<Vertex<int>>(999);
    EXPECT_THROW(graph->addEdge(v1, nonExistent), std::invalid_argument);
    EXPECT_THROW(graph->addEdge(v1, v1), std::invalid_argument);
}


TEST(GraphTest, StringVertices) {
    Graph<std::string> stringGraph;
    auto v1 = stringGraph.addVertex("A");
    auto v2 = stringGraph.addVertex("B");
    stringGraph.addEdge(v1, v2);

    EXPECT_EQ(2, stringGraph.vertexCount());
    EXPECT_EQ(1, stringGraph.edgeCount());
    EXPECT_TRUE(stringGraph.containsEdge(v1, v2));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
