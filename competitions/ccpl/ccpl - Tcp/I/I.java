import java.util.Scanner;
import java.math.BigInteger;
class I{
    public static void main(String args[]){
	Scanner sc= new Scanner(System.in);
	while(sc.hasNext()){
	    BigInteger I = sc.nextBigInteger();
	    BigInteger cero = new BigInteger("0");
	    BigInteger diez = new BigInteger("10");
	    BigInteger sum = new BigInteger("0");
	    BigInteger dos = new BigInteger("2");
	    boolean par = false, entra = true;
	    if(I.mod(dos).equals(cero)){		
		par = true;
	    }
	    while(entra){
		sum = sum.add(I.mod(diez));
		I = I.divide(diez);
		if(I.equals(cero)){
		    entra = false;
		}
	    }
	    if(par && sum.mod(dos).equals(cero)){	       
		System.out.println("superpar");
	    }else{
		System.out.println("no");
	    }
	}
    }   
}
