# Social Network Analysis Tool
**README Documentation**

## Table of Contents
1. [Introduction](#introduction)
2. [Data Structures Used](#data-structures-used)
   - [Graph Representation](#graph-representation)
   - [Traversal Data Structures](#traversal-data-structures)
3. [Explanation of Functions](#explanation-of-functions)
   - [Graph Construction](#graph-construction)
   - [BFS Traversal](#bfs-traversal)
   - [Degree Centrality](#degree-centrality)
   - [Community Detection (Connected Components)](#community-detection-connected-components)
   - [Graph Export (DOT Format)](#graph-export-dot-format)
4. [Example Usage](#example-usage)
   - [Input Edges](#input-edges)
   - [Output (Simulated Terminal)](#output-simulated-terminal)
   - [Graph Export (DOT Format)](#graph-export-dot-format)
5. [Conclusion](#conclusion)

---

## Introduction
The Social Network Analysis Tool is a C++ implementation that models and analyzes complex networks. Using graph-based data structures and traversal algorithms, this tool provides insights into network structure, community formation, and influential nodes. It is designed for real-world applications such as analyzing social media networks.

---

## Data Structures Used

### Graph Representation
- **Adjacency List:**
  - `unordered_map<string, Node*>`: Maps each node ID to its `Node` object.
  - **Node Class:** Stores the node's ID and its list of neighbors (`vector<string>`).
  
This approach is memory-efficient and well-suited for sparse graphs.

### Traversal Data Structures
- **Queue:** Used for BFS traversal to explore nodes level by level.
- **Set:** Tracks visited nodes to prevent revisits during BFS and DFS.

---

## Explanation of Functions

### Graph Construction
- **`addNode(string id)`**: Adds a new node to the graph if it doesn't already exist.
- **`addEdge(string id1, string id2)`**: Adds an undirected edge between two nodes.

### BFS Traversal
- Explores all nodes reachable from a given starting node, layer by layer.
- Maintains a queue to process nodes and a set to track visited nodes.

### Degree Centrality
- Calculates the number of direct connections (edges) for each node.
- Uses the adjacency list to determine neighbor counts.

### Community Detection (Connected Components)
- Uses DFS to identify groups of connected nodes in the graph.
- Recursively visits all nodes in a connected component using a set to track visited nodes.

### Graph Export (DOT Format)
- Exports the graph in DOT format for visualization with GraphViz.
- Outputs edges in the syntax: `"Node1" -- "Node2";`.

---

## Example Usage

### Input Edges
The program is initialized with the following edges:

```cpp
graph.addEdge("Arjun", "Bhavana");
graph.addEdge("Bhavana", "Charu");
graph.addEdge("Charu", "Deepak");
graph.addEdge("Deepak", "Esha");
graph.addEdge("Farhan", "Gita");
graph.addEdge("Gita", "Harsh");
graph.addEdge("Harsh", "Isha");
graph.addEdge("Isha", "Jatin");
graph.addEdge("Kavita", "Lalit");
graph.addEdge("Lalit", "Manav");
graph.addEdge("Manav", "Nidhi");
graph.addEdge("Nidhi", "Omkar");
```

## Output (Simulated Terminal)

```cpp

$ ./social_network_analysis

BFS starting from Arjun:
Arjun Bhavana Charu Deepak Esha

Degree Centrality:
Arjun: 1
Bhavana: 2
Charu: 2
Deepak: 2
Esha: 1
Farhan: 1
Gita: 2
Harsh: 2
Isha: 2
Jatin: 1
Kavita: 1
Lalit: 2
Manav: 2
Nidhi: 2
Omkar: 1

Communities:
Community 1: Arjun Bhavana Charu Deepak Esha
Community 2: Farhan Gita Harsh Isha Jatin
Community 3: Kavita Lalit Manav Nidhi Omkar

Graph exported to graph.dot for visualization.
```
## Graph Export (DOT Format)

graph G {
    "Arjun" -- "Bhavana";
    "Bhavana" -- "Charu";
    "Charu" -- "Deepak";
    "Deepak" -- "Esha";
    "Farhan" -- "Gita";
    "Gita" -- "Harsh";
    ...
}

## Conclusion

This Social Network Analysis Tool showcases how graph data structures and algorithms can be used to analyze complex networks. Key features include BFS traversal, degree centrality calculation, and community detection, providing insights into network structure and dynamics. The ability to export graphs for visualization further enhances the tool's utility.
