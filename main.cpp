#include <iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Flight
    {
    char fno[10],source[30],dest[30],brand[30],date[15],dtime[10],atime[10];
    int price,e_seats,bc_seats,fc_seats;
    float rating;
    public:
    void display(int c);
    void search_flight(int c);
    void book_ticket(int c);
    void calc(char arr[],int p,int s,int c1);
    void hotel();
    void info();
    };

void Flight::display(int c)
    {
    ifstream f1;
    if(c==1)
        {
         f1.open("DFlights.txt",ios::in | ios::binary);
        }
    else if(c==2)
        {
         f1.open("DFlights.txt",ios::in | ios::binary);
        }
    if(!f1)
        {
        cout<<"File cannot be opened\n";
        }
    else
        {
        while(f1>>fno>>source>>dest>>brand>>date>>dtime>>atime>>price>>e_seats>>bc_seats>>fc_seats>>rating)
            {
            cout<<"Flight number : "<<fno<<"\n";
            cout<<"Starting from : "<<source<<"\n";
            cout<<"Destination : "<<dest<<"\n";
            cout<<"Company : "<<brand<<"\n";
            cout<<"Date : "<<date<<"\n";
            cout<<"Departure time : "<<dtime<<"\n";
            cout<<"Arrival time : "<<atime<<"\n";
            cout<<"Price per ticket : "<<price<<"\n";
            cout<<"Number of economy class seats available : "<<e_seats<<"\n";
            cout<<"Number of business class seats available : "<<bc_seats<<"\n";
            cout<<"Number of first class seats available : "<<fc_seats<<"\n";
            cout<<"Rating : "<<rating<<"\n";
            cout<<"\n";
            cout<<"------------------------------------------------------------------\n";
            }
        }
    f1.close();
    }

void Flight::search_flight(int c)
    {
    int temp=0;
    ifstream f2;
    if(c==1)
        {
        f2.open("DFlights.txt");
        }
    else if(c==2)
        {
        f2.open("IFlights.txt");
        }
    char choice[30];
    cout<<"Enter your preferred starting point or destination. eg Pune\n";
    cout<<"Or enter your preferred brand. eg IndiGo\n";
    cout<<"Or enter your preferred date of departure (dd-mm-yyyy) format\n";
    cin>>choice;
    cout<<"\n";
    while(f2>>fno>>source>>dest>>brand>>date>>dtime>>atime>>price>>e_seats>>bc_seats>>fc_seats>>rating)
        {
        if(strcmp(choice,source)==0||strcmp(choice,dest)==0||strcmp(choice,brand)==0||strcmp(choice,date)==0)
            {
            cout<<"Flight number : "<<fno<<"\n";
            cout<<"Starting from : "<<source<<"\n";
            cout<<"Destination : "<<dest<<"\n";
            cout<<"Company : "<<brand<<"\n";
            cout<<"Date : "<<date<<"\n";
            cout<<"Departure time : "<<dtime<<"\n";
            cout<<"Arrival time : "<<atime<<"\n";
            cout<<"Price per ticket : "<<price<<"\n";
            cout<<"Number of economy class seats available : "<<e_seats<<"\n";
            cout<<"Number of business class seats available : "<<bc_seats<<"\n";
            cout<<"Number of first class seats available : "<<fc_seats<<"\n";
            cout<<"Rating : "<<rating<<"\n";
            cout<<"\n";
            cout<<"--------------------------------------------------\n";
            temp++;
            }
        }
    if(temp==0)
        {
        cout<<"Error! Flight not found\n";
        exit(0);
        }
    f2.close();
    }

void Flight::book_ticket(int c)
    {
    int ch;
    ifstream f3;
    char choice[10];
    if(c==1)
        {
        f3.open("DFlights.txt");
        }
    else if(c==2)
        {
        f3.open("IFlights.txt");
        }
    cout<<"Enter the flight number of the flight you wish to book tickets for : ";
    cin>>choice;
    cout<<"\n";
    cout<<"Press 1 if you want to book economy class tickets (No extra charge)\n";
    cout<<"Press 2 if you want to book business class tickets (Rs.10000 extra per ticket)\n";
    cout<<"Press 3 if you want to book first class tickets (Rs.15000 extra per ticket)\n";
    cout<<"Enter your choice : ";
    cin>>ch;
    cout<<"\n";
    while(f3>>fno>>source>>dest>>brand>>date>>dtime>>atime>>price>>e_seats>>bc_seats>>fc_seats>>rating)
        {
        if(strcmp(fno,choice)==0)
            {
            if(ch==1)
                {
                calc(fno,price,e_seats,ch);
                }
            else if(ch==2)
                {
                calc(fno,price,bc_seats,ch);
                }
            else if(ch==3)
                {
                calc(fno,price,fc_seats,ch);
                }
            else
                {
                cout<<"Invalid input\n"
                exit(0);
                }
            }
        }
    f3.close();
    }

void Flight::calc(char arr[],int p,int s,int c1)
    {
    int n1,n2,n3,N;
    float p1,p2,p3,amt;
    if(c1==1)
        {
        cout<<"Number of economy class seats available : "<<s<<"\n";
        }
    else if(c1==2)
        {
        cout<<"Number of business class seats available : "<<s<<"\n";
        }
    else if(c1==3)
        {
        cout<<"Number of first class seats available : "<<s<<"\n";
        }
    cout<<"\n";
    cout<<"Enter the number of adults travelling (No discount) : ";
    cin>>n1;
    cout<<"Enter the number of children (less than 18 years old) travelling (10% discount) : ";
    cin>>n2;
    cout<<"Enter the number of senior citizens (above 65 years old) travelling (12.5% discount) : ";
    cin>>n3;
    cout<<"\n";
    switch(c1)
        {
        case 1:
                p1=n1*p;
                p2=n2*(p-0.1*p);
                p3=n3*(p-0.125*p);
                amt=p1+p2+p3;
                N=n1+n2+n3;
                if(N<=s)
                    {
                    cout<<"Booking successful\n";
                    cout<<"You have opted for economy class seats\n";
                    cout<<"Total number of seats : "<<N<<"\n";
                    cout<<"Total amount is : "<<amt<<"\n";
                    cout<<"\n";
                    cout<<"---------------------------------------------------\n";
                    }
                else
                    {
                    cout<<"Seats are not available\n";
                    }
                break;
        case 2:
               p=p+10000;
               p1=n1*p;
               p2=n2*(p-0.1*p);
               p3=n3*(p-0.125*p);
               amt=p1+p2+p3;
               N=n1+n2+n3;
               if(N<=s)
                    {
                    cout<<"Booking successful\n";
                    cout<<"You have opted for business class seats\n";
                    cout<<"Total number of seats : "<<N<<"\n";
                    cout<<"Total amount is : "<<amt<<"\n";
                    cout<<"\n";
                    cout<<"---------------------------------------------------\n";
                    }
                else
                    {
                    cout<<"Seats not available\n";
                    }
                break;
        case 3:
                p=p+15000;
                p1=n1*p;
                p2=n2*(p-0.1*p);
                p3=n3*(p-0.125*p);
                amt=p1+p2+p3;
                N=n1+n2+n3;
                if(N<=s)
                    {
                    cout<<"Booking successful\n";
                    cout<<"You have opted for first class seats\n";
                    cout<<"Total number of seats : "<<N<<"\n";
                    cout<<"Total amount is : "<<amt<<"\n";
                    cout<<"\n";
                    cout<<"---------------------------------------------------\n";
                    }
                else
                    {
                    cout<<"Seats not available\n";
                    }
                break;
        default:cout<<"Invalid input\n";
        }
    }

void Flight::hotel()
    {
    int e=0;
    char ch[30],city[30],hname[30],web[30],no[15];
    ifstream f4;
    f4.open("Hotels.txt",ios::in | ios::binary);
    if(!f4)
        {
        cout<<"File cannot be opened\n";
        }
    else
        {
        do
            {
            cout<<"Enter the city in which you wish to look for a hotel\n";
            cin>>ch;
            while(f4>>city>>hname>>web>>no)
                {
                if(strcmp(ch,city)==0)
                    {
                    cout<<"City : "<<city<<"\n";
                    cout<<"Hotel Name : "<<hname<<"\n";
                    cout<<"Hotel Website : "<<web<<"\n";
                    cout<<"Hotel Contact Number : "<<no<<"\n";
                    cout<<"\n";
                    cout<<"--------------------------------------------------\n";
                    }
                }
            cout<<"Press 1 if you want to exit\n";
            cin>>e;
            }
        while(e!=1);
        }
    f4.close();
    }

void Flight::info()
    {
    char code[5],city[30];
    ifstream f5;
    f5.open("FInfo.txt",ios::in | ios::binary);
    while(f5>>code>>city)
        {
        cout<<"Airport Code : "<<code<<"\n";
        cout<<"City : "<<city<<"\n";
        cout<<"\n";
        cout<<"--------------------------------------------------\n";
        }
    f5.close();
    }

int main()
    {
    Flight obj;
    int ch1,ch2,c,ex=0;
    int h=0;
    char pass[15];
    cout<<"\t\t\tWELCOME!\n";
    cout<<"\n";
    cout<<"Press 1 if you are an administrator\n";
    cin>>ch1;
    cout<<"\n";
    if(ch1==1)
        {
        cout<<"Enter the password\n";
        cin>>pass;
        cout<<"--------------------------------------------------\n";
        if(strcmp(pass,"F1202")==0)
            {
            do
                {
                cout<<"Press 1 for domestic flights\n";
                cout<<"Press 2 for international flights\n";
                try
                    {
                    cout<<"Enter your choice\n";
                    cin>>ch2;
                    cout<<"\n";
                    if(!(ch2==1||ch2==2))
                        {
                        throw c;
                        }
                    }
                catch(int e)
                    {
                    cout<<"Invalid input!\n";
                    exit(0);
                    }
                cout<<"Press 1 if you want to view the details of all the flights\n";
                cout<<"Press 2 if you want to search for a flight\n";
                cout<<"Press 3 if you want to view the various cities and their respective airport codes\n";
                cout<<"Enter your choice\n";
                cin>>c;
                cout<<"\n";
                switch(c)
                    {
                    case 1:if(ch2==1)
                                {
                                cout<<"The details of the domestic flights are as follows\n";
                                cout<<"\n";
                                obj.display(ch2);
                                }
                            else if(ch2==2)
                                {
                                cout<<"The details of the international flights are as follows\n";
                                cout<<"\n";
                                obj.display(ch2);
                                }
                            else
                                cout<<"Invalid input!\n";
                            break;
                    case 2:obj.search_flight(ch2);
                            break;
                    case 3:obj.info();
                            break;
                    default:cout<<"Invalid input!\n";
                    }
                cout<<"Press 1 if you wish to exit\n";
                cin>>ex;
                }
            while(ex!=1);
            }
        else
            {
            cout<<"Wrong password. Please try again\n";
            }
        }
    else
        {
        cout<<"\n";
        cout<<"Press 1 for domestic flights\n";
        cout<<"Press 2 for international flights\n";
        cin>>ch2;
        cout<<"\n";
        if(ch2==1)
            {
            cout<<"The details of the domestic flights are as follows\n";
            cout<<"\n";
            obj.display(ch2);
            }
        else if(ch2==2)
            {
            cout<<"The details of the international flights are as follows\n";
            cout<<"\n";
            obj.display(ch2);
            }
        else
            {
            cout<<"Invalid input\n";
            }
        obj.search_flight(ch2);
        obj.book_ticket(ch2);
        cout<<"---------------------------------------------------\n";
        cout<<"We are associated with some of the best hotels in the country\n";
        cout<<"You can avail a discount of 10% at these hotels by simply showing them the booking confirmation\n";
        cout<<"Press 1 if you would like to view the hotels we are associated with\n";
        cin>>h;
        cout<<"\n";
        if(h==1)
            {
            obj.hotel();
            }
        cout<<"\t\t\tThank you for using our portal to book your flight tickets\n";
        cout<<"\t\t\tWe hope you have a safe and enjoyable journey\n";
        cout<<"--------------------------------------------------\n";
        return 0;
        }
    }
