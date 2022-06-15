#include "graph.h"

 // adds an edge to the graph
void Graph:: pushEdge(unsigned src_vtx,unsigned dest_vtx, unsigned ec, unordered_set<unsigned>& e_label){		//LABELS ARE PUSHED HERE....
	if(src_vtx > dest_vtx)
	{
		this->edges.push_back(src_vtx*1000000 + dest_vtx*1000 + ec);
		this->EdgeLabelMap[src_vtx*1000000 + dest_vtx*1000 + ec]++;
		e_label.insert(src_vtx*1000000 + dest_vtx*1000 + ec);
	}
	else 
	{
		this->edges.push_back(dest_vtx*1000000 + src_vtx*1000 + ec);
		this->EdgeLabelMap[dest_vtx*1000000 + src_vtx*1000 + ec]++;	
		e_label.insert(dest_vtx*1000000 + src_vtx*1000 + ec);
	}
}

// reads the graph from input file 
void Graph:: readGraph(istream &inp, unsigned vlblCount, unordered_map<char, unsigned> global_vrtxlbl_map, unordered_map<string, unsigned> global_edgetype_map,  unordered_set<unsigned>& e_label){
	char tag;
	// first line should be of the format "g vertexCount(unsigned int) edgeCount(unsigned int) gid(unsigned int)"
	inp >> tag; // the tag 'g'
	inp >> vertexCount; // the no. of vertices in the graph
	inp >> edgeCount; // the no. of edges in the graph
	inp >> gid; // the graph-id of the graph
	vertices.resize(vertexCount);
	vrtxLbl.resize(vertexCount);
	edgeTypeVectr.resize(global_edgetype_map.size(), 0);
	unsigned ind = 0;
	unsigned vid, src_vtx, dest_vtx, ec;
	char vc;  //Vertex type -- vc 
	for(int vtx_ind=0; vtx_ind < vertexCount; vtx_ind++)
	{
		// each line for each vertex should be in the format like: "v vid(unsigned int)"
		inp >> tag >> vid >> vc; // the tag 'v' along with the vertex-id
		
		vertices[vtx_ind] = vid;
		vid_to_ind[vid] = vtx_ind; // mapping vertex-id to its index
		vid_to_vc[vid] = (vc-'A')+65;
		//vid_to_vc[vid] = global_vrtxlbl_map[vc]+ 65;
		vrtxLbl[vtx_ind] = vc;
		//VertexLabelMap [(vc-'A')+65]++;
		//v_label.insert((vc-'A')+65);
		//v_label.insert(vc);
	}
	//cout<<"..................................."<<endl;
	for(int e_ind = 0; e_ind < edgeCount; e_ind++)
	{
		// each line for each edge should be in the format like: "e vid_src(unsigned int) vid_dest(unsigned int)"
		inp >> tag >> src_vtx >> dest_vtx >> ec; // the tag 'e' along with the source and destination vertex-ids
		// Undirected graph : adding edge source to destination and destination to source
		
		if(char(vid_to_vc[src_vtx]-65 +'A') < char(vid_to_vc[dest_vtx]- 65 + 'A'))
		{
			string eType {char(vid_to_vc[src_vtx]-65 +'A') , '-', char(vid_to_vc[dest_vtx]- 65 + 'A') };
			unsigned unsign_eType = global_edgetype_map[eType];
                	//cout<<eType<<"  "<<unsign_eType<<"    "<<edgeTypeVectr[unsign_eType]<<endl;
                	edgeTypeVectr[unsign_eType]++;
                	//cout<<edgeTypeVectr[unsign_eType]<<endl;
		}
		else
		{
			string eType {char(vid_to_vc[dest_vtx]-65 +'A') , '-', char(vid_to_vc[src_vtx]- 65 + 'A') };
			//edgeType[e_ind] = global_edgetype_map[eType];
			unsigned unsign_eType = global_edgetype_map[eType];
			//cout<<eType<<"  "<<unsign_eType<<"    "<<edgeTypeVectr[unsign_eType]<<endl;
			edgeTypeVectr[unsign_eType]++;
			//cout<<edgeTypeVectr[unsign_eType]<<endl;
		}
		pushEdge(vid_to_vc[src_vtx], vid_to_vc[dest_vtx], ec, e_label);			//NOTICE LABEL IS PASSED
	}
	//cout<<"........................................"<<endl;
	VertexLabelVectr.resize(vlblCount, 0);
        for(int i=0; i<vrtxLbl.size(); i++)
        {
                unsigned vlbl = global_vrtxlbl_map[vrtxLbl[i]];
                VertexLabelVectr[vlbl]++;

        }



}

// prints details of the graph
/*void Graph::displayGraph()
{
	cout <<"g "<< gid << ":" << endl;
	cout <<"Vertex Count: "<< vertexCount << endl;
	cout <<"Edge Count: "<< edgeCount << endl;
	for(int vtx_ind = 0; vtx_ind<vertexCount; vtx_ind++)
	{
		cout << "v" << vtx_ind << ": " << vertices[vtx_ind] << endl;
	}
	for(int edg_ind = 0; edg_ind<edgeCount; edg_ind++)
	{
		cout << "e" << edg_ind << ": " << edges[edg_ind]/101 << " " << edges[edg_ind]%101 << endl;
	}
}*/

