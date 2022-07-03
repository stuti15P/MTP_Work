Code Till first 3 filters.

Loose, Strict, Vertex Exact Edge Approximate



#Usage:

Compilation
stuti@d3113f5ea26b:~/Filter_Veo_Label_all_Filters_int_label$ g++ -std=c++14 filter.cpp veo.cpp graph.cpp -o filter_curr2

Run
stuti@d3113f5ea26b:~/Filter_Veo_Label_all_Filters_int_label$ ./filter_curr2 dataset/data_5500.txt 3 96 5502 stat_5502

Here, 3 is choice i.e.. Filter to apply, 96 is sim_threshold, 5502 is dataset size. 
stat_5502  is the resulting directory where all the stats will be saved regarding candidate pairs, sim_threshold of each graph. Memory usage, Time taken and so on..


stuti@d3113f5ea26b:~/Filter_Veo_Label_all_Filters_int_label$ g++ -std=c++14 filter.cpp veo.cpp graph.cpp -o filter_curr2
stuti@d3113f5ea26b:~/Filter_Veo_Label_all_Filters_int_label$ ./filter_curr2 dataset/data_5500.txt 3 96 5502 stat_5502
Usage 1 
Graph Dataset parsed.
Graph Dataset sorted.
GSimJoin: VEO Similarity(filters)
Choice: 3
Similarity Score Threshold: 96
Dataset Size: 5502
ubound: 1.08333
Postfix processing Done 
Loose Filter Count: 1891175
Strict Filter Count: 1872154
 Vertex Exact Edge Approx Count : 569219
Final Similar Pair Count: 2
Memory used: 255.922 MB
Total Time Taken: 204410 milliseconds
stuti@d3113f5ea26b:~/Filter_Veo_Label_all_Filters_int_label$
