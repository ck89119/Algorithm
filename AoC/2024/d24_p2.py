import networkx as nx
import matplotlib.pyplot as plt

# Initialize directed graph
G = nx.DiGraph()

# Parse input to construct the graph
file_path = "/Users/LoveYY/Develop/Algorithm/AoC/2024/in.txt"  # Adjust the path to your file
with open(file_path, "r") as f:
    lines = f.readlines()

# Add nodes for initial variables
for line in lines:
    if ":" in line:  # Initial states
        var, value = line.strip().split(":")
        var = var.strip()
        value = value.strip()
        G.add_node(var, value=value)

# Add edges for operations
for line in lines:
    if "->" in line:  # Operations
        parts = line.strip().split("->")
        result = parts[1].strip()
        operation = parts[0].strip()
        operands = operation.split()

        if len(operands) == 3:  # Binary operation
            src1, op, src2 = operands
            G.add_edge(src1, result, operation=op)
            G.add_edge(src2, result, operation=op)

# Use Graphviz layout (dot) for tree structure
try:
    pos = nx.nx_agraph.graphviz_layout(G, prog="dot")
except ImportError:
    raise ImportError(
        "Graphviz is required for this layout. Ensure you have pygraphviz or pydot installed."
    )

# Draw the graph
plt.figure(figsize=(50, 100))
nx.draw(
    G,
    pos,
    with_labels=True,
    node_size=600,
    node_color="lightblue",
    font_size=12,
    edge_color="gray",
)

# Add edge labels
edge_labels = {(u, v): d["operation"] for u, v, d in G.edges(data=True) if "operation" in d}
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10)

# Save to a file and show the graph
plt.savefig("tree_graph.png", format="png", dpi=300)
plt.title("Tree-Like Graph Visualization")
plt.show()
