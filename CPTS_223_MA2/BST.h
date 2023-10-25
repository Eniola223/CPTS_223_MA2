#ifndef __BST_H
#define __BST_H

#include <iostream>
#include <limits>
using namespace std;

template <typename T>
struct Node {
public:
	T value;
	Node* left;
	Node* right;

	Node(T val) {
		this->value = val;
		this->left = nullptr;
		this->right = nullptr;
	}

	~Node()
	{
		this->value = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
};


template <typename T>
class BST {

protected:
	Node<T>* _root;         // Root of the tree nodes

	/* Add new T val to the tree */
	void addHelper(Node<T>* root, T val) {
		if (root->value > val) {
			if (!root->left) {
				root->left = new Node<T>(val);
			}
			else {
				addHelper(root->left, val);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(val);
			}
			else {
				addHelper(root->right, val);
			}
		}
	}

	/* Print tree out in inorder (A + B) */
	void printInOrderHelper(Node<T>* root) {
		if (!root) return;
		printInOrderHelper(root->left);
		cout << root->value << ' ';
		printInOrderHelper(root->right);
	}

	/* Return number of nodes in tree */
	int nodesCountHelper(Node<T>* root) {
		if (!root) {
			return 0;
		}
		else {
			return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
		}
	}

	/* Return height of tree (root == nullptr -> 0) */
	int heightHelper(Node<T>* root) {
		if (!root) {
			return -1;
		}
		else {
			return 1 + max(heightHelper(root->left), heightHelper(root->right));
		}
	}

	/* Delete a given <T> value from tree */
	bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
		if (!current) return false;
		if (current->value == value) {
			if (current->left == nullptr || current->right == nullptr) {
				Node<T>* temp = current->left;
				if (current->right) temp = current->right;
				if (parent) {
					if (parent->left == current) {
						parent->left = temp;
					}
					else {
						parent->right = temp;
					}
				}
				else {
					this->_root = temp;
				}
			}
			else {
				Node<T>* validSubs = current->right;
				while (validSubs->left) {
					validSubs = validSubs->left;
				}
				T temp = current->value;
				current->value = validSubs->value;
				validSubs->value = temp;
				return deleteValueHelper(current, current->right, temp);
			}
			delete current;
			return true;
		}
		return deleteValueHelper(current, current->left, value) ||
			deleteValueHelper(current, current->right, value);
	}

	/********************************* PUBLIC API *****************************/
public:

	BST() : _root(nullptr) { }               // Basic initialization constructor


	~BST() {
		deletehelper(this->_root);
	}
	void deletehelper(Node<T>* root) {
		if (!root) return;
		deletehelper(root->left);
		deletehelper(root->right);
		delete root;
	}

	/* Public API */
	void add(T val) {
		if (this->_root) {
			this->addHelper(this->_root, val);
		}
		else {
			this->_root = new Node<T>(val);
		}
	}

	void print() {
		printInOrderHelper(this->_root);
	}


	void printLevelOrder(Node<T>* root) {
		if (root == nullptr) {
			return;
		}

		std::queue<Node*>r;

		r.push(root);

		while (!r.empty()) {
			Node* root = r.front();
			r.pop();

			cout << current->value << ' ';
			if (root->left != nullptr) {
				r.push(root->left);
			}
			if (root->right != nullptr) {
				r.push(root->right);
			}
		}
	}

	int nodesCount() {
		return nodesCountHelper(this->_root);
	}

	int height() {
		return heightHelper(this->_root);
	}

	
	void printMaxPath() {
		vector <T> maxPath;
		int MaxSum = findMaxPathHelper(this->_root, maxPath);
		cout << " Maximum Sum path: " << endl;
		for (T val : maxPath) {
			cout << val << " ";
		}
		cout "\n Maximum Sum: " << maxSum << endl;
	}

	int findmaxpathhelper(Node<T>* root, vwctor<T>& maxPath) {
		if (root == nullptr) {
			return 0;
		}
		int leftmax = findmaxpathhelper(root->left, maxPath);
	    int rightmax = findmaxpathhelper(root->right, maxPath);
		int MaxSingle = max(max(leftmax, rightmax), 0) + root->value;
		int MaxPathSum = max(leftmax + rightmax + root->value, MaxSingle);

		if (MaxPathSum > MaxSum) {
			maxPath = vector<T>();
			GetMaximumPath(root, maxPath);
		}
		return MaxSingle;
	}

	void GetMaximumPath(Node <T>* root, vector<T>& Path) {
		if (root == nullptr) {
			return;
		}
		int leftmax = findmaxpathhelper(root->left, maxPath);
		int rightmax = findmaxpathhelper(root->right, maxPath);
		int MaxSingle = max(max(leftmax, rightmax), 0) + root->value));
		
		if (MaxSingle == (leftmax + rightmax + root->value)) {
			path.push_back(root->value);
		//it keeps track of the nodes that belongs to the maximum path
		}
	}

	bool deleteValue(T value) {
		return this->deleteValueHelper(nullptr, this->_root, value);
	}


	bool contains(Node* root, int value) {
		if (root == nullptr) {
			return false;
		}
		if (root->value == value) {
			return true;
		}
		else if (value < root->val) {
			return contains(root->left, value);
		}
		else {
			return contains(root->right, value);
		}
		return numeric_limits<T>::min();
	}
};

#endif


