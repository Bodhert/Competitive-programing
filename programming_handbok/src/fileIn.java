import java.io.*;
import java.util.*;

class Reader 
        
{
    
   public static void main(String[] args) throws FileNotFoundException 
    {
        System.setIn(new FileInputStream("in.in"));
        System.setOut(new PrintStream("out.out"));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(n);
    }
    
}

