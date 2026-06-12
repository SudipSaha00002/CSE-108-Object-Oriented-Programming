/* This class stores the following information about an event: name, starting date, location and list of students registered for the event. */
package com.company;
public class Event {
    private String eventName;
    private String eventDate; // store in the format YYYY-MM-DD
    private String eventLocation;
    private Student[] registeredStudents;
    int participantsAdded = 0; //variable to keep track of number of participants so far added
    int maximumParticipants;
    //Task: Write code for the constructor below to initialize the member variables properly
    public Event(String eventName, String eventDate, String eventLocation, int maximumParticipants) {
        //write your code here

        this.eventName=eventName;
        this.eventDate=eventDate;
        this.eventLocation=eventLocation;
        this.maximumParticipants=maximumParticipants;
        this.registeredStudents=new Student[maximumParticipants];

    }

    // Task: Write getters and setters for Event attributes as required


    public String getEventName() {
        return this.eventName;
    }

    public String getEventDate() {
        return this.eventDate;
    }

    public String getEventLocation() {
        return this.eventLocation;
    }

    public int getMaximumParticipants() {
        return this.maximumParticipants;
    }

    public int getParticipantsAdded() {
        return this.participantsAdded;
    }

    public void setEventName(String eventName) {
        this.eventName = eventName;
    }

    public void setEventDate(String eventDate) {
        this.eventDate = eventDate;
    }

    public void setEventLocation(String eventLocation) {
        this.eventLocation = eventLocation;
    }

    public void setMaximumParticipants(int maximumParticipants) {
        this.maximumParticipants = maximumParticipants;
    }

    public void setParticipantsAdded(int participantsAdded) {
        this.participantsAdded = participantsAdded;
    }

    public Student[] getRegisteredStudents() {
        return this.registeredStudents;
    }

    public void setRegisteredStudents(Student[] registeredStudents) {
        this.registeredStudents = registeredStudents;
    }

    // Task: Write your code for the function below. This functions adds a participant to this event. Check for the following cases: (i) total participant count does not exceed the maximum participant count, (ii) the studentId is not already added.
    public void addParticipant(Student student) {
        // write your code here
        if(participantsAdded<maximumParticipants){
            registeredStudents[participantsAdded]=student;
            participantsAdded++;
            System.out.println("Student registration completed.");
        }
        else{
            System.out.println("Event is full");
        }
    }

    
    //Task: Write code for the function below. This function shows the details of an event. Make sure your output matches with the supplied sample output.
    public void showDetails() {
        //Write your code here

        System.out.println("Name :"+eventName);
        System.out.println("Date :"+eventDate);
        System.out.println("Location :"+eventLocation);
        System.out.println("Registered Participants:");
        for(int i=0;i<participantsAdded;i++){
            registeredStudents[i].showDetails();
        }
    }

        //Task: Write code for the function below. This function check whether the studentId in the argument has registered for this event or not. Return true if registered, otherwise return false.
    public boolean isRegistered(String studentId) {
        //Write your code here
        for(int i=0;i<participantsAdded;i++){
            if(registeredStudents[i].getId().equals(studentId)){
                return true;
            }
        }
        return false;
    }

    // Task: Write code for the function below. This function removes a participant from this event. Check for the following cases: (i) the studentId is not registered.
    public void removeParticipant(String studentId) {
        //Write your code here

        for(int i=0;i<participantsAdded;i++){
            if(registeredStudents[i].getId().equals(studentId)){
                System.out.println("Successfully removed id " + studentId + " from event " + eventName);
                for (int j=i;j<participantsAdded;j++){
                    registeredStudents[j]=registeredStudents[j+1];
                }
                participantsAdded--;
                return;
            }
        }
        System.out.println("Student with ID " + studentId + " is not registered");
    }

}