#include<iostream>
using namespace std;

int string_length(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}

void reversal(char name[]){
    int s=0,e=string_length(name)-1;
    while(s<=e){
    swap(name[s++],name[e--]);
    }
}
int main(){
    char name[20];
    cin>>name;
    cout<<name<<endl;
    // name[2]='\0';
    // cout<<name;
    int size;
    size=string_length(name);
    cout<<"length of string is "<<size<<endl;
    reversal(name);
    cout<<"reversed string is "<<name<<endl;
    // int a=3,b=7;
    // swap(a,b);
    // cout<<a<<b;
    // char s[]={'a','b','c'};
    // cout<<s;     gives all characters and then an unexpected character since no null character found
    // int arr[]={1,2,3,45,6,6};
    // cout<<arr;  gives base address 
}