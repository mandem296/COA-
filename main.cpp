#include<iostream>
#include <cstdlib>
#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
using namespace std;

string FracToBin(double fraction, int positionsToRightofthePoint,string output)
{
    string final = "";

    int leftSide = fraction;
    double fractional = fraction - leftSide;

    while (leftSide)
    {
        int rem = leftSide % 2;

        // Append 0 in binary
        final.push_back(rem +'0');

        leftSide /= 2;
    }

    reverse(final.begin(),final.end());
    final.push_back('.');

    while (positionsToRightofthePoint--)
    {
        fractional *= 2;
        int fract_bit = fractional;

        if (fract_bit == 1)
        {
            fractional -= fract_bit;
            final.push_back(1 + '0');
        }
        else
            final.push_back(0 + '0');
    }
    if(positionsToRightofthePoint<=5){
        output="Exact";
    }else{
        output="Approximate";
    }

return final;
}

int main(){
    int number1;
    int answer[5];
    int i=1;
    int number;
    double frac;
    int bin;
    int a;
    int hex;
    int hexad;
    string Hexadecimal="";
    char hexaCharacters[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};


    cout<<"Please select the type of operation you want to undertake"<<endl;
    cout<<"1. Conversion of numbers without fractions"<<endl;
    cout<<"2. Conversion of numbers with fractions"<<endl;
    cin>>number;
    switch(number){
        case 1:
            {

            system("cls");
            cout<<"Please enter your number : ";
            cin>>number1;
            cout<<"\n";
            bin=number1;
            hex=number1;
        while(number1!= 0)
        {

            answer[i++] = bin%2;
            bin = bin/2;
            a= hex%16;
            Hexadecimal = hexaCharacters[a] + Hexadecimal;
            hex = hex/16;
        }
        cout<<"--------------------------------------------------------------------------------------------------------";
        cout<<"\n";
        cout<<"The hexadecimal equivalent is : "<<Hexadecimal<<endl;
        cout<<"\n";
        cout<<"The binary equivalent is: ";
        for(int j=i-1; j>0; j--)
        {
        cout<<answer[j];
        }
        cout<<"\n\n";
        cout<<"--------------------------------------------------------------------------------------------------------";
        break;

    }

        case 2:
            {
            system("cls");
            cout<<"Please enter the fractional number that you wish to convert to binary"<<endl;
            cin>>frac;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;
            cout<<"\n"<<endl;
            cout<<"The binary equivalent is : "<<endl;
            cout<<FracToBin(frac, 5,"")<<endl;
            cout<<"Exact"<<endl;
            cout<<"\n"<<endl;
            cout<<"-------------------------------------------------------------------------------------------------"<<endl;



            break;

            }

        default:
            cout<<"invalid option!! Please select either 1 or 2"<<endl;
            system("pause");
            system("cls");
            main();
    }
 return 0;
}


