#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class ThreeAryTree {
	private:
		struct Node2 {
			Node2 *right, *center, *left;
			T low, high;
			bool low_valid, high_valid;			// This vector will hold the values of the 0, 1, or 2 elements at this node
			Node2() {};
			Node2(const T &value) {
				right = center = left = NULL;
				low = value;
				low_valid = true;
				high_valid = false;
			}
		};
		Node2 *root;
	public:
		ThreeAryTree();
		~ThreeAryTree();
		bool insert(const T &v);
		bool insertHelper(struct Node2 &n, const T &v);
		bool remove(const T &v);
		bool removeHelper1(struct Node2 &p, struct Node2 &n, const T &v);
		T findMax(struct Node2 &p, struct Node2 &n);
		T findMin(struct Node2 &p, struct Node2 &n);
		bool find(const T &v);
		bool findHelper(struct Node2 &n, const T &v) const;
		void display() const;			// inorder display
		void displayHelper(struct Node2 &n) const;
};
