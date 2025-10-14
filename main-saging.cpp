// Online C++ compiler to run C++ program online
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;


// hello nya -Adam
string temp;
int main() {
    string usr, pswrd, search;
    cout<<"Group:"<<right<<setw(9)<<"Saging"<<endl<<right<<setw(39)<<"Members: Barrameda, Angelito Parale Jr."<<endl<<right<<setw(32)<<"Fetalvero, Cedric Wayne"<<endl<<right<<setw(32)<<"De Villa, Kurt Lawrence"<<endl<<right<<setw(25)<<"Medalla, Vincent"<<endl;
    cout<<"\nWelcome to Saging Library System"<<endl;
    cout<<"Enter /h or /help for functions"<<endl;
    while(true){
        getline(cin,temp);
        if(temp == "/h" || temp=="/help"){
            cout<<"Functions:"<<endl<<"/l or /login"<<endl<<"/s or /search"<<endl;}
        else if(temp == "/l" || temp=="/login"){
            cout<<"User: ";
            cin>>usr;
            cout<<"password: ";
            cin>>pswrd;
            if(usr=="VALID" && pswrd=="VALID"){
                //s
            }
            else
                cout<<"Invalid";
        }
        else if(temp == "/s" || temp=="/search"){
            cout<<"Search: ";
            cin>>search;
        }
    }

    return 0;
}
