#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

void input();
int isComplete();
void checkRow(int,int);
void checkColumn(int,int);
void check3by3box(int,int);
int solveSUDOKU();
void Fill_1();
void fill_given(int,int,int);
void fill3by3box(int);
void hitandtrial(int,int);
void CNoEinGrid();

int given[9][9]={  {0,0,0,0,0,0,6,8,0},
		   {0,0,0,0,7,3,2,0,9},
		   {3,0,9,0,0,0,0,4,5},

		   {4,9,0,0,0,0,0,0,0},
		   {8,0,3,0,5,0,9,0,2},
		   {0,0,0,0,0,0,0,3,6},

		   {9,6,0,0,0,0,3,0,8},
		   {7,0,0,6,8,0,0,0,0},
		   {0,2,8,0,0,0,0,0,0}
			};

int helpingMatrix[9][9];

int row,column;

void main()
{clrscr();
solveSUDOKU();
input();
getch();
}

void input()
{
int i,j;
for(i=0;i<9;i++)
{
for(j=0;j<9;j++)
{
 printf("%d  ",given[i][j]);
}
printf("\n\n");
}
}

int solveSUDOKU()
{ int grid,startRow,startColumn;
int tempRow,tempColumn,pos;
int i,j,iteration=100;
 while(iteration--)
 {
  if(isComplete())
  return 1;

 for(grid=1;grid<=9;grid++)
  {
    Fill_1();
    if(grid<=3)
    startRow=0;
    if(grid>3&&grid<=6)
    startRow=3;
    else if(grid>6&&grid<=9)
    startRow=6;
    switch(grid%3)
    {
      case 1: startColumn=0;break;
      case 2: startColumn=3;break;
      case 0: startColumn=6;break;
    }

    for(tempRow=startRow;tempRow<startRow+3;tempRow++)
    {
      for(tempColumn=startColumn;tempColumn<startColumn+3;tempColumn++)
      {
	if(given[tempRow][tempColumn]!=0)
	{ switch(tempRow%3)
	   {
	    case 0: pos=tempColumn%3;break;
	    case 1: pos=(tempColumn%3)+3;break;
	    case 2: pos=(tempColumn%3)+6;break;
	   }
	   for(i=0;i<9;i++)
	   helpingMatrix[pos][i]=0;

	}

	if(given[tempRow][tempColumn]==0)
	{
	    checkRow(tempRow,tempColumn);
	    checkColumn(tempRow,tempColumn);
	    check3by3box(tempRow,tempColumn);
	}
      }
    }
    fill3by3box(grid);

}
}
 return 0;

}

int isComplete()
{ int i,j;
for(i=0;i<9;i++)
{for(j=0;j<9;j++)
{if(given[i][j]==0)
return 0;}}
return 1;

}



void checkRow(int tempRow,int tempColumn)
{
  int i,j,pos;
  switch(tempRow%3)
  {
   case 0: pos=tempColumn%3;break;
   case 1: pos=(tempColumn%3)+3;break;
   case 2: pos=(tempColumn%3)+6;break;
  }
  for(j=0;j<9;j++)
  if(given[tempRow][j]!=0)
  {
     helpingMatrix[pos][given[tempRow][j]-1]=0;
  }
}

void checkColumn(int tempRow,int tempColumn)
{
  int j,pos;
  switch(tempRow%3)
  {
   case 0: pos=tempColumn%3;break;
   case 1: pos=(tempColumn%3)+3;break;
   case 2: pos=(tempColumn%3)+6;break;
  }
  for(j=0;j<9;j++)
  if(given[j][tempColumn]!=0)
  {
     helpingMatrix[pos][given[j][tempColumn]-1]=0;
  }
}

void check3by3box(int tempRow,int tempColumn)
{
int i,j,pos;
switch(tempRow%3)
  {
   case 0: pos=tempColumn%3;break;
   case 1: pos=(tempColumn%3)+3;break;
   case 2: pos=(tempColumn%3)+6;break;
  }

for(i=(tempRow-tempRow%3);i<(tempRow-tempRow%3)+3;i++)
{for(j=(tempColumn-tempColumn%3);j<(tempColumn-tempColumn%3)+3;j++)
{if(given[i][j]!=0)
helpingMatrix[pos][given[i][j]-1]=0; }}
}

void Fill_1()
{
int i,j;
for(i=0;i<9;i++)
for(j=0;j<9;j++)
helpingMatrix[i][j]=1;
}

void fill3by3box(int grid)
{
  int counter1,counter2,number,pos,number1,pos1;
  int i,j,k,p,q,r;

  for(i=0;i<9;i++)
  { counter1=0;
   for(j=0;j<9;j++)
   {
     if(helpingMatrix[i][j]==1)
     {counter1++;
     pos=i;
     number=j+1;}
   }
   if(counter1==1)
   {
    fill_given(pos,grid,number);
  // for(k=0;k<9;k++)
   // helpingMatrix[pos][k]=0;

   }
  }


   for(q=0;q<9;q++)
  { counter2=0;
   for(p=0;p<9;p++)
   {
     if(helpingMatrix[p][q]==1)
     {counter2++;
     pos1=p;
     number1=q+1;}
   }
   if(counter2==1)
   {
    fill_given(pos1,grid,number1);
   // for(r=0;r<9;r++)
    //helpingMatrix[r][number-1]=0;

   }
   }

}

void fill_given(int pos,int grid,int number)
{
int temprow,tempcolumn,temprow1,tempcolumn1;
if(grid%3!=0)
temprow=grid/3;
else
temprow=grid/3-1;
if(grid%3!=0)
tempcolumn=(grid%3)-1;
else
tempcolumn=2;

if((pos+1)%3!=0)
temprow1=(pos+1)/3;
else
temprow1=(pos+1)/3-1;
if((pos+1)%3!=0)
tempcolumn1=((pos+1)%3)-1;
else
tempcolumn1=2;

row=3*temprow+temprow1;
column=3*tempcolumn+tempcolumn1;

given[row][column]=number;


}


