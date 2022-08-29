/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.ArrayList;
import java.util.*;

/**
 *
 * @author ADMIN
 */

public class StudentTest {
    public static void main(String args[]){
        int choose;
        ArrayList<Student> list = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
                
        do{
            showMenu();
            System.out.print("Ban chon?  ");
            choose = Integer.parseInt(sc.nextLine());
            switch(choose){
                case 1: 
                    System.out.println("Nhap vao so luong sinh vien: ");
                    int  n = Integer.parseInt(sc.nextLine());
                    for(int i=0;i<n;i++){
                        Student std = new Student();
                        std.inputInfo();
                        list.add(std);
                    }
                    break;
                
                case 2: 
                    for(int i=0;i<list.size();i++){
                        list.get(i).showInfo();
                    }
                    break;
                case 3: 
					Collections.sort(list, new Comparator<Student>(){
						@Override
						public int compare(Student st1, Student st2){
							if(st1.getMark() > st2.getMark()) return 1;
							if(st1.getMark() < st2.getMark()) return -1;
							else return 0;
						}
					});
					System.out.println("Sinh vien co diem so thap nhat:");
					list.get(0).showInfo();
					System.out.println("Sinh vien co diem so cao nhat:");
					list.get(list.size() -1).showInfo();
				break;
                case 4: 
					String find = sc.nextLine();
					int count = 0;
					for(int i=0;i<list.size();i++){
						if(list.get(i).getRollNo().equals(find)){
							list.get(i).showInfo();
							count++;
						}
					}
					if(count == 0) System.out.println("Khong tim thay sinh vien");
				break;
                case 5: 
					Collections.sort(list, new Comparator<Student>(){
						@Override
						public int compare(Student o1, Student o2){
							return o1.getName().compareTo(o2.getName());
						}
					});
					for(Student o: list){
						o.showInfo();
					}
				break;
                case 6: 
					Collections.sort(list, new Comparator<Student>(){
						@Override
						public int compare(Student st1, Student st2){
							if(st1.getMark() > st2.getMark()) return -1;
							if(st1.getMark() < st2.getMark()) return 1;
							else return 0;
						}
					});
					for(int i=0;i<list.size();i++){
						if(list.get(i).getMark() >= 8)
							list.get(i).showInfo();
					}
				break;
                case 7:
                    System.out.println("Goodbye!!!");
                    break;
                default: 
                    break;
            }
        } while(choose != 7);
    }
    
    static void showMenu(){
        System.out.println("1. Nhap vao so sinh vien");
        System.out.println("2. Hien thi thong tin sinh vien");
        System.out.println("3. Hien thi max va min theo diem trung binh");
        System.out.println("4. Tim kiem sinh vien theo ma sinh vien");
        System.out.println("5. Hien thi sinh vien theo ten theo ma tu A->Z");
        System.out.println("6. Hien thi sinh vien duoc hoc bong va sx diem giam dan");
        System.out.println("7. Thoat");
    }
}
