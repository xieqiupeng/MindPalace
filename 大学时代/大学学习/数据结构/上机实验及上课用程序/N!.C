    int x=100;
    main()
    { int  n=3, y;
      y=fact(n);
      printf("%d",y);

    }

    int fact(n)
    { if(n==1) x=1;
      else  x=n*fact(n-1);
      printf("%d",x);
      return(x);
    }

