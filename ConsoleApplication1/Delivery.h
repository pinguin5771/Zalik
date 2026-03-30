#pragma once
#include "Package.h"
#include "Date.h"
#include "ArrayTemplate.h"
#include <ctime>
#include <iomanip>
using namespace std;
int arrPackagesSize = 0, arrDateSize = 0, arrStatusSize = 0;

struct Delivery
{
	char courierFullName[100];
	char recipientAdress[100];
	Package thisPackage;
	Date deliveryDate;
	bool status;

	void showInfo()
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "Courier Full Name: " << courierFullName << endl;
		cout << "Recipient Adress: " << recipientAdress << endl;
		cout << "Package number: " << thisPackage.packageNumber << endl;
		cout << "Delivery date: ";
		deliveryDate.printDate();
		cout << "\nStatus: ";
		status? cout << "Delivered" : cout << "Not delivered";
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}

	void showTable()
	{
		cout << "|" << setw(23) << courierFullName << "|" << setw(28) << recipientAdress << "|"
			<< setw(15) << thisPackage.packageNumber << "|" << setw(6);
		deliveryDate.printDate();
		cout << "|" << setw(15);
		status ? cout << "Delivered" : cout << "Not delivered"; 
		cout << "|\n";
	}

	void removeDelivery(Delivery* &arrDelivery,int &NDelivery,int tmp_N)
	{
		int countDelivery = 0;
		for (int i = 0; i < NDelivery; i++)
			if (arrDelivery[i].thisPackage.packageNumber != tmp_N)
				countDelivery++;
		Delivery* tmpD = new Delivery[countDelivery];
		for (int i = 0, j = 0; i < NDelivery; i++)
		{
			if (arrDelivery[i].thisPackage.packageNumber != tmp_N)
			{
				strcpy_s(tmpD[j].courierFullName, arrDelivery[i].courierFullName);
				strcpy_s(tmpD[j].recipientAdress, arrDelivery[i].recipientAdress);
				tmpD[j].thisPackage.packageNumber = arrDelivery[i].thisPackage.packageNumber;
				tmpD[j].deliveryDate = arrDelivery[i].deliveryDate;
				tmpD[j].status = arrDelivery[i].status;
				j++;
			}
		}
		delete[] arrDelivery;
		arrDelivery = tmpD;
		NDelivery = countDelivery;
	}

	void findDelivery(Delivery*& arrDelivery, int& NDelivery, int tmp_S)
	{
		for (int i = 0; i < NDelivery; i++)
			if (arrDelivery[i].thisPackage.packageNumber == tmp_S)
				arrDelivery[i].showInfo();
	}


	void saveToTextFileD(FILE* fp)
	{
		fprintf(fp, "\n%s", courierFullName);
		fprintf(fp, "\n%s", recipientAdress);
		fprintf(fp, "\n%d", thisPackage.packageNumber);
		fprintf(fp, "\n%d", deliveryDate.year);
		fprintf(fp, "\n%d", deliveryDate.month);
		fprintf(fp, "\n%d", deliveryDate.day);
		fprintf(fp, "\n%s", status? "true" : "false");
	}

	void loadFromTextFileD(FILE* fp) {
		char tmp[6];
		fscanf_s(fp, "\n");
		fgets(courierFullName, 100, fp);
		int len = strlen(courierFullName);
		courierFullName[len - 1] = '\0';

		fscanf_s(fp, "\n");
		fgets(recipientAdress, 100, fp);
		len = strlen(recipientAdress);
		recipientAdress[len - 1] = '\0';

		fscanf_s(fp, "\n%d", &thisPackage.packageNumber);
		fscanf_s(fp, "\n%d", &deliveryDate.year);
		fscanf_s(fp, "\n%d", &deliveryDate.month);
		fscanf_s(fp, "\n%d", &deliveryDate.day);

		fscanf_s(fp, "\n");
		fgets(tmp, 6, fp);
		len = strlen(tmp);
		tmp[len - 1] = '\0';
		if (strcmp(tmp, "true")) status = false;
		else status = true;
	}


};