#include<bits/stdc++.h>
using namespace std;

int main(){


    map<pair<unsigned, unsigned>, unsigned> umap;
    ofstream otp;

    otp.open("Ged_till_5_arrange_new.txt");

    ifstream inp;
    inp.open("Ged_till_5_new.txt");
    if(!inp)
    {
        cout<<"Input file can't be opened\n";
        return 0;
    }
    unsigned g1, g2, tau;
    while(!inp.eof())						//Start reading the input file till end.
    {
        inp>>g1>>g2>>tau;
        if(tau <=10)
        {
            if(g1 >=g2)
            {
                if(umap.find({g1, g2}) == umap.end())
                {
                    umap.insert({{g1, g2}, tau});
                    //otp<<g1<<" "<<g2<<" "<<tau<<endl;
                }
            }

            else
            {
                if(umap.find({g2, g1}) == umap.end())
                {
                    umap.insert({{g2, g1}, tau});
                    //otp<<g2<<" "<<g1<<" "<<tau<<endl;
                }

            }
        }
    }

    for(auto ppr: umap)
    {
        pair<unsigned, unsigned> pr =ppr.first;
        unsigned tauu =ppr.second;
        unsigned g11 =pr.first;
        unsigned g22 =pr.second;
        otp<<g11<<" "<<g22<<" "<<tauu<<endl;
    }
    return 0;
}
