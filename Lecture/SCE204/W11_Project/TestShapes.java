import java.util.Scanner;

public class TestShapes {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		double x, y, h, s;
		
		System.out.println("=== Equilateral Triangle ===");
		EquilateralTriangle et = new EquilateralTriangle();
		while (true) {
			System.out.print("Please input x-coordinate of the Vertex 1 of the triangle: ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Vertex 1 of the triangle: ");
			y = scan.nextDouble();
			et.setV1(new Point2D(x, y));
			System.out.print("Please input x-coordinate of the Vertex 2 of the triangle: ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Vertex 2 of the triangle: ");
			y = scan.nextDouble();
			et.setV2(new Point2D(x, y));
			System.out.print("Please input x-coordinate of the Vertex 3 of the triangle: ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Vertex 3 of the triangle: ");
			y = scan.nextDouble();
			et.setV3(new Point2D(x, y));	
			
			try {
				et.checkNonCollinear();
				et.checkEqual();
				break;
			} catch (ShapesWarningException e) {
				System.out.println(e.getMessage());
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
		
		
		System.out.println("\n=== Square ===");
		Square sq = new Square();
		while (true) {
			System.out.print("Please input x-coordinate of the Upper Left of the Square : ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Upper Left of the Square : ");
			y = scan.nextDouble();
			sq.setV1(new Point2D(x, y));
			System.out.print("Please input x-coordinate of the Lower Right of the Square : ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Lower Right of the Square : ");
			y = scan.nextDouble();
			sq.setV2(new Point2D(x, y));
			
			try {
				sq.checkValid();
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
		
		
		System.out.println("\n=== Equilateral Triangular Prism ===");
		EquilateralTriangularPrism etp = new EquilateralTriangularPrism();
		while (true) {
			System.out.print("Please input x-coordinate of the Vertex 1 of the triangle: ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Vertex 1 of the triangle: ");
			y = scan.nextDouble();
			etp.setV1(new Point2D(x, y));
			System.out.print("Please input x-coordinate of the Vertex 2 of the triangle: ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Vertex 2 of the triangle: ");
			y = scan.nextDouble();
			etp.setV2(new Point2D(x, y));
			System.out.print("Please input x-coordinate of the Vertex 3 of the triangle: ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Vertex 3 of the triangle: ");
			y = scan.nextDouble();
			etp.setV3(new Point2D(x, y));
		
			try {
				etp.checkNonCollinear();
				etp.checkEqual();
				break;
			} catch (ShapesWarningException e) {
				System.out.println(e.getMessage());
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
		System.out.print("\nPlease enter normal height: ");
		while (true) {
			h = scan.nextDouble();
			etp.setH(h);
			
			try {
				etp.checkHeight();
				break;
			} catch (Exception e) {
				System.out.print(e.getMessage());
			}
		}
		
		
		System.out.println("\n=== Square Prism ===");
		SquarePrism sqp = new SquarePrism();
		while (true) {
			System.out.print("Please input x-coordinate of the Upper Left of the Square : ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Upper Left of the Square : ");
			y = scan.nextDouble();
			sqp.setV1(new Point2D(x, y));
			System.out.print("Please input x-coordinate of the Lower Right of the Square : ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Lower Right of the Square : ");
			y = scan.nextDouble();
			sqp.setV2(new Point2D(x, y));
		
			try {
				sqp.checkValid();
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}	
		System.out.print("\nPlease enter normal height: ");
		while (true) {
			h = scan.nextDouble();
			sqp.setH(h);
			
			try {
				sqp.checkHeight();
				break;
			} catch (Exception e) {
				System.out.print(e.getMessage());
			}
		}
		
		
		System.out.println("\n=== Equilateral Triangular Pyramid ===");
		EquilateralTriangularPyramid etpy = new EquilateralTriangularPyramid();
		while (true) {
			System.out.print("Please input x-coordinate of the Vertex 1 of the triangle: ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Vertex 1 of the triangle: ");
			y = scan.nextDouble();
			etpy.setV1(new Point2D(x, y));
			System.out.print("Please input x-coordinate of the Vertex 2 of the triangle: ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Vertex 2 of the triangle: ");
			y = scan.nextDouble();
			etpy.setV2(new Point2D(x, y));
			System.out.print("Please input x-coordinate of the Vertex 3 of the triangle: ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Vertex 3 of the triangle: ");
			y = scan.nextDouble();
			etpy.setV3(new Point2D(x, y));
			
			try {
				etpy.checkNonCollinear();
				etpy.checkEqual();
				break;
			} catch (ShapesWarningException e) {
				System.out.println(e.getMessage());
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
	}
		System.out.print("\nPlease enter normal height: ");
		while (true) {
			h = scan.nextDouble();
			etpy.setH(h);		
			try {
				etpy.checkHeight();
				break;
			} catch (Exception e) {
				System.out.print(e.getMessage());
			}
		}
		System.out.print("Please input Slant Height: ");
		while (true) {
			s = scan.nextDouble();
			etpy.setS(s);	
			
			try {
				etpy.checkSlant();
				break;
			} catch (Exception e) {
				System.out.print(e.getMessage());
			}
		}
		
			
		System.out.println("\n=== Square Pyramid ===");
		SquarePyramid sqpy = new SquarePyramid();
		while (true) {
			System.out.print("Please input x-coordinate of the Upper Left of the Square : ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Upper Left of the Square : ");
			y = scan.nextDouble();
			sqpy.setV1(new Point2D(x, y));
			System.out.print("Please input x-coordinate of the Lower Right of the Square : ");
			x = scan.nextDouble();
			System.out.print("Please input y-coordinate of the Lower Right of the Square : ");
			y = scan.nextDouble();
			sqpy.setV2(new Point2D(x, y));
			
			try {
				sqpy.checkValid();
				break;
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
		System.out.print("\nPlease enter normal height: ");
		while (true) {
			h = scan.nextDouble();
			sqpy.setH(h);
			
			try {
				sqpy.checkHeight();
				break;
			} catch (Exception e) {
				System.out.print(e.getMessage());
			}
		}
		System.out.print("Please input Slant Height: ");
		while (true) {
			s = scan.nextDouble();
			sqpy.setS(s);
			
			try {
				sqpy.checkSlant();
				break;
			} catch (Exception e) {
				System.out.print(e.getMessage());
			}
		}	
		
		scan.close();
		
		et.toString();
		sq.toString();
		etp.toString();
		sqp.toString();
		etpy.toString();
		sqpy.toString();
	}
}
