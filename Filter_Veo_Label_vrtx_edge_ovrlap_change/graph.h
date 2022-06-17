#pragma once

#include "common.h"
#include <set>




class Graph
{
	public:
		unsigned gid, vertexCount, edgeCount;
		vector<unsigned> vertices;
		vector<unsigned> degrees;
		vector<char> vrtxLbl;
		unordered_map<unsigned,unsigned> vid_to_ind; // vid to index in adjacency list of graph
		unordered_map<unsigned,unsigned> vid_to_vc;
		vector<pair<unsigned, unsigned> > edges;
		vector<unsigned> edgeType;  //------>   
                //unordered_map<unsigned, unsigned> VertexLabelMap; // count of a type of vertex label
                vector<unsigned> VertexLabelVectr; //will save count of a vertex label in the graph.
		vector<unsigned> edgeTypeVectr;  //----->


		Graph(){
			gid = 0;
			vertexCount = 0;
			edgeCount = 0;
		}

		void readGraph(istream &inp, unsigned vlblCount,  unordered_map<char, unsigned> global_vrtxlbl_map, unordered_map<string, unsigned> global_edgeType_map);
		void pushEdge(unsigned u, unsigned v, unsigned ec);
		void displayGraph();
};

