#include"man.h"
#include <fstream>
#include <iostream>
int main()
{ std::fstream file;
  std::fstream k_file;
 file.open("text.txt",std::ios::in);
  k_file.open("text.txt",std::ios::app);
 char line[256];
 int choice=0;
int a;char b[256];char c[256];
Student first;
Book person_first;
int x=0;

int mode=0;
cout<<"选择模式：1.admin 2.guest"<<endl;
cin>>mode;
if(mode==1){
  x=1;
while(x){

    cout<<"1.借阅书籍 2.删除借阅信息 3.查看借阅数据 4.退出"<<endl;

    cin>>choice;

    switch(choice){
case 1:{
cout<<"无权限";
break;}
case 2:{
cout<<"添加数据";
cout<<"姓名";
cin>>b;
cout<<"学号";
cin>>c;
first.Create(c,b);
break;

}
case 3:{
  int q_choice;
  cout<<"1.查看借阅书籍的人 2.输入姓名查看具体借阅信息"<<endl;
  cin>>q_choice;
  switch(q_choice){
case 1:{first.Display();
break;}
case 2:{
char s[256]="0";
cout<<"输入姓名";
cin>>s;
int op=0;
while(file.getline(line,256)){
if(op==0){
  if(strstr(line,s)){
op=1;
  }
}
else if(op==1){

cout<<line<<endl;
if(strstr(line,"---")){
  op=3;
}
}
else if(op==3){
  break;
}

}break;
}
 
  break;
}
 break;
}

case 4:{
  x=0;
  break;
}
default:
{
  cout<<"重新输入";
  break;
}
}

    }
  }
    else if(mode==2){
    
      x=1;
      cout<<"输入信息："<<endl<<"姓名：";
      cin>>b;
      cout<<"学号：";
      cin>>c;
      Student person(c,b);
    k_file<<b<<" "<<c<< std::endl;
while(x){  cout<<"1.添加借阅信息 2.删除借阅信息 3.查看借阅信息 4.退出"<<endl;
      int person_choice=0;
      cin>>person_choice;
  switch(person_choice){
case 1:{cout<<"借阅数量：";
  cin>>a;
  cout<<"书籍名称：";
  cin>>c;
  cout<<"ISBN：";
  cin>>b;
  person_first.create(a,b,c);
   k_file<<a<<" "<<c<<" "<<b<<std::endl;
break;}
case 2:
{cout<<"无权限";
break;


}
case 3:
{person_first.display();
break;}
case 4:
{x=0;
   k_file<<"---";
  break;}



  }
}

    }
  
  Book *p_sign=person_first.b_head;
  while(p_sign!=NULL){
Book *ac=p_sign;
p_sign = p_sign ->b_next;
delete(ac);


  }
    Student *sign=first.head;
while(sign!=NULL)
{ Student *ak =sign;
  sign = sign -> next;
  delete(ak);
}
file.close();
k_file.close();
    return 0;
}