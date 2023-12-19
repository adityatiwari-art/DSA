// array adt implementation using structures
#include <iostream>
using namespace std;
// struct Myarray
// {
//   int tsize; // can be initialize in the same line
//   int usize;
//   int *ptr;
// };
// void create_array(Myarray* a,int s1,int s2)
// {

//   a->tsize = s1;
//   a->usize = s2;
//   a->ptr=new int(a->tsize);
// }
// void get_array(Myarray* a)
// {
// cout<<"enter array elements:";
// for(int i=0;i<a->usize;i++){
//   cin>>*(a->ptr+i);
// }
//   cout<<a->usize<<endl;
//   cout<<a->tsize<<endl;
// }
// void show_array(Myarray* a)
// {
// cout<<" array elements are:";
// for(int i=0;i<a->usize;i++){
//   cout<<*(a->ptr+i)<<endl;
// }
// }
// int main()
// {
//   struct Myarray a1;
//   create_array(&a1,10,4);
//   get_array(&a1);
//   show_array(&a1);

// }

// we used reference because we want changes in place not in the copy of the structure variable
// implementation of the same using classes
class Myarray
{
  int tsize;
  int usize;
  int *bptr;

public:
  Myarray(int s1, int s2)
  {
    bptr = new int[tsize];
    tsize = s1;
    usize = s2;
  }
  void get_array(Myarray *a);
  void show_array(Myarray *a);
  void search_array(int);
  void insertion_array(int pos,int ele);
  void deletion_array(int pos);
};
void Myarray::get_array(Myarray *a)
{
  cout << "enter the array elements: ";
  for (int i = 0; i < (*a).usize; i++)
  {
    cin >> *((a->bptr) + i); // imp step
  }
}
void Myarray::show_array(Myarray *a)
{
  cout << "the array elements are: ";
  for (int i = 0; i < (*a).usize; i++)
  {
    cout << *((a->bptr) + i) << endl; // imp step
  }
}

// operations
// searching element
void Myarray::search_array(int ele)
{
  int count=0;
  for (int i = 0; i < usize; i++)
  {
    if (*(bptr + i) == ele)
    {
      cout << "element found at position " << i + 1 << endl;
      count=1;
    }
  }
    if(count==0)
    {
      cout << "element not found";
    }
}
// insertion at required position 
void Myarray::insertion_array(int pos,int ele){
  for (int i = usize; i >=pos-1; i--)
  {
   *(bptr+(i))=*(bptr+i-1);
  }
  *(bptr+(pos-1))=ele;
  usize+=1;
}
// deletion from specific position
void Myarray::deletion_array(int pos){
  for (int i = pos-1; i <= usize-1; i++)
  {
    *(bptr+i)=*(bptr+i+1);
  }
  usize-=1;
  
}

int main()
{
  Myarray a(10, 7);
  a.get_array(&a);
  a.show_array(&a);
  // a.search_array(4);
  // a.insertion_array(3,4);
  // a.show_array(&a);
  a.deletion_array(5);
  a.show_array(&a);

}