#include "login.h"
#include "books.h"
using namespace std;
class library : protected login, protected reg
{
private:
	int n, m;
	string name, password;
	int id;
public:
	void selection()
	{
		cout << "Hello This Library managemnet system" << endl;
		cout << "1.\tLogin" << endl << "2.\tRegister" << endl << "3.\tExit\n" << endl;
		cout << "Pls Enter Your Choice in no.";
		cin >> n;
		cout << "\n";
		if (n == 1)
			L();
		else if (n == 2)
			R();
		else if (n == 3)
		{
			cout << "Thank You For Using this service";
			system("exit");
		}
		else
		{
			try
			{
				if (n < 1 || n > 3)
				{
					throw out_of_range("Invalid input. Please enter a number between 1 to 3.");
				}
			}
			catch (out_of_range& e)
			{
				cout << "Error:" << e.what() << endl << endl;
				selection();
			}
		}
	}
	void B()
	{
		Library lib;
		lib.loadBooksFromFile();
		lib.loadIssuedBooksFromFile();
		cout << "Welome to book section\n1.\tBook Issue\n2.\tBook Return\n3.\tBook List" << endl;
		cout << "Please Select any one" << endl;
		cin >> m;
		bool result = true;
		if (m == 1)
		{
			string tit, id, auth, s_id, name, DOI, DOR;
			char c = ',';
			cout << "Give Title,id,auth,name,s_id,Date to be Issued,Date to be returned";
			cin >> tit >> id >> auth >> name >> s_id >> DOI >> DOR;
			//cout << "\n";
			result = lib.issue_book(tit, id, auth, name, s_id, DOI, DOR);
			if (result = true)
			{
				cout << "Book" << endl;
			}
			else
				cout << "not" << endl;
		}
		else if (m == 2)
		{
			string tit;
			cout << "GIve Title of Book";
			cin >> tit;
			lib.removeIssuedBook(tit);
		}
		else if (m == 3)
		{
			lib.displayBooks();
		}
		selection();
	}
	void L()
	{
		cout << "1.\tTeacher" << endl << "2.\tStudent" << endl;
		cout << "Give Your Choice";
		cin >> m;
		cout << "\n";
		if (m == 1)
		{
			cout << "Give Your Name";
			cin >> name;
			cout << "Give Your Id";
			cin >> id;
			try {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw invalid_argument("Invalid Input. Please enter a valid integer.");
				}
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl << endl;
				L();
				return;
			}
			string sid_t = to_string(id);
			cout << "Give Password";
			cin >> password;
			try {
				if (password.empty()) {
					throw invalid_argument("Invalid Input. Password cannot be empty.");
				}
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl << endl;
				L();
				return;
			}
			log_t(name, sid_t, password);
			char x;
			cout << "Do you want to add books\nif yes then press y if no press n to logout and go to main menu\ny or n:\t" << endl;
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				Library lib;
				string tit, id, auth;
				cout << "Give title name";
				cin >> tit;
				cout << "\nGive Book id";
				cin >> id;
				cout << "\nGive Author name";
				cin >> auth;
				Books b(tit, id, auth);
				lib.add_books(b);
				cout << "Added Book Successfully Loging you out to save the book to library" << endl;
				L();
			}
			else if (x == 'n' || x == 'N')
			{
				selection();
			}
			else
			{
				cout << "Give y or n next time now you are logged out";
				selection();
			}
		}
		else if (m == 2)
		{
			cout << "Give Your Name";
			cin >> name;
			cout << "Give Your Id";
			cin >> id;
			try {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw invalid_argument("Invalid Input. Please enter a valid integer.");
				}
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl << endl;
				L();
				return;
			}
			string sid_s = to_string(id);
			cout << "Give Password";
			cin >> password;
			try {
				if (password.empty()) {
					throw invalid_argument("Invalid Input. Password cannot be empty.");
				}
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl << endl;
				L();
				return;
			}
			log_s(name, sid_s, password);
			char y;
			cout << "Do you want to Issue or return any book" << endl;
			cin >> y;
			if (y == 'y' || y == 'Y')
			{
				cout << "Book Issue Menu" << endl;
				B();
			}
			else if (y == 'n' || y == 'N')
			{
				L();
			}
		}
		else if (m == 3)
			selection();
		else
			if (m < 1 || m>3)
			{
				try
				{
					throw out_of_range("Invalid input. Please enter a number between 1 or 2");
				}
				catch (out_of_range& e)
				{
					cout << "Error:" << e.what() << endl << endl;
					L();
				}
			}
	}
	void R()
	{
		cout << "1.\tTeacher" << endl << "2.\tStudent" << endl;
		cout << "Give Your Choice";
		cin >> m;
		cout << "\n";
		if (m == 1)
		{
			cout << "Give Your Name";
			cin >> name;
			cout << "Give Your ID";
			cin >> id;
			try {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw invalid_argument("Invalid Input. Please enter a valid integer.");
				}
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl << endl;
				R();
				return;
			}
			string sid_t = to_string(id);
			cout << "Set Password";
			cin >> password;
			try {
				if (password.empty()) {
					throw invalid_argument("Invalid Input. Password cannot be empty.");
				}
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl << endl;
				R();
				return;
			}
			reg::Register_t(name, sid_t, password);
			char x;
			cout << "Do you want to add books\nif yes then press y if no press n to logout and go to main menu\ny or n:\t" << endl;
			cin >> x;
			if (x == 'y' || x == 'Y')
			{
				Library lib;
				string tit, id, auth;
				cout << "Give title name";
				cin >> tit;
				cout << "\nGive Book id";
				cin >> id;
				cout << "\nGive Author name";
				cin >> auth;
				Books b(tit, id, auth);
				lib.add_books(b);
				cout << "Added Book Successfully Loging you out to save the book to library" << endl;
				L();
			}
			else if (x == 'n' || x == 'N')
			{
				selection();
			}
		}
		else if (m == 2)
		{
			cout << "Give Your Name";
			cin >> name;
			cout << "Give Your ID";
			cin >> id;
			try {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw invalid_argument("Invalid Input. Please enter a valid integer.");
				}
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl << endl;
				R();
				return;
			}
			string sid_s = to_string(id);
			cout << "Set Password";
			cin >> password;
			try {
				if (password.empty()) {
					throw invalid_argument("Invalid Input. Password cannot be empty.");
				}
			}
			catch (exception& e) {
				cout << "Error: " << e.what() << endl << endl;
				R();
				return;
			}
			reg::Register_s(name, sid_s, password);
			cout << "Registered Successful" << endl;
			char y;
			cout << "Do you want to Issue or return any book" << endl;
			cin >> y;
			if (y == 'y' || y == 'Y')
			{
				cout << "Book Issue Menu" << endl;
				B();
			}
			else if (y == 'n' || y == 'N')
			{
				L();
			}
		}
		else if (m == 3)
		{
			cout << "Exiting to maim menu" << endl;
			selection();
		}
		else
			if (m < 1 || m>3)
			{
				try
				{
					throw out_of_range("Invalid input. Please enter a number between 1 or 2");
				}
				catch (out_of_range& e)
				{
					cout << "Error:" << e.what() << endl << endl;
					R();
				}
			}
	}
};
int main()
{
	library l;
	l.selection();
}