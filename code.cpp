#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Hostel{
    private :
    string Name;
    int Rent,Bed;
    public:

    Hostel(string name, int rent , int bed){
        Name = name;
        Rent = rent;
        Bed = bed;
    }
    string getName(){
    return Name;
}
int getRent(){
    return Rent;
}
int getBed(){
    return Bed;
}
void reserve(){
    ifstream in("Desktop/Hostel.txt");
    ofstream out("Desktop/Hostel.txt", ios::app);

    string line;
    while(getline(in, line)){
        // if(line.find(Name) != string::npos){
        //     cout << "Hostel already exists." << endl;
        //     return;
        // }
        int pos = line.find("5star");
        if(pos != string::npos){

            int bed =  Bed - 1;
            Bed = bed;
            stringstream ss;
            ss<<bed;
            string strBed = ss.str();

            int bedpos = line.find_last_of(" :");
            line.replace(bedpos + 1, line.length() - bedpos - 1, strBed);
    }
    out<<line<<endl;
}out.close();
    in.close();
    remove("Desktop/Hostel.txt");
    rename("Desktop/Hostel.txt", "Desktop/Hostel.txt");
    cout << "Bed reserved successfully." << endl;
    }
};

class Student{
    private:
    string Name ,RollNo,Address;

    public:
    Student():Name(""),RollNo(""),Address(""){}
     void setName(string name){
        Name = name;
    }
     void setRollNo(string rollno){
     RollNo = rollno;
    }
     void setAddress(string address){
    Address = address;
    }
     string getName(){
    return Name;
}
string getRollNo(){
    return RollNo;
}
string getAddress(){
    return Address;
}
};

int main(){
    Hostel h("5star",7000,5);
    ofstream out("Desktop/Hostel.txt");
    out << "\t" << h.getName() << " : " << h.getRent() << endl;
    cout<<"DATA SAVED SUCCESSFULLY"<<endl;
    out.close();
    Student s;

 bool exit = false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWELCOME TO THE HOSTEL"<<endl;
        cout<<"\t*********************"<<endl;
        cout<<"\t1 Reserve a Bed/Accomodation :"<<endl;
        cout<<"\t2 EXIT."<<endl;
        cout<<"\t Enter The Choice :"<<endl;
        cin>>val;
        cin.ignore(); 

        if (val==1)
        {
            system("cls");
            string name,rollno,address;
            cout<<"\tEnter The Name Of Student :"<<endl;
            cin>>name;
            s.setName(name);


             cout<<"\tEnter The RollNo :"<<endl;
            cin>>rollno;
            s.setRollNo(rollno);

             cout<<"\tEnter The Address  :"<<endl;
            cin>>address;
            s.setAddress(address);

            if(h.getBed() > 0){
              h.reserve();
              ofstream outFile("Desktop/Hostel.txt", ios::app);
              outFile << "\t" << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl;
              outFile.close();
              Sleep(2000);
            }else{
                cout << "No beds available." << endl;
                Sleep(2000);
            }
            // else if(h.getBed() == 0){
            //     cout << "No beds available." << endl;
            // }

            // ofstream outFile("Desktop/Hostel.txt", ios::app);
            // // if (outFile.is_open()) {
            //     outFile << "\t" << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl;
            //     cout<<"DATA SAVED SUCCESSFULLY"<<endl;
            //     Sleep(2000);
            //     // outFile.close();
            } else if (val==2)
            {
                exit = true;
                cout << "Exiting the program." << endl;
                Sleep(1000);
                system("cls");
            }
             {
                cout << "Unable to open file." << endl;
            }
        }
        
        }
// }