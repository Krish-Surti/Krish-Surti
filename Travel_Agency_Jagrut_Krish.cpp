#include<iostream>
#include<stdlib.h>
using namespace std;

void clrscr() {
    system("cls");
}

struct Pre {
    int n, d, co;
    string c[4];
};

class Cities {
    public:
    string c[14] = {"Ahmedabad","Anand","Bhavnagar","Dwarka","Gandhinagar","Junagadh","Kutch","Mehsana","Morbi","Nadiad","Rajkot","Surat","Vadodara","Verawal"};
};

class Pages: public Cities {
    public:
    char homep() {
        clrscr();
        char opt;
        cout<<"***Welcome to JAI AMBE TRAVELS***\n";
        cout<<"Press b to book your trip,\nPress c to contact us.\nPress r to write a review about our services.\nPress e to exit.\n";
        cin>>opt;
        return opt;
    }

    int booking() {
        re:
        clrscr();
        char opt;
        cout<<"Press p to see our premade packages, or press g to go back.\n";
        cin>>opt;
        switch(opt) {
            case 'P':
            case 'p': {
                int pack;
                char op;
                pack=packages();
                cout<<"Press p to proceed to payment.\nPress c to cancel and start over.\n";
                cin>>op;
                switch(op) {
                    case 'P':
                    case 'p': {
                        Payment(pack);
                        break;
                    }
                    case 'C':
                    case 'c': {
                        goto re;
                    }
                }
                return 0;
                break;
            }
            case 'G':
            case 'g': {
                return 1;
                break;
            }
            default:
                return 0;
        }
    }

    int packages() {
        clrscr();
        int pno;
        cout<<"The packages we offer are:\n";
        cout<<"No\tDays\tCost\tCities\n";
        Pre p[4] = {{1,3,5000,{c[0],c[7]}},{2,7,12000,{c[3],c[5],c[8],c[11]}},{3,5,7500,{c[2],c[6],c[10]}},{4,6,9000,{c[13],c[12],c[9],c[4]}}};
        for(int i=0; i<4; i++) {
            cout<<p[i].n<<"\t"<<p[i].d<<"\t"<<p[i].co<<"\t";
            for(int c=0; c<4; c++) {
                cout<<p[i].c[c]<<" ";
            }
            cout<<endl<<endl;
        }
        cout<<"Enter pack no. you find perfect for you.\n";
        cin>>pno;
        return --pno;
    }

    void Payment(int pack) {
        clrscr();
        Pre p[4] = {{1,3,5000,{c[0],c[7]}},{2,7,12000,{c[3],c[5],c[8],c[11]}},{3,5,7500,{c[2],c[6],c[10]}},{4,6,9000,{c[13],c[12],c[9],c[4]}}};
        cout<<"You have selected pack number: "<<pack+1<<endl;
        cout<<"Your bill will be: Rs."<<p[pack].co<<endl;
        cout<<"Since this is your first trip with us you get a 10% discount.\n";
        p[pack].co -= p[pack].co*0.1;
        cout<<"Total bill: Rs."<<p[pack].co<<endl<<endl;
        cout<<"Thank you for travelling with us!! Please do visit again!\n\n\n\n";
    }

    char rev() {
        r:
        clrscr();
        int star;
        char opt;
        string rev;
        cout<<"Enter your ratings out of 5:\t";
        cin>>star;
        cout<<"Enter review\n";
        cin>>rev;
        cout<<"To review again press 'e', and to go back press 'g'.\n";
        cin>>opt;
        if(opt=='e') {
            goto r;
            return 0;
        }
        else
            return opt;
    }

    char Contact() 
    {
        char opt;
        cout<<"Our contact details are:\n\nIn Surat\n";
        cout<<"Owner of the agency: Ramnikbhai Patel\n";
        cout<<"To contact, call on: 7977545312\n";
        cout<<"Our address: Baranpuri, Bhagal, Char Rasta, Opp. Reshamvala Medical, Surat - 395001\n";
        cout<<"Our tour guides in respective cities and their phone numbers:\nAhmedabad: Jignesh Shah, Ph No.:  8291598231\nDwarka: Dev Mehta, Ph No.:  9512464656\nKutch: Jethalal Gada, Ph No.: 8097859730\nSurat: Mehul Chhatriwala, Ph No.: 7622085035\n";
        cout<<"\nPress 'g' to go back.";
        cin>>opt;
        return opt;
    }
};

int main() {
    Pages p;
    Loop:
    switch(p.homep()) {
        case 'B':
        case 'b': {
            if(p.booking()==1) {
                goto Loop;
            }
            else
                break;
        }

        case 'R':
        case 'r': {
            if(p.rev()=='g') {
                goto Loop;
            }
            else
                break;
        }

        case 'C':
        case 'c': {
            if(p.Contact()=='g') {
                goto Loop;
            }
            else
                break;
        }

        case 'E':
        case 'e': {
            goto End;
        }
    }
    End:
    return 0;
}