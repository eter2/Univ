
public class SquarePrism extends Square{
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
	
	public double getLateralSurfaceArea() {
		return getDistance(getV1(), getV2()) * getH() * 4;
	}
	
	public double getSurfaceArea() {
		return getDistance(getV1(), getV2()) * getH() * 4 + getArea() * 2;
	}
	
	public double getVolume() {
		return getArea() * getH();
	}
	
	@Override
	public String toString() {
		System.out.printf("Type of shape: Square Prism%n");
		System.out.printf("\tcoordinates of upper left vertex: %.1f, %.1f%n", getV1().getX(), getV1().getY());
		System.out.printf("\tcoordinates of lower right vertex: %.1f, %.1f%n", getV2().getX(), getV2().getY());
		System.out.printf("\tSide of a square: %.2f%n", getDistance(getV1(), getV2()));
		System.out.printf("\tNormal Height: %.1f%n", getH()); 
		System.out.printf("\tLateral Surface Area: %.2f%n", getLateralSurfaceArea());
		System.out.printf("\tSurface Area: %.2f%n", getSurfaceArea()); 
		System.out.printf("\tVolume: %.2f%n%n", getVolume()); 
		return null;
	}

	public double getH() {
		return h;
	}
}
