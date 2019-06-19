/*
	Name: Project Initer
	Author: Eike Wientjes
	Description: Inits C++ Projects with readme.md file.
	Version: v1.1.1
*/
#include <iostream>
#include <conio.h>
#include <fstream>
#include <direct.h>
#include <windows.h>
#include <time.h>
using namespace std;

const string VERSION = "v1.1.1";
static int progress = -1;
static int sleep_time = 50;

void gotoxy (int x, int y)
{
    COORD coord;
    coord.X = x - 1; 
	coord.Y = y - 1; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void updateProgressBar() {
	progress++;
	gotoxy(1, 23);
	cout << "Progress: ";
	
	switch(progress) {
		case 0:
			cout << "0% - [ ]";
			break;
		case 1:
			cout << "10% - [";
			for(int i = 0; i < 4; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;
		case 2:
			cout << "20% - [";
			for(int i = 0; i < 8; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;;
		case 3:
			cout << "30% - [";
			for(int i = 0; i < 12; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;
		case 4:
			cout << "40% - [";
			for(int i = 0; i < 16; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;
		case 5:
			cout << "50% - [";
			for(int i = 0; i < 20; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;
		case 6:
			cout << "60% - [";
			for(int i = 0; i < 24; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;
		case 7:
			cout << "70% - [";
			for(int i = 0; i < 28; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;
		case 8:
			cout << "80% - [";
			for(int i = 0; i < 32; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;
		case 9:
			cout << "90% - [";
			for(int i = 0; i < 36; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;
		case 10:
			cout << "100% - [";
			for(int i = 0; i < 40; i++) {
				cout << "#";
				Sleep(sleep_time);
			}
			cout << "]";
			break;
	}
}

int main()
{
	updateProgressBar();
	string 	projekt_name, 
			filename, 
			infofile, 
			desc, 
			author, 
			version,
			includes[255];
			
	char foldername[255];
	int includes_count;
	
	gotoxy(1, 1);
	cout << "Project Initer -|- [Build: " << VERSION << "]";
	Sleep(750);

	gotoxy(1, 3);
	cout << "Project Name: ";
	cin >> projekt_name;
	updateProgressBar();
	
	gotoxy(1, 4);
	cout << "Folder name: ";
	cin >> foldername;
	updateProgressBar();
	
	gotoxy(1, 5);
	cout << "Beschreibung: ";
	cin >> desc;
	updateProgressBar();
	
	gotoxy(1, 6);
	cout << "Autor: ";
	cin >> author;
	updateProgressBar();
	
	gotoxy(1, 7);
	cout << "Version: ";
	cin >> version;
	updateProgressBar();
	
	gotoxy(1, 8);
	cout << "How many #includes do you need ?";
	gotoxy(1, 9);
	cout << "Count: ";
	cin >> includes_count;
	updateProgressBar();
	
	if(includes_count != 0) {
		for(int i = 0; i < includes_count; i++) {
			gotoxy(1, i + 10);
			cout << i + 1 << ". Include: ";
			cin >> includes[i];
		}
		updateProgressBar();
	}else {
		gotoxy(1, 10);
		cout << "You have to include some libarys!";
		getch();
		return 0;
	}
	
	mkdir(foldername);
	
	filename = (string)foldername + "/" + projekt_name + ".cpp";
	infofile = (string)foldername + "/Readme.md";
	
	ofstream output(filename.c_str());
	output << "/*\n";
	output << "\tName: " << projekt_name << "\n";
	output << "\tAuthor: " << author << "\n";
	output << "\tVersion: " << version << "\n";
	output << "\tDescription: " << desc << "\n";
	output << "*/\n\n";
	
	for(int i = 0; i < includes_count; i++) 
		output << "#include <" << includes[i] <<">\n";
		
  	output << "using namespace std;\n\n";
  	output << "int main()\n{\n\n\tgetch();\n\treturn 0;\n}";
  	output.close();
  	
  	updateProgressBar();
  	Sleep(500);
  	
  	ofstream output_1(infofile.c_str());
  	output_1 << "Name: " << projekt_name << endl;
  	output_1 << "Description: " << desc << endl;
  	output_1 << "Author: " << author << endl;
  	output_1 << "Version: " << version << endl;
  	output_1.close();
  	
  	updateProgressBar();
  	Sleep(500);
  	
  	updateProgressBar();
  	cout << endl << "Project were created!";
  	
	getch();
	return 0;
}
