#ifndef _TEST_H
#define _TEST_H
#include "Graph.h"
#include "Tree.h"
#include <vector>

void test1() {
	int vNum;
	int v1, v2,e;
	cout << "Input the number of vertexes: ";
	cin >> vNum;
	Graph* G=new Graph(vNum);
	cout << "Input connected pair of vertexes and the weight of the edge: " << endl;
	while(cin >> v1 >> v2 >> e) {
		G->addEdgeNoOrient(v1, v2,e);
	}
	cout << endl;
	cout << endl << "Graph:";
	G->showGraph();

	Node* GTree = new Node();
	GTree->makeTree(G->v,1,1);

	cout << endl;
	GTree->showTree("  ");
	cout << endl;

	vector<int> line;
	int count=0;

	cout <<endl<< "Gamiltonov cycles (each in both directions): ";
	G->searchGamiltonovCycle(GTree, line, count);
	cout << endl << "Graph contains " << count/2 << " Gamiltonov cycles" << endl;

	cout <<endl<< "Fundamental cycles (each in both directions): ";
	G->searchFundamentalCycle(GTree, line, count);
	cout << endl << "Graph contains " << count/2 << " Fundamental cycles" << endl;

}

#endif
