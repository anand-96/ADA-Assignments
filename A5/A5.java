import java.util.Scanner;
abstract class Account
{
	protected int accountNumber;
	protected double accountBal;
	public void setAccountNumber(int accountNumber)
	{
		if(accountNumber>0)
			this.accountNumber=accountNumber;
		else
			System.out.println("Account Number Can't Be Negative");
			
	}
	public void setAccountBal(double accountBal)
	{
		if(accountBal>0)
			this.accountBal = accountBal;
		else
			System.out.println("Account Balance Can't Be Negative");
	}
	public int getAccountNumber()
	{
		return this.accountNumber;
	}
	public double getAccountBal()
	{
		return this.accountBal;
	}
	public Account(int accountNumber)
	{
		if(accountNumber>0)
		{
			this.accountNumber= accountNumber;
			this.accountBal=0;
		}
		else
		{
			System.out.println("Account Number Can't Be Negative");
		}
	}
	public Account()
	{
		this.accountNumber=0;
		this.accountBal=0;
	}
	public String toString()
	{
		return "Account Number :- "+accountNumber+" Account Balance :- "+accountBal;
	}
	abstract double computeInterest(int time);
}
class Checking extends Account
{
	public String toString()
	{
		return "Checking :- Account Number :- "+super.accountNumber+" Account Balance  :- "+super.accountBal;
	}
	public Checking(int accountNumber)
	{
		super(accountNumber);
	}
	public double computeInterest(int time)
	{
		double result=0;
		result = (super.accountBal - 700)*time*0.02;
		return 0;
	}
}
class Savings extends Account
{
	private int interestRate;
	public void setInterestRate(int interestRate)
	{
		this.interestRate = interestRate;
	}
	public int getInterestRate()
	{
		return this.interestRate;
	}
	public String toString()
	{
		return "Saving : Account Number :- "+super.accountNumber+" Account Balance :- "+super.accountBal+"  Interest Rate :- "+this.interestRate ;
	}	
	public Savings(int accountNumber, int interestRate)
	{
		super(accountNumber);
		this.interestRate = interestRate;
	}
	public double computeInterest(int time)
	{
		return (time*(1+this.interestRate)*super.accountBal)-super.accountBal;
	}
}
class A5
{
	public static void main(String args[])
	{
		Account obj[] = new Account[5];
		System.out.println("Enter Checking Account Details First Account Number, Account Bal");
		for(int i=0;i<5;i++)
		{
			obj[i] = new Checking(new Scanner(System.in).nextInt());
		}
	}	
}
