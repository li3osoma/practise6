#ifndef _TREE_H
#define _TREE_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Node {
	Node* parent;
	int num;
	int h;
	vector<Node*> children;
	Node(int n) {
		parent = nullptr;
		num = n;
		h = 1;
	}
	Node() {
		num = -1;
		parent = nullptr;
		h = 0;
	}

	void addChildren(int ch) {
		Node* n = new Node(ch);
		n->parent = this;
		children.push_back(n);
	}

	void makeTree(vector<vector<int>> v,int root,int deep) {
		if (this->parent == nullptr) {
			this->num = root;
		}
		for (int i = 1;i < v.size();i++) {
			if (v[this->num][i] != 0) {
				if (this->parent != nullptr) {
					if (this->parent->num != i) this->addChildren(i);
				}
				else this->addChildren(i);
			}
		}
		for (int i = 0;i < this->children.size();i++) {
			if (this->children[i]->num != root && deep+1!=v.size()) 
				this->children[i]->makeTree(v,root,deep+1);
		}
	}

	void showTree(string step) {
		if (this->parent == nullptr) cout << step << this->num;
		for (int i = 0;i < this->children.size();i++) {
			cout << endl << step<<"  "<<children[i]->num;
			this->children[i]->showTree(step + "  ");
		}
	}
};

#endif
