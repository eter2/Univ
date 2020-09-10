
public class Square implements Shapes {
	private Point2D v1, v2;

	public void setV1(Point2D v1) {
		this.v1 = v1;
	}

	public void setV2(Point2D v2) {
		this.v2 = v2;
	}
	
	@Override
	public double getDistance() {	
		return getDistance(getV1(), getV2());
	}
	
	public double getDistance(Point2D p1, Point2D p2) {
		return Math.abs(p1.getX() - p2.getX());
	}

	@Override
	public double getArea() {
		return Math.pow(Math.abs(getV1().getX() - getV2().getX()), 2);
	}
	
	public void checkValid() throws Exception {
		String message = "";
		
		if (getV1().getX() >= getV2().getX())
			message = "\nError: x-coordinate of upper left vertex should be less than x-coordinate of lower right vertex.\nPlease enter valid coordinates.\n";
		else if (getV1().getY() <= getV2().getY())
			message = "\nError: y-coordinate of lower right vertex should be less than y-coordinate of upper left vertex.\nPlease enter valid coordinates.\n";
		
		if (!message.equals(""))
			throw new ShapesException(message);
	}
	
	@Override
	public String toString() {
		System.out.printf("Type of shape: Square%n");
		System.out.printf("\tcoordinates of upper left vertex : %.1f, %.1f%n", getV1().getX(), getV1().getY());
		System.out.printf("\tcoordinates of lower right vertex : %.1f, %.1f%n", getV2().getX(), getV2().getY());
		System.out.printf("\tSide of a square: %.2f%n", getDistance(getV1(), getV2()));
		System.out.printf("\tSurface Area: %.2f%n%n", getArea());
		return null;
	}

	public Point2D getV1() {
		return v1;
	}

	public Point2D getV2() {
		return v2;
	}
}
