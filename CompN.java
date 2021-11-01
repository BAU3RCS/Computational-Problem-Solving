/**
 * @author Brandon Bauer
 * @since 3/6/2021
 * coding comp problem n
 */
import java.util.Scanner;

public class CompN {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int cards = in.nextInt();
		int[] scores = new int[cards];
		
		for(int i=0; i<cards; i++) {
			scores[i] = in.nextInt();
		}
		
		in.close();
		System.out.println(sum);

	}

}
