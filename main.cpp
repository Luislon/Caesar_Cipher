#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


void original_alphavit(char array_alphavit[])
{
    int value1 = 0;
    for(char letter = 'A';letter<='Z';letter++,value1++)
    {
        array_alphavit[value1]=letter;
    }
}

void clipping_alphavit(char array_alphavit2[],int typed_text)
{
    int value2 = 0;
    for(char letter2=('A'+typed_text);letter2<='Z';letter2++,value2++)
    {
        array_alphavit2[value2]=letter2;
    }

    for(char letter3 = 'A';letter3<='A'+typed_text-1;letter3++,value2++)
    {
        array_alphavit2[value2]=letter3;
    }
}

void encryption_function(char mono_text[],char array_alphavit[],char array_alphavit2[],int int_alphavit[],char encoded_text[])
{
    for (int count = 0; count < strlen(mono_text); count++)
    {
        int value3 = 0;
        for (int count2 = 0; count2 < 26; count2++)
        {
            if(mono_text[count] == array_alphavit[count2])
            {
                int_alphavit[count] = value3;
                break;
            }
            value3++;
        }
    }
    cout << "Your encrypted   code >> ";

    for(int ct_mono = 0; ct_mono < strlen(mono_text); ct_mono++)
    {
        if (int_alphavit[ct_mono] != -1 && mono_text[ct_mono] == array_alphavit[int_alphavit[ct_mono]])
        {
            encoded_text[ct_mono] = array_alphavit2[int_alphavit[ct_mono]];
            cout <<  array_alphavit2[int_alphavit[ct_mono]];
        }
        else
        {
            encoded_text[ct_mono] = mono_text[ct_mono];
            cout << mono_text[ct_mono];
        }
    }

}

void deciphering_function(int int_alphavit[],char encoded_text[],char array_alphavit2[],char array_alphavit[],char mono_text[])
{

    cout << "Your unencrypted code >> ";
    for (int ct_mono2 = 0; ct_mono2 < strlen(encoded_text); ct_mono2++)
    {
        if(int_alphavit[ct_mono2]!= -1 && encoded_text[ct_mono2] == array_alphavit2[int_alphavit[ct_mono2]])
            cout << array_alphavit[int_alphavit[ct_mono2]];

        else
        {
            encoded_text[ct_mono2] = mono_text[ct_mono2];
            cout << mono_text[ct_mono2];
        }
    }
}

int main()
{
    char array_alphavit[26]={};
    char array_alphavit2[26]={};
    char *mono_text  = new char[300];
    int  int_alphavit[26];
    char encoded_text[27]{};
    for (int i = 0; i < 26; ++i)
        int_alphavit[i] = -1;
    int typed_text = 0;
    int value0 = 0;

    original_alphavit(array_alphavit);
    cout << "Enter the number to encrypt the alphabet: ";
    cin >> typed_text;

    if(typed_text < 0)
    {
        typed_text = (26-(-typed_text % 26));
    }
    else
    {
        typed_text %= 26;
    }
    clipping_alphavit(array_alphavit2,typed_text);
    cout << "Enter the text to encrypt it: ";
    cin.ignore();
    cin.get(mono_text,300);

    for(int i = 0;i < strlen(mono_text); i++)
    {
        if(isalpha(mono_text[i]))
            mono_text[i] = toupper(mono_text[i]);
    }
    cout << "Enter 1 so as encrypt or 2 for decryption(and q for log out): ";
    while(cin >> value0)
    {
        if(value0 > 2)
            cout << "Enter again" << endl;
        if(value0 == 1)
            encryption_function(mono_text,array_alphavit,array_alphavit2,int_alphavit,encoded_text);
        else if(value0 == 2)
            deciphering_function(int_alphavit,encoded_text,array_alphavit2,array_alphavit,mono_text);

        cout << endl;
    }

    delete [] mono_text;
    cout << endl;
    return 0;
}


