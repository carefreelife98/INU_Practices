import java.util.Iterator;
import java.util.Vector;

public final class LCM {

	private static int MAX_LCM = 100000;
	
	public static double generateLCM(Vector numbers){

		double lcm = 0, gcd = 0;
		double number1 = 0, number2 = 0;
		Iterator iter = numbers.iterator();
		if(iter.hasNext()){
			number1 = ((Double)iter.next()).doubleValue();
			lcm = number1;
		}
		while(iter.hasNext()){

			number2 = ((Double)iter.next()).doubleValue();
			gcd = generateGCD(number1, number2);
			lcm = number1*number2/gcd;
			number1 = lcm;
			/* LCM bounded by max */
			if (lcm >= MAX_LCM) {
				return MAX_LCM;
			}
		}
		/* LCM bounded by max */
		if (lcm >= MAX_LCM) {
			return MAX_LCM;
		}
	
		return lcm;
	}

	public static double generateGCD(double number1, double number2){

		if(number1 >= number2){

			if(number2 == 0)
				return number1;
			else{
				double remainder = Math.IEEEremainder(number1, number2);
				if(remainder < 0)
					remainder = remainder+number2;

				return generateGCD(number2, remainder);
			}
		}
		else{

			if(number1 == 0)
				return number2;
			else{
				double remainder = Math.IEEEremainder(number2, number1);
				if(remainder < 0)
					remainder = remainder+number1;

				return generateGCD(number1, remainder);
			}
		}
	}
}
