import java.util.Scanner;

public class DiceGame {

	public static void main(String[] args) {
		int[] nums = new int[8];
		int[][] dice = new int[4][];
		int[] dp1, dp2;
		int p1 = 0, p2 = 0;
		int counter;
		Scanner in = new Scanner(System.in);
		String[] temp;

		temp = in.nextLine().split(" ");
		for (int i = 0; i < 4; i++)
			nums[i] = Integer.parseInt(temp[i]);

		temp = in.nextLine().split(" ");
		for (int i = 0; i < 4; i++)
			nums[i + 4] = Integer.parseInt(temp[i]);

		dice[0] = generateDie(nums[0], nums[1]);
		dice[1] = generateDie(nums[2], nums[3]);
		dice[2] = generateDie(nums[4], nums[5]);
		dice[3] = generateDie(nums[6], nums[7]);

		dp1 = new int[dice[0].length * dice[1].length];
		counter = 0;
		for (int i : dice[0])
			for (int j : dice[1]) {
				dp1[counter] = i + j;
				counter++;
			}
		
		counter = 0;
		dp2 = new int[dice[2].length * dice[3].length];
		for (int i : dice[2])
			for (int j : dice[3]) {
				dp2[counter] = i + j;
				counter++;
			}
		
		for (int i : dp1) {
			for (int j : dp2) {
				if (i > j) p1 += 1;
				else if (j > i) p2 += 1;
			}
		}
		
		if (p2 > p1) {
			System.out.println("Emma");
		} else if (p1 > p2) {
			System.out.println("Gunnar");
		} else {
			System.out.println("Tie");
		}

		in.close();
	}

	private static int[] generateDie(int x, int y) {
		int[] die = new int[y - x + 1];
		for (int i = 0; i < y - x + 1; i++) {
			die[i] = x + i;
		}
		return die;
	}

}
