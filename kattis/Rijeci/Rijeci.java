import java.util.Scanner;

public class Rijeci {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String result = "A";
		int n = in.nextInt();
		int fibb0 = 0, fibb1 = 1, fibb = 1;

		if (n == 0) {
			System.out.println("1 0");
		} else if (n == 1) {
			System.out.println("0 1");
		} else {
			for (int i = 0; i < n - 1; i++) {
				fibb = fibb0 + fibb1;
				fibb0 = fibb1;
				fibb1 = fibb;
			}
			
			System.out.println(Integer.toString(fibb0) + " " + Integer.toString(fibb));
		}
		
		in.close();
	}

}
