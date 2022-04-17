/*
https://www.hackerrank.com/challenges/phone-book/problem?isFullScreen=true
*/

//Complete this code or write your own from scratch
import java.util.*;
import java.io.*;

class Solution{
	public static void main(String []argh)
	{
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		scan.nextLine();
        
        Map<String, Integer> phoneBook = new HashMap<>(n);
        
		for(int i=0;i<n;i++)
		{
			String name = scan.nextLine();
			int phone = scan.nextInt();
			scan.nextLine();
            
            phoneBook.put(name, phone);
		}
		while(scan.hasNext())
		{
			String query = scan.nextLine();
            
            if (phoneBook.containsKey(query))
                System.out.println(query + "=" + phoneBook.get(query));
            else
                System.out.println("Not found");
		}
        
        scan.close();
	}
}





/*
Sample Input

3
uncle sam
99912222
tom
11122222
harry
12299933
uncle sam
uncle tom
harry

Sample Output

uncle sam=99912222
Not found
harry=12299933
*/
