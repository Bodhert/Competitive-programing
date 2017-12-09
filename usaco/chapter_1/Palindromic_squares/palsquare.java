/*
ID: alejand24
LANG: JAVA
TASK: palsquare
*/

import java.io.*;
import java.util.StringTokenizer;

class palsquare
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
        BufferedReader f = new BufferedReader(new FileReader("palsquare.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));
        StringTokenizer st = new StringTokenizer(f.readLine());
//        String base_string = f.readLine();
        int base = Integer.parseInt(st.nextToken());    
        for(int i = 1; i <= 300; ++i)
        {
//          Integer.toString(Integer.parseInt(number, base1), base2); conversion a base2
            int square = i*i;
            String numBaseChanger = Integer.toString(Integer.parseInt(Integer.toString(i),10),base);
            String squareBaseChanger = Integer.toString(Integer.parseInt(Integer.toString(square),10),base);
            if(isPalin(squareBaseChanger))
            { 
		out.println(numBaseChanger.toUpperCase() + " " + squareBaseChanger.toUpperCase());
            }
        }
         out.close();
    }
    
}

