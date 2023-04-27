#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class File
{
public:
	string x;
	void add_tn(string y)
	{
		ofstream create("Teachers_n.txt", ios::app);
		create << y << endl;
		create.close();
	}
	void add_tid(string y)
	{
		ofstream create("Teachers_id.txt", ios::app);
		create << y << endl;
		create.close();
	}
	void add_tpass(string y)
	{
		ofstream create("Teachers_pass.txt", ios::app);
		create << y << endl;
		create.close();
	}
	void add_sn(string y)
	{
		ofstream create("student_n.txt", ios::app);
		create << y << endl;
		create.close();
	}
	void add_sid(string y)
	{
		ofstream create("student_id.txt", ios::app);
		create << y << endl;
		create.close();
	}
	void add_spass(string y)
	{
		ofstream create("student_pass.txt", ios::app);
		create << y << endl;
		create.close();
	}
};