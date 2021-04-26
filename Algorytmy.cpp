#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;


int main ()
{
    using namespace std::chrono;
  string wektor;
  stringstream sstream;
  int vala;
  int valb;

  vector < int >a;

  cout << "Wprowadz tablice a (oddzielona spacja): "; // pole wprowadzenia tablicy A
  getline (cin, wektor);
  sstream.str (wektor);
  while (sstream >> vala)
    a.push_back (vala);

  sstream.clear ();

  vector < int >b;
  cout << "Wprowadz tablice b (oddzielona spacja): "; // pole wprowadzenia tablicy B
  getline (cin, wektor);
  sstream.str (wektor);
  while (sstream >> valb)
    b.push_back (valb);

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  vector < int >c;
  int m = a.size(); // zmienna m = rozmiarowi tablicy A
  int n = b.size(); // zmienna n = rozmiarowi tablicy B

  int i = 0, j = 0; // zmienne wskaźnikowe
  while (i < m && j < n) // otwarcie pętli dopóki
    {
      if (a[i] < b[j])
	i++;
      else if (b[j] < a[i])
	j++;
      else
	{
	  c.push_back(b[j]); //
	  i++;
	  j++;
	}
    }
    {
    cout << "\nCzesc Wspolna:" << " ";
    }
    for (i = 0; i < c.size (); i++)
    cout << c[i] << " ";

    cout << "\nBez Duplikatow:" << " ";
    {
    c.erase(unique(c.begin(), c.end()), c.end());       // usunięcie duplikatów za pomocą funkcji,
        for(auto it = c.cbegin(); it != c.cend(); it++) // funkcja zawiera pętlę for do usunięcia duplikatów
        cout << *it << " ";
    }
    {
    cout << "\nNumer Indeksu Ostatniej wartosci (liczba elementow w wektorze):" << " ";
        int k = c.size();
        cout << k << " "; //wypisanie szukanego elementu = rozmiarowi badanego wektora
    }
     high_resolution_clock::time_point t2 = high_resolution_clock::now();
     duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
     std::cout << "\nCzas obliczenia " << time_span.count() << " sekund.";
     std::cout << std::endl;

  return 0;
}
