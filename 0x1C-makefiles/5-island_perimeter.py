#!/usr/bin/python3

"""island_perimeter"""


def island_perimeter(grid):
    """Calculate the perimeter of the island described in grid."""
    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                perimeter += 4  # Add 4 initially for the cell's perimeter
                # Check neighbors (up, down, left, right)
                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 2  # Subtract 2 for shared edge
                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 2  # Subtract 2 for shared edge

    return perimeter
