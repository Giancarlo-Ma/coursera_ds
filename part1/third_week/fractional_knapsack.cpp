#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
	int value;
	int weight;
};

bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value  / a.weight;
	double r2 = (double)b.value  / b.weight;
	return r1 > r2;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
	double value = 0.0;

	// write your code here
	// construct [[value,weight]]
	int n = weights.size();
	Item items[n];
	for(int i = 0; i != n; i++) {
		items[i].value = values[i];
		items[i].weight = weights[i];
	}

	sort(items, items+n,cmp);
	// for (int i = 0; i < n; i++) 
    // { 
    //     cout << items[i].value << "  " << items[i].weight << " : " 
    //          << ((double)items[i].value / items[i].weight) << endl; 
    // }

	int curWeight = 0;
	for(int i = 0; i < n; i++) {
		if(curWeight + items[i].weight <= capacity) {
			curWeight += items[i].weight;
			value+=items[i].value;
		}
		else {
			int remain = capacity - curWeight;
			value+=items[i].value * ((double)remain / items[i].weight);
			break;
		}
	}
	return value;
}

int main()
{
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
