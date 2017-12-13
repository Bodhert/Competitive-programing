
import java.io.*;
import java.util.StringTokenizer;

class palsquare
{
    
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader f = 
           new BufferedReader(new FileReader("palsquare.in"));

        PrintWriter out =
           new PrintWriter
             (new BufferedWriter(new FileWriter("palsquare.out")));

        StringTokenizer st = 
           new StringTokenizer(f.readLine());

        int base = Integer.parseInt(st.nextToken());    
        for(int i = 1; i <= 300; ++i)
        {
         //Integer.toString
         //(Integer.parseInt(number, base1), base2);
            String numBaseChanger = 
                Integer.toString
                  (Integer.parseInt
                   (Integer.toString(i),10),base);

            
              out.println(numBaseChanger.toUpperCase());
        }
         out.close();
    }    
}

