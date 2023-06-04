// teste de funcao
#include <iostream>
using namespace std;
#include <string> 
int Sul(int board[8][8], int linhas ,int colunas)
{
    for (;colunas<8;colunas++){
        if (board[linhas][colunas]==1)
        {
            cout<<board[linhas][colunas];
            // return (1);
        }
        cout<<board[linhas][colunas]<<" ";
        // return(0);
    }
}
int main()
{
    int n=1;
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
    cout<<endl;
            for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            Sul(board,j,i+1);
            cout<<"||"<<endl;
            // if (board[j][i]==1){
            //     // Oeste(board,j+1,i);
            //     Leste(board,j-1,i);
            //     cout<<"||"<<endl;
            // }
        }
    }
    
    
    return 0;
}