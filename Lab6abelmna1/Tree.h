#include <iostream>
using namespace std;

 template <typename T>
 class Tree {
    private:
       struct Node {
		Node *right, *left;
		T value;
		Node() {};
		Node(const T &v) {
			right = left = NULL;
			value = v;
		}
	};
	
	Node *root;
    public:
        Tree();
	~Tree();
        bool insert(const T&);
	bool insertHelper(struct Node &n, const T &v);
        bool remove(const T&);
	bool removeHelper(struct Node &parent, struct Node &n, const T &v);
	bool removeNoChildren(struct Node &parent, struct Node &n, const T &v);
	bool removeOneLeftChild(struct Node &parent, struct Node &n, const T &v);
	bool removeOneRightChild(struct Node &parent, struct Node &n, const T &v);
	bool removeTwoChildren(struct Node &parent, struct Node &n, const T &v);
	T findMax(struct Node &parent, struct Node &n);
        bool find(const T&) const;
	bool findHelper(struct Node &n, const T &v) const;
        void display() const; //inorder
	void displayHelper(struct Node &n) const;
	void printTreePic();
	void postorderHelper(struct Node* p, int indent);
 };
