#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
	int c;
	cout<<"\t\t\t_______________________________________\n\n\n";
	cout<<"\t\t\t__________WELCOME TO LOGIN PAGE________\n\n\n";
	cout<<"\t\t\t_______________MENU________________________\n\n";
	cout<<"                                                 \n\n";
	cout<<"\t| Press 1 to Login  |"<<endl;
	cout<<"\t| Press 2 to REGISTER  |"<<endl;
	cout<<"\t| Press 3 if you forgot your password  |"<<endl;
	cout<<"\t| Press 4 to Exit  |"<<endl;	
	cout<<"\t| Enter your choice:"<<endl;
	cin>>c;
	cout<<endl;
	switch(c)
	{
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout<<"\t\t\t THANk you!!\n\n";
		default:
			cout<<"\t\t\t please select the option given in the above";
			main();
			
}
}
void login()
{
	int count;
	string userid,password,id,pass;
	system("cls");
	cout<<"\t\t\t Please enter the username and password "<<endl;
	cout<<"\t\t\t USERNAME";
	cin>>userid;
	cout<<"\t\t\t PASSWORD";
	cin>>password;
	
	
	ifstream input("record.txt");
	
	while(input>>id>>pass)
	{
		if(id==userid && pass==password)
		{
			count=1;
			system("cls");
			
		}
	}
	
	input.close();
	
	if(count==1)
	{
		cout<<userid<<"\n your login is successfull\n";
		main();
		
		
			}
			else{
				cout<<"\n LOGIN ERROR \n Please check your username and password \n";
				main();
				
				
			}
}
void registration()
{
	string ruserid,rpassword,rid,rpass;
	system("cls");
	cout<<"\t\t\t Enter the username";
	cin>>ruserid;
	cout<<"\t\t\tEnter the password:";
	cin>>rpassword;
	
	
	ofstream f1("record.txt",ios::app);
	f1<<ruserid<<" "<<rpassword<<endl;
	system("cls");
	cout<<"\n\t\t\t registration is successfull\n";
	main();
	
	
}
void forgot()
{
	int option;
	system("cls");
	cout<<"\t\t\t you forgot your password? No worries";
	cout<<"press 1 to search your username";
	cout<<"press 2 to go to back to your main menu ";
	cout<<"\t\t\t enter your choice";
	cin>>option;
	switch(option)
	{
		case 1:{
			int count=0;
			string suserid,sid,spass;
			cout<<"\n\t\t\t enter your username which you remember";
			cin>>suserid;
			
			ifstream f2("record.txt");
			while(f2>>sid>>spass)
			{
				if(sid==suserid)
				{
					count=1;
					
				}
			}
			f2.close();
			if(count==1)
			{
				cout<<"\n\n Your account is found\n";
				cout<<"\n\n your password is"<<spass;
				main();
				
			}
			else{
				cout<<"\n\t sorry your account is not found!\n";
				main();
				
			}
			break;
			
			}
			case 2:
				{
					main();
					
				}
				default:
					cout<<"\t\t\t Wrong choice ! Please try again";
					forgot();
					
			
		}
	}

