#pragma warning(disable : 4996)
/***********************************************************************
 * File: Source.cpp
 * Author: ¶À®x½n (0978wally@gmail.com)
 * Create Date: 2024-05-23
 * Editor: ¶À®x½n (0978wally@gmail.com)
 * Update Date: 2024-05-23
 * Description: manages a collection of books, allowing the user to 
 *   perform various operations such as inserting, deleting, finding, 
 *   and sorting books.
***********************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void insert(vector<vector<string>> &bookData);// Inserts a new book entry into bookData.
void deleteEdition(vector<vector<string>>& bookData);// Deletes a specific edition of a book from bookData.
void deleteBook(vector<vector<string>>& bookData);// Deletes all editions of a specific book from bookData.
void findBook(vector<vector<string>>& bookData);// Finds and prints details of a specific book.
void findAuthor(vector<vector<string>>& bookData);// Finds and prints all books by a specific author.
void sortTitle(vector<vector<string>> bookData);// Sorts bookData by title and prints the sorted data.
void sortAuthor(vector<vector<string>> bookData);// Sorts bookData by author and prints the sorted data.
void printData(vector<vector<string>> copyData);// Prints the book data.
bool getBookInfo(string& title, string& author, string& edition);// Extracts title, author, and edition from the input command.
bool getBookInfo(string& title, string& author);// Extracts title and author from the input command.
string findEdition(vector<vector<string>> bookData, string title, string author);// Finds and returns all editions of a specific book.

int main() {
	vector<vector<string>> bookData;

	while (true)
	{
		char commandLine[501];
		cin.getline(commandLine, 500); //get line comment

		if (cin.eof()) {
			break;
		}

		string firstCommand = strtok(commandLine, " ");// Parse the first command

		if (firstCommand == "Insert") { //process command
			insert(bookData);
		}
		else if (firstCommand == "Delete") {
			string secondCommand = strtok(NULL, " ");

			if (secondCommand == "Edition") {
				deleteEdition(bookData);
			}
			else if (secondCommand == "Book") {
				deleteBook(bookData);
			}

		}
		else if (firstCommand == "Find") {
			string secondCommand = strtok(NULL, " ");

			if (secondCommand == "Book") {
				findBook(bookData);
			}
			else if (secondCommand == "Author") {
				findAuthor(bookData);
			}
		}
		else if (firstCommand == "Sort") {
			strtok(NULL, " ");
			string secondCommand = strtok(NULL, " ");

			if (secondCommand == "Title") {
				sortTitle(bookData);
			}
			else if (secondCommand == "Author") {
				sortAuthor(bookData);
			}
		}
		else {
			cout << "Unknown Command.\n";
		}
	}
}

/*
 * Inserts a new book into the collection.
 * Pre: The bookData vector exists.
 * Post: If the book is successfully added, it is stored in the bookData vector.
 */
void insert(vector<vector<string>> &bookData) {
	string title, author, edition;

	if (getBookInfo(title, author, edition) == false) {//Incomplete Command
		cout << "Incomplete Command.\n";
		return;
	}

	vector<string> tempBook = { title, author, edition };
	auto findBook = find(bookData.begin(), bookData.end(), tempBook);//find book

	if (findBook == bookData.end()) { //book not exist -> add book
		bookData.push_back(tempBook);
		printf("Insert %s's %s, Edition: %s.\n", author.c_str(), title.c_str(), edition.c_str());
	}
	else {
		cout << "Datum already exist.\n";
	}
}

/*
 * Deletes a specific edition of a book from the collection.
 * Pre: The bookData vector exists.
 * Post: If the edition is found, it is removed from the bookData vector.
 */
void deleteEdition(vector<vector<string>>& bookData) {
	string title, author, edition;

	if (getBookInfo(title, author, edition) == false) {//Incomplete Command
		cout << "Incomplete Command.\n";
		return;
	}

	vector<string> tempBook = { title, author, edition };
	auto findBook = find(bookData.begin(), bookData.end(), tempBook);//find book

	if (findBook != bookData.end()) { //book exist -> delete
		bookData.erase(findBook);
		printf("Delete %s's %s, Edition: %s.\n", author.c_str(), title.c_str(), edition.c_str());
	}
	else {
		cout << "Datum doesn't exist.\n";
	}
}

/*
 * Deletes all editions of a book by a specific author from the collection.
 * Pre: The bookData vector exists.
 * Post: If the book is found, all its editions are removed from the bookData vector.
 */
void deleteBook(vector<vector<string>>& bookData) {
	string title, author;

	if (getBookInfo(title, author) == false) {//Incomplete Command
		cout << "Incomplete Command.\n";
		return;
	}

	bool hasRemoveBook = false;

	for (size_t i = 0; i < bookData.size(); i++) //find all exist book and delete
	{
		if (bookData[i][0].c_str() == title && bookData[i][1] == author) {
			bookData.erase(i + bookData.begin());
			hasRemoveBook = true;
			i--;
		}
	}

	if (hasRemoveBook) { //print result
		printf("Delete %s's %s.\n", author.c_str(), title.c_str());
	}
	else {
		cout << "Book doesn't exist.\n";
	}
}

/*
 * Finds and displays a book by its title and author.
 * Pre: The bookData vector exists.
 * Post: If the book is found, its details are displayed.
 */
void findBook(vector<vector<string>>& bookData) {
	string title, author;

	if (getBookInfo(title, author) == false) {//Incomplete Command
		cout << "Incomplete Command.\n";
		return;
	}

	bool hasFindBook = false;

	for (size_t i = 0; i < bookData.size(); i++) //find is book exist
	{
		if (bookData[i][0] == title && bookData[i][1] == author) {
			hasFindBook = true;
			break;
		}
	}

	if (hasFindBook) { //print result if book exist
		cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: " << findEdition(bookData, title, author) << "\n";
	}
	else {
		cout << "Book doesn't exist.\n";
	}
}

/*
 * Finds and displays all books by a specific author.
 * Pre: The bookData vector exists.
 * Post: If any books by the author are found, their titles are displayed.
 */
void findAuthor(vector<vector<string>>& bookData) {
	string author = strtok(NULL, "\"\"");
	vector<string> bookTitle;
	bool isFind = false;

	for (size_t i = 0; i < bookData.size(); i++) //find all author book
	{
		if (author == bookData[i][1]) {
			bookTitle.push_back(bookData[i][0]);
			isFind = true;
		}
	}

	if (isFind) { //print result
		printf("%s's Books: ", author.c_str());
		sort(bookTitle.begin(), bookTitle.end());

		for (size_t i = 0; i < bookTitle.size(); i++)
		{
			cout << bookTitle[i];

			if (i < bookTitle.size() - 1) {
				cout << ", ";
			}
		}

		cout << "\n";
	}
	else {
		cout << "No book found.\n";
	}
}

/*
 * Sorts and displays all books by their title.
 * Pre: The bookData vector exists.
 * Post: The books are displayed in sorted order by title.
 */
void sortTitle(vector<vector<string>> copyData) {
	for (size_t i = 0; i < copyData.size() - 1; i++) //buble sort bookdata
	{
		for (size_t j = i + 1; j < copyData.size(); j++)
		{
			if (strcmp(copyData[i][0].c_str(), copyData[j][0].c_str()) > 0) {
				swap(copyData[i], copyData[j]);
			}
			else if (strcmp(copyData[i][0].c_str(), copyData[j][0].c_str()) == 0 && strcmp(copyData[i][1].c_str(), copyData[j][1].c_str()) > 0) {
				swap(copyData[i], copyData[j]);
			}
		}
	}

	printData(copyData);
}

/*
 * Sorts and displays all books by their author.
 *
 * Pre: The bookData vector exists.
 * Post: The books are displayed in sorted order by author.
 */
void sortAuthor(vector<vector<string>> copyData) {
	for (size_t i = 0; i < copyData.size() - 1; i++)//buble sort bookdata
	{
		for (size_t j = i + 1; j < copyData.size(); j++)
		{
			if (strcmp(copyData[i][1].c_str(), copyData[j][1].c_str()) > 0) {
				swap(copyData[i], copyData[j]);
			}
			else if (strcmp(copyData[i][1].c_str(), copyData[j][1].c_str()) == 0 && strcmp(copyData[i][0].c_str(), copyData[j][0].c_str()) > 0) {
				swap(copyData[i], copyData[j]);
			}
		}
	}

	printData(copyData);
}

/*
 * Intent: Prints the book data to the console.
 * Pre: The copyData vector is a valid collection of books, with each book represented as a vector of strings (title, author, edition).
 * Post: The book data is printed to the console, ensuring no duplicate entries are displayed consecutively.
 */
void printData(vector<vector<string>> copyData) {
	for (size_t i = 0; i < copyData.size(); i++)
	{
		if ((i >= 1 && (copyData[i][0] != copyData[i - 1][0] || copyData[i][1] != copyData[i - 1][1])) || i == 0) {
			cout << "Title: " << copyData[i][0] << "\tAuthor: " << copyData[i][1] << "\tEdition: " << findEdition(copyData, copyData[i][0], copyData[i][1]) << "\n";
		}
	}
}

/*
 * Intent: Extracts the book information (title, author, edition) from the input command.
 * Pre: The input command is in the format: "Insert "title" author edition".
 * Post: The title, author, and edition are extracted and stored in the respective reference parameters.
 *       Returns true if successful, false if the command is incomplete.
 */
bool getBookInfo(string& title, string& author, string& edition) {
	title = strtok(NULL, "\"\"");// Extract title

	vector<string> res; // Collect remaining parts of the input (author and edition)
	while (true)
	{
		char* temp = strtok(NULL, " ");

		if (temp == NULL) {
			break;
		}

		res.push_back(temp);
	}

	if (res.size() < 2) return false; // Ensure at least author and edition are provided

	string strAuthor; // Construct the author string from the collected parts
	for (size_t i = 0; i < res.size() - 1; i++)
	{
		strAuthor += res[i];

		if (i < res.size() - 2) {
			strAuthor += " ";
		}
	}

	// Remove leading and trailing characters from the author string
	strAuthor.erase(strAuthor.begin());
	strAuthor.erase(strAuthor.end() - 1);
	author = strAuthor;
	edition = res[res.size() - 1];// The last element in res is the edition
	return true;
}

/*
 * Intent: Extracts the book information (title, author) from the input command.
 * Pre: The input command is in the format: "Find "title" author".
 * Post: The title and author are extracted and stored in the respective reference parameters.
 *       Returns true if successful, false if the command is incomplete.
 */
bool getBookInfo(string& title, string& author) {
	title = strtok(NULL, "\"\""); // Extract title

	vector<string> res; // Collect remaining parts of the input (author)
	while (true)
	{
		char* temp = strtok(NULL, " ");
		if (temp == NULL) {
			break;
		}
		res.push_back(temp);
	}

	string strAuthor; // Construct the author string from the collected parts
	for (size_t i = 0; i < res.size(); i++)
	{
		strAuthor += res[i];

		if (i < res.size() - 1) {
			strAuthor += " ";
		}
	}

	if (res.size() < 1) return false;// Ensure at least author is provided

	// Remove leading and trailing characters from the author string
	strAuthor.erase(strAuthor.begin());
	strAuthor.erase(strAuthor.begin() + strAuthor.length() - 1);
	author = strAuthor;

	// Check if title or author is not empty
	if (title == "" || author == "") {
		return false;
	}
	return true;
}

/*
 * Intent: Finds and returns all editions of a specified book (by title and author) in sorted order.
 * Pre: The bookData vector is a valid collection of books.
 * Post: Returns a string containing the editions of the specified book, sorted and separated by commas.
 */
string findEdition(vector<vector<string>> bookData, string title, string author) {
	vector<int> edition; // Vector to store editions of the specified book

	for (size_t i = 0; i < bookData.size(); i++)  // Loop through bookData to find matching titles and authors
	{
		if (bookData[i][0] == title && bookData[i][1] == author) {
			edition.push_back(strtol(bookData[i][2].c_str(),nullptr,10));
		}
	}

	sort(edition.begin(), edition.end());// Sort editions in ascending order
	string res;

	for (size_t i = 0; i < edition.size(); i++)// Append editions to the result string
	{
		res += to_string(edition[i]);
		res += ", ";
	}

	res.erase(res.end() - 2, res.end()); // Remove the trailing comma and space

	return res;
}