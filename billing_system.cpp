
#include <iostream>
using namespace std;
// ofstream b1("billing.txt", ios::app);

string name[100];
int quantity[100], ID[100];
double price[100];
int totalProducts = 0;

string customerName[100], phone[100];
int customerID[100];
int totalCustomers = 0;

void add_product()
{

    ID[totalProducts] = totalProducts + 1;

    cout << "Enter the Product name : ";
    cin >> name[totalProducts];

    cout << "Enter the Quantity : ";
    cin >> quantity[totalProducts];

    cout << "Enter the Price : ";
    cin >> price[totalProducts];

    totalProducts++;
    cout << "Product Added Successfully!\n";
}

void update_product()
{
    int id, found = -1;

    cout << "Enter Product ID : ";
    cin >> id;

    for (int i = 0; i < totalProducts; i++)
    {
        if (ID[i] == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        cout << "Product Not Found!\n";
        return;
    }
    else
    {
        cout << "Enter New Name : ";
        cin >> name[found];

        cout << "Enter New Quantity : ";
        cin >> quantity[found];

        cout << "Enter New Price : ";
        cin >> price[found];

        cout << "Product Updated Successfully!\n";
    }
}

// void delete_product()
// {
//     int id, found = -1;

//     cout << "Enter Product ID : ";
//     cin >> id;

//     for (int i = 0; i < totalProducts; i++)
//     {
//         if (ID[i] == id)
//         {
//             found = i;
//             break;
//         }
//     }

//     if (found == -1)
//     {
//         cout << "Product Not Found!\n";
//         return;
//     }

//     for (int i = found; i < totalProducts - 1; i++)
//     {
//         ID[i] = ID[i + 1];
//         name[i] = name[i + 1];
//         quantity[i] = quantity[i + 1];
//         price[i] = price[i + 1];
//     }

//     totalProducts--;
//     cout << "Product Deleted Successfully!\n";
// }

void display_product()
{
    if (totalProducts == 0)
    {
        cout << "No Products Available!\n";
        return;
    }

    for (int i = 0; i < totalProducts; i++)
    {
        cout << "ID : " << ID[i] << " | "
             << name[i] << " | Quantity : "
             << quantity[i] << " | Price : "
             << price[i] << endl;
    }
}

void search_product()
{
    int id, found = 0;

    cout << "Enter Product ID : ";
    cin >> id;

    for (int i = 0; i < totalProducts; i++)
    {
        if (ID[i] == id)
        {
            cout << "ID : " << ID[i] << endl;
            cout << "Name : " << name[i] << endl;
            cout << "Quantity : " << quantity[i] << endl;
            cout << "Price : " << price[i] << endl;

            found = 1;
            break;
        }
    }

    if (found == 0)
        cout << "Product Not Found!\n";
}

void Product_Management()
{
    int choice;

    while (true)
    {
        cout << "\n1. Add Product\n";
        cout << "2. Update Product\n";
        // cout << "3. Delete Product\n";
        cout << "4. Display Product\n";
        cout << "5. Search Product\n";
        cout << "6. Back\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_product();
            break;
        case 2:
            update_product();
            break;
        case 3:
            // delete_product();
            break;
        case 4:
            display_product();
            break;
        case 5:
            search_product();
            break;
        case 6:
            return;
        default:
            cout << "INVALID NUMBER\n";
        }
    }
}

void add_customer()
{
    if (totalCustomers >= 100)
    {
        cout << "Customer storage is full!\n";
        return;
    }

    customerID[totalCustomers] = totalCustomers + 1;

    cout << "Enter Customer Name : ";
    cin >> customerName[totalCustomers];

    cout << "Enter Phone Number : ";
    cin >> phone[totalCustomers];

    cout << "Customer ID : " << customerID[totalCustomers] << endl;

    totalCustomers++;
    cout << "Customer Added Successfully!\n";
}

void delete_customer()
{
    int id, found = -1;

    cout << "Enter Customer ID : ";
    cin >> id;

    for (int i = 0; i < totalCustomers; i++)
    {
        if (customerID[i] == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        cout << "Customer Not Found!\n";
        return;
    }

    for (int i = found; i < totalCustomers - 1; i++)
    {
        customerID[i] = customerID[i + 1];
        customerName[i] = customerName[i + 1];
        phone[i] = phone[i + 1];
    }

    totalCustomers--;
    cout << "Customer Deleted Successfully!\n";
}

void search_customer()
{
    int id, found = 0;

    cout << "Enter Customer ID : ";
    cin >> id;

    for (int i = 0; i < totalCustomers; i++)
    {
        if (customerID[i] == id)
        {
            cout << "ID : " << customerID[i] << endl;
            cout << "Name : " << customerName[i] << endl;
            cout << "Phone : " << phone[i] << endl;

            found = 1;
            break;
        }
    }

    if (found == 0)
        cout << "Customer Not Found!\n";
}

void view_history()
{
    cout << "Purchase history feature is not implemented yet.\n";
}

void Customer_Management()
{
    int choice;

    while (true)
    {
        cout << "\n1. Add Customer\n";
        cout << "2. Delete Customer\n";
        cout << "3. Search Customer\n";
        cout << "4. View History\n";
        cout << "5. Back\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_customer();
            break;
        case 2:
            delete_customer();
            break;
        case 3:
            search_customer();
            break;
        case 4:
            view_history();
            break;
        case 5:
            return;
        default:
            cout << "INVALID NUMBER\n";
        }
    }
}

// void preview()
// {
//     int id, found =-1;

// }


void Billing()
{
    int id, qty, customer, found;

    double total = 0;

    if (totalCustomers == 0 || totalProducts == 0)
    {
        cout << "Add products and customers first!\n";
        return;
    }

    cout << "Enter Customer ID : ";
    cin >> customer;

    found = -1;

    for (int i = 0; i < totalCustomers; i++)
    {
        if (customerID[i] == customer)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        cout << "Customer Not Found!\n";
        return;
    }

    while (true)
    {
        display_product();

        cout << "Enter Product ID (0 to finish) : ";
        cin >> id;

        if (id == 0)
            break;

        int index = -1;

        for (int i = 0; i < totalProducts; i++)
        {
            if (ID[i] == id)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Product Not Found!\n";
            continue;
        }

        cout << "Enter Quantity : ";
        cin >> qty;

        if (qty <= 0 || qty > quantity[index])
        {
            cout << "Invalid Quantity or Insufficient Stock!\n";
            continue;
        }

        double amount = price[index] * qty;

        total += amount;
        quantity[index] -= qty;

        cout << name[index] << " x " << qty
             << " = Rs. " << amount << endl;
    }

    cout << "\nCustomer : " << customerName[found] << endl;
    cout << "Total Bill : Rs. " << total << endl;
    cout << "Thank You For Shopping!\n";

}

int main()
{
    int choice;

    cout << "-------------------------------------\n";
    cout << "-                                   -\n";
    cout << "-       WELCOME TO ARYA STORE       -\n";
    cout << "-                                   -\n";
    cout << "-------------------------------------\n";

    while (true)
    {
        cout << "\n1. Product Management\n";
        cout << "2. Customer Management\n";
        cout << "3. Billing\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Product_Management();
            break;
        case 2:
            Customer_Management();
            break;
        case 3:
            Billing();
            break;

        case 4:
            cout << "-------------------------------------\n";
            cout << "-       THANKS FOR VISITING         -\n";
            cout << "-------------------------------------\n";
            return 0;

        default:
            cout << "INVALID NUMBER\n";
        }
    }
}
