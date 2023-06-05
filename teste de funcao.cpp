// teste de funcao
#include <iostream>
using namespace std;
#include <string> 
int Norte_Leste(int board[8][8], int linhas ,int colunas)
{
    for (;linhas>=0;linhas--)
    {
        colunas=colunas+1;
        // if (board[linhas][colunas]==1)
        // {
            cout<<board[linhas][colunas]<<" ";
                // return (1);
        // }
        //     cout<<0;
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
            board[i][j]=n;
            n=n+1;
            // if(j==i)
            // {
            //     board[j][i]=1;
            // }else
            // {
            //     board[j][i]=0;
            // }
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
            Norte_Leste(board,j,i+1);
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