#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Date.h"
using namespace std;

struct Package
{
	int packageNumber;
	char packageType[50];
	float weight;
	float deliveryPrice = 0;

	void showInfo()
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Package Number: " << packageNumber << endl;
		cout << "PackageType: " << packageType << endl;
		cout << "Weight: " << weight << endl;
		cout << "Delivery price: " << deliveryPrice << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}

	void showTable()
	{
		cout << "|" << setw(17) << packageNumber << "|" << setw(17) << packageType << "|"
			<< setw(10) << weight << "|" << setw(16) << deliveryPrice << "|\n";
	}

	void addNewPackage()
	{
		packageNumber = rand() * 1000 + rand();
		cout << "Enter package type:\n";
		cin.ignore();
		cin.getline(packageType, 100);
		cout << "Enter weight:\n";
		cin >> weight;
		cout << "Enter delivery price:\n";
		cin >> deliveryPrice;
	}

	void removePackage(Package* &arrPackages, int &NPackages, int tmp_N)
	{
		int countPkg = 0;
		for (int i = 0; i < NPackages; i++)
			if (arrPackages[i].packageNumber != tmp_N)
				countPkg++;
		if (countPkg < NPackages) cout << "Package has been deleted!\n";
		else cout << "There are no such package!\n";
		Package* tmpP = new Package[countPkg];
		for (int i = 0, j = 0; i < NPackages; i++)
		{
			if (arrPackages[i].packageNumber != tmp_N)
			{
				tmpP[j].packageNumber = arrPackages[i].packageNumber;
				strcpy_s(tmpP[j].packageType, arrPackages[i].packageType);
				tmpP[j].weight = arrPackages[i].weight;
				tmpP[j].deliveryPrice = arrPackages[i].deliveryPrice;
				j++;
			}
		}
		delete[] arrPackages;
		arrPackages = tmpP;
		NPackages = countPkg;
	}


	void findPackage(Package*& arrPackages, int& NPackages, int tmp_S)
	{
		int count = 0;
		for (int i = 0; i < NPackages; i++)
		{
			if (arrPackages[i].packageNumber == tmp_S)
			{
				count++;
				arrPackages[i].showInfo();
			}
		}
		if (count == 0) cout << "No matches!\n";
	}


	void saveToTextFile(FILE* fp)
	{
		fprintf(fp, "\n%d", packageNumber);
		fprintf(fp, "\n%s", packageType);
		fprintf(fp, "\n%f", weight);
		fprintf(fp, "\n%f", deliveryPrice);
	}

	void loadFromTextFile(FILE* fp) {
		fscanf_s(fp, "\n%d", &packageNumber);
		fscanf_s(fp, "\n");
		fgets(packageType, 50, fp);
		int len = strlen(packageType);
		packageType[len - 1] = '\0';
		fscanf_s(fp, "\n%f", &weight);
		fscanf_s(fp, "\n%f", &deliveryPrice);
	}
};

void saveArray(Package* arr, int size);
void loadArray(Package*& arr, int& size);