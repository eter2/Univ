public class EquilateralTriangle implements Shapes {
	private Point2D v1, v2, v3;	

	public void setV1(Point2D v1) {
		this.v1 = v1;
	}

	public void setV2(Point2D v2) {
		this.v2 = v2;
	}

	public void setV3(Point2D v3) {
		this.v3 = v3;
	}

	@Override
	public double getDistance() {	
		return getDistance(getV1(), getV2());
	}
	
	public double getDistance(Point2D p1, Point2D p2) {	
		return Math.sqrt(Math.pow(Math.abs(p1.getX() - p2.getX()), 2) + Math.pow(Math.abs(p1.getY() - p2.getY()),  2));
	}

	@Override
	public double getArea() {
		double s1 = getDistance(getV1(), getV2()), s2 = getDistance(getV2(), getV3()), s3 = getDistance(getV3(), getV1());		
		double p = (s1 + s2 + s3) / 2;
		return Math.sqrt(p * (p - s1) * (p - s2) * (p - s3));
	}
	
	public void checkNonCollinear() throws Exception {
		double l1 = Math.abs(getV1().getY() - getV2().getY()) / Math.abs(getV1().getX() - getV2().getX());
		double l2 = Math.abs(getV2().getY() - getV3().getY()) / Math.abs(getV2().getX() - getV3().getX());
		double l3 = Math.abs(getV3().getY() - getV1().getY()) / Math.abs(getV3().getX() - getV1().getX());
		
		if (l1 == l2 && l2 == l3) {
			String message = "\nError: the three vertices are collinear. Please enter non-collinear vertices\n";
			throw new ShapesException(message);
		}
	}
	
	public void checkEqual() throws Exception {
		double s1 = getDistance(getV1(), getV2()), s2 = getDistance(getV2(), getV3()), s3 = getDistance(getV3(), getV1());
		
		if (s1 != s2 || s2 != s3 || s3 != s1) {
			String message = "\nWarning: the three sides are not equal, but continue your operation.";
			throw new ShapesWarningException(message);
		}
	}
	
	@Override
	public String toString() {
		System.out.printf("\nType of shape: Equilateral Triangle%n");
		System.out.printf("\tCoordinates of Vertex One: %.1f, %.1f%n", getV1().getX(), getV1().getY());
		System.out.printf("\tCoordinates of Vertex Two: %.1f, %.1f%n", getV2().getX(), getV2().getY());
		System.out.printf("\tCoordinates of Vertex Three: %.1f, %.1f%n", getV3().getX(), getV3().getY());
		System.out.printf("\tLength of side 1: %.1f%n", getDistance(getV1(), getV2()));
		System.out.printf("\tLength of side 2: %.1f%n", getDistance(getV2(), getV3()));
		System.out.printf("\tLength of side 3: %.1f%n", getDistance(getV3(), getV1()));
		System.out.printf("\tSurface Area: %.1f%n%n", getArea());
		return null;
	}

	public Point2D getV1() {
		return v1;
	}

	public Point2D getV2() {
		return v2;
	}

	public Point2D getV3() {
		return v3;
	}
}
