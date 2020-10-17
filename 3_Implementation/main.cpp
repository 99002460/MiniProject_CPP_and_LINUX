int main()
{
switch(Type of Account)
{
  case 'Savings Account':
  {
    savingsaccount(name,accountno,balance);
  }
  
  case 'Credit Account':
  {
    creditsaccount(name,accountno,balance);
  }
  
  case 'Savings Account Database':
  {
    savingsaccountDB(name,accountno,balance,listofCustomers);
  }
  
  case 'Credit Account Database':
  {
    creditaccountDB(name,accountno,balance,listofCustomers);
  }
  default:
  {
    printf("Enter a valid Selection");
  }
  
}
