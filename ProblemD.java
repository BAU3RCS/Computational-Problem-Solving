/**
 * @author Brandon Bauer
 * @since 3/6/2021
 * coding comp problem D
 */
import java.util.Scanner;

public class ProblemD {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int line = in.nextInt();
		
		int[] heights = new int[line];
		for(int i=0; i<line; i++) {
			heights[i] = in.nextInt();
		}
		
		int tot = line-1;
		
		int count = 0;
		
		for(int i=0; i<line; i++) {
			
			for(int j=i+2; j<line; j++) {
				
				int comp = Math.min(heights[i],heights[j]);
				for(int k=i+1; k<j; k++) {
					if(heights[k] >= comp) {
						 break;
					 }
					 else if(k==j-1) {
						 count++;
					 }
				}
			}
		}
		
		in.close();
		System.out.println(tot+count);

	}

}
