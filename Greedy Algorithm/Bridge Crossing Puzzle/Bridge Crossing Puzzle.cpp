#include<iostream>

using namespace std;

int main()
{
	
int i=0,swap,position,arr[50],chkn[50],chkr[50],chk[50],idnfyarr[50],count,bp,np,finish=0,ntime=0,rtime=0,max,j,k,finish1=0,finish2=0,flag,time,idnfy=0;
cout<<"Enter number of people: ";
cin>>np;
cout<<"\nCapacity of boat: ";
cin>>bp;
if(bp==1)
{cout<<endl<<"No solution. Becuase,boat capacity is only one."<<endl;getch();exit(0);}
cout<<endl<<"Enter time:"<<endl;
for(i=0;i<np;i++)
cin>>arr[i];


 for (i= 0;i<np-1;i++)
   {
      position =i;
 
      for (j= i+1;j<np;j++)
      {
         if(arr[position]>arr[j])
            position=j;
      }
      if ( position != i )
      {
         swap =arr[i];
         arr[i] = arr[position];
         arr[position] = swap;
      }
   }


for(i=0;i<np;i++)
{
	chkn[i]=0;
}

for(i=0;i<np;i++)
{
	chkr[i]=0;
}

for(;finish!=np;)
{

for(i=0;i<bp;i++)	
{

chkn[0]=1;finish1++;count=1;
for(j=np-1;count<bp && j>=0;j--)
{

	if(chkn[j]==0)
	{
		chkn[j]=1;finish1++;
		if(count==1)  max=j;
		count++;
	
	}
    
    
}

ntime+=arr[max];

if(finish1==np) break;
else
{
chkn[0]=0;finish1--;
ntime+=arr[0];
}
}

// Second code

for(k=0;k<bp;k++)
{
	if(chkr[k]==0)
	{chkr[k]=1;finish2++;flag=k;}
	
}

rtime+=arr[flag];


if(finish2!=np){
for(i=0;i<bp;i++)	
{


for(k=0;k<bp;k++)
{
	
	if(chkr[k]==1) {chkr[k]=0;;rtime+=arr[k];finish2--;break;}
	
}

if(i==bp-1) break;

count=0;
for(j=np-1;count<bp && j>=0;j--)
{

	if(chkr[j]==0)
	{
		chkr[j]=1;finish2++;
		if(count==0)  max=j;
		count++;
	
	}
    
    
}

rtime+=arr[max];

if(finish2==np) break;


}
}


time=min(ntime,rtime);
if(time==ntime)
{
	rtime=time;
	
	for(i=0;i<np;i++)
	chkr[i]=chkn[i];
	
	idnfyarr[idnfy]=1;
	
}
else
{
	ntime=time;

	for(i=0;i<np;i++)
	chkn[i]=chkr[i];
	
	idnfyarr[idnfy]=2;

}

idnfy++;
finish=finish1;
if(finish==np) break;

}


cout<<endl;



// show the output
idnfy=0;finish=0;
for(i=0;i<np;i++)
{
	chk[i]=0;
}


for(;finish!=np;)
{
if(idnfyarr[idnfy]==1){

for(i=0;i<bp;i++)	
{
cout<<"Go: ";
chk[0]=1;cout<<arr[0]<<" ";finish++;count=1;
for(j=np-1;count<bp && j>=0;j--)
{

	if(chk[j]==0)
	{
		chk[j]=1;cout<<arr[j]<<" ";finish++;
		if(count==1)  max=j;
		count++;
	
	}
    
    
}

ntime+=arr[max];

if(finish==np) break;
else
{
chk[0]=0;cout<<endl<<"Return: "<<arr[0]<<endl;finish--;
ntime+=arr[0];
}


}

}
// Second code

if(idnfyarr[idnfy]==2) {
cout<<"Go: ";
for(k=0;k<bp;k++)
{
	if(chk[k]==0)
	{chk[k]=1;cout<<arr[k]<<" ";finish++;flag=k;}
	
}

rtime+=arr[flag];


if(finish!=np){
for(i=0;i<bp;i++)	
{


for(k=0;k<bp;k++)
{
	
	if(chk[k]==1) {chk[k]=0;cout<<endl<<"Return: "<<arr[k]<<endl;rtime+=arr[k];finish--;break;}
	
}

if(i==bp-1) break;

count=0;
cout<<"Go: ";
for(j=np-1;count<bp && j>=0;j--)
{

	if(chk[j]==0)
	{
		chk[j]=1;cout<<arr[j]<<" ";finish++;
		if(count==0)  max=j;
		count++;
	
	}
    
    
}

rtime+=arr[max];

if(finish==np) break;


}
}

}
idnfy++;
if(finish==np) break;

}



cout<<endl<<endl<<"Minimum time required: "<<time<<endl<<endl;



return 0;	
}


