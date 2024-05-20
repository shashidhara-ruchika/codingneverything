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

  public static Integer wordLadderSolutionDEBFS(String[] strArr) {
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


  public static Integer wordLadderSolution(String[] strArr) {
    String begin = strArr[0];
    int n = strArr.length;
    String end = strArr[n - 1];

    Map<String, Set<String>> allComboDict = new HashMap<>();
    for (String word : strArr) {
      Set<String> set = new HashSet<>();
      allComboDict.put(word, set);
      for (int i = 0; i < word.length(); i++) {
        char[] chars = word.toCharArray();
        chars[i] = '*';
        String newWord = new String(chars);
        set.add(newWord);
      }
    }
    
    Queue<Pair> q = new LinkedList<>();

    Map<String, Integer> visited = new HashMap<>();

    q.offer(new Pair(begin, 1));
    visited.put(begin, 1);

    while (!q.isEmpty()) {
      Pair p = q.poll();
      String currentWord = p.word;
      int currentStep = p.step;

      if (currentWord.equals(end)) {
        return currentStep;
      }

      for (String comb : allComboDict.get(currentWord)) {
        
        for (String word : allComboDict.keySet()) {
          if (!word.equals(currentWord) && !visited.containsKey(word) && allComboDict.get(word).contains(comb)) {
            q.offer(new Pair(word, currentStep + 1));
            visited.put(word, currentStep + 1);
          }
        }
        
      }

    }
    

    return -1;
  }

  static class Pair {
    String word;
    int step;

    Pair(String word, int step) {
      this.word = word;
      this.step = step;
    }
  
  }

  public static void main (String[] args) {  
    // keep this function call here     
    String[] s = new String[] {"hit", "log", "dot", "hot", "dog", "lot", "cog"};
    
    System.err.println(wordLadderSolutionDEBFS(s));
    System.err.println(wordLadderSolution(s));

  }

}