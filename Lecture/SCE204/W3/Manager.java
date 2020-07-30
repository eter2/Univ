class Manager {
	private final int MAX = 10;
	private Product[] p = new Product[MAX];
	
	Manager() {
		for (int i = 0; i < MAX; i++)
			p[i] = new Product(i+1, (i+1) * 100, 10);
	}
	
	Product getProduct(int uid) {
		Product prod = null;
		for (int i = 0; i < MAX; i++) {
			if (p[i].getUid() == uid)
				prod = p[i];
		}
		return prod;
	}
}
