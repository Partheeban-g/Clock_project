#include<stdio.h>
 char name[15];
 int number_of_items;
 float quantity[10],total[10];
 float sub_total=0;

void start()
{
   
    printf("Enter the name of a customer :");
    scanf("%s",&name);
    printf("Enter the number of items :");
    scanf("%d",&number_of_items);
}

void items(int n)//2
{
    // for(int j=1;j<=n;j++) = for printing the multple items & their rates
    {
    char item[10][100];
    printf("Enter the Food items \n");
    for(int i=1;i<=n;i++)
    {
        scanf("%100s,",item[i]);
    }
     for(int i=1;i<=n;i++)
    {
        printf("Enter the Quantity of %s : ",item[i]);
        scanf("%f",&quantity[i]);
        printf("Enter the Price of %s : ",item[i]);
        scanf("%f",&total[i]);
    } 
    
    half_bill_1(name);

    for(int i=1;i<=n;i++)
    {
        printf("%d)%s\t\t\t%.0f\t\t\t%.2f\n",i,item[i],quantity[i],quantity[i]*total[i]);
        sub_total = sub_total + (quantity[i]*total[i]);
    }

    half_bill_2();
    }
}


void half_bill_1(char name[])
{
    printf("\n\n");
    printf("\t\t\tADV. Restaurant\t\t\n");
    printf("----------------------------------------------------------\n");
    printf("DATE : 22/07/2022\n");
    printf("Invoice to MR. %s\n",name);
    printf("----------------------------------------------------------\n");
    printf("Items\t\t\tQty\t\t\tTotal\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
}

void half_bill_2()
{
    float discount,net_total,cgst,sgst,grand_total;
    discount = (sub_total*.10);
    net_total = (sub_total-discount);
    cgst = (net_total*0.09);
    sgst = (net_total*0.09);
    grand_total = (net_total+cgst+sgst);
    printf("\n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    printf("Sub-Total\t\t\t\t\t%.2f\n",sub_total);
    printf("Discount @ 10\% \t\t\t\t\t%.2f\n",discount);
    printf("\t\t\t\t\t\t----------\n");
    printf("Net-Total\t\t\t\t\t%.2f\n",net_total);
    printf("CGST @9%\t\t\t\t\t%.2f\n",cgst);
    printf("SGST @9%\t\t\t\t\t%.2f\n",sgst);
    printf("----------------------------------------------------------\n");
    printf("Grand Total\t\t\t\t\t%.2f\n",grand_total);
    printf("----------------------------------------------------------\n");


}

int main()
{ 
    start();
    items(number_of_items);
    return 0;
}