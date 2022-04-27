/******************
 A(0,0)    B(0,6)

      E(2,3)

      F(4,3)

 D(6,0)    C(6,6)
******************/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
void print(int aa[],int n) {
    for (int i=0;i<n;++i) {
        cout<<aa[i]<<" ";
    }
    cout<<endl;
}
double tspdistance(double tsp[][2],int sol[], int n) {
    double res = 0.0;
    for (int i=0;i<n;++i) {
        int k = (i+1)%n;
        res+=sqrt(
                  pow(tsp[sol[i]][0]-tsp[sol[k]][0],2.0)+
                  pow(tsp[sol[i]][1]-tsp[sol[k]][1],2.0));
    }
    return res;
}
bool next_config(int conf[],int ccc[],int n) {
    int maxval = n-1;
	ccc[conf[maxval]] = 0;
	int found = false;
	for (int pos = maxval-1;pos>0 and not found;--pos) {
        ccc[conf[pos]] = 0;
        for (int currval=conf[pos]+1;currval<=maxval;++currval) {
            if (ccc[currval]==0) {
                conf[pos]=currval;
                ccc[currval]=1;
                found = true;
                break;
            }
        }
        if (found) {
            int currval = 0;
            for (++pos; pos<n; ++pos) {
                while(ccc[currval]==1) ++currval;
                conf[pos]=currval;
                ccc[currval]=1;
            }
        }
	}
	return found;
}
void print_conf(int conf[],string tspnodes[],int n) {
    for (int i=0;i<n;++i) {
        cout<<tspnodes[conf[i]]<<" ";
    }
    cout<<endl;
}
int main() {
    const unsigned n = 6;
    string tspnodes[n] = {"A","B","C","D","E","F"};
	double tsp[n][2]={{0,0},{0,6},{6,6},{6,0},{2,3},{4,3}};
	int ccc[n] = {1,1,1,1,1,1};
	int conf[n] = {0,1,2,3,4,5};
	int maxconf[n];
	memcpy(maxconf,conf,sizeof(int)*n);
	double mind = tspdistance(tsp,conf,6);
    int cnt;
	for (cnt=1; next_config(conf,ccc,n); ++cnt) {
        double d = tspdistance(tsp,conf,6);
        if (d<mind) {
            mind = d;
            memcpy(maxconf,conf,sizeof(int)*n);
        }
	}
	cout<<"n="<<n<<endl;
	cout<<cnt<<"=(n-1)!"<<endl;
	cout<<"Best config:"<<endl;
	print(maxconf,n);
	print_conf(maxconf,tspnodes,n);
	cout<<"Best distance: "<<mind<<endl;
}
