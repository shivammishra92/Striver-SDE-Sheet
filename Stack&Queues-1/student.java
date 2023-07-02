import java.util.Scanner;

public class Main {
    static class Student {
        private String usn;
        private String name;

        public Student(String usn, String name) {
            this.usn = usn;
            this.name = name;
        }

        public String getUsn() {
            return usn;
        }

        public void setUsn(String usn) {
            this.usn = usn;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }

    static class UGStudent extends Student {
        private int semester;
        private String branch;

        public UGStudent(String usn, String name, int semester, String branch) {
            super(usn, name);
            this.semester = semester;
            this.branch = branch;
        }

        public int getSemester() {
            return semester;
        }

        public void setSemester(int semester) {
            this.semester = semester;
        }

        public String getBranch() {
            return branch;
        }

        public void setBranch(String branch) {
            this.branch = branch;
        }
    }

    static class PGStudent extends Student {
        private String spec;
        private String ugdeg;

        public PGStudent(String usn, String name, String spec, String ugdeg) {
            super(usn, name);
            this.spec = spec;
            this.ugdeg = ugdeg;
        }

        public String getSpec() {
            return spec;
        }

        public void setSpec(String spec) {
            this.spec = spec;
        }

        public String getUGDegree() {
            return ugdeg;
        }

        public void setUGDegree(String ugdeg) {
            this.ugdeg = ugdeg;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        UGStudent[] ugStudents = new UGStudent[10];
        PGStudent[] pgStudents = new PGStudent[10];
        
        // int N;
        // System.out.println("Enter the value of N");
        // N=sc.nextInt();
        for (int i = 0; i <1 ; i++) {
            System.out.println("Student " + (i + 1));
            String ugUsn = scanner.nextLine();
            String ugName = scanner.nextLine();
            int ugSemester = scanner.nextInt();
            scanner.nextLine();
            String ugBranch = scanner.nextLine();
            ugStudents[i] = new UGStudent(ugUsn, ugName, ugSemester, ugBranch);
            String pgUsn = scanner.nextLine();
            String pgName = scanner.nextLine();
            String pgSpec = scanner.nextLine();
            String pgUGDegree = scanner.nextLine();
            pgStudents[i] = new PGStudent(pgUsn, pgName, pgSpec, pgUGDegree);
        }

      System.out.println("\nUG Student Details:");
for (int i = 0; i < 1; i++) {
    UGStudent ugStudent = ugStudents[i];
    System.out.println("Student " + (i + 1));
    System.out.println("USN: " + ugStudent.getUsn());
    System.out.println("Name: " + ugStudent.getName());
    System.out.println("Semester: " + ugStudent.getSemester());
    System.out.println("Branch: " + ugStudent.getBranch());
    System.out.println();
}

System.out.println("PG Student Details:");
for (int i = 0; i < 10; i++) {
    PGStudent pgStudent = pgStudents[i];
    System.out.println("Student " + (i + 1));
    System.out.println("USN: " + pgStudent.getUsn());
    System.out.println("Name: " + pgStudent.getName());
    System.out.println("Specialization: " + pgStudent.getSpec());
    System.out.println("Undergraduate Degree: " + pgStudent.getUGDegree());
    System.out.println();
}

}
}