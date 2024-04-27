/*
 * Level 1: Container should support adding and removing numbers.
 * Level 2: Container should support getting the median of the numbers stored in it. If size of elements is even, return the leftmost.
 */


package com.codesignal.integercontainer;
import java.util.*;


class IntegerContainerImpl implements IntegerContainer {
  
  TreeMap<Integer, Integer> list;
  TreeMap<Integer, Integer> elementLastIndex;
  int totalElements;
  

  public IntegerContainerImpl() {
    // TODO: implement
      list = new TreeMap<>();
      elementLastIndex = new TreeMap<>();
      totalElements = 0;
  }

  // TODO: implement interface methods here
  public int add(int value) {
    if (list.containsKey(value)) {
      list.put(value, list.get(value) + 1);
    } else {
      list.put(value, 1);
    }
    totalElements += 1;
    return totalElements;
  }
  
  /*
  5
  5,1,5
  
  1 1 1
  4 1 2
  5 2 5 5 4
  10 3 5
  
  1 2 3 4 5  6
  1 4 5 5 10 10 
  1 1 2 1
  1 2 4 6
  
  5/2 = 2
  */
  
  public boolean delete(int value) {
    if (list.containsKey(value)) {
      int currentValueTotal = list.get(value);
      if (currentValueTotal == 1) {
        list.remove(value);
      } else {
        list.put(value, list.get(value) - 1);
      }
      totalElements -= 1;
      return true;
    } 
    
    return false;
  }
  
  public Optional<Integer> getMedian() {
    
    if (totalElements == 0) {
      return Optional.empty();
    }
    
    int mid = (int) Math.ceil(totalElements / 2.0) ;
    
    List<Integer> nums = new ArrayList<Integer>(list.keySet());
    List<Integer> freq = new ArrayList<Integer>(list.values());    
    
    int index = -1;
    int cuurentTotal = 0;
    while (cuurentTotal < mid && index < freq.size()) {
      index++;
      cuurentTotal += freq.get(index);
    }  
      
    return Optional.of(nums.get(index));
    
  }
}
