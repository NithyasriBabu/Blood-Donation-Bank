#ifndef _MAINUI_H_
#define _MAINUI_H_

#include<iostream>
#include<iomanip>
using namespace std;

class MainUI
{
  public:
  static void displayUserMessage(string);
  static int getUserOption(int&);
  static int getLoginOption(int&);
  static int toContinue();
  static int toContinueLogin();
  static void displayMainPage();
  static int getMainMenuOption(int&);
  static void displayUserMenu();
  static void displayMenu();
  static int getTagChoice();
  static void displayAboutDIS();
  static void displayContactDIS();
  static void displayLogout(string);
};

#endif
