import java.util.Scanner;
import java.math.BigInteger;

class root {
	public static BigInteger busquedaBinaria( BigInteger target){
		BigInteger mid = new BigInteger("1");
		BigInteger temp;
		BigInteger base = BigInteger.ZERO;
		BigInteger limite = new BigInteger("10").pow(501);
		while(base.compareTo(limite) <= 0){
			mid = (base.add(limite)).divide(new BigInteger("2"));
			temp = mid.multiply(mid);
			if(temp.compareTo(target) == 0) return mid;
			if(temp.compareTo(target) < 0) base = mid.add(BigInteger.ONE);
			else limite = mid.subtract(BigInteger.ONE); 
		}
			
	return mid;
	}
	
	public static void main(String[] args){	
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		
		for(int i = 0; i < cases; i++){
			BigInteger entrada = sc.nextBigInteger();
			BigInteger salida = busquedaBinaria(entrada);
			System.out.println(salida.toString());
			if(i != cases - 1)
			System.out.println();
		}
		
		sc.close();
		
	}
}

