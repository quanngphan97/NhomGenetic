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

string ordersFile = "Orders.data";
string orderDetailsFile = "OrderDetails.data";
string productsFile = "Products.data";
string categoriesFile = "Categories.data";

GUI::GUI(){
    
}

/*
* @brief Function importProductsToStock(): Import new orders and orderdetails into Orders file and Orderdetails file
* 
* Author: Nguyen Thanh Tra
*/
void GUI::importProductsToStock(){
    int n;

	cout << "HOW MANY ORDERS THAT YOU WANT TO ADD TO STOCK? " << endl << endl;
	cin >> n;

	for (int i = 0; i < n; i++) {
		OrdersData ordersdata(ordersFile);
		OrderDetailsData orderdetailsdata(orderDetailsFile);

		OrderDetails orderdetails;
		Orders orders;

		cout << endl;
		cout << "INSERT YOUR " << (i + 1) << " ORDER: " << endl;

		int idMax = 0;

		for (int i = 0; i < ordersdata.getSize(); i++) {
			Orders oi = ordersdata.get(i);
			if ((oi.OrderID) >= idMax){
				idMax = oi.OrderID;
			}
			else {}
		}
		
		orders.OrderID = (idMax+1);
		orderdetails.OrderID = orders.OrderID;

		/*cout << "The Order ID (Int Type): ";
		cin >> orders.OrderID;
		orderdetails.OrderID = orders.OrderID;*/

		cout << "The Customer ID (Int Type): ";
		cin >> orders.CustomerID;

		cout << "The Employee ID (Int Type): ";
		cin >> orders.EmployeeID;

		/*orders.OrderDate = (string)Writetimernewupdate();*/
		/*orders.OrderDate = GetToday();*/
		cout << "The Order Date (String Type): ";
		cin >> orders.OrderDate;

		cout << "The Shipper ID (Int Type): ";
		cin >> orders.ShipperID;

		int k;
		cout << endl << endl;
		cout << "HOW MANY PRODUCTS THAT YOU WANT TO MAKE IN THIS ORDER: ";
		cin >> k;

		for (int i = 0; i < k; i++) {

			cout << endl << endl;
			cout << "INSERT YOUR " << (i + 1) << " PRUDUCTS:: " << endl;

			cout << "The Product ID (Int Type): ";
			cin >> orderdetails.ProductID;

			cout << "The OrderDetail ID (Int Type): ";
			cin >> orderdetails.OrderDetailID;

			cout << "The Quantity (Int Type): ";
			cin >> orderdetails.Quantity;

			orderdetailsdata.pushBack(orderdetails);

		}

		ordersdata.pushBack(orders);

		ordersdata.exportToFile(ordersFile);
		orderdetailsdata.exportToFile(orderDetailsFile);

	}

	OrdersData ordersdataS(ordersFile);
	OrderDetailsData orderdetailsdataS(orderDetailsFile);

	cout << endl;
	cout << "Your All Orders in your Orders File (ordersFile.data):" << endl << endl;

	for (int i = 0; i < ordersdataS.getSize(); i++) {
		Orders o = ordersdataS.get(i);
		cout << o.toString() << endl;
	}

	ordersdataS.exportToFile(ordersFile);



	cout << endl;
	cout << "Your All OrderDetails in your OrderDetails File (orderDetailsFile.data):" << endl << endl;

	for (int i = 0; i < orderdetailsdataS.getSize(); i++) {
		OrderDetails od = orderdetailsdataS.get(i);
		cout << od.toString() << endl;
	}

	orderdetailsdataS.exportToFile(orderDetailsFile);
}

void GUI::manageProducts(){
    int yourChosen;
	cout << endl;
	cout << "     **-------------What Do You Want To Do?------------**" << endl;
	cout << "     **------------------------------------------------**" << endl;
	cout << "     **                 LGE Store                      **" << endl;
	cout << "     **------------------------------------------------**" << endl;
	cout << "     **        1.Add Products to Products List         **" << endl;
	cout << "     **        2.Remove Products from Products List    **" << endl;
	cout << "     **        3.Exit                                  **" << endl;
	cout << "     **------------------------------------------------**" << endl << endl;

	cin >> yourChosen;

	if (yourChosen == 1) {
		//addProductsToProductsList();
		ProductsData productsdata(productsFile);

		int n;
		cout << endl;
		cout << "Your Chosen is: \"Add More Products To Products List\"" << endl << endl;
		cout << "HOW MANY PRODUCTS THAT YOU WANT TO ADD TO PRODUCTS LIST?" << endl << endl;
		cin >> n;
	
		for (int i = 0; i < n; i++) {
			Products product;
	
			cout << endl;
			cout << "INSERT YOUR " << (i + 1) << " PRODUCT: " << endl;
	
			int idMax = 0;
	
			for (int i = 0; i < productsdata.getSize(); i++) {
				Products pr = productsdata.get(i);
				if ((pr.ProductID) >= idMax) {
					idMax = pr.ProductID;
				}
				else {}
			}
	
			product.ProductID = idMax +1;
			/*cout << "The Product ID (Int Type): ";
			cin >> product.ProductID;*/
	
			cout << "The Product Name (String Type): ";
			cin >> product.ProductName;
	
			cout << "The Supply ID (Int Type): ";
			cin >> product.SupplyID;
	
			cout << "The Category ID (Int Type): ";
			cin >> product.CategoryID;
	
			cout << "The Unit (Int Type): ";
			cin >> product.Unit;
	
			cout << "The Price (Int Type): ";
			cin >> product.Price;
	
			productsdata.pushBack(product);
		}
	
		productsdata.exportToFile(productsFile);
	
		cout << endl;
		cout << "ALL PRODUCTS IN PRODUCTS FILE ARE: " << endl;
	
		for (int i = 0; i < productsdata.getSize(); i++) {
			Products p = productsdata.get(i);
			cout << p.toString() << endl;
		}
	
		//manageProducts();
	}
	else if (yourChosen == 2) {
		//removeProductsFromProductsList();
		ProductsData productsdata(productsFile);

		int id;
		cout << "INSERT THE PRODUCT'S ID THAT YOU WANT TO REMOVE IT FROM PRODUCTS LIST: " << endl;
		cin >> id;
	
		if (id < 0) {
			cout << "EROR TYPE: Please Insert unsigned Interger Type!!" << endl << endl;
			//removeProductsFromProductsList();
		}
		else if (id >= 0) {
	
			for (int i = 0; i < productsdata.getSize(); i++) {
				Products p = productsdata.get(i);
				if ((p.ProductID) == id) {
					productsdata.remove(i);
					cout <<endl << "The Product with the ID [" << id << "] is Removed from Products List." << endl;
				}
				else {}
			}
		}
	
		productsdata.exportToFile(productsFile);
	
		cout << endl <<"NOW, ALL PRODUCTS IN PRODUCTS FILE ARE: " << endl;
	
		for (int i = 0; i < productsdata.getSize(); i++) {
			Products p = productsdata.get(i);
			cout << p.toString() << endl;
		}
	
		//manageProducts();
	}
	else {
		cout << "Your Chosen is \"Exit Menu\"" << endl << endl;
		//menuOptions();
	}
}

void GUI::manageCategories(){
	int yourChosen;
	cout << endl;
	cout << "     **-------------What Do You Want To Do?------------**" << endl;
	cout << "     **------------------------------------------------**" << endl;
	cout << "     **                 LGE Store                      **" << endl;
	cout << "     **------------------------------------------------**" << endl;
	cout << "     **        1.Add Categories to Categories List     **" << endl;
	cout << "     **        2.Remove Category from Categories List  **" << endl;
	cout << "     **        3.Exit                                  **" << endl;
	cout << "     **------------------------------------------------**" << endl << endl;

	cin >> yourChosen;

	if (yourChosen == 1) {
		//addCategoriesToCategoriesList();
		CategoriesData categoriesdata(categoriesFile);

		int n;
		cout << endl;
		cout << "Your Chosen is: \"Add More Categories To Categories List\"" << endl << endl;
		cout << "HOW MANY CATEGORIES THAT YOU WANT TO ADD TO CATEGORIES LIST?" << endl << endl;
		cin >> n;
	
		for (int i = 0; i < n; i++) {
			Categories categories;
	
			cout << endl;
			cout << "INSERT YOUR " << (i + 1) << " CATEGORY: " << endl;
	
			int idMax = 0;
	
			for (int i = 0; i < categoriesdata.GetSize(); i++) {
				Categories ct = categoriesdata.Get(i);
				if ((ct.CategoryID) >= idMax) {
					idMax = ct.CategoryID;
				}
				else {}
			}
	
			categories.CategoryID = idMax +1;
			/*cout << "The Category ID (Int Type): ";
			cin >> categories.CategoryID;*/
	
			cout << "The Category Name (String Type): ";
			cin >> categories.CategoryName;
	
			cout << "The Description (String Type): ";
			cin >> categories.Description;
	
	
			categoriesdata.CreateCategory(categories);
		}
	
		categoriesdata.ExportToFile(categoriesFile);
	
		cout << endl;
		cout << "ALL PRODUCTS IN PRODUCTS FILE ARE: " << endl;
	
		for (int i = 0; i < categoriesdata.GetSize(); i++) {
			Categories c = categoriesdata.Get(i);
			cout << c.ToString() << endl;
		}
	
		manageCategories();
	}
	else if (yourChosen == 2) {
		//removeCategoriesFromCategoriesList();
		CategoriesData categoriesdata(categoriesFile);

		int id;
		cout << "INSERT THE CATEGORY'S ID THAT YOU WANT TO REMOVE IT FROM CATEGORIES LIST: " << endl;
		cin >> id;
	
		if (id < 0) {
			cout << "EROR TYPE: Please Insert unsigned Interger Type!!" << endl << endl;
			//removeProductsFromProductsList();
		}
		else if (id >= 0) {
	
			for (int i = 0; i < categoriesdata.GetSize(); i++) {
				Categories cg = categoriesdata.Get(i);
				if ((cg.CategoryID) == id) {
					categoriesdata.Remove(i);
					cout << endl << "The Product with the ID [" << id << "] is Removed from Products List." << endl;
				}
				else {}
			}
		}
	
		categoriesdata.ExportToFile(categoriesFile);
	
		cout << endl << "NOW, ALL PRODUCTS IN PRODUCTS FILE ARE: " << endl;
	
		for (int i = 0; i < categoriesdata.GetSize(); i++) {
			Categories cg = categoriesdata.Get(i);
			cout << cg.ToString() << endl;
		}
	
		//manageCategories();
	}
	else {
		cout << "Your Chosen is \"Exit Menu\"" << endl << endl;
		//menuOptions();
	}
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
	cout << "**Enter OrderDate(yyyy-mm-dd): ";
    cin >> order.OrderDate;
    order.EmployeeID = 1;
    // Util u;
	// order.OrderDate = u.GetToday();
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
    // OrdersData ordersdata("Orders.data");
    // OrderDetailsData orderdetailsdata("OrderDetails.data");
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
        // cout << "**(5)Orders" << endl;
        // cout << "**(6)OrderDetails" << endl;
        cout << "**(5)Shippers" << endl;
        cout << "**(6)Suppliers" << endl;
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
            // case 5:
            //     cout << "Data Orders:" << endl;
            //     cout << "OrderID, CustomerID, EmployeeID, OrderDate, ShipperID" << endl;
            //     for (int i=0; i < ordersdata.getSize(); i++){
            //         Orders item = ordersdata.get(i);
            //         cout << item.toString() << endl;
            //     }
            //     system("pause");
            //     break;
            // case 6:
            //     cout << "Data OrderDetails:" << endl;
            //     cout << "OrderDetailID, OrderID, ProductID, Quantity" << endl;
            //     for (int i=0; i < orderdetailsdata.getSize(); i++){
            //         OrderDetails item = orderdetailsdata.get(i);
            //         cout << item.toString() << endl;
            //     }
            //     system("pause");
            //     break;
            case 5:
                cout << "Data Shippers:" << endl;
                cout << "ShipperID, ShipperName, Phone" << endl;
                for (int i=0; i < shippersdata.GetSize(); i++){
                    Shippers item = shippersdata.get(i);
                    cout << item.Tostring() << endl;
                }
                system("pause");
                break;
            case 6:
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
    cout << " Update Information Supplier " << endl;
	cout << " Select The Number " << endl;
	cout << " 1.Insert The Information " << endl;
	cout << " 2.Update The Information " << endl;
	cout << " 3.Print The Information " << endl;
	cout << " 4.Exit 				  " << endl;
	int n;
	do
	{
	cout << "Enter Your Number" << endl ;
	cin >> n;
	} while (n <= 0 && n > 4);
	switch (n)
	{
	case 1:
		//InsertSupplier()
		{
			cout << "Enter your number Import Supplier to stock" << endl;
			int n;
			cin >> n;
			Supplier s;
			DataSupplier d("Suppliers.data");
			for(int i = 0;i < n ;i++)
			{
				cout << "Enter the Supplier " << endl;
				cout << "Number" << i+1 << endl;
				cout << "SupplierID" << endl;
				cin >> s.SupplierID ;
				cout << endl;
				cout << "SupplierName" << endl;
				cin >> s.SupplierName ;
				cout << endl;
				cout << "ContactName" << endl;
				cin >> s.ContactName ;
				cout << endl;
				cout << "Address" << endl;
				cin >> s.Address ;
				cout << endl;
				cout << "City" << endl;
				cin >> s.City ;
				cout << endl;
				cout << "PostalCode" << endl;
				cin >> s.PostalCode ;
				cout << endl;
				cout << "Country" << endl;
				cin >> s.Country ;
				cout << endl;
				cout << "Phone" << endl;
				cin >> s.Phone ;
				cout << endl;

				cout << "Your SupplierID is: " << s.SupplierID  << endl;
				cout << "Your SupplierName is: " << s.SupplierName << endl;
				cout << "Your ContactName is: " << s.ContactName << endl;
				cout << "Your Address is: " << s.Address << endl;
				cout << "Your City is: " << s.City << endl;
				cout << "Your Address is: " << s.Address << endl;
				cout << "Your PostalCode is: " << s.PostalCode << endl;
				cout << "Your Country is: " <<  s.Country << endl;
				cout << "Your Phone is: " <<  s.Phone << endl;
				d.Pushback(s);
			}
				cout << " Complete !! " << endl;
				d.Exportofile("Suppliers.data");
		//		UpdateSupplier();
		};
		break;
	case 2:
	//	UpdateSUpplier();
	{		DataSupplier d("Suppliers.data");
				cout << " Enter the number your Update " << endl;
				Supplier s;
				int number ;
				cin >> number;
				cout << endl;
				cout << "SupplierID" << endl;
				cin >> s.SupplierID ;
				cout << endl;
				cout << "SupplierName" << endl;
				cin >> s.SupplierName ;
				cout << endl;
				cout << "ContactName" << endl;
				cin >> s.ContactName ;
				cout << endl;
				cout << "Address" << endl;
				cin >> s.Address ;
				cout << endl;
				cout << "City" << endl;
				cin >> s.City ;
				cout << endl;
				cout << "PostalCode" << endl;
				cin >> s.PostalCode ;
				cout << endl;
				cout << "Country" << endl;
				cin >> s.Country ;
				cout << endl;
				cout << "Phone" << endl;
				cin >> s.Phone ;
				cout << endl;
			d.Update(number,s);
			Supplier t;
			for(int i=0;i<d.GetSize();i++)
			{
			s = d.get(i); 
			cout << s.Tostring() << endl;
			}
			d.Exportofile("Suppliers.data");
		//	UpdateSupplier();
	};
				break;
	case 3:
		//PrintSupplier();
		{	DataSupplier d("Suppliers.data");
			Supplier s;
			for(int i=0;i<d.GetSize();i++)
			{
			s = d.get(i);
			cout << s.Tostring() << endl;
			}
		//	UpdateSupplier();
		};
		break;
	case 4:
		break;
	}
}

