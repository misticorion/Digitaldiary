/*
            COMPUTER PROJECT  2015-16

           C++ POGRAM ON  DIGITAL DIARY


                                          													       -  	SUMEDHAA    ,   XII B

*/

#include<stdlib.h>
#include <iostream>
#include<stdio.h>
#include <conio.h>
#include <fstream>
#include <math.h>
#include <string.h>
#include<process.h>
#include<dos.h>
 ifstream fin;
 ofstream fout;
void create();
void disp();
void alphw();
void alpho();
void dispno();
void dispnam();
void append();
void del();
void contact();
void display();
void note();
void create2();
void disp2();
void del2();
void calc();
void passwordmanager();
void displaydate();
int r;
class cont
{
	long int tno;
	char tname[20];
	public:
	void input()
	{   cout<<"Number";
		cin>>tno;
		cout<<"Name";
		cin>>tname;
		//gets(tname);
	}
	void output()
	{
		cout<<"\n\t\tPhone Number "<<tno<<"\tName "<<tname;
	}
	char *retname()
	{
		return tname;
	}
	long retno()
	{
		return tno;
	}
	void modinam();
	void modino();
}c,c1[20],t;

class calculator
{
	public:
	double num1,num2;
	void add()
	{
		cout<<"\nSum of "<<num1<<"and"<<num2<<" ="<<(num1+num2)<<"\n";
		getch();
	}
	void sub()
	{
		cout<<"\nDifference of "<<num1<<"and"<<num2<<" ="<<(num1-num2)<<"\n";
		getch();
	}
	void multiply()
	{
		cout<<"\nProduct of "<<num1<<"and"<<num2<<" ="<<(num1*num2)<<"\n";
		getch();
	}
	void divide()
	{
		cout<<"\nQuotient of "<<num1<<"and"<<num2<<" ="<<(num1/num2);
		getch();
	}
}cal;
struct pas
{
	char category[30],pass[20];
}s;
struct mast
{
	char user[30],masterpass[30];
}masters;
// **********************MAIN  FUNCITON BEGINS *********************************
int main()
{
	int ch;
	cout<<"WELCOME";
	getch();
	do
	{
		clrscr();
		cout<<"\n\n\n\n\t\t\t MENU\n\n";
		cout<<" 1. CONTACT\n\n";
		cout<<" 2. NOTES\n\n";
		cout<<" 3. PASSWORD MANAGER\n\n";
		cout<<" 4. CALCULATOR\n\n";
		cout<<" 5. EXIT\n\n";
		cout<<" ENTER YOUR CHOICE\n\n";
		cin>>ch;
		 switch(ch)
		{
			case 1: contact();
			break;
			case 2: note();
			break;
			case 3: passwordmanager();
			break;
			case 4: calc();
			break;
		}
	}
	while(ch<5);
		getch();
	return 0;
}
// *********************MAIN  FUNCITON ENDS ************************************
//**********************BEGIN OF CREATE*****************************************
void create()
{
	int n;
	cout<<"\n Enter The Number Of Data\t";
	cin>>n;
	fout.open("contact.txt",ios::binary|ios::app);
	for(int i=0;i<n;i++)
	{
		 c.input();
		fout.write((char*)&c,sizeof(c));
	}
	fout.close();

}
//****************************END OF CREATE*************************************
//****************************BEGIN OF APPEND***********************************
void append()
{
	int n;
	fout.open("contact.txt",ios::app | ios::binary);
	cout<<"\n Enter The Number Of Records To Be Added \t";
	cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"\n Enter Number And Name \n";
			c.input();
			fout.write((char*)&c,sizeof(c));
		}
		fout.close();
}
//*****************************END OF APPEND************************************
//*****************************BEGIN OF DEL*************************************
void del() 
{
	fin.open("contact.txt",ios::binary|ios::in);
	fout.open("temp.txt",ios::binary|ios::app);
	char s[20];
	int found=0;
	cout<<"\n Enter The Name To Be Deleted\t";
	cin>>s;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(strcmpi(c.retname(),s)!=0)
			fout.write((char*)&c,sizeof(c));
		else
			{
			found=1;

			}
	}
	fin.close();
	fout.close();
	if(found==0)
		cout<<"\n Data Not There In The File\n";
	else
	{
		cout<<"\n\n\t\tDELETING... \n";
		remove("contact.txt");
		rename("temp.txt","contact.txt");
	}
	getch();
}
//*************END OF DEL**********************
//*************BEGIN OF contact (MODINAM)***************
void cont::modinam()
{
	fin.open("contact.txt",ios::binary);
	fout.open("temp.txt",ios::binary);
	int found=0; char s[20];
	cout<<"\n Enter The Name To Be Modified\t";
	cin>>s;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(strcmpi(c.retname(),s)==0)
		{
		cout<<"\n Enter The New Name\t"; cin>>c.tname;
		fout.write((char*)&c,sizeof(c)); found=1;
		}
		else
			fout.write((char*)&c,sizeof(c));
	}
	fin.close();
	fout.close();
		if(found==0)
			cout<<"\n Data Not There In The File\n";
		else
		{
			cout<<"\n\n\t\tMODIFIED...";
			remove("contact.txt");
			rename("temp.txt","contact.txt");
		}
	getch();
}
//*************END OF contact (MODIANAM)**************
//*************BEGIN OF contact (MODIANNO)**************
void cont:: modino()
{
	fin.open("contact.txt",ios::binary);
	fout.open("temp.txt",ios::binary|ios::app);
	int found=0; long int z;
	cout<<"\n Enter The Number To Be Modified\t";
	cin>>z;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(z==c.retno())
		{
			cout<<"\n Enter The New Number\t";
			cin>>c.tno;
			fout.write((char*)&c,sizeof(c));
			found=1;
		}
		else
			fout.write((char*)&c,sizeof(c));
	}
	fin.close();
	fout.close();
	if(found==0)
	cout<<"\n Data Not There In The File\n";
	else
	{
		cout<<"\n\n\t\tMODIFIEd..";
		remove("contact.txt");
		rename("temp.txt","contact.txt");
	}
	getch();
}
//*************END OF contact (MODIANNO)**************
//*************BEGIN OF DISPNO*************************
void dispno()
{
	fin.open("contact.txt",ios::binary|ios::in);
	char x[20];
	int found=0;
	cout<<"\n Enter The Name Of The Person \n";
	cin>>x;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(strcmpi(c.retname(),x)==0)
		{
			found=1;
			c.output();
			break;
		}
	}
	if(found==0) cout<<"\n Not In File";
	fin.close();
	getch();
}
//*************END OF DISPNO*************************
//*************BEGIN OF DISPNAM*************************
void dispnam()
{
	long int y;
	fin.open("contact.txt",ios::binary); int found=0;
	cout<<"\n Enter The Telephone Number Of The Person \n"; cin>>y;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.retno()==y)
		{
			found=1;
			c.output();
			break;
		}
	}
	if(found==0) cout<<"\n Not In File";
	fin.close();
	getch();
}
//*************END OF DISPNAM*************************
//*************BEGIN OF ALPHO*************************
void alpho()
{

fin.open("contact.txt",ios::binary|ios::in);
fin.clear();
	int i=0;
	long int si=0;
	while(fin.read((char*)&c1[i],sizeof(c1[i])))
	{
	si+=sizeof(c1[i]);
		i++;
	}
	int n=i;
	for( i=0;i<n;i++)
		for(int j=0;j<n-1;j++)
			if (strcmpi(c1[j].retname(),c1[j+1].retname())>0)
	 		{
				t=c1[j]; c1[j]=c1[j+1]; c1[j+1]=t;
			}
	cout<<"\n\n\n\n\t\t\tLIST OF contact ALHABETICAL ORDER\n\n";
	/*if(n==0)
	cout<<"No records found";*/
	for (int k=0;k<n;k++)
	{c1[k].output();}
	getch();
 	 fin.seekg(0,ios::beg);
	fin.close();
	 fin.clear();
}
//*************END OF ALPHO*************************
//*************BEGIN OF contact*************************
void contact()
{
//	create();
	//system("cls");
	clrscr();
	int ch1;
	do
	{
		//system("cls");
      clrscr();
		cout<<" \n\n\n\n\t\t\t Menu\n\n";
		cout<<"\t 1. Display Options\n\n";
		cout<<"\t 2. Modify Record\n\n";
		cout<<"\t 3. Add New Record\n\n";
		cout<<"\t 4. Delete Record\n\n";
		cout<<"\t 5. Exit\n\n";
		cout<<"\t Enter Your Choice ";
		cin>>ch1;
		switch(ch1)
		{
			case 1:display();
			break;
			case 2:clrscr();//system("cls");
			int ch3;
			do
			{
				clrscr();//system("cls");
				cout<<" Menu\n\n";
				cout<<" 1. Modify Name\n";
				cout<<" 2. Modify Number\n";
				cout<<" 3. Exit\n\n";
				cout<<" Enter Your Choice\n"; cin>>ch3;
				switch(ch3)
				{
					case 1:c.modinam();
					break;
					case 2:c.modino();
					break;
					default:cout<<"\n Please Enter The Correct Choice\n";
				}
			}
			while(ch3<3);
			break;
			case 3:append();
			break;
			case 4:del();
			break;
		}
	}
	while(ch1<5);
}
//*************END OF contact*************************
//*************BEGIN OF DISPLAY*************************
void display()
{
	clrscr();//system("cls");
	 int ch2;
	do
	{
		clrscr();//system("cls");
		cout<<" \n\n\n\t\t\t Menu\n\n";
		cout<<"\n\t 1.Alphabetical Order\n";
		cout<<"\n\t 2.Display Number\n";
		cout<<"\n\t 3.Display Name\n";
		cout<<"\n\t 4.Exit\n\n";
		cout<<" Enter Your Choice ";
		cin>>ch2;
		switch(ch2)
		{
			case 1:alpho();
			fin.clear();
			break;
			case 2:dispno();
			break;
			case 3:dispnam();
			break;
		}
	}
	while(ch2<4);
	getch();

}
//*************END OF DISPLAY*************************
//*************BEGIN OF CREATE2*************************
void create2()
{
	 ofstream  fout;
	char str[20];
	int i=0;
	cout<<"\n Enter Limit \t";
	cin>>r;
    fout.open("note.txt",ios::app);
	while(i<r)
	{
	 cout<<"\nEnter string";
	 cin>>str;
	 fout<<str<<endl;
	 cout<<"\nString Successfully Entered";
	 ++i;
	}
	fout.close();
}
//*************END OF CREATE2*************************
//*************BEGIN OF DISP2*************************
void disp2()
{
	ifstream fin("note.txt",ios::in);
	char ch[10];
	int q=0;  //to count and number notes

	while(fin>>ch)
	{   
		 q++;
	    cout<<"NOTE "<<q<<": "<<ch<<endl;      	
	 }
	fin.close();
}
//*************END OF DISP2*************************
//*************BEGIN OF note*************************
void note()
{
	clrscr();//system("cls");
	int ch4;
	do
	{
		cout<<"	Menu\n\n";
		cout<<"	l.Create note\n";
		cout<<"	2.Display note\n";
		cout<<" 3.Exit\n\n";
		cout<<"Enter Your Choice\n";
		cin>>ch4;
		switch(ch4)
		{
			case 1:create2();
			break;
			case 2:disp2();
			break;
		}
	}
	while(ch4<3);
}
//*************END OF note*************************
//*************BEGIN OF PASSWORDMANAGER*************************
void passwordmanager()
{
	clrscr();//system("cls");
	char name[30],master1[30],ch;
	int j;
	char choice;
	ifstream fin,fmasterin;
	ofstream fout,fmasterout;
	int p;
	clrscr();//system("cls");
	cout<<"\n\n\n\t\tPASSWORD MANAGER\n\n";
	do
	{
	cout<<"\n\t\t1. Give a master password\n\n";
	cout<<"\n\t\t2. Retrieve the password\n\n";
	cout<<"\n\t\t3. Add category to existing user";
	cout<<"\n\t\t4. Exit";
	cout<<"\n \n\n\t\tYour choice \n";
	cin>>p;
	switch (p)
	{
		case 1:
			{
			clrscr();//system("cls");
			cout<<"\n\t\tEnter your username";
			cout<<"\n\t\t";
			gets(name);
			fout.open("Name.txt",ios::app| ios::binary);
			do
			{
				cout<<"\n\t\tEnter the category";
				cout<<"\n\t\t";
				gets(s.category);
				cout<<"\n\tEnter the corresponding password";
				 cout<<"\n\t\t";
				j=0;
				do
				{
					ch=getch();
					s.pass[j]=ch;
					if(ch!=13)
						cout<<"*";
						j++;
				}
				while(ch!=13);
				s.pass[j-1]='\0';
				getch();
				fout.write((char*)&s,sizeof(s));
				cout<<"\n\t\tto continue press any key, to exit press 0"<<endl;
				cin>>choice;
				if(choice==0)
					break;
			}
			while(choice!=48);
			char ch2;
			int y=0;
			cout<<"\n\n\t enter a master password";
			cout<<"\n\t";
			do
			{
				ch2=getch();
				master1[y]=ch2;
				if(ch2!=13)
				cout<<"*";
				y++;
			}
			while
			(ch2!=13); master1[y-1]='\0';
			strcpy(masters.masterpass,master1);
			strcpy(masters.user,name);
			fmasterout.open("master.txt",ios::app|ios::binary);
			fmasterout.write((char *)&masters,sizeof (masters)); fout.close();
			fmasterout.close();
			cout<<" \n\n\n\t\tYOU HAVE SUCCESSFULLY CREATED A MASTER PASSWORD..\n";
			getch();
			 }
		break;

		case 2:
		{
		/* retrieving the password*/
		fmasterin.open("master.txt",ios::in|ios::binary);
		fmasterin.read((char *)&masters,sizeof(masters));
		fmasterin.close();
		int tru=1;
		char cat[20];
		char p2[30];
		int count2=0,z=0;
		char choice5;
		do
		{
			count2++;
			 clrscr();//system("cls");
			 cout<<"\n";
			cout<<"\n\n\n\n\n\n\t\t\tEnter the username";
			cout<<"\t";
			gets(name);
			char ch3;
			cout<<"\n\n\t\t\tEnter the master password"<<"\n\t\t";

			do
			{
				ch3=getch();
				p2[z]=ch3;
				if(ch3!=13)
				cout<<"*";
				z++;
			}
			while(ch3!=13); p2[z-1]='\0';
			if((strcmpi(name,masters.user)==0)&&(strcmpi(p2,masters.masterpass)==0))
			{
				 cout<<"\n\n\t\tEntered username and password donot match";
				cout<<"\n\n\t if you forgot the password and want to exit press0";
				cout<<"\n\n\t press any key to continue";
				choice5=getch();
				if(choice5==48)
				exit(0);
			}
			else
			 {
				tru=0;
			 }
		}
		while(tru!=0&&count2<3);
		if(count2==3&&tru!=0)
		{
			cout<<"\n\n\tSorry only 3 tries..";
			getch();

		}

	/*works only if user name and the password matches*/
		char choice2; clrscr();//system("cls");
		if(tru==0)
		{
			cout<<"\n\t The entered master password and the username match";
		}
		do
		{
			fin.open("Name.txt",ios::in | ios::binary);
			 cout<<"\n";
			cout<<"\n\tEnter the category";
			cout<<"\n\t";
			gets(cat);
			int found=0;
			while(fin.read((char*)&s,sizeof(s)))
			{
				if(strcmp(cat,s.category)==0)
				{
					found=1;
					cout<<"\n\tThe password is";
					cout<<"\n\t";
					puts(s.pass);
					/*cout<<"\n\t Concerning the user's security";
					cout<<"\n\tThe screen will be cleared automatically";
					delay(4);
					clrscr();//system("cls"); */
					 break;
				}
			}
			if(found==0)
			{
				clrscr();//system("cls");
				cout<<"\n\tthe requested category is not found";
				getch();
			}
			fin.close();
		cout<<"\n\tCheck another category?? y/n ";
		cout<<"\n\t";
		cin>>choice2;
		}
		while(choice2=='y');
		getch();
		}
		 break;

	  case 3:
		 fmasterin.open("master.txt",ios::in|ios::binary);
		fmasterin.read((char *)&masters,sizeof(masters));
		fmasterin.close();
		int tr=1;
		char ca[20];
		char p3[30];
		int count3=0,q=0;
	 char choicer;
		do
		{
		cout<<"\nEnter the username";
			count3++;
			 clrscr();//system("cls");
			 cout<<"\n";
			cout<<"\n\n\n\n\n\n\t\t\tEnter the username";
			cout<<"\t";
			gets(name);
			char ch4;
			cout<<"\n\n\t\t\tEnter the master password"<<"\n\t\t";

			do
			{
				ch4=getch();
				p3[q]=ch4;
				if(ch4!=13)
				cout<<"*";
				q++;
			}
			while(ch4!=13);
			 p3[q-1]='\0';
			if((strcmpi(name,masters.user)==0)&&(strcmpi(p3,masters.masterpass)==0))
			{ cout<<"\n\n\t\tEntered username and password donot match";
			  cout<<"\n\n\tIf you forgot the password and want to exit press0";
				cout<<"\n\n\tPress any key to continue";
				choicer=getch();
				if(choicer==48)
				exit(0);
				}
			else
			{
				tr=0;
			}
		}
		while(tr!=0&&count3<3);
		if(count3==3&&tr!=0)
		{
			cout<<"\n\n\tSorry only 3 tries..";
			getch();
		}

	/*works only if user name and the password matches*/
		char choicee;
		clrscr();//system("cls");
		if(tr==0)
			cout<<"\n\t The entered master password and the username match";
		do
		{
			fout.open("Name.txt",ios::app| ios::binary);
			 cout<<"\n";
			cout<<"\n\tEnter the category";
			cout<<"\n\t";
			gets(ca);
			strcpy(s.category,ca);
			cout<<"\nEnter corresponding password";
			 q=0;
			 char ch2;
			do
			{
				ch2=getch();
				p3[q]=ch2;
				if(ch2!=13)
				cout<<"*";
				q++;
			}
			while(ch2!=13);
			strcpy(s.pass,p3);
			fout.write((char*)&s,sizeof(s));
			fout.close();
			cout<<"\nDo you want to enter more";
			cin>>choicee;
		}
		while(choicee=='y');
		getch();
		break;

			 }}

		while(p!=4);
}
//*******************************END OF PASSWORDMANAGER*************************
//*******************************BEGIN OF CALC**********************************
void calc()
{
	int ch5,cf=0;
	do
	{
		clrscr();//system("cls");
		cout<<" \n Menu\n\n";
		cout<<" 1.Add 2 Numbers\n";
		cout<<" 2.Subtract 2 Numbers\n";
		cout<<" 3.Divide 2 Numbers\n";cout<<" 4.Multiply 2 Numbers\n";
		cout<<" 5.Exit\n\n";
		cout<<" Enter Your Choice\n";
		cin>>ch5;
		switch(ch5)
		{
			case 1: cout<<"\n Enter Two Numbers\n";
			cin>>cal.num1>>cal.num2; cal.add();
			break;
			case 2: cout<<"\n Enter Two Numbers\n";
			cin>>cal.num1>>cal.num2; cal.sub();
			break;
			case 3: cout<<"\n Enter Two Numbers\n";
			cin>>cal.num1>>cal.num2; cal.divide();
			break;
			case 4: cout<<"\n Enter Two Numbers\n";
			cin>>cal.num1>>cal.num2;cal.multiply();
			break;
		}
	}
	while(ch5<5);
	getch();
}

