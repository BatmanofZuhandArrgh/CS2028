#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <cstdlib>

using namespace std;



struct Text{
    string title;
    string AuthorName;
    int wordCount;
    vector<double> frequency;
    int lineCount;
};
//void Readfile(ifstream&, Text, string, string, string, vector<string>);
int WordCount(vector<string>);
vector<int> LetterFrequency(vector<string>);
void Writefile(ofstream&, Text, string, string);


int main()
{
    //create struct object
    Text Book;
    
    //create vector to store the book contents
    vector<string> Content;
    
    string first, last, title;
    
    //create ifstream to read the file
    ifstream myfile;
    
    
    //    Readfile(myfile, Book, first, last, title, Content);
    
    //ask user a file name
    string filename;
    cout<<"Pick a file name: ";
    
    cin>>filename;

    //create ifstream to read the file
    //    ifstream myfile;
    myfile.open(filename.c_str());
    if(!(myfile.is_open())){
        cout<<"Error"<<endl;
        cout<<"Pick another file name";
        getline(cin,filename);
        myfile.open(filename.c_str());
    }
    
    //create object to write a file
    //ofstream output;
    
    
    //read the file
    //    string first, last, title1;
    int count = 0;
    while(count<2){
        if(count == 0){
            getline(myfile, title);
            count++;
        }
        else if(count > 0){
            myfile>>first>>last;
            count++;
        }
        
    }
    
    //read author name and title into struct
    Book.AuthorName = first + " " + last;
    Book.title = title;
    
    //read the book contents and store into the vector
    string line;
    int lineCount = 0;
    while(getline(myfile, line)){
        Content.push_back(line);
        lineCount++;
    }
    myfile.close();
    
    //delete unnecessary lines
    Content.erase(Content.begin());
    Content.erase(Content.begin());
    
    //read the line count into struct
    Book.lineCount = Content.size();
    
    
    
    for(unsigned int i=0; i<Content.size(); i++){
        cout<<Content.at(i)<<endl;
    }
    cout<<endl;
    //    cout<<lineCount<<endl;
    
    cout<<endl;
    
    //call function to calculate word count
    int wcount = WordCount(Content);
    Book.wordCount = wcount;
    cout<<wcount<<endl;
    
    //create dummy vector for the letter frequency and call function
    vector<int> letterdummy = LetterFrequency(Content);
    
    //put letter frequency into the structure vector
    for(unsigned int i = 0; i<letterdummy.size(); i++){
        Book.frequency.push_back(letterdummy[i]);
        //        cout<<Book.frequency[i]<<" ";
    }
    
    //create object to write a file
    ofstream output;
    
    //call function to write a file
    Writefile(output, Book, first, last);
    cout<<endl;
    
    //ask user if he wants to do another book
    char onemore;
    cout<<"Do you want to proceed another book?"<<endl;
    cout<<"Enter 'y' for yes, 'n' for no: ";
    cin>>onemore;
    
    if(onemore == 'y'){
        //create ifstream object
        ifstream anotherfile;
        
        //ask user a file name
        string anothername;
        cout<<"Pick a file name: ";
        getline(cin,anothername);
        
        anotherfile.open(anothername.c_str());
        if(!(anotherfile.is_open())){
            cout<<"Error"<<endl;
            cout<<"Pick another file name";
            getline(cin,anothername);
            myfile.open(anothername.c_str());
        }
    }
    else if(onemore == 'n'){
        cout<<"Created one library card catalog file. "<<endl;
    }
    
    
    
    return 0;
}



int WordCount(vector<string> Content){
    string dummy;
    int wordCount = 0;
    for(unsigned int i = 0; i<Content.size(); i++){
        dummy = Content.at(i);
        //        cout<<dummy<<endl;
        if(isalpha(dummy.at(0))){
            wordCount++;
        }
        for(int j = 1; j<dummy.length(); j++){
            if((isalpha(dummy[j]))&&(!isalpha(dummy[j-1]))){
                wordCount++;
            }
        }
        
    }
    return wordCount;
}

vector<int> LetterFrequency(vector<string> Content){
    string dummy;
    vector<int> letter(26);
    for(unsigned int i = 0; i<Content.size(); i++){
        dummy = Content.at(i);
        for(unsigned int k = 0; k<dummy.length(); k++){
            dummy[k] = tolower(dummy[k]);
            letter[dummy[k]-'a']++;
        }
        
    }
    
    return letter;
}

void Writefile(ofstream& output, Text Book, string first, string last){
    output.open("CardCatalog.txt", ios::out| ios_base::app);
    if(!output.is_open()){
        cout<<"Error"<<endl;
    }
    output<<"Title: "<<Book.title<<endl;
    output<<endl;
    output<<"Full Author: "<<Book.AuthorName<<endl;
    output<<endl;
    output<<"Author First Name: "<<first<<endl;
    output<<endl;
    output<<"Author Last Name: "<<last<<endl;
    output<<endl;
    output<<"Word count: "<<Book.wordCount<<endl;
    output<<endl;
    output<<"Line count: "<<Book.lineCount<<endl;
    output<<endl;
    
    char choice;
    cout<<endl;
    cout<<"Do you want to see the letter frequency?"<<endl;
    cout<<"Enter 'y' for yes and 'n' for no"<<endl;
    cout<<"y or n: ";
    cin>>choice;
    
    char a = 'a';
    
    if(choice == 'y'){
        for(unsigned int i = 0; i<Book.frequency.size(); i++){
            Book.frequency[i] = Book.frequency[i]/26;
            output<<static_cast<char>(a)<<": "<<Book.frequency[i]<<"%"<<endl;
            a++;
        }
    }
    else if(choice == 'n'){
        output.close();
    }
    output.close();
}

