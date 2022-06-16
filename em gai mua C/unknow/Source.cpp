#include<stdio.h>
#include<conio.h>
#include"console.h"
#include<windows.h>
#include<time.h>
#include<MMsystem.h>
#pragma comment (lib,"winmm.lib")

void getDate()
{
	int kitu8=147,kitu2=133;
	time_t     now;
    struct tm  ts;
    char buf[80];
    time(&now);
    ts = *localtime(&now);
    strftime(buf, sizeof(buf), "%A %d-%m-%Y %H:%M:%S", &ts);
	TextColor(250);
	Sleep(2000);
    printf("                   H%cm nay l%c: %s , TPHCM\n",kitu8,kitu2, buf);
}
void PlayMusic()
{
	PlaySound(TEXT("intro.wav"), NULL,SND_ASYNC);
}
void main()
{
	SetConsoleTitle(L"Em gái mưa-Mr.siro");
	
	system("color f0");
	int kitu1=229,kitu2=133,kitu3=136,kitu4=130,kitu5=131,kitu7=151,kitu8=147,kitu6=149;
	PlayMusic();
	getDate();
	
    Sleep(3400); 
	TextColor(245);
	printf("\n\n\n                   Don't touch mouse or keyboard",kitu1);
	Sleep(3400);
	TextColor(240);
	printf("                   Copyright © 2019 by NGUYEN VAN QUANG",kitu1);
	Sleep(3500);
	printf("                 Music:   Em gai mua- MR.Siro PRESENT BY: MR.SIRO\n\n");
	Sleep(3500);
	printf("                                               ");
	Sleep(3200);
	clrscr();
	TextColor(245);
	printf("   ");
	Sleep(3500);
	TextColor(241);
	printf("                             ");
	Sleep(3400);
	TextColor(250);
	printf("                                                              ");
	Sleep(3500);
	TextColor(248);
	printf("                                         ");
	Sleep(3500);
	TextColor(244);
	printf("                      ");
	Sleep(1800);
	TextColor(244);
	printf("                       DEV with the legend name:  B%c G%cu!\n\n\n\n",kitu4,kitu5);
	Sleep(1500);
	TextColor(244);
	printf("                             ");
	Sleep(3500);
	clrscr();
	TextColor(245);
	printf("                           ");
	Sleep(3500);
	printf("                           ");
	Sleep(3500);
	printf("                          ");
	Sleep(3500);
	printf("                          ");
	Sleep(3000);
	printf("                          ");
	Sleep(3000);
	printf("                           ");
	Sleep(3500);
	printf("                        ");
	Sleep(3500);
	printf("                         ");
	Sleep(3500);
	printf("                          ");
	Sleep(3500);
	printf("                          ");
	Sleep(3500);
	printf("                           ");
	Sleep(3500);
	
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	PlaySound(NULL, NULL,SND_ASYNC);
}