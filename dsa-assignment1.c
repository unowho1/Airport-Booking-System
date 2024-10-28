#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

int business_class[5]={0,0,0,0,0},economy_class[5]={0,0,0,0,0};
int f[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},r[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

struct waiting_list{
    char name[20];
    int age;
    //int payment;
    int class;
    char food[20];
}queue[10][MAX];

struct linked_list{
    char name[20];
    int age;
    //int payment;
    int class;
    int time;
    char food[20];
    struct linked_list *next;
};

struct linked_list* head[5];
struct linked_list* temp[5];

void insertq(int i) 
{ 
    if(f[i]==-1 && r[i]==-1) 
    f[i]=0; 
    
    if(f[i]==0 && r[i]==MAX-1 || (f[i]==r[i]+1 && r[i]!=-1)) 
    printf("\nNo more seats are available.\n");
    else{ 
        if(r[i]==MAX-1){
            r[i]=-1;
        }
        r[i]++;
    }
    fflush(stdin);
    printf("Enter passenger's name: ");
    scanf("%[^\n]",queue[i][r[i]].name);
    printf("Enter passenger's age: ");
    scanf("%d",&queue[i][r[i]].age);
    fflush(stdin);
    int fd;
    printf("Enter food: ");
    printf("Enter 1 for Vegetarian and 2 for Non Vegetarian \n");
    scanf("%d",&fd);
    if(fd==1)
    {
        printf("\nBiryani 500");
        printf("\nBiryani 200");
        printf("\n");
        printf("\nSandwich");
    }
    else
    {

    }
    printf("Enter your choice:");
    scanf("%[^\n]",queue[i][r[i]].food);
    queue[i][r[i]].class=i%2+1;
}
void beg_insert(int i)
{
    struct linked_list *new=(struct linked_list*)malloc(sizeof(struct linked_list));
    printf("\nEnter 1 to select Business class");
    printf("\nEnter 2 to select Economy class");
    printf("\nEnter your choice : ");
    scanf("%d",&new->class);
    if(new->class==1)
    {
        business_class[i]++; //goto waiting list function
    }
    else
    {
        //if(economy_class[i]==3); //goto waiting list function
        economy_class[i]++;
    }
   
    printf("\n------------------------------------------------");
    printf("\nEnter all the details according to your passport");
    printf("Name : ");
    scanf("%s",new->name);
    printf("Age : ");
    scanf("%d",&new->age);
    printf("Time of Flight : ");
    scanf("%d",&new->time);
    printf("Food : ");
    scanf("%s",new->food);
    head[i]=new;
    new->next=NULL;
    temp[i]=new;
}
void display()
{
    int choice;
    printf("\nEnter the number to choose your flight ");
    printf("1 Ahmedabad(AMD) -> Delhi(DEL)\n");
    printf("2 Ahmedabad(AMD -> Mumbai(BOM)\n");
    printf("3 Ahmedabad(AMD) -> Bangalore(BLR)\n");
    printf("4 Ahmedabad(AMD) -> Chennai(MAA)\n");
    printf("5 Ahmedabad(AMD) -> Kolkata(CCU)\n");
    scanf("%d",&choice);

    struct linked_list *new=head[choice-1];
    while(new!=NULL)
    {
        printf("Name:%s\n",new->name);
        printf("Age:%d\n",new->age);
        //scanf("%d",&new->age);
        printf("Time of Flight:%d\n",new->time);
        //scanf("%d",&new->time);
        printf("Food:%s\n",new->food);
        //scanf("%s",new->food);
        new=new->next;
    }
}

void insert(int i)
{
    struct linked_list *new=(struct linked_list*)malloc(sizeof(struct linked_list));
    printf("\nEnter 1 to select Business class");
    printf("\nEnter 2 to select Economy class");
    printf("\nEnter your choice : ");
    scanf("%d",&new->class);
    if(new->class==1)
    {
        if(business_class[i]==3) //goto waiting list function
        {
            insertq(2*i);
            return;
        }    
        else business_class[i]++;
    }
    else
    {
        if(economy_class[i]==3) //goto waiting list function
        {
            insert(2*i+1);
            return;
        }    
        else economy_class[i]++;
    }
    printf("\n------------------------------------------------");
    printf("\nEnter all the details according to your passport");
printf("\nName : ");
    scanf("%s",new->name);
    printf("\nAge : ");
    scanf("%d",&new->age);
    printf("\nTime of Flight : ");
    scanf("%d",&new->time);
    printf("\nFood : ");
    scanf("%s",new->food);
    new->next=NULL;
    temp[i]->next=new;
    temp[i]=new;
}

void reservation()
{
    int total;
    printf("\nEnter number of tickets you want to book:");
    scanf("%d",&total);
    while(total--)
    {
        int choice;
        printf("\nEnter the number to choose your flight ");
        printf("1 Ahmedabad(AMD) -> Delhi(DEL)\n");
        printf("2 Ahmedabad(AMD -> Mumbai(BOM)\n");
        printf("3 Ahmedabad(AMD) -> Bangalore(BLR)\n");
        printf("4 Ahmedabad(AMD) -> Chennai(MAA)\n");
        printf("5 Ahmedabad(AMD) -> Kolkata(CCU)\n");
        scanf("%d",&choice);
        if(choice<=5 && choice>0)
        {
            if(head[choice-1]==NULL) beg_insert(choice-1);
            else insert(choice-1);
        }
        else{
            printf("Flight not available ! \n");
            total++;
        }
            
            
        }
}



int deleteq(struct linked_list *new,int i)
{
    strcpy(new->name,queue[i][f[i]].name);
    strcpy(new->food,queue[i][f[i]].food);
    new->age=queue[i][f[i]].age;
    if(f[i]==r[i]==-1){

    }
    else if(f[i]==r[i])
    {
        f[i]=-1;
        r[i]=-1;
    }
    else
    {
        f[i]++;
        if(f[i]==MAX)
        f[i]=0;
    }
}

void displayq()
{
    int j,i=0;
        if(i%2==0){
            printf("====BUSINESS CLASS IN FLIGHT %d====",i/2+1);
        }
        else{
            printf("====ECONOMY CLASS IN FLIGHT %d====",i/2+1);
        }
        if(r[i]>=f[i] && r[i]!=-1)
        {
            for(j=f[i];j<=r[i];j++)
            {
                printf("%s    ",queue[0][j].name);
            }
        }
        else if(r[i]==-1)
        printf("\nQueue is empty.\n");
        else
        {
            for(j=f[i];j<=MAX-1;j++)
            {
                printf("%s----",queue[0][j].name);
            }
            for(j=0;j<=r[i];j++)
            {
                printf("%s11111",queue[0][j].name);
            }
        }
        printf("===============================");
}


void cancellation(){
struct linked_list *head1;
char name1[20];
int ch;
    printf("\nEnter the number to choose your flight ");
    printf("1 Ahmedabad(AMD) -> Delhi(DEL)\n");
    printf("2 Ahmedabad(AMD -> Mumbai(BOM)\n");
    printf("3 Ahmedabad(AMD) -> Bangalore(BLR)\n");
    printf("4 Ahmedabad(AMD) -> Chennai(MAA)\n");
    printf("5 Ahmedabad(AMD) -> Kolkata(CCU)\n");
    scanf("%d",&ch);
    int i=ch-1;
printf("\nEnter your name : ");
scanf("%s",name1);
struct linked_list *temp1;

      //key found on the head node.
      //move to head node to the next and free the head.
      if(strcmp((head[i])-> name , name1)==0)
      {
         
            if(head[i]->class==1){
                if(f[2*i]==-1){
            temp1 = head[i];    //backup to free the memory
            head[i] = head[i]->next;
            free(temp1);
            }
            else{
                deleteq(head[i],2*i);
            }
            }
            else{
                if(f[2*i+1]==-1){
            temp1 = head[i];    //backup to free the memory
            head[i] = head[i]->next;
            free(temp1);
            }
            else{
                deleteq(head[i],2*i+1);
            }
            }
   
          printf("\nYour ticket has been cancelled successfully. You will receive your refund in a few hours.");      
  }
     

      else
      {
          struct linked_list *current  = head[i];
          while(current != NULL)
          {
              //if yes, we need to delete the current->next node
              if(strcmp(current->name , name1)==0)
              {
                  //temp1 = current;
                  //node will be disconnected from the linked list.
                  //current = current->next;
                  if(current->class==1){
                        if(f[2*i]==-1){
                    temp1->next = current->next;
                  }
                  else{
                    deleteq(current,2*i);
                  }
                  }
                  else{
                    if(f[2*i+1]==-1){
                    temp1->next = current->next;
                  }
                  else{
                    deleteq(current,2*i+1);
                  }
                  }
                  printf("\nYour ticket has been cancelled successfully. You will receive your refund in a few hours.");      
                  break;
              }
              else
              {
                temp1=current;
                current=current->next;
              }
             
      }
   
}
}
int main()
{
    //*head = new linked_list*[5];
    for(int i=0;i<5;i++) head[i]=NULL;
    for(int i=0;i<5;i++) temp[i]=NULL;
    
    int t=1;
    while(t>0){
    int opt;

    printf("\nWelcome to ABC Airlines");
    printf("\nPress the given numbers to avail for our facilities ");
    printf("\n---------------------------------------------------");
    printf("\n1 Book tickets");
    printf("\n2 Check your ticket status");
    printf("\n3 Cancel your ticket");
    printf("\n4 Check your waiting list status");
    
    printf("\nEnter choice: ");
    printf("\n");
// review feedback, help, waiting list full display, update, 
    scanf("%d",&opt);
    switch(opt)
    {
    case 1:
        reservation();
        break;
    case 2:
        display();
        break;
    case 3:
        cancellation();
        break;
    case 4:
        displayq();
        break;
    default:
        printf("Enter valid choice");
}
printf("\nEnter 0 To exit");
printf("\nElse enter 1");
scanf("%d",&t);
printf("\n---------------------------------------------------");
}
return 0;
}

