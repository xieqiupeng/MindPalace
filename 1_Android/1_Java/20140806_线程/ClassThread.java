public class ClassThread {
	/**
	 * 
	 * @param args
	 */
	public static void main(String[] args) {

		Thread t = Thread.currentThread();
		System.out.println("��ǰ�̣߳�" + t);
		t.setName("First Thread");
		System.out.println("�����֣�" + t);
		for (int i = 0; i < 5; i++) {
			System.out.println(5 - i);
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
