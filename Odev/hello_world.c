#include <stdio.h>
#include <stdlib.h>
int main()
	{
	int choice;  			int hws; 	int pw;
	int salfmngr;			int hwss;	int ipw;
	int hsalfmngr;			int cw;		int cp;
	int sm;					int cws;	int pws;
	int hw;					int ps;		int a;
	int hwc;				float cwss;  
	
	printf("Welcome to payment program.\n\n");
	
	basadon:
	
	printf("Please choose your paycode:\n\n [1] for Managers\n [2] for Hourly Workers\n [3] for Commission Workers\n [4] for Pieceworkers.\n\n\n");
	scanf("%d",&choice);

	
		switch(choice) 
		{
		
		
		  case 1 :
		  printf("How much dollar do you pay per a week for each manager?\n");
		  scanf("%d",&salfmngr);
		  printf("\nHow many managers worked this week?\n");
		  scanf("%d",&hsalfmngr);
		  sm= salfmngr*hsalfmngr;
		  printf("\n\nYou will totally pay %d dollar for managers.\n\n",sm);
		  break;
		 
		 case 2 :
		 printf("How much dollar do you pay per a hour for each hourly worker?\n");
		 scanf("%d",&hw);
		 printf("\nHow many hourly workers worked this week?\n");
		 scanf("%d",&hws);
		 printf("\nHow many workers worked this week?\n");
		 scanf("%d",&hwc);
		
		 	if (hws<=40) 
			{
		    hwss =+ hws*hw*hwc;
		    printf("\n\nYou will totally pay %d dollar for hourly workers.\n\n",hwss);
			}
		
			else
			{
					hwss=+ (40*hw*hwc)+((hws-40)*hw*(3/2)*hwc);	
				 	printf("\n\nYou will totally pay %d dollar for hourly workers\n\n.",hwss); 
			}
			break;
		
		case 3 :
		printf(" How many commission worker worked this week?\n");
		scanf("%d",&cw);
		printf("\n How many product sold from each commision worker this week?\n");
		scanf("%d",&cws);
		printf("\nHow much dollar a product that workers sold?\n");
		scanf("%d",&ps);
		cwss= (cw*250)+(cws*ps*(5.7)/100);
		printf("\n\nYou will totally pay %.1f dollar for commission workers.\n\n",cwss);
		break;
		
		
		case 4:
		printf("How many pieceworker worked this week?\n");
		scanf("%d",&pw);
		printf("\nHow many item produced from each pieceworker?\n");
		scanf("%d",&ipw);
		printf("\nHow much dollar earn a pieceworker for a item?\n");
		scanf("%d",&cp);
		pws= pw*ipw*cp;
		printf("\n\nYou will totally pay %d dollar for pieceworkers.",pws);
		break;
		
	
			
	}
	tekrar:
	printf("\n\nDo you want to use program again? [yes=1] [no=2] ");
	scanf("%d",&a);
	
	if (a==1) {
		goto basadon;
		
	}
	else if (a==2)
	{ printf("\n\nHave nice day boss");
	
	return 0;
		
	}
		
	
	else printf("\n\nYour choose is wrong try again.");
	  goto tekrar;
	
	
	return 0;
	}
	
	

	
	
	
	
	
	

#include <stdio.h>
#include <stdlib.h>
int main()
	{
	int choice;  			int hws; 	int pw;
	int salfmngr;			int hwss;	int ipw;
	int hsalfmngr;			int cw;		int cp;
	int sm;					int cws;	int pws;
	int hw;					int ps;		int a;
	int hwc;				float cwss;  
	
	printf("Welcome to payment program.\n\n");
	
	basadon:
	
	printf("Please choose your paycode:\n\n [1] for Managers\n [2] for Hourly Workers\n [3] for Commission Workers\n [4] for Pieceworkers.\n\n\n");
	scanf("%d",&choice);

	
		switch(choice) 
		{
		
		
		  case 1 :
		  printf("How much dollar do you pay per a week for each manager?\n");
		  scanf("%d",&salfmngr);
		  printf("\nHow many managers worked this week?\n");
		  scanf("%d",&hsalfmngr);
		  sm= salfmngr*hsalfmngr;
		  printf("\n\nYou will totally pay %d dollar for managers.\n\n",sm);
		  break;
		 
		 case 2 :
		 printf("How much dollar do you pay per a hour for each hourly worker?\n");
		 scanf("%d",&hw);
		 printf("\nHow many hourly workers worked this week?\n");
		 scanf("%d",&hws);
		 printf("\nHow many workers worked this week?\n");
		 scanf("%d",&hwc);
		
		 	if (hws<=40) 
			{
		    hwss =+ hws*hw*hwc;
		    printf("\n\nYou will totally pay %d dollar for hourly workers.\n\n",hwss);
			}
		
			else
			{
					hwss=+ (40*hw*hwc)+((hws-40)*hw*(3/2)*hwc);	
				 	printf("\n\nYou will totally pay %d dollar for hourly workers\n\n.",hwss); 
			}
			break;
		
		case 3 :
		printf(" How many commission worker worked this week?\n");
		scanf("%d",&cw);
		printf("\n How many product sold from each commision worker this week?\n");
		scanf("%d",&cws);
		printf("\nHow much dollar a product that workers sold?\n");
		scanf("%d",&ps);
		cwss= (cw*250)+(cws*ps*(5.7)/100);
		printf("\n\nYou will totally pay %.1f dollar for commission workers.\n\n",cwss);
		break;
		
		
		case 4:
		printf("How many pieceworker worked this week?\n");
		scanf("%d",&pw);
		printf("\nHow many item produced from each pieceworker?\n");
		scanf("%d",&ipw);
		printf("\nHow much dollar earn a pieceworker for a item?\n");
		scanf("%d",&cp);
		pws= pw*ipw*cp;
		printf("\n\nYou will totally pay %d dollar for pieceworkers.",pws);
		break;
		
	
			
	}
	tekrar:
	printf("\n\nDo you want to use program again? [yes=1] [no=2] ");
	scanf("%d",&a);
	
	if (a==1) {
		goto basadon;
		
	}
	else if (a==2)
	{ printf("\n\nHave nice day boss");
	
	return 0;
		
	}
		
	
	else printf("\n\nYour choose is wrong try again.");
	  goto tekrar;
	
	
	return 0;
	}
	
	

	
	
	
	
	
	
