#include<iostream>
using namespace std;
int n,m,i,j,bomb=0;
int main()
{
    int tabla[100][100];
    cout<<"-----------BUN VENIT PE MINESWEEPER---------"<<endl<<endl;
    Begin:	unsigned short choice;
    cout<<"Selectati nivelul de dificultate: "<<endl;
    cout<<" "<<"1) Incepator;"<<endl;
    cout<<" "<<"2) Usor;"<<endl;
    cout<<" "<<"3) Intermediar;"<<endl;
    cout<<" "<<"4) Expert;"<<endl;
    cout<<" "<<"5) Custom..."<<endl;
    cout<<" "<<"6) Iesire"<<endl;
    cin>>choice;
    if(choice<=0 || choice >=7)
    {
        cout<<endl;
         cout << ">>> Ai ales gresit! <<<" << endl;
	      cout<<endl;
	      goto Begin;
    }
    switch (choice)
    {
    case 1:
        n=3;
        m=3;

        break;
    case 2:
        n=5;
        m=5;
        break;
    case 3:
        n=7;
        m=7;
        break;
    case 4:
        n=9;
        m=9;
        break;
    case 5:
        c1:
        cout<<"lungime"<<" "<<"(minim : 2; maxim 19): ";
        cin>>n;
        cout<<"latime"<<" "<<" (minim : 2; maxim 19): ";
        cin>>m;
        cout<<"numar de bombe "<<"(maxim: "<<n*m-1<<"): ";
        cin>>bomb;
        if(n<2 || m<2 || n>19 || m>19 || bomb>n*m-1)
        {
            cout<<"Numere prea mari, va rugam reintroduceti:"<<endl<<endl;
            goto c1;
        }
        break;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
            cout<<tabla[n][m]<<" ";
            cout<<endl;
    }
}
