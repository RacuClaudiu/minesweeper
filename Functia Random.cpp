#include <iostream>
#include <time.h>       //pentru timp.
#include <stdlib.h>     //memorie dinamica, randomizare.
using namespace std;
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
int main()
{
}
