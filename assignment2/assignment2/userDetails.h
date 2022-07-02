struct userDetails{
	unsigned long social_security_number;
	unsigned long card_number;
	unsigned long cvv_number;
	char dob[10];
	char address[100];
	char full_name[50];
	char name_printed[20];
	char email[30];
	char card_expiry_date[10];
	char card_issue_date[10];
};

void printData(struct userDetails u1){
	printf("Social Security Number = %lu\n",u1.social_security_number);
	printf("Card Number = %lu\n",u1.card_number);
	printf("CVV Number = %lu\n",u1.cvv_number);
	printf("Date of Birth = %s\n",u1.dob);
	printf("Address = %s\n",u1.address);
	printf("Full Name = %s\n",u1.full_name);
	printf("Name Printed = %s\n",u1.name_printed);
	printf("Email = %s\n",u1.email);
	printf("Card Issue Date = %s\n",u1.card_issue_date);
	printf("Card Expiry Date = %s\n",u1.card_expiry_date);
	printf("\n");
}

