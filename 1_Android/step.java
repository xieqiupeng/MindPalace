public class step {

	public static void main(String[] args) {
		int step = 0;
		boolean a;
		do {
			step += 1;
			a = step % 2 == 1 && step % 3 == 2 && step % 5 == 4
					&& step % 6 == 5 && step % 7 == 0;
		} while (!a);
		System.out.println(step);
	}
}
