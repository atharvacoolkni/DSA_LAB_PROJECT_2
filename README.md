# Social Network Analysis Tool

## Project Overview

This project is a **Social Network Analysis Tool** built in **C++** that utilizes **graph data structures** and **hash tables** to model and analyze social networks. The tool provides functionalities such as:

1. **Graph Construction**: Represents users (nodes) and their relationships (edges).
2. **Social Network Analysis**:
   - **Centrality Calculation**: Identifies key individuals based on their connections.
   - **Community Detection**: Finds groups of users who are closely connected.
   - **Graph Traversals**: Explores the network using BFS (Breadth-First Search) and DFS (Depth-First Search).
3. **Graph Export**: Outputs the graph to a `.dot` file for visualization using tools like GraphViz.

---

## Data Structures Used

- **Graph Representation**: 
  - Nodes are stored as objects containing their ID and a list of neighbors.
  - The graph is represented as an adjacency list using a hash table (`std::unordered_map`).

- **Hash Table** (`std::unordered_map`): 
  - Efficiently maps node IDs to their respective node objects.

- **Queue** (`std::queue`): 
  - Used in **BFS** to process nodes level by level.

- **Set** (`std::set`): 
  - Tracks visited nodes during BFS, DFS, and community detection.

- **File Stream** (`std::ofstream`): 
  - Writes the graph structure to a `.dot` file.

---

## Features

### 1. **Graph Construction**
- **`addNode`**: Adds a node (user) to the graph if it does not already exist.
- **`addEdge`**: Adds an undirected edge between two nodes, creating nodes automatically if they don't exist.

### 2. **Graph Traversals**
- **Breadth-First Search (BFS)**:
  - Explores the graph level by level starting from a given node.
  - Identifies all users directly or indirectly connected to a specific user.
- **Depth-First Search (DFS)**:
  - Explores the graph deeply from one node before backtracking.
  - Used to find all users in a connected component.

### 3. **Community Detection**
- **`findConnectedComponents`**:
  - Identifies connected components (communities) in the graph.
  - Each community is a group of closely connected users.

### 4. **Centrality Calculation**
- **`calculateDegreeCentrality`**:
  - Computes the degree centrality of each node (number of direct connections).
  - Helps identify influencers in the network.

### 5. **Graph Export**
- **`exportToGraphViz`**:
  - Exports the graph in **DOT format** for visualization using GraphViz.
  - Creates a file named `graph.dot`.

---

## How This is a Social Network Analysis Tool

1. **Centrality**:
   - Identifies "influencers" in the network by calculating the degree centrality.
   - Users with high centrality scores have more direct connections and influence.

2. **Community Detection**:
   - Discovers groups (communities) in the network using DFS to find connected components.

3. **Graph Traversals**:
   - BFS and DFS provide insights into how users are connected and how information can propagate.

4. **Visualization**:
   - The exported graph in DOT format helps visualize relationships and identify clusters easily.

---

## How to Use the Tool

### 1. **Compile the Program**
Use the following command to compile the program:
```bash
g++ -o social_network_analysis social_network_analysis.cpp

./social_network_analysis

```
## View Outputs

- The program will display the following results in the console:
  1. **BFS Traversal**: Shows the order of nodes visited starting from a specific node.
  2. **Degree Centrality**: Lists the centrality scores of each node (number of direct connections).
  3. **Communities**: Identifies connected components (groups of users) in the graph.

- The graph structure is exported to a file named `graph.dot`.

---

## Visualize the Graph

To visualize the graph:

1. **Using a GraphViz Viewer**:
   - Open the `graph.dot` file in any GraphViz-compatible viewer.

2. **Using an Online Tool**:
   - Copy the contents of the `graph.dot` file.
   - Paste it into an [online GraphViz editor](https://graphviz.gitlab.io/_pages/Examples.html) or tools like [GraphViz Online](https://dreampuf.github.io/GraphvizOnline/).

3. **Using the Command Line**:
   - Convert the `graph.dot` file to an image using GraphViz:
     ```bash
     dot -Tpng graph.dot -o graph.png
     ```
   - Open `graph.png` to view the graph structure.

This visualization will provide an intuitive representation of the graph structure, relationships, and communities.

# Sample Output

## BFS Traversal
**Starting from node Alice:**
Alice Bob Carol David Eve Frank Grace Heidi Ivan Judy Kevin Lily Mark Nancy Olivia Peter Quinn Rose Sam Tina


## Degree Centrality
**Displays the number of direct connections (degree) for each node:**
Alice: 4 Bob: 3 Carol: 3 David: 2 Eve: 3 Frank: 2 Grace: 3 Heidi: 4 Ivan: 3 Judy: 3 Kevin: 3 Lily: 2 Mark: 3 Nancy: 2 Olivia: 3 Peter: 3 Quinn: 2 Rose: 2 Sam: 2 Tina: 1

## Communities
**Connected components (groups of closely related nodes) detected using DFS:**

Community 1: Alice Bob Carol David Eve 
Community 2: Grace Heidi Ivan Judy Kevin
Community 3: Lily Mark Nancy Olivia Peter Community 4: Quinn Rose Sam Tina


## Graph Export (graph.dot)
**The graph is exported in DOT format for visualization. Example snippet:**
```dot
graph G {
    "Alice" -- "Bob";
    "Alice" -- "Carol";
    "Bob" -- "David";
    "Carol" -- "Eve";
    "Eve" -- "Frank";
    ...
}
```
Visualized Graph

To view the network visually, open the graph.dot file in a GraphViz-compatible tool. Below is an example of how the graph may look:

Alice -- Bob -- David
        |       |
      Carol     Eve -- Frank
        ...


## Conclusion

This Social Network Analysis Tool effectively demonstrates how data structures like graphs and hash tables can be utilized to model and analyze complex networks. By implementing fundamental graph traversal algorithms such as BFS and DFS, the tool provides insights into the structure and dynamics of a social network. 

### Key Features:
1. **Centrality Calculation**: 
   - The degree centrality measure identifies influential nodes (users) in the network by determining their number of direct connections.

2. **Community Detection**: 
   - Using DFS, the tool identifies connected components, helping to uncover clusters or communities within the network.

3. **Graph Export**: 
   - The tool generates a `graph.dot` file, allowing users to visualize the network using GraphViz or similar tools.

### Applications:
- **Social Media Analysis**: Identifying influencers or key users within a social network.
- **Community Detection**: Detecting groups or clusters based on interactions.
- **Visualization**: Visualizing relationships in the network helps understand the connections and clusters at a glance.

This project demonstrates how foundational concepts in data structures and algorithms can be applied to solve real-world problems in social network analysis. By extending this tool with more complex metrics like betweenness centrality, clustering coefficients, or weighted graphs, it can be adapted for advanced social network studies. 
