#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
void main(){
	int i,number,ch=0,chs=0;
	char choice,str[1000],str1[1000];
	printf(" This program is for Encryption/Decryption Caesar, Atbash, Playfair Ciphers.\n");
	do{
		printf(" Select an option :-\n	1.	Caesar Cipher.\n	2.	Atbash Cipher.\n	3.	Vigenere\n");
		scanf("%d",&ch);
		switch(ch){
			case(1):
				printf(" Select an option :-\n	1.	Encrypt.\n	2.	Decrypt.\n");
				scanf("%d",&chs);
				switch(chs){
					case(1):
						printf("Enter normal text : \n");
 						scanf(" %[^\n]s ",str);
 						printf("Enter key :\n");
 						scanf("%d",&number);
 						i=0;
 						number%=26;
 						printf("Encrypted Caesar code\n\n");
  						while(str[i]!='\0'){
     						if(!((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127))){
       							if((str[i]>'a'+number+1)&&(str[i]<='z'))
       								printf("%c",str[i]-number-2);
       							else if((str[i]>'A'+number+1)&&(str[i]<='Z'))  
       								printf("%c",str[i]-number-2);
       							else
       								printf("%c",str[i]+24-number);
     						} 
    						if(((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
    						  printf("%c",str[i]);
   							i++;
  						}
  						printf("\n");
						break;
					case(2):
						printf("Enter encrypted tax : \n");
 						scanf(" %[^\n]s ",str); 
 						printf("Enter key :\n");
 						scanf("%d",&number);
 						i=0;
 						printf("Decrypted Caesar code\n\n");
  						while(str[i]!='\0'){
 							if(!((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127))){
  								if((str[i]>='a')&&(str[i]<'z'-number-1))
    							   printf("%c",str[i]+number+2);
  								else if(str[i]>='A'&&str[i]<'Z'-number-1)
    							   printf("%c",str[i]+number+2); 
  								else
   									printf("%c",str[i]-24+number);
							}
    						if(((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
    						  printf("%c",str[i]);
   							i++;
  						}
  						printf("\n");
						break;
				}
				break;
			case(2):
				printf(" Select an option :-\n	1.	Encrypt.\n	2.	Decrypt.\n");
				scanf("%d",&chs);
				switch(chs){
					case(1):
						printf("Enter normal text : \n");
 						scanf(" %[^\n]s ",str); 
 						i=0;
 						printf("Atbash Cipher code\n");
  						while(str[i]!='\0'){
 							if(!((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127))){
   								if(str[i]>='A'&&str[i]<='Z')
   									printf("%c",'Z'+'A'-str[i]);
   								if(str[i]>='a'&&str[i]<='z')
   									printf("%c",'z'+'a'-str[i]);
 							}
    						if(((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
 							    printf("%c",str[i]);
   							i++;
  						}
  						printf("\n");
						break;
					case(2):
						printf("Enter encrypted tax : \n");
 						scanf(" %[^\n]s ",str); 
 						i=0;
 						printf("Decrypted Atbash Cipher code\n");
  						while(str[i]!='\0'){
 							if(!((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127))){
   								if(str[i]>='A'&&str[i]<='Z')
   									printf("%c",'Z'+'A'-str[i]);
   								if(str[i]>='a'&&str[i]<='z')
   									printf("%c",'z'+'a'-str[i]);
 							}
    						if(((str[i]>=0&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
      							printf("%c",str[i]);
   							i++;
  						}
  						printf("\n");
						break;
				}
				break;
			case(3):
				printf(" Select an option :-\n	1.	Encrypt.\n	2.	Decrypt.\n");
				scanf("%d",&chs);
				int i,j,k,numstr[100],numkey[100],numcipher[100];
 				char str[100],key[100];
				switch(chs){
					case(1):
 						printf("Enter normal text : \n");
 						scanf(" %[^\n]s ",str);
 						//converting entered string to Capital letters
 						for(i=0,j=0;i<strlen(str);i++){
						  	if(str[i]!=' '){
   								str[j]=toupper(str[i]);   
   								j++;
  							}
						}
 						str[j]='\0';
 						printf("Entered normal text is : %s \n",str);
 						//Storing string in terms of ascii
 						for(i=0;i<strlen(str);i++){
 							 numstr[i]=str[i]-'A';
 						}
 						printf("Enter a key\n");
 						scanf(" %[^\n]s ",key);
    					//converting entered key to Capital letters
 						for(i=0,j=0;i<strlen(key);i++){
 							if(key[i]!=' '){
							   key[j]=toupper(key[i]);   
							   j++;
							}
 						}
 						key[j]='\0';
    					//Assigning key to the string
    					for(i=0;i<strlen(str);){
     						for(j=0;(j<strlen(key))&&(i<strlen(str));j++){
      							numkey[i]=key[j]-'A';
      							i++;
     						} 
    					}
    					for(i=0;i<strlen(str);i++){
     						numcipher[i]=numstr[i]+numkey[i];
    					}
    					for(i=0;i<strlen(str);i++){
     						if(numcipher[i]>25){
      							numcipher[i]=numcipher[i]-26;
     						}
    					}
    					printf("Vigenere Cipher text is : \n");
    					for(i=0;i<strlen(str);i++)
      						printf("%c",(numcipher[i]+'A')); 
 						printf("\n");
						break;
					case(2):
						printf("Enter encrypted tax : \n");
 						scanf(" %[^\n]s ",str);
 						//converting entered string to Capital letters
 						for(i=0,j=0;i<strlen(str);i++){
  							if(str[i]!=' '){
   								str[j]=toupper(str[i]);   
   								j++;
  							}
 						}
 						str[j]='\0';
 						printf("Entered encrypted tax is : %s \n",str);
 						//Storing string in terms of ascii
 						for(i=0;i<strlen(str);i++)
  							numstr[i]=str[i]-'A';
 						printf("Enter a key\n");
 						scanf(" %[^\n]s ",key);
    					//converting entered key to Capital letters
 						for(i=0,j=0;i<strlen(key);i++){
  							if(key[i]!=' '){
   								key[j]=toupper(key[i]);   
   								j++;
  							}
 						}
 						key[j]='\0';
     					//Assigning key to the string
    					for(i=0;i<strlen(str);){
     						for(j=0;(j<strlen(key))&&(i<strlen(str));j++){
      							numkey[i]=key[j]-'A';
      							i++;
     						}
    					}
    					for(i=0;i<strlen(str);i++){
     						numcipher[i]=numstr[i]-numkey[i];//changed from + to - for decryption 
     							if(numcipher[i]<0)
      								numcipher[i]+=26;
    					}
    					printf("Decrypted Vigenere Cipher text is\n");   
    					for(i=0;i<strlen(str);i++){
      						printf("%c",(numcipher[i]+'A')); 
    					}
 						printf("\n");
						break;
				}
				break;
	}
		printf(" Tell whether want to insert more values : ");
		scanf(" %c",&choice);
	}while(choice=='y' || choice=='Y');
}
