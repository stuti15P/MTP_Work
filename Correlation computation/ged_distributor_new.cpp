#include<bits/stdc++.h>
using namespace std;

int main(){


    set<pair<unsigned, unsigned>> uset;
    ofstream otp;

    otp.open("Ged_till_5_new.txt");

    ifstream inp;
    inp.open("Ged_till_5.txt");
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
                if(uset.find({g1, g2}) == uset.end())
                {
                    uset.insert({g1, g2});
                    otp<<g1<<" "<<g2<<" "<<tau<<endl;
                }
            }

            else
            {
                if(uset.find({g2, g1}) == uset.end())
                {
                    uset.insert({g2, g1});
                    otp<<g2<<" "<<g1<<" "<<tau<<endl;
                }

            }
        }
    }
    return 0;
}
