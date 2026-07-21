# Smart Route Planner

A console-based route planning application developed in **C++** that computes the shortest path between locations in a weighted graph using **Dijkstra's Algorithm**.

## Overview

Smart Route Planner models locations as vertices and roads as weighted edges in an undirected graph. The application allows users to select a source and destination and calculates both the minimum travel distance and the corresponding optimal route.

The graph is represented using an **adjacency list**, while Dijkstra's Algorithm is implemented using a **priority queue (min-heap)** for efficient shortest-path computation.

---

## Features

- Represents locations and roads using a weighted graph
- Uses adjacency-list graph representation
- Computes shortest paths using Dijkstra's Algorithm
- Uses a priority queue (min-heap) for efficient traversal
- Reconstructs and displays the actual shortest route
- Accepts source and destination locations from the user
- Handles invalid source or destination locations
- Supports bidirectional weighted roads

---

## Technologies and Concepts

- C++
- Standard Template Library (STL)
- Graph Data Structures
- Dijkstra's Algorithm
- Priority Queue
- Adjacency List
- Hash Maps
- Path Reconstruction

---

## Project Structure

```text
Smart-Route-Planner-using-graph-algorithms/
│
├── main.cpp
├── sample_output.txt
├── README.md
└── .gitignore
```

---

## How It Works

The application represents every location as a vertex in a graph and every road as a weighted edge.

For example:

```text
Delhi ----233 km---- Agra
  |                    |
280 km               290 km
  |                    |
Jaipur               Kanpur
```

When the user provides a source and destination:

1. All distances are initially set to infinity.
2. The source distance is initialized to `0`.
3. A priority queue selects the location with the smallest known distance.
4. Adjacent edges are relaxed whenever a shorter path is discovered.
5. Parent information is stored to reconstruct the final route.
6. The shortest distance and route are displayed.

---

## Example

### Input

```text
Enter source location: Delhi
Enter destination location: Kanpur
```

### Output

```text
Shortest Distance: 523 km
Optimal Route: Delhi -> Agra -> Kanpur
```

The selected route is:

```text
Delhi -> Agra -> Kanpur
```

with:

```text
Delhi -> Agra  = 233 km
Agra -> Kanpur = 290 km

Total = 523 km
```

---

## Time Complexity

Using an adjacency list and priority queue, Dijkstra's Algorithm runs in approximately:

```text
O((V + E) log V)
```

where:

- `V` = number of vertices (locations)
- `E` = number of edges (roads)

---

## How to Run

### Clone the repository

```bash
git clone https://github.com/Srinivas-Mutta/Smart-Route-Planner-using-graph-algorithms.git
```

### Navigate to the project directory

```bash
cd Smart-Route-Planner-using-graph-algorithms
```

### Compile

```bash
g++ main.cpp -o routeplanner
```

### Run on Windows

```bash
.\routeplanner.exe
```

### Run on Linux/macOS

```bash
./routeplanner
```

---

## Future Enhancements

- Support dynamically adding locations and roads
- Read graph data from external files
- Case-insensitive location search
- Implement A* search for heuristic-based pathfinding
- Add a graphical map interface
- Support dynamic road weights such as traffic conditions

---

## Author

**Srinivas Mutta**

B.Tech in Electronics and Communication Engineering  
Indian Institute of Technology (ISM) Dhanbad
