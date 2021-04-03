#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void choose();
void jumble();
char word[][10]={"abort","novel","ticks","taste","touch","king","unary","uncle","twins","usage","infix","execute","large","lough","disappera","bully","casual","forge","purse","introvert","ramp"};
int ps1=0,ps2=0;
char pw[10],qn[10],ans[0];
int tw=20;
void choose()
{
   int k,i;
   tw=tw-1;
   k=rand()%tw;
   strcpy(pw,word[k]);
   for(i=k;i<=tw;i++)
    strcpy(word[i],word[i+1]);
    return;
}

void jumble()
{
    char temp[10];
    strcpy(qn,"");
    strcpy(temp,pw);
    int x,y,len=strlen(pw),z;

    for(x=0;x<len;x++)
    {
        y=rand()%(len-x);
        //printf("\t%d\t",y);
        qn[x]=temp[y];
        for(z=y;z<(len-x);z++)
            temp[z]=temp[z+1];


    }

   return;

}
int main()
{
    char p1[20],p2[20];
    int b,m=10,t=1;
    printf("\nEnter the name of player 1: ");
    scanf("%s",p1);
    printf("\nEnter the name of player 2: ");
    scanf("%s",p2);
    while(1)
    {
      srand(time(0));
      choose();
      jumble();
      printf("\nJumbled word is: %s\n",qn);
      if (t%2==1)
      {
        printf("\n\t%s, Your turn: \n",p1);
        scanf("%s",ans);
        if(!strcmp(ans,pw))
            {
                ps1=ps1+1;
                printf("\nWright answer, Your new score is %d\n",ps1);
            }
        else
            printf("\nWrong! Answer= %s , score=%d\n",pw,ps1);

        printf("\n----------------------------------------------------------------\n");

        }
        else
        {
           printf("\n\t%s, Your turn.",p2);
        scanf("%s",ans);
        if(!strcmp(ans,pw))
            {
                ps2=ps2+1;
                printf("\nWright answer, Your new score is %d\n",ps2);
            }
        else
            printf("\nWrong! Answer= %s , score=%d\n",pw,ps2);
        printf("\n----------------------------------------------------------------\n");
        printf("\n\nPress 1 to continue and 0 to exit:");
        scanf("%d",&b);
        printf("\n----------------------------------------------------------------\n");
        if((b==0)||(m==1))
        {
            if (ps1>ps2)
                printf("\n%s Won\n",p1);
            else
                printf("\n%s Won\n",p2);
            printf("Thank you! %s and %s...\n\t your scores are %d and %d respectively",p1,p2,ps1,ps2);
            break;
        }

        }

    t++;
    }
    return 0;
}
