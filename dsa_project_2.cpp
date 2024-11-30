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
    std::unordered_map<std::string, Node*> nodes;

public:
    void addNode(std::string id) {
        if (nodes.find(id) == nodes.end()) {
            nodes[id] = new Node(id);
        }
    }

    void addEdge(std::string id1, std::string id2) {
        addNode(id1);
        addNode(id2);
        nodes[id1]->neighbors.push_back(id2);
        nodes[id2]->neighbors.push_back(id1);
    }

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

    void DFSUtil(std::string current_id, std::set<std::string>& visited, std::vector<std::string>& component) {
        visited.insert(current_id);
        component.push_back(current_id);

        for (auto neighbor_id : nodes[current_id]->neighbors) {
            if (visited.find(neighbor_id) == visited.end()) {
                DFSUtil(neighbor_id, visited, component);
            }
        }
    }

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

    std::unordered_map<std::string, int> calculateDegreeCentrality() {
        std::unordered_map<std::string, int> centrality;

        for (auto const& pair : nodes) {
            std::string node_id = pair.first;
            centrality[node_id] = nodes[node_id]->neighbors.size();
        }

        return centrality;
    }

    void exportToGraphViz(const std::string& filename) {
        std::ofstream file;
        file.open(filename);
        file << "graph G {\n";
        for (auto const& pair : nodes) {
            std::string node_id = pair.first;
            for (auto neighbor_id : nodes[node_id]->neighbors) {
                if (node_id < neighbor_id) {
                    file << "    \"" << node_id << "\" -- \"" << neighbor_id << "\";\n";
                }
            }
        }
        file << "}\n";
        file.close();
        std::cout << "Graph exported to " << filename << " for visualization.\n";
    }

    ~Graph() {
        for (auto const& pair : nodes) {
            delete pair.second;
        }
    }
};

int main() {
    Graph graph;

    // Adding 50 hardcoded edges (you can modify these as needed)
    graph.addEdge("Alice", "Bob");
    graph.addEdge("Alice", "Carol");
    graph.addEdge("Bob", "David");
    graph.addEdge("Carol", "Eve");
    graph.addEdge("Eve", "Frank");
    graph.addEdge("Frank", "Grace");
    graph.addEdge("Grace", "Heidi");
    graph.addEdge("Heidi", "Ivan");
    graph.addEdge("Ivan", "Judy");
    graph.addEdge("Alice", "Kate");
    graph.addEdge("Kate", "Leo");
    graph.addEdge("Leo", "Mike");
    graph.addEdge("Mike", "Nina");
    graph.addEdge("Nina", "Oscar");
    graph.addEdge("Oscar", "Paul");
    graph.addEdge("Paul", "Quinn");
    graph.addEdge("Quinn", "Rose");
    graph.addEdge("Rose", "Sam");
    graph.addEdge("Sam", "Tom");
    graph.addEdge("Tom", "Uma");
    graph.addEdge("Uma", "Victor");
    graph.addEdge("Victor", "Wendy");
    graph.addEdge("Wendy", "Xander");
    graph.addEdge("Xander", "Yara");
    graph.addEdge("Yara", "Zane");
    graph.addEdge("Bob", "Frank");
    graph.addEdge("Carol", "Heidi");
    graph.addEdge("David", "Judy");
    graph.addEdge("Eve", "Kate");
    graph.addEdge("Frank", "Mike");
    graph.addEdge("Grace", "Nina");
    graph.addEdge("Heidi", "Oscar");
    graph.addEdge("Ivan", "Paul");
    graph.addEdge("Judy", "Quinn");
    graph.addEdge("Kate", "Rose");
    graph.addEdge("Leo", "Sam");
    graph.addEdge("Mike", "Tom");
    graph.addEdge("Nina", "Uma");
    graph.addEdge("Oscar", "Victor");
    graph.addEdge("Paul", "Wendy");
    graph.addEdge("Quinn", "Xander");
    graph.addEdge("Rose", "Yara");
    graph.addEdge("Sam", "Zane");
    graph.addEdge("Tom", "Alice");
    graph.addEdge("Uma", "Bob");
    graph.addEdge("Victor", "Carol");
    graph.addEdge("Wendy", "David");

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


