import java.io.*;
import java.util.*;


public class ProjectEuler 
        
{
    public static boolean isPalin(String num)
    {
        for(int i = 0; i < num.length()/2; ++i)
        {
            if(num.charAt(i) != num.charAt(num.length()-1-i)) return false;
        }
        return true;
    }
    
    public static void main(String[] args) 
    {
        int maxi = -1;
        for(int i = 100; i <= 999; ++i)
            for(int j = 100; j <= 999; ++j)
                if(isPalin(Integer.toString(i*j))) maxi = Math.max(maxi, i*j);
        
        System.out.println(maxi);
    }
    
}

