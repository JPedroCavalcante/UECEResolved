package model;

import java.util.ArrayList;

public class Movie {
    private String name;
    private int classification;
    private ArrayList<String> SessionsList = new ArrayList();

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getClassification() {
        return classification;
    }

    public void setClassification(int classification) {
        this.classification = classification;
    }

    public ArrayList<String> getSessionsList() {
        return SessionsList;
    }

    public void setSessionsList(ArrayList<String> SessionsList) {
        this.SessionsList = SessionsList;
    }
    
}
