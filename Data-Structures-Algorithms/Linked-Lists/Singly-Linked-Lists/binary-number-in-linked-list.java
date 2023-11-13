/*

Given Binary Number Linked List 0->1->0->0>1->1 [2] return its decimal number 19[10]
*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class SinglyLinkedListNode {
    public int data;
    public SinglyLinkedListNode next;

    public SinglyLinkedListNode(int nodeData) {
        this.data = nodeData;
        this.next = null;
    }
}

class SinglyLinkedList {
    public SinglyLinkedListNode head;
    public SinglyLinkedListNode tail;

    public SinglyLinkedList() {
        this.head = null;
        this.tail = null;
    }

    public void insertNode(int nodeData) {
        SinglyLinkedListNode node = new SinglyLinkedListNode(nodeData);

        if (this.head == null) {
            this.head = node;
        } else {
            this.tail.next = node;
        }

        this.tail = node;
    }
}

class SinglyLinkedListPrintHelper {
    public static void printList(SinglyLinkedListNode node, String sep, BufferedWriter bufferedWriter) throws IOException {
        while (node != null) {
            bufferedWriter.write(String.valueOf(node.data));

            node = node.next;

            if (node != null) {
                bufferedWriter.write(sep);
            }
        }
    }
}


class Result {

    /*
     * Complete the 'getNumber' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts INTEGER_SINGLY_LINKED_LIST binary as parameter.
     */

    /*
     * For your reference:
     *
     * SinglyLinkedListNode {
     *     int data;
     *     SinglyLinkedListNode next;
     * }
     *
     */

    public static long getNumber(SinglyLinkedListNode binary) {
    // Write your code here
        SinglyLinkedListNode node = binary;
        double twoPow = 1;
        while (node != null) {
            node = node.next;
            twoPow *= 2;
        }
        twoPow /= 2;
        
        System.out.println(twoPow);
        
        double decimal = 0;
        
        node = binary;
        
        while (node != null) {
            decimal += node.data * twoPow;
            twoPow /= 2;
            node = node.next;
        }
        
        return (long) decimal;

    }

}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        SinglyLinkedList binary = new SinglyLinkedList();

        int binaryCount = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, binaryCount).forEach(i -> {
            try {
                int binaryItem = Integer.parseInt(bufferedReader.readLine().trim());

                binary.insertNode(binaryItem);
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        long result = Result.getNumber(binary.head);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
