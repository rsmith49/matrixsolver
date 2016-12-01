#include <stdio.h>
#include <math.h>

#define MAXROW 10
#define MAXCOL 11



void rowSwap (float a[][MAXCOL], int row1, int row2, int nrows);

void rowScale (float a[][MAXCOL], int row, double scale, int nrows);

void rowReduce (float a[][MAXCOL], int row1, int row2, int col, int nrows);

void rowElim (float a[][MAXCOL], int rowStart, int colStart, int nrows);

void getReducedEch (float a[][MAXCOL], int nrows);

int getRow0 (float a[][MAXCOL], int row, int nrows);

int getCol0 (float a[][MAXCOL], int col, int nrows);

int isPivot (float a[][MAXCOL], int row, int col);



int main()   {
int row,i,j,n,k;
float m[MAXROW][MAXCOL];
float d;


   for (i=0;i<10;i++)   {                   /* set entire array to value */
      for (j=0;j<11;j++)   {
         m[i][j] = 0;
      }
   }


   do {
      printf ("Enter the number of rows: ");  /* find # of rows */
      scanf ("%d",&row);
      if ((row<=0)||(row>MAXROW))  {          /* variable guard */
         printf ("Invalid number of rows\n");
      }
   } while ((row<=0)||(row>MAXROW));


   printf ("Enter your matrix:\n");       /* scan in matrix */
   for (i=0;i<row;i++)   {
      for (j=0;j<=row;j++)   {
         scanf("%f",&m[i][j]);
      }
   }

   getReducedEch(m,row);
/*   for (i=0;i<row;i++)   {
      for (j=0;j<=row;j++)   {
         printf ("%5.2f ",m[i][j]);
      }
      printf ("\n");
   }
   j = 0;
   for (i=0;i<row;i++)   {
      printf ("x%d = ",i);
      if (isPivot(m,i,j)&&(getRow0(m,i)==(row-1)))   {
         printf ("%5.2f\n",i+1,m[i][row]);
         j++;
      }
      else   {
         while (j==0)   {
            j++;
         }
         if (j>=row)   {
            
         }
         if  (isPivot(m,i,j))   {
            k = 0;
            for (n=j+1;n<row;n++)   {
               if (m[i][n]!=0)   {
                  if (m[i][n]<0)   {
                     d = (-1*m[i][j]);
                     if (k==0)   {
                        printf ("%5.2f ",d);
                        k++;
                     }
                     else   {
                        printf ("+ %5.2f ",d);
                     }
                  }
                  else   {
                     printf ("- %5.2f ",d);
                  }
               }
            }
            if (m[i][row]<0)   {
               d = (-1*m[i][row]);
               printf ("- %5.2f\n",d);
            }
            else   {
               printf ("+ %5.2f\n",m[i][row]);
            }
         }
         else   {
            printf ("x%d\n",i);
         }
         j++;
      }
   } */

   for (i=0;i<row;i++)   {
      for (j=0;j<row;j++)   {
         if (m[i][j]!=0)   {
            k++;
         }
      }
      if ((k==0)&&(!((m[i][j]+.001>0)&&(m[i][j]-.001<0))))   {
         printf ("Inconsistent System\n");
         return 0;
      }
      k = 0;
   }

   i = 0;
   for (j=0;j<row;j++)   {
      printf ("x%d = ",j+1);
      if ((m[i][j]+.001>0)&&(m[i][j]-.001<0))   {
         printf ("x%d\n",j+1);
      }
      else   {
         k = 0;
         for (n=j+1;n<row;n++)   {
            if (!((m[i][n]+.001>0)&&(m[i][n]-.001<0)))   {
               if (m[i][n]<0)   {
                  d = (-1.0*m[i][n]);
                  if (k==0)   {
                     printf ("%5.2fx%d ",d,n+1);
                  }
                  else   {
                     printf ("+ %5.2fx%d ",d,n+1);
                  }
               }
               else   {
                  d = (-1.0*m[i][n]);
                  if (k==0)   {
                     printf ("%5.2fx%d ",d,n+1);
                  }
                  else   {
                     printf ("- %5.2fx%d ",m[i][n],n+1);
                  }
               }
               k++;
            }
         }
         if (!((m[i][row]+.001>0)&&(m[i][row]-.001<0)))   {
            if (k==0)   {
               printf ("%5.2f",m[i][row]);
            }
            else   {
               if (m[i][row]<0)   {
                  d = (-1.0*m[i][row]);
                  printf ("- %5.2f",d);
               }
               else   {
                  printf ("+ %5.2f",m[i][row]);
               }
            }
         }
      printf ("\n");
      i++;
      }
   }


   return 0;
}


int isPivot(float a[][MAXCOL],int row, int col)   {
int i,d;
   d = 0;
   for (i=0;i<col-1;i++)   {
      if (a[row][i]==0)   {
         d++;
      }
   }
   return ((!d)&&a[row][col]);
}


void rowSwap (float a[][MAXCOL], int row1, int row2, int nrows)   {
int j;
float b[MAXCOL];

   for (j=0;j<=nrows;j++)   {
      b[j] = a[row2][j];
      a[row2][j] = a[row1][j];
      a[row1][j] = b[j];
   }
   return;
}



void rowScale (float a[][MAXCOL], int row, double scale, int nrows)   {
int i;

   for (i=0;i<=nrows;i++)   {
      a[row][i] = a[row][i]*scale;
   }
   return;
}



void rowReduce (float a[][MAXCOL], int row1, int row2, int col, int nrows)   {
int i;
double m;
   if ((a[row1][col]==0)||(col==nrows+1))   {
      printf ("WRONG\n");
      return;
   }
   if (row1==row2)   {
      return;
   }
   m = (a[row2][col]/a[row1][col]);
   for (i=0;i<=nrows;i++)   {
      a[row2][i] = (a[row2][i] - m*a[row1][i]);
   }
   return;
}



void rowElim (float a[][MAXCOL], int row, int col, int nrows)   {
int i;

   for (i=0;i<nrows;i++)   {
      rowReduce(a,row,i,col,nrows);
   }
   return;
}



void getReducedEch (float a[][MAXCOL], int nrows)   {
int i,j,d;
double m;
   i=0;
   j=0;

   while ((i<nrows)&&(j<nrows))   {
      while ((a[i][j]!=0)&&(i<nrows))   {
         rowElim(a,i,j,nrows);
         i++;
         j++;
      }
      if (a[i][j]==0)   {
         d = i;
         while ((a[i][j]==0)&&(i<nrows))   {
            i++;
         }
         if (i==nrows)   {
            j++;
         }
         else   {
            rowSwap(a,i,d,nrows);
         }
         i = d;
      }
   }
   j=0;
   for (i=0;i<nrows;i++)   {
      if (a[i][j]!=0)   {
         m = 1.0/a[i][j];
         rowScale(a,i,m,nrows);
         j++;
      }
   }

   return;
}



int getRow0 (float a[][MAXCOL], int row, int nrows)   {
int i,d;

   d = 0;
   for (i=0;i<nrows;i++)   {
      if (a[row][i]==0)   {
         d++;
      }
   }

   return d;
}

int getCol0 (float a[][MAXCOL], int col, int nrows)   {
int i,d;

   d = 0;
   for (i=0;i<nrows;i++)   {
      if (a[i][col]==0)   {
         d++;
      }
   }

   return d;
}
