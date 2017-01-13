
#include<iostream>
using namespace std;
int n,m,i,j,bomb=0,x,y;
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













    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            tabla[i][j] = 1;
    cout<<tabla[i][j]<<" ";
        }
            cout<<endl;
    }
    //i = random(i, m);
   // j = random(j, n);
    do
    {
        i+=3;
        j+=6;
       // y = random(i, m);
        //x = random(j, n);
        if(tabla[y][x] != 9)        // Daca nu e deja bomba. Cu 9 am notat bomba.
        {
            tabla[x][y]=9;
            bomb--;
            if((x-1)>=0){
                if(tabla[x-1][y]!=9)
                    tabla[x-1][y]++;//Dam valorii din punct +1 pentru a marca bomba din apropiere.
                if((y-1)>=0)
                    if(tabla[x-1][y-1] != 9){
                        tabla[x-1][y-1]++;
                            if(tabla[x][y-1] != 9)
                                tabla[x][y-1]++;
                }
            }
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

    //for(i=1;i<=m;i++){
       // for(j=1;j<=n;j++)
            //cout<<tabla[i][j]<<" ";
            //cout<<endl;
  //  }



























    if(choice!=6){
    cout<<" 1) replay;"<<endl;
    cout<<" 2) exit;"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        goto Begin;
    }
    }
}
