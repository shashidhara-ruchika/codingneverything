
"""
You are given a two-dimensional array lamps, 
where lamps [i] contains information about the ith lamp. 

lamps [i] [0] is an integer representing the lamp's coordinate, 
and lamps [i] [1] is a positive integer representing the effective radius of the ith lamp. 

That means that the ith lamp illuminates everything 
in a range from lamps [i] [0] - lamps [i] [1] to lamps [i] [0] + lamps [i] [1] inclusive.

Your task is to find the coordinate of the point 
that is illuminated by the highest number of lamps. 
In case of a tie, return the point among them with the minimal possible coordinate.

Example: For lamps = [[-2, 3], [2, 3], [2, 1]], the output should be solution (lamps) = 1.
"""

import collections

def solution(lamps):
    """
    Finds the coordinate illuminated by the highest number of lamps.

    Args:
        lamps: A list of lists, where each inner list contains
               [coordinate, radius].

    Returns:
        The integer coordinate illuminated by the most lamps. In case of a
        tie, it returns the point with the minimal coordinate.
    """
    events = collections.defaultdict(int)

    # Step 1 & 2: Create and aggregate events
    for coordinate, radius in lamps:
        start = coordinate - radius
        end = coordinate + radius
        
        events[start] += 1
        events[end + 1] -= 1

    # Get the sorted list of coordinates where the number of lamps changes
    sorted_coords = sorted(events.keys())

    # Step 3: Sweep through the coordinates
    max_lamps = 0
    current_lamps = 0
    result_coordinate = 0
    
    # It's safe to initialize result_coordinate with the first event point if it exists
    if sorted_coords:
        result_coordinate = sorted_coords[0]

    for coord in sorted_coords:
        # Update the number of lamps at the current coordinate
        current_lamps += events[coord]

        # Check for a new maximum
        if current_lamps > max_lamps:
            max_lamps = current_lamps
            result_coordinate = coord
            
    return result_coordinate

# Example usage from the image:
lamps_data = [[-2, 3], [2, 3], [2, 1]]
output = solution(lamps_data)
print(f"For lamps = {lamps_data}, the output should be {output}")
# Expected output: For lamps = [[-2, 3], [2, 3], [2, 1]], the output should be 1