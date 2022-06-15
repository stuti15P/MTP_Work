#include "graph.h"
#include <set>

//Taking as ordered_set. set bcoz duplicates are not allowed. ordered bcoz I need in Increasing order.
//set<char> global_vrtxlbl_set;
//unordered_map<char, unsigned> global_vrtxlbl_map;  //to map global vertex label to unsigned numeric. 
//double computeSimilarity(Graph &g1, Graph &g2, double &commonV, unordered_set<unsigned>& v_label, unordered_set<unsigned>& e_label);
double computeSimilarity(Graph &g1, Graph &g2, double &commonV,  unordered_set<unsigned>& e_label);
