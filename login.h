#include "file.h"
using namespace std;
class reg
{
	private:
		string name;
		string y;
		//int n;
	public:
		void Register_t(string name, string id, string password)
		{
			File f;
			f.add_tn(name);
			f.add_tid(id);
			f.add_tpass(password);
		}
		void Register_s(string name, string id, string password)
		{
			File f;
			f.add_sn(name);
			f.add_sid(id);
			f.add_spass(password);
		}
};
class login : protected reg
{
private:
	string name_t,name_s, password_t,password_s;
	string id_s, id_t;
	bool login_t;
	bool login_s;
public:
	void Login_t(string nam_t, string idd_t, string pass_t)
	{
		name_t = nam_t;
		id_t = idd_t;
		password_t = pass_t;
	}
	void Login_s(string nam_s, string idd_s, string pass_s)
	{
		name_s = nam_s;
		id_s = idd_s;
		password_s = pass_s;
	}
	void log_t(string nam_t, string idd_t, string pass_t)
	{
		string passw_t;
		string nae;
		name_t = nam_t;
		char y;
		string i_t;
		login_t = false;
		ifstream Open_nt("Teachers_n.txt");
		ifstream Open_it("Teachers_id.txt");
		ifstream Open_pt("Teachers_pass.txt");

		while (getline(Open_nt, nae) && getline(Open_it, i_t) && getline(Open_pt, passw_t))
		{
			if (name_t == nae && id_t == i_t && password_t == passw_t)
			{
				login_t = true;
			}
		}
		Open_nt.close();
		Open_it.close();
		Open_pt.close();
		if (login_t)
		{
			Login_t(name_t, id_t, password_t);
			cout << "Login Successful" << endl;
			cout << name_t << "\t" << id_t << "\t" << password_t << endl;
		}
		else
		{
			cout << "You are not Registered\nPls Register 1st..." << endl;
			cout << "Do you Want to Register\nPls type y or n";
			cin >> y;
			if (y == 'y' || y == 'Y')
			{
				reg :: Register_t(name_t,id_t,password_t);
			}
			/*else if (y == 'n' || y = 'N')
			{
				exit(0);
			}*/
		}

	}
	void log_s(string nam_s, string idd_s, string pass_s)
	{
		string passw_s;
		string nae;
		name_s = nam_s;
		//id_s = idd_s;
		char y;
		string i_s;
		ifstream Open_ns("Student_n.txt");
		ifstream Open_is("Student_id.txt");
		ifstream Open_ps("Student_pass.txt");
		login_s = false;

		while (getline(Open_ns, nae) && getline(Open_is, i_s) && getline(Open_ps, passw_s))
		{
			if (name_s == nae && id_s == i_s && password_s == passw_s)
			{
				login_s = true;
			}
		}
		Open_ns.close();
		Open_is.close();
		Open_ps.close();
		if (login_s)
		{
			Login_s(name_s, idd_s, pass_s);
			cout << "Login Successful" << endl;
			cout << name_s <<"\t" << idd_s << "\t" << pass_s << endl;
		}
		else
		{
			cout << "You are not Registered\nPls Register 1st..." << endl;
			cout << "Do you Want to Register\nPls type y or n";
			cin >> y;
			if (y == 'y' || y == 'Y')
			{
				reg::Register_s(name_s, id_s, password_s);
			}
			else if (y == 'n' || y == 'N')
			{
				exit(0);
			}
		}
	}
};