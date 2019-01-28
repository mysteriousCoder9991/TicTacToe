#include <stdio.h>
/**
 *  AIM:- TO PLAY BASIC TIC TAC TOE
 *  PROGRAM DEVELOPED BY :- RAHUL DHAR
 *  VERSION :-1.01.26.01.2019(BASIC CODE)
 */
 char s1[51];char s2[51];
 int arr[3][3];

 void getData()
 {
     printf("Enter player's 1 name :- ");
     gets(s1);
     printf("\nEnter player's 2 name :- ");
     gets(s2);
 }

 void setArray()
{
        int i,j;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                arr[i][j]=-1;
}

void display()
{
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                printf("%d\t",arr[i][j]);
            printf("\n");
        }
}

int satCheck()
{
    int i,j,f=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(arr[i][j]==-1)
              {
                f=1;
                break;
               }
    return f;
}

int check(int a)
    {
        int i,j,f1=0,f2=0,c=0,f3=0,f4=0,f5=0,f6=0,f7=0,f8=0;
        for(i=0;i<3;i++)//left diagonal
        {
            if(arr[i][i]!=a)
            {
                f1=1;
                break;
            }
        }
        if(arr[0][2]==a && arr[1][1]==a && arr[2][0]==a)// right diagonal
            f2=1;
        if(arr[0][0]==a && arr [0][1]==a && arr[0][2]== a)//First row
            f3=1;
        if(arr[1][0]==a&& arr[1][1]== a&& arr[1][2]== a)// second row
            f4=1;
        if(arr[2][0]== a && arr[2][1]==a&& arr[2][2]== a)// third row
            f5=1;
        if(arr[0][0]==a && arr[1][0]==a && arr[2][0]==a)// first column
            f6=1;
        if(arr[0][1]==a && arr[1][1] ==a && arr[2][1]==a)// second column
            f7=1;
        if(arr[0][2]==a && arr[1][2]==a && arr[2][2]== a)//third column
            f8=1;
        if(f1==0 ||f2==1||f3==1||f4==1||f5==1||f6==1||f7==1||f8==1)
            return 1;
        else
            return 0;
    }

    int posVer(int x, int y)
    {
        if((x>=0&&x<=2)&&(y>=0&&y<=2))
            return 1;
        else
            return 0;
    }

    int verify(int x ,int y)
    {
        int f1=0;
        if(arr[x][y]==-1)
            f1=1;
        if(f1==1)
            return 1;
        else
            return 0;
    }

    int main()
    {
        int x1,y1,x2,y2;int p=-1,c=0;
        getData();
        setArray();
        display();
        puts("In this game 0=1,1=2 and 2=3");
        do
        {
            printf("\n%s 's Turn",s1);
            puts("\nEnter the position of your '1's");
            do
            {
                do
                {
                    scanf("%d",&x1);
                    scanf("%d",&y1);
                    if(posVer(x1,y1)==1)
                        break;
                }
                while(1);
                if(verify(x1,y1)==1)
                {
                    arr[x1][y1]=1;
                    break;
                }
                else
                    printf("Position already filled ");
            }
            while(1);
            display();
            if(check(1)==1)
            {
                printf(" Winner is ");
                puts(s1);
                p=1;
                break;
            }

             if(satCheck()==00)
                break;

            printf("%s 's Turn",s2);
            puts("\nEnter the position of your '0's");

            do
            {
                do
                {
                    scanf("%d",&x2);
                    scanf("%d",&y2);
                    if(posVer(x2,y2)==1)
                        break;
                }
                while(1);
                if(verify(x2,y2)==1)
                {
                    arr[x2][y2]=0;
                    break;
                }
                else
                    printf("\nPosition already filled  ");
            }
            while(1);
            display();
            if(check(0)==1)
            {
               printf(" Winner is %s",s2);
               p=0;
               break;
            }


        }
        while(1);
        if(p==-1)
            printf("\nMatch draw");
    }
