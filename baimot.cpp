#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
struct ngay
{
	int ngay1, thang, nam;
};
struct sinhVien
{
	string name;
	string maSv;
	int gioiTinh;
	ngay ngaySinh;
	string diaChi;
	string lop;
	string khoa;
};

struct node
{
	sinhVien data;
	node* next;
};

// nhap sinh vien
sinhVien* nhapsv() {
	sinhVien* sv = new sinhVien();
	cout << " nhap vao ten sv : ";
	getline(cin, sv->name);
	cout << "nhap vao ma sv : ";
	cin >> sv->maSv;
	cout << "nhap vao gioi tinh (1 nam , 2 nu) : ";
	cin >> sv->gioiTinh;
	cout << "nhap vao ngay thang nam sinh : ";
	cin >> sv->ngaySinh.ngay1 >> sv->ngaySinh.thang >> sv->ngaySinh.nam;
	cin.ignore();
	cout << "nhap vao dia chi : ";
	getline(cin, sv->diaChi);
	cout << "nhap vao lop : ";
	getline(cin, sv->lop);
	cout << "nhap vao khoa : ";
	getline(cin, sv->khoa);
	return sv;
}

// in ra sinh vien 
void print(sinhVien sv) {
	cout << "------------------------------";
	cout << "Ten : " << sv.name << endl;
	cout << "Ma sv : " << sv.maSv << endl;
	cout << "gioi tinh : " << sv.gioiTinh << endl;
	cout << "ngay sinh : " << sv.ngaySinh.ngay1 << "/" << sv.ngaySinh.thang << "/" << sv.ngaySinh.nam << endl;
	cout << " dia chi : " << sv.diaChi << endl;
	cout << "lop : " << sv.lop << endl;
	cout << "khoa :" << sv.khoa << endl;
}

// make node
node* newsv(sinhVien* sv) {
	node* newst = new node();
	newst->data = *sv;
	newst->next = NULL;
	return newst;
}
// them vao cuoi
void pushback(node** head, sinhVien* sv) {
	node* hsm = newsv(sv);
	node* temp = *head;
	if (*head == NULL) {
		*head = hsm;
		return;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = hsm;
	}

}
void duyet(node* head) {
	while (head != NULL) {
		cout << "Ten : " << head->data.name << endl;
		cout << "Ma sv : " << head->data.maSv << endl;
		cout << "gioi tinh : " << head->data.gioiTinh << endl;
		cout << "ngay sinh : " << head->data.ngaySinh.ngay1 << "/" << head->data.ngaySinh.thang << "/" << head->data.ngaySinh.nam << endl;
		cout << " dia chi : " << head->data.diaChi << endl;
		cout << "lop : " << head->data.lop << endl;
		cout << "khoa :" << head->data.khoa << endl;
		head = head->next;
	}
}
int main() {
	node* head = NULL;
	sinhVien* sv = new sinhVien();
	while (1)
	{

		cout << "----------------------------" << endl;
		cout << "1. Them vao cuoi" << endl;
		cout << "2. duyet" << endl;
		int lc;
		cin >> lc;
		cin.ignore();
		if (lc == 1) {
			sv = nhapsv();
			pushback(&head, sv);
		}
		else
		{
			if (lc == 2) {
				duyet(head);
			}
			else
			{
				break;
			}
		}

	}
}