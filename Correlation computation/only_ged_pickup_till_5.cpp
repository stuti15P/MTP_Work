#include<bits/stdc++.h>
using namespace std;

int main(){



    ofstream otp;

    otp.open("only_ged_till_5.txt");

    ifstream inp;
    inp.open("Ged_till_5_arrange_new.txt");
    if(!inp)
    {
        cout<<"Input file can't be opened\n";
        return 0;
    }
    unsigned g1, g2;
    double veo;
    while(!inp.eof())						//Start reading the input file till end.
    {
        inp>>g1>>g2>>veo;
        otp<<veo<<" ,";

    }
    return 0;
}
