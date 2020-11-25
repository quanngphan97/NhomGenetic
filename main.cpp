#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include "businessobjects/Products.h"
#include "businessobjects/Orders.h"
#include "businessobjects/OrderDetails.h"
#include "businessobjects/Customers.h"
#include "businessobjects/Shippers.h"
#include "./dataaccess/ProductsData.h"
#include "./dataaccess/OrdersData.h"
#include "./dataaccess/OrderDetailsData.h"
#include "./dataaccess/CustomersData.h"
#include "./dataaccess/EmployeesData.h"
#include "./dataaccess/DataShippers.h"
#include "./libs/json.hpp"
#include "./libs/util.h"
#include "./gui/GUI.h"
using json = nlohmann::json;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/** @brief Function list function of application and execute options.
 *  
 *  Function list data from file, select  file need read, read file selected then show it to screen.
 */
void menuOptions() {
	GUI gui;
	int yourChosen;

	do{
		cout << endl << endl;
		cout << "     **-------------What Do You Want To Do?------------**" << endl;
		cout << "     **------------------------------------------------**" << endl;
		cout << "     **                 LGE Store                      **" << endl;
		cout << "     **------------------------------------------------**" << endl;
		cout << "     **          1.Import Products to Stock            **" << endl;
		cout << "     **          2.Export Products from Stock          **" << endl;
		cout << "     **          3.Check Inventory                     **" << endl;
		cout << "     **          4.Check Inventory by Date             **" << endl;	
		cout << "     **          5.Update Supplier                     **" << endl;
		cout << "     **          6.Update Product                      **" << endl;
		cout << "     **          7.Update Category                     **" << endl;
		cout << "     **          8.List Data                           **" << endl;
		cout << "     **          9.Backup and Recovery                 **" << endl;
		cout << "     **          0.Exit Menu                           **" << endl;
		cout << "     **------------------------------------------------**" << endl << endl;

		cout << "     **Select your action: ";
		cin >> yourChosen;

		switch (yourChosen){
			case 1:
				gui.importProductsToStock();
				break;
			case 2:
				gui.ExportProductsFromStock();
				break;
			case 3:
				gui.CheckInventory();
				break;
			case 4:
				break;
			case 5:
				gui.UpdateSupplier();
				break;
			case 6:
				gui.manageProducts();
				break;
			case 7:
				gui.manageCategories();
				break;
			case 8:
				gui.ListData();
				break;
			case 9:
				gui.BackupAndRecovery();
				break;
		default:
			break;
		}
	}while (yourChosen != 0);
}

int main(int argc, char** argv) {
    menuOptions();

	return 0;
}
