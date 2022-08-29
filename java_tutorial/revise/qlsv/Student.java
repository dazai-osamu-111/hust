/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Scanner;

/**
 *
 * @author ADMIN
 */
public class Student extends Person {
    String rollNo;
    float mark;
    String email;
    
    public Student(){
        
    }

    public String getRollNo() {
        return rollNo;
    }

    public boolean setRollNo(String rollNo) {
        if(rollNo != null && rollNo.length() == 8 ){
        this.rollNo = rollNo;
        return true;
        } else {
            System.err.println("Nhap ko hop le(do dai phai bang 8)");
            return false;
        }
    }

    public float getMark() {
        return mark;
    }

    public boolean setMark(float mark) {
        if(mark >= 0 && mark <=10){
        this.mark = mark;
        return true;
        } else{
            System.err.println("Nhap sai diem(>=0 va <= 10");
            return false;
        }
    }

    public String getEmail() {
        return email;
    }

    public boolean setEmail(String email) {
        if(email!= null && email.contains("@") && !email.contains(" ")){
            this.email = email;
            return true;
        } else{
            System.err.println("Email phai co @ va ko chua dau cach.");
            return false;
        }
    }
    
    @Override
    public void inputInfo(){
        Scanner sc = new Scanner(System.in);
        super.inputInfo();
        
        System.out.print("Nhap ma so sinh vien: ");
        while(true){
            String rollNoInput = sc.nextLine();
            if(setRollNo(rollNoInput)){
                break;
            }
        }
        
        System.out.print("Nhap diem: ");
        while(true){
            float markInput = Float.parseFloat(sc.nextLine());
            if(setMark(markInput)) break;
        }
        
        System.out.print("Nhap email: ");
        while(true){
            String emailInput = sc.nextLine();
            if(setEmail(emailInput)) break;
        }
    }
    
    @Override
    public void showInfo(){
        super.showInfo();
        System.out.println(" ; Ma so sinh vien: " + rollNo + " ; diem: " + mark + " ; Email: " + email);
        System.out.println("");
    }
    public boolean checkScholarship(){
        return mark >= 8;
    }
}
