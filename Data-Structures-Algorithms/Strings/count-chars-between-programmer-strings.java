// https://gist.github.com/neerajkumar/58d7a8c48dfb2675c2c444524f511a0a

/*
xprogxrmaxemr pp prmmograeiruu 
1st & last substring contains the letters of the programmer

return value is 2, since 2 characters are in the middle of the 1st & last substrings

take 10th char from first, go until you find programmer freq dict to find end of first len substring -> f
take 10th char from last, go until you find programmer freq dict to find start of last len substring -> l

return l - f - 1
*/

public boolean isProgrammerString(Map<Character, Integer> freq) {
	    if (freq.isEmpty()) {
	    	return true;
	    } else {
	    	return false;
	    }
	}
	
	public Map<Character, Integer> getProgrammerMap() {
		Map<Character, Integer> freqMap = new HashMap<Character, Integer>();
		freqMap.put('p', 1);
		freqMap.put('r', 3);
		freqMap.put('o', 1);
		freqMap.put('g', 1);
		freqMap.put('a', 1);
		freqMap.put('m', 2);
		freqMap.put('e', 1);
		
		return freqMap;
	}
	
	public void delChar(Map<Character, Integer> freq, Character c) {
		if (freq.containsKey(c)) {
			int val = freq.get(c);
			if (val == 1) {
				freq.remove(c);
			} else {
				freq.put(c, val - 1);
			}
		}
	}
	
	
	public int charsBetweenProgrammerStrings(String s) {

		int n = s.length();
		Map<Character, Integer> fpMap = getProgrammerMap();
		Map<Character, Integer> lpMap = getProgrammerMap();
		
		for (int i = 0; i < 10; i++) {
			delChar(fpMap, s.charAt(i));
			delChar(lpMap, s.charAt(n - 1 - i));
		}
		
		int fEnd = 10;
		while (!isProgrammerString(fpMap)) {
			delChar(fpMap, s.charAt(fEnd));
			fEnd++;
		}
		
		int lFirst = n - 1 - 10;
		while (!isProgrammerString(lpMap)) {
			delChar(lpMap, s.charAt(lFirst));
			lFirst--;
		}
		
		return lFirst - fEnd - 1;
	}
