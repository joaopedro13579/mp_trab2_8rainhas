#include <iostream>
using namespace std;
#include <string> 
#include <fstream> 
void writeLineToFile(const string& x, const string& y) 
{
    ofstream file("8_rainhas");
    if (file.is_open()) {
        file << x << " " << y;  // Write the line to the file
        file.close();  // Close the file
    } else {
        cout<<"error";
    }
}
string arrayToString(int arr[2]) 
{
    string str1 = to_string(arr[0]);
    string str2 = to_string(arr[1]);
    string result = str1 + "," + str2;
    return result;
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
    int arr1[9][2];
    int arr2[9][2];
    //criador da matriz
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {

            if(j==i)
            {
                board[j][i]=1;
            }else
            {
                board[j][i]=0;
            }
        }
    }
    //end
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                arr1[0][0],arr1[0][1]=Leste(board,j-1,i);
                arr1[1][0],arr1[0][1]=Oeste(board,j+1,i);
                arr2[0][0],arr2[0][1]=i,j;          
            }
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                arr1[3][0],arr1[3][1]=Norte(board,j,i-1);
                arr1[4][0],arr1[4][1]=Sul(board,j,i+1);
                arr2[1][0],arr2[1][1]=i,j; 
            }
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                arr1[5][0],arr1[5][0]=Norte_Leste(board,j,i);
                arr1[6][0],arr1[6][1]=Sul_Leste(board,j,i);
                arr2[2][0],arr2[0][1]=i,j; 
            }
        }
    }
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if (board[j][i]==1)
            {
                arr1[7][0],arr1[7][1]=Norte_Oeste(board,j,i);
                arr1[8][0],arr1[8][1]=Sul_Oeste(board,j,i);
                arr2[3][0],arr2[0][1]=i,j; 

            }
        }
    }
    for (int i=0;i<8;i++){
        for(int j=0;j<3;j++){
            if (arr1[i][0]!=16)
            {
                string x=to_string(arr2[j][0]);
                string y=to_string(arr2[j][1]);
                string x1=to_string(arr1[i][0]);
                string y1=to_string(arr1[i][1]);
                string escritor=x+","+y+x1+","+y1;
                fstream file("8_rainhas");
                file << escritor<<endl;
            }
        }
    }
    
    return 0;
}
