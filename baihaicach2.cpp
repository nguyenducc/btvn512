#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* makenode(int data) {
	node* newnode = new node();
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void duyet(node* tail) {
	node* temp = tail;
	if (tail != NULL) {
		do
		{
			temp = temp->next;
			cout << temp->data << " ";
		} while (temp != tail);
		cout << endl << "---------------";
	}
}

node* pushhead(node* tail, int data) {
	node* newnode = makenode(data);
	if (tail == NULL) {
		tail = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->next = tail->next;
		tail->next = newnode;
	}
	return tail;
}
node* pushback(node* tail, int data) {
	return pushhead(tail, data)->next;
}

node* xoavitri(node* tail, int vitri) {
	node* temp = tail;
	int n = sizeof(*tail);
	if (vitri <1 || vitri>n) {
		cout << "khong xoa duoc";
	}
	else
	{
		if (n == 1) {
			tail = NULL;
			delete temp;
		}
		else
		{
			for (int i = 1; i <= vitri - 1; i++)
			{
				temp = temp->next;
			}node* nodexoa = temp->next;
			temp->next = temp->next->next;
			delete nodexoa;
		}

	}
	return tail;
}
int main() {
	node* tail = NULL;
	int k;
	cout << "nhap vao k = ";
	cin >> k;
	while (1)
	{
		cout << endl;
		cout << "1.them nguoi " << endl;
		cout << "2.choi " << endl;
		cout << "3. in ra so nguoi con lai " << endl;
		int lc;
		cin >> lc;
		if (lc == 1) {
			int data;
			cout << "nhap vao ma ng choi ";
			cin >> data;
			tail = pushback(tail, data);
		}
		else {
			if (lc == 2) {
				{
					tail = xoavitri(tail, k);
					tail = tail->next->next;
				}
			}
			else
			{
				if (lc == 3) {
					duyet(tail);
				}
			}
		}
	}
}
