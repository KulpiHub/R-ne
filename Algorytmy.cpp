#include <iostream>
#include <bits/stdc++.h>
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

  vector <int> a;

  cout << "Wprowadz tablice a (oddzielona spacja): ";
  getline (cin, wektor);
  sstream.str (wektor);
  while (sstream >> vala)
    a.push_back (vala);

  sstream.clear ();

  vector <int> b;
  cout << "Wprowadz tablice b (oddzielona spacja): ";
  getline (cin, wektor);
  sstream.str (wektor);
  while (sstream >> valb)
    b.push_back (valb);

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  vector<int> c;
  unsigned long m = a.size();
  unsigned long n = b.size();
  int i = 0;
  int j = 0;
  while (i < m && j < n)
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
    for (unsigned i = 0; i < c.size (); i++)
    cout << c[i] << " ";

    cout << "\nBez Duplikatow:" << " ";
    {
    c.erase(unique(c.begin(), c.end()), c.end());
        for(auto it = c.cbegin(); it != c.cend(); it++)
        cout << *it << " ";
    }
    {
    cout << "\nNumer Indeksu Ostatniej wartosci (liczba elementow w wektorze):" << " ";
        unsigned long vectorElements = c.size();
        cout << vectorElements << " ";
    }
     high_resolution_clock::time_point t2 = high_resolution_clock::now();
     duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
     std::cout << "\nCzas obliczenia " << time_span.count() << " sekund.";
     std::cout << std::endl;

  return 0;
}
