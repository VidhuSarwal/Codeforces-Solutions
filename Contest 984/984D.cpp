#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count1543InLayer(const string &layer) {
    int count = 0;
    for (size_t i = 0; i + 3 < layer.size(); ++i) {
        if (layer.substr(i, 4) == "1543") {
            ++count;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> carpet(n);
        for (int i = 0; i < n; ++i) {
            cin >> carpet[i];
        }

        int totalCount = 0;
        int layer = 0;
        
        // Traverse each layer clockwise
        while (layer * 2 < n && layer * 2 < m) {
            string layerTraversal;

            // Top row of the current layer
            for (int j = layer; j < m - layer; ++j) {
                layerTraversal += carpet[layer][j];
            }
            // Right column of the current layer
            for (int i = layer + 1; i < n - layer; ++i) {
                layerTraversal += carpet[i][m - layer - 1];
            }
            // Bottom row of the current layer (only if it's not the same as the top row)
            if (n - layer - 1 > layer) {
                for (int j = m - layer - 2; j >= layer; --j) {
                    layerTraversal += carpet[n - layer - 1][j];
                }
            }
            // Left column of the current layer (only if it's not the same as the right column)
            if (m - layer - 1 > layer) {
                for (int i = n - layer - 2; i > layer; --i) {
                    layerTraversal += carpet[i][layer];
                }
            }

            totalCount += count1543InLayer(layerTraversal);
            ++layer;
        }

        cout << totalCount << endl;
    }
    return 0;
}
