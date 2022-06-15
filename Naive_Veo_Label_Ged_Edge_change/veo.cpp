#include "veo.h"
#include <cmath>
#include <bits/stdc++.h>


//Taking as ordered_set. set bcoz duplicates are not allowed. ordered bcoz I need in Increasing order.
extern set<char> global_vrtxlbl_set;
extern unordered_map<char, unsigned> global_vrtxlbl_map;  //to map global vertex label to unsigned numeric. 
extern unordered_map<string, unsigned> global_edgetype_map;



// Edge comparator
bool edgeComp(pair<unsigned, unsigned> &a, pair<unsigned, unsigned> &b,Graph &g1,Graph &g2)// since we have stored labels in edges, so we need not use vid_to_vc here.
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

// Intersection of vertex lists of 2 graphs
double intersection_vertices(vector<unsigned> &s1, vector<unsigned> &s2,unsigned gid1,unsigned gid2,Graph &g1,Graph &g2)
{
	double common = 0;

	for(auto pr : global_vrtxlbl_map){
		unsigned vlbl = pr.second;
		common += min(g1.VertexLabelVectr[vlbl], g2.VertexLabelVectr[vlbl]);
	}
	//cout<<"In intersection_vertices common vertices = "<<common<<endl;

	/*unsigned s1_iter = 0;
	unsigned s2_iter = 0;
	
	while(s1_iter < s1.size() && s2_iter < s2.size())
	{
		if(g1.vid_to_vc[s1[s1_iter]] < g2.vid_to_vc[s2[s2_iter]])
			s1_iter++;
		else if(g1.vid_to_vc[s1[s1_iter]] > g2.vid_to_vc[s2[s2_iter]])
			s2_iter++;
		else
		{
			
			s1_iter++;
			s2_iter++;
			common++;		
		}
	}*/

	return common;
}

// Intersection of edge lists of 2 graphs
double intersection_edges(vector<unsigned> &s1, vector<unsigned> &s2,unsigned gid1,unsigned gid2,Graph &g1,Graph &g2, unordered_set<unsigned>& e_label)
{

	double common = 0;

	/*for(auto label : e_label){

		common += min(g1.EdgeLabelMap[label], g2.EdgeLabelMap[label]);
	} */
	for(auto pr :global_edgetype_map){
		unsigned eType =pr.second;
		//cout<<pr.first<<" "<<pr.second<<endl;
		//cout<<g1.edgeTypeVectr[eType]<<"  "<<g2.edgeTypeVectr[eType]<<endl;
		common += min(g1.edgeTypeVectr[eType], g2.edgeTypeVectr[eType]);
	}
	//cout<<"In intersection_vertices common edges = "<<common<<endl;



/*	unsigned s1_iter = 0;
	unsigned s2_iter = 0;

	while(s1_iter < s1.size() && s2_iter < s2.size())
	{
		if(s1[s1_iter] < s2[s2_iter])
			s1_iter++;
		else if(s1[s1_iter] > s2[s2_iter])
			s2_iter++;
		else
		{
			
			s1_iter++;
			s2_iter++;
			common++;		
		}
	}
*/
	return common;
}

// VEO Similarity computation
double computeSimilarity(Graph &g1, Graph &g2, double &commonV,  unordered_set<unsigned>& e_label)
{
	if(commonV == 0)
		commonV = intersection_vertices(g1.vertices, g2.vertices,g1.gid,g2.gid,g1,g2);
	commonV+=intersection_edges(g1.edges, g2.edges,g1.gid,g2.gid,g1,g2, e_label);

//	cout << commonV << " "<<g1.vertexCount+g2.vertexCount+g1.edgeCount+g2.edgeCount<<"\n";

	double simScore = (double)(200.0*(commonV)/(double)(g1.vertexCount+g2.vertexCount+g1.edgeCount+g2.edgeCount));

	return simScore;
}
