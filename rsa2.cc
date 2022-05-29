#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
//Function to find gcd
//of two numbers
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

//FUNCTION TO FIND inverse
int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if ((((a%m) * (x%m)) % m ) == 1)
            return x;
         return -1;

}
//FUNCTION TO ATTACK WHEN e=3 BY FIND MESSAGE WITH CUBE
void attack(int e,int n){
    int i=3;
    double E,s;
   while(true){
    E=1/(e*1.0);
    s=pow((i*1.0),(E));
    s=fmod(s,(n*1.0));
    if(floor(s)==s){
        cout<<"message = "<<i <<endl;
        break;}
    else
        i++;


}
}
int main()
{
//Enter two large prime
// numbers p and q
int p,q,n,Pn,e;
int d;
  p = 53;
  q = 59;
//Select an encryption key
  e=3;
  n = p * q;
  Pn = (p-1)*(q-1);
//Generate privte key d

 d = modInverse(e,Pn);

if(d>0) {

    cout<<"decryption key is: "<<d<<endl;
}
else
 cout<<"Multiplicative inverse for the given encryption key does not  exist. Choose a different encryption key ";

// Enter the message to be sent

int M = 8;

//Signature is created by Alice
int S = pow(M, d);
S=S%n;
cout<<"Signature is "<<S<<endl;
//Alice sends M and S both to Bob
//Bob generates message M1 using the
//signature S, Alice's public key e
//and product n.
 int M1 = pow(S, e);
 M1=M1%n;

//If M = M1 only then Bob accepts
//the message sent by Alice.

if (M == M1){
    cout<<"As M = M1, Accept the message sent by Alice"<<endl;
}
else {
   cout<<"As M not equal to M1, Do not accept the message sent by Alice "<<endl;
}

attack(e,n);

    return 0;
}
