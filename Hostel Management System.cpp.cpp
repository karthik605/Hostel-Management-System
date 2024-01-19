//KONGARA SRI SATYA SAI KARTHIK AP21110010328
//KOTESWAR DHULIPALLA           AP21110010327
//BOLLA SHIVA NAGA SUHAS REDDY  AP21110010329
//MEGHANASRI TADIKONDA          AP21110010326
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<fstream>
using namespace std;

class hostel
{
public:
    void login_page();
    void enter_student_data();
    void enter_staff_data();
    void update_student_data();
    void update_staff_data();
    void check_vacancies();
    void food_wastage();
    void total_food_wastage();
};

void hostel::check_vacancies()
{
  ifstream x("student_log_in.txt");
  string username,password,towernum,roomnum,bednum,fee;
  unordered_map<string,int> checkvac;

  while(x>>username)
  {
      x>>password;
      x>>towernum;
      x>>roomnum;
      x>>bednum;
      x>>fee;

      checkvac[roomnum+towernum]++;
  }

  cout<<"T1 Vacancies\n";
  for(int i=110;i<=718;i++)
  {
      string str= to_string(i);
      if(4-checkvac[str+"T1"] > 0)
      {
          cout<<str+"T1 "<<4-checkvac[str+"T1"]<<" vacancies"<<endl;
      }
  }
  cout<<endl;
  cout<<"T2 Vacancies\n";
  for(int i=110;i<=718;i++)
  {
      string str= to_string(i);
      if(4-checkvac[str+"T2"] > 0)
      {
          cout<<str+"T2 "<<4-checkvac[str+"T2"]<<" vacancies"<<endl;
      }
  }

  x.close();
}
void hostel::total_food_wastage()
{
    ifstream x1("food_wastage.txt");
    int total_wast=0;
    int weight;
    string food_item;

    while(getline(x1>>ws,food_item))
    {
        x1>>weight;
        total_wast+=weight;

        cout<<food_item<<endl;
        cout<<weight<<"Kg"<<endl;

        cout<<endl;
    }
    cout<<"Total waste: "<<total_wast<<"Kg"<<endl;
    x1.close();
}
void hostel::food_wastage()
{
    fstream x("food_wastage.txt",ios::in|ios::out|ios::app);
    string food_item;
    int weight;
    char opt;
    do{
        cout<<"Enter Food item: ";
        getline(cin>>ws, food_item);

        cout<<"Enter weight in KGs: ";
        cin>>weight;

        x<<food_item<<endl;
        x<<weight<<endl;

        cout<<"Want to Enter more?(y/n): ";
        cin>>opt;

        cin.ignore();
        cout<<endl;
    }while(opt=='y' or opt=='Y');

    cout<<"\nData Entered Successfully\n";

    x.close();
}
void hostel::update_staff_data()
{
    fstream x("staff_log_in.txt",ios::in|ios::out|ios::app);
    string username,password,job,salary;
    vector<vector<string>> Update;
    vector<string>staf;
    while(x>>username)
    {
        x>>password;
        x>>job;
        x>>salary;

        staf.push_back(username);
        staf.push_back(password);
        staf.push_back(job);
        staf.push_back(salary);

        Update.push_back(staf);

        staf.clear();
    }
    x.close();

    string update_user;
    cout<<"Enter Username of staff to update data: ";
    cin>>update_user;
    int nothere=0;
    for(int i=0; i<Update.size(); i++)
    {
        if(update_user == Update[i][0])
        {
            nothere=1;
            cout<<"1)Update password\n";
            cout<<"2)Update job details\n";
            cout<<"\n";
            int see;
            cout<<"Enter option: ";
            cin>>see;

            switch(see)
            {
            case 1:
                {
                string update_pass;
                cout<<"Enter updated password: ";
                cin>>update_pass;
                Update[i][1]=update_pass;
                break;
                }

            case 2:
                {
                string update_job,update_salary;
                cout<<"Enter Updated job: ";
                cin>>update_job;
                Update[i][2]=update_job;

                cout<<"Enter Updated salary: ";
                cin>>update_salary;
                Update[i][3]=update_salary;

                break;
                }
            }
            break;
        }
    }
    if(nothere==0)
    {
        cout<<"\n";
        cout<<"User not found!\n";
        cout<<"\n";
    }
    else{
    ofstream x1("staff_log_in.txt");
    while(!Update.empty())
    {
        x1<<Update[0][0]<<endl;
        x1<<Update[0][1]<<endl;
        x1<<Update[0][2]<<endl;
        x1<<Update[0][3]<<endl;
        Update.erase(Update.begin());
    }
    cout<<"Updated staff data Successfully\n";
    x1.close();
    }
}
void hostel::update_student_data()
{
    fstream x("student_log_in.txt",ios::in|ios::out|ios::app);
    string tower_num,room_type,room_num,bed_num,fee_due,username,password;//  [[student1 data]
                                                                          //    [student2 data]]
    vector<vector<string>> Update;
    vector<string>stud;
    while(x>>username)
    {
        x>>password;
        x>>tower_num;
        x>>room_type;
        x>>room_num;
        x>>bed_num;
        x>>fee_due;

        stud.push_back(username);
        stud.push_back(password);
        stud.push_back(tower_num);
        stud.push_back(room_type);
        stud.push_back(room_num);
        stud.push_back(bed_num);
        stud.push_back(fee_due);

        Update.push_back(stud);

        stud.clear();
    }
    x.close();

    string update_user;
    cout<<"Enter Username of student to update data: ";
    cin>>update_user;
    int nothere=0;
    for(int i=0; i<Update.size(); i++)
    {
        if(update_user == Update[i][0])
        {
            nothere=1;
            cout<<"1)Update password\n";
            cout<<"2)Update room details\n";
            cout<<"3)Update fee due\n";
            cout<<"\n";
            int see;
            cout<<"Enter option: ";
            cin>>see;

            switch(see)
            {
            case 1:
                {
                string update_pass;
                cout<<"Enter updated password: ";
                cin>>update_pass;
                Update[i][1]=update_pass;
                break;
                }

            case 2:
                {
                string update_tower_num,update_room_type,update_room_num,update_bed_num;
                cout<<"Enter Updated tower number: ";
                cin>>update_tower_num;
                Update[i][2]=update_tower_num;

                cout<<"Enter Updated room type: ";
                cin>>update_room_type;
                Update[i][3]=update_room_type;

                cout<<"Enter Updated room number: ";
                cin>>update_room_num;
                Update[i][4]=update_room_num;

                cout<<"Enter Updated bed number: ";
                cin>>update_bed_num;
                Update[i][5]=update_bed_num;
                break;
                }

            case 3:
                {
                string updated_fee_due;
                cout<<"Enter Updated fee due: ";
                cin>>updated_fee_due;
                Update[i][6]=updated_fee_due;
                break;
                }

            }


            break;
        }
    }
    if(nothere==0)
    {
        cout<<"\n";
        cout<<"User not found!\n";
        cout<<"\n";
    }
    else{
    ofstream x1("student_log_in.txt");
    while(!Update.empty())
    {
        x1<<Update[0][0]<<endl;
        x1<<Update[0][1]<<endl;
        x1<<Update[0][2]<<endl;
        x1<<Update[0][3]<<endl;
        x1<<Update[0][4]<<endl;
        x1<<Update[0][5]<<endl;
        x1<<Update[0][6]<<endl;
        Update.erase(Update.begin());
    }
    cout<<"Updated student data Successfully\n";
    x1.close();
    }

}
void hostel::enter_staff_data()
{
    cout<<endl<<endl;
    fstream x("staff_log_in.txt",ios::in|ios::out|ios::app);
    char ch;
    string username,password,job;
    string salary;
    do{
        cout<<"Enter staff User name: ";
        cin>>username;
        cout<<"Enter Password: ";
        cin>>password;
        cout<<"Enter Job: ";
        cin>>job;
        cout<<"Enter Salary: ";
        cin>>salary;

        x<<username<<endl;
        x<<password<<endl;
        x<<job<<endl;
        x<<salary<<endl;

        cout<<"press y/Y to continue the process n/N to end process: ";
        cin>>ch;
    }while(ch=='y' or ch=='Y');

    cout<<endl<<"staff(s) data fetched successfully"<<endl;
    x.close();
}
void hostel::enter_student_data()
{
    cout<<endl<<endl;
    fstream x("student_log_in.txt",ios::in|ios::out|ios::app);
    char ch;
    string username,password,tower_num;
    string room_type;
    string room_num,bed_num,fee_due;
    do{
        cout<<"Enter student User name: ";
        cin>>username;
        cout<<"Enter Password: ";
        cin>>password;
        cout<<"Enter Tower number: ";
        cin>>tower_num;
        cout<<"Enter Room Type: ";
        cin>>room_type;
        cout<<"Enter Room Number: ";
        cin>>room_num;
        cout<<"Enter Bed Number: ";
        cin>>bed_num;
        cout<<"Enter fee due: ";
        cin>>fee_due;

        x<<username<<endl;
        x<<password<<endl;
        x<<tower_num<<endl;
        x<<room_type<<endl;
        x<<room_num<<endl;
        x<<bed_num<<endl;
        x<<fee_due<<endl;

        cout<<"press y/Y to continue the process n/N to end process: ";
        cin>>ch;
    }while(ch=='y' or ch=='Y');

    cout<<endl<<"student(s) data fetched successfully"<<endl;
    x.close();
}
void hostel::login_page()
{
        string person;
        cout<<"Admin login Press A (or) a\nStudent login Press S (or) s\n";
        cin>>person;
        string username,check_user;
        string password,check_pass;
        if(person=="a" or person=="A")
        {
            cout<<"Enter username: ";
            cin>>username;
            cout<<"Enter password: ";
            cin>>password;
            int temp=0;
            ifstream x("admin_log_in.txt");
            while(x>>check_user)
            {
                x>>check_pass;
                if(username==check_user && password==check_pass)
                {
                    temp=1;
                    cout<<endl;
                    cout<<"_____________SRM AP Hostel Management system Admin page_____________"<<endl;
                    break;

                }
                else if(username!=check_user && password==check_pass)
                {
                    temp=2;
                }
                else if(username==check_user && password!=check_pass)
                {
                    temp=3;
                }
            }
            if(temp==0)
            {
                cout<<"User not found"<<endl;
            }
            else if(temp==2)
            {
                cout<<"Check username"<<endl;
            }
            else if(temp==3)
            {
                cout<<"Incorrect password"<<endl;
            }

            if(temp==1)
            {
                cout<<endl<<"Choose the option "<<endl;
                cout<<"1)Enter student data"<<endl;
                cout<<"2)Enter staff data"<<endl;
                cout<<"3)Update student data"<<endl;
                cout<<"4)Update staff data"<<endl;
                cout<<"5)Check Vacancies"<<endl;
                cout<<"6)Enter Mess Food wastage(in KGs)"<<endl;
                cout<<"7)Check Total Food wastage(in KGs)"<<endl;
                int choice;
                cout<<endl;
                cout<<"Enter your choice: ";
                cin>>choice;
                //code continues.....
                switch(choice)
                {
                case 1:
                    enter_student_data();
                    break;
                case 2:
                    enter_staff_data();
                    break;
                case 3:
                    update_student_data();
                    break;
                case 4:
                    update_staff_data();
                    break;
                case 5:
                    check_vacancies();
                    break;
                case 6:
                    food_wastage();
                    break;
                case 7:
                    total_food_wastage();
                    break;
                default:
                    cout<<endl<<"Invalid Input"<<endl;
                }
            }

        }
        if(person=="S" or person=="s")
        {
            int temp=0;
            cout<<"Enter username: ";
            cin>>username;
            cout<<"Enter password: ";
            cin>>password;
            string tower_num,room_type,room_num,bed_num,fee_due;
            ifstream fi("student_log_in.txt");
            while(fi>>check_user)
            {
                fi>>check_pass;
                fi>>tower_num;
                fi>>room_type;
                fi>>room_num;
                fi>>bed_num;
                fi>>fee_due;
                if(check_user == username && check_pass == password)
                {
                    temp=1;
                    cout<<endl;
                    cout<<"*******Room details*******"<<endl;
                    cout<<"Room Type: "<<room_type<<endl;
                    cout<<"Allotted Room Number: "<<tower_num<<"/Level "<<room_num[0]<<"/"<<room_num<<"/Bed-"<<bed_num<<endl;
                    cout<<"Fee due: "<<fee_due<<endl<<endl;
                    break;
                }
            }
            if(temp==0)
            {
                cout<<"Invalid Credentials"<<endl;
            }
        }

}
int main()
{
    cout<<"*****************SRM AP Hostel Portal*****************\n";
    cout<<endl;
    hostel o1;
    o1.login_page();
    return 0;
}
