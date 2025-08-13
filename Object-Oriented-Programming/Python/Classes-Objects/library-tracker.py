"""
Your task is to develop a library book circulation tracker.

You are given a sequence of operations that represent activities in a library. Each operation is one of three types: acquisition, checkout, or reclassify. Operations are provided in the following format:

["acquisition", "<book category>", "<quantity>", "<price>"] – the library acquires <quantity> books of <book category>, each valued at <price> for insurance purposes.
["checkout", "<book category>", "<quantity>"] – patrons borrow <quantity> books of <book category>. If books of the specified category have different insurance values, the least valuable ones should be checked out first. It is guaranteed that the library will always have enough books to fulfill all checkout requests.
["reclassify", "<book category>", "<quantity>", "<original price>", "<new price>"] – the library reclassifies <quantity> books of <book category> to a more valuable edition. It is guaranteed that there are <quantity> books of the specified category with the <original price> value.
Your function should calculate the total insurance value of all books checked out after processing the entire sequence of operations. Return an array representing the insurance value of books for each checkout operation.

Note: You are not expected to provide the most optimal solution, but a solution with time complexity not worse than O(operations.length2) will fit within the execution time limit.

Example

For

operations = [
  ["acquisition", "fiction", "2", "100"],
  ["acquisition", "reference", "3", "60"],
  ["checkout", "fiction", "1"],
  ["checkout", "reference", "1"],
  ["reclassify", "reference", "1", "60", "100"],
  ["checkout", "reference", "1"],
  ["checkout", "reference", "1"]
]
the output should be

solution(operations) = [100, 60, 60, 100]
Let's analyze the operations:

["acquisition", "fiction", "2", "100"] - the library acquires 2 fiction books, each valued at 100.
["acquisition", "reference", "3", "60"] - the library acquires 3 reference books, each valued at 60.
["checkout", "fiction", "1"] - a patron checks out 1 fiction book valued at 100, so the insurance value is 1 × 100 = 100.
["checkout", "reference", "1"] - a patron checks out 1 reference book valued at 60, so the insurance value is 1 × 60 = 60.
["reclassify", "reference", "1", "60", "100"] - one reference book is reclassified and its value becomes 100.
["checkout", "reference", "1"] - a patron checks out 1 reference book. There are 2 reference books in the library with values of 60 and 100, and the one with the value of 60 should be checked out first, so the insurance value is 1 × 60 = 60.
["checkout", "reference", "1"] - a patron checks out 1 reference book. There is 1 reference book in the library with the value of 100, so the insurance value is 1 × 100 = 100.
Input/Output

[execution time limit] 4 seconds (py3)

[memory limit] 1 GB

[input] array.array.string operations

An array of strings, where each element represents one of 3 types of operations described above - acquisition, checkout, or reclassify.
Each <book category> only consists of alphanumeric characters - English letters and digits.
Each <price> and <quantity> are string representations of integers which are between 0 and 2000.

Guaranteed constraints:
1 ≤ operations.length ≤ 100,
3 ≤ operations[i].length ≤ 5.

[output] array.integer

An array of integers representing insurance values from each checkout operation.

[Python 3] Syntax Tips

# Prints help message to the console
# Returns a string
def helloWorld(name):
    print("This prints to the console when you Run Tests")
    return "Hello, " + name
"""
import bisect 
import heapq

class Node:
    def __init__(self, data):
        self.data = data 
        self.next = None 
    
class SortedLinkedList:
    def __init__(self):
        self.head = None 
        
    def insert(self, data): # time complexity: O(n)
        new_node = Node(data)
        
        if self.head is None or self.head.data >= new_node.data:
            new_node.next = self.head
            self.head = new_node 
            return 
        
        current_node = self.head 
        while current_node.next is not None and current_node.next.data < new_node.data:
            current_node = current_node.next 
        
        new_node.next = current_node.next 
        current_node.next = new_node

    def delete(self, data): # time complexity : O(n)
        if self.head is None:
            return 
        
        if self.head.data == data:
            self.head = self.head.next 
            return 
            
        current_node = self.head 
        previous_node = None 
        
        while current_node is not None and current_node.data != data:
            previous_node = current_node
            current_node = current_node.next 
            
        if current_node is None:
            return  
        
        previous_node.next = current_node.next 
        
    def delete_head(self): # time complexity : O(1)
        if self.head is not None:
            self.head = self.head.next 
        
class LibraryTrackerSLL:
    
    def __init__(self):
        self.books = dict()
        
    def acquisition(self, book_category, quantity, price): # time complexity: O(quantity * n)
        if book_category not in self.books:
            self.books[book_category] = SortedLinkedList()
        
        sll = self.books[book_category]
        for i in range(quantity):
            sll.insert(price)

    def checkout(self, book_category, quantity): # time complexity : O(quantity * n)
        total = 0
        sll = self.books[book_category]
        for i in range(quantity):
            data = sll.head.data 
            total += data 
            sll.delete_head()
        return total

    def reclassify(self, book_category, quantity, original_price, new_price): # time complexity : O(quantity * n)
        sll = self.books[book_category]
        for i in range(quantity):
            sll.delete(original_price)
        for i in range(quantity):
            sll.insert(new_price)

import bisect 

class Book:
    def __init__(self, price):
        self.price = price 
    
    def __lt__(self, other):
        return self.price >= other.price # rev order [100, 70, 80, 60]

    def __eq__(self, other):
        return self.price == other.price
    
    def __str__(self):
        return str(self.price)
    
    def __repr__(self):
        return str(self.price)

class LibraryTrackerBisect:
    def __init__(self):
        self.books = dict()

    def acquisition(self, book_category, quantity, price):  # time complexity: O(quantity * log n), worst O(quantity * n)
        if book_category not in self.books:
            self.books[book_category] = []

        sorted_books = self.books[book_category]
        for i in range(quantity):
            bisect.insort(sorted_books, Book(price)) # time complexity : O(log n),  worst O(n)

        # format print("acquisition: ", book_category, quantity, price, self.books)
        # print("acquisition: ", book_category, quantity, price)
        # print(self.books)

    def checkout(self, book_category, quantity):  # time complexity : O(quantity)
        total = 0
        sorted_books = self.books[book_category]
        # print("checkout: ", book_category, quantity, total)
        for i in range(quantity):
            data = sorted_books.pop() # time complexity : O(1)
            # print(self.books)
            total += data.price
            
        
        return total

    def reclassify(self, book_category, quantity, original_price, new_price):  # time complexity : O(quantity * n)
        sorted_books = self.books[book_category]
        for i in range(quantity):
            sorted_books.remove(Book(original_price)) # time complexity : O(n)
        for i in range(quantity):
            bisect.insort(sorted_books, Book(new_price)) # time complexity : O(log n), worst O(n)

        # print("reclassify: ", book_category, quantity, original_price, new_price)
        # print(self.books)

import heapq

class LibraryBook:
    def __init__(self, price):
        self.price = price 
    
    def __lt__(self, other):
        return self.price < other.price #  order [100, 70, 80, 60]

    def __eq__(self, other):
        return self.price == other.price
    
    def __str__(self):
        return str(self.price)
    
    def __repr__(self):
        return str(self.price)
    
class LibraryTrackerHeapq:
    def __init__(self):
        self.books = dict()

    def acquisition(self, book_category, quantity, price):  # time complexity: O(quantity * log n)
        if book_category not in self.books:
            self.books[book_category] = []

        sorted_books = self.books[book_category]
        for i in range(quantity):
            heapq.heappush(sorted_books, LibraryBook(price)) # time complexity : O(log n)


    def checkout(self, book_category, quantity):  # time complexity : O(quantity * log n)
        total = 0
        sorted_books = self.books[book_category]
        for i in range(quantity):
            data = heapq.heappop(sorted_books) # time complexity : O(log n)
            total += data.price            
        
        return total

    def reclassify(self, book_category, quantity, original_price, new_price):  # time complexity : O(quantity * n)
        # replace books with original_price with new_price and then re-heapify
        sorted_books = self.books[book_category]

        for i in range(quantity):
            index = sorted_books.index(LibraryBook(original_price)) # time complexity: O(n)
            sorted_books[index].price = new_price
            
        heapq.heapify(sorted_books) # time complexity: O(n)
    

    def reclassify1(self, book_category, quantity, original_price, new_price):  # time complexity : O(quantity * n)
        # remove books with original_price, re-heapify and then add books with new price
        sorted_books = self.books[book_category]

        for i in range(quantity):
            sorted_books.remove(LibraryBook(original_price)) # time complexity : O(n)
        
        heapq.heapify(sorted_books) # time complexity: O(n)

        for i in range(quantity):
            heapq.heappush(sorted_books, LibraryBook(new_price)) # time complexity : O(log n)

    
        

    
def solution(operations):
    
    lt = LibraryTrackerHeapq()
    
    result = []
    
    for operation in operations:
        
        operation_type = operation[0]
        
        if operation_type == "acquisition":
            lt.acquisition(operation[1], int(operation[2]), int(operation[3]))
        
        if operation_type == "checkout":
            ans = lt.checkout(operation[1], int(operation[2]))
            result.append(ans)
            
        if operation_type == "reclassify":
            lt.reclassify(operation[1], int(operation[2]), int(operation[3]), int(operation[4]))
        
        # print()
        # print()
    return result


def check_ans(operations, expected_ans):

    my_ans = solution(operations)

    assert my_ans == expected_ans, f"Expected {expected_ans}, but got {my_ans}"

if __name__ == '__main__':
    print("Solution")
    
    check_ans([["acquisition","fiction","2","100"], 
 ["acquisition","reference","3","60"], 
 ["checkout","fiction","1"], 
 ["checkout","reference","1"], 
 ["reclassify","reference","1","60","100"], 
 ["checkout","reference","1"], 
 ["checkout","reference","1"]],  [100, 60, 60, 100])
    


    check_ans([["acquisition","A","2","200"], 
 ["acquisition","B","3","100"], 
 ["checkout","A","2"], 
 ["checkout","B","1"], 
 ["reclassify","B","1","100","180"], 
 ["checkout","B","2"]], [400, 100, 280])

    check_ans([["acquisition","A","2","100"], 
 ["checkout","A","1"], 
 ["reclassify","A","1","100","160"], 
 ["checkout","A","1"], 
 ["acquisition","A","2","70"], 
 ["checkout","A","1"], 
 ["reclassify","A","1","70","130"], 
 ["checkout","A","1"]], [100, 160, 70, 130])

    check_ans([["acquisition","book","4","999"]], [])

    check_ans([["acquisition","Qy0Fkfxxd","1917","795"], 
 ["reclassify","Qy0Fkfxxd","435","795","875"], 
 ["reclassify","Qy0Fkfxxd","13","795","875"], 
 ["reclassify","Qy0Fkfxxd","449","795","875"], 
 ["acquisition","Qy0Fkfxxd","1584","431"], 
 ["reclassify","Qy0Fkfxxd","98","875","963"], 
 ["checkout","Qy0Fkfxxd","309"], 
 ["reclassify","Qy0Fkfxxd","914","795","875"], 
 ["acquisition","bS6s","1383","732"], 
 ["checkout","Qy0Fkfxxd","1250"]], [133179, 538750])

    check_ans([["acquisition","ldQowsYNz","695","818"], 
 ["reclassify","ldQowsYNz","238","818","900"], 
 ["reclassify","ldQowsYNz","230","818","900"], 
 ["reclassify","ldQowsYNz","30","818","900"], 
 ["checkout","ldQowsYNz","383"], 
 ["checkout","ldQowsYNz","94"], 
 ["reclassify","ldQowsYNz","217","900","991"], 
 ["reclassify","ldQowsYNz","116","991","1091"], 
 ["reclassify","ldQowsYNz","36","991","1091"], 
 ["reclassify","ldQowsYNz","45","991","1091"], 
 ["checkout","ldQowsYNz","181"], 
 ["acquisition","tj","1244","476"], 
 ["checkout","tj","860"], 
 ["acquisition","tj","484","247"], 
 ["checkout","tj","293"], 
 ["reclassify","tj","2","476","524"], 
 ["acquisition","ngw","230","347"], 
 ["checkout","ngw","38"], 
 ["checkout","ldQowsYNz","37"], 
 ["acquisition","stDjvCgk","4","806"]], [328546, 84600, 195280, 409360, 72371, 13186, 40367])


