#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "userDetails.h"

int mx_size=1024;

int hashFunction(unsigned long idx){
	int sq=0, temp=idx;
	
	while(temp){
		int rem = temp%10;
		sq += (rem*rem);
		temp/=10;
	}

	sq = sq%mx_size;
	
	return sq;
}

struct node{
	struct userDetails data;
	struct node *next;
};

void insertion(struct node **hashMap, struct userDetails u1){
	
	unsigned long cn = u1.card_number;
	int idx = hashFunction(cn);

	struct node* n1 = malloc(sizeof(struct node));
	
	if(n1==NULL){
		fprintf(stderr,"Error with malloc while node creation.\n");
		exit(1);
	}
	
	n1->data = u1;
	n1->next = NULL;
	
	if(hashMap[idx]==NULL){
		hashMap[idx] = n1;
		return ;
	}

	struct node* temp = hashMap[idx];
					
	while(temp->next!=NULL){
		temp=temp->next;
	}

	temp->next=n1;

	return ;
}

void deletion(struct node **hashMap, int cn){
	int idx = hashFunction(cn);

	struct node* temp = hashMap[idx], *toDelete;
	
	if(temp->data.card_number==cn){
		toDelete=temp;
		hashMap[idx]=temp->next;
	}else{

		while(temp->next!=NULL){
			if(temp->next->data.card_number==cn){
				toDelete=temp->next;
				temp->next=toDelete->next;
				break;
			}
			temp=temp->next;
		}

	}
	
	toDelete->next=NULL;
	free(toDelete);
}

void printAllData(struct node **hashMap){
	
	for(int i=0; i<mx_size; i++){
		if(hashMap[i]!=NULL){
			printf("Id: %d\n",i+1);
			struct node* temp=hashMap[i];
			while(temp!=NULL){
				printData(temp->data);
				temp=temp->next;
			}
			
		}
	}
}

struct userDetails createUser(){
	struct userDetails u1;;

	printf("Enter Social Security Number:");
	scanf("%lu",&u1.social_security_number);
	
	printf("Enter Card Number:");
	scanf("%lu",&u1.card_number);
	
	printf("Enter CVV Number:");
	scanf("%lu",&u1.cvv_number);
	fgetc(stdin);
	
	printf("Enter Date of Birth:");
	fgets(u1.dob,sizeof(u1.dob),stdin);
	u1.dob[strlen(u1.dob)-1]=0;
	
	printf("Enter Address:");
	fgets(u1.address,sizeof(u1.address),stdin);
	u1.address[strlen(u1.address)-1]=0;
	
	printf("Enter Full Name:");
        fgets(u1.full_name,sizeof(u1.full_name),stdin);
	u1.full_name[strlen(u1.full_name)-1]=0;
	
	printf("Enter Name Printed:");
	fgets(u1.name_printed,sizeof(u1.name_printed),stdin);
	u1.name_printed[strlen(u1.name_printed)-1]=0;

	printf("Enter Email:");
	fgets(u1.email,sizeof(u1.email),stdin);
	u1.email[strlen(u1.email)-1]=0;

	printf("Enter Card Issue Date:");
	fgets(u1.card_issue_date,sizeof(u1.card_issue_date),stdin);
	u1.card_issue_date[strlen(u1.card_issue_date)-1]=0;

	printf("Enter Card Expiry Date:");
	fgets(u1.card_expiry_date,sizeof(u1.card_expiry_date),stdin);
	u1.card_expiry_date[strlen(u1.card_expiry_date)-1]=0;

	return u1;
}

int main(){
	int n=4;
	
	struct node **hashMap = malloc(mx_size*sizeof(struct node*));
	
	if(hashMap==NULL){
		fprintf(stderr,"Error with malloc return value\n");
		exit(1);
	}

	memset(hashMap,0,mx_size*sizeof(hashMap));

	//struct userDetails arr[n];
	/*
	for(int i=0; i<n; i++){
		struct userDetials u1 = createUser();
		insertion(hashMap,u1);
	}

	printf("\n\n");	
	
	printAllData(hashMap);
	
	unsigned long cn=1234567890123456;
	int idx = hashFunction(cn);
	deletion(hashMap,idx,cn);
	printf("--------------------------------------------------------------\n");	
	printAllData(hashMap);
	*/
	int op;
	do{
		printf("1.Enter 1 for insertion.\n");
		printf("2.Enter 2 for deletion.\n");
		printf("3.Enter 3 for printing all data.\n");
		printf("4.Enter 4 for exit.\n");
		scanf("%d",&op);
		printf("\n");
		struct userDetails u;
		unsigned long idx;

		switch(op){
			case 1: 
				 u = createUser();
				insertion(hashMap,u);
				break;
			case 2:
				printf("Enter the card number of user to be deleted:");
				scanf("%lu",&idx);			
				deletion(hashMap,idx);	
				break;
			case 3:
				printAllData(hashMap);
				break;
			case 4:
				exit(0);
			default:
				printf("Enter valid option:\n");
		}

		printf("\n");
	}while(op!=4);

	for(int i=0; i<mx_size; i++){
		free(hashMap[i]);
		hashMap[i]=NULL;
	}

	free(hashMap);
	hashMap=NULL;
	
	return 0;
}

