/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odev1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayilmaz <dayilmaz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:04:34 by dayilmaz          #+#    #+#             */
/*   Updated: 2023/03/05 21:04:34 by dayilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

class Dugum
{
	public:
		string veri;
		Dugum *sonraki = nullptr;
		Dugum(string veri)
		{
			this->veri=veri;
		}
		Dugum(){}
};

class Liste
{
	Dugum *root;
	public:
		Liste ekle(Liste liste, string veri)
		{
			Dugum *yeniDugum = new Dugum(veri);
			if(liste.root == nullptr)
				liste.root = yeniDugum;
			else
			{
				Dugum *tekrar = liste.root;
				while (tekrar->sonraki != nullptr)
					tekrar = tekrar->sonraki;
				tekrar->sonraki = yeniDugum;
			}
			return (liste);
		}

		Liste duzenliekle(Liste liste, string veri)
		{
		/*  3 durumumuz vardır
				1) Liste boş ise ilk elemana ekle.
				2) Root elemanından küçük ise root elemanı ile değiştir.
				3) iki eleman arasında bir değer ise arasına ekleme işlemi (swap benzeri).			*/

			Dugum *yeniDugum = new Dugum(veri);
			//liste boş ise uygulanacak olan koşul bloğumuz
			if(liste.root == nullptr)
				liste.root = yeniDugum;
			//eklenencek veri root elemanımızdan daha küçük bir değere sahip ise uygulanacak olan koşul bloğumuz
			else if(yeniDugum->veri < liste.root->veri)
			{
				yeniDugum->sonraki = root;
				liste.root = yeniDugum;
			}
			//En küçük yada iki değer arasında bir değere sahip olduğunda uygulanacak kümeler
			else
			{
				Dugum *tekrar = liste.root;
				while (tekrar->sonraki != nullptr && tekrar->sonraki->veri < yeniDugum->veri)
					tekrar = tekrar->sonraki;
				Dugum *temp = tekrar->sonraki;
				tekrar->sonraki = yeniDugum;
				yeniDugum->sonraki = temp;
			}
			return(liste);
		}

		void yazdir(Liste liste)
		{
			Dugum *tekrar = liste.root;
			while (tekrar != nullptr)
			{
				cout << tekrar->veri << " ";
				tekrar = tekrar->sonraki;
			}
		}

		Liste sil(Liste liste, string silenecekveri)
		{
			if(liste.root != nullptr && liste.root->veri == silenecekveri)
				liste.root = liste.root->sonraki;
			Dugum *tekrar = liste.root;
			while(tekrar->sonraki != nullptr && tekrar->sonraki->veri != silenecekveri)
				tekrar = tekrar->sonraki;
			if (tekrar->sonraki == nullptr)
				cout << "Girilen dizi bulunamadi";
			else
				tekrar->sonraki = tekrar->sonraki->sonraki;
			return (liste);
		}
		int bul(Liste liste, string bulanacakveri)
		{
			int miktar;
			miktar = 1;
			if(liste.root->veri == bulanacakveri)
				return (0);
			while (liste.root->sonraki->veri != bulanacakveri)
			{
				miktar++;
				liste.root = liste.root->sonraki;
			}
			cout << “Listede”<<miktar<<”. siradir”;// EKRAN RESMİ ALINDIKTAN SONRA EKLENMİŞTİR
			return (miktar);
		}
		Liste nincieleman(Liste liste, int n)
		{
			int i = 0;
			Dugum *dondurelecek = liste.root;
			while (dondurelecek->sonraki != nullptr && i < n)
			{
				dondurelecek = dondurelecek->sonraki;
				i++;
			}
			if (dondurelecek->sonraki == nullptr || n < 0)
			{
				cout << "Liste uzunluğu girdiğiniz uzunluk miktarindan kisadir";
			}
			else
				cout << dondurelecek->veri;
			return (liste);
		}

		Liste nincielemanisil(Liste liste, int n)
		{
			int i = 0;
			Dugum *dondurelecek = liste.root;
			while (dondurelecek->sonraki != nullptr && i < n-1)
			{
				dondurelecek = dondurelecek->sonraki;
				i++;
			}
			if (dondurelecek->sonraki == nullptr || n < 0)
				cout << "Liste uzunluğu girdiğiniz uzunluk miktarindan kisadir";	
			else if (n == 0)
				liste.root = liste.root->sonraki;
			else
				dondurelecek->sonraki = dondurelecek->sonraki->sonraki;
			return (liste);
		}

		int say(Liste liste)
		{
			int miktar;
			miktar = 1;
			if(liste.root == NULL)
				return (0);
			while (liste.root->sonraki != nullptr)
			{
				miktar++;
				liste.root = liste.root->sonraki;
			}
			return (miktar);
		}

		void terstenyazdir(Liste liste)
		{
			int n = liste.say(liste);
			int i = 0;
			Dugum *tekrar = liste.root;
			while (i < n)
			{
				tekrar = liste.root;
				while (tekrar != nullptr)
				{
					if (i == n-1)
					{
						cout << tekrar->veri << " ";
					}
					tekrar = tekrar->sonraki;
					i++;
				}
				n--;
				i = 0;
			}
		}
};



int main()
{
	Liste liste;
	liste = liste.duzenliekle(liste,"Davut");
	liste = liste.duzenliekle(liste,"Enes");
	liste = liste.duzenliekle(liste,"Yilmaz");
	liste = liste.duzenliekle(liste,"Bilgisayar");
	liste = liste.duzenliekle(liste,"Mühendisliği");
	liste = liste.duzenliekle(liste,"4. Dönem");
	liste = liste.duzenliekle(liste,"Öğrencisi");
	liste.yazdir(liste);
	cout << '\n' << liste.say(liste) << '\n';
	liste.terstenyazdir(liste);
	
	Liste list;
	list = list.ekle(list,"Davut");
	list = list.ekle(list,"Enes");
	list = list.ekle(list,"Yilmaz");
	list = list.ekle(list,"Bilgisayar");
	list = list.ekle(list,"Mühendisliği");
	list = list.ekle(list,"4. Dönem");
	list = list.ekle(list,"Öğrencisi");
	list.yazdir(list);
	cout << '\n' << list.say(list) << '\n'; 
	list.terstenyazdir(list);
}
