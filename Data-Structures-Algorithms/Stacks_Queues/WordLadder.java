// https://algo.monster/liteproblems/127

import java.util.*; 
import java.io.*;

class WordLadder {

  public static int addQueue(Map<String, Integer> visitedOne, Map<String, Integer> visitedOther, Queue<String> q, Set<String> wordSet) {
    for(int i = q.size(); i > 0; --i) {
      String current = q.poll();
      int currentStep = visitedOne.get(current);
      char[] chars = current.toCharArray();

      for(int j = 0; j < chars.length; ++j) {
        char originalChar = chars[j];
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          chars[j] = ch;
          String newWord = new String(chars);
          if (!wordSet.contains(newWord) || visitedOne.containsKey(newWord)) {
            continue;
          }

          if (visitedOther.containsKey(newWord)) {
            return currentStep + visitedOther.get(newWord);
          }

          q.offer(newWord);
          visitedOne.put(newWord, currentStep + 1);
        }

        chars[j] = originalChar;
      }
    }

    return -1;
  }

  public static Integer wordLadderSolution(String[] strArr) {
    String begin = strArr[0];
    int n = strArr.length;
    String end = strArr[n - 1];
    
    List<String> wordList = new ArrayList<>();

    for (int i = 1; i < n; i++) {
      wordList.add(strArr[i]);
    }

    Set<String> wordSet = new HashSet<>(wordList);

    Queue<String> qbegin = new ArrayDeque<>();
    Queue<String> qend = new ArrayDeque<>();

    Map<String, Integer> vbegin = new HashMap<>();
    Map<String, Integer> vend = new HashMap<>();

    qbegin.offer(begin);
    qend.offer(end);

    vbegin.put(begin, 1);
    vend.put(end, 1);

    while (!qbegin.isEmpty() && !qend.isEmpty()) {
      int ans = 0;
      if (qbegin.size() <= qend.size()) {
        ans = addQueue(vbegin, vend, qbegin, wordSet);
      } else {
        ans = addQueue(vend, vbegin, qend, wordSet);
      }
      if (ans != -1) {
        return ans;
      }
    }

    return -1;

  }

  
  
  public static void main (String[] args) {  
    // keep this function call here     
    Scanner s = new Scanner(System.in);
    System.out.print(wordLadderSolution(s.nextLine()).toString()); 
  }

}