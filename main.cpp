#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjacencyList;

public:

    // Add a bidirectional weighted road between two locations
    void addRoad(string source, string destination, int distance) {
        adjacencyList[source].push_back({destination, distance});
        adjacencyList[destination].push_back({source, distance});
    }

    // Display all locations and their connected routes
    void displayGraph() {
        cout << "\nAvailable Routes:\n";

        for (const auto& location : adjacencyList) {
            cout << location.first << " -> ";

            for (const auto& neighbour : location.second) {
                cout << "(" << neighbour.first
                     << ", " << neighbour.second << " km) ";
            }

            cout << endl;
        }
    }
};

int main() {

    Graph routePlanner;

    // Adding locations and road distances
    routePlanner.addRoad("Delhi", "Jaipur", 280);
    routePlanner.addRoad("Delhi", "Agra", 233);
    routePlanner.addRoad("Jaipur", "Agra", 240);
    routePlanner.addRoad("Agra", "Lucknow", 330);
    routePlanner.addRoad("Lucknow", "Kanpur", 90);
    routePlanner.addRoad("Agra", "Kanpur", 290);

    cout << "=================================\n";
    cout << "       SMART ROUTE PLANNER       \n";
    cout << "=================================\n";

    routePlanner.displayGraph();

    return 0;
}
