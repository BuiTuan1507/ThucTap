#include<stdio.h>
#include<conio.h>

int n;

int main(){
	do{
		printf("nhap so n: ");
		scanf("%d",&n);
	}while (n<=0);
	printf("ban da nhap so nguyen duong : %d", n);
	return 0;

}
