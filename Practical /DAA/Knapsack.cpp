
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit of item "
             << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;

        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    double totalProfit = 0;

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else {
            totalProfit += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    cout << "Maximum profit = " << totalProfit << endl;

    return 0;
}

