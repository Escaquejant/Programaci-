#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <utility>
#include <queue>
#include <deque>
#include <unordered_set>
#include <stack>
#include <map>

using namespace std;

#define ll long long int
#define ffor(i,j,n) for(ll i=j;i<n;++i)
#define fforr(k,a,b) for(ll k=b-1; k>=a;k--)
#define ffors(el, obj) for(const auto& el: obj)
#define fform(el, obj) for(auto el=obj.begin(); el != obj.end(); el++)
    // el->first, el->second
#define ffind(el, valor) (el.find(valor)!=el.end())
#define all(v) v.begin(), v.end()

int processa(vector <ll> &v, ll resp, vector<string> &vs) {
    vs.push_back("");
    vector <ll> v0=v;
    sort(all(v0));
    ffor(i,0,v0.size()-1) {
        ffor(j,i+1  ,v0.size()) {
                vector <ll> vv;
                ffor(k,0,v0.size()) {
                    if (k!=i && k!=j) vv.push_back(v0[k]);
                }
                vv.push_back(0);
                ffor(k,0,4) {
                    stringstream  ss;
                    ll dada;
                    char oper;
                    switch(k) {
                        case 0: dada=v0[i]+v0[j]; oper='+'; break;
                        case 1: dada=v0[j]-v0[i]; oper='-';  break;
                        case 2: dada=v0[i]*v0[j]; oper='*';  break;
                        case 3: if (v[i])
                            dada=(v0[i]%v0[j]?0:v0[j]/v0[i]);  oper='/'; break;
                    }
                    if (dada!=0) {
                        vv[vv.size()-1]=dada;
                        ss << v0[j] << " " << oper << " " << v0[i] << " = " << dada  ;
                        vs[vs.size()-1]=ss.str();
                        if (dada==resp) return 1;
                        if (vv.size()>=2)
                            if (processa(vv,resp,vs)) return 1;
                        
                    }
                }
        }
    }
    vs.pop_back();
    return 0;
}

void fesho0() {
    ll ai, resp;
    vector <ll> v;
    vector <string> vs;

    // Lee los 6 números
    ffor(i,0,6) {
        cin >> ai;
        v.push_back(ai);
    }

    // Lee el resultado
    cin >> resp;

    if (!processa(v,resp,vs)) {
        cout << "No existe solución" << endl;
    } else {
        cout << "(";
        ffor(kk,0,v.size())
            cout << " " << v[kk] << " ";
        cout << "-> " << resp << " )" << endl;

        ffor(i,0,vs.size()) {
            cout << vs[i] << endl;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    fesho0();
    return 0;
}