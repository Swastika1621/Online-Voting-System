#include<stdio.h>

struct candidate{
    char name[50], simbol[50];
    int vote;

} participent[50];

int input_Candidate_Data(void){
    int num,choise,condition=1,i;

    printf("Enter how meny candidate are participeting : ");
    scanf("%d",&num);

    printf("\n\nEnter the details : \n");
    for(i=1; i<=num; i++){

        printf("%2d : Name : ",i);
        scanf("%s",participent[i].name);

        
        printf("\tSymbol : ");
        scanf("%s",participent[i].simbol);
    }

    printf("\n\nThe Paricipents are complitly Saved in Database\n\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@_\n\n");
    return num;
}

void Display_All_Candidates(int num){
    int i;
    printf("| SI NO |      Name     |  Symbol  |\n");
    for(i=1; i<=num; i++){
        printf("|%7d|%15s|%10s|\n",i,participent[i].name,participent[i].simbol);
    }
}

void Get_Vote(int num){
    int SI;

    printf("Enter the SI NO of your Vote : ");
    scanf("%d",&SI);

    //SI--;
    
    if((SI<=0) || (SI>num)){
        printf("\n\nThe Candidet Not Exisit\n");
    }
    else{
        participent[SI].vote++;
    }
}

void Get_Result(int num, int vote){
    int max,pos,i;

    printf("\n\n\nThe Result of All Camdidates :\n\n");
    printf("| SI NO |      Name     |  Symbol  | Votes |\n");
    for(i=1; i<=num; i++){
        printf("|%7d|%15s|%10s|%7d|\n",i,participent[i].name,participent[i].simbol,participent[i].vote);
    }
    printf("\n\n");
    
}

int main(){
    int chois,condition=1,max,pos,i;

    int num,vote=0;
    num = input_Candidate_Data();

    while (condition!=0)
    {
        printf("\n\nEnter the Choice\n");
        printf("1 : Want to vote\n");
        printf("2 : Display Result\n");
        scanf("%d",&chois);

        if(chois==1){
            vote++;
            Display_All_Candidates(num);
            Get_Vote(num);
        }

        else if(chois==2){
            Get_Result(num,vote);
            condition=0;
        }

        else{
            printf("Enter Properly : \n");
            vote--;
        }
    }

    max=participent[1].vote, pos=1;

    for(i=1; i<=num; i++){
        if(participent[i].vote > max){
            max=participent[i].vote;
            pos=i;
        }
    }

    printf("The Winner Of This Votting is\n");
    printf("| SI NO |      Name     |  Symbol  | Votes |\n");
    printf("|%7d|%15s|%10s|%7d|\n",pos,participent[pos].name,participent[pos].simbol,participent[pos].vote);
        

    printf("\n\n\nIN THIS ELECTION %d CITIZENS ARE DEDICATED THIER VOTE'S\n\n\n",vote);
    return 0;
}
