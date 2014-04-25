#include <iostream>
#include <queue>
using namespace std;
int f()
{
    int n,m;
    char c;

    cin >> n >> m;
    short int tab[n][m];
    queue <int> Q;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin >> c;

            if(c=='1')
                tab[i][j]=1;
            else
                tab[i][j]=0;

            if(tab[i][j]==1)
            {
                Q.push(i);
                Q.push(j);
            }
        }

        while(!Q.empty())
        {
            int i=Q.front(); Q.pop();
            int j=Q.front(); Q.pop();

            if(i!=0 && tab[i-1][j]!=1 && (tab[i-1][j]==0 || tab[i-1][j] > tab[i][j]+1)) // up
                { tab[i-1][j] = tab[i][j]+1; Q.push(i-1); Q.push(j); }

            if(i!=n-1 && tab[i+1][j]!=1 && (tab[i+1][j]==0 || tab[i+1][j] > tab[i][j]+1)) //down
                { tab[i+1][j] = tab[i][j]+1; Q.push(i+1); Q.push(j);}

            if(j!=0 && tab[i][j-1]!=1 && (tab[i][j-1]==0 || tab[i][j-1] > tab[i][j]+1)) //lefr
                { tab[i][j-1] = tab[i][j]+1; Q.push(i); Q.push(j-1);}

            if(j!=m-1 && tab[i][j+1]!=1 && (tab[i][j+1]==0 || tab[i][j+1] > tab[i][j]+1)) //right
                { tab[i][j+1] = tab[i][j]+1; Q.push(i); Q.push(j+1);}

        }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            cout << tab[i][j]-1 << " ";

            cout << endl;

        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--)
        f();
}

