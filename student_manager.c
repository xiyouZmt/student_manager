#include<stdio.h>
#include<stdlib.h>/*system*/
#include<string.h>/*字符串*/
#include<conio.h>/*getch*/
#include<windows.h>/*Sleep*/
#include<graphics.h>
struct person
{
	int  a;
	char ID[15];
	char name[30];
	char Phone[15];
	char sex[10];
	char age[10];
	char Highermath[10];
	char C[10];
	char English[10];
	struct person *next;
};
int sum=0;
char a,b,c,d,e,e1,e2;
gotoxy(int x,int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	return 0;
}
Interface()
{
	int r;
	// 创建绘图窗口
	initgraph(1366, 768);
	// 画渐变的天空(通过亮度逐渐增加)
	float H = 190;		// 色相
	float S = 1;		// 饱和度
	float L = 0.7f;		// 亮度
	for(r = 0; r < 768; r++)
	{
		L += 0.0005f;
		setlinecolor( HSLtoRGB(H, S, L) );
		line(0, r, 1365, r);
	}
	// 画彩虹(通过色相逐渐增加)
	H = 0;
	S = 1;
	L = 0.5f;
	setlinestyle(PS_SOLID, 2);		// 设置线宽为 2
	for(r = 400; r > 344; r--)
	{
		H += 5;
		setlinecolor( HSLtoRGB(H, S, L) );
		circle(500, 480, r);
	}
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 48;                      // 设置字体高度为 48
	_tcscpy(f.lfFaceName, _T(""));		  // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿
	settextstyle(&f);                     // 设置字体样式
	outtextxy(420,180,"Welcome!");
	outtextxy(200,400,"Press any key to continue");
	getch();
	closegraph();
	return 0;
}
struct person *Head;
struct person *creat()
{
	struct person *New,*End;
	char x;
	FILE *p;
	sum=0;
	while(1)
	{
		p=fopen("e:\\学生信息.txt","at+");
		if(p==NULL)
		{
			printf("False to open the file,e:\\学生信息.txt maybe don't exist\n");
			printf("Press any key to continue");
			x=getch();
			continue;
		}
		break;
	}
	New=End=(struct person *)malloc(sizeof(struct person));
	printf("Please input the information(at least 1 ,stop when input '0')\n");
	printf("ID\tName\tSex\tage\tPhone\t    Highermath\tC\tEnglish\n");
	scanf("%s",New->ID);
	fprintf(p,"%s\t",New->ID);
	scanf("%s",New->name);
	fprintf(p,"%s\t",New->name);
	scanf("%s",New->sex);
	fprintf(p,"%s\t",New->sex);
	scanf("%s",New->age);
	fprintf(p,"%s\t",New->age);
	scanf("%s",New->Phone);
	fprintf(p,"%s\t",New->Phone);
	scanf("%s",New->Highermath);
	fprintf(p,"%s\t",New->Highermath);
	scanf("%s",New->C);
	fprintf(p,"%s\t",New->C);
	scanf("%s",New->English);
	fprintf(p,"%s\n",New->English);
	New->a=1;
	while(1)
	{
		sum++;
		New->a=sum;
		if(sum==1)
		{
			New->next=NULL;
			End=New;
			Head=New;
		}
		else
		{
			New->next=NULL;
			End->next=New;
			End=New;
		}
		New=(struct person *)malloc(sizeof(struct person));
		scanf("%s",New->ID);
		if(strcmp(New->ID,"0")==0)
			break;
		fprintf(p,"%s\t",New->ID);
		scanf("%s",New->name);
		fprintf(p,"%s\t",New->name);
		scanf("%s",New->sex);
		fprintf(p,"%s\t",New->sex);
		scanf("%s",New->age);
		fprintf(p,"%s\t",New->age);
		scanf("%s",New->Phone);
		fprintf(p,"%s\t",New->Phone);
		scanf("%s",New->Highermath);
		fprintf(p,"%s\t",New->Highermath);
		scanf("%s",New->C);
		fprintf(p,"%s\t",New->C);
		scanf("%s",New->English);
		fprintf(p,"%s\n",New->English);
	}
	fclose(p);
	free(New);
	return Head;
}
printf1(struct person *Head)
{
	struct person *p;
	int i=1;
	printf("*******There are %d personal information*******\n",sum);
	printf("\tID\tName\tSex\tage\tPhone\t   Highermath\tC\tEnglish\n");
	p=Head;
	while(p!=NULL)
	{
		if(sum!=0)
		{
			printf("%d\t",i++);
			printf("%s\t",p->ID);
			printf("%s\t",p->name);
			printf("%s\t",p->sex);
			printf("%s\t",p->age);
			printf("%s\t",p->Phone);
			printf("%s\t",p->Highermath);
			printf("%s\t",p->C);
			printf("%s\n",p->English);
			p=p->next;
		}
	}
	return 0;
}
Exchange(struct person *p,struct person *p1)
{
	int t;
	char s[30];
	t=p->a;
	p->a=p1->a;
	p1->a=t;/*交换序号*/
	strcpy(s,p1->ID);
	strcpy(p1->ID,p->ID);
	strcpy(p->ID,s);/*交换ID*/
	strcpy(s,p1->name);
	strcpy(p1->name,p->name);
	strcpy(p->name,s);/*交换name*/
	strcpy(s,p1->age);
	strcpy(p1->age,p->age);
	strcpy(p->age,s);/*交换age*/
	strcpy(s,p1->Phone);
	strcpy(p1->Phone,p->Phone);
	strcpy(p->Phone,s);/*交换Phone*/
	strcpy(s,p1->sex);
	strcpy(p1->sex,p->sex);
	strcpy(p->sex,s);/*交换sex*/
	strcpy(s,p1->Highermath);
	strcpy(p1->Highermath,p->Highermath);
	strcpy(p->Highermath,s);/*交换Highermath*/
	strcpy(s,p1->C);
	strcpy(p1->C,p->C);
	strcpy(p->C,s);/*交换LanguageC*/
	strcpy(s,p1->English);
	strcpy(p1->English,p->English);
	strcpy(p->English,s);/*交换English*/
	return 0;
}
Sort(struct person *Head)
{
	struct person *p;
	struct person *p1;
	if(sum!=0)
	{
		p=Head;
		p1=p->next;
		printf("Please choose the types\n");
		printf("1.Dont't sort\n");
		printf("2.Sort by ID\n");
		printf("3.Sort by name\n");
		printf("4.Sort by Phone\n");
		printf("5.Sort by age\n");
		printf("6.Sort by Highermath\n");
		printf("7.Sort by Language\n");
		printf("8.Sort by English\n");
		printf("9.Return\n");
		while(1)
		{
			b=getch();
			switch(b-48)
			{
				case 1:system("cls");/*Sort by order*/
					while(p!=NULL)
					{
						p1=p->next;
						while(p1!=NULL)
						{
							if(p->a>p1->a)
								Exchange(p,p1);
							p1=p1->next;
						}
						p=p->next;
					}
					break;
				case 2:system("cls");/*Sort by ID*/
					while(p!=NULL)
					{
						p1=p->next;
						while(p1!=NULL)
						{
							if(strcmp(p->ID,p1->ID)>0)
								Exchange(p,p1);
							p1=p1->next;
						}
						p=p->next;
					}
					break;
				case 3:system("cls");/*Sort by name*/
					while(p!=NULL)
					{
						p1=p->next;
						while(p1!=NULL)
						{
							if(strcmp(p->name,p1->name)>0)
								Exchange(p,p1);
							p1=p1->next;
						}
						p=p->next;
					}
					break;
				case 4:system("cls");/*Sort by Phone*/
					while(p!=NULL)
					{
						p1=p->next;
						while(p1!=NULL)
						{
							if(strcmp(p->Phone,p1->Phone)>0)
								Exchange(p,p1);
							p1=p1->next;
						}
						p=p->next;
					}
					break;
				case 5:system("cls");/*Sort by age*/
					while(p!=NULL)
					{
						p1=p->next;
						while(p1!=NULL)
						{
							if(strcmp(p->age,p1->age)>0)
								Exchange(p,p1);
							p1=p1->next;
						}
						p=p->next;
					}
					break;
				case 6:system("cls");/*Sort by Highermath*/
					while(p!=NULL)
					{
						p1=p->next;
						while(p1!=NULL)
						{
							if(strcmp(p->Highermath,p1->Highermath)<0)
								Exchange(p,p1);
							p1=p1->next;
						}
						p=p->next;
					}
					break;
				case 7:system("cls");/*Sort by C/C++*/
					while(p!=NULL)
					{
						p1=p->next;
						while(p1!=NULL)
						{
							if(strcmp(p->C,p1->C)<0)
								Exchange(p,p1);
							p1=p1->next;
						}
						p=p->next;
					}
					break;
				case 8:system("cls");/*Sort by English*/
					while(p!=NULL)
					{
						p1=p->next;
						while(p1!=NULL)
						{
							if(strcmp(p->English,p1->English)<0)
								Exchange(p,p1);
							p1=p1->next;
						}
						p=p->next;
					}
					break;
				case 9:break;
			}
			if(b=='1'||b=='2'||b=='3'||b=='4'||b=='5'||b=='6'||b=='7'||b=='8'||b=='9')
				break;
		}
	}
	else
	{
		printf("There are no person !\nPlease input information,stop when input '0'\n");
		Head=creat();
	}
	return 0;
}
Save(struct person *p)
{
	FILE *h;
	char x;
	h=fopen("e:\\学生信息.txt","wt");
	while(p!=NULL)
	{
		while(1)
		{
			if(h==NULL)
			{
				printf("False to open the file,e:\\学生信息.txt maybe don't exist\n");
				printf("Press any key to continue");
				x=getch();
				continue;
			}
			break;
		}
		fprintf(h,"%s\t",p->ID);
		fprintf(h,"%s\t",p->name);
		fprintf(h,"%s\t",p->sex);
		fprintf(h,"%s\t",p->age);
		fprintf(h,"%s\t",p->Phone);
		fprintf(h,"%s\t",p->Highermath);
		fprintf(h,"%s\t",p->C);
		fprintf(h,"%s\t",p->English);
		fprintf(h,"\n");
		p=p->next;
	}
	fclose(h);
	return 0;
}
struct person *Insert(struct person *Head)
{
	struct person *p1;
	struct person *p2;
	char m;
	if(sum!=0)
	{
		p1=Head;
		while(p1->next!=NULL)
			p1=p1->next;
		p2=p1;
		printf("ID\tName\tSex\tage\tPhone\t   Highermath\tC\tEnglish(stop when input 0)\n");
		while(1)
		{
			p1=(struct person *)malloc(sizeof(struct person));
			scanf("%s",p1->ID);
			if(strcmp(p1->ID,"0")==0)
			{
				printf("\nAre you sure to save information(press 'Y' to save, others don't save)\n");
				m=getch();
				if(m=='y'||m=='Y')
				{
					printf("Successfully saved at e:\\学生信息.txt\n");
					Save(Head);
				}
				break;
			}
			scanf("%s",p1->name);
			scanf("%s",p1->sex);
			scanf("%s",p1->age);
			scanf("%s",p1->Phone);
			scanf("%s",p1->Highermath);
			scanf("%s",p1->C);
			scanf("%s",p1->English);
			p2->next=p1;
			p1->next=NULL;
			p1->a=(p2->a)+1;
			p2=p1;
			sum++;
		}
	}
	else
	{
		printf("There are not person !\nPlease input information,stop when input '0'\n");
		Head=creat();
	}
	return Head;
}
struct person *Delete(struct person *Head)
{
	char m,n[30];
	struct person *p1;
	struct person *p2;
	if(sum!=0)
	{
		while(1)
		{
			system("cls");
			p1=Head;
			p2=p1;
			printf("Please input the person's name,Stop when input '0'\n");
			gotoxy(0,4);
			printf1(p1);
			gotoxy(0,1);
			fflush(stdin);
			gets(n);
			if(strcmp(n,"0")==0)
			{
				printf("\nAre you sure to save information(press 'Y' to save, others don't save)\n");
				m=getch();
				if(m=='y'||m=='Y')
				{
					printf("Successfully saved at e:\\学生信息.txt\n");
					Save(Head);
				}
				break;
			}
			if(strcmp(p1->name,n)==0)
			{
				p1=p1->next;
				Head=p1;
				while(p1!=NULL)
				{
					(p1->a)--;
					p1=p1->next;
				}
				free(p2);
				sum--;
				if(sum==0)
					break;
				break;
			}
			else
			{
				while(1)
				{
					if(p1==NULL)
					{
						printf("Sorry,there is no this person!\nPlease input once more stop when input '0'\n");
						gotoxy(1,1);
						Sleep(3000);
						break;
					}
					else
					{
						if(strcmp(p1->name,n)==0)
						{
							p2->next=p1->next;
							free(p1);
							while(p2->next!=NULL)
							{
								p2=p2->next;
								if(p2->next==NULL)
									break;
								(p2->a)--;
							}
							sum--;
							break;
						}
					}
					p2=p1;
					p1=p1->next;
				}
				if(p1==NULL)
					continue;
				break;
			}
		}
	}
	else
	{
		printf("There are no persons !\nPlease input information,stop when input '0'\n");
		Head=creat();
	}
	return Head;
}
Change(struct person *Head)
{
	char m,x;
	char n[30];
	struct person *p1;
	if(sum!=0)
	{
		while(1)
		{
			system("cls");
			p1=Head;
			printf("Please input the personal name(stop when input '0'):\n");
			fflush(stdin);
			gets(n);
			if(strcmp(n,"0")==0)
			{
				printf("\nAre you sure to save information(press 'Y' to save, others don't save)\n");
				m=getch();
				if(m=='y'||m=='Y')
				{
					printf("Successfully saved at e:\\学生信息.txt\n");
					Sleep(2000);
					Save(Head);
				}
				break;
			}
			while(1)
			{
				if(p1==NULL)
				{
					printf("Sorry,there is no this person\nPlease input once more, stop when input '0'\n");
					gotoxy(0,1);
					printf(" \b");
					gets(n);
					if(strcmp(n,"0")==0)
					{
						printf("\nAre you sure to save information(press 'Y' to save, others don't save)\n");
						m=getch();
						if(m=='y'||m=='Y')
						{
							printf("Successfully saved at e:\\学生信息.txt\n");
							Save(Head);
						}
						break;
					}
					p1=Head;
				}
				if(p1!=NULL)
				{
					if(strcmp(p1->name,n)==0)
						break;
				}
				p1=p1->next;
			}
			while(p1!=NULL)
			{
				system("cls");
				printf("Please choose the types that you want to change\n");
				printf("1.ID\n");
				printf("2.name\n");
				printf("3.Phone\n");
				printf("4.age\n");
				printf("5.Highermath\n");
				printf("6.C\n");
				printf("7.English\n");
				printf("8.Return\n");
				x=getch();
				switch(x-48)
				{
					case 1:printf("Please input new ID:");
						scanf("%s",p1->ID);
						break;
					case 2:printf("Please input new name:");
						scanf("%s",p1->name);
						break;
					case 3:printf("Please input new Phone:");
						scanf("%s",p1->Phone);
						break;
					case 4:printf("Please input new age:");
						scanf("%s",p1->age);
						break;
					case 5:printf("Please input new Highermath point:");
						scanf("%s",p1->Highermath);
						break;
					case 6:printf("Please input new C point:");
						scanf("%s",p1->C);
						break;
					case 7:printf("Please input new English:");
						scanf("%s",p1->English);
						break;
					case 8:break;
				}
				if(x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7')
				{
					printf("Successfully change!\n\n");
					printf("Press any key to continue;\nwhen input 'r' return last, input '1' return menu\n");
					d=getch();
					if(d=='r')
						break;
					else
					{
						if(d!='1')
							continue;
					}
				}
				if(x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8')
					break;
			}
			if(d=='1')
				break;
		}
	}
	else
	{
		printf("There are no persons !\nPlease input information,stop when input '0'\n");
		Head=creat();
	}
	return 0;
}
Search(struct person *Head)
{
	struct person *p;
	char s[30];
	if(sum!=0)
	{
		while(1)
		{
			system("cls");
			printf("Please choose the types\n");
			printf("1.Search by ID\n");
			printf("2.Search by Name\n");
			printf("3.Search by Phone\n");
			printf("4.Return\n");
			a='0';
			c=getch();
			switch(c-48)
			{
				case 1 :while(1)
					{
						system("cls");
						p=Head;
						e=0;
						printf("Please input the ID:");
						fflush(stdin);
						gets(s);
						printf("\tID\tName\tSex\tage\tPhone\t   Highermath\tC\tEnglish\n");
						while(p!=NULL)
						{
							if(memcmp(p->ID,s,strlen(s))==0)
							{
								printf("%d\t",p->a);
								printf("%s\t",p->ID);
								printf("%s\t",p->name);
								printf("%s\t",p->sex);
								printf("%s\t",p->age);
								printf("%s\t",p->Phone);
								printf("%s\t",p->Highermath);
								printf("%s\t",p->C);
								printf("%s\n",p->English);
								p=p->next;
							}
							else
							{
								e++;
								p=p->next;
							}
						}
						if(p==NULL)
						{
							if(sum==e)
								printf("Sorry,there is no this person!\n\n");
							printf("Press any key to continue\nWhen input 'r' return last, input '1' return menu input '0' end\n");
							a=getch();
							if(a=='0')
								exit(0);
							else
							{
								if(a=='r')
									break;
								else
								{
									if(a=='1')
										break;
									continue;
								}
							}
						}
					}
					break;
				case 2:while(1)
					{
						system("cls");
						p=Head;
						e=0;
						printf("Please input the key words:");
						fflush(stdin);
						scanf("%s",s);
						printf("\tID\tName\tSex\tage\tPhone\t   Highermath\tC\tEnglish\n");
						while(p!=NULL)
						{
							if(memcmp(p->name,s,strlen(s))==0)
							{
								printf("%d\t",p->a);
								printf("%s\t",p->ID);
								printf("%s\t",p->name);
								printf("%s\t",p->sex);
								printf("%s\t",p->age);
								printf("%s\t",p->Phone);
								printf("%s\t",p->Highermath);
								printf("%s\t",p->C);
								printf("%s\n",p->English);
								p=p->next;
							}
							else
							{
								e++;
								p=p->next;
							}
						}
						if(p==NULL)
						{
							if(sum==e)
								printf("Sorry,there is no this person!\n\n");
							printf("Press any key to continue\nWhen input 'r' return last, input '1' return menu input '0' end\n");
							a=getch();
							if(a=='0')
								exit(0);
							else
							{
								if(a=='r')
									break;
								else
								{
									if(a=='1')
										break;
									continue;
								}
							}
						}
					}
					break;
				case 3 :while(1)
					{
						system("cls");
						p=Head;
						e=0;
						printf("Please input the Phone number:");
						fflush(stdin);
						scanf("%s",s);
						printf("\tID\tName\tSex\tage\tPhone\t   Highermath\tC\tEnglish\n");
						while(p!=NULL)
						{
							if(memcmp(p->Phone,s,strlen(s))==0)
							{
								printf("%d\t",p->a);
								printf("%s\t",p->ID);
								printf("%s\t",p->name);
								printf("%s\t",p->sex);
								printf("%s\t",p->age);
								printf("%s\t",p->Phone);
								printf("%s\t",p->Highermath);
								printf("%s\t",p->C);
								printf("%s\n",p->English);
								p=p->next;
							}
							else
							{
								e++;
								p=p->next;
							}
						}
						if(p==NULL)
						{
							if(sum==e)
								printf("Sorry,there is no this person!\n\n");
							printf("Press any key to continue\nWhen input 'r' return last, input '1' return menu input '0' end\n");
							a=getch();
							if(a=='0')
								exit(0);
							else
							{
								if(a=='r')
									break;
								else
								{
									if(a=='1')
										break;
									continue;
								}
							}
						}
					}
					break;
				case 4 :break;
			}
			if(c=='1'||c=='2'||c=='3'||c=='4')
			{
				if(a=='r')
					continue;
				break;
			}
		}
	}
	else
	{
		printf("There are not person !\nPlease input information,stop when input '0'\n");
		Head=creat();
	}
	return 0;
}
Statistics(struct person *Head)
{
	struct person *p;
	char s[10],t[10];
	int i,y;
	if(sum!=0)
	{
		while(1)
		{
			system("cls");
			printf("Please choose the types\n");
			printf("1.Statistics Highermath\n");
			printf("2.Statistics c\n");
			printf("3.Statistics English\n");
			printf("4.Return\n");
			e2='0';
			e1=getch();
			switch(e1-48)
			{
				case 1:while(1)
					{
						system("cls");
						p=Head;
						i=0;
						e=0;
						y=5;
						printf("Please input the score\n");
						printf("Lower bound:\n");
						printf("Upper bound:");
						gotoxy(12,1);
						gets(s);
						gotoxy(12,2);
						gets(t);
						printf("\n\tID\tName\tSex\tage\tPhone\t   Highermath\n");
						while(p!=NULL)
						{
							if((strlen(p->Highermath)>strlen(s)||(strlen(p->Highermath)==strlen(s)&&strcmp(p->Highermath,s)>=0))&&(strlen(p->Highermath)<strlen(t)||(strlen(p->Highermath)==strlen(t)&&strcmp(p->Highermath,t)<=0)))
							{
									printf("%d\t",p->a);
									printf("%s\t",p->ID);
									printf("%s\t",p->name);
									printf("%s\t",p->sex);
									printf("%s\t",p->age);
									printf("%s\t",p->Phone);
									printf("%s\n",p->Highermath);
									p=p->next;
									i++;
									y++;
							}
							else
							{
								e++;
								p=p->next;
							}
						}
						if(p==NULL)
						{
							if(sum==e)
								printf("Sorry,there is no information!\n\n");
							else
							{
								gotoxy(0,3);
								printf("*******There are %d personal information*******",i);
								gotoxy(0,y);
							}
							printf("Press any key to continue\nWhen input 'r' return last, input '1' return menu input '0' end\n");
							e2=getch();
							if(e2=='0')
								exit(0);
							else
							{
								if(e2=='r')
									break;
								else
								{
									if(e2=='1')
										break;
									continue;
								}
							}
						}
					}
					break;
				case 2:while(1)
					{
						system("cls");
						p=Head;
						i=0;
						e=0;
						y=5;
						printf("Please input the score\n");
						printf("Lower bound:\n");
						printf("Upper bound:");
						gotoxy(12,1);
						gets(s);
						gotoxy(12,2);
						gets(t);
						printf("\n\tID\tName\tSex\tage\tPhone\t   C\n");
						while(p!=NULL)
						{
							if((strlen(p->C)>strlen(s)||(strlen(p->C)==strlen(s)&&strcmp(p->C,s)>=0))&&(strlen(p->C)<strlen(t)||(strlen(p->C)==strlen(t)&&strcmp(p->C,t)<=0)))
							{
								printf("%d\t",p->a);
								printf("%s\t",p->ID);
								printf("%s\t",p->name);
								printf("%s\t",p->sex);
								printf("%s\t",p->age);
								printf("%s\t",p->Phone);
								printf("%s\n",p->C);
								p=p->next;
								i++;
								y++;
							}
							else
							{
								e++;
								p=p->next;
							}
						}
						if(p==NULL)
						{
							if(sum==e)
								printf("Sorry,there is no information!\n\n");
							else
							{
								gotoxy(0,3);
								printf("*******There are %d personal information*******",i);
								gotoxy(0,y);
							}
							printf("Press any key to continue\nWhen input 'r' return last, input '1' return menu input '0' end\n");
							e2=getch();
							if(e2=='0')
								exit(0);
							else
							{
								if(e2=='r')
									break;
								else
								{
									if(e2=='1')
										break;
									continue;
								}
							}
						}
					}
					break;
				case 3:while(1)
					{
						system("cls");
						p=Head;
						i=0;
						e=0;
						y=5;
						printf("Please input the score\n");
						printf("Lower bound:\n");
						printf("Upper bound:");
						gotoxy(12,1);
						gets(s);
						gotoxy(12,2);
						gets(t);
						printf("\n\tID\tName\tSex\tage\tPhone\t   Highermath\n");
						while(p!=NULL)
						{
							if(strlen(p->English)>=strlen(s)&&(strcmp(p->English,s)>=0)&&(strlen(p->English)<=strlen(t)&&(strcmp(p->English,t)<=0)))
							{
								printf("%d\t",p->a);
								printf("%s\t",p->ID);
								printf("%s\t",p->name);
								printf("%s\t",p->sex);
								printf("%s\t",p->age);
								printf("%s\t",p->Phone);
								printf("%s\n",p->English);
								p=p->next;
								i++;
								y++;
							}
							else
							{
								e++;
								p=p->next;
							}
						}
						if(p==NULL)
						{
							if(sum==e)
								printf("Sorry,there is no information!\n\n");
							else
							{
								gotoxy(0,3);
								printf("*******There are %d personal information*******",i);
								gotoxy(0,y);
							}
							printf("Press any key to continue\nWhen input 'r' return last, input '1' return menu input '0' end\n");
							e2=getch();
							if(e2=='0')
								exit(0);
							else
							{
								if(e2=='r')
									break;
								else
								{
									if(e2=='1')
										break;
									continue;
								}
							}
						}
					}
					break;
				case 4:break;
			}
			if(e1=='1'||e1=='2'||e1=='3'||e1=='4')
			{
				if(e2=='r')
					continue;
				break;
			}
		}
	}
	else
	{
		printf("There are not person !\nPlease input information,stop when input '0'\n");
		Head=creat();
	}
	return 0;
}
main()
{
	FILE *h,*g;
	struct person *New1,*End1;
	char s[20],t[20],f1[20],f2[20],ID[15],password[20],password1[20],password2[20];
	char m,n,o,p,q,p1;
	int l,k=1,x,y,z=0,w,u,v;
	unsigned r=0;
	Interface();
	while(1)
	{
		while(k!=7)
		{
			system("cls");
			gotoxy(36,8);
			printf("**********Welcome to students management system**********");
			for(x=36,y=9;y<18;y++)
			{
				gotoxy(x,y);
				printf("|\t\t\t\t\t\t\t    |");
			}
			gotoxy(37,17);
			printf("_______________________________________________________");
			gotoxy(54,10);
			printf("1.\t Login");
			gotoxy(54,12);
			printf("2.\tRegister");
			gotoxy(54,14);
			printf("3.    Change password");
			gotoxy(54,16);
			printf("4.    Forget password");
			gotoxy(42,18);
			printf("Press up and down to move and choose function");
			while(1)
			{
				r=10;
				gotoxy(35,r);
				printf("%c",2);
				gotoxy(52,r);
				printf(">>");
				gotoxy(75,r);
				printf("<<");
				gotoxy(93,r);
				l=1;
				while(1)
				{
					p1=getch();
					if(p1==13)
						break;
					if(p1==72)
					{
						gotoxy(35,r);
						printf(" ");
						gotoxy(52,r);
						printf("  ");
						gotoxy(75,r);
						printf("  ");
						if((r-2)<9)
						{
							gotoxy(35,16);
							printf("%c",2);
							gotoxy(52,16);
							printf(">>");
							gotoxy(75,16);
							printf("<<");
							gotoxy(93,16);
							r=16;
							l=4;
						}
						else
						{
							r-=2;
							gotoxy(35,r);
							printf("%c",2);
							gotoxy(52,r);
							printf(">>");
							gotoxy(75,r);
							printf("<<");
							gotoxy(93,r);
							l--;
						}
					}
					if(p1==80)
					{
						gotoxy(35,r);
						printf(" ");
						gotoxy(52,r);
						printf("  ");
						gotoxy(75,r);
						printf("  ");
						if((r+2)>17)
						{
							gotoxy(35,10);
							printf("%c",2);
							gotoxy(52,10);
							printf(">>");
							gotoxy(75,10);
							printf("<<");
							gotoxy(93,10);
							r=10;
							l=1;
						}
						else
						{
							r+=2;
							gotoxy(35,r);
							printf("%c",2);
							gotoxy(52,r);
							printf(">>");
							gotoxy(75,r);
							printf("<<");
							gotoxy(93,r);
							l++;
						}
					}
				}
				break;
			}
			system("cls");
			if(l==1||l==2)
			{
				while(1)/*循环输入账号密码*/
				{
					system("cls");
				    gotoxy(40,6);
					printf("*************************************************");
					for(x=40,y=7;y<20;y++)
					{
						gotoxy(x,y);
	 					printf("|\t\t\t\t\t\t|");
					}
					if(l==1)
					{
						gotoxy(49,8);
						printf("Please input your ID and password");

					}
					if(l==2)
					{
						gotoxy(49,8);
						printf("Please input a ID and a password");
					}
					gotoxy(41,19);
					printf("_______________________________________________");
					gotoxy(52,10);
					printf("ID   :");
					gotoxy(49,14);
					printf("Password:");
					if(l==2)
					{
						gotoxy(32,22);
						printf("Noticed:");
						printf(" * Tne ID and password of the 19 bit most");
						gotoxy(40,23);
						printf(" * The password at least 6 bit");
						gotoxy(40,24);
						printf(" * There is nointerval between ID and password");
					}/*打印图表*/
					while(1)/*输入账号*/
					{
						fflush(stdin);
						gotoxy(58,10);
						z=0;
						q=getch();
						if(q==13)
						{
							if(l==1)
							{
								gotoxy(45,12);
								printf("You input nothing! please input your ID");
							}
							if(l==2)
							{
								gotoxy(46,12);
								printf("You input nothing! please input a ID");
							}
							u=0;
							continue;
						}
						if(u==0)
						{
							for(x=45,y=12;x<84;x++)
							{
								gotoxy(x,y);
								printf(" ");
							}
							gotoxy(58,10);
						}
						while(q!=13 && z<20  )
						{
							if(q==8)
							{
								if(w==0 && z>0)
								{
									z--;
									printf("\b \b");
								}
								else
									printf("");
							}/*删除账号*/
							else
							{
								if(l==1)
								{
									s[z]=q;
									if(z<19)
									{
										z++;
										printf("%c",q);
									}
									w=0;
								}
								if(l==2)
								{
									if(q!=32)/*判断输入是否为空格*/
									{
										s[z]=q;
										if(z<19)
										{
											z++;
											printf("%c",q);
										}
										w=0;
									}
								}
							}/* 输入显示账号 */
							q=getch();
							if(z==0&&q==13)
								break;
						}
						if(z==0)
						{
							if(l==1)
							{
								gotoxy(45,12);
								printf("You input nothing! please input your ID");
							}
							if(l==2)
							{
								gotoxy(46,12);
								printf("You input nothing! please input a ID");
							}
							u=0;
						}
						else
						{
							s[z]=0;
							break;
						}
					}/*输入账号结束*/
					while(1)/*输入密码*/
					{
						fflush(stdin);
						gotoxy(58,14);
						z=0;
						p=getch();
						if(p==13)
						{
							if(l==1)
							{
								gotoxy(42,16);
								printf("You input nothing! please input your password");
							}
							if(l==2)
							{
								gotoxy(43,16);
								printf("You input nothing! please input a password");
							}
							v=0;
							continue;
						}
						if(v==0)
						{
							for(x=42,y=16;x<87;x++)
							{
								gotoxy(x,y);
								printf(" ");
							}
							gotoxy(58,14);
						}
						while(p!=13 && z<20)
						{
							if(p==8)
							{
								if(w==0 && z>0)
								{
									z--;
									printf("\b \b");
								}
								else
									printf("");
							}/*删除密码*/
							else
							{
								if(l==1)
								{
									t[z]=p;
									if(z<19)
									{
										z++;
										if(l==1)
											printf("*");
										else
											printf("%c",p);
									}
									w=0;
								}
								if(l==2)
								{
									if(q!=32)
									{
										t[z]=p;
										if(z<19)
										{
											z++;
											if(l==1)
												printf("*");
											else
												printf("%c",p);
										}
										w=0;
									}
								}
							}/* 输入密码显示* */
							p=getch();
							if(z==0&&p==13)
								break;
						}
						if(z==0)
						{
							if(l==1)
							{
								gotoxy(42,16);
								printf("You input nothing! please input your password");
							}
							if(l==2)
							{
								gotoxy(43,16);
								printf("You input nothing! please input a password");
							}
							v=0;
						}
						else
						{
							t[z]=0;
							break;
						}
					}/*输入密码结束*/
					switch(l)
					{
						case 1: gotoxy(58,16);
							printf("Logining...");
							gotoxy(46,18);
							printf("|\t\t\t\t\t|");
							r=1;
							for(x=47;x<80;x++)
							{
								gotoxy(x,18);
								printf(">");
								gotoxy(82,18);
								printf("%d",r+=3);
								Sleep(100);
							}
							for(x=58,y=16;x<69;x++)
							{
								gotoxy(x,y);
								printf(" ");
							}
							g=fopen("e:\\账号信息.txt","rt");
							if(g==NULL)
								g=fopen("e:\\账号信息.txt","wt+");
							while(!feof(g))
							{
								fscanf(g,"%s",f1);
								fscanf(g,"%s",f2);
								if(strcmp(f1,s)==0&&strcmp(f2,t)==0)
								{
									gotoxy(46,20);
									printf("Congratulations! Successfully login");
									p1='1';
									Sleep(2000);
									break;
								}
								if(strcmp(f1,s)==0&&strcmp(f2,t)!=0)
								{
									gotoxy(57,20);
									printf("False password!");
									gotoxy(41,21) ;
									printf("Press any key to continue,when input '0' return");
									p=getch();
									p1=0;
									break;
								}
							}
							fclose(g);
							if(strcmp(f1,s)!=0)
							{
								gotoxy(46,20);
								printf("The ID dont't exist! please register");
								gotoxy(41,21) ;
								printf("Press any key to continue,when input '0' return");
								p=getch();
							}
							break;
						case 2:if(strlen(t)<6)
						   {
							    gotoxy(45,16);
								printf("The length of the password less than 6");
							    gotoxy(52,18);
								printf("Please register once more");
			      				gotoxy(40,20);
								printf("Press any key to continue, when input '0' return");
								q=getch();
								break;
						   }
							g=fopen("e:\\账号信息.txt","at+");
							if(g==NULL)
								g=fopen("e:\\账号信息.txt","wt+");
							while(!feof(g))
							{
								fscanf(g,"%s",f1);
								fscanf(g,"%s",f2);
								if(strcmp(f1,s)==0)
								{
									gotoxy(51,16);
									printf("This ID has been registered!");
									gotoxy(54,18);
									printf("Please register again");
									gotoxy(40,20);
									printf("Press any key to continue, when input '0' return");
									q=getch();
									break;
								}
							}
							if(strcmp(f1,s)!=0)
							{
								fprintf(g,s);
								fprintf(g,"\n");
								fprintf(g,t);
								fprintf(g,"\n");
								fclose(g);
								gotoxy(53,16);
								printf("Successfully register!");
								gotoxy(44,18);
								printf("Now,you can login,press any key to login");
								l=1;
								q=getch();
							}
							break;
					}
					if(l==1&&(p=='0'||p1=='1'))
						break;
					if(l==2&&q=='0')
						break;
				}/*循环输入账号密码*/
			}
			if(l==1&&p1=='1')
				break;
			if(l==3)/*修改密码*/
			{
				while(1)/*重复修改*/
				{
					system("cls");
					printf("Please input your personal login ID and password\n");
					printf("1.ID:\n\n");
					printf("2.Password:");
					gotoxy(5,1);
					gets(ID);
					gotoxy(11,3);
					gets(password);
					if(strlen(password)>19||strlen(password)<6)/*当新密码不合格时*/
					{
						printf("\n\nThe password of the 19 bit most, at least 6 bit\n");
						printf("Please any key to continue, press '1' return\n");
						p1=getch();
						if(p1=='1')
							break;
						continue;
					}
					g=fopen("e:\\账号信息.txt","rt+");
					while(!feof(g))/*从文件中读取账号信息*/
					{
						fscanf(g,"%s",f1);
						fscanf(g,"%s",f2);
						if(strcmp(f1,ID)==0&&strcmp(f2,password)==0)/*当输入的账号信息准确时*/
						{
							gotoxy(0,4);
							printf("\nSuccessfully confirm!");
							Sleep(1000);
							while(1)/*判断密码是否合格*/
							{
								system("cls");
								printf("Please input your new password\n");
								gets(password1);
								if(strlen(password1)>19||strlen(password1)<6)/*当新密码不合格时*/
								{
									printf("\nThe password of the 19 bit most, at least 6 bit\n");
									printf("Please any key to continue, press '1' return\n");
									p1=getch();
									if(p1=='1')
										break;
									continue;
								}
								printf("Please input your new password again\n");
								gets(password2);
								if(strcmp(password1,password2)!=0)
								{
									printf("\nTwice the password is inconsistent\n");
									printf("Please any key to continue, press '1' return\n");
									p1=getch();
									if(p1=='1')
										break;
									continue;
								}
								else/*把新密码写到文件的相应位置*/
								{
									r=ftell(g)-strlen(f2);
									rewind(g);
									fseek(g,r,0);
									for(r=0;r<strlen(f2);r++)
										fprintf(g," ");
									r=ftell(g)-strlen(f2);
									rewind(g);
									fseek(g,r,0);
									fwrite(password1,sizeof(char),strlen(password1),g);
									printf("\nSuccessfully change!\n");
									fclose(g);
									printf("Press any key to continue,press '1' return\n");
									p1=getch();
									r=0;
									break;
								}
							}/*判断密码是否合格*/
						}
						if(r==0||p1=='1')
						{
							fclose(g);
							break;
						}
						if(strcmp(f1,ID)==0&&strcmp(f2,password)!=0)/*当输入的账号信息不准确时*/
						{
							printf("\nFalse password!\n");
							printf("Please any key to continue, press '1' return\n");
							p1=getch();
								break;
						}
					}/*从文件中读取账号信息*/
					if(p1=='1')
						break;
					continue;
					if(strcmp(f1,ID)!=0)
					{
						printf("This ID don't exist! please input again");
						Sleep(2000);
						continue;
					}
					fclose(g);
				}
			}/*修改密码*/
			if(l==4)/*找回密码*/
			{
				while(1)/*循环查找*/
				{
					system("cls");
					printf("Please input your ID\n");
					gets(ID);
					printf("\nSearching, please wait...\n");
					r=1;
					printf("|\t\t\t\t  |");
					for(x=1;x<34;x++)
					{
						gotoxy(x,4);
						printf(">");
						gotoxy(36,4);
						printf("%d",r+=3);
						Sleep(100);
					}
					for(x=0;x<30;x++)
					{
						gotoxy(x,3);
						printf(" ");
					}
					g=fopen("e:\\账号信息.txt","rt");
					while(!feof(g))/*从文件中读取账号信息*/
					{
						fscanf(g,"%s",f1);
						fscanf(g,"%s",f2);
						if(strcmp(f1,ID)==0)
						{
							gotoxy(0,6);
							printf("Successfully retrieve!\n");
							printf("Please remember your password:%s\n\n",f2);
							printf("Press any key to continue,press '1' to return");
							p1=getch();
							break;
						}
					}
					if(strcmp(f1,ID)!=0)
					{
						printf("\n\nThis ID don't exist!\n\n");
						printf("Please any key to continue, press '1' return\n");
						p1=getch();
						if(p1=='1')
							break;
						continue;
					}
					if(p1=='1')
						break;
					continue;
					fclose(g);
				}/*循环查找*/
			}
		}
		while(1)/*选择录入信息*/
		{
			system("cls");
			gotoxy(45,10);
			printf("********************************************");
			for(x=45,y=11;y<17;y++)
			{
				gotoxy(x,y);
				printf("|\t\t\t\t\t\t|");
			}
			gotoxy(46,16);
			printf("__________________________________________");
			gotoxy(48,12);
			printf("1.  Recording information from files");
			gotoxy(48,14);
			printf("2.\t   Input manually");
			gotoxy(48,17);
			p1=getch();
			system("cls");
			switch(p1-48)
			{
				case 1:	h=fopen("e:\\学生信息.txt","rt");/*从文件中读取数据*/
					if(h==NULL)
						h=fopen("e:\\学生信息.txt","wt");
					printf("e:\\学生信息.txt truly to open\n");
					Sleep(1000);
					if(o=fgetc(h)==EOF)
					{
						printf("There are no information! press any key to input");
						o=getch();
						system("cls");
						Head=creat();
						break;
					}
					New1=End1=(struct person *)malloc(sizeof(struct person));
					printf("\tID\tName\tSex\tage\tPhone\t    Highermath\tC\tEnglish\n");
					sum=0;
					New1->a=1;
					while(1)
					{
						sum++;
						New1->a=sum;
						if(sum==1)
						{
							rewind(h);
							fscanf(h,"%s",New1->ID);
							fscanf(h,"%s",New1->name);
							fscanf(h,"%s",New1->sex);
							fscanf(h,"%s",New1->age);
							fscanf(h,"%s",New1->Phone);
							fscanf(h,"%s",New1->Highermath);
							fscanf(h,"%s",New1->C);
							fscanf(h,"%s",New1->English);
							printf("%d\t",New1->a);
							printf("%s\t",New1->ID);
							printf("%s\t",New1->name);
							printf("%s\t",New1->sex);
							printf("%s\t",New1->age);
							printf("%s\t",New1->Phone);
							printf("%s\t",New1->Highermath);
							printf("%s\t",New1->C);
							printf("%s\n",New1->English);
							New1->next=NULL;
							End1=New1;
							Head=New1;
						}
				   		else
						{
							fscanf(h,"%s",New1->ID);
							if(feof(h))
							{
								free(New1);
								fclose(h);
								sum--;
								printf("Press any key to continue");
								o=getch();
								break;
							}
							fscanf(h,"%s",New1->name);
							fscanf(h,"%s",New1->sex);
							fscanf(h,"%s",New1->age);
							fscanf(h,"%s",New1->Phone);
							fscanf(h,"%s",New1->Highermath);
							fscanf(h,"%s",New1->C);
							fscanf(h,"%s",New1->English);
							printf("%d\t",New1->a);
							printf("%s\t",New1->ID);
							printf("%s\t",New1->name);
							printf("%s\t",New1->sex);
							printf("%s\t",New1->age);
							printf("%s\t",New1->Phone);
							printf("%s\t",New1->Highermath);
							printf("%s\t",New1->C);
							printf("%s\n",New1->English);
							New1->next=NULL;
							End1->next=New1;
							End1=New1;
						}
						New1=(struct person *)malloc(sizeof(struct person));
					}
					break;/*从磁盘文件录入信息*/
				case 2:Head=creat();
					break;/*手动录入信息*/
			}
			if(p1=='1'||p1=='2')
				break;
		}
		while(1)/*主菜单*/
		{
			system ("cls");
			gotoxy(45,5);
			printf("**********Choose the function**********");
			for(x=45,y=6;y<23;y++)
			{
				gotoxy(x,y);
				printf("|\t\t\t\t\t   |");
			}
			gotoxy(46,22);
			printf("_____________________________________");
			gotoxy(49,7);
			printf("1.Display all of the students");
			gotoxy(49,9);
			printf("2.\t Insert students");
			gotoxy(49,11);
			printf("3.\t Delete students");
			gotoxy(49,13);
			printf("4.\t Change students");
			gotoxy(49,15);
			printf("5.\t Search students");
			gotoxy(49,17);
			printf("6.    Statistics students");
			gotoxy(49,19);
			printf("7.\t     Return");
			gotoxy(49,21);
			printf("8.\t      Exit");
			gotoxy(42,23);
			printf("Press up and down to move and choose function");
			while(1)
			{
				r=7;
				gotoxy(44,r);
				printf("%c",2);
				gotoxy(46,r);
				printf(">>");
				gotoxy(81,r);
				printf("<<");
				gotoxy(84,r);
				k=1;
				while(1)
				{
					p1=getch();
					if(p1==13)
						break;
					if(p1==72)
					{
						gotoxy(44,r);
						printf(" ");
						gotoxy(46,r);
						printf("  ");
						gotoxy(81,r);
						printf("  ");
						if((r-2)<6)
						{
							gotoxy(44,21);
							printf("%c",2);
							gotoxy(46,21);
							printf(">>");
							gotoxy(81,21);
							printf("<<");
							gotoxy(84,21);
							k=8;
							r=21;
						}
						else
						{
							r-=2;
							gotoxy(44,r);
							printf("%c",2);
							gotoxy(46,r);
							printf(">>");
							gotoxy(81,r);
							printf("<<");
							gotoxy(84,r);
							k--;
						}

					}
					if(p1==80)
					{
						gotoxy(44,r);
						printf(" ");
						gotoxy(46,r);
						printf("  ");
						gotoxy(81,r);
						printf("  ");
						if((r+2)>22)
						{
							gotoxy(44,7);
							printf("%c",2);
							gotoxy(46,7);
							printf(">>");
							gotoxy(81,7);
							printf("<<");
							gotoxy(84,7);
							k=1;
							r=7;
						}
						else
						{
							r+=2;
							gotoxy(44,r);
							printf("%c",2);
							gotoxy(46,r);
							printf(">>");
							gotoxy(81,r);
							printf("<<");
							gotoxy(84,r);
							k++;
						}
					}
				}
				break;
			}
			system("cls");
			switch(k)
			{
				case 1:while(1)/*多种方式显示数据*/
					{
						system("cls");
						Sort(Head);
						if(b=='9')
							break;
						printf1(Head);
						printf("Press any key to continue,when input '1' return, input '0' end\n");
						n=getch();
						if(n=='1'||n=='0')
							break;
					}
					if(n=='0')
						return 0;
					continue;
				case 2:Head=Insert(Head);/*插入数据*/
					gotoxy(0,5);
					printf1(Head);
					printf("Press any key to returu, end when input '0'\n");
					n=getch();
					if(n==48)
					{
						printf("\nAre you sure to save information(press 'Y' to save, others don't save)\n");
						m=getch();
						if(m=='y'||m=='Y')
						{
							printf("Successfully saved at e:\\学生信息.txt\n");
							Save(Head);
						}
					}
					continue;
				case 3:while(1)
					{
						system("cls");
						Head=Delete(Head);/*删除数据*/
						gotoxy(0,4);
						printf1(Head);
						if(sum==0)
						{
							gotoxy(0,6);
							printf("All of persons have been deleted!                                          \n");
							printf("Press any key to return, when input '1' record information, input '0' end  \n");
						}
						else
							printf("Press any key to continue, when input '1' return, input '0' end            \n");
						n=getch();
						if(n=='0')
						{
							printf("\nAre you sure to save information(press 'Y' to save, others don't save)\n");
							m=getch();
							if(m=='y'||m=='Y')
							{
								printf("Successfully saved at e:\\学生信息.txt\n");
								Save(Head);
							}
							return 0;
						}
						if(sum==0)
						{
							if(n=='1')
							{
								system("cls");
								Head=creat();
							}
							break;
						}
						else
						{
							if(n=='1')
								break;
							continue;
						}
					}
					break;
				case 4:Change(Head);/*修改数据*/
					break;
				case 5:while(1)/*查找数据*/
					{
						system("cls");
						Search(Head);
						if(c=='4'||a=='1')
							break;
						if(sum!=e)
						{
							printf("Press any key to continue,when input '1' return, input '0' end\n");
							n=getch();
							if(n=='1'||n=='0')
								break;
						}
					}
					if(n==48)
						return 0;
					continue;
				case 6:while(1)/*统计数据*/
					{
						system("cls");
						Statistics(Head);
						if(e1=='4'||e2=='1')
							break;
						if(sum!=e)
						{
							printf("Press any key to continue,when input '1' return, input '0' end\n");
							n=getch();
							if(n=='1'||n=='0')
								break;
						}
					}
					if(n=='0')
						return 0;
					continue;
				case 7:break;
				case 8:printf("\nAre you sure to save information(press 'Y' to save, others don't save)\n");
					m=getch();
					if(m=='y'||m=='Y')
					{
						printf("Successfully saved at e:\\学生信息.txt\n");
						Save(Head);
					}
					return 0;
			}
			if(k==7)
			   break;
		}
		if(k!=7)
			break;
	}
	return 0;
}
