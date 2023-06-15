//kth smallest element in a row-wise and column-wise sorted 2D array 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Element {
    int value; 
    int row;   
    int col;   

    Element(int v, int r, int c) : value(v), row(r), col(c) {}
};


struct Compare {
    bool operator()(const Element& a, const Element& b) {
        return a.value > b.value;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();

    
    priority_queue<Element, vector<Element>, Compare> minHeap;


    for (int i = 0; i < n; i++) {
        minHeap.push(Element(matrix[i][0], i, 0));
    }

    while (k > 1) {
        Element curr = minHeap.top();
        minHeap.pop();

        int row = curr.row;
        int col = curr.col + 1;

        if (col < n) {
            minHeap.push(Element(matrix[row][col], row, col));
        }

        k--;
    }

    return minHeap.top().value; 
}

int main() {
    int n, k;
    cout << "Enter the value of n (matrix size): ";
    cin >> n;
    cout << "Enter the matrix elements row by row:\n";

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int kthSmallestElement = kthSmallest(matrix, k);
    cout << "The kth smallest element is: " << kthSmallestElement << endl;

    return 0;
}
