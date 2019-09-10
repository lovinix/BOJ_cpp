#include <iostream>
using namespace std;
int main(){
	double m=0;int x;
	for(int i=0;i<3;++i){
		double a,b,c;
		cin>>a>>b;
		a*=10,b*=10;
		if(a>=5000)a-=500;
		c=b/a;
		if(m<=c)m=c,x=i;}
	cout << "SNU"[x];}