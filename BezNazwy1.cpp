#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <sstream>

using namespace std;


int main()
{

	string zmienna;
	ifstream plik;
	int suma=0;
	int suma2=0;
	int czynp1=0;
	int suma3=0;
	string najw="0";
	string najm="9999999999";
	plik.open("dane.txt");
	if(plik.good())
	{
		for(int i=1; i<=5000; i++)
		{
			getline(plik,zmienna);
			int dl=zmienna.length();
			if(zmienna[0]==zmienna[dl-1]) suma++;
		}
		plik.close();
		plik.open("dane.txt");
		for(int i=1; i<=5000; i++)
		{
			int wynik=0;
			getline(plik,zmienna);
			int dl=zmienna.length();
			for(int j=0; j<dl; j++)
			wynik=(zmienna[j]-48)*pow(8,dl-1-j)+wynik;

			ostringstream ss;
			ss<<wynik;
			string str = ss.str();

			dl=str.length();
			if(str[0]==str[dl-1]) suma2++;
		}
		plik.close();
		plik.open("dane.txt");

		for(int i=1; i<=5000; i++)
		{

			getline(plik,zmienna);
			int dl=zmienna.length();
			for(int j=0; j<dl-1; j++)
			{
				//cout<<zmienna[j]<<endl;
				//cout<<zmienna[j+1]<<endl;
				if(zmienna[j]<=zmienna[j+1]) czynp1++;
				//system("pause");
			}
            //cout<<i<<". Dlugosc: "<<dl<<" , czynp1 = "<<czynp1<<" , czynp2 = "<<czynp2<<endl;
			if(czynp1==dl-1)
            {
                suma3++;
                //cout<<i<<". "<<zmienna<<endl;

                //ZNAJDOWANIE MAXIMUM
                if(dl>najw.length())
                {
                     najw=zmienna;
                }
                if(dl==najw.length())
                {
                    if(zmienna>najw) najw=zmienna;
                }
                //ZNAJDOWANIE MINIMUM
                if(dl<najm.length())
                {
                     najm=zmienna;
                }
                if(dl==najm.length())
                {
                    if(zmienna<najm) najm=zmienna;
                }

            }
            czynp1=0;

		}

	}
	plik.close();
	cout<<"Zad1 a) Ten warunek spelnia: "<<suma<<" liczb,"<<endl;
	cout<<"Zad1 b) Ten warunek spelnia: "<<suma2<<" liczb,"<<endl;
	cout<<"Zad3 c) Ten warunek spelnia: "<<suma3<<" liczb,"<<endl;
	cout<<"        max: "<<najw<<endl;
	cout<<"        min: "<<najm<<endl;

}
