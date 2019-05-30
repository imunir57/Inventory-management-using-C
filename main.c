#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[15];
    int code;
    double rate;

} product;
product item;
FILE *f;

void add();
void by_rate();
void by_name();
void by_code();
void viewBYcode();
void viewBYrate();
void viewBYname();
void dltByName();
void dltByCode();

int i,j,k,flag;

int main() {
    printf("\n_______________________________WELCOME_________________________________________\n");
    do {
        printf("\n\n\n\n\t\t\t[1]Add an item\n\t\t\t[2]Buy item by name\n\t\t\t[3]Buy item by code\n");
        printf("\t\t\t[4]Search by name\n\t\t\t[5]Search by code\n\t\t\t[6]Search by rate\n");
        printf("\t\t\t[7]View by name\n\t\t\t[8]View by code\n\t\t\t[9]View by rate\n\t\t\t[0]Exit\n\t\t\t ");
        scanf("%d",&j);

        switch(j) {
        case 1:
            add();
            break;
        case 2:
            dltByName();
            break;
        case 3:
            dltByCode();

            break;
        case 4:
            by_name();

            break;
        case 5:
            by_code();

            break;
        case 6:
            by_rate();
            break;
        case 7:
            viewBYname();
            break;
        case 8:
            viewBYcode();
            break;
        case 9:
            viewBYrate();
            break;
        default:
            if(j!=0) {
                printf("Enter correct number\n");
                printf("\nPress any key to try again.");
                getch();
            }
            break;

        }
        system("cls");
    } while(j!=0);
    printf("\n\n--------------------------------GOOD BYE!!------------------------------------\n\n");

    return 0;
}

void add() {
    system("cls");
    f=fopen("list.txt","a+");
    printf("\n\n\t\tCode:");
    scanf("%d",&item.code);
    printf("\t\tName:");
    scanf("%s",&item.name);
    printf("\t\tRate:");
    scanf("%lf",&item.rate);
    fprintf(f,"\n%d\t%s\t%.2lf",item.code,item.name,item.rate);
    printf("\nItem success fully added.\n");
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}

void by_code() {
    system("cls");
    int cd;
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        getch();
        return;
    }
    printf("\n\n\n\t\t\tEnter code:");
    scanf("%d",&cd);
    flag=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\t",&item.code,item.name,&item.rate);
        if(cd==item.code) {
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nNot Found!!\n");
    else {
        printf("\n\t\tCode\tName\tRate\n");
        printf("\n\t\t%d\t%s\t%.2lf\n",item.code,item.name,item.rate);
    }
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}

void by_rate() {
    system("cls");
    int rt;
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        getch();
        return;
    }
    printf("\n\n\n\t\t\tEnter rate:");
    scanf("%d",&rt);
    flag=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf",&item.code,item.name,&item.rate);
        if(rt==(int)item.rate) {
            flag=1;

            break;
        }
    }
    if(flag==0)
        printf("\nNot Found!!\n");
    else {
        printf("\n\t\tCode\tName\tRate\n");
        printf("\n\t\t%d\t%s\t%.2lf\n",item.code,item.name,item.rate);
    }
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}

void by_name() {
    system("cls");
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        getch();
        return;
    }
    char nm[20];
    printf("\n\n\n\t\t\tEnter name:");
    scanf("%s",nm);
    flag=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item.code,item.name,&item.rate);
        if(!stricmp(nm,item.name)) {
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nNot Found!!\n");
    else {
        printf("\n\t\tCode\tName\tRate\n");
        printf("\n\t\t%d\t%s\t%.2lf\n",item.code,item.name,item.rate);
    }
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}


void viewBYname() {
    system("cls");
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        getch();
        return;
    }
    product item[100];
    double tmp;
    char temp[20];
    i=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item[i].code,item[i].name,&item[i].rate);
        i++;
    }
    for(k=0; k<i; k++) {
        for(j=k; j<i; j++) {
            if(strcmp(item[k].name,item[j].name)>0) {
                tmp=item[k].rate;
                item[k].rate=item[j].rate;
                item[j].rate=tmp;

                item[k].code=item[k].code^item[j].code;
                item[j].code=item[k].code^item[j].code;
                item[k].code=item[k].code^item[j].code;

                strcpy(temp,item[k].name);
                strcpy(item[k].name,item[j].name);
                strcpy(item[j].name,temp);

            }
        }
    }
    printf("\n\t\tName            Code       Rate\n");
    for(k=0; k<i; k++)
        printf("\t\t%-11s   %6d   %8.2lf\n",item[k].name,item[k].code,item[k].rate);
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}


void viewBYrate() {
    system("cls");
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        getch();
        return;
    }
    product item[100];
    double tmp;
    char temp[20];
    i=0;

    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item[i].code,item[i].name,&item[i].rate);
        i++;
    }
    for(k=0; k<i; k++) {
        for(j=k; j<i; j++) {
            if(item[k].rate>item[j].rate) {
                tmp=item[k].rate;
                item[k].rate=item[j].rate;
                item[j].rate=tmp;

                item[k].code=item[k].code^item[j].code;
                item[j].code=item[k].code^item[j].code;
                item[k].code=item[k].code^item[j].code;

                strcpy(temp,item[k].name);
                strcpy(item[k].name,item[j].name);
                strcpy(item[j].name,temp);

            }
        }
    }
    printf("\n\t\t    Rate   Name            Code\n");
    for(k=0; k<i; k++)
        printf("\t\t%8.2lf   %-11s   %6d\n",item[k].rate,item[k].name,item[k].code);
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}


void viewBYcode() {
    system("cls");
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        getch();
        return;
    }
    product item[100];
    double tmp;
    char temp[20];
    i=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item[i].code,item[i].name,&item[i].rate);
        i++;
    }
    for(k=0; k<i; k++) {
        for(j=k; j<i; j++) {
            if(item[k].code>item[j].code) {
                tmp=item[k].rate;
                item[k].rate=item[j].rate;
                item[j].rate=tmp;

                item[k].code=item[k].code^item[j].code;
                item[j].code=item[k].code^item[j].code;
                item[k].code=item[k].code^item[j].code;

                strcpy(temp,item[k].name);
                strcpy(item[k].name,item[j].name);
                strcpy(item[j].name,temp);

            }
        }
    }
    printf("\n\t\t  Code   Name              Rate\n");
    for(k=0; k<i; k++)
        printf("\t\t%6d   %-11s   %8.2lf\n",item[k].code,item[k].name,item[k].rate);
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}

void dltByName() {
    system("cls");
    FILE *dlt;
    double p=-1;
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        getch();
        return;
    }
    dlt=fopen("temp.txt","w");
    char namedlt[15];
    printf("\n\n\t\tEnter item name:");
    scanf("%s",namedlt);
    flag=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item.code,item.name,&item.rate);
        if(!stricmp(namedlt,item.name)) {
            flag=1;
            while(1) {
                printf("\nPlease pay %.2lf Taka(0 to discard):",item.rate);
                scanf("%lf",&p);
                if(p==0)break;
                if(p==item.rate) {
                    printf("\nyou are successfully buy this item.\n");
                    p=1;
                    break;
                }
            }
        }
        if(p!=1)
            fprintf(dlt,"%d\t%s\t%.2lf\n",item.code,item.name,item.rate);
        p=-1;
    }
    fclose(f);
    fclose(dlt);
    if(flag==0)
        printf("\nName not found\n");
    remove("list.txt");
    rename("temp.txt","list.txt");
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}

void dltByCode() {
    system("cls");
    FILE *dlt;
    f=fopen("list.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        getch();
        return;
    }
    dlt=fopen("temp.txt","w");
    int codlt;
    double p=-1;
    printf("\n\n\t\tEnter item code:");
    scanf("%d",&codlt);
    flag=0;
    while(!feof(f)) {
        fscanf(f,"%d\t%s\t%lf\n",&item.code,item.name,&item.rate);
        if(codlt==item.code) {
            flag=1;
            while(1) {
                printf("\nPlease pay %.2lf Taka(0 to discard):",item.rate);
                scanf("%lf",&p);
                if(p==0)break;
                if(p==item.rate) {
                    printf("\nyou are successfully buy this item.\n");
                    p=1;
                    break;
                }
            }
        }
        if(p!=1)
            fprintf(dlt,"%d\t%s\t%.2lf\n",item.code,item.name,item.rate);
        p=-1;
    }
    fclose(f);
    fclose(dlt);
    if(flag==0)
        printf("\nCode not found\n");
    remove("list.txt");
    rename("temp.txt","list.txt");
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}
