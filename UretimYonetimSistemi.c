#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define ENTER 13
#define BKSP 8
#define SPACE 32
#define TAB 9

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
//	SetConsoleTextAttributes(hStdOut,wColor);
	SetConsoleTextAttribute(hStdOut,wColor);

}
}


struct item
{
	char productname[40],productcomp[40],c;
	int productid;
	int price;
	int Qnt;
}st;

void wel_come(void);
void title(void);
void login();
void menu(void);
void title(void);
void deleteproduct(void);
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void add_item();
void read_item();
void search_item();
void edit_item();
void main(void)

{
wel_come(); //call for welcome screen function
login(); //call for login function
}



void wel_come(void)

{
	time_t t;
	time(&t);
	printf("                                                                                                         \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s",ctime(&t));
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t|    URUN YONETIM SISTEMI \t |\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t|\t  KONSOL UYGULAMASI \t |\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t\t|\n");

	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|Devam etmek icin herhangi bir tusa basin.........\t\t\t\t\t\t\t\t\t\t|\n");

	printf("---------------------------------------------------------------------------------------------------------\n");

getch();
system("cls");
}

void login()
{

int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="1234";
    do
{

    printf("\n  ========================  GIRIS   ========================  ");
    printf(" \n                        KULLANICI ADI:-");
	scanf("%s", &uname);
	printf(" \n                        SIFRE:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"admin")==0 && strcmp(pword,"1234")==0)
	{
	printf("  \n\n\n       BASARILI GIRIS, HOSGELDINIZ..");
	printf("\n\n\n\t\t\t\tDevam etmek icin herhangi bir tusa basin...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        YANLIS KULLANICI ADI YA DA SIFRE");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\n 4 kere yanlis girdiginiz icin bloke edildiniz!!!");

		getch();

		}
		system("cls");
		menu();
}



void menu(void)
{
	int choice;
	system("cls");
	main:
	printf("\n======================== URUN YONETIM SISTEMI ========================");
	printf("                                                                                          ");
	printf("                                                                                          ");
	printf("\n\t\tPress <1> URUN EKLE ");
	printf("\n\t\tPress <2> URUN SIL ");
	printf("\n\t\tPress <3> URUN ARA");
	printf("\n\t\tPress <4> URUN LISTESI");
	printf("\n\t\tPress <5> URUN DUZENLE");
	printf("\n\t\tPress <6> CIKIS YAP!");

	printf("\n\n\t\tSECIMINIZI GIRIN[1-6]");
	scanf("%i", &choice);

	system("cls");

	switch(choice)
	{
		case 1:
			add_item();
			break;
		case 2:
			deleteproduct();
			break;
		case 3:
		search_item();
			break;
		case 4:
		read_item();
			break;
		case 5:
			edit_item();
			break;
		case 6:
		printf("SISTEM CIKISI...");
		exit(0);
		break;


		default:
		printf("GECERSIZ INPUT! SISTEM CIKISI\n");
			getch();
	}

}

void add_item()
{
	int index, valid;
	char c;
	int a=0;

	FILE *fp;


	do
	{
		system("cls");
		printf("============ URUN DETAYLARINI GIRIN ============");
		int ID;//for comparing staff ID if file isnot NULL
		//declaration of file variable named as sfile
		fp = fopen("NextFile.dat","a+");//opening file and creating a staff.txt file to append or write

		if((fp = fopen("NextFile.dat","a+"))!=NULL)//if condition to check file is NULL or not
		{
			I:
			printf("\nURUN KODU:\t :");
			scanf("%i",&ID);
			while(fscanf(fp,"%s %s %i %i %i", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt)!=EOF)
			{
				/*
				fscanf reads every data stored in the file
				if entered staffID already exist then jumps to
				position I declared inside if(sfile!=NULL) at top
				*/
				if(ID == st.productid)
				{
					printf("\n\tBU KOD ZATEN MEVCUT, BASKA BIR KOD GIRINIZ.\n");
					goto I;
				}
			}
			st.productid = ID;
		}
		else//runs if sfile is empty
		{
			printf("\t URUN KODU\t :");
			scanf("%i",&st.productid);
		}

	//add product name
		do
		{

			//printf("<<<<<<<<<<<<<<Enter Product Detail>>>>>>>>>>>>>");
			fflush(stdin);
			printf("\nURUN AD\t :");
			gets(st.productname); // get input string
			st.productname[0]=toupper(st.productname[0]);
			//iterate for every character in string
			for (index=0; index<strlen(st.productname); ++index)
			{	//check if character is valid or not
				if(isalpha(st.productname[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n INGILIZCE KARAKTER OLARAK TEKRAR GIRINIZ:");
				getch();


			}
		}while(!valid);	//while end here


		//Product Company
			do
		{
			char productcomp[40];
			fflush(stdin);
			printf("\nURUN MARKASI\t :");
			gets(st.productcomp); // get input string
			st.productcomp[0]=toupper(st.productcomp[0]);
			//iterate for every character in string
			for (index=0; index<strlen(st.productcomp); ++index)
			{	//check if character is valid or not
				if(isalpha(st.productcomp[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n INGILIZCE KARAKTER OLARAK TEKRAR GIRINIZ");
				getch();


			}
		}while(!valid);

		//productid
		do
			{
				printf("\nKAC [10-5000] TL:");
				scanf("%i",&st.price);
				if(st.price<10 || st.price>5000)
				{
					printf("\n\t 10 ILE 5000 arasinda bir deger giriniz.");
				}
			}while(st.price<10 || st.price>5000);

				do
			{
				printf("\nKAC TANE [1-500]\t:");
				scanf("%i",&st.Qnt);
				if(st.Qnt<1 || st.Qnt>500)
				{
					printf("\n\tTekrar giriniz");
				}
			}while(st.Qnt<1 || st.Qnt>500);

	//	printf("\nProduct Price\t :");
	//	scanf("%i", &st.price);
		//printf("\nProduct ID\t :");
		//scanf("%i", &st.productid);
	//	printf("\nProduct Quantity :");
	//	scanf("%i",&st.Qnt);

		fp=fopen("NextFile.dat","a");
		fprintf(fp,"\n%s %s %i %i %i", st.productname, st.productcomp,st.price, st.productid,st.Qnt);
		fclose(fp);
		printf("\n baska bir urun eklemek icin enter a ana menuye donmek icin herhangi bir tusa basiniz");

	}
	while((c = getch()) =='\r');
	menu();
}


void search_item()
{
	char target[40];
	int found=0;
	FILE *sfile;
	sfile=fopen("NextFile.dat","r");
	printf("\n Aratmak icin urun ismi giriniz:");
	fflush(stdin);
	gets(target);
	target[0]=toupper(target[0]);
	//
	while (!feof(sfile) && found==0)
	{
		fscanf(sfile,"%s %s %i %i %i", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt);
		if(strcmp(target, st.productname)==0)
		{
			found=1;
		}
	}

	if(found)
	{
		printf("\n Kayit bulundu");
		printf("\nUrun Adi\t\t:%s  \nMarkasi\t\t:%s \nFiyati\t\t:%i \nUrun ID\t\t:%i \nKac tane\t:%i", st.productname, st.productcomp, st.price, st.productid, st.Qnt);

	}
	else
		printf("kayit bulunamadi");
		fclose(sfile);
		printf("\nana menuye donmek icin herhangi bir tusa basiniz");
		while((st.c = getch()) =='\r');
		menu();

}

void deleteproduct(void)
{
	char target[40];
	int found=0;
	FILE *sfile, *tfile;
	sfile=fopen("NextFile.dat","r");
	tfile=fopen("TempFile.dat","w+");
	printf("\n silinecek urun icin isim giriniz: ");
	fflush(stdin);
	scanf("%s",target);
	target[0]=toupper(target[0]);
	while (fscanf(sfile,"%s %s %i %i %i\n",st.productname,st.productcomp, &st.price,&st.productid,&st.Qnt)!=EOF)
	{
		if(strcmp(target,st.productname)==0)
		{
			found=1;
		}
		else
		{
			fprintf(tfile,"%s %s %i %i %i\n", st.productname,st.productcomp, st.price,st.productid,st.Qnt);
		}
	}
			if(!found)
			{
				printf("\n kayit bulunamadi");
				getch();
				menu();
			}
			else
			{
				printf("\n kayit basariyla silindi.");
			}
			fclose(sfile);
			fclose(tfile);
			remove("NextFile.dat");
			rename("TempFile.dat","NextFile.dat");

			printf("\n Ana menuye donmek icin herhangi bir tusa basiniz");
		while((st.c = getch()) =='\r');
		menu();
}

void read_item()
{
	FILE *f;
	int i, q;
	if((f=fopen("NextFile.dat","r"))==NULL)
	{

		gotoxy(10,3);
		printf("kayýt bulunamadý");
		printf("\n\t\t Ana menuye donmek icin herhangi bir tusa basiniz");
		getch();
		menu();


	}
	else
	{

		gotoxy(0,5);
			for(i=0;i<100;i++)
		{
			printf("-");
		}
		gotoxy(5,6);
		printf("URUN ADI");
		gotoxy(25,6);
		printf("URUN FIYATI");
		gotoxy(40,6);
		printf("URUN MARKASI");
		gotoxy(60,6);
		printf("URUN KOD");
		gotoxy(80,6);
		printf("KAC TANE\n");

		for(i=0;i<100;i++)
		{
			printf("-");
		}
		q=8;
		while(fscanf(f,"%s %s %i %i %i\n", st.productname,st.productcomp, &st.price, &st.productid,&st.Qnt)!=EOF)
		{
			gotoxy(5,q);
			printf("%s",st.productname);
			gotoxy(25,q);
			printf("%i",st.price);
			gotoxy(40,q);
			printf("%s",st.productcomp);
			gotoxy(60,q);
			printf("%i",st.productid);
			gotoxy(80,q);
			printf("%i",st.Qnt);

			q++;
		}
		printf("\n");
		for(i=0;i<100;i++)
			printf("-");
	}
	fclose(f);

	printf("\nAna menuye donmek icin herhangi bir tusa basiniz");
		//while((st.c = getch()) =='\r');
		getch();
		menu();
}

void edit_item()
{
	int index, valid;
	char target[40];
	FILE *fp, *rp;
	int a=0;
	int id;
	char edit;
	long int size=sizeof(st);
	if((fp=fopen("NextFile.dat","r+"))==NULL)
	{
		printf("hýcbýr kayýt eklenemedi.");
		menu();
	}
	else
	{
		rp = fopen("TempFile.dat","a");
		system("cls");
		printf("duzenlemek icin urun kodunu giriniz");
		scanf("%i",&id);
		fflush(stdin);
		while(fscanf(fp,"%s %s %i %i %i\n", st.productname,st.productcomp, &st.price, &st.productid,&st.Qnt)!=EOF)
		{
			if(id==st.productid)
			{

				a=1;
				printf("\n\t*****  Kayit bulundu  *****");
				printf("\nUrun adi\t\t: %s",st.productname);
				printf("\nUrun markasi\t\t: %s",st.productcomp);
				printf("\nFiyatý\t\t\t: %i",st.price);
				printf("\nUrun kodu:\t\t: %i",st.productid);
				printf("\nKac tane:\t:%i",st.Qnt);

				printf("\n\n\t*** Yeni Kayit ***");
			do
				{

					fflush(stdin);
					printf("\nYeni urun adi\t\t: ");
					gets(st.productname); // get input string
					st.productname[0]=toupper(st.productname[0]);
					//iterate for every character in string
					for (index=0; index<strlen(st.productname); ++index)
					{	//check if character is valid or not
						if(isalpha(st.productname[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n INGILIZCE KARAKTER OLARAK TEKRAR GIRINIZ");
						getch();


					}
				}while(!valid);	//while end here


				//Product Company
				do
				{
					char productcomp[40];
					fflush(stdin);
					printf("\nYenni urun marka:\t\t:");
					gets(st.productcomp); // get input string
					st.productcomp[0]=toupper(st.productcomp[0]);
					//iterate for every character in string
					for (index=0; index<strlen(st.productcomp); ++index)
					{	//check if character is valid or not
						if(isalpha(st.productcomp[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("INGILIZCE KARAKTER OLARAK TEKRAR GIRINIZ");
						getch();


					}
				}while(!valid);

					do
			{
				printf("\Yeni Fiyat [10-5000]TL:");
				scanf("%i",&st.price);
				if(st.price<10 || st.price>5000)
				{
					printf("\n\tLUTFEN BELIRLENEN ARALIKTA BIR FIYAT GIRINIZ.");
				}
			}while(st.price<10 || st.price>5000);

				printf("\nYENI URUN KODU:\t\t:");
				scanf("%i",&st.productid);

				do
			{
				printf("\nKAC TANE [1-500]\t:");
				scanf("%i",&st.Qnt);
				if(st.Qnt<1 || st.Qnt>500)
				{
					printf("\n\tLUTFEN BELIRLENEN ARALIKTAKI SAYIDA URUN GIRINIZ.");
				}
			}while(st.Qnt<1 || st.Qnt>500);


				printf("ONAYLAMAK ICIN Y YE BASINIZ");
				edit=getche();
				if(edit=='y' || edit=='Y')
				{
					fprintf(rp,"%s %s %i %i %i\n", st.productname, st.productcomp, st.price, st.productid,st.Qnt);
					fflush(stdin);
					printf("\n\n\t\tBASARIYLA DUZENLENDI!!!");
				}
			}
			else
			{
				fprintf(rp,"%s %s %i %i %i\n", st.productname, st.productcomp, st.price, st.productid,st.Qnt);
				fflush(stdin);
			}

		}
		if(!a)
		{
			printf("\n\nBOYLE BIR URUN MEVCUT DEGIL!!!!");
		}
		fclose(rp);
		fclose(fp);
		remove("NextFile.dat");
		rename("TempFile.dat","NextFile.dat");
		getch();
	}
	menu();
}
