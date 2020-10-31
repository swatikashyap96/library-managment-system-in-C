  #include<dos.h>
   #include<stdio.h>
     #include<graphics.h>

      #define enter arrow 13
       #define keyup arrow 72
	#define left arrow 75
	 #define right arrow 77
	  #define down arrow 80
	   #define esc arrow 27

	struct issued
    {
       char i_name[20],ib_name[20];
       int ib_code,d,m,y;
    }all;

       struct books
    {
      char b_name[20],b_author[20];
      int b_code;
    }bk;

      struct student
   {
      char s_name[20],f_name[20],c_name[20];
      int s_year;
   }st;a


    void about(void);
      void control(int y, FILE *fs, FILE *fi, FILE *fb);
	void gui(int y);
	  void manage_student(int y);
	    void student(void);
	      void add_student(FILE *fs);
		void delete_student(FILE *fs, FILE *fi);
		  void student_record(FILE *fs, FILE *fi);
		    void book(void);
		      void add_book(FILE *fb);
			void search_book(FILE *fb);
			  void manage_book(int y);
			    void issued_book(FILE *fi, FILE *fs);
			      void return_book(FILE *fi);
				void rule(void);
				  void error();
				    void notfication();
				      void play();
					void play2();
					  void student_modify(FILE *fs,FILE *fi,FILE *fb);

int x=170,xs=310,selector=0;


      int   main()
    {
	 int gd=DETECT,gm,i,y=150;

	 FILE *fb;
	 FILE *fs;
	 FILE *fi;

	initgraph(&gd,&gm,"C:\\Turboc3\\bgi");

	 fs=fopen("studentrecord.dat","ab+");

	if(fs==NULL)
    {
	    printf("student record File not found");
	    getch();
	    main();
    }

	fi=fopen("isubook.dat","ab+");

	if(fi==NULL)
   {
	    printf("book issued File not found");
	    getch();
	    main();
   }
       fb=fopen("libstock.dat","ab+");
       if(fb==NULL)
   {
	    printf("libraby stock File not found");
	    getch();
	    main();
   }
	selector=0;

	gui(y);
	control(y, fs, fi, fb);

	return 0;
   }

//             ***  the controler or selector function  ***

	void control(int y, FILE *fs, FILE *fi, FILE *fb)
   {
	int ch;

	while(1)
   {
	lable1:
	  ch=getch();
	    cleardevice();

	switch(ch)
   {
	case 72:        // up
		y-=70;
	if(y>300)
		{  x=250;  xs=150;  }
	else
		{  x=170;   xs=310;  }
	break;

	case 75:      // left
		y=380;
		x=120;
		xs=100;
	break;

	case 77:      // right
		y=380;
		x=420;
		xs=100;
	break;

	case 80:       // down
		y+=70;

	if(y>300)
		{  x=250;  xs=150;  }
	else
		{  x=170;   xs=310;  }
	break;

	case 'h':
	     main();
	break;

	case 27:      // exit
		exit(0);
	break;
  }

	if(y>360)
		{  y=360;   }
	if(y<150)
		{  y=150;  }

	   if(selector==0)       // main menu
	{
		gui(y);
	 if(ch==13)
	{
	  if(x==170 && y==150)
		 {   cleardevice();   manage_student(y);    }
	 if(x==170 && y==220)
		 {	   cleardevice();   manage_book(y);    }
	 if(x==170 && y==290)
		 {   rule();    }

	 goto lable1;
	}
	}


	if(selector==20)      // student manager
   {
	   manage_student(y);
	if(ch==13)
    {
	if(x==171 && y==150)
		 { 	   cleardevice();   add_student(fs);    }
	if(x==171 && y==220)
		 {	   cleardevice();  student_record(fs, fi); }
	if(x==171 && y==290)
		 {	   cleardevice();  student_modify(fs, fi, fb); }
	if(x==171 && y==360)
		 {	   cleardevice();  delete_student(fs, fi);   }
	goto lable1;
    }
   }


       if(selector==40)   // book
   {
	 manage_book(y);
     if(ch==13)
     {
     if(x==168 && y==150)
	     {	   cleardevice();  add_book(fb);     }

     if(x==168 && y==220)
	     {	   cleardevice();  issued_book(fs, fi);  }
     if(x==168 && y==290)
	     {	   cleardevice();  search_book(fb);  }
     if(x==168 && y==360)
	     {	   cleardevice();  return_book(fi);  }
	goto lable1;
     }
    }

	if(xs==150 && x==250)    // notfication button
    {
	  ch=getch();

	if(ch==13)
  {
	 cleardevice();
	  notfication();
		 goto lable1;
  }
    }


	if(xs==100 && x==120)    // about button
  {
	 ch=getch();
	if(ch==13)
  {
	   cleardevice();
	   about();
  }
  }

	if(xs==100 && x==420)    // exit button
  {
	ch=getch();
      if(ch==13)
    {
       cleardevice();
		error();
     }
  }

 }
 } //               ***   Controller fun over here   ***

   /*        Graphical user interface is start processing here      */
	void gui(int y)
     {
	   rectangle(1,1,getmaxx(),getmaxy());
	     setfillstyle(9,4);
	       floodfill(4,4,WHITE);
		 bar3d(80,120,570,420,5,5);
		   setfillstyle(9,6);
		     floodfill(82,124,WHITE);
		       setfillstyle(1,15);
			 floodfill(85,119,WHITE);
			    floodfill(572,410,WHITE);   // top 3d

	  settextstyle(11,0,3);
	    outtextxy(20,457,"Use Nevagation Key For Up/Down/Right/left");
	      outtextxy(20,427,"Press Q if controller is locked");
		outtextxy(20,442,"Press Enter Button For Selection");
		  settextstyle(1,0,4);
		    outtextxy(190,20,"LIBRARY MANAGER");
		      line(180,60,490,60);

	settextstyle(1,0,2);
	setfillstyle(1,6);

	 bar3d(170,150,480,190,5,5);   // STUDENT
	   floodfill(173,151,WHITE);
	     outtextxy(230,155,"MANAGE STUDENT");

	 bar3d(170,220,480,260,5,5);   // BOOK
	   floodfill(173,221,WHITE);
	    outtextxy(230,225,"MANAGE BOOK's");

	bar3d(170,290,480,330,5,5);   // ISSUED BOOK
	  floodfill(173,291,WHITE);
	    outtextxy(230,295,"RULE's & RELUGATION's");

	bar3d(250,360,400,400,5,5);   // ISSUED BOOK
	  floodfill(333,361,WHITE);
	    outtextxy(260,365,"NOTIFICATION");

	bar3d(120,360,220,400,5,5);   // ABOUT
	  floodfill(123,361,WHITE);
	    outtextxy(145,365,"ABOUT");

	bar3d(420,360,520,400,5,5);   // EXIT
	  floodfill(423,361,WHITE);
	    outtextxy(440,365,"EXIT");

	setfillstyle(1,15);
	  floodfill(173,149,WHITE);
	    floodfill(481,153,WHITE); // 1 button  3d

	  floodfill(173,219,WHITE);
	    floodfill(482,258,WHITE); // 2 button  3d

	  floodfill(173,289,WHITE);
	    floodfill(483,323,WHITE);   // 3 button 3d

	  floodfill(482,358,WHITE);
	    floodfill(521,398,WHITE); // exit top button  3d

	  floodfill(125,359,WHITE);
	    floodfill(221,398,WHITE); // about top button  3d

	  floodfill(253,359,WHITE);
	    floodfill(401,397,WHITE); // 1 button  3d

	  setfillstyle(9,4);
	    rectangle(x,y,xs+x,40+y);
	      floodfill(x+3,y+2,WHITE);         // option

}  //       ***    graphical user interface over here    ****


/*           ***   manage student function start here   ***            */

	void manage_student(int y)
    {
	 selector=20;
	  x=171;

	   rectangle(1,1,getmaxx(),getmaxy());
	     setfillstyle(9,4);
	       floodfill(4,4,WHITE);
		 bar3d(80,120,570,420,5,5);
		   setfillstyle(9,6);
		     floodfill(82,124,WHITE);
		       setfillstyle(1,15);
			 floodfill(85,119,WHITE);
			   floodfill(572,410,WHITE);   // top 3d

	 settextstyle(11,0,3);
	 outtextxy(10,450,"Press H for Main Menu");

	   settextstyle(1,0,4);
	    outtextxy(130,20,"MANAGE STUDENT RECORD");
	     line(115,60,550,60);

	  settextstyle(1,0,2);
	  setfillstyle(1,6);

	    bar3d(171,151,480,190,5,5);   // STUDENT
	      floodfill(173,151,WHITE);
		outtextxy(240,155,"ADD STUDENT");

	    bar3d(171,221,480,260,5,5);   // BOOK
	      floodfill(173,221,WHITE);
		outtextxy(240,225,"SEARCH STUDENT");

	    bar3d(171,291,480,330,5,5);   // ISSUED BOOK
	      floodfill(173,291,WHITE);
		 outtextxy(240,295,"MODIFY STUDENT");

	    bar3d(171,361,480,400,5,5);   // ISSUED BOOK
	      floodfill(173,361,WHITE);
		outtextxy(240,365,"DELETE STUDENT");

		setfillstyle(1,15);

	    floodfill(175,150,WHITE);
	     floodfill(481,153,WHITE); // 1 button  3d
		floodfill(175,220,WHITE);
		 floodfill(482,258,WHITE); // 2 button  3d
		    floodfill(175,290,WHITE);
		     floodfill(483,323,WHITE);   // 3 button 3d
			floodfill(175,360,WHITE);
			 floodfill(483,383,WHITE);   // 3 button 3d

	setfillstyle(9,4);             // option
	   rectangle(x,y,480,y+40);
	      floodfill(x+3,y+3,WHITE);

   } // manage student function over here


   /*        *** Function for Add Student operation start here ***       */

	void add_student(FILE *fs)
   {
	char ch;
	char s[100];
	char name[20];
	int t;

	settextstyle(11,0,3);
	  outtextxy(10,450,"Press H for Main Menu");

	rewind(fs);

	rectangle(1,1,getmaxx(),getmaxy());
	  setfillstyle(9,4);
	    floodfill(4,4,WHITE);
	      bar3d(80,120,570,420,5,5);
		setfillstyle(9,6);
		  floodfill(82,124,WHITE);
		    setfillstyle(1,15);
		      floodfill(85,119,WHITE);
			floodfill(572,410,WHITE);   // top 3d

	settextstyle(1,0,4);
	  outtextxy(225,20,"ADD STUDENT");
	    line(210,60,450,60);


      line(80,350,570,350);
       settextstyle(1,0,1);
	 outtextxy(100,370,"NOTE: Fill The Form According To Student Id Card");

       settextstyle(1,0,1);
	setfillstyle(1,6);

	bar3d(100,150,280,180,3,3);   // STUDENT
	  floodfill(105,151,WHITE);
	    outtextxy(125,155,"Student Name");

	bar3d(100,200,280,230,3,3);   // BOOK
	  floodfill(105,201,WHITE);
	    outtextxy(130,205,"Father Name");

	bar3d(100,250,280,280,3,3);   // ISSUED BOOK
	  floodfill(105,251,WHITE);
	    outtextxy(120,255,"Student Course");

	bar3d(100,300,280,330,3,3);   // ISSUED BOOK
	  floodfill(105,311,WHITE);
	    outtextxy(140,305,"Course Year");

	setfillstyle(1,15);

	floodfill(105,149,WHITE);
	 floodfill(281,173,WHITE); // 1 button  3d
	    floodfill(103,199,WHITE);
	     floodfill(282,228,WHITE); // 2 button  3d
		floodfill(103,249,WHITE);
		 floodfill(281,273,WHITE);   // 3 button 3d
		    floodfill(103,299,WHITE);
		      floodfill(281,323,WHITE);   // 3 button 3d

	settextstyle(1,0,1);
	 setfillstyle(1,0);

	bar3d(320,150,530,180,3,3);   // STUDENT
	  floodfill(325,151,WHITE);

	 play();
	 fflush(stdin);

	gotoxy(43,11);
	  gets(name);

	while(fread(&st,sizeof(st),1,fs)==1)
    {
       if( (strcmp(name,st.s_name)==0))
    {
      setfillstyle(9,BLACK);
	bar3d(180,200,440,300,0,0);
	  outtextxy(210,205,"this name is available in");
	    outtextxy(220,230,"record.");
	      outtextxy(230,255,"try with full name");
    play2();
    fclose(fs);
    getch();
    main();
    }
    }

       strcpy(st.s_name,name);
	 bar3d(320,200,530,230,3,3);   // BOOK
	   floodfill(325,201,WHITE);

     play();
     fflush(stdin);

   gotoxy(43,14);
     gets(st.f_name);

     bar3d(320,250,530,280,3,3);   // ISSUED BOOK
       floodfill(325,251,WHITE);

     play();
     fflush(stdin);

     gotoxy(43,17);
       gets(st.c_name);

     play();

     bar3d(320,300,530,330,3,3);   // ISSUED BOOK
       floodfill(325,311,WHITE);

      gotoxy(43,20);
	scanf("%d",&st.s_year);

     settextstyle(11,0,1);            // creat error box
       setfillstyle(1,0);
	 bar3d(180,150,440,250,0,0);

	 if(strcmp(st.s_name,st.f_name)==0)    	   // check special case
     {
	 circle(310,190,25);
	   circle(303,180,3);
	     circle(320,180,3);
	       ellipse(310,200,0,200,8,5);
		 setfillstyle(1,6);
		   floodfill(312,202,WHITE);
		     outtextxy(205,220,"Student And Father Name Must");
		       outtextxy(240,235,"Be Different");
	  play2();
	  fclose(fs);
	  getch();
	  main();
      }

      outtextxy(205,170,"Press Y/N for Save & Retry");
	outtextxy(190,220,"Y - for Save");
	  outtextxy(320,220,"C - for cancel");

      play2();
      lable:

	     ch=getch();

       if(ch=='y' || ch=='Y')
    {
	  play();
	    fwrite(&st,sizeof(st),1,fs);
	      fclose(fs);
   }
   else if(ch=='c' || ch=='C')
   {
	  play();
	    fclose(fs);
	      main();
   }
   else
   {
	  play2();
	    fclose(fs);
	      printf("enter a valid key");
	  goto lable;
   }
     main();
   }      //  add student over here


/*      ***   function for delete student record is stard here  ***         */

	void delete_student(FILE *fs, FILE *fi)
   {

       int flag=0;
       FILE *fptmp;
       char name[20];
       char s[100];

	 rectangle(1,1,getmaxx(),getmaxy());
	   setfillstyle(9,4);
	     floodfill(4,4,WHITE);
	       bar3d(80,120,570,420,5,5);
		 setfillstyle(9,6);
		   floodfill(82,124,WHITE);
		     setfillstyle(1,15);
		       floodfill(85,119,WHITE);
			 floodfill(572,410,WHITE);   // top 3d

	settextstyle(11,0,3);
	  outtextxy(10,450,"Press H for Main Menu");
	    settextstyle(1,0,4);
	      outtextxy(175,20,"DELETE STUDENT");
		line(165,60,450,60);

	settextstyle(1,0,1);
	  setfillstyle(1,6);

       bar3d(100,200,280,230,3,3);   // BOOK
	 floodfill(105,201,WHITE);
	   outtextxy(130,205,"STUDENT NAME");

	    setfillstyle(1,15);

       floodfill(103,199,WHITE);
	 floodfill(282,228,WHITE); // 2 button  3d

       settextstyle(1,0,1);
	 setfillstyle(1,0);

       bar3d(320,200,530,230,3,3);   // BOOK
	 floodfill(325,201,WHITE);

       line(80,350,570,350);
	outtextxy(100,370,"This Function Is Delete All The Record Of Student.");

       play();

      gotoxy(44,14);
	gets(name);

       fptmp=fopen("tempfile.dat","wb");

	 while(fread(&st,sizeof(st),1,fs)==1)
    {
	 if( (strcmp(name,st.s_name)!=0))
    {
	  fwrite(&st,sizeof(st),1,fptmp);
    }
    else
	  flag=1;
    }
	fclose(fs);
	  fclose(fptmp);
	    remove("studentrecord.dat");
	       rename("tempfile.dat","studentrecord.dat");

     fptmp=fopen("tmp.dat","wb");

      while(fread(&all,sizeof(all),1,fi)==1)    // delete issued record
   {
      if(strcmp(name,all.i_name)!=0)
   {
      fwrite(&st,sizeof(st),1,fptmp);
   }
     else
     flag=1;
   }
     fclose(fi);
       fclose(fptmp);
	 remove("isubook.dat");
	   rename("tmp.dat","isubook.dat");

	 play();

      settextstyle(11,0,1);
	setfillstyle(1,0);
	  bar3d(180,150,440,250,0,0);

	if(flag!=0)
   {
	settextstyle(11,0,1);
	  setfillstyle(1,0);
	    bar3d(180,150,440,250,0,0);
	      outtextxy(205,170,"Student Data Was Deleted");
		outtextxy(215,200,"Successfully");

	 play2();
   }
	 else
   {
       outtextxy(205,180,"Student Data Was not be");
	 outtextxy(215,210," delete");

       play2();
   }

       getch();
       main();

   }   //  deleted student fun over here


/*      ***  Function For Perform Modification In Student Record  ***     */

	  void student_modify(FILE *fs,FILE *fi,FILE *fb)
   {
	rectangle(1,1,getmaxx(),getmaxy());
	  setfillstyle(9,4);
	    floodfill(4,4,WHITE);
	      bar3d(80,120,570,470,5,5);
		setfillstyle(9,0);
		  floodfill(82,124,WHITE);
		    setfillstyle(1,15);
		      floodfill(85,119,WHITE);
			floodfill(572,350,WHITE);   // top 3d

	circle(330,240,90);
	  circle(300,220,10);
	    circle(360,220,10);
	      setfillstyle(1,4);
		floodfill(333,243,WHITE);

	settextstyle(1,0,4);
	  outtextxy(195,20,"Student Record");
	    line(180,60,450,60);

	ellipse(330,280,180,0,30,20);
	  outtextxy(120,360,"Currently Under Process");

       play2();
	 getch();
	   fclose(fs);
	     fclose(fi);
	       fclose(fb);
       main();
   }       // modification fun over here



/*       ***  Function for Display All The Record Of Student  ***    */

	void student_record(FILE *fs, FILE *fi)
    {

	int flag=0,i=0;
	char name[20],name2[20];

	   cleardevice();
	play();

       rectangle(1,1,getmaxx(),getmaxy());
	 setfillstyle(9,4);
	   floodfill(4,4,WHITE);
	     bar3d(80,120,570,470,5,5);
	       setfillstyle(9,0);
		 floodfill(82,124,WHITE);
		   setfillstyle(1,15);
		     floodfill(85,119,WHITE);
		       floodfill(572,350,WHITE);   // top 3d

	settextstyle(11,0,3);
	  outtextxy(10,450,"Press H for Main Menu");
	    settextstyle(1,0,4);
	      outtextxy(195,20,"Student Record");
		line(180,60,450,60);

	settextstyle(1,0,1);
	  setfillstyle(9,4);
	    bar3d(100,150,280,180,3,3);   // STUDENT
	      floodfill(105,151,WHITE);
		outtextxy(125,155,"Student Name");

	setfillstyle(1,0);
	  bar3d(320,150,530,180,3,3);   // STUDENT
	    floodfill(325,151,WHITE);

       fflush(stdin);

       gotoxy(43,11);
	 gets(name);

 //              check the student is available in record or not

       while(fread(&st,sizeof(st),1,fs)==1)
    {
       if(strcmp(name,st.s_name)==0)
    {
	 gotoxy(13,13);
	 printf("STUDENT NAME :-  ");
	     puts(st.s_name);

	 gotoxy(13,15);
	 printf(" Father name :- ");
	     puts(st.f_name);

	 gotoxy(51,13);
	 printf(" course name :- ");
	     puts(st.c_name);

	 gotoxy(51,15);
	      printf(" course year :-  %d",st.s_year);
    flag=1;

     line(90,250,550,250);
       gotoxy(20,18);
	 printf("book name");

       gotoxy(40,18);
	 printf("book code");

       gotoxy(55,18);
	 printf("issued date");

      strcpy(name2,name);

	  while(fread(&all,sizeof(all),1,fi)==1)
    {
	  if(strcmp(name2,all.i_name)==0)
     {
	 i+=2;
	gotoxy(43,11);
	  puts(all.i_name);

	gotoxy(17,18+i);
	  puts(all.ib_name);

	gotoxy(43,18+i);
	  printf("%d ",all.ib_code);

	gotoxy(55,18+i);
	  printf(" %d/%d/%d",all.d,all.m,all.y);
    }
    }
	flag=1;
    }
    }

	 if(flag==0)
     {
       settextstyle(11,0,1);
	 setfillstyle(9,0);
	   bar3d(180,200,440,300,0,0);
	     floodfill(190,255,WHITE);
	       circle(310,240,25);
		 circle(303,230,3);
		   circle(320,230,3);
		     ellipse(310,250,0,200,8,5);
		       setfillstyle(1,6);
			 floodfill(312,242,WHITE);
			   outtextxy(240,280,"Student Not Found");

	 play2();
     }

      fclose(fs);
	fclose(fi);
	  getch();
	    main();
    }  //         student record function is over here



	void manage_book(int y)
  {
	selector=40;
	x=168;

	settextstyle(11,0,3);
     outtextxy(10,450,"Press H for Main Menu");

	  rectangle(1,1,getmaxx(),getmaxy());
	  setfillstyle(9,4);
	  floodfill(4,4,WHITE);

	     settextstyle(1,0,4);
		outtextxy(170,20,"MANAGE BOOK RECORD");
		   line(160,60,540,60);

		bar3d(80,120,570,420,5,5);
		   setfillstyle(9,6);
		      floodfill(82,124,WHITE);
			 setfillstyle(1,15);
			     floodfill(85,119,WHITE);
				floodfill(572,410,WHITE);   // top 3d

	     settextstyle(1,0,1);
	     setfillstyle(1,6);

	bar3d(168,150,480,190,5,5);   // STUDENT
	   floodfill(173,151,WHITE);
	       outtextxy(240,155,"ADD BOOK");

	bar3d(168,220,480,260,5,5);   // BOOK
	   floodfill(173,221,WHITE);
		outtextxy(240,225,"ISSUED BOOK");

	bar3d(168,290,480,330,5,5);   // ISSUED BOOK
	    floodfill(173,291,WHITE);
		outtextxy(240,295,"SEARCH BOOK");

	bar3d(168,360,480,400,5,5);   // ISSUED BOOK
	     floodfill(173,361,WHITE);
		outtextxy(240,365,"RETURN BOOK");


	     setfillstyle(1,15);
	     floodfill(175,150,WHITE);
	     floodfill(481,153,WHITE); // 1 button  3d

	floodfill(175,220,WHITE);
	floodfill(482,258,WHITE); // 2 button  3d

	     floodfill(175,290,WHITE);
	     floodfill(483,323,WHITE);   // 3 button 3d

		setfillstyle(9,4);             // option
		rectangle(168,y,480,y+40);
		floodfill(171,y+3,WHITE);

	getch();
   }



	void add_book(FILE *fb)
   {
	char s[100];
	char ch;
   //	     fseek(fb,0,2);

	 play();


	settextstyle(11,0,3);
     outtextxy(10,450,"Press H for Main Menu");

	    rectangle(1,1,getmaxx(),getmaxy());
	    setfillstyle(9,4);
	    floodfill(4,4,WHITE);


		settextstyle(1,0,4);
		outtextxy(240,20,"ADD BOOK");
		line(230,60,420,60);

		    bar3d(80,120,570,420,5,5);
		    setfillstyle(9,6);
		    floodfill(82,124,WHITE);
		    setfillstyle(1,15);
		    floodfill(85,119,WHITE);
		    floodfill(572,410,WHITE);   // top 3d
		line(80,350,570,350);
 outtextxy(100,370,"NOTE: SIAS LIBRARY MANAGER");

	    settextstyle(1,0,1);
	    setfillstyle(1,6);

		    bar3d(100,150,280,180,3,3);   // STUDENT
		    floodfill(105,151,WHITE);
		    outtextxy(125,155,"Book Name");

			bar3d(100,200,280,230,3,3);   // BOOK
			floodfill(105,201,WHITE);
			outtextxy(130,205,"Author Name");

			bar3d(100,250,280,280,3,3);   // BOOK
			floodfill(105,251,WHITE);
			outtextxy(130,255,"Book Code");


	    setfillstyle(1,15);

	    floodfill(105,149,WHITE);
	    floodfill(281,173,WHITE); // 1 button  3d

		floodfill(103,199,WHITE);
		floodfill(282,228,WHITE); // 2 button  3d

		floodfill(108,149,WHITE);
		floodfill(282,268,WHITE); // 2 button  3d

// scnaf fun
	settextstyle(1,0,1);
	setfillstyle(1,0);

	 play();

		bar3d(320,150,530,180,3,3);   // STUDENT
		floodfill(325,151,WHITE);
		  gotoxy(44,11);
	     gets(bk.b_name);

	 play();

		   bar3d(320,200,530,230,3,3);   // BOOK
		   floodfill(325,201,WHITE);
	       gotoxy(44,14);
	     gets(bk.b_author);

	 play();

		   bar3d(320,250,530,280,3,3);   // BOOK
		   floodfill(325,251,WHITE);
	      fflush(stdin);
		gotoxy(44,17);
	     scanf("%d",&bk.b_code);

	 play();

settextstyle(11,0,1);
setfillstyle(1,0);
bar3d(180,150,440,250,0,0);
outtextxy(205,170,"Press Y/N for Save & Retry");

outtextxy(190,220,"Y - for Save");

outtextxy(320,220,"C - for cancel");

  lable:
play2();

  ch=getch();
  if(ch=='y' || ch=='Y')
  {
		play();
		fwrite(&bk,sizeof(bk),1,fb);
		 fclose(fb);
   }
   else if(ch=='c' || ch=='C')
   {
   play();
		 fclose(fb);
		main();
   }
   else
   {
   printf("enter a valid key");
   goto lable;
   }
main();

   }


	  void issued_book(FILE *fs, FILE *fi)
   {

   char print[22];
   int flag=0;
//   rewind(fs);
	cleardevice();

	settextstyle(11,0,3);
     outtextxy(10,450,"Press H for Main Menu");
	rectangle(1,1,getmaxx(),getmaxy());
	setfillstyle(9,4);
	floodfill(4,4,WHITE);

	   settextstyle(1,0,4);
	   outtextxy(230,20,"ISSUED BOOK");
	   line(230,60,450,60);

		bar3d(80,120,570,420,5,5);
		setfillstyle(9,6);
		floodfill(82,124,WHITE);
		setfillstyle(1,15);
		floodfill(85,119,WHITE);
		floodfill(572,410,WHITE);   // top 3d



	settextstyle(1,0,1);
	setfillstyle(1,6);

		bar3d(100,150,280,180,3,3);   // STUDENT
		floodfill(105,151,WHITE);
		outtextxy(125,155,"Student Name");

		    bar3d(100,200,280,230,3,3);   // BOOK
		    floodfill(105,201,WHITE);
		    outtextxy(130,205,"BOOK Name");

			bar3d(100,250,280,280,3,3);   // ISSUED BOOK
			floodfill(105,251,WHITE);
			outtextxy(120,255,"BOOK CODE");

			    bar3d(100,300,280,330,3,3);   // ISSUED BOOK
			    floodfill(105,311,WHITE);
			    outtextxy(140,305,"ISSUED DATE");

		    setfillstyle(1,15);

			    floodfill(105,149,WHITE);
			    floodfill(281,173,WHITE); // 1 button  3d

		       floodfill(103,199,WHITE);
		       floodfill(282,228,WHITE); // 2 button  3d

		  floodfill(103,249,WHITE);
		  floodfill(281,273,WHITE);   // 3 button 3d

	      floodfill(103,299,WHITE);
	      floodfill(281,323,WHITE);   // 3 button 3d



	// scnaf fun
	settextstyle(1,0,1);
	setfillstyle(1,0);

	   bar3d(320,150,530,180,3,3);   // STUDENT
	   floodfill(325,151,WHITE);

	 play();

  gotoxy(43,11);
   gets(print);

     while(fread(&st,sizeof(st),1,fs)==1)
    {
     if(strcmp(st.s_name,print)==0)
     {

     strcpy(all.i_name,print);

	 play();

		bar3d(320,200,530,230,3,3);   // BOOK
		floodfill(325,201,WHITE);
		gotoxy(43,14);
		 gets(all.ib_name);

	 play();

		    bar3d(320,250,530,280,3,3);   // ISSUED BOOK
		    floodfill(325,251,WHITE);

	 gotoxy(43,17);
     scanf("%d",&all.ib_code);

	 play();

			bar3d(320,300,530,330,3,3);   // ISSUED BOOK
			floodfill(325,311,WHITE);
			  gotoxy(43,20);
     scanf("%d%d%d",&all.d,&all.m,&all.y);


		line(80,350,570,350);
  outtextxy(100,370,"NOTE: sias");

     fclose(fs);
     fwrite(&all,sizeof(all),1,fi);
     flag=1;
     }

    }

	 play2();
settextstyle(11,0,1);
setfillstyle(1,0);
bar3d(180,150,440,250,0,0);

//outtextxy(190,220,"Y - for Save");

//outtextxy(320,220,"C - for cancel");
//	 play();

     if(flag==0)
outtextxy(205,170,"Student Not Found");
     else
outtextxy(205,170,"Book Issued Successfully");

//     getch();
	 fclose(fi);
	 fclose(fs);
getch();
	 main();
   }


	void search_book(FILE *fb)
   {
   int f=0;
   char name[10];

	 play();

	    rectangle(1,1,getmaxx(),getmaxy());
	    setfillstyle(9,4);
	    floodfill(4,4,WHITE);

		settextstyle(1,0,4);
		outtextxy(210,20,"SEARCH BOOK");
		line(200,60,450,60);

		    bar3d(80,120,570,420,5,5);
		    setfillstyle(9,6);
		    floodfill(82,124,WHITE);
		    setfillstyle(1,15);
		    floodfill(85,119,WHITE);
		    floodfill(572,410,WHITE);   // top 3d

	    settextstyle(1,0,1);
	    setfillstyle(1,6);

			bar3d(100,200,280,230,3,3);   // BOOK
			floodfill(105,201,WHITE);
			outtextxy(130,205,"BOOK NAME");

	    setfillstyle(1,15);

		floodfill(103,199,WHITE);
		floodfill(282,228,WHITE); // 2 button  3d

// scnaf fun
	settextstyle(1,0,1);
	setfillstyle(1,0);

		   bar3d(320,200,530,230,3,3);   // BOOK
		   floodfill(325,201,WHITE);

		line(80,350,570,350);
 outtextxy(170,370,"Check Availablity Of The Book");

	 play();

   gotoxy(40,10);
   gets(name);
    while(fread(&bk,sizeof(bk),1,fb)==1)
    {
    if(strcmp(name,bk.b_name)==0)
    {
	   puts(bk.b_name);

	 // printf("\n author name ");
	     puts(bk.b_author);

	//  printf("\n book code ");
	      printf("%d",bk.b_code);
	 f=1;
	   }
    }
    if(f==0)
    outtextxy(200,200,"book not found");

    getch();
     fclose(fb);
    main();
   }


	void return_book(FILE *fi)
   {
   int flag=0,code;
     FILE *tmp;

	 play();

	    rectangle(1,1,getmaxx(),getmaxy());
	    setfillstyle(9,4);
	    floodfill(4,4,WHITE);

		settextstyle(1,0,4);
		outtextxy(220,20,"RETURN BOOK");
		line(210,60,450,60);

		    bar3d(80,120,570,420,5,5);
		    setfillstyle(9,6);
		    floodfill(82,124,WHITE);
		    setfillstyle(1,15);
		    floodfill(85,119,WHITE);
		    floodfill(572,410,WHITE);   // top 3d

	    settextstyle(1,0,1);
	    setfillstyle(1,6);

			bar3d(100,200,280,230,3,3);   // BOOK
			floodfill(105,201,WHITE);
			outtextxy(130,205,"BOOK CODE");

	    setfillstyle(1,15);

		floodfill(103,199,WHITE);
		floodfill(282,228,WHITE); // 2 button  3d

// scnaf fun
	settextstyle(1,0,1);
	setfillstyle(1,0);

		   bar3d(320,200,530,230,3,3);   // BOOK
		   floodfill(325,201,WHITE);


		line(80,350,570,350);
 outtextxy(90,370,"Enter Book Code & The Book Is Return Successfully");

	 play();

     tmp=fopen("tmpd.dat","wb");

     gotoxy(44,14);
      scanf("%d",&code);
     /*
      printf(" student name ");
	gets(name);

     printf(" book name ");
	gets(name2);
      */
      while(fread(&all,sizeof(all),1,fi)==1)
      {
	if(code!=all.ib_code)
	{
	    fwrite(&all,sizeof(all),1,tmp);
	    flag=1;
	}
      }

   fclose(fi);
   fclose(tmp);
   remove("isubook.dat");
   rename("tmpd.dat","isubook.dat");
setfillstyle(9,BLACK);
bar3d(180,200,440,300,0,0);
	settextstyle(2,0,6);

	 play2();

    if(flag==1)
    {
    outtextxy(270,215,"Sorry:");
     outtextxy(210,240,"The Book is Not Found");
    }
    else
    {
    outtextxy(270,215," ");
     outtextxy(210,240,"Book Return Successfully");
    }
	settextstyle(1,0,4);
      getch();
      main();
   }



      void rule()
  {
		FILE *fp;
		 char print[1000];
	 play2();

	   closegraph();
       fp=fopen("rule.txt","ab+");

	fread(&print,sizeof(print),1,fp);
       gotoxy(3,2);
	 puts(print);


		fseek(fp,0,2);
		   fclose(fp);

	  getch();
	 play();

	  main();
}



void error()
{
char ch;

int i;
	      lable:

	 play();

	      cleardevice();
		rectangle(1,1,getmaxx(),getmaxy());
		setfillstyle(9,4);
		floodfill(4,4,WHITE);

	     settextstyle(1,0,4);
	     outtextxy(274,20,"EXIT");
	     line(260,60,350,60);

	bar3d(80,120,570,420,5,5);
	setfillstyle(9,6);
	floodfill(82,124,WHITE);
	setfillstyle(1,15);
	floodfill(85,119,WHITE);
	floodfill(572,410,WHITE);   // top 3d

	settextstyle(8,0,2);
	outtextxy(175,150,"Do You Want TO EXIT The ");
	line(170,180,480,180);
	outtextxy(210,200,"LIBRARY MANAGER");
	line(200,230,430,230);


	circle(295,290,5);
	circle(345,290,5);
	circle(320,310,60);
	setfillstyle(1,BLACK);
	floodfill(296,291,WHITE);
	floodfill(346,291,WHITE);
	setfillstyle(9,4);
	floodfill(333,300,WHITE);
	ellipse(320,330,180,0,22,10);

	settextstyle(11,0,3);                  // imp text style
	outtextxy(90,380," Press ' Y ' for exit");
	outtextxy(380,380," Press ' x ' for cancel");
	settextstyle(11,0,3);
	ch=getch();
	 play();

	if(ch=='Y' || ch=='y')
	   exit(1);
	if(ch=='x' || ch=='X')
	  main();
	goto lable;

}

void about()
{

int i;
	 play();

	      cleardevice();
		rectangle(1,1,getmaxx(),getmaxy());
		setfillstyle(9,4);
		floodfill(4,4,WHITE);

	     settextstyle(1,0,4);
	     outtextxy(255,20,"ABOUT US.");
	     line(245,60,410,60);

	bar3d(70,120,580,420,5,5);
	setfillstyle(9,6);
	floodfill(72,124,WHITE);
	setfillstyle(1,15);
	floodfill(75,119,WHITE);
	floodfill(582,410,WHITE);   // top 3d

	settextstyle(1,0,2);
       outtextxy(250,135,"DEVLOPER TEAM");
      delay(200);
       line(240,165,420,165);
    play2();
    outtextxy(95,185,"' RUBY FAIZAN ' Cordinate Of B.C.A.");
    play2();
    outtextxy(95,220,"' MUKUL JATAV ' Student of B.C.A. 2018 Batch.");
    play2();
    outtextxy(95,255," Special thanks to ' ADNAN BHAI ' ");

   settextstyle(11,0,3);
    outtextxy(80,300,"  **********************************************************");
    outtextxy(80,330,"This Software Is Create In Turbo C. The Software Is devloped");
    outtextxy(80,350,"Using - FILE HANDLING, GRAPHICS, And Other Predefined Function");
    outtextxy(80,370,"And Also Some Function Is Defined By User In C.");
    outtextxy(80,390,"This Is Devloped For Maintain Library In A Well Defined Manar.");
//    outtextxy(95,360,"");

    play();
}


void notfication()
{
	      cleardevice();
		rectangle(1,1,getmaxx(),getmaxy());
		setfillstyle(9,4);
		floodfill(4,4,WHITE);

	     settextstyle(1,0,4);
	     outtextxy(245,20,"NOTFICATION");
	     line(245,60,430,60);

	bar3d(70,120,580,420,5,5);
	setfillstyle(9,BLACK);
	floodfill(72,124,WHITE);
	setfillstyle(1,15);
	floodfill(75,119,WHITE);
	floodfill(582,410,WHITE);   // top 3d


	circle(330,240,90);
	circle(300,220,10);
	circle(360,220,10);
	setfillstyle(1,4);
	floodfill(333,243,WHITE);

	ellipse(330,300,0,180,30,20);
	outtextxy(120,360,"NO NOTFICATION AVAILABLE");
      //	getch();

}


void play()
{
sound(200);
delay(110);
nosound();

}

void play2()
{

    sound(1000);
  delay(150);
  sound(500);
  delay(300);
  nosound();
     delay(500);


}
