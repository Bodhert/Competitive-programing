/*
ID: alejand24
LANG: JAVA
TASK: dualpal
*/

import java.io.*;
import java.util.*;

 class dualpal
        
{
    
   public static boolean isPalin(String num)
    {
        for(int i = 0; i < num.length()/2; ++i)
        {
            if(num.charAt(i) != num.charAt(num.length()-1-i)) return false;
        }
        return true;
    }
    
    public static void main(String[] args) throws IOException
    {
        System.setIn(new FileInputStream("dualpal.in"));
        System.setOut(new PrintStream("dualpal.out"));
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int S = sc.nextInt();
        int curNum = S+1;
        int cont = 0;
        while(cont < N)
        {
            int isDual = 0;
            for(int base = 2; base <= 10; ++base)
            {
                String numBaseChanger = Integer.toString(Integer.parseInt(Integer.toString(curNum),10),base);
                if(isPalin(numBaseChanger)) 
                {
                    isDual++;
                    if(isDual >= 2)
                    {
                        System.out.println(curNum);
                        cont++;
                        break;
                    }
                }
            }
            curNum++;
        }   
    }
}

