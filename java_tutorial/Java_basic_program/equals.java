//overriding equals() method
@Override
public boolean equals(Object obj){
	if(obj == null)
		return false;
	if(obj == this)
		return true;
	return this.getRegno() == ((Employee)obj).getRegno();
}