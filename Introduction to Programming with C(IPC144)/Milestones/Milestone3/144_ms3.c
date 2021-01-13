#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100

const double TAX = 0.13;

struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};

void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
int yes(void);
void GroceryInventorySystem(void);
int menu(void);
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int noOfRecs, int sku, int* index);
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item *itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int *NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);


void welcome(void){
	printf("---=== Grocery Inventory System ===---\n\n");
}

void printTitle(void){
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double gTotal){
	printf("--------------------------------------------------------+----------------\n");
	if(gTotal > 0){
	printf("                                           Grand Total: |%12.2lf\n",gTotal);
	}
}


void flushKeyboard(void){
	char c;
	while( (c = getchar()) != '\n' && c != EOF){
	}
}


void pause(void){
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

int getInt(void){
	int value;
	char charValue;
	do{
		scanf("%d%c",&value,&charValue);
		if(charValue != '\n'){
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	}while(charValue != '\n');
	return value;
}

int getIntLimited(int lowerLimit, int upperLimit){
	int value;
	do{
		value = getInt();
		if(value < lowerLimit || value > upperLimit){
			printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
		}
	}while(value < lowerLimit || value > upperLimit); 
       return value;	
}


double getDouble(void){
	double value;
	char charValue;
	do{
		scanf("%lf%c",&value,&charValue);
		if(charValue != '\n'){
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	}while(charValue != '\n');
	return value;
}

double getDoubleLimited(double lowerLimit, double upperLimit){
	double value, result;
	do{
		value = getDouble();
		if(value > lowerLimit && value < upperLimit){
			result = value;
		}
		if(value < lowerLimit || value > upperLimit){
			printf("Invalid value, %lf< value < %lf: ",lowerLimit,upperLimit);
		}
	}while(value < lowerLimit || value > upperLimit);
	return result;
}

int yes(void){
	int quit = 0;
	char charValue;
	do{
		scanf(" %c",&charValue);
		if(charValue != 'y' && charValue != 'Y' && charValue != 'n' && charValue != 'N'){
			flushKeyboard();
			printf("Only (Y)es or (N)o are acceptable: ");
		}else if(charValue == 'y' || charValue == 'Y'){
			quit = 1;
		}else if(charValue == 'n' || charValue == 'N'){
			quit = 0;
		}
	}while(charValue != 'y' && charValue != 'Y' && charValue != 'n' && charValue != 'N');
	return quit;
}

int menu(void){
	int option;     
	printf("1- List all items\n");
	printf("2- Search by SKU\n");  
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	option = getIntLimited(0, 7);
	return option;
}

void GroceryInventorySystem(void){
	welcome();
	int option, quit;
	do{
		option = menu();
		switch(option){
			case 1:
				printf("List Items under construction!\n");
				pause();
				break;
			case 2:
				printf("Search Items under construction!\n");
				pause();
				break;
			case 3:
				printf("Checkout Item under construction!\n");
				pause();
				break;
			case 4:
				printf("Stock Item under construction!\n");
				pause();
				break;
			case 5:
				printf("Add/Update Item under construction!\n");
				pause();
				break;
			case 6:
				printf("Delete Item under construction!\n");
				pause();
				break;
			case 7:
				printf("Search by name under construction!\n");
				pause();
				break;
			case 0:
				printf("Exit the program? (Y)es/(N)o: ");
				quit = yes();
				break;

			default:
				printf("Invalid value, 0 < value < 7: ");
				break;
		}
	}while(option != '\n' && quit != 1);
}

double totalAfterTax(struct Item item){
	double totalInvPrice;
	double total;
	total = item.price * item.quantity;
	if(item.isTaxed == 1){
		totalInvPrice = total + total * TAX;
	} else {
		totalInvPrice = total;
	}
	return totalInvPrice;
}


int isLowQuantity(struct Item item){
	int itemQuantityStatus = 0;
	if(item.quantity < item.minQuantity){
		itemQuantityStatus = 1;
	}
	return itemQuantityStatus;
}


struct Item itemEntry(int sku){
	struct Item data;
	data.sku = sku;

	printf("        SKU: %d\n",sku);

	printf("       Name: ");
	scanf(" %[^\n]",data.name);
	flushKeyboard();

	printf("      Price: ");
	data.price = getDouble();

	printf("   Quantity: ");
	data.quantity = getInt();	

	printf("Minimum Qty: ");
	data.minQuantity = getInt();

	printf("   Is Taxed: ");
	data.isTaxed = yes();

	flushKeyboard();

	return data;
}

void displayItem(struct Item item, int linear){
	if(linear == LINEAR){

		if(isLowQuantity(item)){
			printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|***\n", item.sku, item.name, item.price, item.isTaxed ? "Yes" : "No", item.quantity, item.minQuantity, totalAfterTax(item));
		} else {
			printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|\n", item.sku, item.name, item.price, item.isTaxed ? "Yes" : "No", item.quantity, item.minQuantity, totalAfterTax(item));
		}

	} else {
		printf("        SKU: %d\n",item.sku);
		printf("       Name: %s\n",item.name);
		printf("      Price: %.2lf\n",item.price);
		printf("   Quantity: %d\n",item.quantity);
		printf("Minimum Qty: %d\n",item.minQuantity);
		
		if(item.isTaxed == 1){
			printf("   Is Taxed: Yes\n");
		} else {
			printf("   Is Taxed: No\n");
		}
		
		if(isLowQuantity(item) || item.minQuantity == 0){
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}
}

void listItems(const struct Item item[], int noOfItems){
	int counter;
	double grandTotal = 0;
	printTitle();
	for(counter = 0; counter < noOfItems; counter++){
		printf("%-4d",counter+1);
		displayItem(item[counter],LINEAR);
		grandTotal = grandTotal + totalAfterTax(item[counter]);
	}
	printFooter(grandTotal);
}

int locateItem(const struct Item item[], int noOfRecs, int sku, int *index){
	int i;
	int status = 0;
	for(i = 0; i < noOfRecs; i++){
		if(item[i].sku == sku){
			*index = i;
			status = 1;
		}
	}
	return status;
}


void search(const struct Item item[], int NoOfRecs){
	int skuByUser;
	int status, index;

	printf("Please enter the SKU: ");
	skuByUser = getIntLimited(SKU_MIN, SKU_MAX);
	
	status = locateItem(item, NoOfRecs, skuByUser, &index);

	if(status == 1){
		displayItem(item[index], FORM);
	} else {
		printf("Item not found!\n");
	}
}

void updateItem(struct Item *itemptr){
	struct Item data;
	int overWriteData;

	printf("Enter new data:\n");
	data = itemEntry(itemptr->sku);
	
	printf("Overwrite old data? (Y)es/(N)o: ");
	overWriteData = yes();

	if(overWriteData == 1){
		printf("--== Updated! ==--\n");
		*(itemptr) = data;
	} else {
		printf("--== Aborted! ==--\n");
	}
}

void addItem(struct Item item[], int *NoOfRecs, int sku){
	struct Item data;
	
	if( *NoOfRecs != MAX_ITEM_NO ){
		int wantToAddItem;
		data = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		wantToAddItem = yes();

		if(wantToAddItem == 1){
			*NoOfRecs += 1;
			item[*NoOfRecs - 1] = data;
			printf("--== Added! ==--\n");
		} else {
			printf("--== Aborted! ==--\n");
		}
	} else {
		printf("Can not add new item; Storage Full!\n");
	}
}

void addOrUpdateItem(struct Item item[], int *NoOfRecs){
	int skuByUser;
	int status;
	int index;

	printf("Please enter the SKU: ");
	skuByUser = getIntLimited(SKU_MIN, SKU_MAX);
	
	status = locateItem(item, *NoOfRecs, skuByUser, &index);
	if(status == 1){
		int isUpdate;
		
		displayItem(item[index], FORM);

		printf("Item already exists, Update? (Y)es/(N)o: ");
		isUpdate = yes();

		if(isUpdate == 1){
			updateItem(&item[index]);
		} else {
			printf("--== Aborted! ==--\n");
		}
	} else {
		addItem(item, NoOfRecs, skuByUser);
	}
}	

void adjustQuantity(struct Item item[], int NoOfRecs, int stock){
	int validSkuByUser;
	int locate;
	int index = -1;
	int qty;
	
	printf("Please enter the SKU: ");
	scanf("%d", &validSkuByUser);

	locate = locateItem(item, NoOfRecs, validSkuByUser, &index);
	
	if(locate != 1){
		printf("SKU not found in storage!\n");
	} else {
		displayItem(item[index], FORM);
		
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ",stock == STOCK ? "to stock" : "to checkout", stock == STOCK ? (MAX_QTY - item[index].quantity) : item[index].quantity);
		scanf("%d",&qty);
		if(qty == 0){
			printf("--== Aborted! ==--\n");
		} else {
			if(stock == STOCK){
				while((qty > (MAX_QTY - item[index].quantity)) || (qty < 0)){
					printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", stock == STOCK ? "to stock" : "to checkout", stock == STOCK ? MAX_QTY - item[index].quantity : item[index].quantity);
					scanf("%d",&qty);
				}
				item[index].quantity += qty;
				printf("--== Stocked! ==--\n");
			}
			if(stock == CHECKOUT){
				while((qty > item[index].quantity) || (qty < 0)){
					printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", stock == STOCK ? "to stock" : "to checkout", stock == STOCK ? MAX_QTY - item[index].quantity : item[index].quantity);
					scanf("%d", &qty);
				}
				item[index].quantity = item[index].quantity - qty;
				printf("--== Checked out! ==--\n");
			}
			if(item[index].quantity <= item[index].minQuantity){
				printf("Quantity is low, please reorder ASAP!!!\n");
			}
		}
	}
}
