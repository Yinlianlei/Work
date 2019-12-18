#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int Load(int ,int ,int [][]);
int TransMatrix(int ,int ,int [][],int [][]);
int MatrixMutiply(int ,int ,int [][],int [][],int [][]);
int OutputMatrix(int ,int ,int [][],int [][],int [][]);
int main(void)
{
    int X,Y;
    printf("********************\nInput(X-Y):");
    scanf("%d-%d",&X,&Y);
    int Matrix[X][Y],Matrix1[X][Y],Sum[X][Y];
    Load(X,Y,Matrix);
    TransMatrix(X,Y,Matrix,Matrix1);
    MatrixMutiply(X,Y,Matrix,Matrix1,Sum);
    OutputMatrix(X,Y,Matrix,Matrix1,Sum);
    return 0;
}

int Load(int X,int Y,int Martix[X][Y])
{
    FILE *A;
    int B,C;
    if((A=fopen("test.txt","r"))==NULL)
    {
        printf("Can't open the File");
        exit(1);
    }
    for(B=0;B<X;B++)
    {
        for(C=0;C<Y;C++)
        {
            fscanf(A,"%d ",&Martix[B][C]);
        }
    }
    /*for(B=0;B<X;B++)
    {
        for(C=0;C<Y;C++)
        {
            printf("%d\t",Martix[B][C]);
        }
        printf("\n");
    }*/

}

int TransMatrix(int X,int Y,int Matrix[X][Y],int Matrix1[X][Y])
{
    int A,B;
    for(A=0;A<X;A++)
    {
        for(B=0;B<Y;B++)
        {
            Matrix1[B][A]=Matrix[A][B];
        }
    }
    /*for(A=0;A<X;A++)
    {
        for(B=0;B<Y;B++)
        {
            printf("%d\t",Matrix1[A][B]);
        }
        printf("\n");
    }*/
}

int MatrixMutiply(int X,int Y,int Matrix[X][Y],int Matrix1[X][Y],int Sum[X][Y])
{
    int A,B,C,D;
    for(A=0;A<X;A++)
    {
        for(B=0;B<Y;B++)
        {
            Sum[A][B]=0;
            for(C=0,D=0;C<Y && D<X;C++,D++)
            {
                Sum[A][B]+=Matrix[A][D]*Matrix1[C][B];
            }
        }
    }
    /*for(A=0;A<X;A++)
    {
        for(B=0;B<Y;B++)
        {
            printf("%d\t",Sum[A][B]);
        }
        printf("\n");
    }*/
}

int OutputMatrix(int X,int Y,int Matrix[X][Y],int Matrix1[X][Y],int Sum[X][Y])
{
    FILE *C;
    int A,B;
    if((C=fopen("JG.txt","w"))==NULL)
    {
        printf("Can't creat!");
    }
    for(A=0;A<X;A++)
    {
        for(B=0;B<Y;B++)
        {
            printf("%d\t",Sum[A][B]);
        }
        printf("\n");
    }
    for(A=0;A<X;A++)
    {
        for(B=0;B<Y;B++)
        {
            fprintf(C,"%d\t",Sum[A][B]);
        }
        fprintf(C,"\n");
    }
}

