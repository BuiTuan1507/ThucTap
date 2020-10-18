#include<iostream>
using namespace std;


int N; // N so tu nhien
int result = 1;
void input(){
	cin>>N;
}
void giaithua(int N){
	for (int i = 2; i<=N; i++){
		result = result * i;
	}
}
void output(){
	cout<<result;
}
int main(){
	
	input();
	giaithua(N);
	output();
	return 0;
}
