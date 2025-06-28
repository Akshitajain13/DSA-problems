#include <stdio.h>
#include <stdlib.h>
class Diagonal{
private:
int *A,n;
public:
Diagonal(){
n=2;
A=new int[2];}
Diagonal(int n){
this->n=n;
A=new int[n];}
~Diagonal(){
delete [ ]A;
}
void set( int I,int j,int x);
Int get(int I,int j);
void Display();
};
void Diagonal::set( int i,int j,int x){
If(i==j){
A[I-1]=x;}
}
int Diagonal :: get( int i,int j){
if(I==j) 
return A[i-1];
else
return 0;}
void Diagonal::Display(){
for (int i=0;i<m.n;i++){
for(int j=0;j<m.n;j++){
if(i==j)
cout<<A[I-1];
else
cout<<0;}
cout<<endl}
}

