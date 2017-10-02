

     //HANOI.cpp      

     #include<stdio.h> // scanf¡¢printf
     void move(char getone,char putone)
	 {  printf("%c-->%c\n",getone,putone);	 
	 }
	 void hanoi(int n,char x,char y,char z)
	 {if(n==1)move(x,z);
	   else{hanoi(n-1,x,z,y);
	       move(x,z);
	       hanoi(n-1,y,x,z);	      
	   }
	 }
	void  main()
	 {int m;
	  printf("Input the number of diskes:");
	  scanf("%d",&m);
	  printf("The step to moving %3d diskes:\n",m);
	  hanoi(m,'A','B','C');	
	}
