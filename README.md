# Smart Route Planner

A graph-based route planning application developed in **C++** that computes the shortest path between locations in a weighted graph using **Dijkstra's Algorithm**.

## Overview

Smart Route Planner is a console-based application that models locations as graph vertices and roads as weighted edges. Given a source and destination, the application determines the shortest path between them using Dijkstra's Algorithm.

The project demonstrates the practical implementation of graph data structures, greedy algorithms, and efficient pathfinding techniques using the C++ Standard Template Library (STL).

---

## Features

- Computes the shortest path between two locations.
- Implements Dijkstra's Algorithm using a Priority Queue.
- Uses an adjacency list for efficient graph representation.
- Interactive console-based interface.
- Modular and optimized C++ implementation.

---

## Technologies Used

- C++
- Standard Template Library (STL)
- Graph Data Structures
- Priority Queue (Min Heap)

---

## Algorithm

The application uses **Dijkstra's Algorithm** to determine the shortest distance from a source vertex to all reachable vertices.

### Time Complexity

| Operation | Complexity |
|-----------|------------|
| Dijkstra's Algorithm | **O((V + E) log V)** |

Where:

- **V** = Number of vertices
- **E** = Number of edges

---

## Project Structure

```
smart-route-planner/
│
├── src/
│   ├── main.cpp
│   ├── graph.cpp
│   └── graph.h
│
├── screenshots/
├── sample_input.txt
├── sample_output.txt
└── README.md
```

---

## Getting Started

### Clone the repository

```bash
git clone https://github.com/Srinivas-Mutta/smart-route-planner.git
```

### Navigate to the project directory

```bash
cd smart-route-planner
```

### Compile

```bash
g++ main.cpp graph.cpp -o planner
```

### Run

```bash
./planner
```

---

## Sample Input

```
Enter Source: A
Enter Destination: F
```

## Sample Output

```
Shortest Distance: 14

Shortest Path:
A -> C -> D -> F
```

---

## Future Enhancements

- Interactive graphical interface
- Support for A* Search Algorithm
- Bellman-Ford Algorithm implementation
- Dynamic graph updates
- Import graph data from external files

---

## Learning Outcomes

Through this project, I gained hands-on experience with:

- Graph Data Structures
- Dijkstra's Algorithm
- Greedy Algorithms
- Priority Queues
- Adjacency List Representation
- Modular C++ Programming
- Time and Space Complexity Analysis

---

## Author

**Srinivas Mutta**

B.Tech in Electronics and Communication Engineering

Indian Institute of Technology (ISM) Dhanbad
