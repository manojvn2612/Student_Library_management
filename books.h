#include <iostream>
#include <vector>
#include <string>
#include <fstream>
class Books
{
	public:
		string title, Book_id, author;
		bool is_available;
		Books()
		{
			title = "";
			Book_id = "";
			author = "";
			is_available = true;
		}
		Books(string tit, string id, string aut, bool avail = true)
		{
			title = tit;
			Book_id = id;
			author = aut;
			is_available = avail;
		}
};
class Book_Issue
{
	public:
		string title, Book_id, author, name, s_id, DOI, DOR;
		Book_Issue()
		{
			title = "";
			Book_id = "";
			author = "";
			name = "";
			s_id = "";
			DOI = "";
			DOR = "";
		}
		Book_Issue(string t, string b_id, string auth, string nme, string st_id, string DI, string DR)
		{
			title = t;
			Book_id = b_id;
			author = auth;
			name = nme;
			s_id = st_id;
			DOI = DI;
			DOR = DR;
		}
};
class Library
{
	public:
		vector <Books> books;
		vector <Book_Issue> issued_books;
		void savebooktofile()
		{
			ofstream out("Books.txt",ios::app);
			for (int i = 0; i < books.size(); i++)
			{
				out << books[i].title << endl;
				out << books[i].Book_id << endl;
				out << books[i].author << endl;
				out << books[i].is_available << endl;
			}
		}
		void add_books(Books b)
		{
			books.push_back(b);
			savebooktofile();
		}
		void remove_books(int index)
		{
			if (index > 0 && index < books.size())
			{
				books.erase(books.begin() + index);
				savebooktofile();
			}
		}
		bool issue_book(string title, string b_id, string auth, string name, string student_id, string DOI, string DOR)
		{
			int index = find_book(title);
			if (index != -1 && books[index].is_available) 
			{
				books[index].is_available = false;
				Book_Issue ib(books[index].title, b_id, auth, name, student_id, DOI, DOR);
				issued_books.push_back(ib);
				issue_book_to_file();
				return true;
			}
			else 
			{
				return false;
			}
		} 
		void removeIssuedBook(string title) {
			ifstream infile("Issued_Books.txt");
			ofstream outfile("temp.txt");
			string t,a,n,b_i,s_i,di,dr;
			bool found = false;
			while (getline(infile, t)) {
				if (t == title) {
					// Skip this book
					found = true;
					for (int i = 0; i < issued_books.size(); i++) {
						getline(infile, t);
					}
				}
				else {
					// Write this book to the temp file
					outfile << t << endl;
					for (int i = 0; i < issued_books.size(); i++) {
						getline(infile, t);
						outfile << t << endl;
					}
				}
			}
			infile.close();
			outfile.close();
			if (found) {
				// Delete the original file
				remove("Issued_Books.txt");
				// Rename the temp file to the original file name
				int result = rename("temp.txt", "Issued_Books.txt");
				if (result == 0)
					cout << "Book removed successfully." << endl;
			}
			else {
				// Delete the temp file
				remove("temp.txt");
				cout << "Book not found." << endl;
			}
		}

		void issue_book_to_file()
		{
			ofstream out("Issued_Books.txt",ios::out);
			for (int i = 0; i < issued_books.size(); i++)
			{
				out << issued_books[i].title << endl;
				out << issued_books[i].Book_id << endl;
				out << issued_books[i].author << endl;
				out << issued_books[i].name << endl;
				out << issued_books[i].s_id << endl;
				out << issued_books[i].DOI << endl;
				out << issued_books[i].DOR << endl;
			}
			out.close();
		}
		int return_book_to_file()
		{
			string tittle, b_id;
			ifstream in("Issued_Books.txt");
			while (getline(in, tittle)&& getline(in,b_id))
			{
				for (int i = 0; i < issued_books.size(); i++)
				{
					if (issued_books[i].title == tittle)
						return i;
				}
				return -1;
			}
			in.close();
		}
		int find_book(string title)
		{
			for (int i = 0; i < books.size(); i++)
			{
				if (books[i].title == title)
					return i;
			}
			return -1;
		}
		int find_book_issue(string title,string id)
		{
			for (int i = 0; i < issued_books.size(); i++)
			{
				if (issued_books[i].title == title && issued_books[i].Book_id == id)
					return i;
			}
			return -1;
		}
		void loadBooksFromFile() {
			ifstream infile("books.txt");
			string title, author, id;
			bool avail;
			while (getline(infile, title) && getline(infile, author) && getline(infile, id) && infile >> avail) 
			{
				Books b(title, author, id, avail);
				books.push_back(b);
			}
		}
		void loadIssuedBooksFromFile() {
			ifstream infile("issued_books.txt");
			string title, auth, name, s_id, issue, ret, B_id;
			while (getline(infile, title) && getline(infile,B_id) && getline(infile,auth) && getline(infile, name) && getline(infile, s_id)  && getline(infile, issue) && getline(infile, ret))
			{
				Book_Issue ib(title, B_id, auth, name, s_id, issue, ret);
				issued_books.push_back(ib);
			}
		}
		void displayBooks() 
		{
			for (int i = 0; i < books.size(); i++) {
				cout << "Title: " << books[i].title << endl;
				cout << "Author: " << books[i].author << endl;
				cout << "ISBN: " << books[i].Book_id << endl;
				if (books[i].is_available) {
					cout << "Availability: Available" << endl << endl;
				}
				else {
					cout << "Availability: Not Available" << endl << endl;
				}
			}
		}

};