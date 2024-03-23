#include<iostream>
using namespace std;

class SavingsAccount
{
   //declare data members
  private:
   //set annualInterestRate to 0.0 default value
    static double annualInterestRate;
    double savingsBalance;
  public:
   //set the balance
   void setBalance(double);
   //modify interest rates
   static void modifyInterestRate(double);
   //retruns total balance with interest
   double calculateMonthInt();
};

double SavingsAccount::annualInterestRate = 0;

//static funtion modify interest rate
void SavingsAccount::modifyInterestRate(double iRate)
{
   annualInterestRate = iRate;
}

//set the balance
void SavingsAccount::setBalance(double bal)
{
   savingsBalance = bal;
}

//calculating savings balance with monthly interest
double SavingsAccount::calculateMonthInt()
{
   double monthInt = 0;
   monthInt += savingsBalance*annualInterestRate / 12;
   return savingsBalance += monthInt;
}

int main()
{
   //delcare class objects
   SavingsAccount saver1, saver2;

   //setter functions of balance
   saver1.setBalance(2000.00);
   saver2.setBalance(3000.00);

   saver1.modifyInterestRate(0.03);

   //find balance
   cout << "Balance of saver1 and saver2 on 3% interest Rate\n";
   cout << "Balance of saver1 = " << saver1.calculateMonthInt()
       << endl;
   cout << "Balance of saver2 = " << saver2.calculateMonthInt()
       << endl << endl;

   saver1.modifyInterestRate(0.04);
   cout << "Balance of saver1 and saver2 on 4% interest Rate\n";
   cout << "New Balance of saver1 = " << saver1.calculateMonthInt()        << endl;
   cout << "New Balance of saver2 = " << saver2.calculateMonthInt()    << endl<<endl;
   return 0;
}