#include<windows.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<MMsystem.h>
#include<string>
using namespace std;

void showAdminLogin();
void showAdminHomePage();
void adminLogin();
void searchUser();
void delUser();

void showGuestLogin();
void guestSignIn();
void guestLogin();
void showGuestHomePage();
void addTask();
void delTask();

void showCredits();
void showAbout();
void exit();

string currentuser,currentuser2;

int main()
{
    string temp;
		system("cls");
		system("color 0");
		cout << "-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 1");
		cout << "-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 2");
		cout << "-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 3");
		cout << "|==     ==  =  ==    =  =   =====    ======   =====  ====== =       =    =    ====   =====|"<<endl;
		Sleep(300);
		system("color 4");
		cout << "|= =   = =  =  = =   =  =  =        =      =  =        =    =   =   =   = =   =   =  =    |"<<endl;
		Sleep(300);
		system("color 5");
		cout << "|=  = =  =  =  =  =  =  =   =====   =      =  ====     =    =  = =  =  =====  ====   ==== |"<<endl;
		Sleep(300);
		system("color 6");
		cout << "|=   =   =  =  =   = =  =        =  =      =  =        =    = =   = =  =   =  = =    =    |"<<endl;
		Sleep(300);
		system("color 7");
		cout << "|=       =  =  =    ==  =   =====    ======   =        =    ==     ==  =   =  =   =  =====|"<<endl;
		Sleep(300);
		system("color 8");
		cout << "-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color d");
		cout << "-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color e");
		cout << "-------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
	    cout << "                                 1) ADMIN MENU"<<endl;
		cout << "                                 2) GUEST MENU"<<endl;
		cout << "                                 3) Credits"<<endl;
		cout << "                                 4) About"<<endl;
		cout << "                                 5) Exit\n"<<endl;
		cout<<"Enter key ";
		PlaySound(TEXT("welcome.wav"),NULL,SND_SYNC);
	    cin >> temp;
		Beep(523,500);
	    if (temp == "1")
	    {
	        showAdminLogin();
	    }
	
	    else if (temp == "2")
	    {
	        showGuestLogin();
	    }
	    
		else if (temp == "3")
		{
			showCredits();
		}
		else if (temp == "4")
		{
			showAbout();
		}
		else if (temp == "5")
		{
			exit();
		}
		else 
		{
			cout<<"Re-Enter"<<endl<<"Wait for a while...";
			Sleep(3000);
			main();
		}
}
void showAdminLogin()
{
	system("cls");
	string temp;
	Sleep(300);
	system("color 4");
	cout<<"-------------------------------------------------------"<<endl;
    Sleep(300);
	system("color 2");
	cout<<"-------------Welcome to ADMIN Login Page---------------"<<endl;
    Sleep(300);
	system("color 3");
	cout<<"-------------------------------------------------------"<<endl<<endl;
    Sleep(300);
	system("color e");
	cout<<"1) Log in"<<endl;
    cout<<"2) BACK"<<endl<<endl;
    cout<<"Enter key ";
    cin>>temp;
    Beep(523,500);
	if(temp=="1")
	{
    	adminLogin();
	}
	else if (temp=="2")
	{
		main();
	}
	else
	{
		showAdminLogin();	
	}
}
void showAdminHomePage()
{
		system("cls");
		string flag;
        Sleep(300);
		system("color 0");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 1");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 2");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 3");
		cout<<"|               =    ====   ==   ==  =  ==    =  =====     =     ====   =====             |"<<endl;
		Sleep(300);
		system("color 4");
		cout<<"|              = =   =   =  = = = =  =  = =   =  =    =   = =   =       =                 |"<<endl;
		Sleep(300);
		system("color 5");
		cout<<"|             =====  =   =  =  =  =  =  =  =  =  =====   =====  =  ==   ====              |"<<endl;
		Sleep(300);
		system("color 6");
		cout<<"|             =   =  =   =  =     =  =  =   = =  =       =   =  =    =  =                 |"<<endl;
		Sleep(300);
		system("color 7");
		cout<<"|             =   =  ====   =     =  =  =    ==  =       =   =   ====   =====             |"<<endl;
		Sleep(300);
		system("color 8");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 9");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;	
		Sleep(300);
		system("color e");
		cout<<"-------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
		cout<< "                                 1) Search USER"<<endl;
		cout<< "                                 2) Delete USER"<<endl;
		cout<< "                                 3) BACK"<<endl<<endl;
		cout<<"Enter key ";
    	cin>>flag;
    	Beep(523,500);
	if (flag == "1")
	{
		searchUser();
	}
	else if (flag == "2")
	{
		delUser();
	}
	else if (flag == "3")
	{
		showAdminLogin();
	}
	else
	{
		showAdminHomePage();
	}
}
void searchUser()
{
	string line,user;
	bool username_printed=false;
	cout<<endl<<"Search User: ";
	cin>>user;
	user+=".txt";
	ifstream file;
	file.open(user.c_str());
	string user2;
		for(int i = 0; i < user.length(); i++) {
		 if(user[i] == '.') {
			break;
		}
		user2 += user[i];
		}
	if(!file) {
		cout << "This user does not exist" << endl;
		Sleep(2000);
		showAdminHomePage();
		return;
	}
	
	for(int i = 0; !file.eof(); i++) 
	{
		getline(file, line);
		if(line != "Website" && line != "Calculator" && line != "Game" && line != "Application") {
		if(username_printed) {continue;}
		cout <<endl<< "Username: " << user2 << endl;
		username_printed = true;
	} 
	else {
		cout << "Task: " << endl;
		cout << line << endl ;
	}
	}
		cout<<endl;
		system("pause");
		file.close();
		showAdminHomePage();
}
void delUser()
{
	string user;
	cout<<endl<<"Delete User :";
	cin>>user;
	user+= ".txt";
	remove(user.c_str());
	{
	Beep(523,500);
	cout<<endl<<"Deleting.";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
	Sleep(600);
	cout<<".";
	Sleep(600);
	cout<<".";
	Sleep(600);
	cout<<".";
    Sleep(600);
	cout<<".";
	Sleep(600);
	{
		system("cls");
		system("color b");
		cout<<"---------------------------"<<endl;
		Sleep(400);
		system("color c");
		cout<<"-------USER Deleted!-------"<<endl;
		Sleep(400);
		system("color e");
		cout<<"---------------------------"<<endl;
		Sleep(2000);
		showAdminHomePage();
	}
	}
}
void showGuestLogin()
{
	system("cls");
	string temp;
	Sleep(300);
	system("color 4");
	cout<<"-------------------------------------------------------"<<endl;
    Sleep(300);
	system("color 2");
	cout<<"-------------Welcome to GUEST Login Page---------------"<<endl;
    Sleep(300);
	system("color 3");
	cout<<"-------------------------------------------------------"<<endl<<endl;
    Sleep(300);
	system("color e");
	cout<<"1) Sign in"<<endl;
    cout<<"2) Log in"<<endl;
    cout<<"3) BACK"<<endl<<endl;
    cout<<"Enter key ";
    cin >> temp;
    Beep(523,500);
	if (temp=="1")
	{
		guestSignIn();
	}
	else if (temp=="2")
	{
		guestLogin();
	}
	else if(temp=="3")
	{
		main();
	}
	else 
	{
		showGuestLogin();
	}
}
void showGuestHomePage()
{
		system("cls");
		string flag;
		Sleep(300);
		system("color 0");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 1");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 2");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 3");
		cout<<"|              ====   =   =  =====   ====  =====  =====     =     ====   =====            |"<<endl;
		Sleep(300);
		system("color 4");
		cout<<"|             =       =   =  =      =        =    =    =   = =   =       =                |"<<endl;
		Sleep(300);
		system("color 5");
		cout<<"|             =  ==   =   =  ====    ====    =    =====   =====  =  ==   ====             |"<<endl;
		Sleep(300);
		system("color 6");
		cout<<"|             =    =  =   =  =           =   =    =       =   =  =    =  =                |"<<endl;
		Sleep(300);
		system("color 7");
		cout<<"|              ====    ===   =====   ====    =    =       =   =   ====   =====            |"<<endl;
		Sleep(300);
		system("color 8");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;
		Sleep(300);
		system("color 9");
		cout<<"-------------------------------------------------------------------------------------------"<<endl;	
		Sleep(300);
		system("color e");
		cout<<"-------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
		cout<<"                                 1) Add Task"<<endl;
		cout<<"                                 2) Delete Task"<<endl;
		cout<<"                                 3) BACK"<<endl;
		cout<<"Enter key ";
		cin>>flag;
		Beep(523,500);
	if (flag == "1")
	{
		addTask();
	}
	else if (flag == "2")
	{
		delTask();
	}
	else if (flag == "3")
	{
		showGuestLogin();
	}
	else 
	{
		showGuestHomePage();		
	}
}
void showCredits()
{
	system("cls");
	string flag;
	Sleep(300);
	system("color 1");
	cout << "------------------------------------"<<endl;
	Sleep(300);
	system("color 2");
	cout << "------------| Credits |-------------"<<endl;
	Sleep(300);
	system("color 3");
	cout << "------------------------------------"<<endl<<endl;
	Sleep(300);
	system("color e");
	cout<<"A";
	Sleep(100);
	cout<<"b";
	Sleep(100);
	cout<<"d";
    Sleep(100);
	cout<<"u";
	Sleep(100);
    cout<<"l";
    Sleep(100);
    cout<<" A";
    Sleep(100);
    cout<<"l";
    Sleep(100);
    cout<<"i";
    Sleep(100);
    cout<<" x";
    Sleep(100);
    cout<<" D";
    Sleep(100);
    cout<<"D";
    Sleep(100);
    cout<<"D";
	Sleep(100);
    cout<<"D"<<endl<<endl;
	{
	system("pause");
	Beep(523,500);
	main();
	}
}
void showAbout()
{
	system("cls");
	Sleep(500);
	system("color 1");
	cout<<"--------------------------------------"<<endl;
	Sleep(500);
	system("color 2");
	cout<<"--------------| About |---------------"<<endl;
	Sleep(500);
	system("color 3");
	cout<<"--------------------------------------"<<endl;
	Sleep(500);
	system("color e");
	Sleep(100);
    cout<<"A";
    Sleep(100);
    cout<<"O";
    Sleep(100);
    cout<<"A";
    Sleep(100);
    cout<<" <3";
	Sleep(100);
	cout<<" M";
	Sleep(100);
	cout<<"y";
	Sleep(100);
	cout<<" N";
    Sleep(100);
	cout<<"a";
	Sleep(100);
    cout<<"m";
    Sleep(100);
    cout<<"e";
    Sleep(100);
    cout<<" i";
    Sleep(100);
    cout<<"s";
	Sleep(100);
	cout<<" A";
	Sleep(100);
	cout<<"b";
	Sleep(100);
	cout<<"d";
    Sleep(100);
	cout<<"u";
	Sleep(100);
    cout<<"l";
    Sleep(100);
    cout<<" A";
    Sleep(100);
    cout<<"l";
    Sleep(100);
    cout<<"i.";
    Sleep(100);
    cout<<" I";
	Sleep(100);
	cout<<" h";
	Sleep(100);
	cout<<"a";
	Sleep(100);
	cout<<"v";
    Sleep(100);
	cout<<"e";
	Sleep(100);
    cout<<" u";
    Sleep(100);
    cout<<"s";
    Sleep(100);
    cout<<"e";
    Sleep(100);
    cout<<"d\n";
	Sleep(100);
	cout<<"4";
	Sleep(100);
	cout<<" F";
	Sleep(100);
	cout<<"u";
    Sleep(100);
	cout<<"n";
	Sleep(100);
    cout<<"c";
    Sleep(100);
	cout<<"t";
	Sleep(100);
	cout<<"i";
    Sleep(100);
	cout<<"o";
	Sleep(100);
    cout<<"n";
    Sleep(100);
	cout<<"a";
	Sleep(100);
	cout<<"l";
    Sleep(100);
	cout<<"i";
	Sleep(100);
    cout<<"t";
    Sleep(100);
	cout<<"i";
	Sleep(100);
	cout<<"e";
    Sleep(100);
	cout<<"s";
	cout<<" i";
	Sleep(100);
	cout<<"n";
	cout<<" M";
	Sleep(100);
	cout<<"y";
	Sleep(100);
	cout<<" p";
	Sleep(100);
	cout<<"r";
    Sleep(100);
	cout<<"o";
	Sleep(100);
    cout<<"j";
    Sleep(100);
    cout<<"e";
    Sleep(100);
    cout<<"c";
    Sleep(100);
    cout<<"t";
	Sleep(100);
    cout<<" &";
	Sleep(100);
    cout<<"\nM";
	Sleep(100);
	cout<<"y";
	Sleep(100);
	cout<<" p";
	Sleep(100);
	cout<<"r";
    Sleep(100);
	cout<<"o";
	Sleep(100);
    cout<<"j";
    Sleep(100);
    cout<<"e";
    Sleep(100);
    cout<<"c";
    Sleep(100);
    cout<<"t";
	Sleep(100);
	cout<<" n";
	Sleep(100);
	cout<<"a";
	Sleep(100);
	cout<<"m";
    Sleep(100);
	cout<<"e";
	Sleep(100);
    cout<<" i";
    Sleep(100);
    cout<<"s";
    Sleep(100);
    cout<<" M";
    Sleep(100);
    cout<<"I";
	Sleep(100);
	cout<<"N";
	Sleep(100);
	cout<<"I";
	Sleep(100);
	cout<<" S";
    Sleep(100);
	cout<<"O";
	Sleep(100);
    cout<<"F";
    Sleep(100);
    cout<<"T";
    Sleep(100);
    cout<<"W";
    Sleep(100);
    cout<<"A";
	Sleep(100);
	cout<<"R";
	Sleep(100);
	cout<<"E";
	Sleep(100);
	cout<<" :";
    Sleep(100);
	cout<<")\n\n";
	Sleep(100);
	{
	system("pause");
	Beep(523,500);
	main();
	}
}
void exit()
{ 
	exit(0);
}
void addTask()
{
		ofstream file;
		file.open(currentuser.c_str(),ios::app);
		system("cls");
		string user;
		for(int i = 0; i < currentuser.length(); i++) {
		 if(currentuser[i] == '.') {
			break;
		}
		user += currentuser[i];
		}
		currentuser2=user;
		string flag;
		cout<<"1) Website"<<endl;
		cout<<"2) Calculator"<<endl;
		cout<<"3) Game"<<endl;
		cout<<"4) Application"<<endl;
		cout<<"5) Back"<<endl<<endl;
		cout<<"Enter Key ";
		cin>>flag;
		Beep(523,500);
		if (flag=="1")
		{
			system("cls");
			system("color b");
			cout<<"----------------------------"<<endl;
			Sleep(400);
			system("color c");
			cout<<"-------Website Added!-------"<<endl;
			Sleep(400);
			system("color e");
			cout<<"----------------------------"<<endl;
			Sleep(2000);
			file << "Website" << endl;
			showGuestHomePage(); 
		}
		else if (flag=="2")
		{
			system("cls");
			system("color b");
			cout<<"-------------------------------"<<endl;
			Sleep(400);
			system("color c");
			cout<<"-------Calculator Added!-------"<<endl;
			Sleep(400);
			system("color e");
			cout<<"-------------------------------"<<endl;
			Sleep(2000);
			file << "Calculator" << endl;
			showGuestHomePage(); 
		}
		else if (flag=="3")
		{
			system("cls");
			system("color b");
			cout<<"-------------------------"<<endl;
			Sleep(400);
			system("color c");
			cout<<"-------Game Added!-------"<<endl;
			Sleep(400);
			system("color e");
			cout<<"-------------------------"<<endl;
			Sleep(2000);
			file << "Game" << endl;
			showGuestHomePage(); 
		}
		else if (flag=="4")
		{
			system("cls");
			system("color b");
			cout<<"--------------------------------"<<endl;
			Sleep(400);
			system("color c");
			cout<<"-------Application Added!-------"<<endl;
			Sleep(400);
			system("color e");
			cout<<"--------------------------------"<<endl;
			Sleep(2000);
			file << "Application" << endl;
			showGuestHomePage(); 
		}
		else if (flag=="5")
		{
			showGuestHomePage();
		}
		else 
		{
			addTask();	
		}
		file.close();
}
void delTask()
{
	string del;
	cout<<"Delete your task: ";
	cin>>del;
	string line;
	ifstream file;
	ofstream file2;
	file.open(currentuser.c_str());
	file2.open("temp.txt", ios::app);
	for(int i = 0; !file.eof(); i++) {
		getline(file, line);
		if(line != del) {
			file2 << line << endl;
		}
	}
	file.close();
	file2.close();
	
	file2.open(currentuser.c_str());
	file.open("temp.txt");
	
	for(int i = 0; !file.eof(); i++) {
		getline(file, line);
		file2 << line << endl;
	}
	
	file2.close();
	file.close();
	
	remove("temp.txt");
	Beep(523,500);
	cout<<endl<<"Deleting.";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
	Sleep(600);
	cout<<".";
	Sleep(600);
	cout<<".";
	Sleep(600);
	cout<<".";
    Sleep(600);
	cout<<".";
	Sleep(600);
	{
		system("cls");
		system("color b");
		cout<<"---------------------------"<<endl;
		Sleep(400);
		system("color c");
		cout<<"-------TASK Deleted!-------"<<endl;
		Sleep(400);
		system("color e");
		cout<<"---------------------------"<<endl;
		Sleep(2000);
		showGuestHomePage();
	}
}
void guestLogin()
{
		system("cls");
		string user,pass,user2,pass2;
		cout<<"-------------------------------------------------------"<<endl;
	    cout<<"-------------Welcome to GUEST Login Page---------------"<<endl;
	    cout<<"-------------------------------------------------------"<<endl<<endl;
		cout<<"Enter Username: ";
		cin>>user;
		cout<<"Enter Password: ";
		cin>>pass;
		Beep(523,500);
		cout<<"Processing.";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
		Sleep(600);
		ifstream file;
		user += ".txt";
		currentuser = user;
		file.open(user.c_str());	
		if(!file) 
		{
		cout<<"\n\nAccount does not exist!";
		cout<<"\nWait for while...";
		Sleep(3000);
		{
			showGuestLogin();
		}
		} 
		string user3;
		for(int i = 0; i < user.length(); i++) {
		 if(user[i] == '.') {
			break;
		} 
		user3 += user[i];
		}
		currentuser2=user3;
		getline(file, user2);	
		getline(file, pass2);	
		if(user2 != user3 || pass2 != pass) 
		{
		Sleep(1000);
		cout<<"\n\nIncorrect Password!"<<endl;
		cout<<user<<endl<<endl<<pass<<endl;
	 	cout<<"Wait for while...";
	 	Sleep(3000);
		{
			guestLogin();
		}
		} 
			
		else if(user2 == user3 && pass2 == pass)
		{
		Sleep(500);
		file.close();
		showGuestHomePage();
		}
}
void guestSignIn()
{
		system("cls");
		string user,pass;
		cout<<"--------------------------------------------------"<<endl;
		cout<<"-------------Welcome to GUEST Sign IN-------------"<<endl;
		cout<<"--------------------------------------------------"<<endl<<endl;
		cout<<"Enter New Username: ";
		cin>>user;
		cout<<"Enter New Password: ";
		cin>>pass;
		Beep(523,500);
		cout<<endl<<"Processing.";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
	    cout<<".";
	    Sleep(600);
		system("cls");
		Sleep(400);
		system("color b");
		ofstream file;
		user += ".txt";
		string user2;
		file.open(user.c_str(), ios::app);
		for(int i = 0; i < user.length(); i++) {
		if(user[i] == '.') {
			break;
		} 
		user2 += user[i];
		}
		file << user2 << endl;
		file << pass << endl;
		file.close();
		file.open("guestuser.txt", ios::app);
		file << user2 << endl;
		cout<<"------------------------------------------------"<<endl;
		Sleep(400);
		system("color c");
		cout<<"-------Congratulation! You are Registered-------"<<endl;
		Sleep(400);
		system("color e");
		cout<<"------------------------------------------------"<<endl;
		Sleep(2000);
		file.close();
		{
		showGuestLogin();
		}
}
void adminLogin()
{
	system("cls");
	string adminUser,adminPass;
	cout<<"---------------------------------------------------"<<endl;
	cout<<"-------------Welcome to ADMIN Login----------------"<<endl;
	cout<<"---------------------------------------------------"<<endl<<endl;
	cout<<"Enter ID: ";
    cin>>adminUser;
    cout<<endl<<"Enter Password: ";
    cin>>adminPass;
    Beep(523,500);
    cout<<endl<<"Processing.";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    Beep(523,500);
    if (adminPass=="12345" && adminUser=="admin")
    {
    	showAdminHomePage();
	}
	else 
	{
		Sleep(600);
		cout<<endl<<endl<<"WRONG ID & PASSWORD PLEASE TRY AGAIN!!!"<<endl;
		cout<<endl<<"Wait for while...";
		Sleep(3000);
		{
			showAdminLogin();
		}
	}
}
