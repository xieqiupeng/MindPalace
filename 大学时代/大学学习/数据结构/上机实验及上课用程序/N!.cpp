

    #include "stdio.h" 
    int x=100;
    int fact(int n)
    { if(n==1) x=1;
      else  x=n*fact(n-1);
      printf("%d\n",x);
      return(x);
    }

    
    void main()
    { int  n=3, y;
      y=fact(n);
      printf("%d\n",y);

    }

    

