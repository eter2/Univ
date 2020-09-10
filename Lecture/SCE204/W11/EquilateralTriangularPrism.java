
public class EquilateralTriangularPrism extends EquilateralTriangle {
	private double h;

	public void setH(double h) {
		this.h = h;
	}
	
	public void checkHeight() throws Exception {	
		if (getH() <= 0) {
			String message = "Error: Normal height should be positive\nPlease enter positive value for normal height: ";
			throw new ShapesException(message);
		}
	}
	
	public double getSurfaceArea() {
		double s1 = getDistance(getV1(), getV2()), s2 = getDistance(getV2(), getV3()), s3 = getDistance(getV3(), getV1());		
		return s1 * getH() + s2 * getH() + s3 * getH() + getArea() * 2;
	}
	
	public double getVolume() {
		return getArea() * getH();
	}
	
	@Override
	public String toString() {
		System.out.printf("Type of shape: Equilateral Triangle Prism%n");
		System.out.printf("\tcoordinates of Vertex One: %.1f, %.1f%n", getV1().getX(), getV1().getY());
		System.out.printf("\tcoordinates of Vertex Two: %.1f, %.1f%n", getV2().getX(), getV2().getY());
		System.out.printf("\tcoordinates of Vertex Three: %.1f, %.1f%n", getV3().getX(), getV3().getY());
		System.out.printf("\tLength of side 1: %.1f%n", getDistance(getV1(), getV2()));
		System.out.printf("\tLength of side 2: %.1f%n", getDistance(getV2(), getV3()));
		System.out.printf("\tLength of side 3: %.1f%n", getDistance(getV3(), getV1()));
		System.out.printf("\tNormal Height: %.1f%n", getH()); 
		System.out.printf("\tSurface Area: %.1f%n", getSurfaceArea()); 
		System.out.printf("\tVolume: %.1f%n%n", getVolume()); 
		return null;
	}

	public double getH() {
		return h;
	}
}
