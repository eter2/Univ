
public class EquilateralTriangularPyramid extends EquilateralTriangularPrism {
	private double s;

	public void setS(double s) {
		this.s = s;
	}
	
	public void checkSlant() throws Exception {	
		if (s <= getH()) {
			String message = "Error: Slant Height should be larger than normal Height.\nPlease input correct Slant Height: ";
			throw new ShapesException(message);
		}
	}
	
	@Override
	public double getSurfaceArea() {
		double s1 = getDistance(getV1(), getV2()), s2 = getDistance(getV2(), getV3()), s3 = getDistance(getV3(), getV1());		
		return getArea() + (s * (s1 + s2 + s3)) / 2;
	}
	
	@Override
	public double getVolume() {
		return (super.getVolume()) / 3;
	}
	
	@Override
	public String toString() {
		System.out.printf("Type of shape: Equilateral Triangular Pyramid%n");
		System.out.printf("\tCoordinates of Vertex One: %.1f, %.1f%n", getV1().getX(), getV1().getY());
		System.out.printf("\tCoordinates of Vertex Two: %.1f, %.1f%n", getV2().getX(), getV2().getY());
		System.out.printf("\tCoordinates of Vertex Three: %.1f, %.1f%n", getV3().getX(), getV3().getY());
		System.out.printf("\tLength of side 1: %.1f%n", getDistance(getV1(), getV2()));
		System.out.printf("\tLength of side 2: %.1f%n", getDistance(getV2(), getV3()));
		System.out.printf("\tLength of side 3: %.1f%n", getDistance(getV3(), getV1()));
		System.out.printf("\tNormal Height: %.1f%n", getH());
		System.out.printf("\tSlant Height: %.1f%n", s);
		System.out.printf("\tSurface Area: %.1f%n", getSurfaceArea()); 
		System.out.printf("\tVolume: %.1f%n%n", getVolume()); 
		return null;
	}

	public double getS() {
		return s;
	}
}
