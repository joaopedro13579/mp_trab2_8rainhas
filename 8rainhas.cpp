#include <iostream>
using namespace std;
#include <string> 
void criador_de_texto(string x){
    
}
string arrayToString(int arr[2]) 
{
    string str1 = to_string(arr[0]);
    string str2 = to_string(arr[1]);
    string result = str1 + "," + str2;
    return result;
}
void printer(int j,int i,int rainha_2[2]){
    string x;
    string j1=to_string(j);
    string i1=to_string(i);
    if (rainha_2[0]==16)
    {
        
    }else
    {   
        x=i1+j1;
        x=x+" "+arrayToString(rainha_2);
       criador_de_texto(x); 
    }
}
int Oeste(int board[8][8], int linhas ,int colunas)
{
    int arr[2];
    for (;linhas<8;linhas++)
    {
        if (board[linhas][colunas]==1)
        {
            arr[0]=linhas;
            arr[1]=colunas;
            return (arr[2]);
        }
    }
    arr[0]=16;
    arr[1]=16;
    return(arr[2]);
}
int Leste(int board[8][8], int linhas ,int colunas)
{
    int arr[2];
    for (;linhas>=0;linhas--)
    {
        if (board[linhas][colunas]==1)
        {
            arr[0]=linhas;
            arr[1]=colunas;
            return (arr[2]);
        }
    }
    arr[0]=16;
    arr[1]=16;
    return(arr[2]);
}
int Norte(int board[8][8], int linhas ,int colunas)
{
    int arr[2];
    for (;colunas>=0;colunas--){
        if (board[linhas][colunas]==1)
        {
            arr[0]=linhas;
            arr[1]=colunas;
            return (arr[2]);
        }
    }
    arr[0]=16;
    arr[1]=16;
    return(arr[2]);
}
int Sul(int board[8][8], int linhas ,int colunas)
{
    int arr[2];
    for (;colunas<8;colunas++){
        if (board[linhas][colunas]==1)
        {
            arr[0]=linhas;
            arr[1]=colunas;
            return (arr[2]);
        }
    }
    arr[0]=16;
    arr[1]=16;
    return(arr[2]);
}
int Norte_Leste(int board[8][8], int linhas ,int colunas)
{
    int arr[2];
    for (;linhas>0;linhas--)
    {
        colunas=colunas-1;
        if (board[linhas][colunas]==1)
        {
            arr[0]=linhas;
            arr[1]=colunas;
            return (arr[2]);
        }
    }
    arr[0]=16;
    arr[1]=16;
    return(arr[2]);
}
int Norte_Oeste(int board[8][8], int linhas ,int colunas)
{
    int arr[2];    
    for (;linhas<8;linhas++)
    {
        colunas=colunas-1;
        if (board[linhas][colunas]==1)
        {
            arr[0]=linhas;
            arr[1]=colunas;
            return (arr[2]);
        }                        
    }
    arr[0]=16;
    arr[1]=16;
    return(arr[2]);
}
int Sul_Oeste(int board[8][8], int linhas ,int colunas)
{
    int arr[2];
    for (;linhas<7;linhas++)
    {
        colunas=colunas+1;
        if (board[linhas][colunas]==1)
        {
            arr[0]=linhas;
            arr[1]=colunas;
            return (arr[2]);
        }          
    }
    arr[0]=16;
    arr[1]=16;
    return(arr[2]);
}
int Sul_Leste(int board[8][8], int linhas ,int colunas)
{
    int arr[2];
    for (;linhas>=0;linhas--)
    {
        colunas=colunas+1;
        if (board[linhas][colunas]==1)
        {
            arr[0]=linhas;
            arr[1]=colunas;
            return (arr[2]);
        }       
    }
    arr[0]=16;
    arr[1]=16;
    return(arr[2]);
}

int main()
{
    int n=0;
    int board[8][8];
    int arr[2];
    //criador da matriz
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            // board[i][j]=n;
            // n=n+1;
            if(j==i)
            {
                board[j][i]=1;
            }else
            {
                board[j][i]=0;
            }
        }
    }
    //     for (int i=0;i<8;i++)
    // {
    //     for (int j=0;j<8;j++)
    //     {
    //         cout<<board[j][i]<<" ";
            
    //     }
    //     cout<<endl;
    // }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                arr[2]=Leste(board,j-1,i);
                printer(i,j,arr);
                arr[2]=Oeste(board,j+1,i);
                printer(i,j,arr);
            }
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                arr[2]=Norte(board,j,i-1);
                printer(i,j,arr);
                arr[2]=Sul(board,j,i+1);
                printer(i,j,arr);
            }
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                arr[2]=Norte_Leste(board,j,i);
                printer(i,j,arr);
                arr[2]=Sul_Leste(board,j,i);
                printer(i,j,arr);
            }
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                arr[2]=Norte_Oeste(board,j,i);
                printer(i,j,arr);
                arr[2]=Sul_Oeste(board,j,i);
                printer(i,j,arr);
            }
        }
    }
    
    
    return 0;
}
// 1 0 0 0 0 0 0 0 
// 0 1 0 0 0 0 0 0
// 0 0 1 0 0 0 0 0
// 0 0 0 1 0 0 0 0
// 0 0 0 0 1 0 0 0
// 0 0 0 0 0 1 0 0
// 0 0 0 0 0 0 1 0
// 0 0 0 0 0 0 0 1
