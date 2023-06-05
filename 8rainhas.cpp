#include <iostream>
using namespace std;
#include <string> 
int Oeste(int board[8][8], int linhas ,int colunas)
{
    for (;linhas<8;linhas++){
        if (board[linhas][colunas]==1)
        {
            cout<<board[linhas][colunas];
            // return (board[linhas][colunas]);
        }
        cout<<0;
        // return(0);
    }
}
int Leste(int board[8][8], int linhas ,int colunas)
{
    for (;linhas>=0;linhas--){
        if (board[linhas][colunas]==1)
        {
            cout<<board[linhas][colunas];
            // return (1);
        }
        cout<<1;
        return(0);
    }
}
int Norte(int board[8][8], int linhas ,int colunas)
{
    for (;colunas>=0;colunas--){
        if (board[linhas][colunas]==1)
        {
            cout<<board[linhas][colunas];
            // return (1);
        }
        cout<<1;
        // return(0);
    }
}
int Sul(int board[8][8], int linhas ,int colunas)
{
    for (;colunas<8;colunas++){
        if (board[linhas][colunas]==1)
        {
            cout<<board[linhas][colunas];
            // return (1);
        }
        cout<<0;
        // return(0);
    }
}
int Norte_Leste(int board[8][8], int linhas ,int colunas)
{
    for (;linhas>0;linhas--)
    {
        colunas=colunas-1;
        if (board[linhas][colunas]==1)
        {
            cout<<board[linhas][colunas]<<" ";
            return (board[linhas][colunas]);
        }
            cout<<0;
            return(0);            
    }
}
int Norte_Oeste(int board[8][8], int linhas ,int colunas)
{
    for (;linhas<8;linhas++){
        if (board[linhas][colunas]==1)
        {
            cout<<board[linhas][colunas];
            // return (1);
        }
        cout<<0;
        // return(0);
    }
}
int Sul_Oeste(int board[8][8], int linhas ,int colunas)
{
    for (;linhas<7;linhas++)
    {
        colunas=colunas+1;
        if (board[linhas][colunas]==1)
        {
            cout<<board[linhas][colunas]<<" ";
            return (board[linhas][colunas]);
        }
            cout<<0;
            return(0);            
    }
}
int Sul_Leste(int board[8][8], int linhas ,int colunas)
{
    for (;linhas>=0;linhas--)
    {
        colunas=colunas+1;
        if (board[linhas][colunas]==1)
        {
            cout<<board[linhas][colunas]<<" ";
            return (board[linhas][colunas]);
        }
            cout<<0;
            return(0);            
    }
}

int main()
{
    int n=0;
    int board[8][8];
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
        for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            cout<<board[j][i]<<" ";
            
        }
        cout<<endl;
    }
            for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                Leste(board,j-1,i);
                Oeste(board,j+1,i);
                cout<<"||"<<endl;
            }
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                Norte(board,j,i-1);
                Sul(board,j,i+1);
                cout<<"||"<<endl;
            }
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                Norte_Leste(board,j,i-1);
                Sul_Leste(board,j,i+1);
                cout<<"||"<<endl;
            }
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                Norte_Oeste(board,j,i-1);
                Sul_Oeste(board,j,i+1);
                cout<<"||"<<endl;
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
/*x0000000||
  1x000000||
  11x00000||
  111x0000||
  1111x000||
  11111x00||
  111111x0||
  1111111x||*/