#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Document.h
class Document{
private:
    string name;
    string extension;
    string contents;
public:
    Document(string nameIn, string extensionIn, string contentsIn);
    string GetName();
    void Rename(string newDocumentName);
    string GetExtension();
    string GetContents();
    void Print();

};

//Document.cpp
Document::Document(string nameIn, string extensionIn, string contentsIn){
    name = nameIn;
    extension = extensionIn;
    contents = contentsIn;
}
string Document::GetName(){
    return name;
}
void Document::Rename(string newDocumentName){
    name = newDocumentName;
}
string Document::GetExtension(){
    return extension;
}
string Document::GetContents(){
    return contents;
}
void Document::Print(){
    cout << "Name: " << name << "." << extension << endl;
    cout << "Contents: " << contents << endl;
}

//main.cpp----------
void DisplayMenu(){
    cout << "Choose an option below: "<< endl;
    cout << "1. Add a document to your list"<< endl;
    cout << "2. Rename one of your documents"<< endl;
    cout << "3. Share one of your documents with a friend"<< endl;
    cout << "4. Display all of the documents"<< endl;
    cout << "5. Quit"<< endl << endl;
}
std::string GetUserString(const std::string& prompt = "") {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}

int GetUserInt(const std::string& prompt = "") {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}

// Modify the main function to handle each menu option
// Consider creating a new function (above main) per menu option
int main(){
    const int ADD_DOCUMENT_OPTION = 1;
    const int RENAME_DOCUMENT_OPTION = 2;
    const int SHARE_YOUR_DOCUMENT_OPTION = 3;
    const int DISPLAY_ALL_DOCUMENTS_OPTION = 4;
    const int QUIT_OPTION = 5;

    int option;
    DisplayMenu();
    option = GetUserInt();

    while(option != QUIT_OPTION){

        if(option == ADD_DOCUMENT_OPTION){

        }
        else if(option == RENAME_DOCUMENT_OPTION){

        }
        else if(option == SHARE_YOUR_DOCUMENT_OPTION){

        }
        else if(option == DISPLAY_ALL_DOCUMENTS_OPTION){

        }

        option = GetUserInt("Enter option: \n");
    }
    return 0;
}
