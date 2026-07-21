#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjacencyList;

public:

    // Add a bidirectional weighted road between two locations
    void addRoad(const string& source, const string& destination, int distance) {
        adjacencyList[source].push_back({destination, distance});
        adjacencyList[destination].push_back({source, distance});
    }

    // Display all available locations
    void displayLocations() const {
        cout << "\nAvailable Locations:\n";

        for (const auto& location : adjacencyList) {
            cout << "- " << location.first << '\n';
        }
    }

    // Find the shortest path using Dijkstra's Algorithm
    void findShortestPath(const string& source, const string& destination) {

        // Check whether source and destination exist
        if (adjacencyList.find(source) == adjacencyList.end() ||
            adjacencyList.find(destination) == adjacencyList.end()) {

            cout << "\nInvalid source or destination location.\n";
            return;
        }

        unordered_map<string, int> distance;
        unordered_map<string, string> parent;

        // Initially, distance to every location is infinity
        for (const auto& location : adjacencyList) {
            distance[location.first] = INT_MAX;
        }

        // Min heap: {distance, location}
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
        > pq;

        distance[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {

            int currentDistance = pq.top().first;
            string currentLocation = pq.top().second;

            pq.pop();

            // Ignore outdated entries
            if (currentDistance > distance[currentLocation]) {
                continue;
            }

            // Destination reached
            if (currentLocation == destination) {
                break;
            }

            for (const auto& neighbour : adjacencyList[currentLocation]) {

                string nextLocation = neighbour.first;
                int roadDistance = neighbour.second;

                int newDistance = currentDistance + roadDistance;

                // Relaxation step
                if (newDistance < distance[nextLocation]) {

                    distance[nextLocation] = newDistance;
                    parent[nextLocation] = currentLocation;

                    pq.push({newDistance, nextLocation});
                }
            }
        }

        // Destination is unreachable
        if (distance[destination] == INT_MAX) {
            cout << "\nNo route exists between "
                 << source << " and " << destination << ".\n";
            return;
        }

        // Reconstruct shortest path
        vector<string> path;

        string current = destination;

        while (current != source) {
            path.push_back(current);
            current = parent[current];
        }

        path.push_back(source);

        reverse(path.begin(), path.end());

        // Display result
        cout << "\n=================================\n";
        cout << "          ROUTE RESULT           \n";
        cout << "=================================\n";

        cout << "Shortest Distance: "
             << distance[destination]
             << " km\n";

        cout << "Optimal Route: ";

        for (size_t i = 0; i < path.size(); i++) {

            cout << path[i];

            if (i != path.size() - 1) {
                cout << " -> ";
            }
        }

        cout << '\n';
    }
};


int main() {

    Graph routePlanner;

    // Add locations and road distances
    routePlanner.addRoad("Delhi", "Jaipur", 280);
    routePlanner.addRoad("Delhi", "Agra", 233);
    routePlanner.addRoad("Jaipur", "Agra", 240);
    routePlanner.addRoad("Agra", "Lucknow", 330);
    routePlanner.addRoad("Lucknow", "Kanpur", 90);
    routePlanner.addRoad("Agra", "Kanpur", 290);

    cout << "=================================\n";
    cout << "       SMART ROUTE PLANNER       \n";
    cout << "=================================\n";

    routePlanner.displayLocations();

    string source;
    string destination;

    cout << "\nEnter source location: ";
    getline(cin, source);

    cout << "Enter destination location: ";
    getline(cin, destination);

    routePlanner.findShortestPath(source, destination);

    return 0;
}
