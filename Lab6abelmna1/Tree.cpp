#include <iostream>
#include "Tree.h"
using namespace std;

template <typename T>
Tree<T>::Tree(){
	root = NULL;
}

template <typename T>
Tree<T>::~Tree() {
	while (root) {
		remove(root->value);
	}
}

template <typename T>
bool Tree<T>::insert(const T &v){
	if (root == NULL) {
		root = new Node(v);
		return true;
	} else {
		return insertHelper(*root, v);
	}

	cout << "Reached Error Point in insert()" << endl;
	return false;
}

template <typename T>
bool Tree<T>::insertHelper(struct Node &n, const T &v) {
	if (v == n.value) {				// Cannot have duplicates in the tree
		return false;
	} else if (v > n.value && n.right != NULL) {
		return insertHelper(*n.right, v);
	} else if (v < n.value && n.left != NULL) {
		return insertHelper(*n.left, v);
	} else if (v > n.value && n.right == NULL) {
		n.right = new Node(v);
		return true;
	} else if (v < n.value && n.left == NULL) {
		n.left = new Node(v);
		return true;
	}

	cout << "Reached Error Point in insertHelper()" << endl;
	return false;
}

template <typename T>
bool Tree<T>::removeNoChildren(struct Node &parent, struct Node &n, const T &v) {
	if (parent.left && parent.left->value == n.value) {								// parent's left points to n
		delete &n;
		parent.left = NULL;
		return true;
	} else {													// parent's right points to n
		delete &n;
		parent.right = NULL;
		return true;
	}

	return false;
}

template <typename T>
bool Tree<T>::removeOneLeftChild(struct Node &parent, struct Node &n, const T &v) {
	if (parent.left && parent.left->value == n.value) {								// parent's left points to n
		parent.left = n.left;
		delete &n;
		return true;
	} else {													// parent's right points to n
		parent.right = n.left;
		delete &n;
		return true;
	}

	return false;
}

template <typename T>
bool Tree<T>::removeOneRightChild(struct Node &parent, struct Node &n, const T &v) {
	if (parent.left && parent.left->value == n.value) {								// parent's left points to n
		parent.left = n.right;
		delete &n;
		return true;
	} else {													// parent's right points to n
		parent.right = n.right;
		delete &n;
		return true;
	}

	return false;
}

template <typename T>
bool Tree<T>::removeTwoChildren(struct Node &parent, struct Node &n, const T &v) {							
	T max = findMax(n, *(n.left));
	n.value = max;
	return true;
}


template <typename T>
T Tree<T>::findMax(struct Node &parent, struct Node &n) {
	if (n.right) return findMax(n, *(n.right));
	else {
		T max = n.value;
		if (n.left) removeOneLeftChild(parent, n, n.value);
		else removeNoChildren(parent, n, n.value);
		//cout << "max: " << max << endl;
		return max;
	}
}

template <typename T>
bool Tree<T>::remove(const T &v) {
	if (root != NULL) {
		if (v == root->value) {
			if (root->left == NULL && root->right == NULL) {			// Root has no children
				delete (root);
				root = NULL;
				return true;
			} else if (root->left && root->right == NULL) {			// Root only has left child
				Node *temp = root;
				root = root->left;
				delete temp;
				return true;
			} else if (root->left == NULL && root->right) {			// Root only has right child
				Node *temp = root;
				root = root->right;
				delete temp;
				return true;
			} else if (root->left && root->right) {					// Root has two children
				T max = findMax(*root, *(root->left));
				root->value = max;
				return true;
			}
		} else if (v > root->value && root->right != NULL) {
			return removeHelper(*root, *(root->right), v);
		} else if (v < root->value && root->left != NULL) {
			return removeHelper(*root, *(root->left), v);
		}
		
	}
	return false;
}

template <typename T>
bool Tree<T>::removeHelper(struct Node &parent, struct Node &n, const T &v) {
	if (v == n.value) {
		// Remove n.value from Tree
		if (n.left == NULL && n.right == NULL) {				// n has no children
			return removeNoChildren(parent, n, v);

		} else if (n.left != NULL && n.right == NULL) {				// n only has a left child
			return removeOneLeftChild(parent, n, v); 

		} else if (n.left == NULL && n.right != NULL) {				// n only has a right child
			return removeOneRightChild(parent, n, v);

		} else if (n.left != NULL && n.right != NULL) {				// n has 2 children
			return removeTwoChildren(parent, n, v);

		}
	} else if (v > n.value && n.right != NULL) {
		return removeHelper(n, *(n.right), v);
	} else if (v < n.value && n.left != NULL) {
		return removeHelper(n, *(n.left), v);
	}
	
	return false;
}

template <typename T>
bool Tree<T>::find(const T &v) const {
	if (root != NULL) return findHelper(*root, v);
	
	return false;
}

template <typename T> 
bool Tree<T>::findHelper(struct Node &n, const T &v) const{
	if (v == n.value) return true;
	else if (v > n.value && n.right) return findHelper(*(n.right), v);
	else if (v < n.value && n.left) return findHelper(*(n.left), v);
	else return false;
}

template <typename T>
void Tree<T>::display() const {
  if(root != NULL) displayHelper(*root); 
}

template <typename T>
void Tree<T>::displayHelper(struct Node &n) const {
	if (n.left != NULL) displayHelper(*(n.left));
	cout << n.value << endl;
	if (n.right != NULL) displayHelper(*(n.right));
}


