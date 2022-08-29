public Student extends Person{
	private int mark;
	private String grade;
	
	void setMark(int mark){
		this.mark = mark;
	}
	
	int getMark(){
		return this.mark;
	}
	
	void setGrade(String grade){
		this.grade = grade;
	}
	
	String getGrade(){
		return this.grade;
	}
	
	public void calGrade(){
		if(getMark() >= 8) setGrade("distinction");
		else if(getMark()>=7) setGrade("credit");
		else if(getMark() >= 5) setGrade("pass");
		else if(getMark() >= 0) setGrade("fail");
	}
	
	
}