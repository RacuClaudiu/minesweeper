#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void reluare();
int random(int, int);
void dezvaluire(int);
void alegere();
int n=0,m=0,i=0,j=0,bomb=0,boo=0,x,y,q,z,defuse=0;
int JocTerminat;
int steag();
int tabla[100][100];
int main()
{
    int steag[100],u=0,v=0,uv=0,ch;
 B1:
    cout<<endl;
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
           system("CLS");
         cout << ">>> Ai ales gresit! <<<" << endl;
	      cout<<endl;
	      goto Begin;
    }
    switch (choice)
    {
    case 1:
        n=3;
        m=3;
        bomb=2;
        boo=bomb;
        defuse=bomb;
        break;
    case 2:
        n=5;
        m=5;
        bomb=4;
        boo=bomb;
        break;
    case 3:
        n=7;
        m=7;
        bomb=9;
        boo=bomb;
        break;
    case 4:
        n=9;
        m=9;
        bomb=20;
        boo=bomb;
        break;
    case 5:
        c1:
        cout<<"lungime"<<" "<<"(minim : 2; maxim 15): ";
        cin>>n;
        cout<<"latime"<<" "<<" (minim : 2; maxim 15): ";
        cin>>m;
        cout<<"numar de bombe "<<"(maxim: "<<n*m-1<<"): ";
        cin>>bomb;
        boo=bomb;
        if(n<2 || m<2 || n>15 || m>15 || bomb>n*m-1)
        {
            cout<<"Numere prea mari, va rugam reintroduceti:"<<endl<<endl;
            goto c1;
        }
        break;
    case 6:
        exit(0);
    }
   F3: x=0;
    y=0;
    JocTerminat=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            tabla[i][j] = 0;
    cout<<tabla[i][j]<<" ";
        }
            cout<<endl;
    }
    i = random(i, m);
    j = random(j, n);
    do
    {
        i+=3;
        j+=6;
        y = random(i, m);
        x = random(j, n);
        if(tabla[x][y] != 9)        // Daca nu e deja bomba. Cu 9 am notat bomba.
        {
            tabla[x][y]=9;
            bomb--;
            if((x-1) >= 0)
                if(tabla[x-1][y] != 9)
                    tabla[x-1][y]++;
            if((x-1) >= 0 && (y-1) >= 0)
                if(tabla[x-1][y-1] != 9)
                    tabla[x-1][y-1]++;
            if((y-1) >= 0)
                if(tabla[x][y-1] != 9)
                tabla[x][y-1]++;
            if((x+1) < n)
                if(tabla[x+1][y] != 9)
                    tabla[x+1][y]++;
            if((x+1) < n && (y+1) < m)
                if(tabla[x+1][y+1] != 9)
                    tabla[x+1][y+1]++;
            if((y+1) < m)
                if(tabla[x][y+1] != 9)
                    tabla[x][y+1]++;
                if((x-1) >= 0 && (y+1) < m)
                    if(tabla[x-1][y+1] != 9)
                        tabla[x-1][y+1]++;
                if((x+1) < n && (y-1) >= 0)
                    if(tabla[x+1][y-1] != 9)
                        tabla[x+1][y-1]++;
                         }
        }while(bomb>0);
         int vector[m][n];
           for(i = 0; i < m; i++)
            for(j=0;j<n;j++)
            vector[i][j]=0;
           cout<<endl;
           for(i=0;i<m;i++){
                for(j=0;j<n;j++)
                cout<<tabla[i][j]<<" ";
           cout<<endl;
         }
do{
        bomb=0;
        q=0;
   D1: system("CLS");
   cout<<endl<<endl;
   cout<<"------BOMBE RAMASE: "<<boo<<" -----"<<endl<<endl;
    cout<<"    ";
    for(j=0;j<n;j++)
        cout<<j<<" ";
    cout<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            {
                if(j==0){
                cout << i ;
                if(i<10){
                        cout<<" ";
                    }
                    cout<< " |";

                }
        if(vector[i][j]==1)
            dezvaluire(tabla[i][j]);
        else
            cout << "_|";
        if(j==(n-1))
            cout << endl;
        if(tabla[i][j]!=9 && vector[i][j]==1)
            q++;
        if(tabla[i][j] == 9)
            bomb++;
        }
        }
        win:
            if(q >= ((m*n) - bomb) || boo==0)                                                           //Mesaj "castig"
                         {
                             cout<<endl;
                        cout << "--------Felicitari! Ai castigat!-------" << endl;
                                    JocTerminat = 1;
                         }
                         if(JocTerminat == 0)
                         {


  F1:  cout<<" Alegeti una din cele doua variante:";
    cout<<" 1) click;";
    cout<<" 2) steag;"<<endl;
    cin>>ch;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    if(ch<1 || ch>2)
    {
       system("CLS");
         cout << ">>> Ai ales gresit! <<<" << endl;
         cout<<endl;
         goto F3;
    }
    switch(ch)
    {
        case 1:
            break;
        case 2:
            if(tabla[x][y]==9)
                boo--;
                if(boo==0)
                    goto win;
                tabla[x][y]=steag[uv];
            if(tabla[x][y]!=10)
            {
                steag[uv]=tabla[x][y];
                tabla[x][y]=10;
                cout<<"steag in punctul: "<<x<<y;
            }
            break;
    }
                         }
                        if(tabla[x][y] == 9 && boo!=0)
                         {
                             system("CLS");
                             cout << "---------Ai lovit o mina!----------" << endl;
                             cout << "   ";
                             for(i=0;i<m;i++)
                                cout << i << " ";
                             cout << endl;
                             JocTerminat = 1;
                             for(i=0; i<m; i++)
                                {
                                    for(j=0;j<n;j++)
                                        {
                                            if(j==0)
                                                cout << i << " |";
                                                if(tabla[i][j]==9)
                                                    vector[i][j]=1;
                                                if(vector[i][j]==1)
                                                dezvaluire(tabla[i][j]);
                             else
                                cout << "_|";
                             if(j==(n-1))
                                cout << endl;
                             }
                             }
                             }
                             if(tabla[x][y]==0)
                         {
                             vector[x][y] = 1;
                                    for(i=0;i<m;i++)
                                    {
                                        for(j=0;j<n;j++)
                                        {
                                            if(i>(x-2)&&i<(x+2))
                                            if(j>(y-2)&&j<(y+2))
                                            if(tabla[i][j]!=9)
                                            vector[i][j]=1;
                                            }
                                            }
                                            }
                                        if(tabla[x][y]>0 && tabla[x][y]<9)
                                            vector[x][y] = 1;
           } while(JocTerminat == 0);
           if (JocTerminat == 1)
           reluare();
}
void reluare()
{
    int choice;
    cout<<endl;
    cout<<" 1) reia;"<<endl;
    cout<<" 2) iesire;"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        main();
    case 2:
      break;
    }
}
void dezvaluire(int x)
{
           if(x == 0)
                         cout << "o|";
           else if(x == 9)
                         cout << "x|";
           else
                         cout << x << "|";
}
int random(int i, int b)
{
           long ran;
           int t = time(0);
           int s;
           srand(t);
           s = ran;
           ran = rand();
           ran >>= ran / (ran * i) + (i * 1337);
           ran = ran % b;
           return ran;
}
void alegere()
{
    char steag[100];
    int q,u;
    cout<<" 1) click;";
    cout<<" 2) steag;"<<endl;
    cin>>q;
    switch(q)
    {
    case 1:
        break;
    case 2:
         u=((4*i)+(2*j)+1);
    if(tabla[i][j]!='F'){
    steag[u]=tabla[i][j];
    tabla[i][j]='F';
    }
    cout<<tabla[i][j];
        break;
    }
}
int steagg(int u)
{
    int steag[100];
    if(tabla[i][j]!='F'){
    steag[4*i+2*j+1]=tabla[i][j];
    tabla[i][j]='F';
    }
    if(tabla[i][j]=='F')
        tabla[i][j]=steag[4*i+2*j+1];
}
