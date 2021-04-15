#include <stdio.h>
#include "fun.h"
void insertValue(int i, int j, unsigned char user);
unsigned char isFUll();
unsigned char isOver();
unsigned char mat[3][3]={'_','_','_','_','_','_','_','_','_'};
unsigned char userturn=0;

// MAin Function//
int main(){
	unsigned char user1[30],user2[30],winner;
	int ival, jval;
	
	printf("\nEnter the name of Player 1:");
	scanf("%s",&user1);

	printf("\nEnter the name of Player 2:");
	scanf("%s",&user2);

	again:
	printf("\n\n");
	printMatrix();
	winner=isOver();

	if(winner){
		printf("\n ********* Congratulations %s \n ----You have won the game! ------",((winner=='X')?user1:user2));
		goto end;
}
	if(!isFUll){
		printf("\n **** Game Over! ***");
		goto end;
	}

	repeat:
	printf("\n **** Player (%s) turn, Enter value (00-22) : ",(userturn==0?user1:user2));
	scanf("%d%d",&ival,&jval);
	
	if((ival>2 || ival<0) || (jval>2 || jval<0)){
		printf("\n *** Error: Invalid Indices, Try Again!");
		goto repeat;
	}

	if(mat[ival][jval]!='_'){
		printf("\n *** Error: Already Filled, Try Again!");
		goto repeat;

	}
	insertValue(ival,jval,userturn);
	userturn=!userturn;
	goto again;

	end:
	printf("\n");

	return 0;
}

// print matrix



// void insertValue

void insertValue(int i, int j, unsigned char user){
	mat[i][j]=((user==0)?'X':'O');


}

// CHecking Matrix Full

unsigned char isFUll(){
	unsigned char i,j,count=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(mat[i][j]=='_'){
				++count;
			}
			
		}
	}
}

// Game over
unsigned char isOver(){
	unsigned char i,j,user;
	unsigned char storeChar=0, dfstoreChar=0, dsstoreChar=0;
	int sum=0, dfsum=0, dssum=0;

	// Sum of X+X+X is 264 and O+O+O is 237
	// case 1
	for(i=0;i<3;i++){
		sum=0;
		for(j=0;j<3;j++){
			if(mat[i][j]=='_') break;
			sum=sum+mat[i][j];
			storeChar= mat[i][j];

		}
		if(sum==237 || sum ==264){
			return storeChar;
		}
	}
	// case 2
	for(i=0;i<3;i++){
		sum=0;
		for(j=0;j<3;j++){
			if(mat[j][i]=='_') break;
			sum=sum+mat[j][i];
			storeChar= mat[j][i];

		}
		if(sum==237 || sum ==264){
			return storeChar;
		}
	}
	// case 3 (Diagonals)
	for(i=0;i<3;i++){
		// first diagonal
		for(j=0;j<3;j++){
			
			if(i==j){
			if(mat[i][j]=='_') break;
			dfsum=sum+mat[i][j];
			dfstoreChar= mat[i][j];
			}

		}
		if(sum==237 || sum ==264){
			return storeChar;
		}

		// Second Diagonal
		for(j=3;j>0;j++){
			if(i==2-j+1){
				if(mat[i][j-1]=='_') break;
				dssum= dssum+mat[i][j-1];
				dsstoreChar=mat[i][j-1];
			}
		}
		if(dfsum==237 || dfsum==264){
			return dfstoreChar;
		}
		else if (dssum==237 || dssum==264){
			return dsstoreChar;
		}
	}
	return 0;
}