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

void AddDocument(vector<Document*> &paramDocList) {
    // Declare and initialize variables
    string docName = "";
    string docExtension = "";
    string docContent = "";

    // Prompt for user input
    docName = GetUserString("Enter the document name: ");
    docExtension = GetUserString("Enter the document extension: ");
    docContent = GetUserString("Enter the document content: ");

    // Create newDocument object and allocate memory
    Document* newDocument = new Document(docName, docExtension, docContent);

    // Add to the passed vector parameter
    paramDocList.push_back(newDocument);
}

void RenameDocument(vector<Document*> &paramDocList) {
    // Declare and initialize variables
    int userInt = 0;
    string docName = "";

    // Prompt for user input
    userInt = GetUserInt("Enter the index of your document you want to rename: ");
    docName = GetUserString("Enter the new name of the document: ");

    // Rename the document on the passed vector
    paramDocList.at(userInt)->Rename(docName);
}

void ShareDocument(vector<Document*> paramDocList, vector<Document*> &paramSharedDocList) {
    // Declare and initialize variables
    int userInt = 0;

    // Prompt for user input
    userInt = GetUserInt("Enter the index of your document you want to share: ");

    // Point the shared document list to the document at the specified index on the user's list
    paramSharedDocList.push_back(paramDocList.at(userInt)); // Notice that we haven't created a new object
}

void DisplayAllDocuments(vector<Document*> paramDocList, vector<Document*> paramSharedDocList) {

    cout << "-------------------Your List------------------" << endl;

    // Loop through each position on the vector of user's documents and output its properties
    for (int i = 0; i < paramDocList.size(); ++i) {
        cout << "Name: " << paramDocList.at(i)->GetName()  << "." << paramDocList.at(i)->GetExtension() << endl;
        cout << "Contents: " << paramDocList.at(i)->GetContents();
    }

    cout << "--------------Your Friend's List--------------" << endl;

    // Loop through each position on the vector of user's shared documents and output its properties
    for (int i = 0; i < paramSharedDocList.size(); ++i) {
        cout << "Name: " << paramSharedDocList.at(i)->GetName()  << ".";
        cout << paramSharedDocList.at(i)->GetExtension() << endl;
        cout << "Contents: " << paramSharedDocList.at(i)->GetContents();
    }

    cout << "----------------------------------------------" << endl;
}

// Modify the main function to handle each menu option
// Consider creating a new function (above main) per menu option
int main() {

    // Declare a vector of document type w/ pointer
    vector<Document*> userDocumentList(0);
    vector<Document*> sharedDocumentList(0);

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
            AddDocument(userDocumentList);
        }
        else if(option == RENAME_DOCUMENT_OPTION){
            RenameDocument(userDocumentList);
        }
        else if(option == SHARE_YOUR_DOCUMENT_OPTION){
            ShareDocument(userDocumentList, sharedDocumentList);
        }
        else if(option == DISPLAY_ALL_DOCUMENTS_OPTION){
            DisplayAllDocuments(userDocumentList, sharedDocumentList);
        }

        option = GetUserInt("Enter option: \n");
    }

    // Free up allocated memory
    for (int i = 0; i < userDocumentList.size(); ++i) {
        delete userDocumentList.at(i); // Each position in the document list has a document with memory allocated
        // but the shared list only points to these documents
    }

    return 0;
}
