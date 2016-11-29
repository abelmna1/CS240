#include <iostream>
#include "ThreeAryTree.h"

using namespace std;

template <typename T>
ThreeAryTree<T>::ThreeAryTree() {
	root = NULL;
}

template <typename T>
ThreeAryTree<T>::~ThreeAryTree() {
	while (root) {
		if (root->low_valid) remove(root->low);
		if (root->high_valid) remove(root->high);
	}
}

template <typename T>
bool ThreeAryTree<T>::insert(const T &v) {
	if (root == NULL) {			// Inserting element to an empty tree
		root = new Node2(v);
		return true;
	} else {				// Inserting element to a nonempty tree
		return insertHelper(*root, v); 
	}

	cout << "Reached Error Point in insert()" << endl;
	return false;
}

template <typename T>
bool ThreeAryTree<T>::insertHelper(struct Node2 &n, const T &v) {
	if ((n.low_valid && v == n.low) || (n.high_valid && v == n.high)) {		// Case 0: Cannot have duplicates in the tree
		cout << "Cannot have duplicates in the tree." << endl;
		return false;
	} else if (!n.low_valid && !n.high_valid) {					// Case 1: Node exists, but it has no values
		n.low = v;
		n.low_valid = true;
		return true;
	} else if (n.low_valid && !n.high_valid) {					// Case 2a: Node exists, but it only has a low value
		if (v > n.low) {
			n.high = v;
			n.high_valid = true;
			return true;
		} else {
			if (n.left) return insertHelper(*(n.left), v);
			else n.left = new Node2(v);
			return true;
		}
	} else if (!n.low_valid && n.high_valid) {					// Case 2b: Node exists, but it only has a high value
		if (v < n.high) {
			n.low = v;
			n.low_valid = true;
			return true;
		} else {
			if (n.right) return insertHelper(*(n.right), v);
			else n.right = new Node2(v);
			return true;
		}
	} else if (n.low_valid && n.high_valid) {					// Case 3: Node exists, and it has both a low and a high value
		if (v < n.low) {									// v < n.low
			if (n.left) return insertHelper(*(n.left), v);
			else n.left = new Node2(v);
			return true;
		} else if (v > n.high) {								// v > n.high
			if (n.right) return insertHelper(*(n.right), v);
			else n.right = new Node2(v);
			return true;
		} else if (v > n.low && v < n.high) {							// n.low < v < n.high
			if (n.center) return insertHelper(*(n.center), v);
			else n.center = new Node2(v);
			return true;
		}
	}
	
	cout << "Reached Error Point in insertHelper()" << endl;
	return false;
}

template <typename T>
bool ThreeAryTree<T>::remove(const T &v) {
	if (root) {
		if (root->low_valid && root->low == v) {							// root's low value is v
			if (root->left) {										//// n has a left subtree
				root->low = findMax(*root,*(root->left));
			} else if (root->center) {									//// n has a center subtree
				root->low = findMin(*root,*(root->center));
			} else if (root->right) {									//// n has a right subtree
				root->low = root->high;		
				root->high = findMin(*root,*(root->right));
			} else {										//// n is a leaf node
				root->low_valid = false;
				if (!root->high_valid) {								////// n is now an empty leaf node
					delete root;
					root = NULL;
				}
			}
			return true;
		} else if (root->high_valid && root->high == v) {						// root's high value is v
				if (root->right) {										//// n has a right subtree
				root->high = findMin(*root,*(root->right));
			} else if (root->center) {									//// n has a center subtree
				root->high = findMax(*root,*(root->center));
			} else if (root->left) {									//// n has a left subtree
				root->high = root->low;		
				root->low = findMax(*root,*(root->left));
			} else {										//// n is a leaf node
				root->high_valid = false;
				if (!root->low_valid) {
					delete root;
					root = NULL;
				}
			}
			return true;
		}
		if (root->low_valid && v < root->low && root->left) {							// v would be in root's left subtree
			return removeHelper1(*root, *(root->left), v);
		} else if (root->low_valid && root->high_valid && root->low < v && v < root->high && root->center) {	// v would be in root's center subtree
			return removeHelper1(*root, *(root->center), v);
		} else if (root->high_valid && v > root->high && root->right) {						// v would be in root's right subtree
			return removeHelper1(*root, *(root->right), v);
		}
		cout << "The value is not in the tree (only checked root)" << endl;	
	}

	
	return false;
}

template <typename T>
bool ThreeAryTree<T>::removeHelper1(struct Node2 &p, struct Node2 &n, const T &v) {
	if (n.low_valid && n.low == v) {								// found v, it's the low value of n
		if (n.left) {										//// n has a left subtree
			n.low = findMax(n,*(n.left));
		} else if (n.center) {									//// n has a center subtree
			n.low = findMin(n,*(n.center));
		} else if (n.right) {									//// n has a right subtree
			n.low = n.high;		
			n.high = findMin(n,*(n.right));
		} else {										//// n is a leaf node
			n.low_valid = false;
			if (!n.high_valid) {								////// n is now an empty leaf node
				if (p.left == &n) p.left = NULL;
				if (p.center == &n) p.center = NULL;
				if (p.right == &n) p.right = NULL;
				delete &n;
			}
		}
		return true;
	} else if (n.high_valid && n.high == v) {							// found v, it's the high value of n
		if (n.right) {										//// n has a right subtree
			n.high = findMin(n,*(n.right));
		} else if (n.center) {									//// n has a center subtree
			n.high = findMax(n,*(n.center));
		} else if (n.left) {									//// n has a left subtree
			n.high = n.low;		
			n.low = findMax(n,*(n.left));
		} else {										//// n is a leaf node
			n.high_valid = false;
			if (!n.low_valid) {
				if (p.left == &n) p.left = NULL;
				if (p.center == &n) p.center = NULL;
				if (p.right == &n) p.right = NULL;
				delete &n;
			}
		}
		return true;
	} else if (n.low_valid && v < n.low && n.left) {						// look for v in n's left subtree
		return removeHelper1(n, *(n.left), v);
	} else if (n.high_valid && n.low_valid && n.low < v && v < n.high && n.center) {				// look for v in n's center subtree
		return removeHelper1(n, *(n.center), v);
	} else if (n.high_valid && n.high < v && n.right) {							// look for v in n's right subtree
		return removeHelper1(n, *(n.right), v);
	}
	
	cout << "This value is not in the tree" << endl;
	return false;
}

template <typename T>
T ThreeAryTree<T>::findMax(struct Node2 &p, struct Node2 &n) {
	if (n.right) return findMax(n, *(n.right));	
	else {
		T max;
		if (n.high_valid) {
			max = n.high;
			removeHelper1(p, n, n.high);
		} else {
			max = n.low;
			removeHelper1(p, n, n.low);
		}
		return max;
	}
	cout << "ERROR IN findMax" << endl;
	return 0;
}

template <typename T>
T ThreeAryTree<T>::findMin(struct Node2 &p, struct Node2 &n) {
	if (n.left) return findMin(n, *(n.left));	
	else {
		T min;
		if (n.low_valid) {
			min = n.low;
			removeHelper1(p, n, n.low);
		} else if (n.high_valid) {
			min = n.high;
			removeHelper1(p, n, n.high);
		} else {
			cout << "ERROR 1 in findMin" << endl;
		}
		return min;
	}
	cout << "ERROR 2 in findMin" << endl;
	return 0;
}

template <typename T>
bool ThreeAryTree<T>::find(const T &v) {
	if (root) return findHelper(*root, v);
	return false;
}

template <typename T>
bool ThreeAryTree<T>::findHelper(struct Node2 &n, const T &v) const {
	if ((n.low_valid && v == n.low) || (n.high_valid && v == n.high)) {		// Case 0: Value you're looking for is in this Node
		//cout << "Found the element!" << endl;
		return true;
	} else if (!n.low_valid && !n.high_valid) {					// Case 1: Node exists, but it has no values
		if (n.left && n.center && n.right) return (findHelper(*(n.left), v) || findHelper(*(n.center), v) || findHelper(*(n.right), v));
		else if (n.left && n.center) return (findHelper(*(n.left), v) || findHelper(*(n.center), v));
		else if (n.center && n.right) return (findHelper(*(n.center), v) || findHelper(*(n.center), v));
		else if (n.left && n.right) return (findHelper(*(n.left), v) || findHelper(*(n.right), v));
		else if (n.left) return findHelper(*(n.left), v);
		else if (n.center) return findHelper(*(n.center), v);
		else if (n.right) return findHelper(*(n.right), v);
		else return false;				// This Node is a leaf
	} else if (n.low_valid && !n.high_valid) {					// Case 2a: Node exists, but it only has a low value
		if (v > n.low) {
			if (n.center && n.right) return (findHelper(*(n.center), v) || findHelper(*(n.center), v));
			else if (n.center) return findHelper(*(n.center), v);
			else if (n.right) return findHelper(*(n.right), v);
			else return false;			// This Node is a leaf
		} else {
			if (n.left) return findHelper(*(n.left), v);
			else return false;			// This Node is a leaf
		}
	} else if (!n.low_valid && n.high_valid) {					// Case 2b: Node exists, but it only has a high value
		if (v < n.high) {
			if(n.left && n.center) return (findHelper(*(n.left), v) || findHelper(*(n.center), v));
			else if(n.left) return findHelper(*(n.left), v);
			else if(n.center) return findHelper(*(n.center), v);
			else return false;			// This Node is a leaf
		} else {
			if (n.right) return findHelper(*(n.right), v);
			else return false;			// This Node is a leaf
		}
	} else if (n.low_valid && n.high_valid) {					// Case 3: Node exists, and it has both a low and a high value
		if (v < n.low) {									// v < n.low. Search the left subtree
			if (n.left) return findHelper(*(n.left), v);
			else return false;
		} else if (v > n.high) {								// v > n.high. Search the right subtree
			if (n.right) return findHelper(*(n.right), v);
			else return false;
		} else if (v > n.low && v < n.high) {							// n.low < v < n.high. Search the center subtree
			if (n.center) return findHelper(*(n.center), v);
			else return false;
		}
	}
	
	cout << "Reached Error Point in insertHelper()" << endl;
	return false;
}

template <typename T>
void ThreeAryTree<T>::display() const {
	if (root) {
		displayHelper(*root);
	}
}

template <typename T>
void ThreeAryTree<T>::displayHelper(struct Node2 &n) const {
	if (n.left) displayHelper(*(n.left));
	
	if (n.low_valid) {
		
		cout << n.low << endl;
	}
	if (n.center) displayHelper(*(n.center));
	if (n.high_valid) {
		cout << n.high << endl;
	}
	if (n.right) displayHelper(*(n.right));
}
