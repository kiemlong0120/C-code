#include<stdio.h>
#include<conio.h>
#include<string.h>


int tinhChieuDaiChuoi(char chuoi[], int dem, int i)
{
	if (i<strlen(chuoi))
	{
		i++;
		dem++;
		return tinhChieuDaiChuoi(chuoi, dem, i);
	}
	else
	{
		return dem;
	}
}

int inChuoiDaoNguoc(char chuoi[], int i)
{
	if (i >= 0)
	{
		printf("%c", chuoi[i]);
		i--;
		return inChuoiDaoNguoc(chuoi, i);
	}
}

void clearBuffer()
{

	//	clearing the input buffer
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		fflush(stdin);
	//
}

void main()
{
	clearBuffer();
	char chuoi[100];
	int doDaiCuaChuoi;

	printf("\nNhap vao chuoi: ");
	fflush(stdin);
	gets_s(chuoi);

	doDaiCuaChuoi = tinhChieuDaiChuoi(chuoi, 0, 0);

	printf("\ndo dai cua chuoi: %d",doDaiCuaChuoi);

	printf("\nIn chuoi dao nguoc:");
	inChuoiDaoNguoc(chuoi, strlen(chuoi)-1);

	_getch();


}