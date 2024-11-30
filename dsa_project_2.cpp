#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <fstream>

class Node {
public:
    std::string id;
    std::vector<std::string> neighbors;
    Node(std::string id) : id(id) {}
};

class Graph {
private:
    // Hash table mapping node IDs to Node objects
    std::unordered_map<std::string, Node*> nodes;

public:
    // Add a node to the graph
    void addNode(std::string id) {
        if (nodes.find(id) == nodes.end()) {
            nodes[id] = new Node(id);
        }
    }

    // Add an undirected edge between two nodes
    void addEdge(std::string id1, std::string id2) {
        addNode(id1);
        addNode(id2);
        nodes[id1]->neighbors.push_back(id2);
        nodes[id2]->neighbors.push_back(id1);
    }

    // Perform Breadth-First Search starting from a given node
    std::vector<std::string> BFS(std::string start_id) {
        std::vector<std::string> visited_order;
        std::set<std::string> visited;
        std::queue<std::string> q;

        q.push(start_id);
        visited.insert(start_id);

        while (!q.empty()) {
            std::string current = q.front();
            q.pop();
            visited_order.push_back(current);

            for (auto neighbor_id : nodes[current]->neighbors) {
                if (visited.find(neighbor_id) == visited.end()) {
                    q.push(neighbor_id);
                    visited.insert(neighbor_id);
                }
            }
        }

        return visited_order;
    }

    // Perform Depth-First Search starting from a given node
    void DFSUtil(std::string current_id, std::set<std::string>& visited, std::vector<std::string>& component) {
        visited.insert(current_id);
        component.push_back(current_id);

        for (auto neighbor_id : nodes[current_id]->neighbors) {
            if (visited.find(neighbor_id) == visited.end()) {
                DFSUtil(neighbor_id, visited, component);
            }
        }
    }

    // Find connected components (communities) in the graph
    std::vector<std::vector<std::string>> findConnectedComponents() {
        std::set<std::string> visited;
        std::vector<std::vector<std::string>> components;

        for (auto const& pair : nodes) {
            std::string node_id = pair.first;
            if (visited.find(node_id) == visited.end()) {
                std::vector<std::string> component;
                DFSUtil(node_id, visited, component);
                components.push_back(component);
            }
        }

        return components;
    }

    // Calculate degree centrality for all nodes
    std::unordered_map<std::string, int> calculateDegreeCentrality() {
        std::unordered_map<std::string, int> centrality;

        for (auto const& pair : nodes) {
            std::string node_id = pair.first;
            centrality[node_id] = nodes[node_id]->neighbors.size();
        }

        return centrality;
    }

    // Export graph to a file compatible with GraphViz
    void exportToGraphViz(const std::string& filename) {
        std::ofstream file;
        file.open(filename);
        file << "graph G {\n";
        for (auto const& pair : nodes) {
            std::string node_id = pair.first;
            for (auto neighbor_id : nodes[node_id]->neighbors) {
                if (node_id < neighbor_id) { // To avoid duplicate edges
                    file << "    \"" << node_id << "\" -- \"" << neighbor_id << "\";\n";
                }
            }
        }
        file << "}\n";
        file.close();
        std::cout << "Graph exported to " << filename << " for visualization.\n";
    }

    // Destructor to clean up dynamically allocated nodes
    ~Graph() {
        for (auto const& pair : nodes) {
            delete pair.second;
        }
    }
};

int main() {
    Graph graph;

    // Sample data with 25 edges
    graph.addEdge("Alice", "Bob");
    graph.addEdge("Alice", "Carol");
    graph.addEdge("Bob", "David");
    graph.addEdge("Carol", "David");
    graph.addEdge("Alice", "Eve");
    graph.addEdge("Eve", "Frank");
    graph.addEdge("Frank", "Grace");
    graph.addEdge("Grace", "Heidi");
    graph.addEdge("Heidi", "Ivan");
    graph.addEdge("Ivan", "Judy");
    graph.addEdge("Eve", "Judy");
    graph.addEdge("Grace", "Ivan");
    graph.addEdge("Frank", "Heidi");
    graph.addEdge("Heidi", "Alice");
    graph.addEdge("Alice", "Grace");
    graph.addEdge("Bob", "Eve");
    graph.addEdge("Carol", "Grace");
    graph.addEdge("David", "yashas");
    graph.addEdge("rahul", "Judy");
    graph.addEdge("Grace", "David");
    graph.addEdge("Ivan", "rahul");
    graph.addEdge("sazid", "Frank");
    graph.addEdge("sazid", "yashas");
    graph.addEdge("rahul", "sazid");

    // Perform BFS starting from 'Alice'
    std::cout << "BFS starting from Alice:\n";
    std::vector<std::string> bfs_result = graph.BFS("Alice");
    for (auto id : bfs_result) {
        std::cout << id << " ";
    }
    std::cout << "\n\n";

    // Calculate Degree Centrality
    std::cout << "Degree Centrality:\n";
    std::unordered_map<std::string, int> centrality = graph.calculateDegreeCentrality();
    for (auto const& pair : centrality) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
    std::cout << "\n";

    // Find Connected Components (Communities)
    std::cout << "Communities:\n";
    std::vector<std::vector<std::string>> communities = graph.findConnectedComponents();
    int community_num = 1;
    for (auto const& component : communities) {
        std::cout << "Community " << community_num++ << ": ";
        for (auto id : component) {
            std::cout << id << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // Export graph to GraphViz format for visualization
    graph.exportToGraphViz("graph.dot");

    return 0;
}

