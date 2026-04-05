#include"man.h"
int main()
{int choice=0;
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
    cout<<"1.借阅书籍 2.个人信息 3.查看借阅数据 4.退出"<<endl;

    cin>>choice;

    switch(choice){
case 1:{
cout<<"借阅的数量：";
cin>>a;
cout<<"借阅书籍的名称:";
cin>>c;
cout<<"ISBN:";
cin>>b;

 person_first.create(a,b,c); 
  person_first.display();
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
first.Display();
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

    }}
    else if(mode==2){
      x=1;
      cout<<"输入信息："<<endl<<"姓名：";
      cin>>b;
      cout<<"学号：";
      cin>>c;
      Student person(c,b);
    
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
break;}
case 2:
{cout<<"无权限";
break;


}
case 3:
{person_first.display();
break;}
case 4:
{x=0;break;}



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
    return 0;
}