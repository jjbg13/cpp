#include<iostream>
#include<cstring>
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