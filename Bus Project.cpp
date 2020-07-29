#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>

void displayv(int ,int ,int );
void box(int,int,int,int,char);
void boxn(int,int,int,int,char,char);
void heading();
void error(char *);
void display(int,int,char *);
void clserror();

class bus
{
	private :
		int bno;
		int sno[43];
		int fare;
		char start[15],end[15];
	public :
		void get_bus_data()
		{
			box(25,6,55,8,'Û');
			display( 7,32,"ENTER BUS DETAILS");
			box(20,8,60,18,'±');
			display(10,24,"Enter Bus No.       :>  ");
			cin>>bno;
			display(12,24,"Starting   Station  :>  ");
			cin>>start;
			fflush(stdin);
			display(14,24,"Destination Station :>  ");
			cin>>end;
			fflush(stdin);
			sno[0]=0;
			for(int i=1;i<=42;i++)
				sno[i] = 0;
			display(16,24,"Bus Fare Per Seat   :>  ");
			cin>>fare;
		}
		void show_bus_details(int r)
		{
			int e=0,i;
			displayv(r,13,bno);
			gotoxy(20,r);
			cout<<start;
			gotoxy(35,r);
			cout<<end;
			displayv(r,50,fare);
			displayv(r,59,42);
			for(i=1;i<=42;i++)
			{
				if(sno[i] == 0)
					e++;
			}
			displayv(r,66,e);
			displayv(r,74,42-e);
		}
		int chksd(char s[],char d[])
		{
			if (strcmpi(s,start)==0 && strcmpi(d,end)==0)
				return 1;
			else
				return 0;
		}
		int count()
		{
			int t=0;
			for (int i=1;i<=42;i++)
			{
				if (sno[i]==0)
					t++;
			}
			return t;
		}
		int get_bsno()
		{
			return bno;
		}
		void update(int t)
		{
			for(int i=1;i<=42;i++)
			{
				if (sno[i] == 0)
				{
					sno[i] = t;
					break;
				}
			}
		}
		void cancel(int t)
		{
			for(int i=1;i<=42;i++)
			{
				if (sno[i] == t)
				{
					sno[i] = 0;
					break;
				}
			}
		}

		void show_tkt()
		{
			gotoxy(17,12);
			cout<<"FROM : "<<start;
			gotoxy(45,12);
			cout<<"UPTO : "<<end;
		}
		void show_tktdisp()
		{
			gotoxy(17,13);
			cout<<"FROM : "<<start;
			gotoxy(45,13);
			cout<<"UPTO : "<<end;
		}
		int seatno(int t,int l)
		{
			for(int i = l+1;i<=42;i++)
			{
				if(sno[i] == t)
					return i;
			}
		}
		int kiraya()
		{
			return fare;
		}
		int chkbusno()
		{
			return bno;
		}
		void show_chart()
		{
			clrscr();
			display(1,13,"BUS No. : ");
			cout<<bno;
			display(1,32,"FROM : ");
			cout<<start;
			display(1,54,"UPTO : ");
			cout<<end;
		}
		void show_bus_status()
		{
			clrscr();
			int i,x,y,x1,y1;
			heading();
			display(3,13,"BUS No. : ");
			cout<<bno;
			display(3,32,"FROM : ");
			cout<<start;
			display(3,54,"UPTO : ");
			cout<<end;
			box(1,4,78,24,'Û');
			x=4;
			y=5;
			for(i=1;i<=9;i++)
			{
				boxn(x,y,x+4,y+2,'Ä','³');
				x=x+8;
			}

			x=4;
			y=9;
			for(i=1;i<=9;i++)
			{
				boxn(x,y,x+4,y+2,'Ä','³');
				x=x+8;
			}
			x=12;
			y=13;
			for(i=1;i<=8;i++)
			{
				boxn(x,y,x+4,y+2,'Ä','³');
				x=x+8;
			}
			x=12;
			y=17;
			for(i=1;i<=8;i++)
			{
				boxn(x,y,x+4,y+2,'Ä','³');
				x=x+8;
			}
			x=12;
			y=21;
			for(i=1;i<=8;i++)
			{
				boxn(x,y,x+4,y+2,'Ä','³');
				x=x+8;
			}
			x = 11;
			y = 6;
			for(i=3;i<=42;i++)
			{
				if(i>9)
					gotoxy(x-1,y);
				else
					gotoxy(x,y);
				cout<<i;
				y = y +4;
				if ((i-2) % 5 == 0)
				{
					x = x+8;
					y=6;
				}
			}
			display(6,3,"1");
			display(10,3,"2");
			//getch();
			//return;
			x=14;y=6;
			int v=0,o=0;
			for(i=3;i<=42;i++)
			{
				if(sno[i] == 0)
				{
						display(y,x," ");
						v++;
				}
				else
				{
					display(y,x,"X");
					o++;
				}
				y = y + 4;
				if ((i-2) % 5 == 0)
				{
					x = x+8;
					y	= 6;
				}
			}
			if(sno[1] == 0)
			{
				display(6,6," ");
				v++;
			}
			else
			{
				display(6,6,"X");
				o++;
			}
			if(sno[2] == 0)
			{
				display(10,6," ");
				v++;
			}
			else
			{
				display(10,6,"X");
				o++;
			}
			gotoxy(10,24);
			cout<<"  TOTAL OCCUPIED : "<<o<<"  ";
			gotoxy(45,24);
			cout<<"   TOTAL VACANT : "<<v<<"  ";
			getch();
		}
		int get_tno(int p)
		{
			return sno[p];
		}
};

class customer
{
	private :
		char name[15];
		char sex;
		int  age;
		int  bsno;
		int  tktno;
		int seat;
	public :
		void get_cust_data(int r)
		{
			display(r,19," ");
			cin>>name;
			display(r,40," ");
			cin>>age;
			display(r,48," ");
			cin>>sex;
		}
		void update(int tn,int bn)
		{
			bsno = bn;
			tktno = tn;
		}
		void updateseat(int s)
		{
			seat = s;
		}
		int chkcust(int t,int b)
		{
			if (t==tktno && b==bsno)
				return 1;
			else
				return 0;
		}
		int check(int t,int b)
		{
			if (t==tktno && b==bsno )
				return 1;
			else
				return 0;
		}

		void show_tkt(int r)
		{
			gotoxy(30,r);
			cout<<name;
			gotoxy(48,r);
			cout<<sex;
			displayv(r,56,age);
		}
		void display_chart(int r, int c)
		{
			if(c > 0)
				display(r,2+c,"Û");
			//displayv(r,c+5,seat);
			gotoxy(c+12,r);
			cout<<tktno;
			gotoxy(c+18,r);
			cout<<name;
			gotoxy(c+30,r);
			cout<<age;
			gotoxy(c+35,r);
			cout<<sex;
		}
};

class ticket
{
	private :
		int tno;
		int bn;
		int stat;
	public :
		void show()
		{
			cout<<"\nticket no : "<<tno<<"\t\tBus No : "<<bn<<"\t\tStatus :"<<stat;
		}
		void update(int t,int b, int s)
		{
			tno = t;
			bn = b;
			stat = s;
		}
		int get_tno()
		{
			return tno;
		}
		int get_bno()
		{
			return bn;
		}
		int get_stat()
		{
			return stat;
		}
		void cancel()
		{
			stat = 0;
		}
};

void main()
{
	bus bs;
	ticket tk;
	customer cs;

	int ch,cho,i,f,s,s1,s2,t,p,j;
	s  = sizeof(bs);
	s1 = sizeof(cs);
	s2 = sizeof(tk);

	do
	{
		clrscr();
		heading();
		box(30,5,50,7,'Û');
		display(6,33,"M A I N  M E N U");
		box(25,9,55,15,'°');
		int row=10;
		int col=29;
		display(row++,col,"1. ENTER  BUS  DETAILS");
		display(row++,col,"2. MAKE  A RESERVATION");
		display(row++,col,"3. MAKE  A CANCELATION");
		display(row++,col,"4. DISPLAY INFORMATION");
		display(row++,col,"5.     E  X  I  T");
		box(25,17,55,19,'Û');
		display(18,28,"ENTER YOUR VALID CHOICE : ");
		fflush(stdin);
		cin>>ch;
		switch(ch)
		{
			case 1:
				clrscr();
				heading();
				fstream add;
				add.open("bus.dat",ios::app|ios::binary);
				bs.get_bus_data();
				add.write((char *)&bs,s);
				add.close();
				break;
			case 2:
				clrscr();
				char src[15],dest[15];
				f=0;
				fstream show,rstk,rscust;
				show.open("bus.dat",ios::ate|ios::in|ios::out|ios::binary);
				rstk.open("tkd.dat",ios::app|ios::out|ios::in|ios::binary);
				rscust.open("cust.dat",ios::ate|ios::in|ios::out|ios::binary);
				rstk.seekg(0,ios::end);
				show.seekg(0,ios::beg);
				rscust.seekg(0,ios::beg);
				int tst = rstk.tellg()/(sizeof(ticket));
				heading();
				box(25,5,55,7,'Û');
				display(6,29,"RESERVATION DETAILS FORM");
				box(10,8,70,11,'²');
				display(9,20,"ENTER THE SOURCE AND DESTINATION STATION NAME");
				display(10,13,"SOURCE  :> ");
				gets(src);
				fflush(stdin);
				display(10,42,"DESINATION :> ");
				gets(dest);
				fflush(stdin);
				show.read((char *)&bs,s);
				while(!show.eof())
				{
					if(bs.chksd(src,dest))
					{
						f = 1;
						int tv = bs.count();
						int ff = bs.kiraya();
						box(2,13,15,23,'±');
						display(15,6,"BUS No");
						displayv(16,7,bs.get_bsno());
						display(18,4,"AVAILABLE");
						displayv(19,8,tv);
						display(21,4,"FARE/SEAT");
						displayv(22,8,ff);
						if (tv==0)
						{
							error("Sorry No More Seats : ");
							break;
						}
						char more;
						int i = 1;
						display(13,20,"Passenger Name");
						display(13,40,"AGE");
						display(13,48,"SEX");
						display(13,65,"MORE");
						box(20,14,70,14,'þ');
						int ro = 15;
						while(i<=5)
						{
							i++;
							cs.get_cust_data(ro++);
							//**********************//


							//*********************//
							cs.update(tst+1,bs.get_bsno());
							rscust.write((char *)&cs,s1);
							bs.update(tst+1);
							if (i>tv)
							{
								error("No More Reservations Allowed in This Bus");
								getch();
								break;
							}
							if(i==6)
							{
								error("Only Five Passenger Per Ticket is valid : ");
								getch();
								break;
							}
							display(ro-1,66," ");
							fflush(stdin);
							cin>>more;
							if (more != 'Y' && more != 'y')
							{
								break;
							}
						}
						tk.update(tst+1,bs.get_bsno(),1);
						rstk.write((char *)&tk,s2);
						clserror();
						error("Generating Ticket Pls. wait");
						delay(3000);
						int tkt_no = tst+1;
						int bus_no = bs.get_bsno();
						clrscr();
						heading();
						box(15,7,65,23,'Û');
						display(8,16,"TICKET NO.");
						display(8,30,"BUS NO.");
						display(8,40,"FARE/SEAT");
						display(8,53,"TOTAL SEATS");
						displayv(9,20,tkt_no);
						displayv(9,32,bus_no);
						displayv(9,44,ff);
						box(16,10,64,10,'þ');
						display(11,25,"JOURNEY CUM RESERVATION TICKET");
						bs.show_tkt();
						box(16,13,64,13,'þ');
						display(14,20,"SEAT NO.");
						display(14,30,"PASSENGER NAME");
						display(14,48,"SEX");
						display(14,55,"AGE");
						int last = 0;
						rscust.seekg(0,ios::beg);
						rscust.read((char *)&cs,s1);
						int tro=15;
						int sn=0;
						while(!rscust.eof())
						{
								if(cs.chkcust(tkt_no,bus_no))
								{
									int seat_num = bs.seatno(tkt_no,last);
									last = seat_num;
									displayv(tro,22,seat_num);
									cs.show_tkt(tro++);
									cs.updateseat(seat_num); //33
									rscust.seekg(-s1,ios::cur);
									rscust.write((char *)&cs,s1);
									sn++;
								}
								rscust.read((char *)&cs,s1);
						}
						int tf = ff*(sn);
						box(16,20,64,20,'þ');
						gotoxy(16,21);
						cout<<"TOTAL FARE: "<<tf;
						char am[4][6];
						int amt = tf;
						int v = 3;
						int rm;
						while(amt>0)
						{
							rm = amt%10;
							if(rm==0)
								strcpy(am[v],"ZERO");
							if(rm==1)
								strcpy(am[v],"ONE");
							if(rm==2)
								strcpy(am[v],"TWO");
							if(rm==3)
								strcpy(am[v],"THREE");
							if(rm==4)
								strcpy(am[v],"FOUR");
							if(rm==5)
								strcpy(am[v],"FIVE");
							if(rm==6)
								strcpy(am[v],"SIX");
							if(rm==7)
								strcpy(am[v],"SEVEN");
							if(rm==8)
								strcpy(am[v],"EIGHT");
							if(rm==9)
								strcpy(am[v],"NINE");
							v--;
							amt=amt/10;
						}
						cout<<"  (Rs. ";
						int tmp;
						if(tf<10)
							tmp=3;
						else if(tf<100)
							tmp=2;
						else if(tf<1000)
							tmp=1;
						else
							tmp=0;
						for(v=tmp;v<4;v++)
							cout<<am[v]<<" ";
							cout<<" Only)";
						displayv(9,60,sn);
						display(22,32,"HAPPY JOURNEY");
						break;
					}
					show.read((char *)&bs,s);
				}

				if(f==0)
					error("No Bus Available for this Route");
				else
				{
					show.seekg(-s,ios::cur);
					show.write((char *)&bs,s);
				}
				show.close();
				rscust.close();
				rstk.close();
				getch();
				break;
			case 3:
				clrscr();
				heading();
				int tkno;
				box(23,11,57,13,'±');
				display(12,28,"Enter The Ticket No. : ");
				cin>>tkno;
				fstream rsbus,rscu;
				fstream rst;
				rst.open("tkd.dat",ios::binary|ios::in|ios::out|ios::ate);
				rsbus.open("bus.dat",ios::ate|ios::in|ios::out|ios::binary);
				rscu.open("cust.dat",ios::app|ios::in|ios::out|ios::binary);
				f = 0;
				int tkt_no,bus_no;
				int ff;
				rst.seekg(0,ios::beg);
				rst.read((char *)&tk,s2);
				while(!rst.eof())
				{
					tkt_no = tk.get_tno();
					if(tkt_no == tkno ) //&& tk.get_stat()==1)
					{
						if(tk.get_stat() == 0)
						{
							error("This Ticket No. is Already Canceled..!");
							f=2;
							break;
						}
						f=1;
						bus_no = tk.get_bno();
						break;
					}
					rst.read((char *)&tk,s2);
				}
				rsbus.seekg(0,ios::beg);
				rsbus.read((char *)&bs,s);
				if (f==1)
				{
						while(!rsbus.eof())
						{
							if(bus_no == bs.get_bsno())
							{
								ff = bs.kiraya();
								break;
							}
							rsbus.read((char *)&bs,s);
						}
						clrscr();
						heading();
						box(15,8,65,24,'Û');
						display(9,16,"TICKET NO.");
						display(9,30,"BUS NO.");
						display(9,40,"FARE/SEAT");
						display(9,53,"TOTAL SEATS");
						displayv(10,20,tkt_no);
						displayv(10,32,bus_no);
						displayv(10,44,ff);
						box(16,11,64,11,'þ');
						display(12,25,"JOURNEY CUM RESERVATION TICKET");
						bs.show_tktdisp();
						box(16,14,64,14,'þ');
						display(15,20,"SEAT NO.");
						display(15,30,"PASSENGER NAME");
						display(15,48,"SEX");
						display(15,55,"AGE");
						int last = 0;
						rscu.seekg(0,ios::beg);
						rscu.read((char *)&cs,s1);
						int tro=16;
						int sn=0;
						while(!rscu.eof())
						{
								if(cs.chkcust(tkt_no,bus_no))
								{
									int seat_num = bs.seatno(tkt_no,last);
									last = seat_num;
									displayv(tro,22,seat_num);
									cs.show_tkt(tro++);
									sn++;
									bs.cancel(tkt_no);
								}
								rscu.read((char *)&cs,s1);
						}
						int tf = ff*(sn);
						box(16,21,64,21,'þ');
						gotoxy(16,22);
						cout<<"TOTAL FARE: "<<tf;
						char am[4][6];
						int amt = tf;
						int v = 3;
						int rm;
						while(amt>0)
						{
							rm = amt%10;
							if(rm==0)
								strcpy(am[v],"ZERO");
							if(rm==1)
								strcpy(am[v],"ONE");
							if(rm==2)
								strcpy(am[v],"TWO");
							if(rm==3)
								strcpy(am[v],"THREE");
							if(rm==4)
								strcpy(am[v],"FOUR");
							if(rm==5)
								strcpy(am[v],"FIVE");
							if(rm==6)
								strcpy(am[v],"SIX");
							if(rm==7)
								strcpy(am[v],"SEVEN");
							if(rm==8)
								strcpy(am[v],"EIGHT");
							if(rm==9)
								strcpy(am[v],"NINE");
							v--;
							amt=amt/10;
						}
						cout<<"  (Rs. ";
						int tmp;
						if(tf<10)
							tmp=3;
						else if(tf<100)
							tmp=2;
						else if(tf<1000)
							tmp=1;
						else
							tmp=0;
						for(v=tmp;v<4;v++)
							cout<<am[v]<<" ";
							cout<<" Only)";
						displayv(10,60,sn);
						display(23,32,"HAPPY JOURNEY");
						char ans,confirm;
						fflush(stdin);
						box(25,5,55,7,'±');
						display(6,28,"CANCEL THIS TICKET : ");
						cin>>ans;
						if(ans=='y' || ans =='Y')
						{
							display(6,27,"   ARE YOU SURE ?  :   ");
							cin>>confirm;
							if(confirm =='y' || confirm =='Y')
							{
								tk.cancel();
								rst.seekg(-s2,ios::cur);
								rst.write((char *)&tk,s2);
								rsbus.seekg(-s,ios::cur);
								rsbus.write((char *)&bs,s);
							}
						}
					}
					else	if (f==0)
						error("No Ticket with Such Number Generated So Far !");
				getch();
				rst.close();
				rsbus.close();
				rscu.close();
				break;
			case 4:
				do
				{
					clrscr();
					heading();
					box(30,5,50,7,'Û');
					display(6,33,"DISPLAY  MENU");
					box(25,9,55,14,'°');
					int row=10;
					int col=29;
					display(row++,col,"1. DISAPLY  BUS  STATUS");
					display(row++,col,"2. SHOW ALL BUSES INFO.");
					display(row++,col,"3. RESERVATION    CHART");
					display(row++,col,"4. BACK TO MAIN MENU");
					box(25,17,55,19,'Û');
					display(18,28,"ENTER YOUR VALID CHOICE : ");
					fflush(stdin);
					cin>>cho;
					switch(cho)
					{
						case 1:
							clrscr();
							int busn;
							f=0;
							ifstream show;
							show.open("bus.dat",ios::binary);
							box(25,11,55,13,'±');
							display(12,28,"Enter The Bus No. : ");
							cin>>busn;
							show.read((char *)&bs,s);
							while(! show.eof() )
							{
								if(bs.chkbusno()==busn)
								{
									f = 1;
									bs.show_bus_status();
									break;
								}
								show.read((char *)&bs,s);
							}
							if(f==0)
							{
								error("No Bus Exist with Such Number : ");
								getch();
							}
							show.close();
							break;
						case 2:
							clrscr();
							ifstream showrs;
							showrs.open("bus.dat",ios::binary);
							showrs.seekg(0,ios::beg);
							showrs.read((char *)&bs,s);
							heading();
							box(3,5,77,24,'Û');
							display(6,5,"S.No.");
							display(6,12,"Bus No.");
							display(6,20,"FROM");
							display(6,35,"UPTO");
							display(6,50,"FARE");
							display(6,58,"SEATS");
							display(6,65,"EMPTY");
							display(6,73,"FULL");
							box(4,7,76,7,'þ');
							f=1;
							int rw=8;
							while(! showrs.eof() )
							{
									gotoxy(6,rw);
									cout<<f++;
									bs.show_bus_details(rw++);
									showrs.read((char *)&bs,s);
							}
							showrs.close();
							getch();
							break;
						case 3:
							clrscr();
							int p,j,i,rows,cols,num,tnum;
							f=0;
							ifstream bf,cf,tf;
							bf.open("bus.dat",ios::binary);
							cf.open("cust.dat",ios::binary);
							box(25,11,55,13,'±');
							display(12,28,"Enter The Bus No. : ");
							cin>>num;
							clrscr();
							bf.read((char *)&bs,s);
							cols = 0;
							while(! bf.eof() )
							{
								if(bs.chkbusno()==num)
								{
									f=1;
									bs.show_chart();
									box(2,2,79,2,'þ');
									display(3,4,"SEAT");
									display(3,10,"Tkt.No.");
									display(3,18,"NAME");
									display(3,30,"AGE");
									display(3,35,"SEX");
									display(3,40,"Û");
									display(3,42,"SEAT");
									display(3,48,"Tkt.No.");
									display(3,56,"NAEM");
									display(3,69,"AGE");
									display(3,73,"SEX");
									rows = 4;
									cf.seekg(0,ios::beg);

									for(i=1;i<=42;i++)
									{
										tnum = bs.get_tno(i);
										if (tnum == 0)
										{
											if(cols > 0)
												display(rows,2+cols,"Û");
											displayv(rows,4+cols,i);
											display(rows,12+cols,"-x-");
											display(rows,20+cols,"-x-");
											display(rows,30+cols,"-x-");
											display(rows,35+cols,"-x-");
										}
										else
										{
											cf.read((char *)&cs,s1);

											while( !cf.eof())
											{
												if(cs.chkcust(tnum,num))
												{
													cs.display_chart(rows,cols);
													displayv(rows,4+cols,i);
													break;
												}
												cf.read((char *)&cs,s1);
											}
										}
										rows++;
										if(rows >= 25)
										{
											rows = 4;
											cols = cols + 38;
										}
									}
								}
								bf.read((char *)&bs,s);
							}
							if(f==0)
							{
								error("No Bus Exist with Such Number : ");
								getch();
							}
							cf.close();
							bf.close();
							getch();
							break;


						case 4:
							break;
					}
				}while(cho != 4);
				break;
		case 5:
			break;
	}
}while(ch!=5);
}
void box(int c1,int r1,int c2,int r2,char x)
{
	int i;
	for(i=c1;i<=c2;i++)
	{
		gotoxy(i,r1);
		cout<<x;
		gotoxy(i,r2);
		cout<<x;
	}
	for(i=r1+1;i<=r2-1;i++)
	{
		gotoxy(c1,i);
		cout<<x;
		gotoxy(c2,i);
		cout<<x;
	}
}
void boxn(int c1,int r1,int c2,int r2,char x,char y)
{
	int i;
	for(i=c1;i<=c2;i++)
	{
		gotoxy(i,r1);
		cout<<x;
		gotoxy(i,r2);
		cout<<x;
	}
	for(i=r1+1;i<=r2-1;i++)
	{
		gotoxy(c1,i);
		cout<<y;
		gotoxy(c2,i);
		cout<<y;
	}
}
void heading()
{
	box(10,1,70,3,'²');
	gotoxy(18,2);
	cout<<"BHARAT DARSHAN TOURIST BUS SERVICE, DEHRADUN";
}
void error(char *msg)
{
	int i;
	int l = strlen(msg);
	int s,e;
	s = 38-l/2;
	e = 42+l/2;
	box(s,24,e,24,'þ');
	gotoxy(s+2,25);
	cout<<msg;
}
void clserror()
{
	for(int i = 0;i<79;i++)
	{
		gotoxy(i,24);
		cout<<" ";
		gotoxy(i,25);
		cout<<" ";
	}
}
void display(int r,int c,char *str)
{
	gotoxy(c,r);
	cout<<str;
}
void displayv(int r,int c,int n)
{
	gotoxy(c,r);
	cout<<n;
}
