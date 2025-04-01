# Delivery Route Optimization

This project is a C program for optimizing delivery routes using Dijkstra's algorithm. The program computes the shortest path between predefined shops and calculates the total distance and time required to complete the journey.

## Features

- Calculates the shortest path between specified shops.
- Outputs individual paths, total distance, and time taken.
- Predefined list of 22 shops as nodes in a weighted graph.
- User inputs the indices of shops to visit and the mode of transportation speed.

## Shops List

1. Home  
2. Cafe Mocha  
3. Tech Hub Electronics  
4. Sunshine Pharmacy  
5. Book Nook  
6. Tasty Bites Diner  
7. Fashion Forward  
8. City Cycles  
9. Fresh Mart  
10. Gadget Galaxy  
11. Bella's Bakery  
12. Quick Fix Auto  
13. Gourmet Delights  
14. Fit & Fine Gym  
15. Pet Paradise  
16. Starlight Café  
17. Home Essentials  
18. Chill Zone  
19. Eco-Friendly Goods  
20. Veggie World  
21. Craft Corner  
22. Zen Spa  

## How It Works

- The program uses an adjacency matrix to represent the graph of shops and paths.
- Dijkstra's algorithm calculates the shortest distance between consecutive shops.
- Outputs include:
  - Path and distance for each leg of the journey.
  - Total distance for the route.
  - Time taken based on user-provided speed.

## Output Example

Available Shops: 0: Home 1: Cafe Mocha ... 21: Zen Spa

Enter the number of shops to visit (excluding starting point 0): 5 Enter the indices of the shops to visit (between 1 and 21): 21 2 7 4 3 Enter your speed of your mode of transportation in kmph 30

Route and distances: Shortest path from Home to Zen Spa: Path: Home -> Gadget Galaxy -> Fresh Mart -> Gourmet Delights -> Eco-Friendly Goods -> Zen Spa Total distance in Kilometers: 21 Shortest path from Zen Spa to Tech Hub Electronics: Path: Zen Spa -> Fit & Fine Gym -> Quick Fix Auto -> Fashion Forward -> Tech Hub Electronics Total distance in Kilometers: 20 ...

Total distance for the complete route: 70 Time taken to cover the route is 2.333333 hours