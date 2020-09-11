import java.io.*;

class Demo1 {
	public static FileInputStream CreateFile(String fileName) throws IOException {
		FileInputStream fis2 = new FileInputStream(fileName);
		System.out.println("File input stream is created");
		return fis2;
	}
	
	public static void main(String args[]) {
		FileInputStream fis1 = null;
		String fileName = "foo.bar";
		
		try {
			System.out.println("File name is " + fileName);
			fis1 = CreateFile(fileName);
			System.out.println("End of the program");
			
		} catch (IOException e) {
		    System.err.printf("%nException: %s%n", e);
		    
		} catch (Exception e) {
			System.err.printf("%nException: %s%n", e);
		}
	}
}
