#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
struct list
{
int row,column;
list *next;
};
void main()
{
clrscr();
int hearts[78],i,heart=3,gun=202,bullet=24,right=40,down=25,b_flag=0,
    s_flag=0,time=50,w_flag=1,khit,inc=10;
char op;
list *p,*start,*now;
for(i=0;i<78;i++)
{
hearts[i]=1;
}
gotoxy(2,1);
for(i=0;i<78;i++)
{
cout<<(char)heart;
}
gotoxy(right,down);
cout<<(char)gun;
start:
if(kbhit()==0)
{
if(b_flag==1)
{
khit=0;
op=(int)13;
}
else
{
op='\0';
}
}
else
{
op=getch();
khit=1;
}
if((op=='a' || op=='A') && right>2)
{
gotoxy(right,down);
cout<<" ";
right--;
gotoxy(right,down);
cout<<(char)gun;
goto start;
}
else
if((op=='s' || op=='S') && right<79)
{
gotoxy(right,down);
cout<<" ";
right++;
gotoxy(right,down);
cout<<(char)gun;
goto start;
}
else
if((int)op==13)
{
w_flag=1;
if(khit==1)
{
b_flag=1;
p=new list;
if(time>5)
{
time-=inc;
}
if(s_flag==0)
{
start=p;
start->next=NULL;
now=p;
s_flag=1;
}
else
{
now->next=p;
now=p;
now->next=NULL;
}
p->row=right;
p->column=24;
}
p=start;
while(p)
{
if(p->column>0)
{
gotoxy(p->row,p->column);
cout<<(char)bullet;
delay(time);
gotoxy(p->row,p->column);
cout<<" ";
p->column--;
}
else
{
hearts[p->row-2]=0;
if(time<45)
{
time+=inc;
}
}
p=p->next;
}
for(i=0;i<78;i++)
{
if(hearts[i]==1)
{
w_flag=0;
break;
}
}
if(w_flag==1)
{
clrscr();
gotoxy(36,12);
cout<<"You Win";
getch();
exit(0);
}
goto start;
}
else
if((int)op==27)
{
exit(0);
}
goto start;
}
