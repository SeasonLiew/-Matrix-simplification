//
//  main.c
//  转置行列式
//
//  Created by Season Liew on 28/07/2018.
//  Copyright © 2018 Season Liew. All rights reserved.
//
#define SIZE 6
#include <stdio.h>
void Print_matrix(int n, float arr[n][n]);
void reverse(int n,float arr[n][n]);
void input(int n,float arr[n][n]);
void row_xplus(int a,float num,int b,int m,int n,float arr[m][n]);
void row_plus(int a,int b,int m,int n,float arr[m][n]);
void row_x(int num,int a,int m,int n,float arr[m][n]);
void row_swap(int a,int b,int m,int n,float arr[m][n]);
void row_simp(int m,int n,float arr[m][n]);
int row_0_LR(int a,int m,int n,float arr[m][n]);
int row_0_L(int a,int m,int n,float arr[m][n]);
void row_0_sort(int m,int n,float arr[m][n]);
void col_elemination(int i,int pos,int m,int n,float arr[m][n]);
float determinant(int m,float arr[m][m]);
typedef struct div{
    int m;
    int n;
}div;

int main(int argc, const char * argv[]) {
   // float arr[][SIZE]={{1,5,-1,-1},{1,-2,1,3},{3,8,-1,1},{1,-9,3,7}};
    float arr[][SIZE]={{2,-1,-1,2,3,6},
                       {1,1,-2,6,1,8},
                       {4,-6,1,2,1,1},
                       {3,6,-9,1,5,1},
                        {1,4,3,2,4,3},
                        {2,4,1,2,6,3}
    };
    //float arr[SIZE][SIZE]={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
  
     Print_matrix(SIZE, arr);
    //col_elemination(0, 0, SIZE, SIZE, arr);
    row_simp(SIZE, SIZE, arr);
    printf("the determinant of this matrix is %0.2f\n",determinant(SIZE, arr));
}
void Print_Div(div a){
    printf("%d/%d",a.m,a.n);
}
void row_simp(int m,int n,float arr[m][n]){
    int x=0;int y=0;
    for(int i=0;y<n;i++){
    row_0_sort(m, n, arr);
    col_elemination(x, y, m, n, arr);
        row_0_sort(m, n, arr);
        Print_matrix(SIZE, arr);
        if (row_0_L(y+1, m, n, arr)-1!=n)
            y++;
        else
            return ;
    x=row_0_L(y, m, n, arr);
    }
}
void Print_matrix(int n, float arr[n][n]){
    printf("***************\n");
    for(int i=0;i<=n-1;i++){
        printf("|");
        for(int j=0;j<=n-1;j++){
            if(arr[i][j]==0)
                printf("%3c ",'0');
            else printf("%2.2f ",arr[i][j]); 
        }
        printf("\n");
}
    printf("***************\n");
}


void row_x(int num,int a,int m,int n,float arr[m][n]){ //第m行不变是const a行乘一个数num
    for(int i=0;i<=n-1;i++){
        arr[a][i]=arr[a][i]*num;
    }
    
}
void row_plus(int a,int b,int m,int n,float arr[m][n]){ //a加到b行，m行不变，是constant。 n是列大小
    for(int i=0;i<=n-1;i++){
        arr[b][i]=arr[b][i]+arr[a][i];
    }
}
void row_xplus(int a,float num,int b,int m,int n,float arr[m][n]){ //a行乘一个数加到b行，m行不变，是constant。 n是列大小
    for(int i=0;i<=n-1;i++){
        arr[b][i]=arr[b][i]+arr[a][i]*num;
    }
}
void row_swap(int a,int b,int m,int n,float arr[m][n]){  //交换行
    float temp;
    for(int i=0;i<=n-1;i++){
        temp=arr[a][i];
        arr[a][i]=arr[b][i];
        arr[b][i]=temp;
    }
}
void reverse(int n,float arr[n][n]){
    int temp; int count=0;
    for(int i=0;i<=n-1;i++){
        for(int j=count;j<=n-1;j++){
            temp=arr[j][i];
            arr[j][i]=arr[i][j];
            arr[i][j]=temp;
        }
        count++;
    }
}
int row_0_LR(int a,int m,int n,float arr[m][n]){//a行从两边数0的数目
    int count1=0,count2=0;
    for(int i=0;i<=n-1&&arr[a][i]==0;i++)
            count1++;
    for(int j=n-1;j>=0&&arr[a][j]==0;j++)
        count2++;
    return count1+count2;
}
int row_0_L(int a,int m,int n,float arr[m][n]){//a行从左边数0的数目
    int count1=0;
    for(int i=0;i<=n-1;i++)
        if(arr[a][i]==0)
        count1++;

    return count1;
}
void row_0_sort(int m,int n,float arr[m][n]){
    for(int j=0;j<m-1;j++)
        for(int i=0;i<=m-2-j;i++)
            if(row_0_LR(i, m, n, arr)>row_0_LR(i+1, m, n, arr))
            {
                row_swap(i, i+1, m, n, arr);
            }
}
void col_elemination(int i,int pos,int m,int n,float arr[m][n]){ //第i列 以行pos行为参照消0,要保证pos位置的数不为0；
    int p=0;
    if(arr[pos][i]==0){
        printf("ERROR!DIV0\n");
        return;
    }
    p=pos+1;
    for(;p<=m-1;p++){
        //小loop走y
        float ratio=-arr[p][i]/arr[pos][i];
        
        row_xplus(i, ratio, p, m, n, arr); //注意float 传参不要在被调用函数用int 接收否则ratio 将会成为0！
        Print_matrix(SIZE, arr);
    }
    
}
float determinant(int m,float arr[m][m]){
    int temp=arr[0][0];
    for(int i=1;i<m;i++)
        temp=temp*arr[i][i];
    return temp;
}
