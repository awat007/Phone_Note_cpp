#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <tuple>
using namespace std;
enum OS
{
    iOS,
    Android,
    windows,
    phone
};
enum Ram
{
    ram2GB,
    ram4GB,
    ram6GB,
    ram8GB,
    ram12GB,
    ram16GB,
    ram32GB,
    ram64GB
};
enum Storage
{
    S16GB,
    S32GB,
    S64GB,
    S128GB,
    S256GB,
    S512GB,
    S1TB,
    S2TB
};
enum color
{
    white,
    black,
    gold
};
struct mobile
{
    string name;
    string company;
    OS os;
    Ram ram;
    Storage s;
    color c;
    string Price;
    int number_avaible;
    int number_sold;
};

void add_phone(mobile *&, int &);
void Remove_phone(mobile *&, int &);
void showinfo(mobile *&, int);
void Search_phone(mobile *&, int &);
void Print_phones(mobile *&, int &);
void Sort_phone_by_price(mobile *&, int &);
void Change_mobile_info(mobile *&, int &);
void Sell_phone(mobile *&, int &);
void Print_phones_sorted(mobile *&, int &);
void chage_system(mobile *, int);
void change_storage(mobile *, int);
void change_color(mobile *, int);
void change_Ram(mobile *, int);
void change_price(mobile *, int);
void change_number(mobile *, int);
void change_sold(mobile *, int );
int main()
{
    int len = 0;
    bool check = true;
    int x;
    mobile *mobo;
    while (check)
    {
        cout << "enter your choice\n";
        cout << " 1: Add phone\n";
        cout << " 2: Remove phone\n";
        cout << " 3: Sort phone by price\n";
        cout << " 4: Search a phone\n";
        cout << " 5: Cahnge mobile info\n";
        cout << " 6: Sell a phone\n";
        cout << " 7: Print phones\n";
        cout << " 8: Print phones sorted by the most sold to the least\n";
        cout << " 9: Quit\n";
        cin >> x;
        switch (x)
        {
        case 1:
            add_phone(mobo, len);
            break;
        case 2:
            Remove_phone(mobo, len);
            break;
        case 3:
            Sort_phone_by_price(mobo, len);
            break;
        case 4:
            Search_phone(mobo, len);
            break;
        case 5:
            Change_mobile_info(mobo, len);
            break;
        case 6:
            Sell_phone(mobo, len);
            break;
        case 7:
            Print_phones(mobo, len);
            break;
        case 8:
            Print_phones_sorted(mobo, len);
            break;
        case 9:
            check = false;
            break;
        default:
            cout << "your choice is invalid" << endl
                 << "try again\n";
        }
    }
}
void Print_phones_sorted(mobile *&phone, int &len)
{
	for(int i=0; i<len; i++)
	{
		for(int j=0; j<len-1-i; j++)
		{
			if(phone[j].number_sold<phone[j+1].number_sold)
			{
				swap(phone[j],phone[j+1]);
			}
		}
	}
	for(int i=0; i<len; i++)
	{
		showinfo(phone,i);
	}
}
void Sell_phone(mobile *&phone, int &len)
{
	string name;
    string company;
    cout << "plese enter the name of mobile :";
    cin >> name;
    cout << "plese enter the name of company :";
    cin >> company;
    int flag=1;
    int x;
    for(int i=0; i<len; i++)
    {
    	if((phone[i].name==name) && (phone[i].company==company))
    	{
    		showinfo(phone,i);
    		cout<<"how much do you want to sell?\n";
    		cin>>x;
    		if((phone[i].number_avaible!=0) && (phone[i].number_avaible>=x))
    		{
    			phone[i].number_avaible-=x;
    			phone[i].number_sold+=x;
    			showinfo(phone,i);
			}
			else
			{
				cout<<"the phone is not available for sell\n";
			}
    		
		}
		else
		{
			flag=0;
		}
	}
	if(flag=0)
	{
		cout << "Mobile not found!" << endl;
	}
    
}
void addsize(mobile *&phone, int &len)
{
    mobile *ptr = new mobile[len + 1];
    for (int i = 0; i < len; i++)
    {
        ptr[i] = phone[i];
    }
    if (len != 0)
    {
        delete[] phone;
    }
    phone = new mobile[len + 1];
    for (int j = 0; j < len + 1; j++)
    {
        phone[j] = ptr[j];
    }
    delete[] ptr;
    ++len;
    // phone=ptr;
}
void Sort_phone_by_price(mobile *&phone, int &len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1-i; j++)
        {
            if (phone[j].Price > phone[j + 1].Price)
            {
                mobile temp = phone[j];
                phone[j] = phone[j + 1];
                phone[j + 1] = temp;
            }
        }
    }
    
    for(int i=len-1; i>=0; i--)
	{
		showinfo(phone,i);
	}
}
void add_phone(mobile *&phone, int &len)
{
    string name, company;
    int increas, flag = 1, flag2 = 1, flag3 = 1, flag4 = 1, flag5 = 1;
    int x;
    string price;
    int number_sold;
    int number_avaible;
    cout << "plese enter the name of mobile :";
    cin >> name;
    cout << "plese enter the name of company :";
    cin >> company;
    for (int i = 0; i < len; i++)
    {
        if ((name == phone[i].name) && (company == phone[i].company))
        {
            cout << "the mobile is available\n";
            cout << "if you want to add phone plese inter number to phone:";
            cin >> increas;
            phone[i].number_avaible += increas;
            flag = 0;
        }
    }
    if (flag == 1)
    {
        addsize(phone, len);
        phone[len - 1].name = name;
        phone[len - 1].company = company;
        while (flag2 == 1)
        {
            cout << "plese Enter the system\n";
            cout << " 1: iOS\n";
            cout << " 2: Android\n";
            cout << " 3: windows\n";
            cout << " 4: phone\n";
            cin >> x;
            switch (x)
            {
            case 1:
                phone[len - 1].os = OS::iOS;
                flag2 = 0;
                break;
            case 2:
                phone[len - 1].os = OS::Android;
                flag2 = 0;
                break;
            case 3:
                phone[len - 1].os = OS::windows;
                flag2 = 0;
                break;
            case 4:
                phone[len - 1].os = OS::phone;
                flag2 = 0;
                break;
            default:
                cout << "your choice is invalid" << endl
                     << "try again\n";
                flag2 = 1;
            }
        }
        while (flag3 == 1)
        {
            cout << "plese Enter the Ram\n";
            cout << " 1: 2Gb \n";
            cout << " 2: 4GB \n";
            cout << " 3: 6GB \n";
            cout << " 4: 8GB\n";
            cout << " 5: 12GB\n";
            cout << " 6: 16GB\n";
            cout << " 7: 32GB\n";
            cout << " 8: 64GB\n";
            cin >> x;
            switch (x)
            {
            case 1:
                phone[len - 1].ram = Ram::ram2GB;
                flag3 = 0;
                break;
            case 2:
                phone[len - 1].ram = Ram::ram4GB;
                flag3 = 0;
                break;
            case 3:
                phone[len - 1].ram = Ram::ram6GB;
                flag3 = 0;
                break;
            case 4:
                phone[len - 1].ram = Ram::ram8GB;
                flag3 = 0;
                break;
            case 5:
                phone[len - 1].ram = Ram::ram12GB;
                flag3 = 0;
                break;
            case 6:
                phone[len - 1].ram = Ram::ram16GB;
                flag3 = 0;
                break;
            case 7:
                phone[len - 1].ram = Ram::ram32GB;
                flag3 = 0;
                break;
            case 8:
                phone[len - 1].ram = Ram::ram64GB;
                flag3 = 0;
                break;
            default:
                cout << "your choice is invalid" << endl
                     << "try again\n";
                flag3 = 1;
            }
        }
        while (flag4 == 1)
        {
            cout << "plese Enter the storage\n";
            cout << " 1: 16Gb \n";
            cout << " 2: 32GB \n";
            cout << " 3: 64GB \n";
            cout << " 4: 128GB\n";
            cout << " 5: 256GB\n";
            cout << " 6: 512GB\n";
            cout << " 7: 1TB\n";
            cout << " 8: 2TB\n";
            cin >> x;
            switch (x)
            {
            case 1:
                phone[len - 1].s = Storage::S16GB;
                flag4 = 0;
                break;
            case 2:
                phone[len - 1].s = Storage::S32GB;
                flag4 = 0;
                break;
            case 3:
                phone[len - 1].s = Storage::S64GB;
                flag4 = 0;
                break;
            case 4:
                phone[len - 1].s = Storage::S128GB;
                flag4 = 0;
                break;
            case 5:
                phone[len - 1].s = Storage::S256GB;
                flag4 = 0;
                break;
            case 6:
                phone[len - 1].s = Storage::S512GB;
                flag4 = 0;
                break;
            case 7:
                phone[len - 1].s = Storage::S1TB;
                flag4 = 0;
                break;
            case 8:
                phone[len - 1].s = Storage::S2TB;
                flag4 = 0;
                break;
            default:
                cout << "your choice is invalid" << endl
                     << "try again\n";
                flag4 == 1;
            }
        }
        while (flag5 == 1)
        {
            cout << "plese Enter the color\n";
            cout << " 1: white\n";
            cout << " 2: black\n";
            cout << " 3: gold\n";
            cin >> x;
            switch (x)
            {
            case 1:
                phone[len - 1].c = color::white;
                flag5 = 0;
                break;
            case 2:
                phone[len - 1].c = color::black;
                flag5 = 0;
                break;
            case 3:
                phone[len - 1].c = color::gold;
                flag5 = 0;
                break;
            default:
                cout << "your choice is invalid" << endl
                     << "try again\n";
                flag5 = 1;
            }
        }
        cout << "please Enter the price of phone :";
        cin >> price;
        phone[len - 1].Price = price;
        cout << "please Enter the number of available :";
        cin >> number_avaible;
        phone[len - 1].number_avaible = number_avaible;
        cout << "please Enter the number of sold :";
        cin >> number_sold;
        phone[len - 1].number_sold = number_sold;
    }
}

void Remove_phone(mobile *&phone, int &len)
{
    string name;
    string company;
    cout << "plese enter the name of mobile for delete:";
    cin >> name;
    cout << "plese enter the name of company for delete:";
    cin >> company;
    int flag = 0;
    int temp;
    for (int i = 0; i < len; i++)
    {
        if ((name == phone[i].name) && (company == phone[i].company))
        {
            flag = 1;
            for (int j = i; j < len - 1; j++)
            {
                phone[j] = phone[j + 1];
            }
            mobile *ptr1 = new mobile[len - 1];
            for (int k = 0; k < len - 1; k++)
            {
                ptr1[k] = phone[k];
            }
            delete[] phone;
            phone = new mobile[len - 1];
            for (int k = 0; k < len - 1; k++)
            {
                phone[k] = ptr1[k];
            }
            delete[] ptr1;
            len--;
        }
    }
    if (flag == 1)
    {
        cout << "mobile succesfully deleted\n";
    }
    else
    {
        cout << "Mobile not found!" << endl;
    }
}

void showinfo(mobile *&phone, int i)
{

    cout << "................................." << endl;
    cout << " mobile name : " << phone[i].name << endl;
    cout << " Manufacturer company : " << phone[i].company << endl;
    {
        if (phone[i].os == OS::iOS)
        {
            cout << " system : iOS" << endl;
        }
        else if (phone[i].os == OS::Android)
        {
            cout << " system : android" << endl;
        }
        else if (phone[i].os == OS::windows)
        {
            cout << " system : windows" << endl;
        }
        else if (phone[i].os == OS::phone)
        {
            cout << " system : phone" << endl;
        }
    }

    {
        if (phone[i].ram == ram2GB)
        {
            cout << " Ram : 2GB" << endl;
        }
        else if (phone[i].ram == ram4GB)
        {
            cout << " Ram : 4GB" << endl;
        }
        else if (phone[i].ram == ram6GB)
        {
            cout << " Ram : 6GB" << endl;
        }
        else if (phone[i].ram == ram8GB)
        {
            cout << " Ram : 8GB" << endl;
        }
        else if (phone[i].ram == ram12GB)
        {
            cout << " Ram : 12GB" << endl;
        }
        else if (phone[i].ram == ram16GB)
        {
            cout << " Ram : 16GB" << endl;
        }
        else if (phone[i].ram == ram32GB)
        {
            cout << " Ram : 32GB" << endl;
        }
        else if (phone[i].ram == ram64GB)
        {
            cout << " Ram : 64GB" << endl;
        }
    }

    {
        if (phone[i].s == Storage::S16GB)
        {
            cout << " storage : 16GB" << endl;
        }
        else if (phone[i].s == Storage::S32GB)
        {
            cout << " storage : 32GB" << endl;
        }
        else if (phone[i].s == Storage::S64GB)
        {
            cout << " storage : 64GB" << endl;
        }
        else if (phone[i].s == Storage::S128GB)
        {
            cout << " storage : 128GB" << endl;
        }
        else if (phone[i].s == Storage::S256GB)
        {
            cout << " storage : 256GB" << endl;
        }
        else if (phone[i].s == Storage::S512GB)
        {
            cout << " storage : 512GB" << endl;
        }
        else if (phone[i].s == Storage::S1TB)
        {
            cout << " storage : 1TB" << endl;
        }
        else if (phone[i].s == Storage::S2TB)
        {

            cout << " storage : 2TB" << endl;
        }
    }
    {
        if (phone[i].c == color::black)
        {
            cout << " color : black" << endl;
        }
        else if (phone[i].c == color::gold)
        {
            cout << " color : gold" << endl;
        }
        else if (phone[i].c == color::white)
        {
            cout << " color : white" << endl;
        }
    }
    cout << " price : " << phone[i].Price << endl;
    cout << " number of available : " << phone[i].number_avaible << endl;
    cout << " number of sold : " << phone[i].number_sold << endl;
    cout << "................................." << endl;

    cout << endl;
}
void Search_phone(mobile *&phone, int &len)
{
    string name;
    string company;
    cout << "plese enter the name of mobile for search:";
    cin >> name;
    cout << "plese enter the name of company for search:";
    cin >> company;
    int flag = 1;
    for (int i = 0; i < len; i++)
    {
        if ((name == phone[i].name) && (company == phone[i].company))
        {
            cout << "mobile succesfully found\n";
            showinfo(phone, i);
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "Mobile not found!" << endl;
    }
}
void Print_phones(mobile *&phone, int &len)
{
    for (int i = 0; i < len; i++)
    {
        showinfo(phone, i);
    }
}
void change_system(mobile *phone, int i)
{
    int flag = 1;
    int x;
    while (flag == 1)
    {
        cout << "plese Enter the system\n";
        cout << " 1: iOS\n";
        cout << " 2: Android\n";
        cout << " 3: windows\n";
        cout << " 4: phone\n";
        cout << " 5: back\n";
        cin >> x;
        switch (x)
        {
        case 1:
            phone[i].os = OS::iOS;
            showinfo(phone, i);

            break;
        case 2:
            phone[i].os = OS::Android;
            showinfo(phone, i);

            break;
        case 3:
            phone[i].os = OS::windows;
            showinfo(phone, i);

            break;
        case 4:
            phone[i].os = OS::phone;
            showinfo(phone, i);
            break;
        case 5:
            flag = 0;
            break;
        default:
            cout << "your choice is invalid" << endl
                 << "try again\n";
            break;
        }
    }
}
void change_Ram(mobile *phone, int i)
{
    int flag = 1;
    int x;
    while (flag == 1)
    {
        cout << "plese Enter the Ram\n";
        cout << " 1: 2Gb \n";
        cout << " 2: 4GB \n";
        cout << " 3: 6GB \n";
        cout << " 4: 8GB\n";
        cout << " 5: 12GB\n";
        cout << " 6: 16GB\n";
        cout << " 7: 32GB\n";
        cout << " 8: 64GB\n";
        cout << " 9: back\n";
        cin >> x;
        switch (x)
        {
        case 1:
            phone[i].ram = Ram::ram2GB;
            showinfo(phone, i);

            break;

        case 2:
            phone[i].ram = Ram::ram4GB;
            showinfo(phone, i);

            break;

        case 3:
            phone[i].ram = Ram::ram6GB;
            showinfo(phone, i);

            break;

        case 4:
            phone[i].ram = Ram::ram8GB;
            showinfo(phone, i);

            break;

        case 5:
            phone[i].ram = Ram::ram12GB;
            showinfo(phone, i);

            break;

        case 6:
            phone[i].ram = Ram::ram16GB;
            showinfo(phone, i);

            break;

        case 7:
            phone[i].ram = Ram::ram32GB;
            showinfo(phone, i);

            break;

        case 8:
            phone[i].ram = Ram::ram64GB;
            showinfo(phone, i);

            break;
        case 9:
            flag = 0;
            break;

        default:
            cout << "your choice is invalid" << endl
                 << "try again\n";
            break;
        }
    }
}
void change_storage(mobile *phone, int i)
{
    int flag = 1;
    int x;
    while (flag == 1)
    {
        cout << "plese Enter the storage\n";
        cout << " 1: 16Gb \n";
        cout << " 2: 32GB \n";
        cout << " 3: 64GB \n";
        cout << " 4: 128GB\n";
        cout << " 5: 256GB\n";
        cout << " 6: 512GB\n";
        cout << " 7: 1TB\n";
        cout << " 8: 2TB\n";
        cout << " 9: back\n";
        cin >> x;
        if (x == 1)
        {
            phone[i].s = Storage::S16GB;
            showinfo(phone, i);
        }
        else if (x == 2)
        {
            phone[i].s = Storage::S32GB;
            showinfo(phone, i);
        }
        else if (x == 3)
        {
            phone[i].s = Storage::S64GB;
            showinfo(phone, i);
        }
        else if (x == 4)
        {
            phone[i].s = Storage::S128GB;
            showinfo(phone, i);
        }
        else if (x == 5)
        {
            phone[i].s = Storage::S256GB;
            showinfo(phone, i);
        }
        else if (x == 6)
        {
            phone[i].s = Storage::S512GB;
            showinfo(phone, i);
        }
        else if (x == 7)
        {
            phone[i].s = Storage::S1TB;
            showinfo(phone, i);
        }
        else if (x == 8)
        {
            phone[i].s = Storage::S2TB;
            showinfo(phone, i);
        }
        else if (x == 9)
        {
            flag = false;
        }
        else
        {
            cout << "your choice is invalid" << endl
                 << "try again\n";
        }
    }
}
void change_color(mobile *phone, int i)
{
    bool check = true;
    int x;
    while (check)
    {
        cout << "plese Enter the color\n";
        cout << " 1: white\n";
        cout << " 2: black\n";
        cout << " 3: gold\n";
        cout << " 4: back\n";

        cin >> x;
        switch (x)
        {
        case 1:
            phone[i].c = color::white;
            showinfo(phone, i);
            break;
        case 2:
            phone[i].c = color::black;
            showinfo(phone, i);
            break;
        case 3:
            phone[i].c = color::gold;
            showinfo(phone, i);
            break;
        case 4:
            check = false;
            break;
        default:
            cout << "your choice is invalid" << endl
                 << "try again\n";
        }
    }
}
void change_price(mobile *phone, int i)
{
    string x;
    cout << "new price : ";
    cin >> x;
    phone[i].Price = x;
    showinfo(phone, i);
}
void change_number(mobile *phone, int i)
{
    int x;
    cout << "Enter new number available :";
    cin >> x;
    phone[i].number_avaible = x;
    showinfo(phone, i);
}
void change_sold(mobile *phone, int i)
{
    int x;
    cout << "Enter new number sold :";
    cin >> x;
    phone[i].number_sold = x;
    showinfo(phone, i);
}
void Change_mobile_info(mobile *&phone, int &len)
{
    string name;
    string company;
    cout << "plese enter the name of mobile for search:";
    cin >> name;
    cout << "plese enter the name of company for search:";
    cin >> company;
    int flag = 1, flag2 = 1, flag3 = 1, flag4 = 1, flag5 = 1;
    int x;
    bool check = true;
    for (int i = 0; i < len; i++)
    {
        if ((name == phone[i].name) && (company == phone[i].company))
        {
            showinfo(phone, i);
            flag = 1;
            while (flag2 == 1)
            {
                cout << "enter your choice\n";
                cout << " 1: change system\n";
                cout << " 2: change Ram\n";
                cout << " 3: change storage\n";
                cout << " 4: change color\n";
                cout << " 5: change price\n";
                cout << " 6: change number of available\n";
                cout << " 7: number of sold\n";
                cout << " 8: back menu\n";
                cin >> x;
                switch (x)
                {
                case 1:
                    change_system(phone, i);
                    break;
                case 2:
                    change_Ram(phone, i);
                    break;

                case 3:
                    change_storage(phone, i);
                    break;
                case 4:
                    change_color(phone, i);
                    break;

                case 5:
                    change_price(phone, i);
                    break;

                case 6:
                    change_number(phone, i);
                    break;

                case 7:
                    change_sold(phone, i);
                    break;
                case 8:
                    flag2 = 0;
                    break;
                default:
                    cout << "your choice is invalid" << endl
                         << "try again\n";
                    break;
                }
            }
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "Mobile not found!" << endl;
    }
}
