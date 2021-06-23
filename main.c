\\WRITE A MENU DRIVEN PROGRAM FOR MATRIX FUNCTIONS.

#include <stdio.h>
#include <stdlib.h>

//Input Function
void input(int A[][10], int m, int n)
{
    int i,j;
    printf("Enter elements of first array row-wise : \n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
    {
        scanf("%d",&A[i][j]);
    }
}

//Output Function
void output(int A[][10], int m, int n)
{
    int i, j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
    {
        printf("%d\t",A[i][j]);
    }
    printf("\n");
    }
}

//Sum Function
void sum()
{
    int a[10][10], b[10][10], r, c, tr, tc;
    printf("Enter number of rows of matrix A = ");
    scanf("%d",&r);
    printf("Enter number of columns of matrix A = ");
    scanf("%d",&c);
    printf("Enter number of rows of matrix B = ");
    scanf("%d",&tr);
    printf("Enter number of columns of matrix B = ");
    scanf("%d",&tc);
    if(r != tr || c != tc)
    {
        printf("\n The number of rows r columns are not equal, for addition you should enter in right format.");
        return;
    }
    input(a,r,c);
    input(b,r,c);
    int i,j,sums[10][10];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
    {
        sums[i][j] = a[i][j] + b[i][j];
    }

    printf("sum array : \n");
    output(sums, r, c);
}

//Subtraction function
void diff()
{
    int a[10][10], b[10][10], r, c, tr, tc;
    printf("Enter number of rows of matrix A = ");
    scanf("%d",&r);
    printf("Enter number of columns of matrix A = ");
    scanf("%d",&c);
    printf("Enter number of rows of matrix B = ");
    scanf("%d",&tr);
    printf("Enter number of columns of matrix B = ");
    scanf("%d",&tc);
    if(r != tr || c != tc)
    {
        printf("\n The number of rows r columns are not equal, for subtraction you should enter in right format.");
        return;
    }
    input(a,r,c);
    input(b,r,c);
    int i,j,D[10][10];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
    {
        D[i][j] = a[i][j] - b[i][j];
    }

    printf("Difference array : \n");
    output(D, r, c);
}
//Multiplication function
void mul()
{
    int a[10][10], b[10][10], r, c, tr, tc;
    printf("Enter number of rows of matrix A = ");
    scanf("%d",&r);
    printf("Enter number of columns of matrix A = ");
    scanf("%d",&c);
    printf("Enter number of rows of matrix B = ");
    scanf("%d",&tr);
    printf("Enter number of columns of matrix B = ");
    scanf("%d",&tc);
    if(c != tr)
    {
        printf("The input for multiplication is wrong.");
        return;
    }
    input(a,r,c);
    input(b,tr,tc);
    int i,j,muls[10][10],k;
    for(i=0;i<r;i++)
    {
        for(j=0;j<tc;j++)
        {
            muls[i][j]=0;
        }
    }
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
    {
        for(k=0;k<tc;k++)
            muls[i][j] += a[i][k] * b[k][j];
    }

    printf("multiplication array : \n");
    output(muls, r, c);
}
//Transpose of the matrix
void trans()
{
    int a[10][10], b[10][10], r, c;
    printf("Enter number of rows of matrix = ");
    scanf("%d",&r);
    printf("Enter number of columns of matrix= ");
    scanf("%d",&c);
    input(a,r,c);
    printf("Your entered matrix.\n");
    output(a,r,c);
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            b[j][i]=a[i][j];
        }
    }
    printf("Your transposed matrix.\n");
    output(b,c,r);
}
//Upper triangle and lower triangle value display
void tri_display()
{
    int a[10][10], b[10][10], r, c;
    printf("Enter number of rows of matrix = ");
    scanf("%d",&r);
    printf("Enter number of columns of matrix= ");
    scanf("%d",&c);
    input(a,r,c);
    if(r != c)
    {
        printf("Your entered value is incorrect.\n");
        return;
    }
    printf("Upper Triangle elements: \n");
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i != j && i<j)
                printf("%d\t",a[i][j]);
        }
    }
    printf("\n");
    printf("Lower Triangle elements: \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i != j && i>j)
                printf("%d\t",a[i][j]);
        }
    }
    printf("\n");
}
//main
int main()
{
    int ch,ans;
    system("cls");
    do
    {
        printf("\n--------------MENU--------------");
        printf("\n1. Add the matrices.");
        printf("\n2. Subtract the matrices.");
        printf("\n3. Multiply the matrices.");
        printf("\n4. Transpose the matrices.");
        printf("\n5. Display upper and lower matrices.");
        printf("\nEnter your Choice: ");
        scanf("%d",&ch);
        system("cls");
        switch(ch)
        {
            case 1 : printf("\nAddition of the matrices: \n");
                     sum();
                     break;
            case 2 : printf("Subtraction of the matrices: \n");
                     diff();
                     break;
            case 3 : printf("Multiplication of the matrices: \n");
                     mul();
                     break;
            case 4 : printf("Transpose of the matrices: \n");
                     trans();
                     break;
            case 5 : printf("Displaying Lower and upper triangle matrices: \n");
                     tri_display();
                     break;
            default: return 0;
        }
        printf("To continue enter 1, to exit enter 0.");
        scanf("%d",&ans);
        system("cls");
    }while(ans != 0);

}
