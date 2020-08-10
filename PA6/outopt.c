#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number=0;

struct expr
{
  char op[4],op1[5],op2[5],res[5];
  int flag;

}arr[100];


char alloptcode[30][30];


void structregister(){

	int i=0;
	char *token;
	for(i=0; i<number; i++){
		
		//printf("%s\n",alloptcode[i]);

		token=strtok(alloptcode[i]," ");
		strcpy(arr[i].res, token);
		token=strtok(NULL, " ");
		token=strtok(NULL, " ");
		strcpy(arr[i].op1, token);
		token=strtok(NULL, " ");
	
		strcpy(arr[i].op, token);

		token=strtok(NULL, " ");

		strcpy(arr[i].op2, token);
		strcpy(token, "");

	}

}

void printregistered(){

	int i=0;
	for(i=0; i< number; i++){

		 printf("\n%s %s %s %s",arr[i].res,arr[i].op1,arr[i].op,arr[i].op2);
	}

}



void choose(char *buf){

	char *eq="==";
	char *lt=">";
	char *gt="<";
	//printf("see buf here : %s\n", buf);
	int flag=0;
	char copy[strlen(buf)];
	strcpy(copy, buf);
	char *token= strtok(buf, "\t");

	//printf("token in the choose : %s\n", token);

	if(token[0]=='$' && token[1]=='t'){
		flag=1;
	}
	//printf("printing flag : %d\n", flag);
	//printf("printing copy %s\n", copy);
	char optimizethis[50]="";
	if(flag==1){

		strcpy(token, "");
		token=strtok(copy, "\t");
		while(token!=NULL){

			if(strcmp(token, eq)==0 || strcmp(token, lt)==0 || strcmp(token, gt)==0){
				flag=0;
				break;
			}
			else{

				strcat(optimizethis, token);
				strcat(optimizethis, " ");
			}
			token=strtok(NULL, "\t");
		}
	}
	if(flag==1){
		
		//printf("\n\n\nprinting code to optimize : %s\n\n\n", optimizethis);
		strcpy(alloptcode[number], optimizethis);
		number=number+1;
	}
}


void change(int p,int q,char *res)
{
  int i;
  for(i=q+1;i<number;i++)
  {
    if(strcmp(arr[q].res,arr[i].op1)==0)
      if(res == NULL)                         //for csub
        strcpy(arr[i].op1,arr[p].res);
      else                                    //for ceval
        strcpy(arr[i].op1,res);                  
    else if(strcmp(arr[q].res,arr[i].op2)==0)
      if(res == NULL)                         //for csub
        strcpy(arr[i].op2,arr[p].res);
      else                                    //for ceval
        strcpy(arr[i].op2,res);
  }
}

void constant()
{
  int i;
  int op1,op2,res;
  char op,res1[5];
  for(i=0;i<number;i++)
  {
  	
  	/*printf("in the loop of constant\n");
  	printf("op1 : %d\n", op1);
	printf("op2 : %d\n", op2);
	printf("op : %c\n", op);*/
    if(isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0])) //if both digits, store them in variables
    {
      op1=atoi(arr[i].op1);
      //printf("printing op1 : %d\n", op1);
      op2=atoi(arr[i].op2);
      //printf("printing op2 : %d\n", op2);
      op=arr[i].op[0];
      //printf("printing op : %c\n", op);
      switch(op)
      {
        case '+':
          res=op1+op2;
          break;

        case '-':
          res=op1-op2;
          break;

        case '*':
          res=op1*op2;
          break;

        case '/':
          res=op1/op2;
          break;
      }
      sprintf(res1,"%d",res);                              
      arr[i].flag=1; //eliminate expr and replace any operand below that uses result of this expr
     // printf("comes before calling change \n");
      change(i,i,res1);
      op='\0';
      strcpy(res1, "");
    }
  }
}


void expression()
{
  int i,j;
  for(i=0;i<number;i++)
  {
    for(j=i+1;j<number;j++)
    {
      if(strcmp(arr[i].op,arr[j].op)==0) //if operators are same
      {
        if(strcmp(arr[i].op,"+")==0||strcmp(arr[i].op,"*")==0) //order doesn't matter if operators are + or *
        {
          if(strcmp(arr[i].op1,arr[j].op1)==0&&strcmp(arr[i].op2,arr[j].op2)==0 || strcmp(arr[i].op1,arr[j].op2)==0&&strcmp(arr[i].op2,arr[j].op1)==0)  
          {
            arr[j].flag=1; //does't print
            change(i,j,NULL); //change any operand below that uses result of this expression
          }
        }
        
        else                   
        {
          if(strcmp(arr[i].op1,arr[j].op1)==0&&strcmp(arr[i].op2,arr[j].op2)==0)
	          {
            arr[j].flag=1;
            change(i,j,NULL);
          }
        }
      }
    }
  }
}


void output()
{
  int i=0,j=0;
  printf("\n\nOptimized expressions-----------------------------------------\n\n");
  for(i=0;i<number;i++)
  {

    if(1)
    {
      //printf("just about to print \n");
      printf("%d : %s = %s %s %s\n", j, arr[i].res,arr[i].op1,arr[i].op,arr[i].op2);
      j=j+1;
    }
  }
}




void finalfunc(){

	constant();
	expression();
	output();
}

int main(void){


	int Labels[100000];
	char buf[100];
	FILE *f1=fopen("output","r");
	int flag=0,lineno=1;
	memset(Labels,0,sizeof(Labels));
	
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
	
		choose(buf);
		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			int k=atoi(&buf[3]);
			//printf("hi %d\n",k);
			Labels[k]=lineno;
		}
		else
		{
			lineno++;
		}
	}
	fclose(f1);



	f1=fopen("output","r");
	lineno=0;

	//printf("\n\n\n*********************InterMediate Code***************************\n\n");
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{

		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			;
		}
		else
		{
			flag=0;
			lineno++;
			//printf("%3d:\t",lineno);
			int len=strlen(buf),i,flag1=0;
			for(i=len-3;i>=0;i--)
			{
				if(buf[i]=='$'&&buf[i+1]=='$'&&buf[i+2]=='L')
				{
					flag1=1;
					break;
				}
			}
			if(flag1)
			{
				buf[i]=='\0';
				int k=atoi(&buf[i+3]),j;
				//printf("%s",buf);
				//for(j=0;j<i;j++)
					//printf("%c",buf[j]);
				//printf(" %d\n",Labels[k]);
			}
			//else printf("%s",buf);
		}
	}
	//printf("%3d:\tend\n",++lineno);
	fclose(f1);
	structregister();
	

	//printf("final function called : \n");

	finalfunc();

}
