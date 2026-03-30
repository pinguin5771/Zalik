#include "ArrayTemplate.h"
#include "Date.h"
#include "Delivery.h"
#include "Package.h"
#include <iomanip>
#include <cstring>


void showTitleP()
{
	cout << "\n\n+-----------------+-----------------+----------+----------------+\n";
	cout << "|" << setw(17) << "Package number" << "|" << setw(17) << "Package type" << "|"
		<< setw(10) << "Weight" << "|" << setw(16) << "Delivery price" << "|\n";
	cout << "+-----------------+-----------------+----------+----------------+\n";
}

void showTitleD()
{
	cout << "\n\n+-----------------------+----------------------------+---------------+---------------+---------------+\n";
	cout << "|" << setw(23) << "Courier Full Name" << "|" << setw(28) << "Recipient Adress" << "|"
		<< setw(15) << "Package number" << "|" << setw(15) << "Delivery date" << "|"
		<< setw(15) << "Status" << "|\n";
	cout << "+-----------------------+----------------------------+---------------+---------------+---------------+\n";
}

void sortArrDown(Delivery* &arrDelivery, int size)
{
	Delivery temp;
	int indexMax = 0, j = 0;
	while (j < size)
	{
		float max = arrDelivery[j].deliveryDate.year*10000+
			arrDelivery[j].deliveryDate.month*100+
			arrDelivery[j].deliveryDate.day;
		int indexMax = j;
		for (int i = j; i < size; i++)
		{
			if (arrDelivery[i].deliveryDate.year * 10000 +
				arrDelivery[i].deliveryDate.month * 100 +
				arrDelivery[i].deliveryDate.day >= max && i != indexMax)
			{
				max = arrDelivery[i].deliveryDate.year * 10000 +
					arrDelivery[i].deliveryDate.month * 100 +
					arrDelivery[i].deliveryDate.day;
				indexMax = i;
			}
		}
		strcpy_s(temp.courierFullName, arrDelivery[j].courierFullName);
		strcpy_s(temp.recipientAdress, arrDelivery[j].recipientAdress);
		temp.thisPackage.packageNumber = arrDelivery[j].thisPackage.packageNumber;
		temp.deliveryDate = arrDelivery[j].deliveryDate;
		temp.status = arrDelivery[j].status;

		strcpy_s(arrDelivery[j].courierFullName, arrDelivery[indexMax].courierFullName);
		strcpy_s(arrDelivery[j].recipientAdress, arrDelivery[indexMax].recipientAdress);
		arrDelivery[j].thisPackage.packageNumber = arrDelivery[indexMax].thisPackage.packageNumber;
		arrDelivery[j].deliveryDate = arrDelivery[indexMax].deliveryDate;
		arrDelivery[j].status = arrDelivery[indexMax].status;

		strcpy_s(arrDelivery[indexMax].courierFullName, temp.courierFullName);
		strcpy_s(arrDelivery[indexMax].recipientAdress, temp.recipientAdress);
		arrDelivery[indexMax].thisPackage.packageNumber = temp.thisPackage.packageNumber;
		arrDelivery[indexMax].deliveryDate = temp.deliveryDate;
		arrDelivery[indexMax].status = temp.status;

		j++;
	}
}

int main()
{
	srand(time(0));
	FILE* fp = nullptr;
	int NPackages = 0, NDelivery = 0, count = 0;
	int menu = -1;
	Package* arrPackages = nullptr;
	Delivery* arrDelivery = nullptr;

	NPackages = 5;
	NDelivery = 5;
	arrPackages = new Package [NPackages]{
		{123456,"Cosmetic",2.3,100},
		{123457,"Meal",5.6,200},
		{123458,"Clothes",2.4,200},
		{123459,"Shoes",3.2,200},
		{123460,"Meal",5.6,500}
	};

	

	arrDelivery = new Delivery[NDelivery]{
		{"Pupkin Mykola", "Borodina str, 3", {123456,"Cosmetic",2.3,100}, {1,6,2026},false},
		{"Shevchenko Taras", "Lavruhina str, 7", {123457,"Meal",5.6,200}, {30,8,2019},true},
		{"Pupkin Mykola", "Kubalchucha str, 15", {123458,"Clothes",2.4,200}, {30,8,2026},false},
		{"Franko Ivan", "Borodina str, 3", {123459,"Shoes",3.2,200}, {30,8,2025},true},
		{"Kozlovsiy Myhaylo","Onore de Balsaka str, 17",{123460,"Meal",5.6,500}, {31,8,2016},true}
	};

	cout << "-----------------------------------";
	cout << "\nWELCOME TO OUR COURIER SERVICE!\n";
	cout << "-----------------------------------\n";

	while (menu != 0)
	{
		cout << "\n          MENU:\n"
			"-----------------------------------\n"
			"1 - Show all packages\n"
			"2 - Show all deliveries\n"
			"3 - Add new package\n"
			"4 - Delete package\n"
			"5 - Search by package number\n"
			"6 - Sort by date\n"
			"7 - Change status of package\n"
			"8 - Save to file\n"
			"9 - Load from file\n"
			"0 - Exit\n"
			"-----------------------------------\n\n->";
		cin >> menu;

		Package a;
		Delivery b;
		const char* arrCourier[4] = { "Pupkin Mykola","Shevchenko Taras","Franko Ivan","Kozlovsiy Myhaylo" };

		switch (menu)
		{
		case 0:
			cout << "Bye! Have a nice day!\n";
			break;
		case 1:
			showTitleP();
			for (int i = 0; i < NPackages; i++)
			{
				arrPackages[i].showTable();
				cout << "+-----------------+-----------------+----------+----------------+\n";
			}
			cout << endl;
			break;
		case 2:
			showTitleD();
			for (int i = 0; i < NDelivery; i++)
			{
				arrDelivery[i].showTable();
				cout << "+-----------------------+----------------------------+---------------+---------------+---------------+\n";
			}
			cout << endl;
			break;
		case 3:

			int chooseCourier, tmp;
			chooseCourier = rand() % 4;

			a.addNewPackage();

			switch (chooseCourier)
			{
			case 0:
				strcpy_s(b.courierFullName, arrCourier[0]);
				break;
			case 1:
				strcpy_s(b.courierFullName, arrCourier[1]);
				break;
			case 2:
				strcpy_s(b.courierFullName, arrCourier[2]);
				break;
			case 3:
				strcpy_s(b.courierFullName, arrCourier[3]);
				break;
			};
			cout << "Enter delivery adress:\n->";
			cin.ignore();
			cin.getline(b.recipientAdress, 100);
			b.thisPackage = a;
			b.deliveryDate.fillDate();
			b.status = false;

			addItemBack(arrPackages, NPackages, a);
			addItemBack(arrDelivery, NDelivery, b);

			cout << "\nNew delivery has been created!\n\n";
			break;
		case 4:
			int tmp_N;
			cout << "Enter package number you want to delete:\n->";
			cin >> tmp_N;
			arrPackages->removePackage(arrPackages, NPackages, tmp_N);
			arrDelivery->removeDelivery(arrDelivery, NDelivery, tmp_N);
			break;
		case 5:
			int tmp_S;
			cout << "Enter package number you want to find:\n->";
			cin >> tmp_S;
			arrPackages->findPackage(arrPackages, NPackages, tmp_S);
			arrDelivery->findDelivery(arrDelivery, NDelivery, tmp_S);
			break;
		case 6:
			sortArrDown(arrDelivery, NDelivery);
			cout << "Deliveries sorted by date!\n";
			break;
		case 7:
			int tmp_C;
			cout << "Enter package number you want to change:\n->";
			cin >> tmp_C;
			for (int i = 0; i < NDelivery; i++)
			{
				if (arrDelivery[i].thisPackage.packageNumber == tmp_C)
				{
					arrDelivery[i].status = !arrDelivery[i].status;
					count++;
				}
			}
			if (count > 0) cout << "Status changed!\n";
			else cout << "There are no packages with such number.\n";
			break;
		case 8:
			//saveArray
			fopen_s(&fp, "packages.txt", "w");
			if (fp == nullptr)
				cout << "Error: not saved in \"packages.txt\"\n";
			else {
				fprintf(fp, "%d", NPackages);
				for (int i = 0; i < NPackages; i++)
					arrPackages[i].saveToTextFile(fp);
				}
				fclose(fp);
				cout << "Saved in \"packages.txt\"\n";

			//void saveArrayD
				fp = nullptr;
				fopen_s(&fp, "delivery.txt", "w");
				if (fp == nullptr)
					cout << "Error: not saved in \"delivery.txt\"\n";
				else {
					fprintf(fp, "%d", NDelivery);
					for (int i = 0; i < NDelivery; i++)
						arrDelivery[i].saveToTextFileD(fp);
				}
				fclose(fp);
				cout << "Saved in \"delivery.txt\"\n";
			break;
		case 9:
			//loadArray;
			fp = nullptr;
			fopen_s(&fp, "packages.txt", "r");
			if (fp == nullptr)
			{
				arrPackages = nullptr;
				int NPackages = 0;
				cout << "Error: not loaded from \"packages.txt\"!\n";
			}
			else {
				fscanf_s(fp, "%d", &NPackages);
				arrPackages = new Package[NPackages];
				for (int i = 0; i < NPackages; i++) {
					arrPackages[i].loadFromTextFile(fp);
				}
			}
			fclose(fp);
			cout << "Loaded from \"packages.txt\"!\n";


			//void loadArrayD
			fp = nullptr;
			fopen_s(&fp, "delivery.txt", "r");
			if (fp == nullptr)
			{
				arrDelivery = nullptr;
				NDelivery = 0;
				cout << "Error: not loaded from \"delivery.txt\"!\n";
			}
			else {
				fscanf_s(fp, "%d", &NDelivery);
				arrDelivery = new Delivery[NDelivery];
				for (int i = 0; i < NDelivery; i++) {
					arrDelivery[i].loadFromTextFileD(fp);
				}
			}
			fclose(fp);
			cout << "Loaded from \"delivery.txt\"\n";
			break;
		};
	}

	


	delete[] arrPackages;
	delete[] arrDelivery;

	return 0;
}