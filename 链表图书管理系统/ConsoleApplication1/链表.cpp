#include<iostream>
#include<string>
using namespace std;

class Book
{
public:
	int num;
	double price;
	Book *next;
};

Book *head = NULL;

bool check(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] > '9' || str[i] < '0') && (str[i] != '.'))
			return false;
	}
	return true;
}

void showbook(Book *head)
{
	cout << "图书信息如下"<<endl;
	while(head)
	{
		cout << "num:  " << head->num << "\t";
		cout << "price:  " << head->price << endl;
		head = head->next;
	}
}

void Delete(Book *head,int num)
{
	Book *l;
	if (head->num == num)
	{
		l = head;
		head = head->next;
		delete l;	
		::head = head->next;
		cout << "DELETE" << endl;
		return;
	}
	if (head->next == NULL)
	{
		cout << "Can Not Find" << endl;
		return;
	}
	while (head)
	{
		if (head->next == NULL)
		{
			cout << "Can Not Find Num" << endl;
			return;
		}
		while (head->next->num == num)
		{
			l = head->next;
			head->next = l->next;
			delete l;
			cout << "OK" << endl;
			return;
		}
		head = head->next;
	}
	cout << "Can Not Find Num " << endl;
}


Book *creat()
{
	Book *p1, *p2;
	p1 = new Book();
	head = p1;
	p2 = p1;
	cout << "enter the num" << endl;
	string str;
	cin >> str;
	while (!check(str))
	{
		cout << "please enter a num" << endl;
		cin >> str;
	}
	p1->num = atoi(str.c_str());
	if (p1->num != 0)
	{
		cout << "enter the price" << endl;
		string str;
		cin >> str;
		while (!check(str))
		{
			cout << "please enter a price" << endl;
			cin >> str;
		}
		p1->price = atof(str.c_str());
	}
	while (p1->num != 0)
	{
		p2 = p1;
		p1 = new Book();
		cout << "enter num" << endl;
		string str;
		cin >> str;
		while (!check(str))
		{
			cout << "please enter a num" << endl;
			cin >> str;
		}
		p1->num = atoi(str.c_str());
		if (p1->num != 0)
		{
			cout << "enter price" << endl;
			string str;
			cin >> str;
			while (!check(str))
			{
				cout << "please enter a price" << endl;
				cin >> str;
			}
			p1->price = atof(str.c_str());
		}
	p2->next = p1;
	}
	delete p1;
	p2->next = NULL;
	return head;
}
	
void InSertEnd(Book *head,int num,int price)
{//尾插法
	Book *List = new Book;
	Book *l = NULL;
	while (head)
	{
		l = head;
		head = head->next;
	}
	l->next = List;
	List->num = num;
	List->price = price;
	List->next = NULL;
}

void InSertHead(Book *head, int num, int price)
{
	Book *l = new Book;
	l->next = head;
	l->num = num;
	l->price = price;
	::head = l;
}

void InSertMid(Book *head)
{
	cout << "InSertMid Enter The Num(中间插法):" << endl;
	cout << "Enter The New Num Price:" << endl;
	Book *l = new Book;
	cin >> l->num;
	cin >> l->price;
	Book *temp = NULL;
	if (l->num <= head->num)
	{
		l->next = head;
		::head = l;
	}
	while ((l->num > head->num) && (head->next != NULL))
	{
		temp = head;
		head = head->next;
	}
	if (l->num > head->num)
	{
		head->next = l;
	}
	else
	{
		temp->next = l;
		l->next = head;
	}
}
	
int main()
{
	head = creat();
	showbook(head);
	cout << "Enter The Num (Delete)" << endl;
	int ItsNum;
	cin >>  ItsNum;
	Delete(head, ItsNum);
	showbook(head);
	cout << "InSert ,Enter The Num And Price(尾插法)" << endl;
	cin >> ItsNum;
	int ItsPrice;
	cin >> ItsPrice;
	InSertEnd(head, ItsNum, ItsPrice);
	showbook(head);
	cout << "InSert ,Enter The Num And Price(头插法)" << endl;
	cin >> ItsNum;
	cin >> ItsPrice;
	InSertHead(head,ItsNum,ItsPrice);
	showbook(head);
	InSertMid(head);
	showbook(head);
	InSertMid(head);
	showbook(head);
	return  0;
}
