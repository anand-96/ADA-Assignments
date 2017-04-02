import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Facorial
{
        public static void main(String args[])
        {
                 BigInteger fact= BigInteger.ONE;
                 System.out.println("Enter any number");
                 int n = new Scanner(System.in).nextInt();

                for (int i = 2; i <= n; i++)
                   {
                      fact = fact.multiply(new BigInteger(String.valueOf(i)));
                   }

             System.out.println("The factorial of " + n +" is: " + fact);
         }
}
