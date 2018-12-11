import java.io.IOException;
import java.math.BigDecimal;
import java.util.Scanner;
 
/**
 * IMPORTANT: 
 *      O nome da classe deve ser "Main" para que a sua solução execute
 *      Class name must be "Main" for your solution to execute
 *      El nombre de la clase debe ser "Main" para que su solución ejecutar
 */
public class Main {
 
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
		BigDecimal num = sc.nextBigDecimal();
		BigDecimal start = new BigDecimal("0.00");
		BigDecimal maxAngle = new BigDecimal("360.00");
		int cont = 0;
		
		while(!num.equals(start))
		{
			if(cont == 0) 
				start = num;
			
			start = start.add(num);
			if(start.compareTo(maxAngle) > 0)
			{
				start = start.subtract(maxAngle);
			}
			cont++;
		}
		System.out.println(cont);
 
    }
 
}
