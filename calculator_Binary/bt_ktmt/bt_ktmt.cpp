#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include "console.h"
#include<stdlib.h>

#define Size 129
int nhapN();
int nhapNMau();
void xuat(int a[], int bit);
void xuat1(int a[], int bit);
void xuat2(int a[], int bit);
void chuyenDoiSoNhiPhan(int a[], int n, int bit, int mang[]);
void chuyenDoiSoNhiPhanDeChia(int a[], int n, int bit, int mang1[]);
int nhapBit();
int cong2so(int a[], int b[], int c[], int bit, int& h);
void taoMang1(int mang1[], int bit);
void timSoBu2(int a[], int sb2[], int bit, int mang1[]);
void nhan2soKhongDau(int M[], int Q[], int bit);
int nhapNduong();
void chinhDau(int A[], int Q[], int Qbandau[], int M[], int bit, int mang1[]);
void chia2so(int M[], int Qbandau[], int bit, int mang1[], int sb2[]);

int nhapNduong()
{
	int n;
	do
	{
		scanf_s("%d", &n);
		if (n < 0)
			printf("vui long nhap lai so nguyen duong: ");
	} while (n < 0);
	return n;
}
int nhapNMau()
{
	int n;
	scanf_s("%d", &n);
	if (n == 0)
		do
		{
			printf("phep chia khong xac dinh!\nvui long nhap lai n= ");
			scanf_s("%d", &n);
		} while (n == 0);
		return n;
}
int nhapN()
{
	int n;
	scanf_s("%d", &n);
	return n;
}
void xuat(int a[], int bit)
{
	for (int i = 0; i < bit; i++)
	{
		printf("%2d", a[i]);
	}
	_getch();
}
void xuat1(int a[], int bit)
{
	for (int i = 1; i < bit; i++)
	{
		printf("%2d", a[i]);
	}
	_getch();
}
void xuat2(int a[], int bit)
{
	for (int i = 0; i < bit - 1; i++)
	{
		printf("%d", a[i]);
	}
}
void chuyenDoiSoNhiPhanDeChia(int a[], int n, int bit, int mang1[])
{
	int soDu, v = 0;
	if (n < 0)
	{
		n = (-1) * n;
		v = 1;
	}
	for (int i = bit - 1; i >= 0; i--)
	{
		if (n > 0)
		{
			soDu = n % 2;
			a[i] = soDu;
			n = n / 2;
		}
		else
			a[i] = 0;
	}
}
void chuyenDoiSoNhiPhan(int a[], int n, int bit, int mang1[])
{
	int soDu, v = 0;
	if (n < 0)
	{
		n = (-1) * n;
		v = 1;
	}	
	for (int i = bit - 1; i >= 0; i--)		//add số dư từ cuối mảng a vì lấy số dư từ dưới lên
	{		
		if (n > 0)
		{
			soDu = n % 2;
			a[i] = soDu;
			n = n / 2;
		}
		else
			a[i] = 0;
	}
	if (v == 1)
	{
		timSoBu2(a, a, bit, mang1);
	}
}
int nhapBit()
{
	int bit;
	TextColor(249);
	printf("nhap so bit muon chuyen doi: ");
	scanf_s("%d", &bit);
	return bit;
}
int cong2so(int a[], int b[], int c[], int bit, int& h)			//a[] là mảng chứa số thứ nhất ở dạng nhị phân, b[] là số còn lại
{															//c[] là tổng
	int i = bit - 1, temp;								//h la bien memmory,i la bien dem
	for (int o = bit - 1; o >= 0; o--)
	{
		if (i >= 0)
		{
			temp = (h + a[i]);
			if (h > 0)
				h = 0;
			if (temp > 1)
			{
				temp = 0;
				h++;
			}
			c[o] = temp + b[i];
			if (c[o] > 1)
			{
				c[o] = 0;
				h++;
			}
			i--;
		}
	}
	return 0;
}
void taoMang1(int mang1[], int bit)
{
	mang1[bit - 1] = 1;
	for (int i = 0; i < bit - 1; i++)
	{
		mang1[i] = 0;
	}
}
void taoMang0(int mang0[], int bit)
{
	for (int i = 0; i < bit; i++)
	{
		mang0[i] = 0;
	}
}
void timSoBu2(int a[], int sb2[], int bit, int mang1[])
{
	int copy[Size], h = 0;
	for (int i = 0; i < bit; i++)
	{
		copy[i] = a[i];
	}
	for (int i = 0; i < bit; i++)
	{
		if (copy[i] == 0)
			copy[i] = 1;
		else
			copy[i] = 0;
	}
	cong2so(copy, mang1, sb2, bit, h);
}
void capNhatCaculation(int caculation[], int A[], int C, int bit)
{
	for (int k = 0; k < (bit * 2) + 1; k++)
	{
		if (k == 0)
			caculation[0] = C;
		if (k > 0 && k < bit + 1)
			caculation[k] = A[k - 1];
	}
}
void reload(int caculation[], int A[], int& C, int bit)
{
	for (int i = 0; i < (bit * 2) + 1; i++)
	{
		if (i == 0)
			C = caculation[i];
		if (i > 0 && i < bit + 1)
			A[i - 1] = caculation[i];
	}
}
void reload2(int multiply[], int A[], int bit)
{
	for (int i = 0; i < bit; i++)
	{
		if (i >= 0 && i < bit)
			A[i] = multiply[i];
	}
}
void reload3(int share[], int A[], int Q[], int bit)
{
	for (int j = 0; j < bit * 2; j++)
	{
		if (j < bit)
			A[j] = share[j];							// gán A,Q vào
		else
			Q[j - bit] = share[j];
	}
}
void nhan2soKhongDau(int M[], int Q[], int bit)
{
	int C = 0;
	int A[Size];
	taoMang0(A, bit);
	printf("\ngia tri cua A: ");
	xuat(A, bit);
	int caculation[100], dem = 0;
	for (int i = 0; i < (bit * 2) + 1; i++)
	{
		if (i == 0)								//gán C bằng bit dấu của dãy
			caculation[i] = C;
		if (i > 0 && i < bit + 1)
			caculation[i] = A[i - 1];					//gán A vào dãy
		if (i >= bit + 1 && i < (bit * 2) + 1)
			caculation[i] = Q[i - bit - 1];			//gán Q vào dãy

	}
	printf("\ngia tri cua caculation: ");
	xuat(caculation, (bit * 2) + 1);
	for (int d = 0; d < bit; d++)
	{
		printf("\nvong %d: ", d + 1);
		if (caculation[bit * 2] == 1)						// nếu Q(0)=1, A=A+M
		{
			printf("\nQ(0)=1 nen A=A+M: ");
			cong2so(A, M, A, bit, C);
			capNhatCaculation(caculation, A, C, bit);
			xuat(caculation, (bit * 2) + 1);
			dem = 1;
		}

		printf("\n dich phai:       ");
		for (int j = (bit * 2); j >= 0; j--)						// dịch phải
		{
			if (j == 1)
				caculation[j] = C;
			if (j == 0)
				caculation[j] = 0;
			else
				caculation[j] = caculation[j - 1];
		}
		reload(caculation, A, C, bit);
		xuat(caculation, (bit * 2) + 1);
	}
	printf("\nKet qua: Tich cua 2 so = ");
	xuat1(caculation, (bit * 2) + 1);
	_getch();
}
void capNhatMultiply(int multiply[], int A[], int bit)
{
	for (int i = 0; i < (bit * 2) + 1; i++)
	{
		if (i >= 0 && i < bit)
			multiply[i] = A[i];
	}
}
void nhan2soCoDau(int M[], int Q[], int bit, int mang1[], int sb2[])
{
	int h = 0;
	int A[Size], Q1 = 0, multiply[257];
	taoMang0(A, bit);
	timSoBu2(M, sb2, bit, mang1);



	for (int i = 0; i < (bit * 2) + 1; i++)
	{
		if (i >= 0 && i < bit)
			multiply[i] = A[i];
		if (i >= bit && i < (bit * 2))
			multiply[i] = Q[i - bit];
		else
			multiply[i] = Q1;
	}
	printf("\ngia tri cua multiply la: ");
	xuat(multiply, (bit * 2) + 1);



	for (int k = 0; k < bit; k++)
	{
		printf("\nvong %d:", k + 1);
		if (multiply[(bit * 2) - 1] == 0 && multiply[bit * 2] == 1)					// nếu Q(0)Q(-1)=01, A=A+M
		{
			printf("\nQ(0)Q(-1)=01, A=A+M: ");
			if (h != 0)
				h = 0;
			cong2so(A, M, A, bit, h);
			capNhatMultiply(multiply, A, bit);
			xuat(multiply, (bit * 2) + 1);
		}
		if (multiply[(bit * 2) - 1] == 1 && multiply[bit * 2] == 0)					// nếu Q(0)Q(-1)=10, A=A-M
		{
			printf("\nQ(0)Q(-1)=10, A=A-M: ");
			if (h != 0)
				h = 0;
			cong2so(A, sb2, A, bit, h);
			capNhatMultiply(multiply, A, bit);
			xuat(multiply, (bit * 2) + 1);
		}
		printf("\ndich phai: ");								// Q(0)Q(-1)=00||11, dịch phải
		for (int l = (bit * 2); l > 0; l--)
		{
			multiply[l] = multiply[l - 1];
		}
		if (multiply[1] == 0)
			multiply[0] = 0;
		if (multiply[1] == 1)
			multiply[0] = 1;
		reload2(multiply, A, bit);
		xuat(multiply, (bit * 2) + 1);
	}
	printf("\nKet qua: Tich cua 2 so = ");
	xuat2(multiply, (bit * 2) + 1);
	_getch();
}
void capNhatShare(int share[], int A[], int Q[], int bit)
{
	for (int j = 0; j < bit * 2; j++)
	{
		if (j < bit)
			share[j] = A[j];							// cập nhật A,Q
		else
			share[j] = Q[j - bit];
	}
}
void copy(int a[], int b[], int bit)
{
	for (int i = 0; i < bit; i++)
	{
		a[i] = b[i];
	}
}
void chia2so(int M[], int Qbandau[], int bit, int mang1[], int sb2[])
{
	int A[Size], share[129], h = 0, Q[Size];
	copy(Q, Qbandau, bit);
	taoMang0(A, bit);
	timSoBu2(M, sb2, bit, mang1);




	for (int j = 0; j < bit * 2; j++)
	{
		if (j < bit)
			share[j] = A[j];							// gán A,Q vào
		else
			share[j] = Q[j - bit];
	}
	printf("\ngia tri cua share: ");
	xuat(share, bit * 2);
	for (int i = 0; i < bit; i++)
	{
		printf("\nvong %d", i + 1);
		printf("\ndich trai:       ");



		for (int k = 0; k < bit * 2; k++)				// dịch trái
		{
			if (k == (bit * 2) - 1)
			{
				share[k] = 0;
			}
			else
				share[k] = share[k + 1];
		}
		reload3(share, A, Q, bit);
		xuat(share, bit * 2);
		if (h != 0)
			h = 0;
		printf("\nA= ");
		xuat(A, bit);
		printf("\n-M= ");
		xuat(sb2, bit);
		printf("\nA=A-M: ");
		if (h != 0)
			h = 0;											//A=A-M
		cong2so(A, sb2, A, bit, h);
		if (h != 0)
			h = 0;
		capNhatShare(share, A, Q, bit);
		xuat(share, bit * 2);
		if (A[0] == 1)									//nếu A<0, A=A+M, Q(0)=0
		{
			printf("\nA<0 nen A=A+M,Q(0)=0: ");
			Q[bit - 1] = 0;
			if (h != 0)
				h = 0;
			cong2so(A, M, A, bit, h);
			if (h != 0)
				h = 0;
			capNhatShare(share, A, Q, bit);
			xuat(share, bit * 2);
		}
		else										//Q(0)=1
		{
			printf("\nA!<0 nen Q(0)=1: ");
			Q[bit - 1] = 1;
			capNhatShare(share, A, Q, bit);
			xuat(share, bit * 2);
		}
	}
	
	printf("\nKet qua:");
	printf("\n\n	Thuong cua 2 so = Q= ");
	xuat(Q, bit);
	printf(", so du=A=  ");
	xuat(A, bit);
	_getch();
}
void chinhDau(int A[], int Q[], int Qbandau[], int M[], int bit, int mang1[])
{
	if (Qbandau[0] == 0 && M[0] == 1)
	{
		timSoBu2(Q, Q, bit, mang1);
	}
	if (Qbandau[0] == 1 && M[0] == 0)
	{
		timSoBu2(Q, Q, bit, mang1);
	}
	if (Qbandau[0] == 1)
		timSoBu2(A, A, bit, mang1);
}
void main()
{
	system("color f0");
	int a[Size], b[Size], c[Size];						//   mảng a chứa số thứ nhất, mảng b chứa số thứ hai, mảng c là kết quả
	int sb2[Size], mang1[Size];						//   mảng sb2 chứa số bù 2, mảng mang1 chứa giá trị nhị phân của số 1
	int bit = nhapBit(), chon, h = 0;
	do
	{
		taoMang1(mang1, bit);
		int s = 179;
		TextColor(250);
		printf(" __________________________________________________________________________");
		printf("\n|-------------------------------------------------------------------------|");
		printf("\n|-------------------------------WELLCOME----------------------------------|");
		printf("\n|-------------------------------------------------------------------------|");
		TextColor(246);
		printf("\n|         Xin moi chon chuc nang:                                         |");
		TextColor(241);
		printf("\n| 1> Cong 2 so nguyen o dang so nhi phan:                                 |");
		TextColor(242);
		printf("\n| 2> Tru 2 so nguyen o dang so nhi phan:                                  |");
		TextColor(253);
		printf("\n| 3> Nhan 2 so nguyen <khong dau> o dang so nhi phan:                     |");
		TextColor(244);
		printf("\n| 4> Nhan 2 so nguyen bat ki o dang so nhi phan( giai thuat booth):       |");
		TextColor(252);
		printf("\n| 5> Chia 2 so nguyen bat ki o dang so nhi phan:                          |");
		TextColor(249);
		printf("\n| 9> Nhap lai so bit:                                                     |");
		TextColor(245);
		printf("\n| 0> EXIT                                                                 |");
		TextColor(248);
		printf("\n| Lua chon cua ban la: ");
		scanf_s("%d", &chon);
		TextColor(250);
		printf(" \n__________________________________________________________________________\n");
		TextColor(240);
		switch (chon)
		{
		case 1:

			printf("\nnhap so bi cong: ");
			chuyenDoiSoNhiPhan(a, nhapN(), bit, mang1);
			printf("\nnhap so cong: ");
			chuyenDoiSoNhiPhan(b, nhapN(), bit, mang1);
			printf("\ngia tri cua so bi cong o dang nhi phan: ");
			xuat(a, bit);
			printf("\ngia tri cua so cong o dang nhi phan:    ");
			xuat(b, bit);
			cong2so(a, b, c, bit, h);
			if (h == 1)
				h = 0;
			printf("\nTong 2 so o dang nhi phan=              ");
			xuat(c, bit);
			break;
		case 2:

			printf("\nnhap so bi tru: ");
			chuyenDoiSoNhiPhan(a, nhapN(), bit, mang1);
			printf("\nnhap so tru: ");
			chuyenDoiSoNhiPhan(b, nhapN(), bit, mang1);
			printf("\ngia tri cua so bi tru o dang nhi phan:   ");
			xuat(a, bit);
			printf("\ngia tri cua so tru o dang nhi phan:      ");
			xuat(b, bit);
			timSoBu2(b, sb2, bit, mang1);
			cong2so(a, sb2, c, bit, h);
			if (h == 1)
				h = 0;
			printf("\nHieu 2 so o dang nhi phan=               ");
			xuat(c, bit);
			break;
		case 3:

			printf("\nnhap so bi nhan: ");
			chuyenDoiSoNhiPhan(a, nhapNduong(), bit, mang1);
			printf("\nnhap so nhan: ");
			chuyenDoiSoNhiPhan(b, nhapNduong(), bit, mang1);
			printf("\ngia tri cua so bi nhan o dang nhi phan:  ");
			xuat(a, bit);
			printf("\ngia tri cua so nhan o dang nhi phan:     ");
			xuat(b, bit);
			nhan2soKhongDau(a, b, bit);
			break;
		case 4:

			printf("\nnhap so bi nhan: ");
			chuyenDoiSoNhiPhan(a, nhapN(), bit, mang1);
			printf("\nnhap so nhan: ");
			chuyenDoiSoNhiPhan(b, nhapN(), bit, mang1);
			printf("\ngia tri cua so bi nhan o dang nhi phan:  ");
			xuat(a, bit);
			printf("\ngia tri cua so nhan o dang nhi phan:     ");
			xuat(b, bit);
			nhan2soCoDau(a, b, bit, mang1, sb2);
			break;
		case 5:
			printf("\nnhap so bi chia: ");
			chuyenDoiSoNhiPhanDeChia(a, nhapN(), bit, mang1);
			printf("\nnhap so chia: ");
			chuyenDoiSoNhiPhanDeChia(b, nhapNMau(), bit, mang1);
			printf("\ngia tri cua so bi chia o dang nhi phan:  ");
			xuat(a, bit);
			printf("\ngia tri cua so chia o dang nhi phan:     ");
			xuat(b, bit);
			chia2so(b, a, bit, mang1, sb2);
			break;
		case 0:
			return;
			break;
		case 9:
			bit = nhapBit();
			break;
		default:
			break;
		}
		clrscr();
	} while (1);
	_getch();
}