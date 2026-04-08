#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Student{
private :
int year,mouth,day ;
char id[256];
char name_s[256];
public:
Student *next=NULL;
Student *head=NULL;
Student *tail=NULL;
Student(){};
Student (char id_1[256],char name_1[256]){
strcpy(id,id_1);
strcpy(name_s,name_1);
 }
void Create(char id_1[256],char name_1[256]){
    if(head==NULL){
        Student *p= new Student;
        head =p;
        tail =p;
    }else{
Student *p = new Student;
tail -> next = p;
tail = p;}
 strcpy(tail->id,id_1);
strcpy(tail->name_s,name_1);
}
void Display(){
    Student *kt=head;
    while(kt!=NULL){
cout<< kt ->id<<"  "<< kt -> name_s<<endl;
kt = kt -> next;
     }
}
void se(){
    std::fstream file;
    file.open("text.txt",std::ios::in);
    char line[256];
    char *st;
 char *en;
 char b[256];char c[256];
    int lop=0;
int l_len;
  int l_llen;
while(file.getline(line,256)){
  if(lop==1){
if(strstr(line,"---")){
  lop=0;
}
  }
  else if(lop==0){
st=line;
en=strstr(st," ");
l_len=en-st;
char *end=st+strlen(st);
en++;
l_llen=end-en;
strncpy(b,st,l_len);
b[l_len]='\0';
strncpy(c,en,l_llen);
c[l_llen]='\0';
Create(c,b);
    lop=1;
  }
 }
 file.close();
   Display();
  
}void sft(){
      std::fstream file;
    file.open("text.txt",std::ios::in);
    char lline[256];
    char s[256];
cout<<"输入姓名";
cin>>s;
int op=0;
while(file.getline(lline,256)){
if(op==0){
  if(strstr(lline,s)){
op=1;
  }
}
else if(op==1){
 cout<<lline<<endl;
if(strstr(lline,"---")){
  op=3;
}
}
else if(op==3){
  break;
}
}
file.close();
 }
 void xxx(){
   Student *sign=head;
while(sign!=NULL)
{ Student *ak =sign;
  sign = sign -> next;
  delete(ak);
}
head =NULL;
tail =NULL;

 }
};
class Book{
char ISBN[256];
char name[256];
int num;
public:
Book *b_head=NULL;
Book *b_tail=NULL;
Book *b_next=NULL;
Book(){};
void create(int n,char a[],char b[] ){
if(b_head==NULL){
Book *l = new Book;
b_head=l;
b_tail = b_head;
 }else if(b_head!=NULL){
Book *l = new Book;
b_tail -> b_next = l;
b_tail = l;
 }
strcpy(b_tail->ISBN,a);
strcpy(b_tail->name,b);
b_tail->num=n;
 }
 void display(){  Book *ll = b_head;
    while(ll!=NULL){ 
         cout<<"借阅数量:"<<ll -> num<<" "<<"书籍名称:"<<ll ->name <<"ISBN:"<<ll ->ISBN<<endl;
        ll = ll -> b_next;
     }
}
};