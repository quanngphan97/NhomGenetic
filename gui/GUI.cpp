#include "GUI.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include "../businessobjects/Customers.h"
#include "../businessobjects/Categories.h"
#include "../businessobjects/Employees.h"
#include "../businessobjects/Products.h"
#include "../businessobjects/Orders.h"
#include "../businessobjects/OrderDetails.h"
#include "../businessobjects/Shippers.h"
#include "../businessobjects/Suppliers.h"
#include "../dataaccess/CustomersData.h"
#include "../dataaccess/CategoriesData.h"
#include "../dataaccess/EmployeesData.h"
#include "../dataaccess/ProductsData.h"
#include "../dataaccess/OrdersData.h"
#include "../dataaccess/OrderDetailsData.h"
#include "../dataaccess/DataShippers.h"
#include "../dataaccess/DataSupplier.h"
#include "../libs/json.hpp"
#include "../libs/util.h"

using json = nlohmann::json;
using namespace std;

GUI::GUI(){
    
}

void GUI::importProductsToStock(){
    
}

void GUI::manageProducts(){
    
}

void GUI::manageCategories(){

}

/** @brief Function export products.
 *  
 *  Function export products:
 *  - Create a order
 *  - Enter quantity of product need to buy
 *  - Create orderdetail corresponding to product quantity
 *  - Write data to file
 *  @author Ly Truong (truonglehaily)
 */
void GUI::ExportProductsFromStock() {
    OrdersData ordersdata("Orders.data");
    OrderDetailsData orderdetailsdata("OrderDetails.data");
	
    system("cls");
    cout << endl << endl;
	cout << "**------------------------------------------------**" << endl;
	cout << "**                 LGE Store                      **" << endl;
	cout << "**------------------------------------------------**" << endl;
	cout << "**          2.Export Products from Stock          **" << endl;
	cout << "**------------------------------------------------**" << endl;

	int n;
    Orders order;
    cout << "**Enter CustomerID: ";
    cin >> order.CustomerID;
    cout << "**Enter ShipperID: ";
    cin >> order.ShipperID;
    order.EmployeeID = 1;
    Util u;
	order.OrderDate = u.GetToday();
	order.OrderID = ordersdata.getLastId() + 1;
    ordersdata.pushBack(order);

    cout <<"How many products do you want to buy?  ";
	cin >> n;
	cout <<"-------------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		OrderDetails orderdetail;
		orderdetail.OrderDetailID = orderdetailsdata.getLastId() + 1;
		orderdetail.OrderID = order.OrderID;
		
		cout << "Product " << i+1 << ":" << endl;
		cout << "Enter ProductID: ";
		cin >> orderdetail.ProductID;

		int temp;
		cout << "Enter Quantity: ";
		cin >> temp;
		orderdetail.Quantity = 0 - temp;

		orderdetailsdata.pushBack(orderdetail);
	}

	for (int i = 0; i < orderdetailsdata.getSize(); i++){
		OrderDetails p = orderdetailsdata.get(i);
	}

	ordersdata.exportToFile("Orders.data");
	orderdetailsdata.exportToFile("OrderDetails.data");

	cout << "You bought " << n << " products!" << endl;
	system("pause");
}

/** @brief Function list data from file.
 *  
 *  Function list data from file, select  file need read, read file selected then show it to screen.
 *  @author Ly Truong (truonglehaily)
 */
void GUI::ListData(){
    CustomersData customersdata("Customers.data");
    CategoriesData categoriesdata("Categories.data");
    EmployeesData employeesdata("Employees.data");
    ProductsData productsdata("Products.data");
    OrdersData ordersdata("Orders.data");
    OrderDetailsData orderdetailsdata("OrderDetails.data");
    DataShippers shippersdata("Shippers.data");
    DataSupplier suppliersdata("Suppliers.data");

    int choose;
    do{
        system("cls");
        cout << endl << endl;
        cout << "**------------------------------------------------**" << endl;
        cout << "**                 LGE Store                      **" << endl;
        cout << "**------------------------------------------------**" << endl;
        cout << "**          8.List Data                           **" << endl;
        cout << "**------------------------------------------------**" << endl;
        cout << "**(1)Customers" << endl;
        cout << "**(2)Categories" << endl;
        cout << "**(3)Employees" << endl;
        cout << "**(4)Products" << endl;
        cout << "**(5)Orders" << endl;
        cout << "**(6)OrderDetails" << endl;
        cout << "**(7)Shippers" << endl;
        cout << "**(8)Suppliers" << endl;
        cout << "**(0)Back" << endl << endl;
        cout << "**What data do you want to display? ";
        cin >> choose;
        switch (choose){
            case 1:
                cout << "Data Customers:" << endl;
                cout << "CustomerID, CustomerName, ContactName, Address, City, PostalCode, Country" << endl;
                for (int i=0; i < customersdata.GetSize(); i++){
                    Customers item = customersdata.Get(i);
                    cout << item.ToString() << endl;
                }
                system("pause");
                break;
            case 2:
                cout << "Data Categories:" << endl;
                cout << "CategoryID, CategoryName, Description" << endl;
                for (int i=0; i < categoriesdata.GetSize(); i++){
                    Categories item = categoriesdata.Get(i);
                    cout << item.ToString() << endl;
                }
                system("pause");
                break;
            case 3:
                cout << "Data Employees:" << endl;
                cout << "EmployeeID, LastName, FirstName, BirthDate, Photo, Notes" << endl;
                for (int i=0; i < employeesdata.GetSize(); i++){
                    Employees item = employeesdata.Get(i);
                    cout << item.ToString() << endl;
                }
                system("pause");
                break;
            case 4:
                cout << "Data Products:" << endl;
                cout << "ProductID, ProductName, SupplierID, CategoryID, Unit, Price" << endl;
                for (int i=0; i < productsdata.getSize(); i++){
                    Products item = productsdata.get(i);
                    cout << item.toString() << endl;
                }
                system("pause");
                break;
            case 5:
                cout << "Data Orders:" << endl;
                cout << "OrderID, CustomerID, EmployeeID, OrderDate, ShipperID" << endl;
                for (int i=0; i < ordersdata.getSize(); i++){
                    Orders item = ordersdata.get(i);
                    cout << item.toString() << endl;
                }
                system("pause");
                break;
            case 6:
                cout << "Data OrderDetails:" << endl;
                cout << "OrderDetailID, OrderID, ProductID, Quantity" << endl;
                for (int i=0; i < orderdetailsdata.getSize(); i++){
                    OrderDetails item = orderdetailsdata.get(i);
                    cout << item.toString() << endl;
                }
                system("pause");
                break;
            case 7:
                cout << "Data Shippers:" << endl;
                cout << "ShipperID, ShipperName, Phone" << endl;
                for (int i=0; i < shippersdata.GetSize(); i++){
                    Shippers item = shippersdata.get(i);
                    cout << item.Tostring() << endl;
                }
                system("pause");
                break;
            case 8:
                cout << "Data Suppliers:" << endl;
                cout << "SupplierID, SupplierName, ContactName, Address, City, PostalCode, Country, Phone" << endl;
                for (int i=0; i < suppliersdata.GetSize(); i++){
                    Supplier item = suppliersdata.get(i);
                    cout << item.Tostring() << endl;
                }
                system("pause");
                break;
            default:
                break;
        }
    }while (choose != 0);    
}

void GUI::CheckInventory(){
    cout << "Check Inventory Product " << endl;
	OrderDetailsData d("OrderDetails.data");
	OrderDetails s,k;
	int parameter = 0;
	int Result =  0;
	vector<int> ArrayProductID;
	for(int i=0; i<d.getSize(); i++)
	{
		s=d.get(i);
		if(ArrayProductID.size()==0) ArrayProductID.push_back(s.ProductID);
		for(int n= 0 ;n < ArrayProductID.size();n++)
		{
			if(s.ProductID == ArrayProductID[n]) parameter = parameter + 1 ; 
		}
		if(parameter==0)
		{
		 ArrayProductID.push_back(s.ProductID);
		}
		parameter = 0 ;
	}
	for(int j=0;j<ArrayProductID.size();j++)
	{
		for(int m=0;m<d.getSize();m++)
			{
				k = d.get(m);
				if(ArrayProductID[j] == k.ProductID ) Result = Result + k.Quantity;
			}
		cout << "ProductID " << ArrayProductID[j] << " Quantity " << Result << endl;
		Result = 0; 
	}
	cout << " Checked Inventory Product Complete " << endl ;
}

void GUI::PrintImportProductstostock(){
    
}

void GUI::PrintExportProductstostock(){
    
}

void GUI::UpdateSupplier(){
    
}

