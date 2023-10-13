import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ArrayList<Student> students = new ArrayList<>();
        int numberOfStudents;

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        numberOfStudents = scanner.nextInt();
        scanner.nextLine(); //  newline character

        for (int i = 0; i < numberOfStudents; i++) {
            System.out.print("Enter name for Student " + (i + 1) + ": ");
            String name = scanner.nextLine();
            System.out.print("Enter age for Student " + (i + 1) + ": ");
            int age = scanner.nextInt();
            scanner.nextLine(); // newline character

            students.add(new Student(name, age));
        }

        
    }
}
