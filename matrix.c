#include <stdio.h>
#include <math.h>

void twovar (double x1, double x2, double x, double y1, double y2, double y);

void twovar (double x1, double x2, double x, double y1, double y2, double y)   {
int z;
double a;
double b;
double c;
double d;
double e;
double f;
double g;
   if ((x2==0)&&(y2==0)&&((x1*1.0/y1)==(x*1.0/y)))   {
      printf ("x1 = %g\nx2 is free\n",x*1.0/x1);
      return;
   }
   if (((x1==0)&&(x2==0)&&(x!=0))||((y1==0)&&(y2==0)&&(y!=0)))   {
      printf ("Not Valid\n");
      return;
   }

z = (2*(x1==0) + (y1==0));
   switch (z)   {
      case 0:   {
      a = (y1*1.0/x1);
      b = (y2-a*x2);
      c = (y-a*x);
         if ((b==0)&&(c==0))   {
            printf ("x1 = %g + (%g)x2\n",x*1.0/x1,x2*(-1.0)/x1);
            return;
         }
         if ((b==0)&&(c!=0))   {
            printf ("Not Valid\n");
            return;
         }
         else   {
         d = (x2*1.0/b);
         e = (x-d*c);
            printf ("x1 = %g\nx2 = %g\n",e*1.0/x1,c*1.0/b);
            return;
         }
      }
      case 1:   {
         if (y2==0)   {
            printf ("x1 = %g + (%g)x2\n",x*1.0/x1,x2*(-1.0)/x1);
            return;
         }
         else   {
         f = (x-(x2*1.0/y2)*y);
            printf ("x1 = %g\nx2 = %g\n",f*1.0/x1,y*1.0/y2);
            return;
         }
      }
      case 2:   {
      g = x1;
      x1 = y1;
      y1 = g;
      g = x2;
      x2 = y2;
      y2 = g;
      g = x;
      x = y;
      y = g;
      a = (y1*1.0/x1);
      b = (y2-a*x2);
      c = (y-a*x);
         if ((b==0)&&(c==0))   {
            printf ("x1 = %g + (%g)x2\n",x*1.0/x1,x2*(-1.0)/x1);
            return;
         }
         if ((b==0)&&(c!=0))   {
            printf ("Not Valid\n");
            return;
         }
         else   {
         d = (x2*1.0/b);
         e = (x-d*c);
            printf ("x1 = %g\nx2 = %g\n",e*1.0/x1,c*1.0/b);
            return;
         }
      }
      case 3:   {
         if ((y2==0)&&(y==0))   {
            printf ("x1 is free\nx2 = %g\n",x*1.0/x2);
            return;
         }
         if ((y2==0)&&(y!=0))   {
            printf ("Not Valid\n");
            return;
         }
         if ((x2*1.0/y2)==(x*1.0/y))   {
            printf ("x1 is free\nx2 = %g\n",x*1.0/x2);
            return;
         }
         if ((x2*1.0/y2)!=(x*1.0/y))   {
            printf ("Not Valid\n");
            return;
         }
      }
   }
}

int main ()   {
double x1,x2,x,y1,y2,y;
double a, b, c;
a = (y1*1.0/x1);
b = (y2-a*x2);
c = (y-a*x);
   do   {
   printf ("Enter your two by two matrix: ");
   scanf ("%lf%lf%lf%lf%lf%lf",&x1,&x2,&x,&y1,&y2,&y);
   twovar (x1,x2,x,y1,y2,y);
   } while ((((x1==0)&&(x2==0)&&(x!=0))||((y1==0)&&(y2==0)&&(y!=0)))||(((x2*1.0
           /y2)!=(x*1.0/y))&&(x1==0)&&(y1==0))||(((y2==0)&&(y!=0))&&(x1==0)&&
           (y1==0))||(((b==0)&&(c!=0))&&(x1==0))||(((b==0)&&(c!=0))&&(y1==0))||
           (((b==0)&&(c!=0))&&((y1-a*x1)==0)));
   return 0;
}
