int max (int x, int y) { return (x > y)? x : y; }
 
int lps(int *str)
{
   int i, j, cl;
   int L[m][m];  
 
   for (i = 0; i < m; i++)
      L[i][i] = 1;

    for (cl=2; cl<=m; cl++)
    {
        for (i=0; i<m-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
 
    return L[0][m-1];
}

