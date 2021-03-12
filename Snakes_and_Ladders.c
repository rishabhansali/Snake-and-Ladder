#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
Use of File handling to save the game and resuming it from previously save point.
Random selection of six different combinations of snakes as well as six different ladders every time the game runs.
A player gets a green signal only if he gets 1 or 6 as dice value.
A player gets a consecutive turn if he gets 6 as dice value
*/
 
int ladlower[6]={0,0,0,0,0,0},ladupper[6]={0,0,0,0,0,0},snalow[6]={0,0,0,0,0,0},snaup[6]={0,0,0,0,0,0};
void dissal(int pl,int comp)
{
    if(pl<comp)
                {
                    printf("Yipee you got a ladder to %d",comp);
                }
                else if(pl>comp)
                {
                    printf("oops snake has eaten you to position %d",comp);
                }
}
int checkforsal(int player)
{
    int i,pos;
  for(i=0;i<6;i++)
  {
      if (player==ladlower[i])
      {
          pos=ladupper[i];
          break;
      }
      else if(player==snaup[i])
      {
          pos=snalow[i];
          break;
      }
      else
      {
          pos=player;
      }
  }
  return pos;
}
void main()
{
    int temp,di=0, fturn1=1, pocket=0;
	int j=0;
	FILE *f;
	char ch,get;
	int state=0;

printf("Would you like to:\n    1)Read the rules\n    2)Play the game\n\n");
scanf("%d", &ch);
       
if (ch==1){printf("\nThe rules are simple: \n   You press enter to roll the die\n   You are then told which space you have landed on\n   If you land on a snake you will move down the board\n   If you land on a ladder then you will move up it\n   In order to win you must land on 64 exactly\n   If you go over 64 then your imaginary piece will be moved backwards for the remainder of your dice roll\n\n Good Luck\n\n");}
if (ch==1,2){
       
       
      printf("\nWelcome to Snakes and Ladders.\n");
	  printf("\n100  99  98  97  96  95  94  93  92  91\n");
      printf(" 81  82  83  84  85  86  87  88  89  90\n");
      printf(" 80  79  78  77  76  75  74  73  72  71\n");
      printf(" 61  62  63  64  65  66  67  68  69  70\n");
      printf(" 60  59  58  57  56  55  54  53  52  51\n");
      printf(" 41  42  43  44  45  46  47  48  49  50\n");
      printf(" 40  39  38  37  36  35  34  33  32  31\n");
      printf(" 21  22  23  24  25  26  27  28  29  30\n");
      printf(" 20  19  18  17  16  15  14  13  12  11\n");
      printf("  1   2   3   4   5   6   7   8   9  10\n");                       /*Prints the board for user's reference*/
      
	
	while(1)
	{
	    printf("Press 1 to start new game\n");
	fflush(stdin);
	srand(time(NULL));
	get=getchar();
	if(get=='1')
	{
	    state=0;
	}
	else
	{
	        continue;
	}

	if (state==0)
	{
		//number of players
	      int players, i;
	      while(1){
		      printf("\nEnter the number of players: ");
			  scanf("%d", &players);
			  if(players>=2){
			  	break;
			  }
			  else{
			  	printf("\nMinimum 2 players required. Please try again.\n");
			  }
		  }
		  int p[players], fp[players];
		
		int winner, f=0;
	   for( i = 0 ; i < 6 ; i++ )
	
	     {
	
	         j=0;
	
	     ladlower[i]=(rand()%90)+1;
	       ladupper[i]=((ladlower[i]+(rand()%100)+1)%99)+1;
	       snalow[i]=(rand()%90)+1;
	       snaup[i]=((snalow[i]+(rand()%100)+1)%99)+1;
	       if(ladlower[i]>ladupper[i])
	       {
	           temp=ladlower[i];
	           ladlower[i]=ladupper[i];
	           ladupper[i]=temp;
	       }
	       if(snalow[i]>snaup[i])
	       {
	           temp=snalow[i];
	           snalow[i]=snaup[i];
	           snaup[i]=temp;
	       }
	       if(ladupper[i]-ladlower[i]<9&&ladupper[i]<90)
	       {
	           ladupper[i]=ladupper[i]+10;
	       }
	       if(snaup[i]-snalow[i]<9&&snaup[i]<90)
	       {
	           snaup[i]=snaup[i]+7;
	       }
	
	       if(ladupper[i]==snalow[i]||ladupper[i]==snaup[i]
	          ||ladlower[i]==snaup[i]||ladlower[i]==snalow[i])
	       {
	           i=i-1;
	           continue;
	       }
	       while(j<i)
	       {
	                if(ladupper[j]==snaup[i]||ladlower[j]==snalow[i]||ladlower[j]==snaup[i]||
	              snalow[j]==snaup[i]||snaup[j]==snaup[i]||snalow[j]==snalow[i]||ladlower[j]==ladlower[i]
	              ||ladupper[j]==ladupper[i])
	           {
	               i=i-1;
	               continue;
	
	           }
	           j++;
	       }
	     }
	     printf("\n\t Ladders\t\t Snakes\n");
	    for(i=0;i<6;i++)
	    {
	        printf("%d\t%02d--->%02d",i+1,ladlower[i],ladupper[i]);
	        printf("\t\t%02d--->%02d\n",snaup[i],snalow[i]);
	    }
	    for(i=0;i<players;i++){      
			p[i]=0;
			fp[i]=0;
		}
	
		while(1){
			for(i=0; i<players; i++){
				if(p[i]==100){
					winner=i+1;
					f=1;
					break;
				}
			}
			if(f==1){
				printf("\n--------------------------------\n");
				printf("Player %d won!!\n", winner);
				printf("G A M E  O V E R\n");
				printf("--------------------------------\n");
//				f=0;
				break;
			}
			else{
			    printf("\nPress a to restart the game");
				printf("\nPress q to quit");
				for(i=0; i<players; i++){
				        printf("\nPlease press r to roll the dice");
				        printf("\n--------------------------------");
				        printf("\nPlayer %d turn:\n", (i+1));
				        printf("Give choice: ");
				        fflush(stdin);
				        ch=getchar();
					if(ch=='r')
			        {
			            di=(rand()%6)+1;
			            printf("\nWooo!You got %d ",di);
			            if(p[i]==0&&(di==1||di==6))
			               {
			                   fp[i]=1;
			                   printf("\nYeah you are good to go....");
			               }
			            if(fp[i]==1&&di==6)
			            {
			                fturn1=1;
			                p[i]=p[i]+6;
			                pocket=checkforsal(p[i]);
			                dissal(p[i],pocket);
			                p[i]=pocket;
			            }
			            else if(fp[i]==1&&di!=6)
			            {
			                fturn1=0;
			                p[i]=p[i]+di;
			                pocket=checkforsal(p[i]);
			                dissal(p[i],pocket);
			                p[i]=pocket;
			            }
			            else if(fp[i]==0)
			            {
			                printf("\nSorry,you need 1 or 6 to get a green signal\n");
			                fturn1=0;
			                p[i]=0;
			            }
			            if(p[i]>100)
			            {
			                printf("Sorry you cannot cross 100\n");
			                p[i]=p[i]-di;
			            }
			            int k;
			            for(k=0; k<players; k++){
			            	printf("\nPlayer %d at position %02d",(k+1), p[k]);	
						}
						if(p[i]==100){
							winner=i+1;
							f=1;
							break;
						}  
			        }
			        else if(ch=='q')
			        {
			        	printf("\t\t\t\t\nGAME EXITED\n\t\t\t\t");
			            exit(0);
			        }
			        else if(ch=='a')
			        {
			            state=0;
			            for(i=0;i<players;i++){      
							p[i]=0;
							fp[i]=0;
						}
						printf("\n\t\t\t\tGAME RE-STARTED\t\t\t\t\n");
			            break;
			        }
			        else
					{
						printf("Invalid choice. Try again");
						i--;
					}
					printf("\n-------------------------------------------");
				}

				
		}	
		  
	}
	}

}
}
}
 



