#include <iostream>
#include<string>
#include<conio.h>
using namespace std;

struct node{
    int roll_no,cycle,sr;
    string name;
    node* link;
    node(){
    	sr=1;
	}
};

class Student{
    private:
        node* start;
        int roll,cycle_no,serial;
        string student_name;
    public:
        Student(){
            start=NULL;
            serial=0;
        }
        void Input(void){
            cout<<"Enter Student Name: ";
            getline(cin,student_name);
            cout<<"Enter Roll No of Student "<<student_name<<" : ";
            cin>>roll;
            cout<<"Enter your Cycle Token Number: ";
            cin>>cycle_no;
            system("cls");
        }
        void Link_data(void){
            node* p= new node;
            p->name=student_name;
            p->roll_no=roll;
            p->cycle=cycle_no;
            p->sr=++serial;
            p->link=NULL;
            if(start==NULL){
                start = p;
            }
            else{
                node* cur=start;
                while(cur->link!=NULL){
                    cur=cur->link;
                }
                node* temp= p;
                cur->link=temp;
            }
        }
        
        void search(int n){
        	if(n==1){
        		string s_name;
        		cout<<"Enter Name: ";
        		cin.ignore();
        		getline(cin,s_name);
        		node* cur=start;
        		while(cur != NULL){
        			int x=s_name.compare(cur->name);
        			if(x==0){
        				system("cls");
        				cout<<"Data Matched!!!"<<"\n";
        				
        				cout<<"-------------------------Student Data List-------------------------\n\n";
				cout<<"Sr# \tStudent Name\t\tRoll_No\t\tCycle Token_NO\t\t  \n";
        				cout<<"---------------------------------------------------------------\t\n";
        				cout<<cur->sr<<"\t"<<cur->name<<"\t\t"<<cur->roll_no<<"\t\t\t"<<cur->cycle<<"\t\t\n";
        				cout<<"***********************************************************************\n\n";
        				return ;
					}
					cur=cur->link;
				}
				cout<<"Data Not || Not Exist\n\n";
				return ;
			}
			if(n==2){
        		int s_roll;
        		cout<<"Enter Roll No: ";
        		cin>>s_roll;
        		node* cur=start;
        		while(cur != NULL){
        			if(cur->roll_no == s_roll){
        				system("cls");
        				cout<<"Data Matched!!!"<<"\n";
        				
        				cout<<"-------------------------Student Data List-------------------------\n\n";
				cout<<"Sr# \tStudent Name\t\tRoll_No\t\tCycle Token_NO\t\t  \n";
        				cout<<"---------------------------------------------------------------\t\n";
        				cout<<cur->sr<<"\t"<<cur->name<<"\t\t"<<cur->roll_no<<"\t\t\t"<<cur->cycle<<"\t\t\n";
        				cout<<"***********************************************************************\n\n";
        				return ;
					}
					cur=cur->link;	
				}
				system("cls");
				cout<<"\n----------Data Not Found----------\n";
				return ;
				
			}
			if(n==3){
        		int s_cycle;
        		cout<<"Enter Cycle Token No: ";
        		cin>>s_cycle;
        		node* cur=start;
        	while(cur != NULL){
        			if(cur->cycle == s_cycle){
        				system("cls");
        				cout<<"Data Matched!!!"<<"\n";
        				
        				cout<<"-------------------------Student Data List-------------------------\n\n";
				cout<<"Sr# \tStudent Name\t\tRoll_No\t\tCycle Token_NO\t\t  \n";
        				cout<<"---------------------------------------------------------------\t\n";
        				cout<<cur->sr<<"\t"<<cur->name<<"\t\t"<<cur->roll_no<<"\t\t\t"<<cur->cycle<<"\t\t\n\n";
        				cout<<"***********************************************************************\n\n";
        				return ;
					}
					cur=cur->link;	
				}
			}
		
		}
		
		void modified_data(int n) {
    int s_roll = n;
    node* cur = start;
    while (cur != NULL) {
        if (cur->roll_no == s_roll) {
           
            cout << "Data Matched!!!" << "\n";
            string name;
            int roll_no, cycle_no;
            cout << "Enter Name: ";
            cin.ignore();
			getline(cin,name);
            cout << "Enter Roll No: ";
            cin >> roll_no;
            cout << "Enter Cycle No: ";
            cin >> cycle_no;
            cur->name = name;
            cur->roll_no = roll_no;
            cur->cycle = cycle_no;
            system("cls");
            cout << "Data Changed Successfully!!!" << endl;
            system("cls");
			return ;
        }
        cur = cur->link;
    }
    // If roll number is not found in the list
    system("cls");
    cout << "Roll Number not found!!!" << endl;
}


			void Delete(int val){
				if(start==NULL){
					cout<<"There is No Data To Delete\n\n";
					return ;
				}
				else if((start->roll_no) == val){
					node* x = start;
					start = start->link;
					node* temp = start;
					while(temp !=NULL){
						--(temp->sr);
						temp=temp->link;
					}
					show_deleted(x);
					delete x; 
					return ;
				}
				else{
					node* cur=start;
					while(cur != NULL){
						if((cur->link->roll_no) == val){
							node* x = cur->link;
							if(cur->link->link !=NULL){
								cur->link = cur->link->link;
							}
							node* temp = start->link;
					while(temp !=NULL){
						--(temp->sr);
						temp=temp->link;
					}
							show_deleted(x);
							delete x;
							return ;
						}
						cur = cur->link;
					}
					cout<<"\t\t\t--------------Data Not Found--------------\n\n";
					return ;
				}
			}

		void Print(){
			node* cur=start;
			if(cur==NULL){
				cout<<"There is no student data!!!\n\n";
				cout<<"================================\n\n";
				return ;
			}
			cout<<"\n\t\t\t-------------------------Student Data List-------------------------\n\n";
			cout<<"\n\t\t\tSr# \tStudent Name\t\tRoll_No\t\tCycle Token_NO\t\t  \n";
        	cout<<"\n\t\t\t---------------------------------------------------------------\t\n";
			while(cur!=NULL){
        				cout<<"\n\t\t\t"<<cur->sr<<"\t"<<cur->name<<"\t\t"<<cur->roll_no<<"\t\t\t"<<cur->cycle<<"\t\t\n";
        				cur=cur->link;
			}
			cout<<"****************************************************************************************************************\n\n";
		}
		void show_deleted(node* x){
			system("cls");
			cout<<"\t\t\tData Deleted Successfuly\t\t\n";
						cout<<"\t\t===================================\n";
						cout<<"Sr# \tStudent Name\t\tRoll_No\t\tCycle Token_NO\t\t  \n";
        				cout<<"---------------------------------------------------------------\t\n";
        				cout<<x->sr<<"\t"<<x->name<<"\t\t"<<x->roll_no<<"\t\t\t"<<x->cycle<<"\t\t\n\n";
        				cout<<"***********************************************************************\n\n";
		}
};

int main(){
	p:
		system("color 6");
		cout<<endl;
		cout<<"\t\t\t\t ---------Mohammad Saud Attari---------\t\t\t\t\n\n";
	char pass[11]={"saudattari"};
	char password[11];
	int a=3;
	
	for(int i=0; i<3; i++){
	cout<<"Enter 8 character password: "<<endl;
	cin>>password;
	int j=strcmp(password,pass);
	if(j==0){
		cout<<"\a"<<endl;
		cout<<"------Correct Passowrd------\n";
		system("cls");
		break;
	}
	else{
		system("cls");
		cout<<"!!!Wrong Password!!!\t\t ";
		cout<<--a<<" Attempt Left"<<endl;
		if(a==0){
			return 0;
		}
	}
}
Student s1;

string name;
int no;
cout<<"Enter Your name: "<<endl;
cin.ignore();
	getline(cin,name);
	system("cls");
    cout<<"\t\t\t\t\tWelcome "<<name<<" In Student Data System\t\t\t\n";
	cout<<"\t\t\t-----------------------------------------------------------\n\n";
//	cout<<"1: Add Student\n2: Search Student\n3: Change Student Details\n4: Print Student Data\n5: Terminate Program\n\n";
	while(true){
		cout<<"\t\t\t================================================================\t\t\t\n";
		cout<<"\t\t\t||\t\t1: Add Student\n\t\t\t||\t\t2: Search Student\n\t\t\t||\t\t3: Change Student Details\n\t\t\t||\t\t4: Delete Student Data\n\t\t\t||\t\t5: Print Student Data\n\t\t\t||\t\t6: Restart Program\n\t\t\t||\t\t7: Terminate Program\n";
		cout<<"\t\t\t================================================================\t\t\t\n";
		cout<<"\nEnter Choice= ";
		cin>>no;
		switch(no){
			case 1:{
				system("cls");
				s1.Input();
				s1.Link_data();
				cout<<endl;
				break;
			}
			case 2:{
				system("cls");
				cout<<"1: Search With Name\n2: Search With Roll No\n3: Search With Cycle NO\n";
				cout<<"-----------------------------------\n\n";
				cout<<"Enter One Number Of above: ";
				int x;
				cin>>x;
				s1.search(x);
				cout<<endl;
				break;
			}
			case 3:{
				system("cls");
				int r;
				cout<<"Enter Roll No to modified data: ";
				cin>>r;
				s1.modified_data(r);
				cout<<endl;
				break;
			}
			case 4:{
				system("cls");
				int r;
				cout<<"Enter Roll No to Delete data: ";
				cin>>r;
				s1.Delete(r);
				cout<<endl;
				break;
			}
			case 5:{
				system("cls");
				s1.Print();
				break;
			}
			case 6:{
				system("cls");
				cout<<"Program Restart Successfully!!!\n";
				goto p;
				break;
			}
			case 7:{
				exit(0);
				break;
			}
			default:{
				cout<<"Wrong Choice!!!\n";
				break;
			}
		}
		
	}
//	goto p;
	system("pause");
return 0;
}
