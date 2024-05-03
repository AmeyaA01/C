#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define RESET "\x1B[0m" // FORMULA FOR BOLD LETTERS 
#define BOLD "\x1B[1m" // FORMULA FOR BOLD LETTERS 
struct items{
    char item[20];
    float price;
    int qty;
};

struct orders{
    char customer[50];
    char date[50];
    char time[20];
    int numOfItems;
    struct items itm[50];
};


//functions to generate bills
void generateBillHeader(char name[50],char date[30],char time[20]){
   		 printf("\n\n");
     	printf("\n\t   -----------------");
        printf("\n\t %s  ADV. Restaurant%s",BOLD,RESET);
        printf("\n\t   -----------------");
        printf("\nDate:%s",date);
        printf("\nTime:%s",time);
        printf("\nInvoice To: %s",name);
        printf("\n");
        printf("---------------------------------------\n");
        printf("Items\t\t");
        printf("Qty\t");
        printf("Total\t\t");
        printf("\n---------------------------------------");
        printf("\n\n");
        
}
void generateBillBody(char item[30],int qty, float price){
    printf("%s\t\t",item); 
        printf("%d\t\t",qty); 
        printf("%.2f\t",qty*price); 
        printf("\n");
}

void generateBillFooter(float total){
    printf("\n");
    float dis = 0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;//netTotal + cgst + sgst
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f",grandTotal);
    printf("\n---------------------------------------\n");
}
int main(){ //MAIN FUNCTION
	  
	int op,opt,n,i;
    struct orders ord;
    struct orders order;
    char name[50];
    FILE *fp;
       //dashboard 
int dish,items,available;
if (items=0 && items!=available  )
	{
		printf(" this item is not available !!");
}

else if(items = available)
printf("\t\t\t\t\t\t\t\t %s DISPLAY OF MENU CARD %s\n\n",BOLD,RESET);

printf("\tCAFEMENIA\t1.COLD COFFEE 50/- \t\t2.BELGIAN HOT CHOCOLATE 60/-\t3.ICED HAZELNUT LATTE 80/- \t4.CAPPUCCINO 80/-\t\t5.CARAMELLATTE 90/-\t\n\n");

printf("\n\tBURGERMANIA \t1.VEG CHEESE BURGER 60/-\t2.ALOO TIKKI BURGER 50/-\t3.DOUBLE CHEESE BURGER 70/-\t4.VEGETABLE BURGER 50/-\t\t5.POTATO CORN BURGER 60/-\t\n\n");

printf("\n\tPIZZAS \t\t1.MARGHERITA PIZZA 150/- \t2.VEG CHEESE PIZZA 120/- \t3.PANEER PIZZA 100/-\t\t4.SWEET CORN PIZZA 100/- \t5.THIN CRUST PIZZA 165/-\t\n\n");

printf("\n\tMILKSHAKE \t1.STRAWBERRY MILKSHAKE 50/- \t2. TOASTED MARSHMELLO 75/- \t3.CHOCOLATE BLEND 80/- \t\t4.HAZELNUT MILKSHAKE 90/- \t5.MOCHA MILKSHAKE 60/-\t\n\n");

printf("\n\tNUGGETS \t1.CHEESE NUGGETS 40/- \t\t2.POTATO NUGGETS 30/- \t\t3.PANEER NUGGETS 50/- \t\t4.CORN NUGGETS 45/- \t\t5.MIX VEG NUGGETS 40/-\t\n\n");

printf("\n\tDOUGHNUTS \t1.GLAZED DOUGHNUT 80/- \t\t2.SUGAR DOUGHNUT 60/- \t\t3.VANILLA DOUGHOUT 60/-\t\t4.CHOCOLATE RAISE 80/-\t\t5.CREAM FILLED DOUGHOUT 75/-\t\n\n");

printf("\n\tBROWNIES\t1.CHOCOLATE MINT 50/-\t\t2.CREAM CHEESE BROWNIE 70/-\t3. WALLNUT BROWNIE 100/- \t4.SILKLET BROWNIE 85/- \t\t5.S'MORES BROWNIE 90/-\t\n\n");

printf("\n\tICE-CREAMES \t1.ITALIAN ICECREAM 40/-\t\t2.CHOCO CHIP ICECREAM 50/- \t3.ROLLED ICECREAM 50/-\t\t4. PHILADELPHIA 40/-\t\t5.KULFI 30/-\t\n\n");
 
 

{
   
    float total = 0;
    int invoiceFound = 0;
    printf("\n\nPlease select your prefered operation");
    printf("\n\n1.Generate Invoice");
    printf("\n\nYour choice:\t");
    scanf("%d",&opt);
    fgetc(stdin);
    switch(opt)
	{
        case 1:
      
        printf("\nPlease enter the name of the customer:\t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1] = 0;
        strcpy(ord.date,__DATE__);
        strcpy(ord.time,__TIME__);
        
        printf("\nPlease enter the number of items:\t");
        scanf("%d",&n);
        ord.numOfItems = n;
        for( i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d:\t",i+1);
//            scanf("%d",&dish);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("Please enter the quantity:\t");
           
            scanf("%d",&ord.itm[i].qty);
            printf("Please enter the unit price:\t");
            scanf("%f",&ord.itm[i].price);
            total += ord.itm[i].qty*ord.itm[i].price;
        }

        generateBillHeader(ord.customer,ord.date,ord.time);
        for( i=0;i<ord.numOfItems;i++)
		{
            generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        }
        generateBillFooter(total);
        break;

        case 2:
        printf("THANK YOU \n");
        if(!invoiceFound){
            printf("Sorry the invoice for this billing system doesnot exist",name);
        }
        fclose(fp);
        break;

        case 3:
        printf("\t\t\t BYE BYE :)");
        exit(0);
       break;

    default:
    printf("SORRY YOU INSERTED INVALID OPTION");
    break;
 }
    printf("\n\tTHANK YOU VISIT AGAIN \n\n\t Bye Bye :)\n\n");
    printf("\n\n");

    return 0;
}
}
