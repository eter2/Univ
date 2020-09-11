
public class SquarePyramid extends SquarePrism {
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
		return getArea() + (s * getDistance(getV1(), getV2()) * 4) / 2;
	}
	
	@Override
	public double getVolume() {
		return (super.getVolume()) / 3;
	}
	
	@Override
	public String toString() {
		System.out.printf("Type of shape: Square Pyramid%n");
		System.out.printf("\tcoordinates of upper left vertex : %.1f, %.1f%n", getV1().getX(), getV1().getY());
		System.out.printf("\tcoordinates of lower right vertex: %.1f, %.1f%n", getV2().getX(), getV2().getY());
		System.out.printf("\tSide of a square: %.2f%n", getDistance(getV1(), getV2()));
		System.out.printf("\tNormal Height: %.1f%n", getH());
		System.out.printf("\tSlant Height: %.1f%n", s);
		System.out.printf("\tSurface Area: %.2f%n", getSurfaceArea()); 
		System.out.printf("\tVolume: %.2f%n%n", getVolume()); 
		return null;
	}

	public double getS() {
		return s;
	}
}
