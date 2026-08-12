#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    int vertices, edges;

    cout << "Number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices);

    cout << "Number of edges: ";
    cin >> edges;

    cout << "Enter edges:\n";
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int source;
    cout << "Starting vertex: ";
    cin >> source;

    auto dfsStart = high_resolution_clock::now();

    vector<bool> visitedDFS(vertices, false);
    stack<int> st;
    st.push(source);

    cout << "\nDFS Traversal: ";
    while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (!visitedDFS[current]) {
            visitedDFS[current] = true;
            cout << current << " ";

            for (int i = graph[current].size() - 1; i >= 0; i--) {
                int next = graph[current][i];
                if (!visitedDFS[next])
                    st.push(next);
            }
        }
    }

    auto dfsEnd = high_resolution_clock::now();

    auto bfsStart = high_resolution_clock::now();

    vector<bool> visitedBFS(vertices, false);
    queue<int> q;
    q.push(source);
    visitedBFS[source] = true;

    cout << "\nBFS Traversal: ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int next : graph[current]) {
            if (!visitedBFS[next]) {
                visitedBFS[next] = true;
                q.push(next);
            }
        }
    }

    auto bfsEnd = high_resolution_clock::now();

    cout << "\n\nDFS Time: "
         << duration_cast<nanoseconds>(dfsEnd - dfsStart).count() << " ns";

    cout << "\nBFS Time: "
         << duration_cast<nanoseconds>(bfsEnd - bfsStart).count() << " ns";

    return 0;
}
