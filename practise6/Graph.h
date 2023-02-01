#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <vector>
#include "Tree.h"
using namespace std;

vector<vector<int>> depricate(vector<vector<int>> v, int column) {
	vector<vector<int>> v1 = v;
	for (int i = 0;i <= v.size() - 1;i++) v1[i][column] = -1;
	return v1;
}

bool isContent(vector<int> line, int l) {
	for (int i = 0;i < line.size();i++)
		if (line[i] == l) return true;
	return false;
}

struct Graph {
	int vNum=0;
	vector<vector<int>> v;
	Graph(int n) {
		vNum = n;
		v.resize(vNum+1);
		for (int i = 0;i <= n;i++) {
			v[i].resize(vNum + 1);
			v[i][0] = i;
			v[0][i] = i;
			for (int j = 1;j <= n;j++) {
				v[i][j] = 0;
			}
		}
	}
	int addEdgeNoOrient(int a, int b,int e=1) {
		if (a <= vNum && a >= 1 && b <= vNum && b >= 1) {
			v[a][b] = e;
			v[b][a] = e;
		}
		else return 1;
		return 0;
	}
	int showVertextNeigbors(int i) {
		if (i >= 1 && i <= vNum) {
			cout << v[i][0] << ": ";
			for (int j = 1;j <= vNum;j++) {
				if (v[i][j]) cout << j << "("<<v[i][j]<<") ";
			}
		}
		else return 1;
		return 0;
	}
	void showGraph() {
		for (int i = 1;i <= vNum;i++) {
			showVertextNeigbors(i);
			cout << endl;
		}
	}

	void searchGamiltonovCycle(Node* GTree,vector<int> line,int &count) {
		line.push_back(GTree->num);
		if (GTree->children.size() == 0) {
			if (line.size() == vNum + 1 && line[0] == line[line.size() - 1]) {
				count++;
				cout << endl;
				for (int i = 0;i < line.size();i++) {
					cout << line[i] << " ";
				}
				line.pop_back();
				return;
			}
		}
		for (int i = 0;i < GTree->children.size();i++) {
			if (isContent(line, GTree->children[i]->num) && GTree->children[i]->num != line[0]) continue;
			searchGamiltonovCycle(GTree->children[i],line,count);
		}
	}

	void searchFundamentalCycle(Node* GTree, vector<int> line,int& count) {
		line.push_back(GTree->num);
		if (GTree->children.size() == 0) {
			if (line.size() == vNum + 1 && line[0] == line[line.size() - 1]) {
				vector<vector<int>> temps;
				for (int i = 0;i < line.size()-3;i++) {
					vector<int> temp;
					for (int j = i;j < line.size() - 1;j++) {

						//temp.resize(temp.size() + 1);
						temp.push_back(line[j]);

						if (j > i+1 && v[line[i]][line[j]] != 0) {

							//temps.resize(temps.size() + 1);
							temp.push_back(line[i]);
							temps.push_back(temp);
							temp.pop_back();
							count++;
						}
					}
				}
				line.pop_back();
				for (int i = 0;i < temps.size();i++) {
					cout << endl;
					for (int j = 0;j < temps[i].size();j++) {
						cout << temps[i][j] << " ";
					}
				}
				return;
			}
		}
		for (int i = 0;i < GTree->children.size();i++) {
			if (isContent(line, GTree->children[i]->num) && GTree->children[i]->num != line[0]) continue;
			searchFundamentalCycle(GTree->children[i], line, count);
		}
	}
};

#endif