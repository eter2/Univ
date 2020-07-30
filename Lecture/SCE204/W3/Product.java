class Product {
	private int uid;
	private int price;
	private int stock;
	
	Product(int uid, int price, int stock) {
		this.uid = uid;
		this.price = price;
		this.stock = stock;
	}

	int getStock() {
		return stock;
	}

	int getUid() {
		return uid;
	}

	int getPrice() {
		return price;
	}

	void setStock(int stock) {
		this.stock = stock;
	}
}
