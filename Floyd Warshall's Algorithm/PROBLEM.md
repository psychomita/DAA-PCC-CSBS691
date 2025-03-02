```
In a professional networking platform (like LinkedIn), people are connected through various degrees of relationships.
Each connection has a strength score that indicates the quality of the relationship. Your task is to develop an
algorithm that finds the strongest and shortest path between every pair of professionals in the network.
```

## Problem Definition:

You are given a weighted, directed graph where:
<li>
  Nodes (People): Represent individual professionals.
</li>
<li>
  Edges (Connections): Represent direct relationships between professionals.
</li>
<li>
  Weights (Connection Strengths): A numerical value that represents how strong a relationship is.
</li>
<li>
  Lower weight = Stronger connection (e.g., 1 = best friend, 10 = distant acquaintance).
</li>
<li>
  Higher weight = Weaker connection (e.g., 100 = barely know each other).
</li>
<li>
  If two professionals are not directly connected, the weight is ∞ (infinity).
</li>
<br/>

```
Your task is to implement the Floyd-Warshall Algorithm to determine the strongest and shortest connection path
between every pair of professionals.
