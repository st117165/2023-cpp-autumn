#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
void menu();
void expandarray(int*& a, int& l, int n);
void displayarray(int*& a, int l);
void addelement(int*& a, int& l);
void deleteelement(int*& a, int& l);
void deleteelement1(int*& a, int& l, int n);
void sortascending(int*& a, int l);
void reversearray(int*& a, int l);
void minmaxswap(int*& a, int l);
int countofelement(int*& a, int l, int n);
void addnrandomelements(int*& a, int& l);
void deletedublicates(int*& a, int& l);
