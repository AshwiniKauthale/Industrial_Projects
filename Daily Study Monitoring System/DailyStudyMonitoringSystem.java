
import java.time.LocalDate;
import java.util.*;
import java.io.*;
import java.time.Duration;
import javax.security.auth.Subject;
import javax.xml.crypto.Data;
import jdk.jfr.Description;

// Done
class StudyLog {

    private LocalDate Date;
    private String Subject;
    private double Duration;
    private String Description;

    public StudyLog(LocalDate a, String b, double c, String d) {
        this.Date = a;
        this.Subject = b;
        this.Duration = c;
        this.Description = d;
    }

    public LocalDate getDate() {
        return this.Date;
    }

    public String getSubject() {
        return this.Subject;
    }

    public double getDuration() {
        return this.Duration;
    }

    public String getDescription() {
        return this.Description;
    }

    @Override
    public String toString() {
        return Date + " | " + Subject + " | " + Duration + " | " + Description;
    }
}

// Done
class StudyTracker {

    public ArrayList<StudyLog> Database = new ArrayList<StudyLog>();

    public void InsertLog() {
        Scanner sobj = new Scanner(System.in);

        System.out.println("----------------------------------------------------------");
        System.out.println("------------Enter valid details of your study-------------");
        System.out.println("-----------------------------------------------------------");

        LocalDate Dateobj = LocalDate.now();

        System.out.println("Please Enter the name of subject like C/C++/Java/Python)");
        String sub = sobj.nextLine();

        System.out.println("Enter the time Period of your study in hours");
        double dur = sobj.nextDouble();
        sobj.nextLine();

        System.out.println("Please provide the description of your study");
        String desc = sobj.nextLine();

        StudyLog studyobj = new StudyLog(Dateobj, sub, dur, desc);

        Database.add(studyobj);

        System.out.println("Study log gets stored succesfully");

        System.out.println("----------------------------------------------------------");

    }

    public void DisplayLog() {
        System.out.println("---------------------------------------------------------");

        if (Database.isEmpty()) {
            System.out.println("---------------------Nothing to Display--------------------");
            System.out.println("-----------------------------------------------------------");

            return;
        }

        System.out.println("--------Log Report of Daily Study Monitoring System -------");
        System.out.println("-----------------------------------------------------------");

        for (StudyLog s : Database) {
            System.out.println(s);
        }

        System.out.println("-----------------------------------------------------------");
    }

    public void ExportCSV() {
        System.out.println("-----------------------------------------------------------");

        if (Database.isEmpty()) {
            System.out.println("--------------------- Nothing to Export -------------------");
            System.out.println("-----------------------------------------------------------");
            return;
        }

        String Filename = "StudyTracker.csv";

        try (FileWriter fwobj = new FileWriter(Filename)) {
            fwobj.write("Data,Subject,Duration,Description\n");

            for (StudyLog s : Database) {
                fwobj.write(s.getDate() + ","
                        + s.getSubject().replace(",", " ") + ","
                        + s.getDuration() + ","
                        + s.getDescription().replace(",", " ") + "\n");
            }

            System.out.println("Data gets exported in CSV");
        } catch (Exception eobj) {
            System.out.println("Exception Occured in CSV");
        }
    }

    public void SummaryByDate() {
        System.out.println("-----------------------------------------------------------");

        if (Database.isEmpty()) {
            System.out.println("-------------Nothing to display as database is empty---------");
            System.out.println("-------------------------------------------------------------");
            return;
        }

        System.out.println("--------------Summary By Date from Study Tracker-----------");

        TreeMap<LocalDate, Double> tobj = new TreeMap<LocalDate, Double>();

        LocalDate lobj = null;
        double d = 0.0, old = 0.0;

        for (StudyLog sobj : Database) {
            lobj = sobj.getDate();
            d = sobj.getDuration();

            if (tobj.containsKey(lobj)) {
                old = tobj.get(lobj);
                tobj.put(lobj, d + old);
            } else {
                tobj.put(lobj, d);
            }

            //  Display the details as per subject
            for (LocalDate l : tobj.keySet()) {
                System.out.println("Subject : " + l + " Total Study Duration : " + tobj.get(l));
            }

            System.out.println("--------------------------------------------------------------");

        }
    }

    public void SummaryBySubject() {
        System.out.println("-----------------------------------------------------------");

        if (Database.isEmpty()) {
            System.out.println("-------------Nothing to display as database is empty---------");
            System.out.println("-------------------------------------------------------------");
            return;
        }

        System.out.println("-------------Summary By Subject from Study Tracker----------");

        TreeMap<String, Double> tobj = new TreeMap<String, Double>();

        String s = null;
        double d = 0.0, old = 0.0;

        for (StudyLog sobj : Database) {
            s = sobj.getSubject();
            d = sobj.getDuration();

            if (tobj.containsKey(s)) {
                old = tobj.get(s);
                tobj.put(s, d + old);
            } else {
                tobj.put(s, d);
            }

            //  Display the details as per subject
            for (String str : tobj.keySet()) {
                System.out.println("Subject : " + str + " Total Study Duration : " + tobj.get(str));
            }

            System.out.println("--------------------------------------------------------------");

        }

    }

}

class DailyStudyMonitoringSystem {

    public static void main(String A[]) {
        Scanner sobj = new Scanner(System.in);
        StudyTracker stobj = new StudyTracker();

        System.out.println("-----------------------------------------------------------");
        System.out.println("------- Welcome to Daily Study Monitoring System ----------");
        System.out.println("-----------------------------------------------------------");

        int iChoice = 0;

        do {
            System.out.println("Please select Appropriate option");
            System.out.println("1 : Insert New Study Log");
            System.out.println("2 : View all Study Log");
            System.out.println("3 : Export Study Log to CSV file");
            System.out.println("4 : Summary of Study Log By Date");
            System.out.println("4 : Summary of Study Log By Subject");
            System.out.println("6 : Exit the application");

            iChoice = sobj.nextInt();

            switch (iChoice) {
                // Insert new study log
                case 1:
                    stobj.InsertLog();
                    break;
                // View all Study Log
                case 2:
                    stobj.DisplayLog();
                    break;

                // Export Study Log to CSV file
                case 3:
                    stobj.ExportCSV();
                    break;

                // Summary of Study Log By Date
                case 4:
                    stobj.SummaryByDate();
                    break;

                // Summary of Study Log By Subject
                case 5:
                    stobj.SummaryBySubject();
                    break;

                // Exit the application
                case 6:
                    System.out.println("------------------------------------------------------------");
                    System.out.println("-----Thank You for using Daily Study Monitoring System -----");
                    System.out.println("------------------------------------------------------------");
                    break;

                default:
                    System.out.println("Please enter valid option");
                    break;
            }

        } while (iChoice != 6);   // End of do while

        sobj.close();
    }  // End of main
}  // End of starter class
