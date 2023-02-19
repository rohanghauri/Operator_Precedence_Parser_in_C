//@Auth M.Rohan Ghauri
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	int MAXSIZE = 50;       
	int stack[50];     
	int top = -1; 
	

	int getTop(){
		return top;
	}
	
	int checkRelation(int stackChar,int inputChar)
	{
	int x,y = 0;
	//62->,60-<,404-,401-Accept
	int ParseTable[6][6] = {
		{62,60,60,62,60,62},//+
		{62,62,60,62,60,62},//*
		{60,60,60,404,60,404},//(
		{62,62,404,62,404,62},//)
		{62,62,404,62,404,62},//id
		{60,60,60,60,60,401},//$
	};           
	//[stackChar][inputChar]
	if (stackChar == 43){x = 0;}
	if (stackChar == 42){x = 1;}
	if (stackChar == 40){x = 2;}
	if (stackChar == 41){x = 3;}
	if (stackChar == 105){x = 4;}
	if (stackChar == 36){x = 5;}
	//------------------------------
	if (inputChar == 43){y = 0;}
	if (inputChar == 42){y = 1;}
	if (inputChar == 40){y = 2;}
	if (inputChar == 41){y = 3;}
	if (inputChar == 105){y = 4;}
	if (inputChar == 36){y = 5;}
	return ParseTable[x][y];
}

int giveTerminal(){//int *ptrStack){
	//int tempStack[50];
	int z = 0;
	int mytop = getTop();
	//printf("%d---mytop");
	int terminal;
	//printf("%d---giveTerminal\n",mytop);
	while(mytop!=-1){
		if (stack[top] == 43  ||stack[top] == 42 ||stack[top] == 40 ||stack[top] == 41 ||
		stack[top] == 105 ||stack[top] == 36){
		//return ptrStack[mytop];
		 terminal = stack[top];				
		}	
		mytop = mytop-1;
	}	
	return terminal;
}	
	
	

	int isempty() 
	{
   	if(top == -1)
    	  return 1;
   	else
    	  return 0;
	}
   
	int isfull() 
	{
   	if(top == MAXSIZE)
      return 1;
   else
      return 0;
	}

int peek() {
   return stack[top];
}

int pop() {
   int data;
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}


int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}
void callReduce(){
	int mytop = getTop();
	int popTime = 0;
	int pushElement = 0;
	
	int prod1[10] = {69,69,43,84};
	int prod2[10] = {69,84};
	int prod3[10] = {84,84,42,70};
	int prod4[10] = {84,70};
	int prod5[10] = {70,40,69,41};
	int prod6[10] = {70,105};
	
	
	if (mytop >= 3){//Stack can have elements that can be replaced by a production contaning 3 elements and 1
		int item = stack[mytop];
		if (item == prod6[1]){
			//printf("%c--from 1st rule\n",70);
			popTime = 1;
			pushElement = 70;
			}
		if (item == prod4[1]){
			//printf("%c-- from 1st rule\n",84);
			popTime = 1;
			pushElement = 84;
			}
		if (item == prod2[1]){
			//printf("%c-- from 1st rule\n",69);
			popTime = 1;
			pushElement = 69;
			}	
		if (item == prod1[3] && stack[mytop-1]==prod1[2] && stack[mytop-2] == prod1[1]){
			//printf("%c--from 3rule\n",69);
			popTime = 3;
			pushElement = 69;
		}
		if (item == prod3[3] && stack[mytop-1]==prod3[2] && stack[mytop-2] == prod3[1]){
			//printf("%c--from 3rule\n",84);
			popTime = 3;
			pushElement = 84;
		}
		if (item == prod5[3] && stack[mytop-1]==prod5[2] && stack[mytop-2] == prod5[1]){
			//printf("%c--from 3rule\n",69);
			popTime = 3;
			pushElement = 69;
		}
	}
	else{
		int item = stack[mytop];
		if (item == prod6[1]){
			//printf("%c--from 1st rule\n",70);
			popTime = 1;
			pushElement = 70;
			}
		if (item == prod4[1]){
			//printf("%c-- from 1st rule\n",84);
			popTime = 1;
			pushElement = 84;
			}
		if (item == prod2[1]){
			//printf("%c-- from 1st rule\n",69);
			popTime = 1;
			pushElement = 69;
			}	
	}
	//printf("%c",prod1[2]);
	for(int v = 0 ;v < popTime;v++){
		pop();
	}
	push(pushElement);
	//printf("%c",tempStack[1]);
	

}
	push(36);//Pushing dollar into the empty stack
	int x = 0 ;
	int noInc = 0;
	int v = 0;
	while(argv[1][x]!= 0){
	int noInc = 0;
	 
	 int stackChar = giveTerminal();
	 	int rel = checkRelation(stackChar,argv[1][x]);//Returns weather we have to shift or reduce
	 	//printf("%d-- Gives Relation\n",rel);
	 	printf("\n%c--StackChar|%c--InputChar\n",stackChar,argv[1][x]);
	 	if(stackChar==36 &&argv[1][x]==41){
	 	printf("String Accepted\n");
	 		break;
	 	}
	 	else if (rel == 60){
	 		printf("Shift");
	 		push(argv[1][x]);//Shift Func
	 	}
	 	else if (rel==62){
	 		noInc = 1;
	 		printf("Reduction");
	 		callReduce();
	 		
	 	}
	 	else if(rel==404){
	 		printf("String Rejected\n");
	 		break;	
	 	}//For dash relation)*/
	 	else if(rel==401){
	 		printf("String Accepted\n");
	 		break;
	 	}
	 
	 if(argv[1][x] == 105 && noInc == 0){
	 	x = x + 2;
	 }
	 else{	
	 	if (noInc == 0){x++;}
	 }
	
	}
	
	



}
