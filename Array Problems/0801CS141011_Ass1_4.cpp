#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#define MAX_SIZE 1000000
using namespace std;

int digits(int i)
{
    return i > 0 ? (int) log10((double) i) + 1 : 1;
}
		

double bisection(double a,double b){
	double EPS=1E-15 ,c=1/b,f0,f1,x2;
	double x0=1,x1=2;
	while(1){

		f0=pow(x0,c)-a;
		f1=pow(x1,c)-a;
		x2=(x1+x0)/2;
		if(f0*f1<0)
			x1=x2;
		else
			x0=x2;
		if(abs(x1-x0)<EPS) 
			 break ;
		}
	return x2;	
}


double regulaFalsi(double a,double b){
	double EPS = 1E-15 ,c=1/b;
	double x0=1,x1=2,x2;
	while(1){
		x2=x0-(pow(x0,c)-a)/(pow(x1,c)-pow(x0,c))*(x1-x0);
		if(abs(x2-x0)<EPS) 
			 break ;
		x0=x2;
		}
	return x2;
}


double newtonRapson(double a,double b){
	double EPS = 1E-15 ,c=1/b;
	double x0=1,x1;
	while(1){
		x1=x0-x0*b*(1-a*pow(x0,-(int)c));
		if(abs(x1-x0)<EPS) 
			 break ;
		x0=x1 ;
		}
	return x1;	
}

int main()  
{
	double n,x,a,b,ans=1,flag=0;
	cin>>a>>b;
	if(b<0.0){
		flag=1;
		b=abs(b);
	}
	int	d=digits((int)b);
	d=pow(10,d);

// Approach 1: By Newton Rapson Method
	if(b<1.0)
		ans=newtonRapson(a,b);
	else{
		if(b==(b-(int)b/d))
			ans=pow(a,b);
		else
			ans=ans*newtonRapson(a,b-b/d);
	}
	if(flag==1)
		ans=1/ans;
	printf("By Newton Rapson Method : a to the power b is %.15lf\n",ans);
	
// Approach 2: By Regula Falsi Method

	ans=1;
	if(b<1.0)
		ans=regulaFalsi(a,b);
	else{
		if(b==(b-(int)b/d))
			ans=pow(a,b);
		else
			ans=ans*regulaFalsi(a,b-b/d);
	}
	if(flag==1)
		ans=1/ans;
	printf("By Regula Falsi Method : a to the power b is %.15lf\n",ans);

// By Iterative Bisection
	
	ans=1;
	if(b<1.0)
		ans=bisection(a,b);
	else{
		if(b==(b-(int)b/d))
			ans=pow(a,b);
		else
			ans=ans*bisection(a,b-b/d);
	}
	if(flag==1)
		ans=1/ans;
	printf("By Iterative bisection Method : a to the power b is %.15lf\n",ans);

	return 0;
}